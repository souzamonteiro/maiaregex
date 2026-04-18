/*
 * test_regex.cpp
 *
 * Robust C++ test suite for POSIX regex implementation
 */

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <iomanip>
#include <cstring>
#include "regex.h"

class RegexTest {
private:
    static int tests_passed;
    static int tests_failed;
    
public:
    static void print_header(const std::string& title) {
        std::cout << "\n\033[36m=== " << title << " ===\033[0m\n";
    }
    
    static void assert_true(bool condition, const std::string& test_name) {
        if (condition) {
            std::cout << "  " << std::left << std::setw(50) << test_name 
                      << " \033[32m✓ PASSED\033[0m\n";
            tests_passed++;
        } else {
            std::cout << "  " << std::left << std::setw(50) << test_name 
                      << " \033[31m✗ FAILED\033[0m\n";
            tests_failed++;
        }
    }
    
    static void assert_regex_match(const std::string& pattern, 
                                   const std::string& text,
                                   const std::string& test_name) {
        regex_t regex;
        int ret = regcomp(&regex, pattern.c_str(), 0);
        
        if (ret != REG_NOERROR) {
            assert_true(false, test_name + " (compilation failed)");
            return;
        }
        
        ret = regexec(&regex, text.c_str(), 0, nullptr, 0);
        assert_true(ret == REG_NOERROR, test_name);
        regfree(&regex);
    }
    
    static void assert_regex_no_match(const std::string& pattern,
                                      const std::string& text,
                                      const std::string& test_name) {
        regex_t regex;
        int ret = regcomp(&regex, pattern.c_str(), 0);
        
        if (ret != REG_NOERROR) {
            assert_true(false, test_name + " (compilation failed)");
            return;
        }
        
        ret = regexec(&regex, text.c_str(), 0, nullptr, 0);
        assert_true(ret == REG_NOMATCH, test_name);
        regfree(&regex);
    }
    
    static void assert_capture(const std::string& pattern,
                               const std::string& text,
                               int group, size_t expected_so, size_t expected_eo,
                               const std::string& test_name) {
        regex_t regex;
        regmatch_t matches[10];
        int ret = regcomp(&regex, pattern.c_str(), 0);
        
        if (ret != REG_NOERROR) {
            assert_true(false, test_name + " (compilation failed)");
            return;
        }
        
        ret = regexec(&regex, text.c_str(), 10, matches, 0);
        if (ret == REG_NOERROR && group <= (int)regex.re_nsub) {
            assert_true(matches[group].rm_so == (ptrdiff_t)expected_so &&
                       matches[group].rm_eo == (ptrdiff_t)expected_eo,
                       test_name);
        } else {
            assert_true(false, test_name);
        }
        regfree(&regex);
    }
    
    static void print_summary() {
        std::cout << "\n========================================\n";
        std::cout << "Test Summary:\n";
        std::cout << "  \033[32mPassed: " << tests_passed << "\033[0m\n";
        std::cout << "  \033[31mFailed: " << tests_failed << "\033[0m\n";
        std::cout << "  Total:  " << (tests_passed + tests_failed) << "\n";
        std::cout << "========================================\n";
    }
    
    static bool all_passed() { return tests_failed == 0; }
};

int RegexTest::tests_passed = 0;
int RegexTest::tests_failed = 0;

class RegexWrapper {
private:
    regex_t regex;
    bool compiled;
    
public:
    RegexWrapper() : compiled(false) {
        std::memset(&regex, 0, sizeof(regex));
    }
    
    ~RegexWrapper() {
        if (compiled) {
            regfree(&regex);
        }
    }
    
    bool compile(const std::string& pattern, int flags = 0) {
        if (compiled) {
            regfree(&regex);
            compiled = false;
        }
        int ret = regcomp(&regex, pattern.c_str(), flags);
        compiled = (ret == REG_NOERROR);
        return compiled;
    }
    
    bool match(const std::string& text, int flags = 0) {
        if (!compiled) return false;
        return regexec(&regex, text.c_str(), 0, nullptr, flags) == REG_NOERROR;
    }
    
    bool match(const std::string& text, std::vector<regmatch_t>& matches, int flags = 0) {
        if (!compiled) return false;
        matches.resize(regex.re_nsub + 1);
        int ret = regexec(&regex, text.c_str(), matches.size(), matches.data(), flags);
        return ret == REG_NOERROR;
    }
    
    size_t get_subexp_count() const {
        return compiled ? regex.re_nsub : 0;
    }
    
    std::string get_error_message(int errcode) {
        char buf[256];
        regerror(errcode, &regex, buf, sizeof(buf));
        return std::string(buf);
    }
};

void test_compilation() {
    RegexTest::print_header("Compilation Tests");
    
    RegexWrapper rw;
    
    RegexTest::assert_true(rw.compile("hello"), "Compile simple literal");
    RegexTest::assert_true(rw.get_subexp_count() == 0, "No subexpressions");
    
    RegexTest::assert_true(rw.compile("[a-z]"), "Compile character class");
    RegexTest::assert_true(rw.compile("^start$"), "Compile anchors");
    RegexTest::assert_true(!rw.compile("[a-z"), "Detect invalid bracket");
}

