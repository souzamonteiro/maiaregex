#include "maia_regex.h"
#include <stdio.h>
#include <stdlib.h>

static int failures = 0;
static int checks = 0;

static void verify(int condition, const char *name)
{
    ++checks;
    if (!condition) { ++failures; printf("FAIL: %s\n", name); }
}

static void expect(const MaiaRegexProgram *program, const unsigned int *input,
                   unsigned int length, unsigned int start,
                   const MaiaRegexLimits *limits, int status,
                   unsigned int expected_end, const char *name)
{
    unsigned int end = 1234567;
    int result = maia_regex_exec(program, input, length, start, limits, &end);
    verify(result == status && end == (status == MAIA_REGEX_MATCH ? expected_end : 1234567), name);
}

static void test_cycle_context(void)
{
    MaiaRegexInstruction code[] = {
        { MAIA_REGEX_ACCEPT, 0, 0, 0 },
        { MAIA_REGEX_CHAR, 98, 0, 0 },
        { MAIA_REGEX_CHAR, 97, 0, 1 },
        { MAIA_REGEX_CHAR, 97, 0, 0 },
        { MAIA_REGEX_SPLIT, 5, 2, 0 },
        { MAIA_REGEX_SPLIT, 4, 3, 0 },
        { MAIA_REGEX_CHAR, 122, 0, 0 },
        { MAIA_REGEX_POSITIVE, 4, 0, 6 },
        { MAIA_REGEX_SPLIT, 7, 5, 0 }
    };
    MaiaRegexProgram program;
    unsigned int input[] = { 97, 98 };
    program.code = code;
    program.ranges = 0;
    program.instruction_count = 9;
    program.range_count = 0;
    program.entry = 8;
    expect(&program, input, 2, 0, 0, MAIA_REGEX_MATCH, 2, "cycle-pruned assertion results are not cached across contexts");
    expect(&program, input, 1, 0, 0, MAIA_REGEX_MATCH, 1, "ordered cycle fallback remains available");
    code[7].op = MAIA_REGEX_NEGATIVE;
    expect(&program, input, 2, 0, 0, MAIA_REGEX_MATCH, 2, "negative assertion does not cache cycle-dependent results");
}

