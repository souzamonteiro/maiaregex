/* Minimal generator-owned failure: no BRE semantic compiler or matcher involved. */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../../maia_regex.h"
static int reject_calloc=0;
static void* parser_probe_calloc(size_t count,size_t size){return reject_calloc?0:calloc(count,size);}
#define calloc parser_probe_calloc
#include "../../generated/bre-parser.hpp"
#undef calloc
int main(){
 MaiaCCLexerState lexer;MaiaCCParserToken tokens[4];MaiaCCParserState parser;
 maiaCCLexerStateInit(&lexer,"a",1);assert(maiaCCLexerTokenize(&lexer,tokens,4));
 maiaCCParserStateInit(&parser,tokens,lexer.tokenCount,0);reject_calloc=1;
 const int result=maiaCC_parse(&parser);
 printf("valid pattern; rejected memo calloc: accepted=%d failed=%d errors=%u position=%u\n",result,parser.failed,parser.errorCount,parser.position);
 assert(!result&&parser.failed==1&&parser.errorCount==0);
 assert(parser.resourceError==MAIACC_PARSE_RESOURCE_NOMEM);
 reject_calloc=0;maiaCCLexerStateInit(&lexer,"[",1);assert(maiaCCLexerTokenize(&lexer,tokens,4));
 maiaCCParserStateInit(&parser,tokens,lexer.tokenCount,0);
 const int malformed=maiaCC_parse(&parser);
 printf("malformed pattern; successful calloc: accepted=%d failed=%d errors=%u position=%u\n",malformed,parser.failed,parser.errorCount,parser.position);
 assert(!malformed&&parser.failed==1);assert(parser.resourceError==MAIACC_PARSE_RESOURCE_NONE);
 puts("PASS: explicit resourceError distinguishes NOMEM from syntax");return 0;
}
