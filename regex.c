/*
 * regex.c
 *
 *     POSIX-compatible regular expression library implementation
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "regex.h"

/* Internal opcodes */
#define OP_CHR       1
#define OP_ANY       2
#define OP_CCL       3
#define OP_BOL       4
#define OP_EOL       5
#define OP_BOT       6
#define OP_EOT       7
#define OP_BOW       8
#define OP_EOW       9
#define OP_REF      10
#define OP_CLO      11
#define OP_ALT      12
#define OP_END       0

/* Internal constants */
#define MAXCHR      128
#define CHRBIT        8
#define BITBLK       (MAXCHR/CHRBIT)
#define BLKIND      0170
#define BITIND        07
#define MAXNFA      2048
#define MAXTAG        10

/* Internal CHAR type */
typedef unsigned char CHAR;

/* Internal regex structure */
typedef struct {
    int tagstk[MAXTAG];
    CHAR nfa[MAXNFA];
    int status;
    CHAR bittab[BITBLK];
    const char *bol;
    const char *bopat[MAXTAG];
    const char *eopat[MAXTAG];
    size_t re_nsub;
    int cflags;
} regex_internal_t;

static CHAR bitarr[] = {1, 2, 4, 8, 16, 32, 64, 128};

static CHAR chrtyp[MAXCHR] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
    0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,
    0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0
};

#define inascii(x) (0177&(x))
#define iswordc(x) chrtyp[inascii(x)]
#define isinset(x,y) ((x)[((y) & BLKIND) >> 3] & bitarr[(y) & BITIND])

#define ANYSKIP  2
#define CHRSKIP  3
#define CCLSKIP 18

static void chset(regex_internal_t *regex, CHAR c)
{
    regex->bittab[((c) & BLKIND) >> 3] |= bitarr[(c) & BITIND];
}

static int regex_compile_internal(regex_internal_t *regex, const char *pattern)
{
    const char *p;
    CHAR *mp = regex->nfa;
    CHAR *lp;
    CHAR *sp = regex->nfa;
    int tagi = 0;
    int tagc = 1;
    int n;
    CHAR mask;
    int c1, c2;
    CHAR *alt_stack[MAXNFA];
    int alt_depth = 0;
    
    regex->status = 0;
    regex->re_nsub = 0;
    memset(regex->bittab, 0, BITBLK);
    
    if (!pattern || !*pattern) {
        return REG_BADPAT;
    }
    
    for (p = pattern; *p; p++) {
        lp = mp;
        switch(*p) {
            case '.':
                *mp++ = OP_ANY;
                break;
            case '^':
                if (p == pattern) {
                    *mp++ = OP_BOL;
                } else {
                    *mp++ = OP_CHR;
                    *mp++ = *p;
                }
                break;
            case '$':
                if (!*(p+1)) {
                    *mp++ = OP_EOL;
                } else {
                    *mp++ = OP_CHR;
                    *mp++ = *p;
                }
                break;
            case '[':
                *mp++ = OP_CCL;
                if (*++p == '^') {
                    mask = 0377;
                    p++;
                } else {
                    mask = 0;
                }
                if (*p == '-') {
                    chset(regex, *p++);
                }
                if (*p == ']') {
                    chset(regex, *p++);
                }
                while (*p && *p != ']') {
                    if (*p == '-' && *(p+1) && *(p+1) != ']') {
                        p++;
                        c1 = *(p-2) + 1;
                        c2 = *p++;
                        while (c1 <= c2) {
                            chset(regex, (CHAR)c1++);
                        }
                    } else {
                        chset(regex, *p++);
                    }
                }
                if (!*p) {
                    return REG_EBRACK;
                }
                for (n = 0; n < BITBLK; n++) {
                    *mp++ = mask ^ regex->bittab[n];
                    regex->bittab[n] = 0;
                }
                break;
            case '*':
            case '+':
                if (p == pattern) {
                    return REG_BADRPT;
                }
                lp = sp;
                if (*lp == OP_CLO) {
                    break;
                }
                switch(*lp) {
                    case OP_BOL:
                    case OP_BOT:
                    case OP_EOT:
                    case OP_BOW:
                    case OP_EOW:
                    case OP_REF:
                    case OP_ALT:
                        return REG_BADRPT;
                    default:
                        break;
                }
                if (*p == '+') {
                    for (sp = mp; lp < sp; lp++) {
                        *mp++ = *lp;
                    }
                }
                *mp++ = OP_END;
                *mp++ = OP_END;
                sp = mp;
                while (--mp > lp) {
                    *mp = mp[-1];
                }
                *mp++ = OP_CLO;
                mp = sp;
                break;
            case '|':
                /* Handle alternation */
                *mp++ = OP_ALT;
                /* Save position for later patching */
                alt_stack[alt_depth++] = mp;
                *mp++ = 0;
                *mp++ = 0;
                break;
            case '\\':
                switch(*++p) {
                    case '(':
                        if (tagc < MAXTAG) {
                            regex->tagstk[++tagi] = tagc;
                            *mp++ = OP_BOT;
                            *mp++ = tagc++;
                            regex->re_nsub++;
                        } else {
                            return REG_ESUBREG;
                        }
                        break;
                    case ')':
                        if (tagi > 0) {
                            *mp++ = OP_EOT;
                            *mp++ = regex->tagstk[tagi--];
                        } else {
                            return REG_EPAREN;
                        }
                        break;
                    case '<':
                        *mp++ = OP_BOW;
                        break;
                    case '>':
                        *mp++ = OP_EOW;
                        break;
                    case '1': case '2': case '3': case '4': case '5':
                    case '6': case '7': case '8': case '9':
                        n = *p - '0';
                        if (tagi > 0 && regex->tagstk[tagi] == n) {
                            return REG_ESUBREG;
                        }
                        if (tagc > n) {
                            *mp++ = OP_REF;
                            *mp++ = n;
                        } else {
                            return REG_ESUBREG;
                        }
                        break;
                    default:
                        *mp++ = OP_CHR;
                        *mp++ = *p;
                }
                break;
            default:
                *mp++ = OP_CHR;
                *mp++ = *p;
                break;
        }
        sp = lp;
    }
    
    if (tagi > 0) {
        return REG_EPAREN;
    }
    
    *mp++ = OP_END;
    regex->status = 1;
    
    return REG_NOERROR;
}

