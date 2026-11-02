/* Test-only allocation transport: linked before instrumented library objects. */
#include <stdlib.h>
#include <string.h>
struct BreFaultAllocation {void* pointer;size_t size;};
static struct BreFaultAllocation bre_fault_allocations[16384];
static unsigned int bre_fault_calls,bre_fault_fail,bre_fault_error;
static size_t bre_fault_live,bre_fault_peak;
void* bre_fault_malloc(size_t size){unsigned int i;void* pointer;++bre_fault_calls;if(bre_fault_fail==bre_fault_calls)return 0;pointer=malloc(size);if(!pointer)return 0;for(i=0;i<16384;++i)if(!bre_fault_allocations[i].pointer){bre_fault_allocations[i].pointer=pointer;bre_fault_allocations[i].size=size;bre_fault_live+=size;if(bre_fault_live>bre_fault_peak)bre_fault_peak=bre_fault_live;return pointer;}bre_fault_error=1;free(pointer);return 0;}
void bre_fault_free(void* pointer){unsigned int i;if(!pointer)return;for(i=0;i<16384;++i)if(bre_fault_allocations[i].pointer==pointer){bre_fault_live-=bre_fault_allocations[i].size;bre_fault_allocations[i].pointer=0;free(pointer);return;}bre_fault_error=1;}
void* bre_fault_calloc(size_t count,size_t size){void* pointer;if(size&&count>((size_t)-1)/size)return 0;pointer=bre_fault_malloc(count*size);if(pointer)memset(pointer,0,count*size);return pointer;}
void* bre_fault_realloc(void* previous,size_t size){unsigned int i;size_t old=0;void* pointer;if(!previous)return bre_fault_malloc(size);for(i=0;i<16384;++i)if(bre_fault_allocations[i].pointer==previous)old=bre_fault_allocations[i].size;pointer=bre_fault_malloc(size);if(pointer){memcpy(pointer,previous,old<size?old:size);bre_fault_free(previous);}return pointer;}
void bre_fault_reset(unsigned int fail){bre_fault_calls=0;bre_fault_fail=fail;bre_fault_peak=bre_fault_live;bre_fault_error=0;}
unsigned int bre_fault_count(void){return bre_fault_calls;}
unsigned int bre_fault_bytes(void){return (unsigned int)bre_fault_live;}
unsigned int bre_fault_peak_bytes(void){return (unsigned int)bre_fault_peak;}
unsigned int bre_fault_invalid(void){return bre_fault_error;}
