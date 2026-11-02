/* Private persistent scope histories; included only by the C89 executor.
 * Copyright 2026 Roberto Luiz Souza Monteiro. SPDX-License-Identifier: Apache-2.0 */
static void bre_history_retain(BreRun* r,unsigned int id){if(id!=BRE_NONE)++r->history[id].refs;}
static void bre_history_drop(BreRun* r,unsigned int id){
 while(id!=BRE_NONE){BreHistory* n=r->history+id;unsigned int previous;if(--n->refs)break;previous=n->prev;n->free_next=r->history_free;r->history_free=id;id=previous;}
}
static int bre_history_tag(BreRun* r,BreState* state,unsigned int kind,unsigned int key,unsigned int open){
 unsigned int id;BreHistory* node;
 if(!bre_tick(r,1))return 0;
 if(r->history_order==(size_t)-1){r->error=MAIA_BRE_LIMIT;return 0;}
 if(r->history_free!=BRE_NONE){id=r->history_free;r->history_free=r->history[id].free_next;}
 else{
  if(r->history_count==r->history_capacity){
   unsigned int cap=r->history_capacity?r->history_capacity*2:32;size_t bytes,old;BreHistory* next;
   /* The node ceiling also keeps every possible incoming reference count finite. */
   if(cap>UINT_MAX/4||sizeof(BreHistory)>((size_t)-1)/(size_t)cap){r->error=MAIA_BRE_LIMIT;return 0;}
   bytes=(size_t)cap*sizeof(BreHistory);old=(size_t)r->history_capacity*sizeof(BreHistory);
   if(bytes>r->limits->max_workspace_bytes-r->used){r->error=MAIA_BRE_LIMIT;return 0;}
   next=(BreHistory*)malloc(bytes);if(!next){r->error=MAIA_BRE_NOMEM;return 0;}
   if(r->history_count)memcpy(next,r->history,r->history_count*sizeof(BreHistory));free(r->history);r->history=next;r->history_capacity=cap;r->used=r->used-old+bytes;
  }
  id=r->history_count++;
 }
 node=r->history+id;node->prev=state->history;node->refs=1;node->kind=kind;node->key=key;node->pos=state->pos;node->open=open;node->order=++r->history_order;
 bre_history_retain(r,state->history);bre_history_drop(r,state->history);state->history=id;return 1;
}
static unsigned int bre_history_scopes(BreRun* r,unsigned int head){
 unsigned int count=0;while(head!=BRE_NONE){const BreHistory* n=r->history+head;if(!bre_tick(r,1))return 0;if(n->kind)++count;head=n->prev;}return count;
}
static int bre_priority_reserve(BreRun* r,unsigned int required){
 unsigned int cap;size_t bytes,old;BrePriority* next;if(required<=r->priority_capacity)return 1;
 cap=r->priority_capacity?r->priority_capacity:16;while(cap<required){if(cap>UINT_MAX/4){r->error=MAIA_BRE_LIMIT;return 0;}cap*=2;}
 if(sizeof(BrePriority)>((size_t)-1)/(size_t)cap/2){r->error=MAIA_BRE_LIMIT;return 0;}
 bytes=(size_t)cap*sizeof(BrePriority)*2;old=(size_t)r->priority_capacity*sizeof(BrePriority)*2;
 if(bytes>r->limits->max_workspace_bytes-r->used){r->error=MAIA_BRE_LIMIT;return 0;}
 next=(BrePriority*)malloc(bytes);if(!next){r->error=MAIA_BRE_NOMEM;return 0;}free(r->priorities);r->priorities=next;r->priority_capacity=cap;r->used=r->used-old+bytes;return 1;
}
static int bre_priority_fill(BreRun* r,unsigned int head,BrePriority* output){
 unsigned int count=0;while(head!=BRE_NONE){const BreHistory* n=r->history+head;if(!bre_tick(r,1))return 0;if(n->kind){const BreHistory* open=r->history+n->open;output[count].order=open->order;output[count].key=open->key;output[count++].length=n->pos-open->pos;}head=n->prev;}return 1;
}
/* Iterative heapsort restores opening/preorder order. Arena slots are reusable;
   monotonic opening serials, rather than allocation addresses, define chronology. */
static int bre_priority_sift(BreRun* r,BrePriority* records,unsigned int count,unsigned int root){
 while(root<count/2){unsigned int child=root*2+1;BrePriority temporary;if(!bre_tick(r,1))return 0;if(child+1<count&&records[child].order<records[child+1].order)++child;if(records[root].order>=records[child].order)break;temporary=records[root];records[root]=records[child];records[child]=temporary;root=child;}return 1;
}
static int bre_priority_sort(BreRun* r,BrePriority* records,unsigned int count){
 unsigned int i;for(i=count/2;i>0;){--i;if(!bre_priority_sift(r,records,count,i))return 0;}
 for(i=count;i>1;){BrePriority temporary=records[0];--i;records[0]=records[i];records[i]=temporary;if(!bre_priority_sift(r,records,i,0))return 0;}return 1;
}
static int bre_history_better(BreRun* r,unsigned int candidate,unsigned int best){
 unsigned int a=bre_history_scopes(r,candidate),b,i;BrePriority* left;BrePriority* right;if(r->error)return 0;b=bre_history_scopes(r,best);if(r->error)return 0;
 if(!a&&!b)return 0;if(!bre_priority_reserve(r,a>b?a:b))return 0;left=r->priorities;right=left+r->priority_capacity;
 if(!bre_priority_fill(r,candidate,left)||!bre_priority_fill(r,best,right)||!bre_priority_sort(r,left,a)||!bre_priority_sort(r,right,b))return 0;
 for(i=0;i<a&&i<b;++i){if(!bre_tick(r,1))return 0;if(left[i].key!=right[i].key)return left[i].key<right[i].key;if(left[i].length!=right[i].length)return left[i].length>right[i].length;}
 return a>b;
}
