# Makefile for POSIX regex library and tests

CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -O2 -g -std=c99
CXXFLAGS = -Wall -Wextra -O2 -g -std=c++11
LDFLAGS = 

TARGETS = libregex.a test_regex_c test_regex_cpp test_regex_program test_regex_program_reference test_regex_program_sparse

all: $(TARGETS)

libregex.a: regex.o maia_regex.o
	ar rcs $@ $^

maia_regex.o: maia_regex.c maia_regex.h
	$(CC) -Wall -Wextra -O2 -std=c89 -pedantic-errors -c $< -o $@

test_regex_program: test_regex_program.c maia_regex.o
	$(CC) -Wall -Wextra -O2 -std=c89 -pedantic-errors -o $@ $^

test_regex_program_reference: test_regex_program_reference.c maia_regex.o
	$(CC) -Wall -Wextra -O2 -std=c89 -pedantic-errors -o $@ $^

test_regex_program_sparse: test_regex_program_sparse.c maia_regex.c maia_regex.h
	$(CC) -Wall -Wextra -O2 -std=c89 -pedantic-errors -o $@ test_regex_program_sparse.c

regex.o: regex.c regex.h
	$(CC) $(CFLAGS) -c $< -o $@

test_regex_c: test_regex.c libregex.a
	$(CC) $(CFLAGS) -o $@ test_regex.c -L. -lregex $(LDFLAGS)

test_regex_cpp: test_regex.cpp libregex.a
	$(CXX) $(CXXFLAGS) -o $@ test_regex.cpp -L. -lregex $(LDFLAGS)

test: test_regex_c test_regex_cpp test_regex_program test_regex_program_reference test_regex_program_sparse
	./test_regex_program
	./test_regex_program_reference
	./test_regex_program_sparse
	@echo "\n=== Running C tests ===\n"
	./test_regex_c
	@echo "\n=== Running C++ tests ===\n"
	./test_regex_cpp

clean:
	rm -f *.o *.a $(TARGETS)

install:
	@echo "To install, copy regex.h and maia_regex.h to /usr/local/include and libregex.a to /usr/local/lib"

.PHONY: all test clean install

# Additive BRE development gates. Existing targets and compiler flags stay intact.
bre-generate:
	node scripts/generate-bre.mjs

bre-native:
	node scripts/test-bre-bootstrap-policy.mjs
	node scripts/check-bre-bootstrap.mjs
	node scripts/build-bre-native.mjs

bre-test: bre-native
	node scripts/test-bre-syntax.mjs
	node scripts/test-bre-frontends.mjs
	./build/bre/api
	./build/bre/concurrent
	node scripts/test-bre-matching.mjs
	node scripts/test-bre-reference.mjs --native-only

bre-wasm:
	node --max-old-space-size=16384 scripts/build-bre-wasm.mjs
	node scripts/test-bre-matching.mjs --wasm
	node scripts/test-bre-model.mjs
	node scripts/test-bre-reference.mjs
	node scripts/test-bre-resources.mjs
	node scripts/build-bre-fault-wasm.mjs
	node scripts/test-bre-fault-wasm.mjs
	node --max-old-space-size=16384 scripts/build-bre-wasm.mjs --frontend
	node scripts/test-bre-frontends.mjs --wasm
	node scripts/test-bre-ordered-wasm.mjs

bre-sanitize:
	node scripts/build-bre-native.mjs --sanitize
	./build/bre-sanitize/api
	./build/bre-sanitize/concurrent
	node scripts/test-bre-matching.mjs --sanitize
	node scripts/test-bre-allocation.mjs

.PHONY: bre-generate bre-native bre-test bre-wasm bre-sanitize
