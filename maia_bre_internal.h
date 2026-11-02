#ifndef MAIA_BRE_INTERNAL_H
#define MAIA_BRE_INTERNAL_H
#include "maia_bre.h"
#include <limits.h>
#define BRE_MAGIC 0x4D425231U
#define BRE_NONE UINT_MAX
#define BRE_ACCEPT 0
#define BRE_CHAR 1
#define BRE_ANY 2
#define BRE_CLASS 3
#define BRE_NOT_CLASS 4
#define BRE_BEGIN 5
#define BRE_END 6
#define BRE_OPEN 7
#define BRE_CLOSE 8
#define BRE_REF 9
#define BRE_REPEAT 10
#define BRE_REPEAT_END 11
typedef struct BreInstruction {unsigned int op,a,b,next,min,max;} BreInstruction;
typedef struct BreRange {unsigned int first,last;} BreRange;
struct MaiaBreProgram {
 unsigned int magic,entry,code_count,range_count,groups,depth,code_capacity,range_capacity,repeat_bound;
 BreInstruction* code;BreRange* ranges;size_t storage_bytes;
};
#ifdef __cplusplus
extern "C" {
#endif
int bre_limits_valid(const MaiaBreLimits*);
int bre_utf8_next(const unsigned char*,unsigned int,unsigned int*,unsigned int*);
int bre_text_check(const unsigned char*,unsigned int);
#ifdef __cplusplus
}
#endif
#endif
