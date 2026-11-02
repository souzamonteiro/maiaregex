/* Syntax/collector probe, isolated from production library exports. */
#include <stdlib.h>
#include <string.h>
#include "../../maia_regex.h"
#include "../../generated/bre-parser.hpp"
struct FrontNode {unsigned int kind,position;const char* name;};
static char front_source[1025];static MaiaCCParserToken front_tokens[1025];static FrontNode front_nodes[16384];static unsigned int front_count,front_token_count,front_overflow;
static unsigned int front_checkpoint(void*){return front_count;}
static void front_restore(void*,unsigned int checkpoint){front_count=checkpoint;}
static void front_add(unsigned int kind,const char* name,unsigned int position){if(front_count==16384){front_overflow=1;return;}FrontNode* n=front_nodes+front_count++;n->kind=kind;n->name=name;n->position=position;}
static void front_start(void*,const char* name,unsigned int position){front_add(1,name,position);}
static void front_end(void*,const char* name,unsigned int position){front_add(2,name,position);}
static void front_abort(void*,const char*,unsigned int){}
static void front_terminal(void*,unsigned int type,const char*,unsigned int,unsigned int position){front_add(3,maiaCCParserTokenName(type),position);}
extern "C" char* bre_front_source(){return front_source;}
extern "C" int bre_front_parse(unsigned int length){front_count=0;front_overflow=0;MaiaCCLexerState lexer;maiaCCLexerStateInit(&lexer,front_source,length);if(!maiaCCLexerTokenize(&lexer,front_tokens,1025))return 0;front_token_count=lexer.tokenCount;MaiaCCParseEvents events;events.context=0;events.checkpoint=front_checkpoint;events.restore=front_restore;events.startNonterminal=front_start;events.endNonterminal=front_end;events.abortNonterminal=front_abort;events.terminal=front_terminal;events.matchesContextual=0;MaiaCCParserState parser;maiaCCParserStateInit(&parser,front_tokens,front_token_count,&events);return maiaCC_parse(&parser)&&!front_overflow;}
extern "C" unsigned int bre_front_nodes(){return front_count;}
extern "C" unsigned int bre_front_tokens(){return front_token_count;}
extern "C" unsigned int bre_front_kind(unsigned int i){return front_nodes[i].kind;}
extern "C" unsigned int bre_front_position(unsigned int i){return front_nodes[i].position;}
extern "C" const char* bre_front_name(unsigned int i){return front_nodes[i].name;}
extern "C" const char* bre_front_token_name(unsigned int i){return maiaCCParserTokenName(front_tokens[i].type);}
extern "C" unsigned int bre_front_byte_start(unsigned int i){return static_cast<unsigned int>(front_tokens[i].value-front_source);}
extern "C" unsigned int bre_front_byte_end(unsigned int i){return bre_front_byte_start(i)+front_tokens[i].length;}
extern "C" unsigned int bre_front_token_start(unsigned int i){return front_tokens[i].start;}
extern "C" unsigned int bre_front_token_end(unsigned int i){return front_tokens[i].end;}
#ifdef BRE_FRONT_NATIVE
#include <stdio.h>
int main(int argc,char** argv){unsigned int i,n;if(argc!=2)return 2;n=(unsigned int)strlen(argv[1]);if(n>1024)return 2;memcpy(front_source,argv[1],n);if(!bre_front_parse(n)){puts("INVALID");return 0;}for(i=0;i<front_token_count;++i)printf("T %s %u %u %u %u\n",bre_front_token_name(i),bre_front_token_start(i),bre_front_token_end(i),bre_front_byte_start(i),bre_front_byte_end(i));for(i=0;i<front_count;++i)printf("N %u %s\n",bre_front_kind(i),bre_front_name(i));return 0;}
#endif