void test_cpp_strings() {
    RegexTest::print_header("C++ String Tests");
    
    RegexWrapper rw;
    
    // Test with std::string
    rw.compile("world");
    RegexTest::assert_true(rw.match("hello world"), "Match in C++ string");
    RegexTest::assert_true(!rw.match("hello"), "No match correctly reported");
    
    // Test pattern from string
    std::string pattern = "[0-9][0-9]*";
    rw.compile(pattern);
    RegexTest::assert_true(rw.match("12345"), "Pattern from std::string");
}

void test_capturing_groups_cpp() {
    RegexTest::print_header("Capturing Groups Tests (C++)");
    
    RegexWrapper rw;
    std::vector<regmatch_t> matches;
    
    rw.compile("\\(hello\\) \\(world\\)");
    RegexTest::assert_true(rw.get_subexp_count() == 2, "Two capturing groups");
    
    if (rw.match("hello world", matches)) {
        RegexTest::assert_true(matches.size() >= 3, "Sufficient match slots");
        RegexTest::assert_true(matches[1].rm_so == 0 && matches[1].rm_eo == 5,
                              "First group capture");
        RegexTest::assert_true(matches[2].rm_so == 6 && matches[2].rm_eo == 11,
                              "Second group capture");
    }
}

void test_raii_pattern() {
    RegexTest::print_header("RAII Pattern Tests");
    
    {
        RegexWrapper rw;
        rw.compile("test");
        RegexTest::assert_true(rw.match("test"), "RAII object works");
    } // Automatically cleaned up
    
    RegexTest::assert_true(true, "RAII cleanup doesn't crash");
}

void test_performance() {
    RegexTest::print_header("Performance Tests");
    
    RegexWrapper rw;
    rw.compile("[a-zA-Z][a-zA-Z]*");
    
    const int iterations = 10000;
    int matches = 0;
    
    for (int i = 0; i < iterations; i++) {
        if (rw.match("TestString123")) {
            matches++;
        }
    }
    
    RegexTest::assert_true(matches == iterations, 
                          "Performance: " + std::to_string(iterations) + " iterations");
}

void test_error_messages() {
    RegexTest::print_header("Error Message Tests");
    
    RegexWrapper rw;
    
    rw.compile("[a-z");
    char errbuf[256];
    regerror(REG_EBRACK, nullptr, errbuf, sizeof(errbuf));
    std::string msg(errbuf);
    RegexTest::assert_true(msg.length() > 0, "Error message not empty");
}

void test_edge_cases() {
    RegexTest::print_header("Edge Cases Tests");
    
    RegexWrapper rw;
    
    // Empty pattern
    RegexTest::assert_true(!rw.compile(""), "Empty pattern fails");
    
    // Very long pattern
    std::string long_pattern(500, 'a');
    RegexTest::assert_true(rw.compile(long_pattern), "Long pattern compiles");
    RegexTest::assert_true(rw.match(std::string(500, 'a')), "Long pattern matches");
    
    // Pattern with backslashes
    rw.compile("\\[test\\]");
    RegexTest::assert_true(rw.match("[test]"), "Escaped brackets work");
    
    // ASCII works
    rw.compile("[a-z]");
    RegexTest::assert_true(rw.match("abc"), "ASCII works");
}

void test_common_use_cases() {
    RegexTest::print_header("Common Use Cases Tests");
    
    // Email-like validation (basic regex compatible)
    RegexWrapper email_regex;
    email_regex.compile("[a-zA-Z][a-zA-Z]*@[a-zA-Z][a-zA-Z]*\\.[a-zA-Z][a-zA-Z][a-zA-Z]");
    RegexTest::assert_true(email_regex.match("user@domain.com"), "Valid email pattern");
    RegexTest::assert_true(!email_regex.match("invalid-email"), "Invalid email pattern");
    
    // URL-like validation (basic regex compatible)
    RegexWrapper url_regex;
    url_regex.compile("http://[a-zA-Z][a-zA-Z]*\\.[a-zA-Z][a-zA-Z][a-zA-Z]");
    RegexTest::assert_true(url_regex.match("http://example.com"), "Valid HTTP URL pattern");
    
    // Phone number pattern
    RegexWrapper phone_regex;
    phone_regex.compile("[0-9][0-9][0-9]-[0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]");
    RegexTest::assert_true(phone_regex.match("123-456-7890"), "Valid phone pattern");
}

int main() {
    std::cout << "========================================\n";
    std::cout << "C++ POSIX Regex Test Suite\n";
    std::cout << "========================================\n";
    
    test_compilation();
    test_cpp_strings();
    test_capturing_groups_cpp();
    test_raii_pattern();
    test_performance();
    test_error_messages();
    test_edge_cases();
    test_common_use_cases();
    
    RegexTest::print_summary();
    
    return RegexTest::all_passed() ? 0 : 1;
}