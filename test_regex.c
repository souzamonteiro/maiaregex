/*
 * test_regex.c
 *
 * Robust test suite for POSIX regex implementation
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "regex.h"

#define TEST_PASSED "\033[32mPASSED\033[0m"
#define TEST_FAILED "\033[31mFAILED\033[0m"

static int tests_passed = 0;
static int tests_failed = 0;

static void test_assert(int condition, const char *test_name)
{
    if (condition) {
        printf("  %s: %s\n", test_name, TEST_PASSED);
        tests_passed++;
    } else {
        printf("  %s: %s\n", test_name, TEST_FAILED);
        tests_failed++;
    }
}

static void test_simple_match(void)
{
    printf("\n=== Simple Match Tests ===\n");
    
    regex_t regex;
    regmatch_t matches[10];
    int ret;
    
    /* Test 1: Simple literal match */
    ret = regcomp(&regex, "hello", 0);
    test_assert(ret == REG_NOERROR, "Compile 'hello'");
    if (ret == REG_NOERROR) {
        ret = regexec(&regex, "hello world", 1, matches, 0);
        test_assert(ret == REG_NOERROR, "Match 'hello' in 'hello world'");
        if (ret == REG_NOERROR) {
            test_assert(matches[0].rm_so == 0 && matches[0].rm_eo == 5, 
                       "Correct match position");
        }
        regfree(&regex);
    }
    
    /* Test 2: No match */
    ret = regcomp(&regex, "xyz", 0);
    test_assert(ret == REG_NOERROR, "Compile 'xyz'");
    if (ret == REG_NOERROR) {
        ret = regexec(&regex, "hello world", 1, matches, 0);
        test_assert(ret == REG_NOMATCH, "No match for 'xyz'");
        regfree(&regex);
    }
    
    /* Test 3: Dot metacharacter */
    ret = regcomp(&regex, "h.llo", 0);
    test_assert(ret == REG_NOERROR, "Compile 'h.llo'");
    if (ret == REG_NOERROR) {
        ret = regexec(&regex, "hello", 1, matches, 0);
        test_assert(ret == REG_NOERROR, "Dot matches 'e'");
        ret = regexec(&regex, "hollo", 1, matches, 0);
        test_assert(ret == REG_NOERROR, "Dot matches 'o'");
        regfree(&regex);
    }
}

static void test_character_classes(void)
{
    printf("\n=== Character Class Tests ===\n");
    
    regex_t regex;
    regmatch_t matches[10];
    int ret;
    
    /* Test 1: Character class [aeiou] */
    ret = regcomp(&regex, "[aeiou]", 0);
    test_assert(ret == REG_NOERROR, "Compile '[aeiou]'");
    if (ret == REG_NOERROR) {
        ret = regexec(&regex, "hello", 1, matches, 0);
        test_assert(ret == REG_NOERROR, "Match vowel 'e'");
        test_assert(matches[0].rm_so == 1 && matches[0].rm_eo == 2,
                   "Correct vowel position");
        regfree(&regex);
    }
    
    /* Test 2: Negated class [^aeiou] */
    ret = regcomp(&regex, "[^aeiou]", 0);
    test_assert(ret == REG_NOERROR, "Compile '[^aeiou]'");
    if (ret == REG_NOERROR) {
        ret = regexec(&regex, "hello", 1, matches, 0);
        test_assert(ret == REG_NOERROR, "Match consonant 'h'");
        test_assert(matches[0].rm_so == 0 && matches[0].rm_eo == 1,
                   "Correct consonant position");
        regfree(&regex);
    }
    
    /* Test 3: Range [a-z] */
    ret = regcomp(&regex, "[a-z]", 0);
    test_assert(ret == REG_NOERROR, "Compile '[a-z]'");
    if (ret == REG_NOERROR) {
        ret = regexec(&regex, "Hello", 1, matches, 0);
        test_assert(ret == REG_NOERROR, "Match lowercase 'e'");
        regfree(&regex);
    }
    
    /* Test 4: Invalid bracket */
    ret = regcomp(&regex, "[a-z", 0);
    test_assert(ret == REG_EBRACK, "Detect unmatched bracket");
}

