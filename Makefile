# Makefile for POSIX regex library and tests

CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -O2 -g -std=c99
CXXFLAGS = -Wall -Wextra -O2 -g -std=c++11
LDFLAGS = 

TARGETS = libregex.a test_regex_c test_regex_cpp

all: $(TARGETS)

libregex.a: regex.o
	ar rcs $@ $^

regex.o: regex.c regex.h
	$(CC) $(CFLAGS) -c $< -o $@

test_regex_c: test_regex.c libregex.a
	$(CC) $(CFLAGS) -o $@ test_regex.c -L. -lregex $(LDFLAGS)

test_regex_cpp: test_regex.cpp libregex.a
	$(CXX) $(CXXFLAGS) -o $@ test_regex.cpp -L. -lregex $(LDFLAGS)

test: test_regex_c test_regex_cpp
	@echo "\n=== Running C tests ===\n"
	./test_regex_c
	@echo "\n=== Running C++ tests ===\n"
	./test_regex_cpp

clean:
	rm -f *.o *.a $(TARGETS)

install:
	@echo "To install, copy regex.h to /usr/local/include and libregex.a to /usr/local/lib"

.PHONY: all test clean install