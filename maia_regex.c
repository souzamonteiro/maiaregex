#include "maia_regex.h"
#include <stdlib.h>
#include <limits.h>

typedef struct {
    unsigned int instruction;
    unsigned int position;
    int phase;
} MaiaRegexFrame;

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
    int *memo;
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
    memo = (int *)calloc(cells, sizeof(int));
    if (!memo) return MAIA_REGEX_NOMEM;
    frames = (MaiaRegexFrame *)malloc(capacity * sizeof(MaiaRegexFrame));
    if (!frames) { free(memo); return MAIA_REGEX_NOMEM; }
    frames[0].instruction = program->entry;
    frames[0].position = start;
    frames[0].phase = 0;
    depth = 1;
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
        code = program->code + frame->instruction;
        descend = 0;
        done = 0;
        child_instruction = 0;
        child_position = frame->position;
        if (frame->phase == 0) {
            if (memo[slot]) {
                last = memo[slot] > 0 ? memo[slot] - 1 : -1;
                --depth;
                continue;
            }
            memo[slot] = -1;
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
            memo[slot] = last < 0 ? -1 : last + 1;
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
            frames[depth].instruction = child_instruction;
            frames[depth].position = child_position;
            frames[depth].phase = 0;
            ++depth;
        }
    }
    free(frames);
    free(memo);
    if (result != MAIA_REGEX_MATCH) return result;
    if (last < 0) return MAIA_REGEX_NOMATCH;
    *end = (unsigned int)last;
    return MAIA_REGEX_MATCH;
}