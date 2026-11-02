/* Copyright 2026 Roberto Luiz Souza Monteiro. SPDX-License-Identifier: Apache-2.0 */
#ifndef MAIA_BRE_H
#define MAIA_BRE_H
#include <stddef.h>
#define MAIA_BRE_OK 0
#define MAIA_BRE_NOMATCH 1
#define MAIA_BRE_BADPAT 2
#define MAIA_BRE_ENCODING 3
#define MAIA_BRE_LIMIT 4
#define MAIA_BRE_NOMEM 5
#define MAIA_BRE_ARGUMENT 6
#define MAIA_BRE_UNSUPPORTED 7
#define MAIA_BRE_SEARCH 0
#define MAIA_BRE_ANCHORED 1
typedef struct MaiaBreProgram MaiaBreProgram;
typedef struct MaiaBreLimits {
 unsigned int max_pattern_bytes,max_input_bytes,max_instructions,max_ranges,max_captures;
 unsigned int max_repeat,max_parse_depth,max_frames;
 size_t max_steps,max_workspace_bytes;
} MaiaBreLimits;
typedef struct MaiaBreCapture {
 unsigned int matched,start_byte,end_byte,start_scalar,end_scalar;
} MaiaBreCapture;
typedef struct MaiaBreInfo {
 unsigned int capture_count,instruction_count,range_count;size_t storage_bytes;
} MaiaBreInfo;
#ifdef __cplusplus
extern "C" {
#endif
void maia_bre_default_limits(MaiaBreLimits* out);
int maia_bre_compile_utf8(const unsigned char*,unsigned int,const MaiaBreLimits*,MaiaBreProgram**);
int maia_bre_info(const MaiaBreProgram*,MaiaBreInfo*);
int maia_bre_exec_utf8(const MaiaBreProgram*,const unsigned char*,unsigned int,unsigned int,unsigned int,const MaiaBreLimits*,MaiaBreCapture*,unsigned int);
void maia_bre_free(MaiaBreProgram*);
#ifdef __cplusplus
}
#endif
#endif
