#ifndef MAIACC_GENERATED_CPP98_PARSER_H
#define MAIACC_GENERATED_CPP98_PARSER_H

#include <stdlib.h>
#include "maia_regex.h"

#define MAIACC_TOKEN_EOF 1
#define MAIACC_TOKEN_END_DOLLAR 2
#define MAIACC_TOKEN_OPEN_SPECIAL 3
#define MAIACC_TOKEN_BACKSLASH 4
#define MAIACC_TOKEN_LPAREN 5
#define MAIACC_TOKEN_RPAREN 6
#define MAIACC_TOKEN_LBRACE 7
#define MAIACC_TOKEN_RBRACE 8
#define MAIACC_TOKEN_OPEN 9
#define MAIACC_TOKEN_CLOSE 10
#define MAIACC_TOKEN_CARET 11
#define MAIACC_TOKEN_DOLLAR 12
#define MAIACC_TOKEN_STAR 13
#define MAIACC_TOKEN_DOT 14
#define MAIACC_TOKEN_PLUS 15
#define MAIACC_TOKEN_QUESTION 16
#define MAIACC_TOKEN_PIPE 17
#define MAIACC_TOKEN_DASH 18
#define MAIACC_TOKEN_COLON 19
#define MAIACC_TOKEN_EQUAL 20
#define MAIACC_TOKEN_COMMA 21
#define MAIACC_TOKEN_LETTER 22
#define MAIACC_TOKEN_DIGIT 23
#define MAIACC_TOKEN_CHAR 24
#define MAIACC_TOKEN_COUNT 25
#define MAIACC_RULE_COUNT 72

static const char* maiaCCParserTokenName(unsigned int type) {
  switch (type) {
    case MAIACC_TOKEN_EOF: return "EOF";
    case MAIACC_TOKEN_END_DOLLAR: return "END_DOLLAR";
    case MAIACC_TOKEN_OPEN_SPECIAL: return "OPEN_SPECIAL";
    case MAIACC_TOKEN_BACKSLASH: return "BACKSLASH";
    case MAIACC_TOKEN_LPAREN: return "LPAREN";
    case MAIACC_TOKEN_RPAREN: return "RPAREN";
    case MAIACC_TOKEN_LBRACE: return "LBRACE";
    case MAIACC_TOKEN_RBRACE: return "RBRACE";
    case MAIACC_TOKEN_OPEN: return "OPEN";
    case MAIACC_TOKEN_CLOSE: return "CLOSE";
    case MAIACC_TOKEN_CARET: return "CARET";
    case MAIACC_TOKEN_DOLLAR: return "DOLLAR";
    case MAIACC_TOKEN_STAR: return "STAR";
    case MAIACC_TOKEN_DOT: return "DOT";
    case MAIACC_TOKEN_PLUS: return "PLUS";
    case MAIACC_TOKEN_QUESTION: return "QUESTION";
    case MAIACC_TOKEN_PIPE: return "PIPE";
    case MAIACC_TOKEN_DASH: return "DASH";
    case MAIACC_TOKEN_COLON: return "COLON";
    case MAIACC_TOKEN_EQUAL: return "EQUAL";
    case MAIACC_TOKEN_COMMA: return "COMMA";
    case MAIACC_TOKEN_LETTER: return "LETTER";
    case MAIACC_TOKEN_DIGIT: return "DIGIT";
    case MAIACC_TOKEN_CHAR: return "CHAR";
    default: return "UNKNOWN";
  }
}

struct MaiaCCParserToken {
  unsigned int type;
  const char* value;
  unsigned int length;
  unsigned int start;
  unsigned int end;
};


