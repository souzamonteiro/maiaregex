#include "maia_regex.h"
#include <stdlib.h>
#include <limits.h>

#define MEMO_UNVISITED 0
#define MEMO_VISITING -2
#define MEMO_FAILED -1

typedef struct {
    unsigned int instruction;
    unsigned int position;
    int phase;
    size_t assertion_depth;
    size_t cycle_epoch;
} MaiaRegexFrame;

/* Keys remain occupied when a cycle-pruned value becomes UNVISITED again. */
typedef struct {
    size_t key;
    int value;
} MaiaRegexMemoEntry;

typedef struct {
    MaiaRegexMemoEntry *entries;
    size_t capacity;
    size_t used;
} MaiaRegexMemo;

static size_t maia_regex_memo_hash(size_t key, size_t capacity)
{
    key ^= key >> 16;
    key *= 2654435761UL;
    key ^= key >> 16;
    return key & (capacity - 1);
}

static int *maia_regex_memo_slot(MaiaRegexMemo *memo, size_t cell, int *status)
{
    size_t key, at, probe, next_capacity, index, target;
    MaiaRegexMemoEntry *grown;
    /* The logical dense-size preflight bounds cell below SIZE_MAX / sizeof(int). */
    key = cell + 1;
    at = maia_regex_memo_hash(key, memo->capacity);
    for (probe = 0; probe < memo->capacity; ++probe) {
        if (memo->entries[at].key == key) return &memo->entries[at].value;
        if (!memo->entries[at].key) break;
        at = (at + 1) & (memo->capacity - 1);
    }
    if (probe == memo->capacity) { *status = MAIA_REGEX_LIMIT; return 0; }
    if (memo->used >= memo->capacity / 2) {
        if (memo->capacity > (size_t)-1 / sizeof(MaiaRegexMemoEntry) / 2) {
            *status = MAIA_REGEX_LIMIT; return 0;
        }
        next_capacity = memo->capacity * 2;
        grown = (MaiaRegexMemoEntry *)calloc(next_capacity, sizeof(MaiaRegexMemoEntry));
        if (!grown) { *status = MAIA_REGEX_NOMEM; return 0; }
        for (index = 0; index < memo->capacity; ++index) {
            if (!memo->entries[index].key) continue;
            target = maia_regex_memo_hash(memo->entries[index].key, next_capacity);
            for (probe = 0; probe < next_capacity; ++probe) {
                if (!grown[target].key) break;
                target = (target + 1) & (next_capacity - 1);
            }
            if (probe == next_capacity) {
                free(grown); *status = MAIA_REGEX_LIMIT; return 0;
            }
            grown[target].key = memo->entries[index].key;
            grown[target].value = memo->entries[index].value;
        }
        free(memo->entries);
        memo->entries = grown;
        memo->capacity = next_capacity;
        at = maia_regex_memo_hash(key, next_capacity);
        for (probe = 0; probe < next_capacity; ++probe) {
            if (!memo->entries[at].key) break;
            at = (at + 1) & (next_capacity - 1);
        }
        if (probe == next_capacity) { *status = MAIA_REGEX_LIMIT; return 0; }
    }
    memo->entries[at].key = key;
    memo->entries[at].value = MEMO_UNVISITED;
    ++memo->used;
    return &memo->entries[at].value;
}

int maia_regex_validate(const MaiaRegexProgram *program)
{
    unsigned int index;
    const MaiaRegexInstruction *code;
    if (!program || !program->code || !program->instruction_count
        || program->entry >= program->instruction_count
        || (program->range_count && !program->ranges)) return MAIA_REGEX_INVALID;
    for (index = 0; index < program->range_count; ++index) {
        if (program->ranges[index].first > program->ranges[index].last
            || program->ranges[index].last > 65535U) return MAIA_REGEX_INVALID;
    }
    for (index = 0; index < program->instruction_count; ++index) {
        code = program->code + index;
        if (code->op < MAIA_REGEX_ACCEPT || code->op > MAIA_REGEX_POSITIVE)
            return MAIA_REGEX_INVALID;
        if (code->op == MAIA_REGEX_ACCEPT) continue;
        if (code->op == MAIA_REGEX_SPLIT) {
            if (code->first >= program->instruction_count
                || code->second >= program->instruction_count) return MAIA_REGEX_INVALID;
            continue;
        }
        if (code->next >= program->instruction_count) return MAIA_REGEX_INVALID;
        if (code->op == MAIA_REGEX_CHAR && code->first > 65535U) return MAIA_REGEX_INVALID;
        if ((code->op == MAIA_REGEX_POSITIVE || code->op == MAIA_REGEX_NEGATIVE)
            && code->first >= program->instruction_count) return MAIA_REGEX_INVALID;
        if (code->op == MAIA_REGEX_CLASS || code->op == MAIA_REGEX_NOT_CLASS) {
            if (code->first > program->range_count
                || code->second > program->range_count - code->first) return MAIA_REGEX_INVALID;
        }
    }
    return MAIA_REGEX_MATCH;
}