static const char *regex_match_internal(regex_internal_t *regex, const char *lp, const CHAR *ap)
{
    int op, c, n;
    const char *e;
    const char *are;
    const CHAR *saved_ap;
    const char *saved_lp;
    const char *result;
    
    while ((op = *ap++) != OP_END) {
        switch(op) {
            case OP_CHR:
                if (*lp++ != *ap++) {
                    return NULL;
                }
                break;
            case OP_ANY:
                if (!*lp++) {
                    return NULL;
                }
                break;
            case OP_CCL:
                c = *lp++;
                if (!isinset(ap, c)) {
                    return NULL;
                }
                ap += BITBLK;
                break;
            case OP_BOL:
                if (lp != regex->bol) {
                    return NULL;
                }
                break;
            case OP_EOL:
                if (*lp) {
                    return NULL;
                }
                break;
            case OP_BOT:
                regex->bopat[(int)(*ap++)] = lp;
                break;
            case OP_EOT:
                regex->eopat[(int)(*ap++)] = lp;
                break;
            case OP_BOW:
                if ((lp != regex->bol && iswordc(lp[-1])) || !iswordc(*lp)) {
                    return NULL;
                }
                break;
            case OP_EOW:
                if (lp == regex->bol || !iswordc(lp[-1]) || iswordc(*lp)) {
                    return NULL;
                }
                break;
            case OP_REF:
                n = *ap++;
                for (e = regex->bopat[n]; e < regex->eopat[n]; e++) {
                    if (*e != *lp++) {
                        return NULL;
                    }
                }
                break;
            case OP_CLO:
                are = lp;
                switch(*ap) {
                    case OP_ANY:
                        while (*lp) lp++;
                        ap += ANYSKIP;
                        break;
                    case OP_CHR:
                        c = *(ap+1);
                        while (*lp && c == *lp) lp++;
                        ap += CHRSKIP;
                        break;
                    case OP_CCL:
                        while ((c = *lp) && isinset(ap+1, c)) lp++;
                        ap += CCLSKIP;
                        break;
                    default:
                        return NULL;
                }
                while (lp >= are) {
                    if ((e = regex_match_internal(regex, lp, ap))) {
                        return e;
                    }
                    lp--;
                }
                return NULL;
            case OP_ALT:
                /* Handle alternation - try first branch */
                saved_ap = ap;
                saved_lp = lp;
                result = regex_match_internal(regex, lp, ap);
                if (result) {
                    return result;
                }
                /* Try second branch */
                ap = saved_ap + 2;
                lp = saved_lp;
                break;
            default:
                return NULL;
        }
    }
    return lp;
}

/* POSIX API Functions */