typedef MaiaRegexInstruction MaiaCCLexInstruction;
typedef MaiaRegexRange MaiaCCLexRange;
struct MaiaCCLexPattern {
  const MaiaCCLexInstruction* code;
  const MaiaCCLexRange* ranges;
  unsigned int count;
  unsigned int entry;
  unsigned int token;
  int skip;
  int generic;
  int preferred;
  int role;
  unsigned int rangeCount;
};
struct MaiaCCLexerState {
  const char* input;
  unsigned int length;
  unsigned int position;
  unsigned int bytePosition;
  unsigned int tokenCount;
  int failed;
};
static void maiaCCLexerStateInit(MaiaCCLexerState* self, const char* input, unsigned int length) {
  self->input = input;
  self->length = length;
  self->position = 0;
  self->bytePosition = 0;
  self->tokenCount = 0;
  self->failed = 0;
}
static const MaiaCCLexInstruction maiaCCLexCode0[] = {
  { 0, 0, 0, 0 },
  { 0, 0, 0, 0 },
  { 1, 41, 0, 1 },
  { 1, 92, 0, 2 },
  { 0, 0, 0, 0 },
  { 3, 0, 21, 4 },
  { 6, 5, 0, 1 },
  { 2, 6, 3, 0 },
  { 7, 7, 0, 0 },
  { 1, 36, 0, 8 }
};
static const MaiaCCLexRange maiaCCLexRanges0[] = {
  { 9, 13 },
  { 32, 32 },
  { 160, 160 },
  { 5760, 5760 },
  { 8192, 8202 },
  { 8232, 8233 },
  { 8239, 8239 },
  { 8287, 8287 },
  { 12288, 12288 },
  { 65279, 65279 },
  { 0, 8 },
  { 14, 31 },
  { 33, 159 },
  { 161, 5759 },
  { 5761, 8191 },
  { 8203, 8231 },
  { 8234, 8238 },
  { 8240, 8286 },
  { 8288, 12287 },
  { 12289, 65278 },
  { 65280, 65535 }
};
static const MaiaCCLexInstruction maiaCCLexCode1[] = {
  { 0, 0, 0, 0 },
  { 0, 0, 0, 0 },
  { 3, 0, 3, 1 },
  { 7, 2, 0, 0 },
  { 1, 91, 0, 3 }
};
static const MaiaCCLexRange maiaCCLexRanges1[] = {
  { 58, 58 },
  { 46, 46 },
  { 61, 61 }
};
static const MaiaCCLexInstruction maiaCCLexCode2[] = {
  { 0, 0, 0, 0 },
  { 1, 92, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges2[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode3[] = {
  { 0, 0, 0, 0 },
  { 1, 40, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges3[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode4[] = {
  { 0, 0, 0, 0 },
  { 1, 41, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges4[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode5[] = {
  { 0, 0, 0, 0 },
  { 1, 123, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges5[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode6[] = {
  { 0, 0, 0, 0 },
  { 1, 125, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges6[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode7[] = {
  { 0, 0, 0, 0 },
  { 1, 91, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges7[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode8[] = {
  { 0, 0, 0, 0 },
  { 1, 93, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges8[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode9[] = {
  { 0, 0, 0, 0 },
  { 1, 94, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges9[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode10[] = {
  { 0, 0, 0, 0 },
  { 1, 36, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges10[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode11[] = {
  { 0, 0, 0, 0 },
  { 1, 42, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges11[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode12[] = {
  { 0, 0, 0, 0 },
  { 1, 46, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges12[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode13[] = {
  { 0, 0, 0, 0 },
  { 1, 43, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges13[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode14[] = {
  { 0, 0, 0, 0 },
  { 1, 63, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges14[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode15[] = {
  { 0, 0, 0, 0 },
  { 1, 124, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges15[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode16[] = {
  { 0, 0, 0, 0 },
  { 1, 45, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges16[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode17[] = {
  { 0, 0, 0, 0 },
  { 1, 58, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges17[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode18[] = {
  { 0, 0, 0, 0 },
  { 1, 61, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges18[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode19[] = {
  { 0, 0, 0, 0 },
  { 1, 44, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges19[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode20[] = {
  { 0, 0, 0, 0 },
  { 3, 0, 1, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges20[] = {
  { 97, 122 }
};
static const MaiaCCLexInstruction maiaCCLexCode21[] = {
  { 0, 0, 0, 0 },
  { 3, 0, 1, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges21[] = {
  { 48, 57 }
};
static const MaiaCCLexInstruction maiaCCLexCode22[] = {
  { 0, 0, 0, 0 },
  { 4, 0, 21, 0 },
  { 3, 21, 1, 0 },
  { 3, 22, 1, 2 },
  { 2, 3, 1, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges22[] = {
  { 48, 57 },
  { 45, 45 },
  { 122, 122 },
  { 0, 0 },
  { 36, 36 },
  { 40, 40 },
  { 41, 41 },
  { 42, 42 },
  { 43, 43 },
  { 44, 46 },
  { 58, 58 },
  { 61, 61 },
  { 63, 63 },
  { 91, 91 },
  { 92, 92 },
  { 93, 93 },
  { 94, 94 },
  { 123, 123 },
  { 124, 124 },
  { 2010, 2010 },
  { 55296, 57343 },
  { 56320, 57343 },
  { 55296, 56319 }
};
static const MaiaCCLexInstruction maiaCCLexCode23[] = {
  { 0, 0, 0, 0 },
  { 0, 0, 0, 0 },
  { 1, 41, 0, 1 },
  { 1, 92, 0, 2 },
  { 0, 0, 0, 0 },
  { 3, 0, 21, 4 },
  { 6, 5, 0, 1 },
  { 2, 6, 3, 0 },
  { 7, 7, 0, 0 },
  { 1, 36, 0, 8 }
};
static const MaiaCCLexRange maiaCCLexRanges23[] = {
  { 9, 13 },
  { 32, 32 },
  { 160, 160 },
  { 5760, 5760 },
  { 8192, 8202 },
  { 8232, 8233 },
  { 8239, 8239 },
  { 8287, 8287 },
  { 12288, 12288 },
  { 65279, 65279 },
  { 0, 8 },
  { 14, 31 },
  { 33, 159 },
  { 161, 5759 },
  { 5761, 8191 },
  { 8203, 8231 },
  { 8234, 8238 },
  { 8240, 8286 },
  { 8288, 12287 },
  { 12289, 65278 },
  { 65280, 65535 }
};
static const MaiaCCLexInstruction maiaCCLexCode24[] = {
  { 0, 0, 0, 0 },
  { 0, 0, 0, 0 },
  { 3, 0, 3, 1 },
  { 7, 2, 0, 0 },
  { 1, 91, 0, 3 }
};
static const MaiaCCLexRange maiaCCLexRanges24[] = {
  { 58, 58 },
  { 46, 46 },
  { 61, 61 }
};
static const MaiaCCLexInstruction maiaCCLexCode25[] = {
  { 0, 0, 0, 0 },
  { 1, 92, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges25[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode26[] = {
  { 0, 0, 0, 0 },
  { 1, 40, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges26[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode27[] = {
  { 0, 0, 0, 0 },
  { 1, 41, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges27[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode28[] = {
  { 0, 0, 0, 0 },
  { 1, 123, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges28[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode29[] = {
  { 0, 0, 0, 0 },
  { 1, 125, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges29[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode30[] = {
  { 0, 0, 0, 0 },
  { 1, 91, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges30[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode31[] = {
  { 0, 0, 0, 0 },
  { 1, 93, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges31[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode32[] = {
  { 0, 0, 0, 0 },
  { 1, 94, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges32[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode33[] = {
  { 0, 0, 0, 0 },
  { 1, 36, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges33[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode34[] = {
  { 0, 0, 0, 0 },
  { 1, 42, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges34[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode35[] = {
  { 0, 0, 0, 0 },
  { 1, 46, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges35[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode36[] = {
  { 0, 0, 0, 0 },
  { 1, 43, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges36[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode37[] = {
  { 0, 0, 0, 0 },
  { 1, 63, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges37[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode38[] = {
  { 0, 0, 0, 0 },
  { 1, 124, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges38[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode39[] = {
  { 0, 0, 0, 0 },
  { 1, 45, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges39[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode40[] = {
  { 0, 0, 0, 0 },
  { 1, 58, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges40[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode41[] = {
  { 0, 0, 0, 0 },
  { 1, 61, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges41[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode42[] = {
  { 0, 0, 0, 0 },
  { 1, 44, 0, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges42[] = {
  { 0, 0 }
};
static const MaiaCCLexInstruction maiaCCLexCode43[] = {
  { 0, 0, 0, 0 },
  { 3, 0, 1, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges43[] = {
  { 97, 122 }
};
static const MaiaCCLexInstruction maiaCCLexCode44[] = {
  { 0, 0, 0, 0 },
  { 3, 0, 1, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges44[] = {
  { 48, 57 }
};
static const MaiaCCLexInstruction maiaCCLexCode45[] = {
  { 0, 0, 0, 0 },
  { 4, 0, 21, 0 },
  { 3, 21, 1, 0 },
  { 3, 22, 1, 2 },
  { 2, 3, 1, 0 }
};
static const MaiaCCLexRange maiaCCLexRanges45[] = {
  { 48, 57 },
  { 45, 45 },
  { 122, 122 },
  { 0, 0 },
  { 36, 36 },
  { 40, 40 },
  { 41, 41 },
  { 42, 42 },
  { 43, 43 },
  { 44, 46 },
  { 58, 58 },
  { 61, 61 },
  { 63, 63 },
  { 91, 91 },
  { 92, 92 },
  { 93, 93 },
  { 94, 94 },
  { 123, 123 },
  { 124, 124 },
  { 2010, 2010 },
  { 55296, 57343 },
  { 56320, 57343 },
  { 55296, 56319 }
};
static const MaiaCCLexPattern maiaCCLexPatterns[] = {
  { maiaCCLexCode0, maiaCCLexRanges0, 10, 9, MAIACC_TOKEN_END_DOLLAR, 0, 0, 0, 0, 21 },
  { maiaCCLexCode1, maiaCCLexRanges1, 5, 4, MAIACC_TOKEN_OPEN_SPECIAL, 0, 0, 0, 0, 3 },
  { maiaCCLexCode2, maiaCCLexRanges2, 2, 1, MAIACC_TOKEN_BACKSLASH, 0, 0, 0, 0, 0 },
  { maiaCCLexCode3, maiaCCLexRanges3, 2, 1, MAIACC_TOKEN_LPAREN, 0, 0, 0, 0, 0 },
  { maiaCCLexCode4, maiaCCLexRanges4, 2, 1, MAIACC_TOKEN_RPAREN, 0, 0, 0, 0, 0 },
  { maiaCCLexCode5, maiaCCLexRanges5, 2, 1, MAIACC_TOKEN_LBRACE, 0, 0, 0, 0, 0 },
  { maiaCCLexCode6, maiaCCLexRanges6, 2, 1, MAIACC_TOKEN_RBRACE, 0, 0, 0, 0, 0 },
  { maiaCCLexCode7, maiaCCLexRanges7, 2, 1, MAIACC_TOKEN_OPEN, 0, 0, 0, 0, 0 },
  { maiaCCLexCode8, maiaCCLexRanges8, 2, 1, MAIACC_TOKEN_CLOSE, 0, 0, 0, 0, 0 },
  { maiaCCLexCode9, maiaCCLexRanges9, 2, 1, MAIACC_TOKEN_CARET, 0, 0, 0, 0, 0 },
  { maiaCCLexCode10, maiaCCLexRanges10, 2, 1, MAIACC_TOKEN_DOLLAR, 0, 0, 0, 0, 0 },
  { maiaCCLexCode11, maiaCCLexRanges11, 2, 1, MAIACC_TOKEN_STAR, 0, 0, 0, 0, 0 },
  { maiaCCLexCode12, maiaCCLexRanges12, 2, 1, MAIACC_TOKEN_DOT, 0, 0, 0, 0, 0 },
  { maiaCCLexCode13, maiaCCLexRanges13, 2, 1, MAIACC_TOKEN_PLUS, 0, 0, 0, 0, 0 },
  { maiaCCLexCode14, maiaCCLexRanges14, 2, 1, MAIACC_TOKEN_QUESTION, 0, 0, 0, 0, 0 },
  { maiaCCLexCode15, maiaCCLexRanges15, 2, 1, MAIACC_TOKEN_PIPE, 0, 0, 0, 0, 0 },
  { maiaCCLexCode16, maiaCCLexRanges16, 2, 1, MAIACC_TOKEN_DASH, 0, 0, 0, 0, 0 },
  { maiaCCLexCode17, maiaCCLexRanges17, 2, 1, MAIACC_TOKEN_COLON, 0, 0, 0, 0, 0 },
  { maiaCCLexCode18, maiaCCLexRanges18, 2, 1, MAIACC_TOKEN_EQUAL, 0, 0, 0, 0, 0 },
  { maiaCCLexCode19, maiaCCLexRanges19, 2, 1, MAIACC_TOKEN_COMMA, 0, 0, 0, 0, 0 },
  { maiaCCLexCode20, maiaCCLexRanges20, 2, 1, MAIACC_TOKEN_LETTER, 0, 0, 0, 0, 1 },
  { maiaCCLexCode21, maiaCCLexRanges21, 2, 1, MAIACC_TOKEN_DIGIT, 0, 0, 0, 0, 1 },
  { maiaCCLexCode22, maiaCCLexRanges22, 5, 4, MAIACC_TOKEN_CHAR, 0, 0, 0, 0, 23 },
  { maiaCCLexCode23, maiaCCLexRanges23, 10, 9, MAIACC_TOKEN_END_DOLLAR, 0, 0, 0, 0, 21 },
  { maiaCCLexCode24, maiaCCLexRanges24, 5, 4, MAIACC_TOKEN_OPEN_SPECIAL, 0, 0, 0, 0, 3 },
  { maiaCCLexCode25, maiaCCLexRanges25, 2, 1, MAIACC_TOKEN_BACKSLASH, 0, 0, 0, 0, 0 },
  { maiaCCLexCode26, maiaCCLexRanges26, 2, 1, MAIACC_TOKEN_LPAREN, 0, 0, 0, 0, 0 },
  { maiaCCLexCode27, maiaCCLexRanges27, 2, 1, MAIACC_TOKEN_RPAREN, 0, 0, 0, 0, 0 },
  { maiaCCLexCode28, maiaCCLexRanges28, 2, 1, MAIACC_TOKEN_LBRACE, 0, 0, 0, 0, 0 },
  { maiaCCLexCode29, maiaCCLexRanges29, 2, 1, MAIACC_TOKEN_RBRACE, 0, 0, 0, 0, 0 },
  { maiaCCLexCode30, maiaCCLexRanges30, 2, 1, MAIACC_TOKEN_OPEN, 0, 0, 0, 0, 0 },
  { maiaCCLexCode31, maiaCCLexRanges31, 2, 1, MAIACC_TOKEN_CLOSE, 0, 0, 0, 0, 0 },
  { maiaCCLexCode32, maiaCCLexRanges32, 2, 1, MAIACC_TOKEN_CARET, 0, 0, 0, 0, 0 },
  { maiaCCLexCode33, maiaCCLexRanges33, 2, 1, MAIACC_TOKEN_DOLLAR, 0, 0, 0, 0, 0 },
  { maiaCCLexCode34, maiaCCLexRanges34, 2, 1, MAIACC_TOKEN_STAR, 0, 0, 0, 0, 0 },
  { maiaCCLexCode35, maiaCCLexRanges35, 2, 1, MAIACC_TOKEN_DOT, 0, 0, 0, 0, 0 },
  { maiaCCLexCode36, maiaCCLexRanges36, 2, 1, MAIACC_TOKEN_PLUS, 0, 0, 0, 0, 0 },
  { maiaCCLexCode37, maiaCCLexRanges37, 2, 1, MAIACC_TOKEN_QUESTION, 0, 0, 0, 0, 0 },
  { maiaCCLexCode38, maiaCCLexRanges38, 2, 1, MAIACC_TOKEN_PIPE, 0, 0, 0, 0, 0 },
  { maiaCCLexCode39, maiaCCLexRanges39, 2, 1, MAIACC_TOKEN_DASH, 0, 0, 0, 0, 0 },
  { maiaCCLexCode40, maiaCCLexRanges40, 2, 1, MAIACC_TOKEN_COLON, 0, 0, 0, 0, 0 },
  { maiaCCLexCode41, maiaCCLexRanges41, 2, 1, MAIACC_TOKEN_EQUAL, 0, 0, 0, 0, 0 },
  { maiaCCLexCode42, maiaCCLexRanges42, 2, 1, MAIACC_TOKEN_COMMA, 0, 0, 0, 0, 0 },
  { maiaCCLexCode43, maiaCCLexRanges43, 2, 1, MAIACC_TOKEN_LETTER, 0, 0, 0, 0, 1 },
  { maiaCCLexCode44, maiaCCLexRanges44, 2, 1, MAIACC_TOKEN_DIGIT, 0, 0, 0, 0, 1 },
  { maiaCCLexCode45, maiaCCLexRanges45, 5, 4, MAIACC_TOKEN_CHAR, 0, 0, 0, 0, 23 }
};
static const unsigned int maiaCCLexPatternCount = 23;
static const unsigned int maiaCCLexContextCount = 46;

static int maiaCCLexWhitespace(unsigned int value) {
  return (value >= 9 && value <= 13) || value == 32 || value == 160 || value == 5760
      || (value >= 8192 && value <= 8202) || value == 8232 || value == 8233
      || value == 8239 || value == 8287 || value == 12288 || value == 65279;
}

static int maiaCCLexDecode(const char* input, unsigned int length,
    unsigned int* units, unsigned int* offsets, unsigned int* count) {
  unsigned int position = 0;
  *count = 0;
  while (position < length) {
    unsigned int start = position;
    unsigned int first = (unsigned char)input[position++];
    unsigned int value = first;
    unsigned int extra = 0;
    unsigned int minimum = 0;
    if (first >= 194 && first <= 223) { value = first & 31; extra = 1; minimum = 128; }
    else if (first >= 224 && first <= 239) { value = first & 15; extra = 2; minimum = 2048; }
    else if (first >= 240 && first <= 244) { value = first & 7; extra = 3; minimum = 65536; }
    else if (first >= 128) return 0;
    if (extra > length - position) return 0;
    while (extra > 0) {
      unsigned int byte = (unsigned char)input[position++];
      if (byte < 128 || byte > 191) return 0;
      value = (value << 6) | (byte & 63);
      --extra;
    }
    if (value < minimum || value > 1114111 || (value >= 55296 && value <= 57343)) return 0;
    offsets[*count] = start;
    if (value > 65535) {
      value -= 65536;
      units[(*count)++] = 55296 + (value >> 10);
      offsets[*count] = start;
      units[(*count)++] = 56320 + (value & 1023);
    } else units[(*count)++] = value;
  }
  offsets[*count] = length;
  return 1;
}

static int maiaCCLexMatch(const MaiaCCLexPattern* pattern, const unsigned int* units,
    unsigned int length, unsigned int position) {
  MaiaRegexProgram program = { pattern->code, pattern->ranges, pattern->count, pattern->rangeCount, pattern->entry };
  unsigned int end = 0;
  int result = maia_regex_exec(&program, units, length, position, 0, &end);
  if (result == MAIA_REGEX_MATCH) return (int)end;
  return result == MAIA_REGEX_NOMATCH ? -1 : -2;
}

static int maiaCCLexerTokenize(MaiaCCLexerState* self, MaiaCCParserToken* tokens, unsigned int capacity) {
  self->tokenCount = 0;
  self->position = 0;
  self->bytePosition = 0;
  self->failed = 0;
  if (!self->input || !tokens || !capacity || self->length > 2147483646U) { self->failed = 1; return 0; }
  size_t entries = (size_t)self->length + 1;
  if (entries > ((size_t)-1) / (3 * sizeof(unsigned int))) { self->failed = 2; return 0; }
  unsigned int* storage = (unsigned int*)malloc(entries * 3 * sizeof(unsigned int));
  if (!storage) { self->failed = 2; return 0; }
  unsigned int* units = storage;
  unsigned int* offsets = storage + entries;
  unsigned int* braces = storage + 2 * entries;
  unsigned int length = 0;
  unsigned int classDepth = 0;
  unsigned int templateDepth = 0;
  if (!maiaCCLexDecode(self->input, self->length, units, offsets, &length)) self->failed = 1;
  int middle = -1;
  int tail = -1;
  for (unsigned int index = 0; index < maiaCCLexPatternCount; ++index) {
    if (maiaCCLexPatterns[index].role == 1) middle = (int)index;
    if (maiaCCLexPatterns[index].role == 2) tail = (int)index;
  }
  while (!self->failed && self->position < length) {
    int best = -1;
    int bestEnd = -1;
    int preferred = -1;
    int preferredEnd = -1;
    int whitespace = -1;
    int whitespaceEnd = -1;
    for (unsigned int index = 0; index < maiaCCLexPatternCount; ++index) {
      int candidate = (int)index;
      const MaiaCCLexPattern* pattern = maiaCCLexPatterns + candidate;
      if (pattern->role == 1 || pattern->role == 2) continue;
      int end = maiaCCLexMatch(pattern, units, length, self->position);
      if (end == -2) { self->failed = 2; break; }
      if (end <= (int)self->position) continue;
      if (templateDepth && pattern->role == 5 && braces[templateDepth - 1] == 0) {
        unsigned int limit = self->position + 256;
        if (limit > length) limit = length;
        for (unsigned int scan = self->position + 1; scan < limit; ++scan) {
          if (units[scan] == 92) { ++scan; continue; }
          int span = -1;
          if (units[scan] == 36 && scan + 1 < length && units[scan + 1] == 123) span = middle;
          else if (units[scan] == 96) span = tail;
          else continue;
          if (span >= 0) {
            int spanEnd = maiaCCLexMatch(maiaCCLexPatterns + span, units, length, self->position);
            if (spanEnd == -2) self->failed = 2;
            if (spanEnd > (int)self->position) { candidate = span; end = spanEnd; pattern = maiaCCLexPatterns + span; }
          }
          break;
        }
      }
      if (best < 0 || end > bestEnd || (end == bestEnd && pattern->skip && !maiaCCLexPatterns[best].skip)
          || (end == bestEnd && maiaCCLexPatterns[best].generic && !pattern->generic)) { best = candidate; bestEnd = end; }
      if (classDepth && pattern->preferred && end > preferredEnd) { preferred = candidate; preferredEnd = end; }
      if (pattern->skip && end > whitespaceEnd) { whitespace = candidate; whitespaceEnd = end; }
    }
    if (preferred >= 0) { best = preferred; bestEnd = preferredEnd; }
    if (whitespace >= 0 && maiaCCLexWhitespace(units[self->position])) { best = whitespace; bestEnd = whitespaceEnd; }
    if (self->failed) break;
    if (best < 0) { self->failed = 1; break; }
    const MaiaCCLexPattern* pattern = maiaCCLexPatterns + best;
    if (!pattern->skip) {
      if (self->tokenCount + 1 >= capacity) { self->failed = 3; break; }
      MaiaCCParserToken* token = tokens + self->tokenCount++;
      token->type = pattern->token;
      token->value = self->input + offsets[self->position];
      token->length = offsets[bestEnd] - offsets[self->position];
      token->start = self->position;
      token->end = (unsigned int)bestEnd;
      if (pattern->role == 6) ++classDepth;
      else if (pattern->role == 7 && classDepth) --classDepth;
      else if (pattern->role == 4 && templateDepth) ++braces[templateDepth - 1];
      else if (pattern->role == 5 && templateDepth && braces[templateDepth - 1]) --braces[templateDepth - 1];
      else if (pattern->role == 3) braces[templateDepth++] = 0;
      else if (pattern->role == 2 && templateDepth) --templateDepth;
    }
    self->position = (unsigned int)bestEnd;
    self->bytePosition = offsets[self->position];
  }
  if (!self->failed) {
    MaiaCCParserToken* token = tokens + self->tokenCount++;
    token->type = MAIACC_TOKEN_EOF;
    token->value = self->input + self->length;
    token->length = 0;
    token->start = length;
    token->end = length;
  }
  free(storage);
  return !self->failed;
}

static int maiaCCLexMatchesContextual(unsigned int expected, const MaiaCCParserToken* token) {
  size_t entries = (size_t)token->length + 1;
  if (entries > ((size_t)-1) / (2 * sizeof(unsigned int))) return 0;
  unsigned int* units = (unsigned int*)malloc(entries * 2 * sizeof(unsigned int));
  if (!units) return 0;
  unsigned int length = 0;
  int accepted = 0;
  if (maiaCCLexDecode(token->value, token->length, units, units + entries, &length)) {
    for (unsigned int index = maiaCCLexPatternCount; index < maiaCCLexContextCount; ++index) {
      if (maiaCCLexPatterns[index].token == expected) {
        accepted = maiaCCLexMatch(maiaCCLexPatterns + index, units, length, 0) == (int)length;
        break;
      }
    }
  }
  free(units);
  return accepted;
}


struct MaiaCCParseEvents {
  void* context;
  unsigned int (*checkpoint)(void*);
  void (*restore)(void*, unsigned int);
  void (*startNonterminal)(void*, const char*, unsigned int);
  void (*terminal)(void*, unsigned int, const char*, unsigned int, unsigned int);
  void (*endNonterminal)(void*, const char*, unsigned int);
  void (*abortNonterminal)(void*, const char*, unsigned int);
  int (*matchesContextual)(void*, unsigned int, const MaiaCCParserToken*);
};

#define MAIACC_PARSE_RESOURCE_NONE 0
#define MAIACC_PARSE_RESOURCE_NOMEM 1
#define MAIACC_PARSE_RESOURCE_LIMIT 2

struct MaiaCCParserState {
  const MaiaCCParserToken* tokens;
  unsigned int tokenCount;
  unsigned int position;
  const MaiaCCParseEvents* events;
  int failed;
  int resourceError;
  unsigned int errorCount;
  unsigned int errorPosition;
  unsigned int expectedToken;
  unsigned int foundToken;
  unsigned char* failureMemo;
};

static void maiaCCParserStateInit(
    MaiaCCParserState* self,
    const MaiaCCParserToken* tokens,
    unsigned int tokenCount,
    const MaiaCCParseEvents* events) {
  self->tokens = tokens;
  self->tokenCount = tokenCount;
  self->position = 0;
  self->events = events;
  self->failed = 0;
  self->resourceError = MAIACC_PARSE_RESOURCE_NONE;
  self->errorCount = 0;
  self->errorPosition = 0;
  self->expectedToken = 0;
  self->foundToken = 0;
  self->failureMemo = 0;
}

static const MaiaCCParserToken* maiaCC_peek(const MaiaCCParserState* self) {
  return self->position < self->tokenCount ? self->tokens + self->position : 0;
}

static void maiaCC_recordError(MaiaCCParserState* self, unsigned int expected) {
  if (self->errorCount == 0) {
    const MaiaCCParserToken* token = maiaCC_peek(self);
    self->errorPosition = self->position;
    self->expectedToken = expected;
    self->foundToken = token ? token->type : MAIACC_TOKEN_EOF;
  }
  ++self->errorCount;
}

static unsigned int maiaCC_checkpointEvents(const MaiaCCParserState* self) {
  return self->events && self->events->checkpoint
      ? self->events->checkpoint(self->events->context)
      : 0;
}

static void maiaCC_restoreEvents(const MaiaCCParserState* self, unsigned int mark) {
  if (self->events && self->events->restore) {
    self->events->restore(self->events->context, mark);
  }
}

static void maiaCC_startNonterminal(const MaiaCCParserState* self, const char* name) {
  if (self->events && self->events->startNonterminal) {
    self->events->startNonterminal(self->events->context, name, self->position);
  }
}

static void maiaCC_endNonterminal(const MaiaCCParserState* self, const char* name) {
  if (self->events && self->events->endNonterminal) {
    self->events->endNonterminal(self->events->context, name, self->position);
  }
}

static void maiaCC_abortNonterminal(const MaiaCCParserState* self, const char* name) {
  if (self->events && self->events->abortNonterminal) {
    self->events->abortNonterminal(self->events->context, name, self->position);
  }
}

static void maiaCC_emitTerminal(
    const MaiaCCParserState* self,
    const MaiaCCParserToken* token) {
  if (self->events && self->events->terminal && token) {
    self->events->terminal(
        self->events->context,
        token->type,
        token->value,
        token->length,
        self->position);
  }
}

static int maiaCC_matchToken(MaiaCCParserState* self, unsigned int expected) {
  if (self->failed) return 0;
  const MaiaCCParserToken* token = maiaCC_peek(self);
  if (!token || token->type != expected) return 0;
  maiaCC_emitTerminal(self, token);
  ++self->position;
  return 1;
}

static int maiaCC_matchContextualToken(MaiaCCParserState* self, unsigned int expected) {
  if (self->failed) return 0;
  const MaiaCCParserToken* token = maiaCC_peek(self);
  if (!token) { maiaCC_recordError(self, expected); return 0; }
  const int accepted = token->type == expected
      || maiaCCLexMatchesContextual(expected, token)
      || (self->events && self->events->matchesContextual
          && self->events->matchesContextual(self->events->context, expected, token));
  if (!accepted) { maiaCC_recordError(self, expected); return 0; }
  maiaCC_emitTerminal(self, token);
  ++self->position;
  return 1;
}

static int maiaCC_expectToken(MaiaCCParserState* self, unsigned int expected) {
  if (maiaCC_matchToken(self, expected)) return 1;
  maiaCC_recordError(self, expected);
  self->failed = 1;
  return 0;
}

static int maiaCC_expectContextualToken(MaiaCCParserState* self, unsigned int expected) {
  if (maiaCC_matchContextualToken(self, expected)) return 1;
  self->failed = 1;
  return 0;
}

static int maiaCC_parse_Input(MaiaCCParserState* self);
static int maiaCC_parse_Sequence0(MaiaCCParserState* self);
static int maiaCC_parse_Piece0(MaiaCCParserState* self);
static int maiaCC_parse_Atom0(MaiaCCParserState* self);
static int maiaCC_parse_Group0(MaiaCCParserState* self);
static int maiaCC_parse_Sequence1(MaiaCCParserState* self);
static int maiaCC_parse_Piece1(MaiaCCParserState* self);
static int maiaCC_parse_Atom1(MaiaCCParserState* self);
static int maiaCC_parse_Group1(MaiaCCParserState* self);
static int maiaCC_parse_Sequence2(MaiaCCParserState* self);
static int maiaCC_parse_Piece2(MaiaCCParserState* self);
static int maiaCC_parse_Atom2(MaiaCCParserState* self);
static int maiaCC_parse_Group2(MaiaCCParserState* self);
static int maiaCC_parse_Sequence3(MaiaCCParserState* self);
static int maiaCC_parse_Piece3(MaiaCCParserState* self);
static int maiaCC_parse_Atom3(MaiaCCParserState* self);
static int maiaCC_parse_Group3(MaiaCCParserState* self);
static int maiaCC_parse_Sequence4(MaiaCCParserState* self);
static int maiaCC_parse_Piece4(MaiaCCParserState* self);
static int maiaCC_parse_Atom4(MaiaCCParserState* self);
static int maiaCC_parse_Group4(MaiaCCParserState* self);
static int maiaCC_parse_Sequence5(MaiaCCParserState* self);
static int maiaCC_parse_Piece5(MaiaCCParserState* self);
static int maiaCC_parse_Atom5(MaiaCCParserState* self);
static int maiaCC_parse_Group5(MaiaCCParserState* self);
static int maiaCC_parse_Sequence6(MaiaCCParserState* self);
static int maiaCC_parse_Piece6(MaiaCCParserState* self);
static int maiaCC_parse_Atom6(MaiaCCParserState* self);
static int maiaCC_parse_Group6(MaiaCCParserState* self);
static int maiaCC_parse_Sequence7(MaiaCCParserState* self);
static int maiaCC_parse_Piece7(MaiaCCParserState* self);
static int maiaCC_parse_Atom7(MaiaCCParserState* self);
static int maiaCC_parse_Group7(MaiaCCParserState* self);
static int maiaCC_parse_Sequence8(MaiaCCParserState* self);
static int maiaCC_parse_Piece8(MaiaCCParserState* self);
static int maiaCC_parse_Atom8(MaiaCCParserState* self);
static int maiaCC_parse_Group8(MaiaCCParserState* self);
static int maiaCC_parse_Sequence9(MaiaCCParserState* self);
static int maiaCC_parse_Piece9(MaiaCCParserState* self);
static int maiaCC_parse_Atom9(MaiaCCParserState* self);
static int maiaCC_parse_DepthOverflow(MaiaCCParserState* self);
static int maiaCC_parse_BeginAnchor(MaiaCCParserState* self);
static int maiaCC_parse_EndAnchor(MaiaCCParserState* self);
static int maiaCC_parse_InitialStarPiece(MaiaCCParserState* self);
static int maiaCC_parse_InitialStar(MaiaCCParserState* self);
static int maiaCC_parse_GroupOpen(MaiaCCParserState* self);
static int maiaCC_parse_GroupClose(MaiaCCParserState* self);
static int maiaCC_parse_Any(MaiaCCParserState* self);
static int maiaCC_parse_Reference(MaiaCCParserState* self);
static int maiaCC_parse_Escape(MaiaCCParserState* self);
static int maiaCC_parse_UnsupportedEscape(MaiaCCParserState* self);
static int maiaCC_parse_Literal(MaiaCCParserState* self);
static int maiaCC_parse_Quantifier(MaiaCCParserState* self);
static int maiaCC_parse_StarRepeat(MaiaCCParserState* self);
static int maiaCC_parse_ExactRepeat(MaiaCCParserState* self);
static int maiaCC_parse_OpenRepeat(MaiaCCParserState* self);
static int maiaCC_parse_BoundedRepeat(MaiaCCParserState* self);
static int maiaCC_parse_Number(MaiaCCParserState* self);
static int maiaCC_parse_Class(MaiaCCParserState* self);
static int maiaCC_parse_ClassOpen(MaiaCCParserState* self);
static int maiaCC_parse_Negation(MaiaCCParserState* self);
static int maiaCC_parse_InitialCloseRange(MaiaCCParserState* self);
static int maiaCC_parse_InitialClose(MaiaCCParserState* self);
static int maiaCC_parse_ClassElement(MaiaCCParserState* self);
static int maiaCC_parse_NamedClass(MaiaCCParserState* self);
static int maiaCC_parse_ClassName(MaiaCCParserState* self);
static int maiaCC_parse_Collating(MaiaCCParserState* self);
static int maiaCC_parse_Equivalence(MaiaCCParserState* self);
static int maiaCC_parse_CollatingScalar(MaiaCCParserState* self);
static int maiaCC_parse_EquivalenceScalar(MaiaCCParserState* self);
static int maiaCC_parse_Range(MaiaCCParserState* self);
static int maiaCC_parse_ClassScalar(MaiaCCParserState* self);


static int maiaCC_parse(MaiaCCParserState* self) {
  self->position = 0;
  self->failed = 0;
  self->resourceError = MAIACC_PARSE_RESOURCE_NONE;
  self->errorCount = 0;
  size_t columns = (size_t)self->tokenCount + 1;
  if (columns == 0 || MAIACC_RULE_COUNT > ((size_t)-1) / columns) { self->failed = 1; self->resourceError = MAIACC_PARSE_RESOURCE_LIMIT; return 0; }
  self->failureMemo = (unsigned char*)calloc(MAIACC_RULE_COUNT, columns);
  if (!self->failureMemo) { self->failed = 1; self->resourceError = MAIACC_PARSE_RESOURCE_NOMEM; return 0; }
  int accepted = maiaCC_parse_Input(self) && !self->failed;
  if (accepted) accepted = self->position == self->tokenCount
      || (self->position + 1 == self->tokenCount
          && maiaCC_peek(self)->type == MAIACC_TOKEN_EOF);
  free(self->failureMemo);
  self->failureMemo = 0;
  return accepted;
}

static int maiaCC_parse_Input(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)0 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Input");
    if (!self->failed && !maiaCC_parse_Sequence0(self)) self->failed = 1;
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_EOF);
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Input");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Input");
  return 0;
}

static int maiaCC_parse_Sequence0(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)1 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Sequence0");
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_BeginAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_InitialStarPiece(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    while (!self->failed) {
      const unsigned int _iterationStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Piece0(self)) {
        self->position = _iterationStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
        break;
      }
      if (self->position == _iterationStart) break;
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_EndAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Sequence0");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Sequence0");
  return 0;
}

static int maiaCC_parse_Piece0(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)2 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Piece0");
    if (!self->failed && !maiaCC_parse_Atom0(self)) self->failed = 1;
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Quantifier(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Piece0");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Piece0");
  return 0;
}

static int maiaCC_parse_Atom0(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)3 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Atom0");
    int _matched = 0;
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Group0(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Class(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Any(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Reference(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Escape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_UnsupportedEscape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Literal(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Atom0");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Atom0");
  return 0;
}

static int maiaCC_parse_Group0(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)4 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Group0");
    if (!self->failed && !maiaCC_parse_GroupOpen(self)) self->failed = 1;
    if (!self->failed && !maiaCC_parse_Sequence1(self)) self->failed = 1;
    if (!self->failed && !maiaCC_parse_GroupClose(self)) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Group0");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Group0");
  return 0;
}

static int maiaCC_parse_Sequence1(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)5 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Sequence1");
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_BeginAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_InitialStarPiece(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    while (!self->failed) {
      const unsigned int _iterationStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Piece1(self)) {
        self->position = _iterationStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
        break;
      }
      if (self->position == _iterationStart) break;
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_EndAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Sequence1");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Sequence1");
  return 0;
}

static int maiaCC_parse_Piece1(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)6 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Piece1");
    if (!self->failed && !maiaCC_parse_Atom1(self)) self->failed = 1;
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Quantifier(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Piece1");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Piece1");
  return 0;
}

static int maiaCC_parse_Atom1(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)7 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Atom1");
    int _matched = 0;
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Group1(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Class(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Any(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Reference(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Escape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_UnsupportedEscape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Literal(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Atom1");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Atom1");
  return 0;
}

static int maiaCC_parse_Group1(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)8 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Group1");
    if (!self->failed && !maiaCC_parse_GroupOpen(self)) self->failed = 1;
    if (!self->failed && !maiaCC_parse_Sequence2(self)) self->failed = 1;
    if (!self->failed && !maiaCC_parse_GroupClose(self)) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Group1");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Group1");
  return 0;
}

static int maiaCC_parse_Sequence2(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)9 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Sequence2");
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_BeginAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_InitialStarPiece(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    while (!self->failed) {
      const unsigned int _iterationStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Piece2(self)) {
        self->position = _iterationStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
        break;
      }
      if (self->position == _iterationStart) break;
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_EndAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Sequence2");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Sequence2");
  return 0;
}

static int maiaCC_parse_Piece2(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)10 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Piece2");
    if (!self->failed && !maiaCC_parse_Atom2(self)) self->failed = 1;
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Quantifier(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Piece2");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Piece2");
  return 0;
}

static int maiaCC_parse_Atom2(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)11 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Atom2");
    int _matched = 0;
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Group2(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Class(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Any(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Reference(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Escape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_UnsupportedEscape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Literal(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Atom2");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Atom2");
  return 0;
}

static int maiaCC_parse_Group2(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)12 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Group2");
    if (!self->failed && !maiaCC_parse_GroupOpen(self)) self->failed = 1;
    if (!self->failed && !maiaCC_parse_Sequence3(self)) self->failed = 1;
    if (!self->failed && !maiaCC_parse_GroupClose(self)) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Group2");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Group2");
  return 0;
}

static int maiaCC_parse_Sequence3(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)13 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Sequence3");
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_BeginAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_InitialStarPiece(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    while (!self->failed) {
      const unsigned int _iterationStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Piece3(self)) {
        self->position = _iterationStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
        break;
      }
      if (self->position == _iterationStart) break;
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_EndAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Sequence3");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Sequence3");
  return 0;
}

static int maiaCC_parse_Piece3(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)14 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Piece3");
    if (!self->failed && !maiaCC_parse_Atom3(self)) self->failed = 1;
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Quantifier(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Piece3");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Piece3");
  return 0;
}

static int maiaCC_parse_Atom3(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)15 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Atom3");
    int _matched = 0;
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Group3(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Class(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Any(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Reference(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Escape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_UnsupportedEscape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Literal(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Atom3");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Atom3");
  return 0;
}

static int maiaCC_parse_Group3(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)16 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Group3");
    if (!self->failed && !maiaCC_parse_GroupOpen(self)) self->failed = 1;
    if (!self->failed && !maiaCC_parse_Sequence4(self)) self->failed = 1;
    if (!self->failed && !maiaCC_parse_GroupClose(self)) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Group3");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Group3");
  return 0;
}

static int maiaCC_parse_Sequence4(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)17 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Sequence4");
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_BeginAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_InitialStarPiece(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    while (!self->failed) {
      const unsigned int _iterationStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Piece4(self)) {
        self->position = _iterationStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
        break;
      }
      if (self->position == _iterationStart) break;
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_EndAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Sequence4");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Sequence4");
  return 0;
}

static int maiaCC_parse_Piece4(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)18 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Piece4");
    if (!self->failed && !maiaCC_parse_Atom4(self)) self->failed = 1;
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Quantifier(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Piece4");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Piece4");
  return 0;
}

static int maiaCC_parse_Atom4(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)19 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Atom4");
    int _matched = 0;
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Group4(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Class(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Any(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Reference(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Escape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_UnsupportedEscape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Literal(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Atom4");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Atom4");
  return 0;
}

static int maiaCC_parse_Group4(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)20 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Group4");
    if (!self->failed && !maiaCC_parse_GroupOpen(self)) self->failed = 1;
    if (!self->failed && !maiaCC_parse_Sequence5(self)) self->failed = 1;
    if (!self->failed && !maiaCC_parse_GroupClose(self)) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Group4");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Group4");
  return 0;
}

static int maiaCC_parse_Sequence5(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)21 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Sequence5");
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_BeginAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_InitialStarPiece(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    while (!self->failed) {
      const unsigned int _iterationStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Piece5(self)) {
        self->position = _iterationStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
        break;
      }
      if (self->position == _iterationStart) break;
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_EndAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Sequence5");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Sequence5");
  return 0;
}

static int maiaCC_parse_Piece5(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)22 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Piece5");
    if (!self->failed && !maiaCC_parse_Atom5(self)) self->failed = 1;
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Quantifier(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Piece5");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Piece5");
  return 0;
}

static int maiaCC_parse_Atom5(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)23 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Atom5");
    int _matched = 0;
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Group5(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Class(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Any(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Reference(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Escape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_UnsupportedEscape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Literal(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Atom5");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Atom5");
  return 0;
}

static int maiaCC_parse_Group5(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)24 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Group5");
    if (!self->failed && !maiaCC_parse_GroupOpen(self)) self->failed = 1;
    if (!self->failed && !maiaCC_parse_Sequence6(self)) self->failed = 1;
    if (!self->failed && !maiaCC_parse_GroupClose(self)) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Group5");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Group5");
  return 0;
}

static int maiaCC_parse_Sequence6(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)25 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Sequence6");
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_BeginAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_InitialStarPiece(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    while (!self->failed) {
      const unsigned int _iterationStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Piece6(self)) {
        self->position = _iterationStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
        break;
      }
      if (self->position == _iterationStart) break;
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_EndAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Sequence6");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Sequence6");
  return 0;
}

static int maiaCC_parse_Piece6(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)26 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Piece6");
    if (!self->failed && !maiaCC_parse_Atom6(self)) self->failed = 1;
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Quantifier(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Piece6");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Piece6");
  return 0;
}

static int maiaCC_parse_Atom6(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)27 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Atom6");
    int _matched = 0;
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Group6(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Class(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Any(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Reference(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Escape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_UnsupportedEscape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Literal(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Atom6");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Atom6");
  return 0;
}

static int maiaCC_parse_Group6(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)28 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Group6");
    if (!self->failed && !maiaCC_parse_GroupOpen(self)) self->failed = 1;
    if (!self->failed && !maiaCC_parse_Sequence7(self)) self->failed = 1;
    if (!self->failed && !maiaCC_parse_GroupClose(self)) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Group6");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Group6");
  return 0;
}

static int maiaCC_parse_Sequence7(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)29 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Sequence7");
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_BeginAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_InitialStarPiece(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    while (!self->failed) {
      const unsigned int _iterationStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Piece7(self)) {
        self->position = _iterationStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
        break;
      }
      if (self->position == _iterationStart) break;
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_EndAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Sequence7");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Sequence7");
  return 0;
}

static int maiaCC_parse_Piece7(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)30 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Piece7");
    if (!self->failed && !maiaCC_parse_Atom7(self)) self->failed = 1;
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Quantifier(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Piece7");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Piece7");
  return 0;
}

static int maiaCC_parse_Atom7(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)31 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Atom7");
    int _matched = 0;
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Group7(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Class(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Any(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Reference(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Escape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_UnsupportedEscape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Literal(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Atom7");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Atom7");
  return 0;
}

static int maiaCC_parse_Group7(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)32 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Group7");
    if (!self->failed && !maiaCC_parse_GroupOpen(self)) self->failed = 1;
    if (!self->failed && !maiaCC_parse_Sequence8(self)) self->failed = 1;
    if (!self->failed && !maiaCC_parse_GroupClose(self)) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Group7");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Group7");
  return 0;
}

static int maiaCC_parse_Sequence8(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)33 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Sequence8");
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_BeginAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_InitialStarPiece(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    while (!self->failed) {
      const unsigned int _iterationStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Piece8(self)) {
        self->position = _iterationStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
        break;
      }
      if (self->position == _iterationStart) break;
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_EndAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Sequence8");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Sequence8");
  return 0;
}

static int maiaCC_parse_Piece8(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)34 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Piece8");
    if (!self->failed && !maiaCC_parse_Atom8(self)) self->failed = 1;
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Quantifier(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Piece8");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Piece8");
  return 0;
}

static int maiaCC_parse_Atom8(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)35 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Atom8");
    int _matched = 0;
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Group8(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Class(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Any(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Reference(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Escape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_UnsupportedEscape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Literal(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Atom8");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Atom8");
  return 0;
}

static int maiaCC_parse_Group8(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)36 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Group8");
    if (!self->failed && !maiaCC_parse_GroupOpen(self)) self->failed = 1;
    if (!self->failed && !maiaCC_parse_Sequence9(self)) self->failed = 1;
    if (!self->failed && !maiaCC_parse_GroupClose(self)) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Group8");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Group8");
  return 0;
}

static int maiaCC_parse_Sequence9(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)37 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Sequence9");
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_BeginAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_InitialStarPiece(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    while (!self->failed) {
      const unsigned int _iterationStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Piece9(self)) {
        self->position = _iterationStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
        break;
      }
      if (self->position == _iterationStart) break;
    }
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_EndAnchor(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Sequence9");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Sequence9");
  return 0;
}

static int maiaCC_parse_Piece9(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)38 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Piece9");
    if (!self->failed && !maiaCC_parse_Atom9(self)) self->failed = 1;
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Quantifier(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Piece9");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Piece9");
  return 0;
}

static int maiaCC_parse_Atom9(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)39 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Atom9");
    int _matched = 0;
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_DepthOverflow(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Class(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Any(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Reference(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Escape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_UnsupportedEscape(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Literal(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Atom9");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Atom9");
  return 0;
}

static int maiaCC_parse_DepthOverflow(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)40 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "DepthOverflow");
    if (!self->failed && !maiaCC_parse_GroupOpen(self)) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "DepthOverflow");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "DepthOverflow");
  return 0;
}

static int maiaCC_parse_BeginAnchor(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)41 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "BeginAnchor");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CARET);
  if (!self->failed) {
    maiaCC_endNonterminal(self, "BeginAnchor");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "BeginAnchor");
  return 0;
}

static int maiaCC_parse_EndAnchor(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)42 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "EndAnchor");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_END_DOLLAR);
  if (!self->failed) {
    maiaCC_endNonterminal(self, "EndAnchor");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "EndAnchor");
  return 0;
}

static int maiaCC_parse_InitialStarPiece(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)43 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "InitialStarPiece");
    if (!self->failed && !maiaCC_parse_InitialStar(self)) self->failed = 1;
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Quantifier(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "InitialStarPiece");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "InitialStarPiece");
  return 0;
}

static int maiaCC_parse_InitialStar(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)44 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "InitialStar");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_STAR);
  if (!self->failed) {
    maiaCC_endNonterminal(self, "InitialStar");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "InitialStar");
  return 0;
}

static int maiaCC_parse_GroupOpen(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)45 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "GroupOpen");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_BACKSLASH);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_LPAREN);
  if (!self->failed) {
    maiaCC_endNonterminal(self, "GroupOpen");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "GroupOpen");
  return 0;
}

static int maiaCC_parse_GroupClose(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)46 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "GroupClose");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_BACKSLASH);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_RPAREN);
  if (!self->failed) {
    maiaCC_endNonterminal(self, "GroupClose");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "GroupClose");
  return 0;
}

static int maiaCC_parse_Any(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)47 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Any");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DOT);
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Any");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Any");
  return 0;
}

static int maiaCC_parse_Reference(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)48 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Reference");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_BACKSLASH);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DIGIT);
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Reference");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Reference");
  return 0;
}

static int maiaCC_parse_Escape(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)49 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Escape");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_BACKSLASH);
    {
      int _matchedAlternative = 0;
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_BACKSLASH);
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DOT);
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CARET);
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DOLLAR);
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_END_DOLLAR);
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_OPEN);
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_OPEN_SPECIAL);
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CLOSE);
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_STAR);
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative) self->failed = 1;
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Escape");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Escape");
  return 0;
}

static int maiaCC_parse_UnsupportedEscape(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)50 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "UnsupportedEscape");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_BACKSLASH);
    {
      int _matchedAlternative = 0;
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_PLUS);
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_QUESTION);
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_PIPE);
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_LETTER);
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CHAR);
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DASH);
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_COLON);
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_EQUAL);
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_COMMA);
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative) self->failed = 1;
    }
  if (!self->failed) {
    maiaCC_endNonterminal(self, "UnsupportedEscape");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "UnsupportedEscape");
  return 0;
}

static int maiaCC_parse_Literal(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)51 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Literal");
    int _matched = 0;
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_LETTER);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DIGIT);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CHAR);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_PLUS);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_QUESTION);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_PIPE);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_LPAREN);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_RPAREN);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_LBRACE);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_RBRACE);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DASH);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_COLON);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_EQUAL);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_COMMA);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CARET);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DOLLAR);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CLOSE);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Literal");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Literal");
  return 0;
}

static int maiaCC_parse_Quantifier(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)52 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Quantifier");
    int _matched = 0;
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_StarRepeat(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_ExactRepeat(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_OpenRepeat(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_BoundedRepeat(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Quantifier");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Quantifier");
  return 0;
}

static int maiaCC_parse_StarRepeat(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)53 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "StarRepeat");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_STAR);
  if (!self->failed) {
    maiaCC_endNonterminal(self, "StarRepeat");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "StarRepeat");
  return 0;
}

static int maiaCC_parse_ExactRepeat(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)54 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "ExactRepeat");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_BACKSLASH);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_LBRACE);
    if (!self->failed && !maiaCC_parse_Number(self)) self->failed = 1;
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_BACKSLASH);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_RBRACE);
  if (!self->failed) {
    maiaCC_endNonterminal(self, "ExactRepeat");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "ExactRepeat");
  return 0;
}

static int maiaCC_parse_OpenRepeat(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)55 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "OpenRepeat");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_BACKSLASH);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_LBRACE);
    if (!self->failed && !maiaCC_parse_Number(self)) self->failed = 1;
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_COMMA);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_BACKSLASH);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_RBRACE);
  if (!self->failed) {
    maiaCC_endNonterminal(self, "OpenRepeat");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "OpenRepeat");
  return 0;
}

static int maiaCC_parse_BoundedRepeat(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)56 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "BoundedRepeat");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_BACKSLASH);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_LBRACE);
    if (!self->failed && !maiaCC_parse_Number(self)) self->failed = 1;
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_COMMA);
    if (!self->failed && !maiaCC_parse_Number(self)) self->failed = 1;
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_BACKSLASH);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_RBRACE);
  if (!self->failed) {
    maiaCC_endNonterminal(self, "BoundedRepeat");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "BoundedRepeat");
  return 0;
}

static int maiaCC_parse_Number(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)57 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Number");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DIGIT);
    while (maiaCC_matchToken(self, MAIACC_TOKEN_DIGIT)) {}
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Number");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Number");
  return 0;
}

static int maiaCC_parse_Class(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)58 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Class");
    if (!self->failed && !maiaCC_parse_ClassOpen(self)) self->failed = 1;
    if (!self->failed) {
      const unsigned int _optionalStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_Negation(self)) {
        self->position = _optionalStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    {
      int _matchedAlternative = 0;
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_InitialCloseRange(self)) self->failed = 1;
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_InitialClose(self)) self->failed = 1;
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative && !self->failed) {
        const unsigned int _alternativeStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_ClassElement(self)) self->failed = 1;
        if (!self->failed) {
          _matchedAlternative = 1;
        } else {
          self->position = _alternativeStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
        }
      }
      if (!_matchedAlternative) self->failed = 1;
    }
    while (!self->failed) {
      const unsigned int _iterationStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
      if (!maiaCC_parse_ClassElement(self)) {
        self->position = _iterationStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
        break;
      }
      if (self->position == _iterationStart) break;
    }
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CLOSE);
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Class");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Class");
  return 0;
}

static int maiaCC_parse_ClassOpen(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)59 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "ClassOpen");
    int _matched = 0;
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_OPEN);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_OPEN_SPECIAL);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "ClassOpen");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "ClassOpen");
  return 0;
}

static int maiaCC_parse_Negation(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)60 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Negation");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CARET);
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Negation");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Negation");
  return 0;
}

