/*
 * regex.h
 *
 *     POSIX-compatible regular expression library
 *
 * Based on the original implementation by Ozan S. Yigit,
 * modified for POSIX compatibility.
 *
 * Copyright 2016 Roberto Luiz Souza Monteiro,
 *                Hernane Borges de Barros Pereira
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef REGEX_H
#define REGEX_H

#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>

#define REGEX_VERSION "2.0"

/* POSIX error codes */
#define REG_NOERROR     0   /* No error */
#define REG_NOMATCH     1   /* No match found */
#define REG_BADPAT      2   /* Invalid regular expression */
#define REG_ECOLLATE    3   /* Invalid collating element */
#define REG_ECTYPE      4   /* Invalid character class */
#define REG_EESCAPE     5   /* Trailing backslash */
#define REG_ESUBREG     6   /* Invalid back reference */
#define REG_EBRACK      7   /* Unmatched bracket */
#define REG_EPAREN      8   /* Unmatched parenthesis */
#define REG_EBRACE      9   /* Unmatched brace */
#define REG_BADBR       10  /* Invalid brace content */
#define REG_ERANGE      11  /* Invalid range */
#define REG_ESPACE      12  /* Out of memory */
#define REG_BADRPT      13  /* Invalid repetition */

/* POSIX compilation flags */
#define REG_EXTENDED    0x001 /* Use extended regular expressions */
#define REG_ICASE       0x002 /* Ignore case */
#define REG_NOSUB       0x004 /* No subexpressions */
#define REG_NEWLINE     0x008 /* Treat newline as special */

/* POSIX execution flags */
#define REG_NOTBOL      0x001 /* Beginning of string is not start of line */
#define REG_NOTEOL      0x002 /* End of string is not end of line */

/* POSIX regex structure */
typedef struct {
    size_t re_nsub;          /* Number of parenthesized subexpressions */
    void *re_compiled;       /* Compiled pattern (internal) */
} regex_t;

/* POSIX regmatch structure */
typedef struct {
    ptrdiff_t rm_so;         /* Start offset of match */
    ptrdiff_t rm_eo;         /* End offset of match */
} regmatch_t;

#ifdef __cplusplus
extern "C" {
#endif

/* POSIX functions */
int regcomp(regex_t *preg, const char *pattern, int cflags);
int regexec(const regex_t *preg, const char *string, size_t nmatch,
            regmatch_t pmatch[], int eflags);
size_t regerror(int errcode, const regex_t *preg, char *errbuf, size_t errbuf_size);
void regfree(regex_t *preg);

#ifdef __cplusplus
}
#endif

#endif /* REGEX_H */