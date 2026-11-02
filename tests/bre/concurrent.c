#include "../../maia_bre.h"
#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
static MaiaBreProgram* shared;
static MaiaBreLimits limits;
static void* run(void* unused){unsigned int i;MaiaBreCapture captures[10];(void)unused;for(i=0;i<500;++i){assert(maia_bre_exec_utf8(shared,(const unsigned char*)"aaaa",4,0,0,&limits,captures,10)==0);assert(captures[0].start_byte==0&&captures[0].end_byte==4);assert(captures[1].start_byte==2&&captures[1].end_byte==3);}return 0;}
int main(void){pthread_t threads[4];unsigned int i;unsigned char source[]="\\(a*\\)*\\1";maia_bre_default_limits(&limits);assert(!maia_bre_compile_utf8(source,(unsigned int)strlen((char*)source),&limits,&shared));memset(source,'x',sizeof(source)-1);for(i=0;i<4;++i)assert(!pthread_create(threads+i,0,run,0));for(i=0;i<4;++i)assert(!pthread_join(threads[i],0));maia_bre_free(shared);puts("Shared immutable program: 4 threads / 2000 executions; mutated source independent");return 0;}