static int maiaCC_parse_InitialCloseRange(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)61 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "InitialCloseRange");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CLOSE);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DASH);
    if (!self->failed && !maiaCC_parse_ClassScalar(self)) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "InitialCloseRange");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "InitialCloseRange");
  return 0;
}

static int maiaCC_parse_InitialClose(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)62 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "InitialClose");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CLOSE);
  if (!self->failed) {
    maiaCC_endNonterminal(self, "InitialClose");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "InitialClose");
  return 0;
}

static int maiaCC_parse_ClassElement(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)63 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "ClassElement");
    int _matched = 0;
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_NamedClass(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Collating(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Equivalence(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_Range(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed && !maiaCC_parse_ClassScalar(self)) self->failed = 1;
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "ClassElement");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "ClassElement");
  return 0;
}

static int maiaCC_parse_NamedClass(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)64 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "NamedClass");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_OPEN_SPECIAL);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_COLON);
    if (!self->failed && !maiaCC_parse_ClassName(self)) self->failed = 1;
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_COLON);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CLOSE);
  if (!self->failed) {
    maiaCC_endNonterminal(self, "NamedClass");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "NamedClass");
  return 0;
}

static int maiaCC_parse_ClassName(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)65 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "ClassName");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_LETTER);
    while (maiaCC_matchToken(self, MAIACC_TOKEN_LETTER)) {}
  if (!self->failed) {
    maiaCC_endNonterminal(self, "ClassName");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "ClassName");
  return 0;
}

