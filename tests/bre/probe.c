#include "../../maia_bre.h"
#include <string.h>
static unsigned char bre_probe_pattern_buffer[1025];
static unsigned char bre_probe_input_buffer[65536];
static MaiaBreLimits bre_probe_limits;
static MaiaBreProgram* bre_probe_program;
static MaiaBreCapture bre_probe_captures[10];
void bre_probe_init(void){maia_bre_free(bre_probe_program);bre_probe_program=0;maia_bre_default_limits(&bre_probe_limits);memset(bre_probe_captures,90,sizeof(bre_probe_captures));}
unsigned char* bre_probe_pattern(void){return bre_probe_pattern_buffer;}
unsigned char* bre_probe_input(void){return bre_probe_input_buffer;}
int bre_probe_compile(unsigned int n){MaiaBreProgram* next=bre_probe_program;int r=maia_bre_compile_utf8(bre_probe_pattern_buffer,n,&bre_probe_limits,&next);if(!r){maia_bre_free(bre_probe_program);bre_probe_program=next;}else if(next!=bre_probe_program)return -1;return r;}
int bre_probe_exec(unsigned int n,unsigned int start,unsigned int mode,unsigned int capacity){memset(bre_probe_captures,90,sizeof(bre_probe_captures));return maia_bre_exec_utf8(bre_probe_program,bre_probe_input_buffer,n,start,mode,&bre_probe_limits,bre_probe_captures,capacity);}
unsigned int bre_probe_capture(unsigned int slot,unsigned int field){const MaiaBreCapture* c=bre_probe_captures+slot;switch(field){case 0:return c->matched;case 1:return c->start_byte;case 2:return c->end_byte;case 3:return c->start_scalar;case 4:return c->end_scalar;default:return 0;}}
unsigned int bre_probe_info(unsigned int field){MaiaBreInfo info;if(maia_bre_info(bre_probe_program,&info))return 0;switch(field){case 0:return info.capture_count;case 1:return info.instruction_count;case 2:return info.range_count;default:return (unsigned int)info.storage_bytes;}}
void bre_probe_limit(unsigned int field,unsigned int value){switch(field){case 0:bre_probe_limits.max_pattern_bytes=value;break;case 1:bre_probe_limits.max_input_bytes=value;break;case 2:bre_probe_limits.max_instructions=value;break;case 3:bre_probe_limits.max_ranges=value;break;case 4:bre_probe_limits.max_captures=value;break;case 5:bre_probe_limits.max_repeat=value;break;case 6:bre_probe_limits.max_parse_depth=value;break;case 7:bre_probe_limits.max_frames=value;break;case 8:bre_probe_limits.max_steps=value;break;case 9:bre_probe_limits.max_workspace_bytes=value;break;default:break;}}
void bre_probe_free(void){maia_bre_free(bre_probe_program);bre_probe_program=0;}
#ifdef BRE_NATIVE
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char** argv){unsigned int i,j;int r;unsigned int plen,ilen;if(argc<3)return 2;plen=(unsigned int)strlen(argv[1]);ilen=(unsigned int)strlen(argv[2]);if(plen>1024||ilen>65535)return 3;bre_probe_init();memcpy(bre_probe_pattern(),argv[1],plen);memcpy(bre_probe_input(),argv[2],ilen);r=bre_probe_compile(plen);if(r){printf("%d\n",r);return 0;}r=bre_probe_exec(ilen,argc>4?(unsigned int)atoi(argv[4]):0,argc>3?(unsigned int)atoi(argv[3]):0,10);printf("%d %u\n",r,bre_probe_info(0));if(!r)for(i=0;i<10;++i){for(j=0;j<5;++j)printf("%s%u",j?",":"",bre_probe_capture(i,j));printf("\n");}bre_probe_free();return 0;}
#endif
