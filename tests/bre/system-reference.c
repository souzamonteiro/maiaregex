/* Independent system BRE oracle, restricted to the shared ASCII/C profile.
 * Compile without -I. so <regex.h> resolves to the system library. */
#include <regex.h>
#include <stdio.h>
#include <string.h>
#include "../../maia_bre.h"
static unsigned long checks, differences;
static void check_pattern(const char* pattern) {
 regex_t reference; MaiaBreProgram* program=0; MaiaBreLimits limits;
 unsigned long previous_differences=differences;
 regmatch_t spans[10]; MaiaBreCapture captures[10];
 char subject[7]; unsigned int length,bits,i,j; int a,b;
 maia_bre_default_limits(&limits);
 a=regcomp(&reference,pattern,0);
 b=maia_bre_compile_utf8((const unsigned char*)pattern,(unsigned int)strlen(pattern),&limits,&program);
 if(a||b){printf("compile disagreement %s: libc=%d Maia=%d\n",pattern,a,b);++differences;if(!a)regfree(&reference);maia_bre_free(program);return;}
 for(length=0;length<=6;++length)for(bits=0;bits<(1U<<length);++bits){
  for(i=0;i<length;++i)subject[i]=(bits&(1U<<i))?'b':'a';subject[length]=0;
  a=regexec(&reference,subject,10,spans,0);
  b=maia_bre_exec_utf8(program,(const unsigned char*)subject,length,0,MAIA_BRE_SEARCH,&limits,captures,10);
  ++checks;
  if((a==0)!=(b==0)||(!a&&b)){if(differences++<20)printf("status %s / %s: libc=%d Maia=%d\n",pattern,subject,a,b);continue;}
  if(a)continue;
  for(j=0;j<10;++j){int first=captures[j].matched?(int)captures[j].start_byte:-1;int last=captures[j].matched?(int)captures[j].end_byte:-1;
   if(first!=spans[j].rm_so||last!=spans[j].rm_eo){if(differences++<20)printf("capture %s / %s #%u: libc=%ld,%ld Maia=%d,%d\n",pattern,subject,j,(long)spans[j].rm_so,(long)spans[j].rm_eo,first,last);break;}
  }
 }
 if(differences!=previous_differences)printf("pattern differences %s: %lu\n",pattern,differences-previous_differences);
 regfree(&reference);maia_bre_free(program);
}
int main(void){
 static const char* atoms[]={"\\(aba*\\)*","a","b",".","[ab]","[^b]","a*","b*",".*","a\\{0,2\\}","a\\{1,2\\}","\\(a*\\)","\\(a*\\)*","\\(a*\\)\\{2\\}","\\(ab*\\)*","\\(a\\(b*\\)\\)*","\\(\\(a*\\)b*\\)*"};
 static const char* fixed[]={"\\(aba*\\)*.*","\\(aba*\\)*\\(.*\\)","\\(a*\\)*\\1","\\(a*\\)\\1","\\(a*\\)*\\1b*","\\(a*\\)\\(a*\\)\\2\\1","\\(a\\(b\\)*\\)*","\\(\\(a*\\)*\\)*","\\(a*\\)\\{0,2\\}","\\(a*\\)\\{2,3\\}","\\(\\(a*\\)b*\\)*\\2","^a*$","a$b","a^b","[]a]","[-ab]","[ab-]","[[:alpha:]]*"};
 unsigned int i,j;char pattern[256];
 for(i=0;i<sizeof(fixed)/sizeof(fixed[0]);++i)check_pattern(fixed[i]);
 for(i=0;i<sizeof(atoms)/sizeof(atoms[0]);++i){check_pattern(atoms[i]);for(j=0;j<sizeof(atoms)/sizeof(atoms[0]);++j){strcpy(pattern,atoms[i]);strcat(pattern,atoms[j]);check_pattern(pattern);}}
 printf("Independent libc BRE: %lu cases, %lu differences\n",checks,differences);return differences?1:0;
}