static int maiaCC_parse_Collating(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)66 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Collating");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_OPEN_SPECIAL);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DOT);
    {
      unsigned int _count = 0;
      while (!self->failed) {
        const unsigned int _iterationStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
        if (!maiaCC_parse_CollatingScalar(self)) {
          self->position = _iterationStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
          break;
        }
        if (self->position == _iterationStart) break;
        ++_count;
      }
      if (_count == 0) self->failed = 1;
    }
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DOT);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CLOSE);
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Collating");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Collating");
  return 0;
}

static int maiaCC_parse_Equivalence(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)67 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Equivalence");
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_OPEN_SPECIAL);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_EQUAL);
    {
      unsigned int _count = 0;
      while (!self->failed) {
        const unsigned int _iterationStart = self->position;
        const unsigned int _eventMark = maiaCC_checkpointEvents(self);
        if (!maiaCC_parse_EquivalenceScalar(self)) {
          self->position = _iterationStart;
          maiaCC_restoreEvents(self, _eventMark);
          self->failed = 0;
          break;
        }
        if (self->position == _iterationStart) break;
        ++_count;
      }
      if (_count == 0) self->failed = 1;
    }
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_EQUAL);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CLOSE);
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Equivalence");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Equivalence");
  return 0;
}

static int maiaCC_parse_CollatingScalar(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)68 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "CollatingScalar");
    int _matched = 0;
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_LETTER);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DIGIT);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CHAR);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_PLUS);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_QUESTION);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_PIPE);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_LPAREN);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_RPAREN);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_LBRACE);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_RBRACE);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DASH);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_COLON);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_EQUAL);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_COMMA);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CARET);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DOLLAR);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_END_DOLLAR);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_STAR);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_BACKSLASH);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_OPEN);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "CollatingScalar");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "CollatingScalar");
  return 0;
}