static void test_anchors(void)
{
    printf("\n=== Anchor Tests ===\n");
    
    regex_t regex;
    regmatch_t matches[10];
    int ret;
    
    /* Test 1: Start anchor ^ */
    ret = regcomp(&regex, "^hello", 0);
    test_assert(ret == REG_NOERROR, "Compile '^hello'");
    if (ret == REG_NOERROR) {
        ret = regexec(&regex, "hello world", 1, matches, 0);
        test_assert(ret == REG_NOERROR, "Match at start");
        test_assert(matches[0].rm_so == 0, "Correct start position");
        
        ret = regexec(&regex, "say hello", 1, matches, 0);
        test_assert(ret == REG_NOMATCH, "No match when not at start");
        regfree(&regex);
    }
    
    /* Test 2: End anchor $ */
    ret = regcomp(&regex, "world$", 0);
    test_assert(ret == REG_NOERROR, "Compile 'world$'");
    if (ret == REG_NOERROR) {
        ret = regexec(&regex, "hello world", 1, matches, 0);
        test_assert(ret == REG_NOERROR, "Match at end");
        
        ret = regexec(&regex, "world hello", 1, matches, 0);
        test_assert(ret == REG_NOMATCH, "No match when not at end");
        regfree(&regex);
    }
}

static void test_repetition(void)
{
    printf("\n=== Repetition Tests ===\n");
    
    regex_t regex;
    regmatch_t matches[10];
    int ret;
    
    /* Test 1: Zero or more * */
    ret = regcomp(&regex, "ho*", 0);
    test_assert(ret == REG_NOERROR, "Compile 'ho*'");
    if (ret == REG_NOERROR) {
        ret = regexec(&regex, "h", 1, matches, 0);
        test_assert(ret == REG_NOERROR, "Zero 'o' matches");
        
        ret = regexec(&regex, "hooo", 1, matches, 0);
        test_assert(ret == REG_NOERROR, "Multiple 'o's match");
        regfree(&regex);
    }
    
    /* Test 2: Using multiple characters for "one or more" semantics */
    ret = regcomp(&regex, "hoo*", 0);
    test_assert(ret == REG_NOERROR, "Compile 'hoo*'");
    if (ret == REG_NOERROR) {
        ret = regexec(&regex, "ho", 1, matches, 0);
        test_assert(ret == REG_NOERROR, "One 'o' matches");
        
        ret = regexec(&regex, "hooo", 1, matches, 0);
        test_assert(ret == REG_NOERROR, "Multiple 'o's match");
        regfree(&regex);
    }
}

static void test_subexpressions(void)
{
    printf("\n=== Subexpression Tests ===\n");
    
    regex_t regex;
    regmatch_t matches[10];
    int ret;
    
    /* Test 1: Capturing group */
    ret = regcomp(&regex, "\\(hello\\)", 0);
    test_assert(ret == REG_NOERROR, "Compile '\\(hello\\)'");
    if (ret == REG_NOERROR) {
        test_assert(regex.re_nsub == 1, "Correct number of subexpressions");
        
        ret = regexec(&regex, "hello world", 10, matches, 0);
        test_assert(ret == REG_NOERROR, "Match group");
        test_assert(matches[1].rm_so == 0 && matches[1].rm_eo == 5,
                   "Correct group capture");
        regfree(&regex);
    }
    
    /* Test 2: Back reference */
    ret = regcomp(&regex, "\\([a-z]\\)\\1", 0);
    test_assert(ret == REG_NOERROR, "Compile '\\([a-z]\\)\\1'");
    if (ret == REG_NOERROR) {
        ret = regexec(&regex, "aa", 10, matches, 0);
        test_assert(ret == REG_NOERROR, "Double letter matches");
        
        ret = regexec(&regex, "ab", 10, matches, 0);
        test_assert(ret == REG_NOMATCH, "Different letters don't match");
        regfree(&regex);
    }
    
    /* Test 3: Multiple groups */
    ret = regcomp(&regex, "\\(ab\\)\\(cd\\)", 0);
    test_assert(ret == REG_NOERROR, "Compile '\\(ab\\)\\(cd\\)'");
    if (ret == REG_NOERROR) {
        test_assert(regex.re_nsub == 2, "Correct number of subexpressions");
        regfree(&regex);
    }
}

static void test_word_boundaries(void)
{
    printf("\n=== Word Boundary Tests ===\n");
    
    regex_t regex;
    regmatch_t matches[10];
    int ret;
    
    /* Test 1: Beginning of word \\< */
    ret = regcomp(&regex, "\\<hello", 0);
    test_assert(ret == REG_NOERROR, "Compile '\\<hello'");
    if (ret == REG_NOERROR) {
        ret = regexec(&regex, "hello world", 1, matches, 0);
        test_assert(ret == REG_NOERROR, "Match at word start");
        
        ret = regexec(&regex, "sayhello", 1, matches, 0);
        test_assert(ret == REG_NOMATCH, "No match when not word start");
        regfree(&regex);
    }
    
    /* Test 2: End of word \\> */
    ret = regcomp(&regex, "world\\>", 0);
    test_assert(ret == REG_NOERROR, "Compile 'world\\>'");
    if (ret == REG_NOERROR) {
        ret = regexec(&regex, "hello world", 1, matches, 0);
        test_assert(ret == REG_NOERROR, "Match at word end");
        regfree(&regex);
    }
}

