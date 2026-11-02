/* Fault injection is confined to separately compiled test objects. */
#include "alloc.h"
#include "../../maia_bre.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
static struct Allocation {void* pointer;size_t size;} allocations[16384];
static size_t live,peak,calls,fail;
void* bre_test_malloc(size_t bytes){unsigned int i;void* p;++calls;if(fail&&calls==fail)return 0;p=malloc(bytes);if(!p)return 0;for(i=0;i<16384;++i)if(!allocations[i].pointer){allocations[i].pointer=p;allocations[i].size=bytes;live+=bytes;if(live>peak)peak=live;return p;}assert(0);return 0;}
void bre_test_free(void* p){unsigned int i;if(!p)return;for(i=0;i<16384;++i)if(allocations[i].pointer==p){live-=allocations[i].size;allocations[i].pointer=0;free(p);return;}assert(0);}
void* bre_test_calloc(size_t count,size_t bytes){void* p;if(bytes&&count>((size_t)-1)/bytes)return 0;p=bre_test_malloc(count*bytes);if(p)memset(p,0,count*bytes);return p;}
void* bre_test_realloc(void* old,size_t bytes){unsigned int i;size_t size=0;void* p;if(!old)return bre_test_malloc(bytes);for(i=0;i<16384;++i)if(allocations[i].pointer==old)size=allocations[i].size;p=bre_test_malloc(bytes);if(p){memcpy(p,old,size<bytes?size:bytes);bre_test_free(old);}return p;}
int main(int argc,char** argv){
 MaiaBreLimits limits;MaiaBreProgram* p=0;MaiaBreProgram* prior;MaiaBreCapture out[10],before[10];MaiaBreInfo info;
 size_t compile_calls,exec_calls,k,baseline,compile_peak;unsigned int status_errors=0;int r;char source[1025];
 const int measure=argc>1&&!strcmp(argv[1],"--measure");
 const char* pattern="\\(a*\\)*\\1";
 maia_bre_default_limits(&limits);r=maia_bre_compile_utf8((const unsigned char*)pattern,(unsigned int)strlen(pattern),&limits,&p);assert(r==0);compile_calls=calls;compile_peak=peak;maia_bre_info(p,&info);printf("Compile peak including generated frontend: %lu bytes, %lu allocations, retained %lu bytes\n",(unsigned long)compile_peak,(unsigned long)compile_calls,(unsigned long)info.storage_bytes);maia_bre_free(p);assert(!live);
 for(k=1;!measure&&k<=compile_calls;++k){calls=0;fail=k;p=0;prior=p;r=maia_bre_compile_utf8((const unsigned char*)pattern,(unsigned int)strlen(pattern),&limits,&p);if(r==0)maia_bre_free(p);else {if(r!=MAIA_BRE_NOMEM){++status_errors;fprintf(stderr,"compile allocation %lu/%lu returned %d instead of NOMEM\n",(unsigned long)k,(unsigned long)compile_calls,r);}assert(p==prior);}assert(!live);}
 fail=0;calls=0;assert(maia_bre_compile_utf8((const unsigned char*)pattern,(unsigned int)strlen(pattern),&limits,&p)==0);baseline=live;
 calls=0;peak=live;assert(maia_bre_exec_utf8(p,(const unsigned char*)"aaaaaaaaaaaa",12,0,0,&limits,out,10)==0);exec_calls=calls;printf("Exec peak excluding retained program: %lu bytes, %lu allocations\n",(unsigned long)(peak-baseline),(unsigned long)exec_calls);assert(live==baseline);
 memset(before,90,sizeof(before));
 for(k=1;!measure&&k<=exec_calls;++k){calls=0;fail=k;memcpy(out,before,sizeof(out));r=maia_bre_exec_utf8(p,(const unsigned char*)"aaaaaaaaaaaa",12,0,0,&limits,out,10);assert(r==MAIA_BRE_NOMEM);assert(!memcmp(out,before,sizeof(out)));assert(live==baseline);}
 fail=0;maia_bre_free(p);assert(!live);
 memset(source,'a',1024);source[1024]=0;calls=0;peak=0;p=0;r=maia_bre_compile_utf8((const unsigned char*)source,1024,&limits,&p);printf("1024-byte literal compile: status %d, peak %lu bytes, %lu allocations\n",r,(unsigned long)peak,(unsigned long)calls);if(!r)maia_bre_free(p);assert(!live);
 if(measure){puts("Measurement only: fault-injection gate was not run");return 0;}
 printf("Allocation failure sweep: %lu compile + %lu exec sites, no leaks or partial output; %u incorrect statuses\n",(unsigned long)compile_calls,(unsigned long)exec_calls,status_errors);return status_errors?1:0;
}
