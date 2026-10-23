/* Exercise actual private scratch helpers and allocation failures without a new API. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "maia_regex.h"

typedef struct { void *pointer; size_t bytes; } Allocation;
static Allocation allocations[16];
static size_t attempts, fail_at, live_bytes, peak_bytes, calloc_bytes;
static void remember(void *pointer, size_t bytes)
{
    unsigned int i;
    if (!pointer) return;
    for (i = 0; i < 16; ++i) if (!allocations[i].pointer) {
        allocations[i].pointer = pointer; allocations[i].bytes = bytes;
        live_bytes += bytes; if (live_bytes > peak_bytes) peak_bytes = live_bytes; return;
    }
    assert(0);
}
static void *checked_malloc(size_t bytes)
{
    void *pointer;
    if (++attempts == fail_at) return 0;
    pointer = malloc(bytes); remember(pointer, bytes); return pointer;
}
static void *checked_calloc(size_t count, size_t bytes)
{
    void *pointer;
    assert(!bytes || count <= (size_t)-1 / bytes);
    calloc_bytes += count * bytes;
    if (++attempts == fail_at) return 0;
    pointer = calloc(count, bytes); remember(pointer, count * bytes); return pointer;
}
static void checked_free(void *pointer)
{
    unsigned int i;
    if (!pointer) return;
    for (i = 0; i < 16; ++i) if (allocations[i].pointer == pointer) {
        live_bytes -= allocations[i].bytes; allocations[i].pointer = 0; free(pointer); return;
    }
    assert(0);
}
static void *checked_realloc(void *pointer, size_t bytes)
{
    unsigned int i;
    void *grown;
    if (++attempts == fail_at) return 0;
    for (i = 0; i < 16; ++i) if (allocations[i].pointer == pointer) {
        grown = realloc(pointer, bytes);
        if (!grown) return 0;
        live_bytes -= allocations[i].bytes; allocations[i].pointer = 0;
        remember(grown, bytes); return grown;
    }
    assert(0); return 0;
}
#define malloc checked_malloc
#define calloc checked_calloc
#define realloc checked_realloc
#define free checked_free
#include "maia_regex.c"
#undef malloc
#undef calloc
#undef realloc
#undef free

static void reset(size_t failure)
{
    assert(live_bytes == 0);
    attempts = 0; fail_at = failure; peak_bytes = 0; calloc_bytes = 0;
}
static void collisions(void)
{
    MaiaRegexMemo memo;
    size_t keys[400], cell, count, i;
    int status = MAIA_REGEX_MATCH;
    int *value;
    reset(0); memo.capacity = 16; memo.used = 0;
    memo.entries = (MaiaRegexMemoEntry *)checked_calloc(16, sizeof(MaiaRegexMemoEntry));
    count = 0;
    for (cell = 0; count < 400; ++cell) {
        if (maia_regex_memo_hash(cell + 1, 16) != 0) continue;
        keys[count] = cell; value = maia_regex_memo_slot(&memo, cell, &status);
        assert(value && status == MAIA_REGEX_MATCH); *value = (int)++count;
    }
    assert(memo.used == 400 && memo.capacity >= 1024);
    value = maia_regex_memo_slot(&memo, keys[0], &status); assert(value); *value = MEMO_UNVISITED;
    for (i = 0; i < 400; ++i) {
        value = maia_regex_memo_slot(&memo, keys[i], &status);
        assert(value && *value == (i ? (int)i + 1 : MEMO_UNVISITED));
    }
    assert(memo.used == 400);
    checked_free(memo.entries); assert(live_bytes == 0);
}
int main(void)
{
    static unsigned int input[65536];
    MaiaRegexInstruction repeat[] = {{MAIA_REGEX_ACCEPT,0,0,0},{MAIA_REGEX_CHAR,97,0,2},{MAIA_REGEX_SPLIT,1,0,0}};
    MaiaRegexInstruction code[128];
    MaiaRegexProgram program;
    MaiaRegexLimits dense = {0,0,0};
    unsigned int end, i;
    size_t failure, count, sparse_bytes, dense_bytes;
    int status;
    collisions();
    for (i = 0; i < 65536; ++i) input[i] = 97;
    program.code = repeat; program.ranges = 0; program.range_count = 0;
    program.instruction_count = 3; program.entry = 2;
    for (i = 0; i < 2; ++i) {
        dense.max_memo_bytes = i ? 3 * 513 * sizeof(int) : 0;
        reset(0); end = 1234567;
        assert(maia_regex_exec(&program,input,512,0,&dense,&end) == MAIA_REGEX_MATCH && end == 512);
        count = attempts; assert(count > 2); assert(live_bytes == 0);
        for (failure = 1; failure <= count; ++failure) {
            reset(failure); end = 1234567;
            status = maia_regex_exec(&program,input,512,0,&dense,&end);
            assert(status == MAIA_REGEX_NOMEM && end == 1234567 && live_bytes == 0);
        }
    }
    for (i = 0; i < 128; ++i) {
        code[i].op = MAIA_REGEX_ACCEPT; code[i].first = 0; code[i].second = 0; code[i].next = 0;
    }
    code[0].op = MAIA_REGEX_CHAR; code[0].first = 122; code[0].next = 1;
    program.code = code; program.instruction_count = 128; program.entry = 0;
    reset(0); end = 1234567;
    assert(maia_regex_exec(&program,input,65536,0,0,&end) == MAIA_REGEX_NOMATCH);
    assert(end == 1234567 && live_bytes == 0);
    sparse_bytes = calloc_bytes; assert(sparse_bytes == 16 * sizeof(MaiaRegexMemoEntry));
    dense.max_memo_bytes = 128 * ((size_t)65536 + 1) * sizeof(int);
    reset(0);
    assert(maia_regex_exec(&program,input,65536,0,&dense,&end) == MAIA_REGEX_NOMATCH);
    dense_bytes = calloc_bytes;
    assert(dense_bytes == dense.max_memo_bytes && end == 1234567 && live_bytes == 0);
    --dense.max_memo_bytes; reset(0);
    assert(maia_regex_exec(&program,input,65536,0,&dense,&end) == MAIA_REGEX_LIMIT);
    assert(attempts == 0 && end == 1234567 && live_bytes == 0);
    printf("MAIA_REGEX_SPARSE: collisions/growth/cycle-reset identity, every allocation failure, exact byte budget; immediate-fail memo bytes %lu sparse/%lu dense\n",(unsigned long)sparse_bytes,(unsigned long)dense_bytes);
    return 0;
}