static void test_error_handling(void)
{
    printf("\n=== Error Handling Tests ===\n");
    
    regex_t regex;
    char errbuf[256];
    int ret;
    
    /* Test 1: Invalid pattern */
    ret = regcomp(&regex, "[a-z", 0);
    test_assert(ret == REG_EBRACK, "Invalid bracket detected");
    
    /* Test 2: regerror function */
    regerror(ret, NULL, errbuf, sizeof(errbuf));
    test_assert(strlen(errbuf) > 0, "regerror returns message");
    
    /* Test 3: NULL pattern */
    ret = regcomp(&regex, NULL, 0);
    test_assert(ret == REG_BADPAT, "NULL pattern rejected");
    
    /* Test 4: NULL regex */
    ret = regexec(NULL, "test", 0, NULL, 0);
    test_assert(ret == REG_BADPAT, "NULL regex rejected");
}

static void test_complex_patterns(void)
{
    printf("\n=== Complex Pattern Tests ===\n");
    
    regex_t regex;
    regmatch_t matches[10];
    int ret;
    
    /* Test 1: Pattern with multiple character classes (email-like) */
    ret = regcomp(&regex, "[a-z][a-z]*@[a-z][a-z]*\\.[a-z][a-z][a-z]", 0);
    test_assert(ret == REG_NOERROR, "Compile email-like pattern");
    if (ret == REG_NOERROR) {
        ret = regexec(&regex, "user@domain.com", 1, matches, 0);
        test_assert(ret == REG_NOERROR, "Email-like pattern matches");
        regfree(&regex);
    }
    
    /* Test 2: IP-like pattern */
    ret = regcomp(&regex, "[0-9][0-9]*\\.[0-9][0-9]*\\.[0-9][0-9]*\\.[0-9][0-9]*", 0);
    test_assert(ret == REG_NOERROR, "Compile IP-like pattern");
    if (ret == REG_NOERROR) {
        ret = regexec(&regex, "192.168.1.1", 1, matches, 0);
        test_assert(ret == REG_NOERROR, "IP-like pattern matches");
        regfree(&regex);
    }
    
    /* Test 3: Pattern with word boundaries */
    ret = regcomp(&regex, "\\<[a-z][a-z]*\\>", 0);
    test_assert(ret == REG_NOERROR, "Compile word pattern");
    if (ret == REG_NOERROR) {
        ret = regexec(&regex, "hello world", 1, matches, 0);
        test_assert(ret == REG_NOERROR, "Word pattern matches");
        regfree(&regex);
    }
    
    /* Test 4: Pattern with character class ranges */
    ret = regcomp(&regex, "[A-Z][a-z][a-z]*", 0);
    test_assert(ret == REG_NOERROR, "Compile capitalized word pattern");
    if (ret == REG_NOERROR) {
        ret = regexec(&regex, "Hello", 1, matches, 0);
        test_assert(ret == REG_NOERROR, "Capitalized word matches");
        regfree(&regex);
    }
}

static void test_regfree(void)
{
    printf("\n=== regfree Tests ===\n");
    
    regex_t regex;
    int ret;
    
    /* Test 1: Normal regfree */
    ret = regcomp(&regex, "test", 0);
    test_assert(ret == REG_NOERROR, "Compile for regfree test");
    regfree(&regex);
    test_assert(regex.re_compiled == NULL, "regfree frees memory");
    
    /* Test 2: regfree on uninitialized */
    memset(&regex, 0, sizeof(regex));
    regfree(&regex);  /* Should not crash */
    test_assert(1, "regfree on zeroed structure doesn't crash");
    
    /* Test 3: Multiple regfree */
    ret = regcomp(&regex, "test2", 0);
    test_assert(ret == REG_NOERROR, "Second compile");
    regfree(&regex);
    regfree(&regex);  /* Double free should be safe */
    test_assert(1, "Double regfree is safe");
}

int main(void)
{
    printf("========================================\n");
    printf("POSIX Regex Implementation Test Suite\n");
    printf("========================================\n");
    
    test_simple_match();
    test_character_classes();
    test_anchors();
    test_repetition();
    test_subexpressions();
    test_word_boundaries();
    test_error_handling();
    test_complex_patterns();
    test_regfree();
    
    printf("\n========================================\n");
    printf("Test Summary:\n");
    printf("  Passed: %d\n", tests_passed);
    printf("  Failed: %d\n", tests_failed);
    printf("  Total:  %d\n", tests_passed + tests_failed);
    printf("========================================\n");
    
    return tests_failed > 0 ? 1 : 0;
}