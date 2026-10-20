/* Small bounded graphs checked against ordered DFS without memoization.
 * This reference intentionally uses recursion; the production runtime does not.
 */
#include "maia_regex.h"
#include <stdio.h>

#define MAX_CODE 9
#define MAX_INPUT 4
#define UNSEEN -1
#define NO_MATCH -1
#define INVALID_CYCLE -2

static unsigned long seed = 20261019UL;

static unsigned int sample(unsigned int bound)
{
    seed = (1664525UL * seed + 1013904223UL) & 0xffffffffUL;
    return (unsigned int)((seed >> 8) % bound);
}

static int reference(const MaiaRegexProgram *program, const unsigned int *input,
                     unsigned int length, unsigned int pc, unsigned int position,
                     int assertion_depth, int active[MAX_CODE][MAX_INPUT + 1])
{
    const MaiaRegexInstruction *instruction;
    int answer, child;
    if (active[pc][position] != UNSEEN)
        return active[pc][position] == assertion_depth ? NO_MATCH : INVALID_CYCLE;
    active[pc][position] = assertion_depth;
    instruction = program->code + pc;
    answer = NO_MATCH;
    switch (instruction->op) {
    case MAIA_REGEX_ACCEPT:
        answer = (int)position;
        break;
    case MAIA_REGEX_CHAR:
        if (position < length && input[position] == instruction->first)
            answer = reference(program, input, length, instruction->next,
                               position + 1, assertion_depth, active);
        break;
    case MAIA_REGEX_END:
        if (position == length)
            answer = reference(program, input, length, instruction->next,
                               position, assertion_depth, active);
        break;
    case MAIA_REGEX_SPLIT:
        answer = reference(program, input, length, instruction->first,
                           position, assertion_depth, active);
        if (answer == NO_MATCH)
            answer = reference(program, input, length, instruction->second,
                               position, assertion_depth, active);
        break;
    case MAIA_REGEX_POSITIVE:
    case MAIA_REGEX_NEGATIVE:
        child = reference(program, input, length, instruction->first,
                          position, assertion_depth + 1, active);
        if (child == INVALID_CYCLE) answer = INVALID_CYCLE;
        else if ((child >= 0) == (instruction->op == MAIA_REGEX_POSITIVE))
            answer = reference(program, input, length, instruction->next,
                               position, assertion_depth, active);
        break;
    }
    active[pc][position] = UNSEEN;
    return answer;
}

int main(void)
{
    static const int operations[] = {
        MAIA_REGEX_ACCEPT, MAIA_REGEX_CHAR, MAIA_REGEX_CHAR,
        MAIA_REGEX_SPLIT, MAIA_REGEX_SPLIT, MAIA_REGEX_END,
        MAIA_REGEX_POSITIVE, MAIA_REGEX_NEGATIVE
    };
    MaiaRegexInstruction code[MAX_CODE];
    MaiaRegexProgram program;
    MaiaRegexLimits limits = { 0, 128, 100000 };
    unsigned int input[MAX_INPUT];
    unsigned int trial, index, position, length, start, end;
    int active[MAX_CODE][MAX_INPUT + 1];
    int expected, status, expected_status;
    program.code = code;
    program.ranges = 0;
    program.range_count = 0;
    for (trial = 0; trial < 100000; ++trial) {
        program.instruction_count = sample(MAX_CODE) + 1;
        program.entry = sample(program.instruction_count);
        for (index = 0; index < program.instruction_count; ++index) {
            code[index].op = operations[sample(8)];
            code[index].first = code[index].op == MAIA_REGEX_CHAR
                ? 97 + sample(2) : sample(program.instruction_count);
            code[index].second = sample(program.instruction_count);
            code[index].next = sample(program.instruction_count);
        }
        length = sample(MAX_INPUT + 1);
        start = sample(length + 1);
        for (index = 0; index < length; ++index) input[index] = 97 + sample(2);
        for (index = 0; index < MAX_CODE; ++index)
            for (position = 0; position <= MAX_INPUT; ++position)
                active[index][position] = UNSEEN;
        expected = reference(&program, input, length, program.entry, start, 0, active);
        expected_status = expected == INVALID_CYCLE ? MAIA_REGEX_INVALID
            : (expected == NO_MATCH ? MAIA_REGEX_NOMATCH : MAIA_REGEX_MATCH);
        end = 1234567;
        status = maia_regex_exec(&program, input, length, start, &limits, &end);
        if (status != expected_status
            || end != (expected >= 0 ? (unsigned int)expected : 1234567U)) {
            printf("Reference mismatch at trial %u: status %d/%d, end %u/%d\n",
                   trial, status, expected_status, end, expected);
            return 1;
        }
    }
    printf("MAIA_REGEX_REFERENCE: 100000 comparisons, 0 failures\n");
    return 0;
}