int main(void)
{
    MaiaRegexInstruction code[] = {
        { MAIA_REGEX_ACCEPT, 0, 0, 0 },
        { MAIA_REGEX_CHAR, 97, 0, 2 },
        { MAIA_REGEX_SPLIT, 1, 0, 0 }
    };
    MaiaRegexProgram program;
    unsigned int input[] = { 97, 97, 97 };
    unsigned int unicode[] = { 0, 233, 55357, 56832 };
    MaiaRegexRange ranges[] = { { 0, 0 }, { 128, 65535 } };
    MaiaRegexLimits limits = { 0, 0, 0 };
    unsigned int *long_input;
    unsigned int index;
    program.code = code;
    program.ranges = 0;
    program.instruction_count = 3;
    program.range_count = 0;
    program.entry = 2;
    expect(&program, input, 3, 0, 0, MAIA_REGEX_MATCH, 3, "greedy repetition");
    expect(&program, input, 3, 2, 0, MAIA_REGEX_MATCH, 3, "nonzero start");
    expect(&program, 0, 0, 0, 0, MAIA_REGEX_MATCH, 0, "empty input");
    limits.max_memo_bytes = 1;
    expect(&program, input, 3, 0, &limits, MAIA_REGEX_LIMIT, 0, "memo limit");
    limits.max_memo_bytes = 0;
    limits.max_frames = 1;
    expect(&program, input, 3, 0, &limits, MAIA_REGEX_LIMIT, 0, "frame limit");
    limits.max_frames = 0;
    limits.max_steps = 1;
    expect(&program, input, 3, 0, &limits, MAIA_REGEX_LIMIT, 0, "step limit");
    limits.max_steps = 0;
    long_input = (unsigned int *)malloc(100000 * sizeof(unsigned int));
    verify(long_input != 0, "long-input allocation");
    if (long_input) {
        for (index = 0; index < 100000; ++index) long_input[index] = 97;
        expect(&program, long_input, 100000, 0, 0, MAIA_REGEX_MATCH, 100000, "long repetition without recursion");
        free(long_input);
    }
    code[2].first = 0;
    code[2].second = 1;
    expect(&program, input, 3, 0, 0, MAIA_REGEX_MATCH, 0, "lazy repetition");
    code[2].first = 2;
    code[2].second = 0;
    expect(&program, input, 3, 0, 0, MAIA_REGEX_MATCH, 0, "epsilon cycle terminates");
    code[2].second = 2;
    expect(&program, input, 3, 0, 0, MAIA_REGEX_NOMATCH, 0, "program without reachable accept terminates");
    code[2].op = MAIA_REGEX_NEGATIVE;
    code[2].first = 2;
    code[2].next = 0;
    expect(&program, input, 3, 0, 0, MAIA_REGEX_INVALID, 0, "recursive negative assertion has no defined truth value");
    code[2].op = MAIA_REGEX_POSITIVE;
    expect(&program, input, 3, 0, 0, MAIA_REGEX_INVALID, 0, "recursive positive assertion is rejected consistently");
    code[2].op = MAIA_REGEX_SPLIT;
    code[2].second = 0;
    code[2].first = 99;
    expect(&program, input, 3, 0, 0, MAIA_REGEX_INVALID, 0, "invalid branch");
    code[2].first = 1;
    code[2].op = MAIA_REGEX_POSITIVE;
    code[2].next = 0;
    code[1].next = 0;
    expect(&program, input, 3, 0, 0, MAIA_REGEX_MATCH, 0, "positive assertion does not consume");
    code[2].op = MAIA_REGEX_NEGATIVE;
    expect(&program, input, 3, 0, 0, MAIA_REGEX_NOMATCH, 0, "negative assertion fails on match");
    code[1].first = 98;
    expect(&program, input, 3, 0, 0, MAIA_REGEX_MATCH, 0, "negative assertion succeeds");
    code[2].op = MAIA_REGEX_END;
    expect(&program, input, 3, 0, 0, MAIA_REGEX_NOMATCH, 0, "end anchor fails before input end");
    expect(&program, input, 3, 3, 0, MAIA_REGEX_MATCH, 3, "end anchor at input end");
    input[0] = 10;
    expect(&program, input, 1, 0, 0, MAIA_REGEX_NOMATCH, 0, "end anchor does not ignore final newline");
    code[1].op = MAIA_REGEX_CLASS;
    code[1].first = 0;
    code[1].second = 2;
    program.ranges = ranges;
    program.range_count = 2;
    program.entry = 1;
    for (index = 0; index < 4; ++index)
        expect(&program, unicode, 4, index, 0, MAIA_REGEX_MATCH, index + 1, "NUL and Unicode code units");
    code[1].op = MAIA_REGEX_NOT_CLASS;
    expect(&program, input, 1, 0, 0, MAIA_REGEX_MATCH, 1, "negated class");
    expect(&program, unicode, 4, 0, 0, MAIA_REGEX_NOMATCH, 0, "negated class rejection");
    code[1].second = 3;
    expect(&program, input, 1, 0, 0, MAIA_REGEX_INVALID, 0, "range table bounds");
    code[1].second = 2;
    ranges[0].last = 65536;
    expect(&program, input, 1, 0, 0, MAIA_REGEX_INVALID, 0, "invalid code-unit range");
    ranges[0].last = 0;
    code[1].op = 99;
    expect(&program, input, 1, 0, 0, MAIA_REGEX_INVALID, 0, "invalid opcode");
    code[1].op = MAIA_REGEX_CHAR;
    code[1].first = 97;
    code[1].next = 99;
    expect(&program, input, 1, 0, 0, MAIA_REGEX_INVALID, 0, "invalid continuation");
    code[1].next = 0;
    expect(&program, 0, 1, 0, 0, MAIA_REGEX_INVALID, 0, "null nonempty input");
    expect(&program, input, 1, 2, 0, MAIA_REGEX_INVALID, 0, "start beyond end");
    expect(0, input, 1, 0, 0, MAIA_REGEX_INVALID, 0, "null program");
    input[0] = 65536;
    expect(&program, input, 1, 0, 0, MAIA_REGEX_INVALID, 0, "invalid input code unit");
    verify(maia_regex_exec(&program, input, 0, 0, 0, 0) == MAIA_REGEX_INVALID, "null result pointer");
    test_cycle_context();
    printf("MAIA_REGEX_PROGRAM: %d checks, %d failures\n", checks, failures);
    return failures ? 1 : 0;
}