static int maiaCC_parse_EquivalenceScalar(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)69 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "EquivalenceScalar");
    int _matched = 0;
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_LETTER);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DIGIT);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CHAR);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_PLUS);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_QUESTION);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_PIPE);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_LPAREN);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_RPAREN);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_LBRACE);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_RBRACE);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DASH);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_COLON);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DOT);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_COMMA);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CARET);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DOLLAR);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_END_DOLLAR);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_STAR);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_BACKSLASH);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_OPEN);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "EquivalenceScalar");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "EquivalenceScalar");
  return 0;
}

static int maiaCC_parse_Range(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)70 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "Range");
    if (!self->failed && !maiaCC_parse_ClassScalar(self)) self->failed = 1;
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DASH);
    if (!self->failed && !maiaCC_parse_ClassScalar(self)) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "Range");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "Range");
  return 0;
}

static int maiaCC_parse_ClassScalar(MaiaCCParserState* self) {
  if (self->failed) return 0;
  const unsigned int __ruleStart = self->position;
  const size_t __memoSlot = (size_t)71 * ((size_t)self->tokenCount + 1) + __ruleStart;
  if (self->failureMemo && self->failureMemo[__memoSlot]) { self->failed = 1; return 0; }
  const unsigned int __eventMark = maiaCC_checkpointEvents(self);
  maiaCC_startNonterminal(self, "ClassScalar");
    int _matched = 0;
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_LETTER);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DIGIT);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CHAR);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_PLUS);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_QUESTION);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_PIPE);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_LPAREN);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_RPAREN);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_LBRACE);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_RBRACE);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DASH);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_COLON);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DOT);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_EQUAL);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_COMMA);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_CARET);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_DOLLAR);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_END_DOLLAR);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_STAR);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_BACKSLASH);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched && !self->failed) {
      const unsigned int _alternativeStart = self->position;
      const unsigned int _eventMark = maiaCC_checkpointEvents(self);
    if (!self->failed) maiaCC_expectToken(self, MAIACC_TOKEN_OPEN);
      if (!self->failed) {
        _matched = 1;
      } else {
        self->position = _alternativeStart;
        maiaCC_restoreEvents(self, _eventMark);
        self->failed = 0;
      }
    }
    if (!_matched) self->failed = 1;
  if (!self->failed) {
    maiaCC_endNonterminal(self, "ClassScalar");
    return 1;
  }
  self->position = __ruleStart;
  if (self->failureMemo) self->failureMemo[__memoSlot] = 1;
  maiaCC_restoreEvents(self, __eventMark);
  maiaCC_abortNonterminal(self, "ClassScalar");
  return 0;
}

#endif