int regcomp(regex_t *preg, const char *pattern, int cflags)
{
    regex_internal_t *internal;
    int ret;
    
    (void)cflags; /* Currently ignore cflags for basic regex */
    
    if (!preg || !pattern) {
        return REG_BADPAT;
    }
    
    internal = (regex_internal_t *)malloc(sizeof(regex_internal_t));
    if (!internal) {
        return REG_ESPACE;
    }
    
    memset(internal, 0, sizeof(regex_internal_t));
    internal->cflags = cflags;
    
    ret = regex_compile_internal(internal, pattern);
    
    if (ret != REG_NOERROR) {
        free(internal);
        preg->re_compiled = NULL;
        preg->re_nsub = 0;
        return ret;
    }
    
    preg->re_compiled = internal;
    preg->re_nsub = internal->re_nsub;
    
    return REG_NOERROR;
}

int regexec(const regex_t *preg, const char *string, size_t nmatch,
            regmatch_t pmatch[], int eflags)
{
    regex_internal_t *internal;
    const char *ep;
    const CHAR *ap;
    const char *lp;
    size_t i;
    
    if (!preg || !preg->re_compiled || !string) {
        return REG_BADPAT;
    }
    
    internal = (regex_internal_t *)preg->re_compiled;
    
    if (internal->status != 1) {
        return REG_BADPAT;
    }
    
    internal->bol = string;
    
    for (i = 0; i < MAXTAG; i++) {
        internal->bopat[i] = NULL;
        internal->eopat[i] = NULL;
    }
    
    ap = internal->nfa;
    lp = string;
    
    if (eflags & REG_NOTBOL) {
        /* Skip BOL assertion */
        while (*ap == OP_BOL) ap++;
    }
    
    switch(*ap) {
        case OP_BOL:
            ep = regex_match_internal(internal, lp, ap);
            break;
        case OP_CHR:
            {
                CHAR c = *(ap+1);
                while (*lp && *lp != c) lp++;
                if (!*lp) return REG_NOMATCH;
                /* Fall through */
            }
        default:
            do {
                if ((ep = regex_match_internal(internal, lp, ap))) {
                    break;
                }
                lp++;
            } while (*lp);
            break;
        case OP_END:
            return REG_NOMATCH;
    }
    
    if (!ep) {
        return REG_NOMATCH;
    }
    
    if (pmatch && nmatch > 0) {
        pmatch[0].rm_so = (ptrdiff_t)(lp - string);
        pmatch[0].rm_eo = (ptrdiff_t)(ep - string);
        
        for (i = 1; i < nmatch && i < MAXTAG && i <= preg->re_nsub; i++) {
            if (internal->bopat[i] && internal->eopat[i]) {
                pmatch[i].rm_so = (ptrdiff_t)(internal->bopat[i] - string);
                pmatch[i].rm_eo = (ptrdiff_t)(internal->eopat[i] - string);
            } else {
                pmatch[i].rm_so = -1;
                pmatch[i].rm_eo = -1;
            }
        }
    }
    
    return REG_NOERROR;
}

size_t regerror(int errcode, const regex_t *preg, char *errbuf, size_t errbuf_size)
{
    const char *msg;
    
    (void)preg; /* Unused parameter */
    
    switch(errcode) {
        case REG_NOERROR: msg = "No error"; break;
        case REG_NOMATCH: msg = "No match"; break;
        case REG_BADPAT: msg = "Invalid regular expression"; break;
        case REG_ECOLLATE: msg = "Invalid collating element"; break;
        case REG_ECTYPE: msg = "Invalid character class"; break;
        case REG_EESCAPE: msg = "Trailing backslash"; break;
        case REG_ESUBREG: msg = "Invalid back reference"; break;
        case REG_EBRACK: msg = "Unmatched bracket"; break;
        case REG_EPAREN: msg = "Unmatched parenthesis"; break;
        case REG_EBRACE: msg = "Unmatched brace"; break;
        case REG_BADBR: msg = "Invalid brace content"; break;
        case REG_ERANGE: msg = "Invalid range"; break;
        case REG_ESPACE: msg = "Out of memory"; break;
        case REG_BADRPT: msg = "Invalid repetition"; break;
        default: msg = "Unknown error"; break;
    }
    
    if (errbuf && errbuf_size > 0) {
        strncpy(errbuf, msg, errbuf_size - 1);
        errbuf[errbuf_size - 1] = '\0';
    }
    
    return strlen(msg) + 1;
}

void regfree(regex_t *preg)
{
    if (preg && preg->re_compiled) {
        free(preg->re_compiled);
        preg->re_compiled = NULL;
        preg->re_nsub = 0;
    }
}