int maia_regex_exec(const MaiaRegexProgram *program, const unsigned int *input,
                    unsigned int length, unsigned int start,
                    const MaiaRegexLimits *limits, unsigned int *end)
{
    size_t columns, cells, slot, capacity, depth, steps, next_capacity;
    size_t active, cycle_epoch;
    int *memo, *memo_value;
    MaiaRegexMemo sparse;
    MaiaRegexFrame *frames, *grown, *frame;
    const MaiaRegexInstruction *code;
    const MaiaRegexRange *range;
    unsigned int index, child_instruction, child_position;
    int result, last, descend, done, matches;
    if (!end || start > length || length > (unsigned int)(INT_MAX - 1)
        || (length && !input) || maia_regex_validate(program) != MAIA_REGEX_MATCH)
        return MAIA_REGEX_INVALID;
    for (index = start; index < length; ++index) {
        if (input[index] > 65535U) return MAIA_REGEX_INVALID;
    }
    columns = (size_t)(length - start) + 1;
    if (program->instruction_count > (size_t)-1 / sizeof(int) / columns)
        return MAIA_REGEX_LIMIT;
    cells = (size_t)program->instruction_count * columns;
    if (limits && limits->max_memo_bytes && cells > limits->max_memo_bytes / sizeof(int))
        return MAIA_REGEX_LIMIT;
    capacity = 64;
    if (limits && limits->max_frames && capacity > limits->max_frames)
        capacity = limits->max_frames;
    if (capacity > (size_t)-1 / sizeof(MaiaRegexFrame)) return MAIA_REGEX_LIMIT;
    memo = 0;
    sparse.entries = 0; sparse.capacity = 16; sparse.used = 0;
    /* Explicit byte budgets retain the original allocation and limit semantics. */
    if ((limits && limits->max_memo_bytes)
        || cells <= 16 * sizeof(MaiaRegexMemoEntry) / sizeof(int)) {
        memo = (int *)calloc(cells, sizeof(int));
        if (!memo) return MAIA_REGEX_NOMEM;
    } else {
        sparse.entries = (MaiaRegexMemoEntry *)calloc(16, sizeof(MaiaRegexMemoEntry));
        if (!sparse.entries) return MAIA_REGEX_NOMEM;
    }
    frames = (MaiaRegexFrame *)malloc(capacity * sizeof(MaiaRegexFrame));
    if (!frames) { free(memo); free(sparse.entries); return MAIA_REGEX_NOMEM; }
    frames[0].instruction = program->entry;
    frames[0].position = start;
    frames[0].phase = 0;
    frames[0].assertion_depth = 0;
    frames[0].cycle_epoch = 0;
    depth = 1;
    cycle_epoch = 0;
    steps = 0;
    last = -1;
    result = MAIA_REGEX_MATCH;
    while (depth) {
        if (limits && limits->max_steps) {
            if (steps >= limits->max_steps) { result = MAIA_REGEX_LIMIT; break; }
            ++steps;
        }
        frame = frames + depth - 1;
        slot = (size_t)frame->instruction * columns + frame->position - start;
        memo_value = memo ? memo + slot : maia_regex_memo_slot(&sparse, slot, &result);
        if (!memo_value) break;
        code = program->code + frame->instruction;
        descend = 0;
        done = 0;
        child_instruction = 0;
        child_position = frame->position;
        if (frame->phase == 0) {
            if (*memo_value == MEMO_VISITING) {
                /* An empty cycle cuts a path; a cycle across an assertion
                 * boundary would recursively define the assertion itself. */
                for (active = depth - 1; active > 0; --active) {
                    if (frames[active - 1].instruction == frame->instruction
                        && frames[active - 1].position == frame->position) break;
                }
                if (!active || frames[active - 1].assertion_depth != frame->assertion_depth) {
                    result = MAIA_REGEX_INVALID;
                    break;
                }
                if (cycle_epoch == (size_t)-1) { result = MAIA_REGEX_LIMIT; break; }
                ++cycle_epoch;
                last = -1;
                --depth;
                continue;
            }
            if (*memo_value != MEMO_UNVISITED) {
                last = *memo_value > 0 ? *memo_value - 1 : -1;
                --depth;
                continue;
            }
            *memo_value = MEMO_VISITING;
            frame->cycle_epoch = cycle_epoch;
            last = -1;
            if (code->op == MAIA_REGEX_ACCEPT) { last = (int)frame->position; done = 1; }
            else if (code->op == MAIA_REGEX_SPLIT) {
                frame->phase = 1;
                child_instruction = code->first;
                descend = 1;
            } else if (code->op == MAIA_REGEX_NEGATIVE || code->op == MAIA_REGEX_POSITIVE) {
                frame->phase = 4;
                child_instruction = code->first;
                descend = 1;
            } else if (code->op == MAIA_REGEX_END) {
                matches = frame->position == length;
                if (matches) {
                    frame->phase = 3;
                    child_instruction = code->next;
                    descend = 1;
                } else done = 1;
            } else if (frame->position < length) {
                matches = code->op == MAIA_REGEX_CHAR && input[frame->position] == code->first;
                if (code->op == MAIA_REGEX_CLASS || code->op == MAIA_REGEX_NOT_CLASS) {
                    matches = 0;
                    for (index = 0; index < code->second; ++index) {
                        range = program->ranges + code->first + index;
                        if (input[frame->position] >= range->first && input[frame->position] <= range->last) {
                            matches = 1;
                            break;
                        }
                    }
                    if (code->op == MAIA_REGEX_NOT_CLASS) matches = !matches;
                }
                if (matches) {
                    frame->phase = 3;
                    child_instruction = code->next;
                    child_position = frame->position + 1;
                    descend = 1;
                } else done = 1;
            } else done = 1;
        } else if (frame->phase == 1 && last < 0) {
            frame->phase = 2;
            child_instruction = code->second;
            descend = 1;
        } else if (frame->phase == 4) {
            matches = (last < 0) == (code->op == MAIA_REGEX_NEGATIVE);
            if (matches) {
                frame->phase = 3;
                child_instruction = code->next;
                descend = 1;
            } else { last = -1; done = 1; }
        } else done = 1;
        if (done) {
            /* Cycle-pruned results depend on active ancestors and cannot
             * be reused after that context has changed. */
            *memo_value = frame->cycle_epoch != cycle_epoch
                ? MEMO_UNVISITED : (last < 0 ? MEMO_FAILED : last + 1);
            --depth;
        } else if (descend) {
            if (limits && limits->max_frames && depth >= limits->max_frames) {
                result = MAIA_REGEX_LIMIT;
                break;
            }
            if (depth == capacity) {
                if (capacity > (size_t)-1 / sizeof(MaiaRegexFrame) / 2) {
                    result = MAIA_REGEX_LIMIT;
                    break;
                }
                next_capacity = capacity * 2;
                if (limits && limits->max_frames && next_capacity > limits->max_frames)
                    next_capacity = limits->max_frames;
                grown = (MaiaRegexFrame *)realloc(frames, next_capacity * sizeof(MaiaRegexFrame));
                if (!grown) { result = MAIA_REGEX_NOMEM; break; }
                frames = grown;
                capacity = next_capacity;
            }
            frames[depth].assertion_depth = frames[depth - 1].assertion_depth
                + (frames[depth - 1].phase == 4 ? 1 : 0);
            frames[depth].cycle_epoch = cycle_epoch;
            frames[depth].instruction = child_instruction;
            frames[depth].position = child_position;
            frames[depth].phase = 0;
            ++depth;
        }
    }
    free(frames);
    free(memo);
    free(sparse.entries);
    if (result != MAIA_REGEX_MATCH) return result;
    if (last < 0) return MAIA_REGEX_NOMATCH;
    *end = (unsigned int)last;
    return MAIA_REGEX_MATCH;
}
