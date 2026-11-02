/* Iterative BRE execution; the ordered lexer engine remains separate.
 * Copyright 2026 Roberto Luiz Souza Monteiro. SPDX-License-Identifier: Apache-2.0 */
#include "maia_bre_internal.h"
#include <stdlib.h>
#include <string.h>
void maia_bre_default_limits(MaiaBreLimits* l){
 if(!l)return;
 l->max_pattern_bytes=1024;l->max_input_bytes=65535;l->max_instructions=4096;l->max_ranges=4096;
 l->max_captures=9;l->max_repeat=255;l->max_parse_depth=9;l->max_frames=4096;
 l->max_steps=1000000;l->max_workspace_bytes=1048576;
}
int bre_limits_valid(const MaiaBreLimits* l){
 if(!l||!l->max_pattern_bytes||!l->max_input_bytes||!l->max_instructions||!l->max_ranges||!l->max_captures||!l->max_repeat||!l->max_parse_depth||!l->max_frames||!l->max_steps||!l->max_workspace_bytes)return MAIA_BRE_ARGUMENT;
 if(l->max_pattern_bytes>1024||l->max_input_bytes>65535||l->max_instructions>4096||l->max_ranges>4096||l->max_captures>9||l->max_repeat>255||l->max_parse_depth>9||l->max_frames>4096)return MAIA_BRE_LIMIT;
 return MAIA_BRE_OK;
}
int bre_utf8_next(const unsigned char* s,unsigned int n,unsigned int* offset,unsigned int* value){
 unsigned int i=*offset,c,more,min,j;
 if(i>=n)return MAIA_BRE_ENCODING;
 c=s[i++];if(!c)return MAIA_BRE_ARGUMENT;
 if(c<128){*value=c;*offset=i;return MAIA_BRE_OK;}
 if(c>=194&&c<=223){c&=31;more=1;min=128;}
 else if(c>=224&&c<=239){c&=15;more=2;min=2048;}
 else if(c>=240&&c<=244){c&=7;more=3;min=65536;}
 else return MAIA_BRE_ENCODING;
 if(more>n-i)return MAIA_BRE_ENCODING;
 for(j=0;j<more;++j){unsigned int b=s[i++];if((b&192)!=128)return MAIA_BRE_ENCODING;c=(c<<6)|(b&63);}
 if(c<min||c>1114111||(c>=55296&&c<=57343))return MAIA_BRE_ENCODING;
 *offset=i;*value=c;return MAIA_BRE_OK;
}
int bre_text_check(const unsigned char* p,unsigned int n){unsigned int i=0,c;int r;if(!p)return MAIA_BRE_ARGUMENT;while(i<n){r=bre_utf8_next(p,n,&i,&c);if(r)return r;}return 0;}
int maia_bre_info(const MaiaBreProgram* p,MaiaBreInfo* out){MaiaBreInfo info;if(!p||p->magic!=BRE_MAGIC||!out)return MAIA_BRE_ARGUMENT;info.capture_count=p->groups;info.instruction_count=p->code_count;info.range_count=p->range_count;info.storage_bytes=p->storage_bytes;*out=info;return 0;}
void maia_bre_free(MaiaBreProgram* p){if(!p)return;free(p->code);free(p->ranges);p->magic=0;free(p);}
typedef struct BreLoop {unsigned int pc,count,start,zero,history_open;} BreLoop;
typedef struct BreState {unsigned int pc,pos,depth;int begin[10],end[10];BreLoop loops[10];unsigned int history,group_history[10];} BreState;
typedef struct BreHistory {unsigned int prev,refs,free_next,kind,key,pos,open;size_t order;} BreHistory;
typedef struct BrePriority {size_t order;unsigned int key,length;} BrePriority;
typedef struct BreRun {
 const MaiaBreLimits* limits;size_t steps,used;BreState* stack;unsigned int count,capacity;
 unsigned int* units;unsigned int* offsets;unsigned int length;int error;
 BreHistory* history;unsigned int history_count,history_capacity,history_free;size_t history_order;
 BrePriority* priorities;unsigned int priority_capacity;
} BreRun;
static int bre_tick(BreRun* r,size_t n){if(n>r->limits->max_steps-r->steps){r->error=MAIA_BRE_LIMIT;return 0;}r->steps+=n;return 1;}
#include "maia_bre_history.h"
static int bre_push(BreRun* r,const BreState* s){
 if(r->count>=r->limits->max_frames-1){r->error=MAIA_BRE_LIMIT;return 0;}
 if(r->count==r->capacity){
  unsigned int cap=r->capacity?r->capacity*2:4;size_t bytes,old;BreState* next;
  if(cap>r->limits->max_frames-1)cap=r->limits->max_frames-1;
  if(sizeof(BreState)>((size_t)-1)/(size_t)cap){r->error=MAIA_BRE_LIMIT;return 0;}
  bytes=(size_t)cap*sizeof(BreState);old=(size_t)r->capacity*sizeof(BreState);
  /* Account for both arrays during checked growth. */
  if(bytes>r->limits->max_workspace_bytes-r->used){r->error=MAIA_BRE_LIMIT;return 0;}
  next=(BreState*)malloc(bytes);if(!next){r->error=MAIA_BRE_NOMEM;return 0;}
  if(r->count)memcpy(next,r->stack,r->count*sizeof(BreState));free(r->stack);r->stack=next;r->capacity=cap;r->used=r->used-old+bytes;
 }
 r->stack[r->count++]=*s;return 1;
}
int maia_bre_exec_utf8(const MaiaBreProgram* p,const unsigned char* input,unsigned int bytes,unsigned int start_byte,unsigned int mode,const MaiaBreLimits* limits,MaiaBreCapture* output,unsigned int capacity){
 BreRun run;BreState current,best;unsigned int at=0,start=BRE_NONE,i,candidate,found=0;size_t entries,decoded;int status;
 MaiaBreCapture captures[10];
 status=bre_limits_valid(limits);if(status)return status;
 if(!p||p->magic!=BRE_MAGIC||!input||(capacity&&!output)||capacity>10||mode>MAIA_BRE_ANCHORED||start_byte>bytes)return MAIA_BRE_ARGUMENT;
 if(bytes>limits->max_input_bytes||p->code_count>limits->max_instructions||p->range_count>limits->max_ranges||p->groups>limits->max_captures||p->depth>limits->max_parse_depth||p->repeat_bound>limits->max_repeat)return MAIA_BRE_LIMIT;
 memset(&run,0,sizeof(run));run.history_free=BRE_NONE;current.history=BRE_NONE;best.history=BRE_NONE;run.limits=limits;run.used=sizeof(BreRun)+sizeof(BreState)*3+sizeof(captures);
 entries=(size_t)bytes+1;if(entries>((size_t)-1)/(sizeof(unsigned int)*2))return MAIA_BRE_LIMIT;
 decoded=entries*sizeof(unsigned int)*2;if(run.used>limits->max_workspace_bytes||decoded>limits->max_workspace_bytes-run.used)return MAIA_BRE_LIMIT;
 run.units=(unsigned int*)malloc(decoded);if(!run.units)return MAIA_BRE_NOMEM;run.offsets=run.units+entries;run.used+=decoded;
 while(at<bytes){unsigned int previous=at,scalar;status=bre_utf8_next(input,bytes,&at,&scalar);if(status){run.error=status;goto done;}if(!bre_tick(&run,at-previous))goto done;if(previous==start_byte)start=run.length;run.offsets[run.length]=previous;run.units[run.length++]=scalar;}
 run.offsets[run.length]=bytes;if(start_byte==bytes)start=run.length;
 if(start==BRE_NONE){run.error=MAIA_BRE_ARGUMENT;goto done;}
 for(candidate=start;candidate<=run.length;++candidate){
  memset(&current,0,sizeof(current));current.history=BRE_NONE;current.pc=p->entry;current.pos=candidate;
  for(i=0;i<10;++i){current.begin[i]=-1;current.end[i]=-1;}current.begin[0]=(int)candidate;
  run.count=0;
  for(;;){
   const BreInstruction* code;
   if(!bre_tick(&run,1))goto done;
   if(current.pc>=p->code_count){run.error=MAIA_BRE_ARGUMENT;goto done;}
   code=p->code+current.pc;
   if(code->op==BRE_ACCEPT){
    /* Whole length precedes hierarchical scope histories, never a final
       capture-vector comparison or first-success branch selection. */
    {int better=!found||current.pos>best.pos;
     if(found&&current.pos==best.pos){better=bre_history_better(&run,current.history,best.history);if(run.error)goto done;}
     if(better){bre_history_drop(&run,best.history);best=current;bre_history_retain(&run,best.history);best.end[0]=(int)current.pos;found=1;}
    }
    goto backtrack;
   }
   if(code->op==BRE_CHAR||code->op==BRE_ANY||code->op==BRE_CLASS||code->op==BRE_NOT_CLASS){
    int match=0;if(current.pos==run.length)goto backtrack;
    if(code->op==BRE_ANY)match=1;
    else if(code->op==BRE_CHAR)match=run.units[current.pos]==code->a;
    else{unsigned int j;for(j=0;j<code->b;++j){const BreRange* range=p->ranges+code->a+j;if(!bre_tick(&run,1))goto done;if(run.units[current.pos]>=range->first&&run.units[current.pos]<=range->last)match=1;}if(code->op==BRE_NOT_CLASS)match=!match;}
    if(!match)goto backtrack;++current.pos;current.pc=code->next;continue;
   }
   if(code->op==BRE_BEGIN){if(current.pos)goto backtrack;current.pc=code->next;continue;}
   if(code->op==BRE_END){if(current.pos!=run.length)goto backtrack;current.pc=code->next;continue;}
   if(code->op==BRE_OPEN){
    /* A new outer participation invalidates captures from its earlier iterations. */
    unsigned int group;if(!bre_history_tag(&run,&current,0,code->max,BRE_NONE))goto done;current.group_history[code->a]=current.history;
    for(group=code->a;group<=code->b;++group){current.begin[group]=-1;current.end[group]=-1;}
    current.begin[code->a]=(int)current.pos;current.pc=code->next;continue;
   }
   if(code->op==BRE_CLOSE){if(!bre_history_tag(&run,&current,1,0,current.group_history[code->a]))goto done;current.end[code->a]=(int)current.pos;current.pc=code->next;continue;}
   if(code->op==BRE_REF){
    unsigned int first,last,j;if(current.begin[code->a]<0||current.end[code->a]<0)goto backtrack;
    first=(unsigned int)current.begin[code->a];last=(unsigned int)current.end[code->a];
    if(last-first>run.length-current.pos)goto backtrack;
    for(j=first;j<last;++j){if(!bre_tick(&run,1))goto done;if(run.units[j]!=run.units[current.pos+j-first])goto backtrack;}
    current.pos+=last-first;current.pc=code->next;continue;
   }
   if(code->op==BRE_REPEAT){
    BreLoop* loop;int can_exit,can_enter;
    if(!current.depth||current.loops[current.depth-1].pc!=current.pc){if(current.depth==10){run.error=MAIA_BRE_LIMIT;goto done;}loop=&current.loops[current.depth++];loop->pc=current.pc;loop->count=0;loop->start=current.pos;loop->zero=0;
     if(!bre_history_tag(&run,&current,0,code->b,BRE_NONE))goto done;loop->history_open=current.history;}
    loop=&current.loops[current.depth-1];can_exit=loop->count>=code->min;can_enter=loop->count<code->max&&(!loop->zero||loop->count<code->min);
    if(can_exit&&can_enter){BreState exit_state=current;exit_state.pc=code->next;--exit_state.depth;bre_history_retain(&run,exit_state.history);if(!bre_history_tag(&run,&exit_state,1,0,loop->history_open)||!bre_push(&run,&exit_state)){bre_history_drop(&run,exit_state.history);goto done;}}
    if(can_enter){loop->start=current.pos;current.pc=code->a;continue;}
    if(can_exit){if(!bre_history_tag(&run,&current,1,0,loop->history_open))goto done;--current.depth;current.pc=code->next;continue;}
    goto backtrack;
   }
   if(code->op==BRE_REPEAT_END){
    BreLoop* loop;const BreInstruction* repeat;
    if(!current.depth||current.loops[current.depth-1].pc!=code->a){run.error=MAIA_BRE_ARGUMENT;goto done;}
    loop=&current.loops[current.depth-1];repeat=p->code+loop->pc;
    /* Optional empty iterations after participation do not overwrite captures.
       Required empty iterations, and a first empty participation, remain real. */
    if(current.pos==loop->start&&loop->count>0&&loop->count>=repeat->min)goto backtrack;
    if(loop->count==UINT_MAX){run.error=MAIA_BRE_LIMIT;goto done;}
    loop->zero=current.pos==loop->start;++loop->count;current.pc=loop->pc;continue;
   }
   run.error=MAIA_BRE_ARGUMENT;goto done;
backtrack:
   bre_history_drop(&run,current.history);current.history=BRE_NONE;if(!run.count)break;current=run.stack[--run.count];
  }
  if(found)break;if(mode==MAIA_BRE_ANCHORED)break;
 }
 if(found){
  memset(captures,0,sizeof(captures));for(i=0;i<=p->groups;++i)if(best.begin[i]>=0&&best.end[i]>=0){captures[i].matched=1;captures[i].start_scalar=(unsigned int)best.begin[i];captures[i].end_scalar=(unsigned int)best.end[i];captures[i].start_byte=run.offsets[captures[i].start_scalar];captures[i].end_byte=run.offsets[captures[i].end_scalar];}
  if(capacity)memcpy(output,captures,capacity*sizeof(MaiaBreCapture));
 }else run.error=MAIA_BRE_NOMATCH;
done:
 status=run.error;bre_history_drop(&run,current.history);bre_history_drop(&run,best.history);while(run.count)bre_history_drop(&run,run.stack[--run.count].history);free(run.history);free(run.priorities);free(run.stack);free(run.units);return status;
}
