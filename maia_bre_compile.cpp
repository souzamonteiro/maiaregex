/* Generated syntax adapter and iterative semantic lowering.
 * Copyright 2026 Roberto Luiz Souza Monteiro. SPDX-License-Identifier: Apache-2.0 */
#define MAIACPP_USE_C_ALLOCATOR
#include "maia_bre_internal.h"
#include "maia_regex.h"
#include <stdlib.h>
#include <string.h>
#include "generated/bre-prefix.hpp"
#include "generated/bre-parser.hpp"
struct BreNode {const char* name;unsigned int token,kind,end,entry,tail,group;int parent;};
struct BreCompile {
 char source[1025];MaiaCCParserToken tokens[1025];BreNode nodes[8192];
 unsigned int count,overflow,depth_overflow;int active;
 unsigned int groups[10];MaiaBreProgram* program;const MaiaBreLimits* limits;size_t steps;
};
static unsigned int bre_checkpoint(void* context){BreCompile* s=(BreCompile*)context;return (s->count<<16)|static_cast<unsigned int>(s->active+1);}
static void bre_restore(void* context,unsigned int mark){BreCompile* s=(BreCompile*)context;s->count=mark>>16;s->active=static_cast<int>(mark&65535u)-1;}
static void bre_append(BreCompile* s,unsigned int kind,const char* name,unsigned int token){
 if(s->count==8192){s->overflow=1;return;}BreNode* n=s->nodes+s->count;n->kind=kind;n->name=name;n->token=token;n->parent=s->active;n->end=s->count+1;n->entry=BRE_NONE;n->tail=BRE_NONE;n->group=0;if(kind==1)s->active=static_cast<int>(s->count);++s->count;
}
static void bre_start(void* context,const char* name,unsigned int){bre_append((BreCompile*)context,1,name,0);}
static void bre_terminal(void* context,unsigned int,const char*,unsigned int,unsigned int position){bre_append((BreCompile*)context,2,0,position);}
static void bre_end(void* context,const char* name,unsigned int){BreCompile* s=(BreCompile*)context;if(s->active<0){s->overflow=1;return;}s->nodes[s->active].end=s->count;s->active=s->nodes[s->active].parent;if(!strcmp(name,"DepthOverflow"))s->depth_overflow=1;}
static void bre_abort(void*,const char*,unsigned int){}
static int bre_named(const BreNode* n,const char* name){return n->kind==1&&!strcmp(n->name,name);}
static int bre_numbered(const BreNode* n,const char* prefix,unsigned int length){return n->kind==1&&!strncmp(n->name,prefix,length)&&n->name[length]>='0'&&n->name[length]<='9'&&!n->name[length+1];}
static int bre_work(BreCompile* s){if(s->steps==s->limits->max_steps)return MAIA_BRE_LIMIT;++s->steps;return 0;}
static unsigned int bre_emit(BreCompile* s,unsigned int op,unsigned int a,unsigned int b){
 MaiaBreProgram* p=s->program;if(p->code_count==p->code_capacity)return BRE_NONE;
 unsigned int id=p->code_count++;BreInstruction* c=p->code+id;c->op=op;c->a=a;c->b=b;c->next=BRE_NONE;c->min=0;c->max=0;return id;
}
static int bre_scalar(BreCompile* s,unsigned int node,unsigned int terminal_index,unsigned int* value){
 unsigned int count=0;
 for(unsigned int i=node+1;i<s->nodes[node].end;++i)if(s->nodes[i].kind==2){
  if(count++==terminal_index){const MaiaCCParserToken* t=s->tokens+s->nodes[i].token;unsigned int at=0;int r=bre_utf8_next(reinterpret_cast<const unsigned char*>(t->value),t->length,&at,value);return r?r:(at==t->length?0:MAIA_BRE_BADPAT);}
 }
 return MAIA_BRE_BADPAT;
}
static int bre_add_range(BreCompile* s,unsigned int a,unsigned int b){
 if(a>b)return MAIA_BRE_BADPAT;MaiaBreProgram* p=s->program;if(p->range_count==p->range_capacity)return MAIA_BRE_LIMIT;
 p->ranges[p->range_count].first=a;p->ranges[p->range_count++].last=b;return 0;
}
static int bre_named_class(BreCompile* s,unsigned int node){
 char name[32];unsigned int size=0;
 for(unsigned int i=node+1;i<s->nodes[node].end;++i)if(bre_named(s->nodes+i,"ClassName")){
  for(unsigned int j=i+1;j<s->nodes[i].end;++j)if(s->nodes[j].kind==2){if(size==31)return MAIA_BRE_BADPAT;name[size++]=s->tokens[s->nodes[j].token].value[0];}break;
 }
 name[size]=0;
 unsigned int ranges[8];unsigned int count=0;
 if(!strcmp(name,"alnum")){ranges[0]=48;ranges[1]=57;ranges[2]=65;ranges[3]=90;ranges[4]=97;ranges[5]=122;count=6;}
 else if(!strcmp(name,"alpha")){ranges[0]=65;ranges[1]=90;ranges[2]=97;ranges[3]=122;count=4;}
 else if(!strcmp(name,"blank")){ranges[0]=9;ranges[1]=9;ranges[2]=32;ranges[3]=32;count=4;}
 else if(!strcmp(name,"cntrl")){ranges[0]=0;ranges[1]=31;ranges[2]=127;ranges[3]=127;count=4;}
 else if(!strcmp(name,"digit")){ranges[0]=48;ranges[1]=57;count=2;}
 else if(!strcmp(name,"graph")){ranges[0]=33;ranges[1]=126;count=2;}
 else if(!strcmp(name,"lower")){ranges[0]=97;ranges[1]=122;count=2;}
 else if(!strcmp(name,"print")){ranges[0]=32;ranges[1]=126;count=2;}
 else if(!strcmp(name,"punct")){ranges[0]=33;ranges[1]=47;ranges[2]=58;ranges[3]=64;ranges[4]=91;ranges[5]=96;ranges[6]=123;ranges[7]=126;count=8;}
 else if(!strcmp(name,"space")){ranges[0]=9;ranges[1]=13;ranges[2]=32;ranges[3]=32;count=4;}
 else if(!strcmp(name,"upper")){ranges[0]=65;ranges[1]=90;count=2;}
 else if(!strcmp(name,"xdigit")){ranges[0]=48;ranges[1]=57;ranges[2]=65;ranges[3]=70;ranges[4]=97;ranges[5]=102;count=6;}
 else return MAIA_BRE_BADPAT;
 for(unsigned int i=0;i<count;i+=2){int r=bre_add_range(s,ranges[i],ranges[i+1]);if(r)return r;}return 0;
}
static int bre_class(BreCompile* s,unsigned int node,unsigned int* instruction){
 unsigned int first=s->program->range_count,negative=0;
 for(unsigned int i=node+1;i<s->nodes[node].end;){
  if(bre_work(s))return MAIA_BRE_LIMIT;BreNode* n=s->nodes+i;int r=0;
  if(bre_named(n,"Negation")){negative=1;i=n->end;continue;}
  if(bre_named(n,"Collating")||bre_named(n,"Equivalence"))return MAIA_BRE_UNSUPPORTED;
  if(bre_named(n,"NamedClass")){r=bre_named_class(s,i);i=n->end;}
  else if(bre_named(n,"InitialClose")){r=bre_add_range(s,93,93);i=n->end;}
  else if(bre_named(n,"Range")||bre_named(n,"InitialCloseRange")){
   unsigned int a=0,b=0,count=0;
   if(bre_named(n,"InitialCloseRange")){a=93;count=1;}
   for(unsigned int j=i+1;j<n->end;)if(bre_named(s->nodes+j,"ClassScalar")){unsigned int value=0;r=bre_scalar(s,j,0,&value);if(r)return r;if(!count)a=value;else b=value;++count;j=s->nodes[j].end;}else ++j;
   if(count!=2)return MAIA_BRE_BADPAT;r=bre_add_range(s,a,b);i=n->end;
  }else if(bre_named(n,"ClassScalar")){
   unsigned int value=0;r=bre_scalar(s,i,0,&value);if(r)return r;
   if(value==45&&s->program->range_count!=first&&n->end+1!=s->nodes[node].end)return MAIA_BRE_BADPAT;
   r=bre_add_range(s,value,value);i=n->end;
  }else{++i;continue;}
  if(r)return r;
 }
 if(s->program->range_count==first)return MAIA_BRE_BADPAT;
 *instruction=bre_emit(s,negative?BRE_NOT_CLASS:BRE_CLASS,first,s->program->range_count-first);return *instruction==BRE_NONE?MAIA_BRE_LIMIT:0;
}
static int bre_quantity(BreCompile* s,unsigned int node,unsigned int* minimum,unsigned int* maximum){
 unsigned int values[2],count=0;*minimum=0;*maximum=UINT_MAX;
 if(bre_named(s->nodes+node,"StarRepeat"))return 0;
 for(unsigned int i=node+1;i<s->nodes[node].end;++i)if(bre_named(s->nodes+i,"Number")){
  unsigned int value=0;
  for(unsigned int j=i+1;j<s->nodes[i].end;++j)if(s->nodes[j].kind==2){unsigned int d=static_cast<unsigned int>(s->tokens[s->nodes[j].token].value[0]-'0');if(d>s->limits->max_repeat||value>(s->limits->max_repeat-d)/10)return MAIA_BRE_LIMIT;value=value*10+d;}
  if(count==2)return MAIA_BRE_BADPAT;values[count++]=value;
 }
 if(!count)return MAIA_BRE_BADPAT;*minimum=values[0];
 if(bre_named(s->nodes+node,"ExactRepeat"))*maximum=*minimum;
 if(bre_named(s->nodes+node,"BoundedRepeat")){if(count!=2)return MAIA_BRE_BADPAT;*maximum=values[1];if(*minimum>*maximum)return MAIA_BRE_BADPAT;}
 return 0;
}
static int bre_lower(BreCompile* s){
 MaiaBreProgram* p=s->program;
 for(unsigned int i=0;i<s->count;++i){
  BreNode* n=s->nodes+i;if(bre_work(s))return MAIA_BRE_LIMIT;
  if(bre_named(n,"UnsupportedEscape"))return MAIA_BRE_UNSUPPORTED;
  if(bre_numbered(n,"Group",5)){
   if(p->groups==s->limits->max_captures)return MAIA_BRE_LIMIT;
   n->group=++p->groups;s->groups[n->group]=i;unsigned int depth=1;
   for(int a=n->parent;a>=0;a=s->nodes[a].parent)if(bre_numbered(s->nodes+a,"Group",5))++depth;
   if(depth>s->limits->max_parse_depth)return MAIA_BRE_LIMIT;if(depth>p->depth)p->depth=depth;
  }
 }
 for(unsigned int i=s->count;i>0;){
  --i;BreNode* n=s->nodes+i;if(n->kind!=1)continue;if(bre_work(s))return MAIA_BRE_LIMIT;
  unsigned int instruction=BRE_NONE;int r=0;
  if(bre_named(n,"Literal")||bre_named(n,"Escape")||bre_named(n,"InitialStar")){
   unsigned int value=42;if(!bre_named(n,"InitialStar")){r=bre_scalar(s,i,bre_named(n,"Escape")?1:0,&value);if(r)return r;}instruction=bre_emit(s,BRE_CHAR,value,0);
  }else if(bre_named(n,"Any"))instruction=bre_emit(s,BRE_ANY,0,0);
  else if(bre_named(n,"BeginAnchor"))instruction=bre_emit(s,BRE_BEGIN,0,0);
  else if(bre_named(n,"EndAnchor"))instruction=bre_emit(s,BRE_END,0,0);
  else if(bre_named(n,"Class")){r=bre_class(s,i,&instruction);if(r)return r;}
  else if(bre_named(n,"Reference")){
   unsigned int value=0;r=bre_scalar(s,i,1,&value);if(r)return r;value-=48;
   if(!value||value>p->groups||s->nodes[s->groups[value]].end>i)return MAIA_BRE_BADPAT;
   instruction=bre_emit(s,BRE_REF,value,0);
  }else{
   unsigned int entry=BRE_NONE,tail=BRE_NONE,quantifier=BRE_NONE;
   for(unsigned int j=i+1;j<n->end;){
    BreNode* child=s->nodes+j;
    if(child->parent==static_cast<int>(i)){
     if(child->entry!=BRE_NONE){if(entry==BRE_NONE)entry=child->entry;else p->code[tail].next=child->entry;tail=child->tail;}
     if(bre_named(child,"Quantifier"))quantifier=j;
    }
    j=child->end;
   }
   if(bre_numbered(n,"Group",5)){
    unsigned int open=bre_emit(s,BRE_OPEN,n->group,0),close=bre_emit(s,BRE_CLOSE,n->group,0);
    if(open==BRE_NONE||close==BRE_NONE)return MAIA_BRE_LIMIT;
    unsigned int last=n->group;for(unsigned int k=n->group+1;k<=p->groups;++k)if(s->groups[k]<n->end)last=k;else break;
    p->code[open].b=last;p->code[open].max=i;
    p->code[open].next=entry==BRE_NONE?close:entry;if(tail!=BRE_NONE)p->code[tail].next=close;entry=open;tail=close;
   }
   if((bre_numbered(n,"Piece",5)||bre_named(n,"InitialStarPiece"))&&quantifier!=BRE_NONE){
    unsigned int minimum=0,maximum=0;
    unsigned int q=quantifier+1;if(q>=s->nodes[quantifier].end)return MAIA_BRE_BADPAT;
    r=bre_quantity(s,q,&minimum,&maximum);if(r)return r;
    unsigned int bound=maximum==UINT_MAX?minimum:maximum;if(bound>p->repeat_bound)p->repeat_bound=bound;
    unsigned int repeat=bre_emit(s,BRE_REPEAT,entry,0),end=bre_emit(s,BRE_REPEAT_END,repeat,0);
    if(repeat==BRE_NONE||end==BRE_NONE||entry==BRE_NONE)return MAIA_BRE_LIMIT;
    p->code[repeat].b=i;p->code[repeat].min=minimum;p->code[repeat].max=maximum;p->code[tail].next=end;entry=repeat;tail=repeat;
   }
   n->entry=entry;n->tail=tail;continue;
  }
  if(instruction==BRE_NONE)return MAIA_BRE_LIMIT;n->entry=instruction;n->tail=instruction;
 }
 unsigned int accept=bre_emit(s,BRE_ACCEPT,0,0);if(accept==BRE_NONE)return MAIA_BRE_LIMIT;
 p->entry=s->nodes[0].entry==BRE_NONE?accept:s->nodes[0].entry;
 if(s->nodes[0].tail!=BRE_NONE)p->code[s->nodes[0].tail].next=accept;return 0;
}
extern "C" int maia_bre_compile_utf8(const unsigned char* pattern,unsigned int length,const MaiaBreLimits* limits,MaiaBreProgram** output){
 int r=bre_limits_valid(limits);if(r)return r;if(!output||!pattern)return MAIA_BRE_ARGUMENT;
 if(length>limits->max_pattern_bytes)return MAIA_BRE_LIMIT;r=bre_text_check(pattern,length);if(r)return r;
 if(sizeof(BreCompile)>limits->max_workspace_bytes)return MAIA_BRE_LIMIT;
 BreCompile* s=(BreCompile*)malloc(sizeof(BreCompile));if(!s)return MAIA_BRE_NOMEM;
 memset(s,0,sizeof(BreCompile));s->active=-1;s->limits=limits;memcpy(s->source,pattern,length);s->source[length]=0;
 MaiaBreProgram* p=(MaiaBreProgram*)calloc(1,sizeof(MaiaBreProgram));if(!p){free(s);return MAIA_BRE_NOMEM;}s->program=p;
 MaiaCCLexerState lexer;maiaCCLexerStateInit(&lexer,s->source,length);
 if(!maiaCCLexerTokenize(&lexer,s->tokens,1025)){r=lexer.failed==2?MAIA_BRE_NOMEM:MAIA_BRE_BADPAT;}
 else{
  MaiaCCParseEvents events;events.context=s;events.checkpoint=bre_checkpoint;events.restore=bre_restore;events.startNonterminal=bre_start;events.terminal=bre_terminal;events.endNonterminal=bre_end;events.abortNonterminal=bre_abort;events.matchesContextual=0;
  MaiaCCParserState parser;maiaCCParserStateInit(&parser,s->tokens,lexer.tokenCount,&events);
  const int parsed=maiaCC_parse(&parser);
  if(parser.resourceError==MAIACC_PARSE_RESOURCE_NOMEM)r=MAIA_BRE_NOMEM;
  else if(parser.resourceError==MAIACC_PARSE_RESOURCE_LIMIT)r=MAIA_BRE_LIMIT;
  else if(s->overflow||s->depth_overflow)r=MAIA_BRE_LIMIT;
  else if(!parsed||parser.failed||parser.position!=lexer.tokenCount||s->active>=0||!s->count)r=MAIA_BRE_BADPAT;
  else{
   p->code_capacity=length*2+16;if(p->code_capacity>limits->max_instructions)p->code_capacity=limits->max_instructions;
   p->range_capacity=length*2+16;if(p->range_capacity>limits->max_ranges)p->range_capacity=limits->max_ranges;
   p->code=(BreInstruction*)malloc(p->code_capacity*sizeof(BreInstruction));p->ranges=(BreRange*)malloc(p->range_capacity*sizeof(BreRange));
   if(!p->code||!p->ranges)r=MAIA_BRE_NOMEM;else r=bre_lower(s);
  }
 }
 if(!r){p->magic=BRE_MAGIC;p->storage_bytes=sizeof(MaiaBreProgram)+p->code_capacity*sizeof(BreInstruction)+p->range_capacity*sizeof(BreRange);*output=p;}else maia_bre_free(p);
 free(s);return r;
}
#include "generated/bre-unprefix.hpp"
