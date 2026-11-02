/* Public API expectations independent of the generated compiler implementation. */
#include "../../maia_bre.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
static unsigned int checks;
#define CHECK(x) do{++checks;assert(x);}while(0)
static void pattern(const char* text,const char* input,unsigned int mode,unsigned int start,int result,const int* spans,unsigned int count){
 MaiaBreLimits limits;MaiaBreProgram* program=0;MaiaBreCapture captures[12],before[12];MaiaBreInfo info;unsigned int i;
 maia_bre_default_limits(&limits);CHECK(maia_bre_compile_utf8((const unsigned char*)text,(unsigned int)strlen(text),&limits,&program)==0);
 memset(captures,90,sizeof(captures));memcpy(before,captures,sizeof(before));
 CHECK(maia_bre_info(program,&info)==0);CHECK(info.capture_count==count-1);
 CHECK(maia_bre_exec_utf8(program,(const unsigned char*)input,(unsigned int)strlen(input),start,mode,&limits,captures,10)==result);
 if(!result){for(i=0;i<count;++i){CHECK(captures[i].matched==(spans[2*i]>=0?1U:0U));if(captures[i].matched){CHECK(captures[i].start_byte==(unsigned int)spans[2*i]);CHECK(captures[i].end_byte==(unsigned int)spans[2*i+1]);}}CHECK(!memcmp(captures+10,before+10,2*sizeof(MaiaBreCapture)));}
 else CHECK(!memcmp(captures,before,sizeof(captures)));
 maia_bre_free(program);
}
int main(void){
 MaiaBreLimits limits;MaiaBreProgram* p=0;MaiaBreProgram* saved;MaiaBreCapture out[10],prior[10];MaiaBreInfo info,original;
 unsigned int i,j;unsigned char text[1200];
 static const int empty[]={0,0};static const int a3[]={0,3};static const int none[]={-1,-1};
 static const int greedy[]={0,3,3,3};static const int repeated[]={0,3,0,3};static const int required[]={0,3,3,3};
 static const int nested[]={0,3,2,3,-1,-1};static const int backref[]={0,3,1,2};static const int reversed[]={0,4,0,2,2,2};
 static const int optional_empty[]={0,0,0,0};static const int nine[]={0,9,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9};
 pattern("","abc",0,0,0,empty,1);pattern("a*","aaa",0,0,0,a3,1);
 pattern("a*\\(a*\\)","aaa",0,0,0,greedy,2);
 pattern("\\(a*\\)*","aaa",0,0,0,repeated,2);pattern("\\(a*\\)\\{2\\}","aaa",0,0,0,required,2);
 pattern("\\(a\\(b\\)*\\)*","aba",0,0,0,nested,3);pattern("\\(a*\\)*\\1","aaa",0,0,0,backref,2);
 pattern("\\(a*\\)\\(a*\\)\\2\\1","aaaa",0,0,0,reversed,3);
 pattern("\\(a*\\)\\{0,2\\}","",0,0,0,optional_empty,2);
 pattern("\\(a\\)\\(b\\)\\(c\\)\\(d\\)\\(e\\)\\(f\\)\\(g\\)\\(h\\)\\(i\\)","abcdefghi",0,0,0,nine,10);
 pattern("^a","ba",0,0,1,none,1);pattern("a","ba",1,0,1,none,1);
 maia_bre_default_limits(&limits);CHECK(maia_bre_compile_utf8((const unsigned char*)".",1,&limits,&p)==0);saved=p;
 memset(out,90,sizeof(out));memcpy(prior,out,sizeof(out));memset(&info,90,sizeof(info));original=info;
 CHECK(maia_bre_info(0,&info)==6);CHECK(!memcmp(&info,&original,sizeof(info)));
 CHECK(maia_bre_exec_utf8(p,(const unsigned char*)"a",1,0,2,&limits,out,10)==6);
 CHECK(maia_bre_exec_utf8(p,(const unsigned char*)"a",1,2,0,&limits,out,10)==6);
 CHECK(maia_bre_exec_utf8(p,(const unsigned char*)"a",1,0,0,&limits,out,11)==6);
 CHECK(maia_bre_exec_utf8(p,(const unsigned char*)"a",1,0,0,&limits,0,1)==6);
 CHECK(!memcmp(out,prior,sizeof(out)));
 CHECK(maia_bre_exec_utf8(p,(const unsigned char*)"a",1,0,0,&limits,0,0)==0);
 CHECK(maia_bre_compile_utf8((const unsigned char*)"[",1,&limits,&p)==2);CHECK(p==saved);
 CHECK(maia_bre_compile_utf8((const unsigned char*)"\\1",2,&limits,&p)==2);CHECK(p==saved);
 CHECK(maia_bre_compile_utf8((const unsigned char*)"\\(\\1\\)",6,&limits,&p)==2);CHECK(p==saved);
 CHECK(maia_bre_compile_utf8((const unsigned char*)"\\+",2,&limits,&p)==7);CHECK(p==saved);
 CHECK(maia_bre_compile_utf8((const unsigned char*)"[[.ch.]]",8,&limits,&p)==7);CHECK(p==saved);
 CHECK(maia_bre_compile_utf8((const unsigned char*)"a\\{256\\}",8,&limits,&p)==4);CHECK(p==saved);
 text[0]='a';text[1]=0;CHECK(maia_bre_exec_utf8(p,text,2,0,0,&limits,out,10)==6);CHECK(!memcmp(out,prior,sizeof(out)));
 for(i=0;i<256;++i){text[0]=(unsigned char)i;if(i>=128){int r=maia_bre_exec_utf8(p,text,1,0,0,&limits,out,10);CHECK(r==3);CHECK(!memcmp(out,prior,sizeof(out)));}}
 {static const unsigned char invalid[][4]={{192,128,0,0},{224,128,128,0},{237,160,128,0},{244,144,128,128},{240,159,152,0}};static const unsigned int lengths[]={2,3,3,4,3};
 for(i=0;i<5;++i){CHECK(maia_bre_compile_utf8(invalid[i],lengths[i],&limits,&p)==3);CHECK(p==saved);CHECK(maia_bre_exec_utf8(p,invalid[i],lengths[i],0,0,&limits,out,10)==3);CHECK(!memcmp(out,prior,sizeof(out)));}}
 {const unsigned char utf8[]={97,195,167,195,163,111,32,240,159,152,132};
 CHECK(maia_bre_exec_utf8(p,utf8,11,1,1,&limits,out,10)==0);CHECK(out[0].start_byte==1&&out[0].end_byte==3&&out[0].start_scalar==1&&out[0].end_scalar==2);
 memcpy(out,prior,sizeof(out));CHECK(maia_bre_exec_utf8(p,utf8,11,2,1,&limits,out,10)==6);CHECK(!memcmp(out,prior,sizeof(out)));
 CHECK(maia_bre_exec_utf8(p,utf8,11,7,1,&limits,out,10)==0);CHECK(out[0].start_byte==7&&out[0].end_byte==11&&out[0].start_scalar==5&&out[0].end_scalar==6);}
 maia_bre_free(p);p=0;
 for(i=1;i<=10;++i){unsigned int n=0;for(j=0;j<i;++j){text[n++]='\\';text[n++]='(';}text[n++]='a';for(j=0;j<i;++j){text[n++]='\\';text[n++]=')';}
 CHECK(maia_bre_compile_utf8(text,n,&limits,&p)==(i<=9?0:4));if(i<=9){maia_bre_free(p);p=0;}else CHECK(!p);}
 limits.max_steps=1;CHECK(maia_bre_compile_utf8((const unsigned char*)"abc",3,&limits,&p)==4);CHECK(!p);
 maia_bre_default_limits(&limits);limits.max_workspace_bytes=1;CHECK(maia_bre_compile_utf8((const unsigned char*)"a",1,&limits,&p)==4);CHECK(!p);
 maia_bre_default_limits(&limits);CHECK(maia_bre_compile_utf8((const unsigned char*)"a*",2,&limits,&p)==0);
 limits.max_steps=5;memcpy(out,prior,sizeof(out));CHECK(maia_bre_exec_utf8(p,(const unsigned char*)"aaaa",4,0,0,&limits,out,10)==4);CHECK(!memcmp(out,prior,sizeof(out)));
 maia_bre_default_limits(&limits);limits.max_workspace_bytes=1;CHECK(maia_bre_exec_utf8(p,(const unsigned char*)"a",1,0,0,&limits,out,10)==4);CHECK(!memcmp(out,prior,sizeof(out)));
 maia_bre_free(p);maia_bre_free(0);printf("BRE public API: %u checks passed\n",checks);return 0;
}
