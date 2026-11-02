/* Generated from C++98 source */
/* Target: C89 */

/* Minimal bridge prelude for MaiaC */
/* Runtime interface */
extern void*  __malloc(unsigned long size);
extern void   __free(void* ptr);

/* String and memory function declarations (MaiaC-compatible, no #include needed) */
extern unsigned int strlen(const char* s);
extern int strcmp(const char* s1, const char* s2);
extern int strncmp(const char* s1, const char* s2, unsigned int n);
extern char* strcpy(char* dest, const char* src);
extern char* strncpy(char* dest, const char* src, unsigned int n);
extern char* strcat(char* dest, const char* src);
extern char* strncat(char* dest, const char* src, unsigned int n);
extern char* strstr(const char* haystack, const char* needle);
extern char* strchr(const char* s, int c);
extern char* strrchr(const char* s, int c);
extern unsigned int strspn(const char* s, const char* accept);
extern unsigned int strcspn(const char* s, const char* reject);
extern char* strtok(char* str, const char* delim);
extern int memcmp(const void* s1, const void* s2, unsigned int n);
extern void* memcpy(void* dest, const void* src, unsigned int n);
extern void* memmove(void* dest, const void* src, unsigned int n);
extern void* memset(void* s, int c, unsigned int n);
extern void* memchr(const void* s, int c, unsigned int n);
extern void* calloc(unsigned int count, unsigned int size);
extern void* realloc(void* ptr, unsigned int size);
/* malloc/free → MaiaC __malloc/__free bridge */
#ifdef MAIACPP_USE_C_ALLOCATOR
extern void* malloc(unsigned int size);
extern void free(void* ptr);
#else
#define malloc(n) __malloc((unsigned long)(n))
#define free(p) __free((void*)(p))
#endif

typedef struct MaiaBreLimits MaiaBreLimits;
typedef struct MaiaBreCapture MaiaBreCapture;
typedef struct MaiaBreInfo MaiaBreInfo;
typedef struct BreInstruction BreInstruction;
typedef struct BreRange BreRange;
typedef struct MaiaBreProgram MaiaBreProgram;
typedef struct MaiaRegexInstruction MaiaRegexInstruction;
typedef struct MaiaRegexRange MaiaRegexRange;
typedef struct MaiaRegexProgram MaiaRegexProgram;
typedef struct MaiaRegexLimits MaiaRegexLimits;
typedef struct MaiaBreGenerated_MaiaCCParserToken MaiaBreGenerated_MaiaCCParserToken;
typedef struct MaiaBreGenerated_MaiaCCLexPattern MaiaBreGenerated_MaiaCCLexPattern;
typedef struct MaiaBreGenerated_MaiaCCLexerState MaiaBreGenerated_MaiaCCLexerState;
typedef struct MaiaBreGenerated_MaiaCCParseEvents MaiaBreGenerated_MaiaCCParseEvents;
typedef struct MaiaBreGenerated_MaiaCCParserState MaiaBreGenerated_MaiaCCParserState;
typedef struct BreNode BreNode;
typedef struct BreCompile BreCompile;

#define EXC_MaiaBreLimits 1
#define EXC_MaiaBreCapture 2
#define EXC_MaiaBreInfo 3
#define EXC_BreInstruction 4
#define EXC_BreRange 5
#define EXC_MaiaBreProgram 6
#define EXC_MaiaRegexInstruction 7
#define EXC_MaiaRegexRange 8
#define EXC_MaiaRegexProgram 9
#define EXC_MaiaRegexLimits 10
#define EXC_MaiaBreGenerated_MaiaCCParserToken 11
#define EXC_MaiaBreGenerated_MaiaCCLexPattern 12
#define EXC_MaiaBreGenerated_MaiaCCLexerState 13
#define EXC_MaiaBreGenerated_MaiaCCParseEvents 14
#define EXC_MaiaBreGenerated_MaiaCCParserState 15
#define EXC_BreNode 16
#define EXC_BreCompile 17

struct MaiaBreLimits {
  unsigned int max_pattern_bytes;
  unsigned int max_input_bytes;
  unsigned int max_instructions;
  unsigned int max_ranges;
  unsigned int max_captures;
  unsigned int max_repeat;
  unsigned int max_parse_depth;
  unsigned int max_frames;
  unsigned int max_steps;
  unsigned int max_workspace_bytes;
};

struct MaiaBreCapture {
  unsigned int matched;
  unsigned int start_byte;
  unsigned int end_byte;
  unsigned int start_scalar;
  unsigned int end_scalar;
};

struct MaiaBreInfo {
  unsigned int capture_count;
  unsigned int instruction_count;
  unsigned int range_count;
  unsigned int storage_bytes;
};

struct BreInstruction {
  unsigned int op;
  unsigned int a;
  unsigned int b;
  unsigned int next;
  unsigned int min;
  unsigned int max;
};

struct BreRange {
  unsigned int first;
  unsigned int last;
};

struct MaiaBreProgram {
  unsigned int magic;
  unsigned int entry;
  unsigned int code_count;
  unsigned int range_count;
  unsigned int groups;
  unsigned int depth;
  unsigned int code_capacity;
  unsigned int range_capacity;
  unsigned int repeat_bound;
  BreInstruction* code;
  BreRange* ranges;
  unsigned int storage_bytes;
};

struct MaiaRegexInstruction {
  int op;
  unsigned int first;
  unsigned int second;
  unsigned int next;
};

struct MaiaRegexRange {
  unsigned int first;
  unsigned int last;
};

struct MaiaRegexProgram {
  const MaiaRegexInstruction* code;
  const MaiaRegexRange* ranges;
  unsigned int instruction_count;
  unsigned int range_count;
  unsigned int entry;
};

struct MaiaRegexLimits {
  unsigned int max_memo_bytes;
  unsigned int max_frames;
  unsigned int max_steps;
};

struct MaiaBreGenerated_MaiaCCParserToken {
  unsigned int type;
  const char* value;
  unsigned int length;
  unsigned int start;
  unsigned int end;
};

struct MaiaBreGenerated_MaiaCCLexPattern {
  const MaiaRegexInstruction* code;
  const MaiaRegexRange* ranges;
  unsigned int count;
  unsigned int entry;
  unsigned int token;
  int skip;
  int generic;
  int preferred;
  int role;
  unsigned int rangeCount;
};

struct MaiaBreGenerated_MaiaCCLexerState {
  const char* input;
  unsigned int length;
  unsigned int position;
  unsigned int bytePosition;
  unsigned int tokenCount;
  int failed;
};

struct MaiaBreGenerated_MaiaCCParseEvents {
  void* context;
  unsigned int (*checkpoint)(void*);
  void (*restore)(void*, unsigned int);
  void (*startNonterminal)(void*, const char*, unsigned int);
  void (*terminal)(void*, unsigned int, const char*, unsigned int, unsigned int);
  void (*endNonterminal)(void*, const char*, unsigned int);
  void (*abortNonterminal)(void*, const char*, unsigned int);
  int (*matchesContextual)(void*, unsigned int, const MaiaBreGenerated_MaiaCCParserToken*);
};

struct MaiaBreGenerated_MaiaCCParserState {
  const MaiaBreGenerated_MaiaCCParserToken* tokens;
  unsigned int tokenCount;
  unsigned int position;
  const MaiaBreGenerated_MaiaCCParseEvents* events;
  int failed;
  int resourceError;
  unsigned int errorCount;
  unsigned int errorPosition;
  unsigned int expectedToken;
  unsigned int foundToken;
  unsigned char* failureMemo;
};

struct BreNode {
  const char* name;
  unsigned int token;
  unsigned int kind;
  unsigned int end;
  unsigned int entry;
  unsigned int tail;
  unsigned int group;
  int parent;
};

struct BreCompile {
  char source[1025];
  MaiaBreGenerated_MaiaCCParserToken tokens[1025];
  BreNode nodes[8192];
  unsigned int count;
  unsigned int overflow;
  unsigned int depth_overflow;
  int active;
  unsigned int groups[10];
  MaiaBreProgram* program;
  const MaiaBreLimits* limits;
  unsigned int steps;
};

extern void maia_bre_default_limits(MaiaBreLimits*);
extern int maia_bre_compile_utf8(const unsigned char*, unsigned int, const MaiaBreLimits*, MaiaBreProgram**);
extern int maia_bre_info(const MaiaBreProgram*, MaiaBreInfo*);
extern int maia_bre_exec_utf8(const MaiaBreProgram*, const unsigned char*, unsigned int, unsigned int, unsigned int, const MaiaBreLimits*, MaiaBreCapture*, unsigned int);
extern void maia_bre_free(MaiaBreProgram*);
extern int bre_limits_valid(const MaiaBreLimits*);
extern int bre_utf8_next(const unsigned char*, unsigned int, unsigned int*, unsigned int*);
extern int bre_text_check(const unsigned char*, unsigned int);
extern int maia_regex_validate(const MaiaRegexProgram*);
extern int maia_regex_exec(const MaiaRegexProgram*, const unsigned int*, unsigned int, unsigned int, const MaiaRegexLimits*, unsigned int*);

static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode0[] = { { 0 , 0 , 0 , 0 } , { 0 , 0 , 0 , 0 } , { 1 , 41 , 0 , 1 } , { 1 , 92 , 0 , 2 } , { 0 , 0 , 0 , 0 } , { 3 , 0 , 21 , 4 } , { 6 , 5 , 0 , 1 } , { 2 , 6 , 3 , 0 } , { 7 , 7 , 0 , 0 } , { 1 , 36 , 0 , 8 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges0[] = { { 9 , 13 } , { 32 , 32 } , { 160 , 160 } , { 5760 , 5760 } , { 8192 , 8202 } , { 8232 , 8233 } , { 8239 , 8239 } , { 8287 , 8287 } , { 12288 , 12288 } , { 65279 , 65279 } , { 0 , 8 } , { 14 , 31 } , { 33 , 159 } , { 161 , 5759 } , { 5761 , 8191 } , { 8203 , 8231 } , { 8234 , 8238 } , { 8240 , 8286 } , { 8288 , 12287 } , { 12289 , 65278 } , { 65280 , 65535 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode1[] = { { 0 , 0 , 0 , 0 } , { 0 , 0 , 0 , 0 } , { 3 , 0 , 3 , 1 } , { 7 , 2 , 0 , 0 } , { 1 , 91 , 0 , 3 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges1[] = { { 58 , 58 } , { 46 , 46 } , { 61 , 61 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode2[] = { { 0 , 0 , 0 , 0 } , { 1 , 92 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges2[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode3[] = { { 0 , 0 , 0 , 0 } , { 1 , 40 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges3[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode4[] = { { 0 , 0 , 0 , 0 } , { 1 , 41 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges4[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode5[] = { { 0 , 0 , 0 , 0 } , { 1 , 123 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges5[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode6[] = { { 0 , 0 , 0 , 0 } , { 1 , 125 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges6[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode7[] = { { 0 , 0 , 0 , 0 } , { 1 , 91 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges7[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode8[] = { { 0 , 0 , 0 , 0 } , { 1 , 93 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges8[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode9[] = { { 0 , 0 , 0 , 0 } , { 1 , 94 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges9[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode10[] = { { 0 , 0 , 0 , 0 } , { 1 , 36 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges10[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode11[] = { { 0 , 0 , 0 , 0 } , { 1 , 42 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges11[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode12[] = { { 0 , 0 , 0 , 0 } , { 1 , 46 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges12[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode13[] = { { 0 , 0 , 0 , 0 } , { 1 , 43 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges13[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode14[] = { { 0 , 0 , 0 , 0 } , { 1 , 63 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges14[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode15[] = { { 0 , 0 , 0 , 0 } , { 1 , 124 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges15[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode16[] = { { 0 , 0 , 0 , 0 } , { 1 , 45 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges16[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode17[] = { { 0 , 0 , 0 , 0 } , { 1 , 58 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges17[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode18[] = { { 0 , 0 , 0 , 0 } , { 1 , 61 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges18[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode19[] = { { 0 , 0 , 0 , 0 } , { 1 , 44 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges19[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode20[] = { { 0 , 0 , 0 , 0 } , { 3 , 0 , 1 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges20[] = { { 97 , 122 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode21[] = { { 0 , 0 , 0 , 0 } , { 3 , 0 , 1 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges21[] = { { 48 , 57 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode22[] = { { 0 , 0 , 0 , 0 } , { 4 , 0 , 21 , 0 } , { 3 , 21 , 1 , 0 } , { 3 , 22 , 1 , 2 } , { 2 , 3 , 1 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges22[] = { { 48 , 57 } , { 45 , 45 } , { 122 , 122 } , { 0 , 0 } , { 36 , 36 } , { 40 , 40 } , { 41 , 41 } , { 42 , 42 } , { 43 , 43 } , { 44 , 46 } , { 58 , 58 } , { 61 , 61 } , { 63 , 63 } , { 91 , 91 } , { 92 , 92 } , { 93 , 93 } , { 94 , 94 } , { 123 , 123 } , { 124 , 124 } , { 2010 , 2010 } , { 55296 , 57343 } , { 56320 , 57343 } , { 55296 , 56319 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode23[] = { { 0 , 0 , 0 , 0 } , { 0 , 0 , 0 , 0 } , { 1 , 41 , 0 , 1 } , { 1 , 92 , 0 , 2 } , { 0 , 0 , 0 , 0 } , { 3 , 0 , 21 , 4 } , { 6 , 5 , 0 , 1 } , { 2 , 6 , 3 , 0 } , { 7 , 7 , 0 , 0 } , { 1 , 36 , 0 , 8 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges23[] = { { 9 , 13 } , { 32 , 32 } , { 160 , 160 } , { 5760 , 5760 } , { 8192 , 8202 } , { 8232 , 8233 } , { 8239 , 8239 } , { 8287 , 8287 } , { 12288 , 12288 } , { 65279 , 65279 } , { 0 , 8 } , { 14 , 31 } , { 33 , 159 } , { 161 , 5759 } , { 5761 , 8191 } , { 8203 , 8231 } , { 8234 , 8238 } , { 8240 , 8286 } , { 8288 , 12287 } , { 12289 , 65278 } , { 65280 , 65535 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode24[] = { { 0 , 0 , 0 , 0 } , { 0 , 0 , 0 , 0 } , { 3 , 0 , 3 , 1 } , { 7 , 2 , 0 , 0 } , { 1 , 91 , 0 , 3 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges24[] = { { 58 , 58 } , { 46 , 46 } , { 61 , 61 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode25[] = { { 0 , 0 , 0 , 0 } , { 1 , 92 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges25[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode26[] = { { 0 , 0 , 0 , 0 } , { 1 , 40 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges26[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode27[] = { { 0 , 0 , 0 , 0 } , { 1 , 41 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges27[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode28[] = { { 0 , 0 , 0 , 0 } , { 1 , 123 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges28[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode29[] = { { 0 , 0 , 0 , 0 } , { 1 , 125 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges29[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode30[] = { { 0 , 0 , 0 , 0 } , { 1 , 91 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges30[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode31[] = { { 0 , 0 , 0 , 0 } , { 1 , 93 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges31[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode32[] = { { 0 , 0 , 0 , 0 } , { 1 , 94 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges32[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode33[] = { { 0 , 0 , 0 , 0 } , { 1 , 36 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges33[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode34[] = { { 0 , 0 , 0 , 0 } , { 1 , 42 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges34[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode35[] = { { 0 , 0 , 0 , 0 } , { 1 , 46 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges35[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode36[] = { { 0 , 0 , 0 , 0 } , { 1 , 43 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges36[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode37[] = { { 0 , 0 , 0 , 0 } , { 1 , 63 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges37[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode38[] = { { 0 , 0 , 0 , 0 } , { 1 , 124 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges38[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode39[] = { { 0 , 0 , 0 , 0 } , { 1 , 45 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges39[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode40[] = { { 0 , 0 , 0 , 0 } , { 1 , 58 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges40[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode41[] = { { 0 , 0 , 0 , 0 } , { 1 , 61 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges41[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode42[] = { { 0 , 0 , 0 , 0 } , { 1 , 44 , 0 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges42[] = { { 0 , 0 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode43[] = { { 0 , 0 , 0 , 0 } , { 3 , 0 , 1 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges43[] = { { 97 , 122 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode44[] = { { 0 , 0 , 0 , 0 } , { 3 , 0 , 1 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges44[] = { { 48 , 57 } };
static const MaiaRegexInstruction MaiaBreGenerated_maiaCCLexCode45[] = { { 0 , 0 , 0 , 0 } , { 4 , 0 , 21 , 0 } , { 3 , 21 , 1 , 0 } , { 3 , 22 , 1 , 2 } , { 2 , 3 , 1 , 0 } };
static const MaiaRegexRange MaiaBreGenerated_maiaCCLexRanges45[] = { { 48 , 57 } , { 45 , 45 } , { 122 , 122 } , { 0 , 0 } , { 36 , 36 } , { 40 , 40 } , { 41 , 41 } , { 42 , 42 } , { 43 , 43 } , { 44 , 46 } , { 58 , 58 } , { 61 , 61 } , { 63 , 63 } , { 91 , 91 } , { 92 , 92 } , { 93 , 93 } , { 94 , 94 } , { 123 , 123 } , { 124 , 124 } , { 2010 , 2010 } , { 55296 , 57343 } , { 56320 , 57343 } , { 55296 , 56319 } };
static const MaiaBreGenerated_MaiaCCLexPattern MaiaBreGenerated_maiaCCLexPatterns[] = { { MaiaBreGenerated_maiaCCLexCode0 , MaiaBreGenerated_maiaCCLexRanges0 , 10 , 9 , 2 , 0 , 0 , 0 , 0 , 21 } , { MaiaBreGenerated_maiaCCLexCode1 , MaiaBreGenerated_maiaCCLexRanges1 , 5 , 4 , 3 , 0 , 0 , 0 , 0 , 3 } , { MaiaBreGenerated_maiaCCLexCode2 , MaiaBreGenerated_maiaCCLexRanges2 , 2 , 1 , 4 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode3 , MaiaBreGenerated_maiaCCLexRanges3 , 2 , 1 , 5 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode4 , MaiaBreGenerated_maiaCCLexRanges4 , 2 , 1 , 6 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode5 , MaiaBreGenerated_maiaCCLexRanges5 , 2 , 1 , 7 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode6 , MaiaBreGenerated_maiaCCLexRanges6 , 2 , 1 , 8 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode7 , MaiaBreGenerated_maiaCCLexRanges7 , 2 , 1 , 9 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode8 , MaiaBreGenerated_maiaCCLexRanges8 , 2 , 1 , 10 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode9 , MaiaBreGenerated_maiaCCLexRanges9 , 2 , 1 , 11 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode10 , MaiaBreGenerated_maiaCCLexRanges10 , 2 , 1 , 12 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode11 , MaiaBreGenerated_maiaCCLexRanges11 , 2 , 1 , 13 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode12 , MaiaBreGenerated_maiaCCLexRanges12 , 2 , 1 , 14 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode13 , MaiaBreGenerated_maiaCCLexRanges13 , 2 , 1 , 15 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode14 , MaiaBreGenerated_maiaCCLexRanges14 , 2 , 1 , 16 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode15 , MaiaBreGenerated_maiaCCLexRanges15 , 2 , 1 , 17 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode16 , MaiaBreGenerated_maiaCCLexRanges16 , 2 , 1 , 18 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode17 , MaiaBreGenerated_maiaCCLexRanges17 , 2 , 1 , 19 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode18 , MaiaBreGenerated_maiaCCLexRanges18 , 2 , 1 , 20 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode19 , MaiaBreGenerated_maiaCCLexRanges19 , 2 , 1 , 21 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode20 , MaiaBreGenerated_maiaCCLexRanges20 , 2 , 1 , 22 , 0 , 0 , 0 , 0 , 1 } , { MaiaBreGenerated_maiaCCLexCode21 , MaiaBreGenerated_maiaCCLexRanges21 , 2 , 1 , 23 , 0 , 0 , 0 , 0 , 1 } , { MaiaBreGenerated_maiaCCLexCode22 , MaiaBreGenerated_maiaCCLexRanges22 , 5 , 4 , 24 , 0 , 0 , 0 , 0 , 23 } , { MaiaBreGenerated_maiaCCLexCode23 , MaiaBreGenerated_maiaCCLexRanges23 , 10 , 9 , 2 , 0 , 0 , 0 , 0 , 21 } , { MaiaBreGenerated_maiaCCLexCode24 , MaiaBreGenerated_maiaCCLexRanges24 , 5 , 4 , 3 , 0 , 0 , 0 , 0 , 3 } , { MaiaBreGenerated_maiaCCLexCode25 , MaiaBreGenerated_maiaCCLexRanges25 , 2 , 1 , 4 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode26 , MaiaBreGenerated_maiaCCLexRanges26 , 2 , 1 , 5 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode27 , MaiaBreGenerated_maiaCCLexRanges27 , 2 , 1 , 6 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode28 , MaiaBreGenerated_maiaCCLexRanges28 , 2 , 1 , 7 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode29 , MaiaBreGenerated_maiaCCLexRanges29 , 2 , 1 , 8 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode30 , MaiaBreGenerated_maiaCCLexRanges30 , 2 , 1 , 9 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode31 , MaiaBreGenerated_maiaCCLexRanges31 , 2 , 1 , 10 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode32 , MaiaBreGenerated_maiaCCLexRanges32 , 2 , 1 , 11 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode33 , MaiaBreGenerated_maiaCCLexRanges33 , 2 , 1 , 12 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode34 , MaiaBreGenerated_maiaCCLexRanges34 , 2 , 1 , 13 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode35 , MaiaBreGenerated_maiaCCLexRanges35 , 2 , 1 , 14 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode36 , MaiaBreGenerated_maiaCCLexRanges36 , 2 , 1 , 15 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode37 , MaiaBreGenerated_maiaCCLexRanges37 , 2 , 1 , 16 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode38 , MaiaBreGenerated_maiaCCLexRanges38 , 2 , 1 , 17 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode39 , MaiaBreGenerated_maiaCCLexRanges39 , 2 , 1 , 18 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode40 , MaiaBreGenerated_maiaCCLexRanges40 , 2 , 1 , 19 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode41 , MaiaBreGenerated_maiaCCLexRanges41 , 2 , 1 , 20 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode42 , MaiaBreGenerated_maiaCCLexRanges42 , 2 , 1 , 21 , 0 , 0 , 0 , 0 , 0 } , { MaiaBreGenerated_maiaCCLexCode43 , MaiaBreGenerated_maiaCCLexRanges43 , 2 , 1 , 22 , 0 , 0 , 0 , 0 , 1 } , { MaiaBreGenerated_maiaCCLexCode44 , MaiaBreGenerated_maiaCCLexRanges44 , 2 , 1 , 23 , 0 , 0 , 0 , 0 , 1 } , { MaiaBreGenerated_maiaCCLexCode45 , MaiaBreGenerated_maiaCCLexRanges45 , 5 , 4 , 24 , 0 , 0 , 0 , 0 , 23 } };
static const unsigned int MaiaBreGenerated_maiaCCLexPatternCount = 23;
static const unsigned int MaiaBreGenerated_maiaCCLexContextCount = 46;

void MaiaBreLimits_init(MaiaBreLimits* self);
void MaiaBreLimits_destroy(MaiaBreLimits* self);

void MaiaBreLimits_init(MaiaBreLimits* self) {
  (void)self;
}

void MaiaBreLimits_destroy(MaiaBreLimits* self) {
  (void)self;
}

void MaiaBreCapture_init(MaiaBreCapture* self);
void MaiaBreCapture_destroy(MaiaBreCapture* self);

void MaiaBreCapture_init(MaiaBreCapture* self) {
  (void)self;
}

void MaiaBreCapture_destroy(MaiaBreCapture* self) {
  (void)self;
}

void MaiaBreInfo_init(MaiaBreInfo* self);
void MaiaBreInfo_destroy(MaiaBreInfo* self);

void MaiaBreInfo_init(MaiaBreInfo* self) {
  (void)self;
}

void MaiaBreInfo_destroy(MaiaBreInfo* self) {
  (void)self;
}

void BreInstruction_init(BreInstruction* self);
void BreInstruction_destroy(BreInstruction* self);

void BreInstruction_init(BreInstruction* self) {
  (void)self;
}

void BreInstruction_destroy(BreInstruction* self) {
  (void)self;
}

void BreRange_init(BreRange* self);
void BreRange_destroy(BreRange* self);

void BreRange_init(BreRange* self) {
  (void)self;
}

void BreRange_destroy(BreRange* self) {
  (void)self;
}

void MaiaBreProgram_init(MaiaBreProgram* self);
void MaiaBreProgram_destroy(MaiaBreProgram* self);

void MaiaBreProgram_init(MaiaBreProgram* self) {
  (void)self;
}

void MaiaBreProgram_destroy(MaiaBreProgram* self) {
  (void)self;
}

void MaiaRegexInstruction_init(MaiaRegexInstruction* self);
void MaiaRegexInstruction_destroy(MaiaRegexInstruction* self);

void MaiaRegexInstruction_init(MaiaRegexInstruction* self) {
  (void)self;
}

void MaiaRegexInstruction_destroy(MaiaRegexInstruction* self) {
  (void)self;
}

void MaiaRegexRange_init(MaiaRegexRange* self);
void MaiaRegexRange_destroy(MaiaRegexRange* self);

void MaiaRegexRange_init(MaiaRegexRange* self) {
  (void)self;
}

void MaiaRegexRange_destroy(MaiaRegexRange* self) {
  (void)self;
}

void MaiaRegexProgram_init(MaiaRegexProgram* self);
void MaiaRegexProgram_destroy(MaiaRegexProgram* self);

void MaiaRegexProgram_init(MaiaRegexProgram* self) {
  (void)self;
}

void MaiaRegexProgram_destroy(MaiaRegexProgram* self) {
  (void)self;
}

void MaiaRegexLimits_init(MaiaRegexLimits* self);
void MaiaRegexLimits_destroy(MaiaRegexLimits* self);

void MaiaRegexLimits_init(MaiaRegexLimits* self) {
  (void)self;
}

void MaiaRegexLimits_destroy(MaiaRegexLimits* self) {
  (void)self;
}

void MaiaBreGenerated_MaiaCCParserToken_init(MaiaBreGenerated_MaiaCCParserToken* self);
void MaiaBreGenerated_MaiaCCParserToken_destroy(MaiaBreGenerated_MaiaCCParserToken* self);

void MaiaBreGenerated_MaiaCCParserToken_init(MaiaBreGenerated_MaiaCCParserToken* self) {
  (void)self;
}

void MaiaBreGenerated_MaiaCCParserToken_destroy(MaiaBreGenerated_MaiaCCParserToken* self) {
  (void)self;
}

void MaiaBreGenerated_MaiaCCLexPattern_init(MaiaBreGenerated_MaiaCCLexPattern* self);
void MaiaBreGenerated_MaiaCCLexPattern_destroy(MaiaBreGenerated_MaiaCCLexPattern* self);

void MaiaBreGenerated_MaiaCCLexPattern_init(MaiaBreGenerated_MaiaCCLexPattern* self) {
  (void)self;
}

void MaiaBreGenerated_MaiaCCLexPattern_destroy(MaiaBreGenerated_MaiaCCLexPattern* self) {
  (void)self;
}

void MaiaBreGenerated_MaiaCCLexerState_init(MaiaBreGenerated_MaiaCCLexerState* self);
void MaiaBreGenerated_MaiaCCLexerState_destroy(MaiaBreGenerated_MaiaCCLexerState* self);

void MaiaBreGenerated_MaiaCCLexerState_init(MaiaBreGenerated_MaiaCCLexerState* self) {
  (void)self;
}

void MaiaBreGenerated_MaiaCCLexerState_destroy(MaiaBreGenerated_MaiaCCLexerState* self) {
  (void)self;
}

void MaiaBreGenerated_MaiaCCParseEvents_init(MaiaBreGenerated_MaiaCCParseEvents* self);
void MaiaBreGenerated_MaiaCCParseEvents_destroy(MaiaBreGenerated_MaiaCCParseEvents* self);

void MaiaBreGenerated_MaiaCCParseEvents_init(MaiaBreGenerated_MaiaCCParseEvents* self) {
  (void)self;
}

void MaiaBreGenerated_MaiaCCParseEvents_destroy(MaiaBreGenerated_MaiaCCParseEvents* self) {
  (void)self;
}

void MaiaBreGenerated_MaiaCCParserState_init(MaiaBreGenerated_MaiaCCParserState* self);
void MaiaBreGenerated_MaiaCCParserState_destroy(MaiaBreGenerated_MaiaCCParserState* self);

void MaiaBreGenerated_MaiaCCParserState_init(MaiaBreGenerated_MaiaCCParserState* self) {
  (void)self;
}

void MaiaBreGenerated_MaiaCCParserState_destroy(MaiaBreGenerated_MaiaCCParserState* self) {
  (void)self;
}

void BreNode_init(BreNode* self);
void BreNode_destroy(BreNode* self);

void BreNode_init(BreNode* self) {
  (void)self;
}

void BreNode_destroy(BreNode* self) {
  (void)self;
}

void BreCompile_init(BreCompile* self);
void BreCompile_destroy(BreCompile* self);

void BreCompile_init(BreCompile* self) {
  (void)self;
}

void BreCompile_destroy(BreCompile* self) {
  (void)self;
}

/* Global functions */
const char* MaiaBreGenerated_maiaCCParserTokenName__N12unsigned_int(unsigned int type);
void MaiaBreGenerated_maiaCCLexerStateInit__pvpvN12unsigned_int(MaiaBreGenerated_MaiaCCLexerState* self, const char* input, unsigned int length);
int MaiaBreGenerated_maiaCCLexWhitespace__N12unsigned_int(unsigned int value);
int MaiaBreGenerated_maiaCCLexDecode__pvN12unsigned_intpvpvpv(const char* input, unsigned int length, unsigned int* units, unsigned int* offsets, unsigned int* count);
int MaiaBreGenerated_maiaCCLexMatch__pvpvN12unsigned_intN12unsigned_int(const MaiaBreGenerated_MaiaCCLexPattern* pattern, const unsigned int* units, unsigned int length, unsigned int position);
int MaiaBreGenerated_maiaCCLexerTokenize__pvpvN12unsigned_int(MaiaBreGenerated_MaiaCCLexerState* self, MaiaBreGenerated_MaiaCCParserToken* tokens, unsigned int capacity);
int MaiaBreGenerated_maiaCCLexMatchesContextual__N12unsigned_intpv(unsigned int expected, const MaiaBreGenerated_MaiaCCParserToken* token);
void MaiaBreGenerated_maiaCCParserStateInit__pvpvN12unsigned_intpv(MaiaBreGenerated_MaiaCCParserState* self, const MaiaBreGenerated_MaiaCCParserToken* tokens, unsigned int tokenCount, const MaiaBreGenerated_MaiaCCParseEvents* events);
const MaiaBreGenerated_MaiaCCParserToken* MaiaBreGenerated_maiaCC_peek__pv(const MaiaBreGenerated_MaiaCCParserState* self);
void MaiaBreGenerated_maiaCC_recordError__pvN12unsigned_int(MaiaBreGenerated_MaiaCCParserState* self, unsigned int expected);
unsigned int MaiaBreGenerated_maiaCC_checkpointEvents__pv(const MaiaBreGenerated_MaiaCCParserState* self);
void MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(const MaiaBreGenerated_MaiaCCParserState* self, unsigned int mark);
void MaiaBreGenerated_maiaCC_startNonterminal__pvpv(const MaiaBreGenerated_MaiaCCParserState* self, const char* name);
void MaiaBreGenerated_maiaCC_endNonterminal__pvpv(const MaiaBreGenerated_MaiaCCParserState* self, const char* name);
void MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(const MaiaBreGenerated_MaiaCCParserState* self, const char* name);
void MaiaBreGenerated_maiaCC_emitTerminal__pvpv(const MaiaBreGenerated_MaiaCCParserState* self, const MaiaBreGenerated_MaiaCCParserToken* token);
int MaiaBreGenerated_maiaCC_matchToken__pvN12unsigned_int(MaiaBreGenerated_MaiaCCParserState* self, unsigned int expected);
int MaiaBreGenerated_maiaCC_matchContextualToken__pvN12unsigned_int(MaiaBreGenerated_MaiaCCParserState* self, unsigned int expected);
int MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(MaiaBreGenerated_MaiaCCParserState* self, unsigned int expected);
int MaiaBreGenerated_maiaCC_expectContextualToken__pvN12unsigned_int(MaiaBreGenerated_MaiaCCParserState* self, unsigned int expected);
int MaiaBreGenerated_maiaCC_parse__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Input__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Sequence0__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Piece0__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Atom0__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Group0__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Sequence1__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Piece1__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Atom1__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Group1__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Sequence2__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Piece2__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Atom2__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Group2__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Sequence3__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Piece3__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Atom3__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Group3__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Sequence4__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Piece4__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Atom4__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Group4__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Sequence5__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Piece5__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Atom5__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Group5__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Sequence6__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Piece6__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Atom6__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Group6__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Sequence7__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Piece7__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Atom7__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Group7__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Sequence8__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Piece8__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Atom8__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Group8__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Sequence9__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Piece9__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Atom9__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_DepthOverflow__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_BeginAnchor__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_EndAnchor__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_InitialStarPiece__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_InitialStar__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_GroupOpen__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_GroupClose__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Any__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Reference__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Escape__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_UnsupportedEscape__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Literal__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Quantifier__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_StarRepeat__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_ExactRepeat__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_OpenRepeat__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_BoundedRepeat__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Number__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Class__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_ClassOpen__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Negation__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_InitialCloseRange__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_InitialClose__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_ClassElement__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_NamedClass__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_ClassName__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Collating__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Equivalence__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_CollatingScalar__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_EquivalenceScalar__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_Range__pv(MaiaBreGenerated_MaiaCCParserState* self);
int MaiaBreGenerated_maiaCC_parse_ClassScalar__pv(MaiaBreGenerated_MaiaCCParserState* self);
unsigned int bre_checkpoint__pv(void* context);
void bre_restore__pvN12unsigned_int(void* context, unsigned int mark);
void bre_append__pvN12unsigned_intpvN12unsigned_int(BreCompile* s, unsigned int kind, const char* name, unsigned int token);
void bre_start__pvpvN12unsigned_int(void* context, const char* name, unsigned int p3);
void bre_terminal__pvN12unsigned_intpvN12unsigned_intN12unsigned_int(void* context, unsigned int p2, const char* p3, unsigned int p4, unsigned int position);
void bre_end__pvpvN12unsigned_int(void* context, const char* name, unsigned int p3);
void bre_abort__pvpvN12unsigned_int(void* p1, const char* p2, unsigned int p3);
int bre_named__pvpv(const BreNode* n, const char* name);
int bre_numbered__pvpvN12unsigned_int(const BreNode* n, const char* prefix, unsigned int length);
int bre_work__pv(BreCompile* s);
unsigned int bre_emit__pvN12unsigned_intN12unsigned_intN12unsigned_int(BreCompile* s, unsigned int op, unsigned int a, unsigned int b);
int bre_scalar__pvN12unsigned_intN12unsigned_intpv(BreCompile* s, unsigned int node, unsigned int terminal_index, unsigned int* value);
int bre_add_range__pvN12unsigned_intN12unsigned_int(BreCompile* s, unsigned int a, unsigned int b);
int bre_named_class__pvN12unsigned_int(BreCompile* s, unsigned int node);
int bre_class__pvN12unsigned_intpv(BreCompile* s, unsigned int node, unsigned int* instruction);
int bre_quantity__pvN12unsigned_intpvpv(BreCompile* s, unsigned int node, unsigned int* minimum, unsigned int* maximum);
int bre_lower__pv(BreCompile* s);
int maia_bre_compile_utf8(const unsigned char* pattern, unsigned int length, const MaiaBreLimits* limits, MaiaBreProgram** output);

const char* MaiaBreGenerated_maiaCCParserTokenName__N12unsigned_int(unsigned int type) {
  {
  switch(type)
  {
  case 1:return"EOF";
  case 2:return"END_DOLLAR";
  case 3:return"OPEN_SPECIAL";
  case 4:return"BACKSLASH";
  case 5:return"LPAREN";
  case 6:return"RPAREN";
  case 7:return"LBRACE";
  case 8:return"RBRACE";
  case 9:return"OPEN";
  case 10:return"CLOSE";
  case 11:return"CARET";
  case 12:return"DOLLAR";
  case 13:return"STAR";
  case 14:return"DOT";
  case 15:return"PLUS";
  case 16:return"QUESTION";
  case 17:return"PIPE";
  case 18:return"DASH";
  case 19:return"COLON";
  case 20:return"EQUAL";
  case 21:return"COMMA";
  case 22:return"LETTER";
  case 23:return"DIGIT";
  case 24:return"CHAR";
  default:return"UNKNOWN";
  }
  }
  return (const char*)0;
}

void MaiaBreGenerated_maiaCCLexerStateInit__pvpvN12unsigned_int(MaiaBreGenerated_MaiaCCLexerState* self, const char* input, unsigned int length) {
  self -> input = input;
  self -> length = length;
  self -> position = 0;
  self -> bytePosition = 0;
  self -> tokenCount = 0;
  self -> failed = 0;
}

int MaiaBreGenerated_maiaCCLexWhitespace__N12unsigned_int(unsigned int value) {
  return ( value >= 9 && value <= 13 ) || value == 32 || value == 160 || value == 5760 || ( value >= 8192 && value <= 8202 ) || value == 8232 || value == 8233 || value == 8239 || value == 8287 || value == 12288 || value == 65279;
}

int MaiaBreGenerated_maiaCCLexDecode__pvN12unsigned_intpvpvpv(const char* input, unsigned int length, unsigned int* units, unsigned int* offsets, unsigned int* count) {
  unsigned int position;
  position = 0;
  * count = 0;
  while (position < length) {
    {
      unsigned int start;
      unsigned int first;
      unsigned int value;
      unsigned int extra;
      unsigned int minimum;
      start = position;
      first = (unsigned char)(input [ position ++ ]);
      value = first;
      extra = 0;
      minimum = 0;
      if (first >= 194 && first <= 223) {
        {
          value = first & 31;
          extra = 1;
          minimum = 128;
        }
      } else {
        if (first >= 224 && first <= 239) {
          {
            value = first & 15;
            extra = 2;
            minimum = 2048;
          }
        } else {
          if (first >= 240 && first <= 244) {
            {
              value = first & 7;
              extra = 3;
              minimum = 65536;
            }
          } else {
            if (first >= 128) {
              return 0;
            }
          }
        }
      }
      if (extra > length - position) {
        return 0;
      }
      while (extra > 0) {
        {
          unsigned int byte;
          byte = (unsigned char)(input [ position ++ ]);
          if (byte < 128 || byte > 191) {
            return 0;
          }
          value = ( value << 6 ) | ( byte & 63 );
          -- extra;
        }
      }
      if (value < minimum || value > 1114111 || ( value >= 55296 && value <= 57343 )) {
        return 0;
      }
      offsets [ * count ] = start;
      if (value > 65535) {
        {
          value -= 65536;
          units [ ( * count ) ++ ] = 55296 + ( value >> 10 );
          offsets [ * count ] = start;
          units [ ( * count ) ++ ] = 56320 + ( value & 1023 );
        }
      } else {
        units [ ( * count ) ++ ] = value;
      }
    }
  }
  offsets [ * count ] = length;
  return 1;
}

int MaiaBreGenerated_maiaCCLexMatch__pvpvN12unsigned_intN12unsigned_int(const MaiaBreGenerated_MaiaCCLexPattern* pattern, const unsigned int* units, unsigned int length, unsigned int position) {
  MaiaRegexProgram program;
  unsigned int end;
  int result;
  program.code = pattern -> code;
  program.ranges = pattern -> ranges;
  program.instruction_count = pattern -> count;
  program.range_count = pattern -> rangeCount;
  program.entry = pattern -> entry;
  end = 0;
  result = maia_regex_exec(& program, units, length, position, 0, & end);
  if (result == 0) {
    return (int)(end);
  }
  return result == 1 ? - 1 : - 2;
}

int MaiaBreGenerated_maiaCCLexerTokenize__pvpvN12unsigned_int(MaiaBreGenerated_MaiaCCLexerState* self, MaiaBreGenerated_MaiaCCParserToken* tokens, unsigned int capacity) {
  unsigned int entries;
  unsigned int* storage;
  unsigned int* units;
  unsigned int* offsets;
  unsigned int* braces;
  unsigned int length;
  unsigned int classDepth;
  unsigned int templateDepth;
  int middle;
  int tail;
  self -> tokenCount = 0;
  self -> position = 0;
  self -> bytePosition = 0;
  self -> failed = 0;
  if (! self -> input || ! tokens || ! capacity || self -> length > 2147483646U) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  entries = (unsigned int)(self -> length) + 1;
  if (entries > ( (unsigned int)(- 1) ) / ( 3 * sizeof ( unsigned int ) )) {
    {
      self -> failed = 2;
      return 0;
    }
  }
  storage = (unsigned int*)(malloc(entries * 3 * sizeof ( unsigned int )));
  if (! storage) {
    {
      self -> failed = 2;
      return 0;
    }
  }
  units = storage;
  offsets = storage + entries;
  braces = storage + 2 * entries;
  length = 0;
  classDepth = 0;
  templateDepth = 0;
  if (! MaiaBreGenerated_maiaCCLexDecode__pvN12unsigned_intpvpvpv(self -> input, self -> length, units, offsets, & length)) {
    self -> failed = 1;
  }
  middle = - 1;
  tail = - 1;
  {
    unsigned int index;
    index = 0;
    for (; index < MaiaBreGenerated_maiaCCLexPatternCount; ++ index) {
      {
        if (MaiaBreGenerated_maiaCCLexPatterns [ index ] . role == 1) {
          middle = (int)(index);
        }
        if (MaiaBreGenerated_maiaCCLexPatterns [ index ] . role == 2) {
          tail = (int)(index);
        }
      }
    }
  }
  while (! self -> failed && self -> position < length) {
    {
      int best;
      int bestEnd;
      int preferred;
      int preferredEnd;
      int whitespace;
      int whitespaceEnd;
      const MaiaBreGenerated_MaiaCCLexPattern* pattern;
      best = - 1;
      bestEnd = - 1;
      preferred = - 1;
      preferredEnd = - 1;
      whitespace = - 1;
      whitespaceEnd = - 1;
      {
        unsigned int index;
        index = 0;
        for (; index < MaiaBreGenerated_maiaCCLexPatternCount; ++ index) {
          {
            int candidate;
            const MaiaBreGenerated_MaiaCCLexPattern* pattern;
            int end;
            candidate = (int)(index);
            pattern = MaiaBreGenerated_maiaCCLexPatterns + candidate;
            if (pattern -> role == 1 || pattern -> role == 2) {
              continue;
            }
            end = MaiaBreGenerated_maiaCCLexMatch__pvpvN12unsigned_intN12unsigned_int(pattern, units, length, self -> position);
            if (end == - 2) {
              {
                self -> failed = 2;
                break;
              }
            }
            if (end <= (int)(self -> position)) {
              continue;
            }
            if (templateDepth && pattern -> role == 5 && braces [ templateDepth - 1 ] == 0) {
              {
                unsigned int limit;
                limit = self -> position + 256;
                if (limit > length) {
                  limit = length;
                }
                {
                  unsigned int scan;
                  scan = self -> position + 1;
                  for (; scan < limit; ++ scan) {
                    {
                      int span;
                      if (units [ scan ] == 92) {
                        {
                          ++ scan;
                          continue;
                        }
                      }
                      span = - 1;
                      if (units [ scan ] == 36 && scan + 1 < length && units [ scan + 1 ] == 123) {
                        span = middle;
                      } else {
                        if (units [ scan ] == 96) {
                          span = tail;
                        } else {
                          continue;
                        }
                      }
                      if (span >= 0) {
                        {
                          int spanEnd;
                          spanEnd = MaiaBreGenerated_maiaCCLexMatch__pvpvN12unsigned_intN12unsigned_int(MaiaBreGenerated_maiaCCLexPatterns + span, units, length, self -> position);
                          if (spanEnd == - 2) {
                            self -> failed = 2;
                          }
                          if (spanEnd > (int)(self -> position)) {
                            {
                              candidate = span;
                              end = spanEnd;
                              pattern = MaiaBreGenerated_maiaCCLexPatterns + span;
                            }
                          }
                        }
                      }
                      break;
                    }
                  }
                }
              }
            }
            if (best < 0 || end > bestEnd || ( end == bestEnd && pattern -> skip && ! MaiaBreGenerated_maiaCCLexPatterns [ best ] . skip ) || ( end == bestEnd && MaiaBreGenerated_maiaCCLexPatterns [ best ] . generic && ! pattern -> generic )) {
              {
                best = candidate;
                bestEnd = end;
              }
            }
            if (classDepth && pattern -> preferred && end > preferredEnd) {
              {
                preferred = candidate;
                preferredEnd = end;
              }
            }
            if (pattern -> skip && end > whitespaceEnd) {
              {
                whitespace = candidate;
                whitespaceEnd = end;
              }
            }
          }
        }
      }
      if (preferred >= 0) {
        {
          best = preferred;
          bestEnd = preferredEnd;
        }
      }
      if (whitespace >= 0 && MaiaBreGenerated_maiaCCLexWhitespace__N12unsigned_int(units [ self -> position ])) {
        {
          best = whitespace;
          bestEnd = whitespaceEnd;
        }
      }
      if (self -> failed) {
        break;
      }
      if (best < 0) {
        {
          self -> failed = 1;
          break;
        }
      }
      pattern = MaiaBreGenerated_maiaCCLexPatterns + best;
      if (! pattern -> skip) {
        {
          MaiaBreGenerated_MaiaCCParserToken* token;
          if (self -> tokenCount + 1 >= capacity) {
            {
              self -> failed = 3;
              break;
            }
          }
          token = tokens + self -> tokenCount ++;
          token -> type = pattern -> token;
          token -> value = self -> input + offsets [ self -> position ];
          token -> length = offsets [ bestEnd ] - offsets [ self -> position ];
          token -> start = self -> position;
          token -> end = (unsigned int)(bestEnd);
          if (pattern -> role == 6) {
            ++ classDepth;
          } else {
            if (pattern -> role == 7 && classDepth) {
              -- classDepth;
            } else {
              if (pattern -> role == 4 && templateDepth) {
                ++ braces [ templateDepth - 1 ];
              } else {
                if (pattern -> role == 5 && templateDepth && braces [ templateDepth - 1 ]) {
                  -- braces [ templateDepth - 1 ];
                } else {
                  if (pattern -> role == 3) {
                    braces [ templateDepth ++ ] = 0;
                  } else {
                    if (pattern -> role == 2 && templateDepth) {
                      -- templateDepth;
                    }
                  }
                }
              }
            }
          }
        }
      }
      self -> position = (unsigned int)(bestEnd);
      self -> bytePosition = offsets [ self -> position ];
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_MaiaCCParserToken* token;
      token = tokens + self -> tokenCount ++;
      token -> type = 1;
      token -> value = self -> input + self -> length;
      token -> length = 0;
      token -> start = length;
      token -> end = length;
    }
  }
  free(storage);
  return ! self -> failed;
}

int MaiaBreGenerated_maiaCCLexMatchesContextual__N12unsigned_intpv(unsigned int expected, const MaiaBreGenerated_MaiaCCParserToken* token) {
  unsigned int entries;
  unsigned int* units;
  unsigned int length;
  int accepted;
  entries = (unsigned int)(token -> length) + 1;
  if (entries > ( (unsigned int)(- 1) ) / ( 2 * sizeof ( unsigned int ) )) {
    return 0;
  }
  units = (unsigned int*)(malloc(entries * 2 * sizeof ( unsigned int )));
  if (! units) {
    return 0;
  }
  length = 0;
  accepted = 0;
  if (MaiaBreGenerated_maiaCCLexDecode__pvN12unsigned_intpvpvpv(token -> value, token -> length, units, units + entries, & length)) {
    {
      {
        unsigned int index;
        index = MaiaBreGenerated_maiaCCLexPatternCount;
        for (; index < MaiaBreGenerated_maiaCCLexContextCount; ++ index) {
          {
            if (MaiaBreGenerated_maiaCCLexPatterns [ index ] . token == expected) {
              {
                accepted = MaiaBreGenerated_maiaCCLexMatch__pvpvN12unsigned_intN12unsigned_int(MaiaBreGenerated_maiaCCLexPatterns + index, units, length, 0) == (int)(length);
                break;
              }
            }
          }
        }
      }
    }
  }
  free(units);
  return accepted;
}

void MaiaBreGenerated_maiaCCParserStateInit__pvpvN12unsigned_intpv(MaiaBreGenerated_MaiaCCParserState* self, const MaiaBreGenerated_MaiaCCParserToken* tokens, unsigned int tokenCount, const MaiaBreGenerated_MaiaCCParseEvents* events) {
  self -> tokens = tokens;
  self -> tokenCount = tokenCount;
  self -> position = 0;
  self -> events = events;
  self -> failed = 0;
  self -> resourceError = 0;
  self -> errorCount = 0;
  self -> errorPosition = 0;
  self -> expectedToken = 0;
  self -> foundToken = 0;
  self -> failureMemo = 0;
}

const MaiaBreGenerated_MaiaCCParserToken* MaiaBreGenerated_maiaCC_peek__pv(const MaiaBreGenerated_MaiaCCParserState* self) {
  return self -> position < self -> tokenCount ? self -> tokens + self -> position : 0;
}

void MaiaBreGenerated_maiaCC_recordError__pvN12unsigned_int(MaiaBreGenerated_MaiaCCParserState* self, unsigned int expected) {
  if (self -> errorCount == 0) {
    {
      const MaiaBreGenerated_MaiaCCParserToken* token;
      token = MaiaBreGenerated_maiaCC_peek__pv(self);
      self -> errorPosition = self -> position;
      self -> expectedToken = expected;
      self -> foundToken = token ? token -> type : 1;
    }
  }
  ++ self -> errorCount;
}

unsigned int MaiaBreGenerated_maiaCC_checkpointEvents__pv(const MaiaBreGenerated_MaiaCCParserState* self) {
  return self -> events && self -> events -> checkpoint ? self -> events -> checkpoint ( self -> events -> context ) : 0;
}

void MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(const MaiaBreGenerated_MaiaCCParserState* self, unsigned int mark) {
  if (self -> events && self -> events -> restore) {
    {
      self -> events -> restore ( self -> events -> context , mark );
    }
  }
}

void MaiaBreGenerated_maiaCC_startNonterminal__pvpv(const MaiaBreGenerated_MaiaCCParserState* self, const char* name) {
  if (self -> events && self -> events -> startNonterminal) {
    {
      self -> events -> startNonterminal ( self -> events -> context , name , self -> position );
    }
  }
}

void MaiaBreGenerated_maiaCC_endNonterminal__pvpv(const MaiaBreGenerated_MaiaCCParserState* self, const char* name) {
  if (self -> events && self -> events -> endNonterminal) {
    {
      self -> events -> endNonterminal ( self -> events -> context , name , self -> position );
    }
  }
}

void MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(const MaiaBreGenerated_MaiaCCParserState* self, const char* name) {
  if (self -> events && self -> events -> abortNonterminal) {
    {
      self -> events -> abortNonterminal ( self -> events -> context , name , self -> position );
    }
  }
}

void MaiaBreGenerated_maiaCC_emitTerminal__pvpv(const MaiaBreGenerated_MaiaCCParserState* self, const MaiaBreGenerated_MaiaCCParserToken* token) {
  if (self -> events && self -> events -> terminal && token) {
    {
      self -> events -> terminal ( self -> events -> context , token -> type , token -> value , token -> length , self -> position );
    }
  }
}

int MaiaBreGenerated_maiaCC_matchToken__pvN12unsigned_int(MaiaBreGenerated_MaiaCCParserState* self, unsigned int expected) {
  const MaiaBreGenerated_MaiaCCParserToken* token;
  if (self -> failed) {
    return 0;
  }
  token = MaiaBreGenerated_maiaCC_peek__pv(self);
  if (! token || token -> type != expected) {
    return 0;
  }
  MaiaBreGenerated_maiaCC_emitTerminal__pvpv(self, token);
  ++ self -> position;
  return 1;
}

int MaiaBreGenerated_maiaCC_matchContextualToken__pvN12unsigned_int(MaiaBreGenerated_MaiaCCParserState* self, unsigned int expected) {
  const MaiaBreGenerated_MaiaCCParserToken* token;
  int accepted;
  if (self -> failed) {
    return 0;
  }
  token = MaiaBreGenerated_maiaCC_peek__pv(self);
  if (! token) {
    {
      MaiaBreGenerated_maiaCC_recordError__pvN12unsigned_int(self, expected);
      return 0;
    }
  }
  accepted = token -> type == expected || MaiaBreGenerated_maiaCCLexMatchesContextual__N12unsigned_intpv(expected, token) || ( self -> events && self -> events -> matchesContextual && self -> events -> matchesContextual ( self -> events -> context , expected , token ) );
  if (! accepted) {
    {
      MaiaBreGenerated_maiaCC_recordError__pvN12unsigned_int(self, expected);
      return 0;
    }
  }
  MaiaBreGenerated_maiaCC_emitTerminal__pvpv(self, token);
  ++ self -> position;
  return 1;
}

int MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(MaiaBreGenerated_MaiaCCParserState* self, unsigned int expected) {
  if (MaiaBreGenerated_maiaCC_matchToken__pvN12unsigned_int(self, expected)) {
    return 1;
  }
  MaiaBreGenerated_maiaCC_recordError__pvN12unsigned_int(self, expected);
  self -> failed = 1;
  return 0;
}

int MaiaBreGenerated_maiaCC_expectContextualToken__pvN12unsigned_int(MaiaBreGenerated_MaiaCCParserState* self, unsigned int expected) {
  if (MaiaBreGenerated_maiaCC_matchContextualToken__pvN12unsigned_int(self, expected)) {
    return 1;
  }
  self -> failed = 1;
  return 0;
}

int MaiaBreGenerated_maiaCC_parse__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int columns;
  int accepted;
  self -> position = 0;
  self -> failed = 0;
  self -> resourceError = 0;
  self -> errorCount = 0;
  columns = (unsigned int)(self -> tokenCount) + 1;
  if (columns == 0 || 72 > ( (unsigned int)(- 1) ) / columns) {
    {
      self -> failed = 1;
      self -> resourceError = 2;
      return 0;
    }
  }
  self -> failureMemo = (unsigned char*)(calloc(72, columns));
  if (! self -> failureMemo) {
    {
      self -> failed = 1;
      self -> resourceError = 1;
      return 0;
    }
  }
  accepted = MaiaBreGenerated_maiaCC_parse_Input__pv(self) && ! self -> failed;
  if (accepted) {
    accepted = self -> position == self -> tokenCount || ( self -> position + 1 == self -> tokenCount && MaiaBreGenerated_maiaCC_peek__pv(self) -> type == 1 );
  }
  free(self -> failureMemo);
  self -> failureMemo = 0;
  return accepted;
}

int MaiaBreGenerated_maiaCC_parse_Input__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(0) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Input");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Sequence0__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 1);
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Input");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Input");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Sequence0__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(1) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Sequence0");
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_BeginAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_InitialStarPiece__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  while (! self -> failed) {
    {
      unsigned int _iterationStart;
      unsigned int _eventMark;
      _iterationStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Piece0__pv(self)) {
        {
          self -> position = _iterationStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
          break;
        }
      }
      if (self -> position == _iterationStart) {
        break;
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_EndAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Sequence0");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Sequence0");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Piece0__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(2) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Piece0");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Atom0__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Quantifier__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Piece0");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Piece0");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Atom0__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  int _matched;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(3) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Atom0");
  _matched = 0;
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Group0__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Class__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Any__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Reference__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Escape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_UnsupportedEscape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Literal__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Atom0");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Atom0");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Group0__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(4) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Group0");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_GroupOpen__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Sequence1__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_GroupClose__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Group0");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Group0");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Sequence1__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(5) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Sequence1");
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_BeginAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_InitialStarPiece__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  while (! self -> failed) {
    {
      unsigned int _iterationStart;
      unsigned int _eventMark;
      _iterationStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Piece1__pv(self)) {
        {
          self -> position = _iterationStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
          break;
        }
      }
      if (self -> position == _iterationStart) {
        break;
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_EndAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Sequence1");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Sequence1");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Piece1__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(6) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Piece1");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Atom1__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Quantifier__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Piece1");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Piece1");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Atom1__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  int _matched;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(7) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Atom1");
  _matched = 0;
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Group1__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Class__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Any__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Reference__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Escape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_UnsupportedEscape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Literal__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Atom1");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Atom1");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Group1__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(8) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Group1");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_GroupOpen__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Sequence2__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_GroupClose__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Group1");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Group1");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Sequence2__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(9) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Sequence2");
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_BeginAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_InitialStarPiece__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  while (! self -> failed) {
    {
      unsigned int _iterationStart;
      unsigned int _eventMark;
      _iterationStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Piece2__pv(self)) {
        {
          self -> position = _iterationStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
          break;
        }
      }
      if (self -> position == _iterationStart) {
        break;
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_EndAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Sequence2");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Sequence2");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Piece2__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(10) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Piece2");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Atom2__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Quantifier__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Piece2");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Piece2");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Atom2__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  int _matched;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(11) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Atom2");
  _matched = 0;
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Group2__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Class__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Any__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Reference__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Escape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_UnsupportedEscape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Literal__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Atom2");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Atom2");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Group2__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(12) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Group2");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_GroupOpen__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Sequence3__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_GroupClose__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Group2");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Group2");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Sequence3__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(13) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Sequence3");
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_BeginAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_InitialStarPiece__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  while (! self -> failed) {
    {
      unsigned int _iterationStart;
      unsigned int _eventMark;
      _iterationStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Piece3__pv(self)) {
        {
          self -> position = _iterationStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
          break;
        }
      }
      if (self -> position == _iterationStart) {
        break;
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_EndAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Sequence3");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Sequence3");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Piece3__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(14) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Piece3");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Atom3__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Quantifier__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Piece3");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Piece3");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Atom3__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  int _matched;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(15) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Atom3");
  _matched = 0;
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Group3__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Class__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Any__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Reference__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Escape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_UnsupportedEscape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Literal__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Atom3");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Atom3");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Group3__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(16) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Group3");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_GroupOpen__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Sequence4__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_GroupClose__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Group3");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Group3");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Sequence4__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(17) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Sequence4");
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_BeginAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_InitialStarPiece__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  while (! self -> failed) {
    {
      unsigned int _iterationStart;
      unsigned int _eventMark;
      _iterationStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Piece4__pv(self)) {
        {
          self -> position = _iterationStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
          break;
        }
      }
      if (self -> position == _iterationStart) {
        break;
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_EndAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Sequence4");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Sequence4");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Piece4__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(18) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Piece4");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Atom4__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Quantifier__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Piece4");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Piece4");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Atom4__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  int _matched;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(19) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Atom4");
  _matched = 0;
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Group4__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Class__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Any__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Reference__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Escape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_UnsupportedEscape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Literal__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Atom4");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Atom4");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Group4__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(20) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Group4");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_GroupOpen__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Sequence5__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_GroupClose__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Group4");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Group4");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Sequence5__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(21) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Sequence5");
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_BeginAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_InitialStarPiece__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  while (! self -> failed) {
    {
      unsigned int _iterationStart;
      unsigned int _eventMark;
      _iterationStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Piece5__pv(self)) {
        {
          self -> position = _iterationStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
          break;
        }
      }
      if (self -> position == _iterationStart) {
        break;
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_EndAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Sequence5");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Sequence5");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Piece5__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(22) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Piece5");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Atom5__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Quantifier__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Piece5");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Piece5");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Atom5__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  int _matched;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(23) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Atom5");
  _matched = 0;
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Group5__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Class__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Any__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Reference__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Escape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_UnsupportedEscape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Literal__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Atom5");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Atom5");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Group5__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(24) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Group5");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_GroupOpen__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Sequence6__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_GroupClose__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Group5");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Group5");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Sequence6__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(25) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Sequence6");
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_BeginAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_InitialStarPiece__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  while (! self -> failed) {
    {
      unsigned int _iterationStart;
      unsigned int _eventMark;
      _iterationStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Piece6__pv(self)) {
        {
          self -> position = _iterationStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
          break;
        }
      }
      if (self -> position == _iterationStart) {
        break;
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_EndAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Sequence6");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Sequence6");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Piece6__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(26) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Piece6");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Atom6__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Quantifier__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Piece6");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Piece6");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Atom6__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  int _matched;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(27) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Atom6");
  _matched = 0;
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Group6__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Class__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Any__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Reference__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Escape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_UnsupportedEscape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Literal__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Atom6");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Atom6");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Group6__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(28) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Group6");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_GroupOpen__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Sequence7__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_GroupClose__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Group6");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Group6");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Sequence7__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(29) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Sequence7");
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_BeginAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_InitialStarPiece__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  while (! self -> failed) {
    {
      unsigned int _iterationStart;
      unsigned int _eventMark;
      _iterationStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Piece7__pv(self)) {
        {
          self -> position = _iterationStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
          break;
        }
      }
      if (self -> position == _iterationStart) {
        break;
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_EndAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Sequence7");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Sequence7");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Piece7__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(30) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Piece7");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Atom7__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Quantifier__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Piece7");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Piece7");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Atom7__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  int _matched;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(31) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Atom7");
  _matched = 0;
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Group7__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Class__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Any__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Reference__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Escape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_UnsupportedEscape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Literal__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Atom7");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Atom7");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Group7__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(32) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Group7");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_GroupOpen__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Sequence8__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_GroupClose__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Group7");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Group7");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Sequence8__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(33) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Sequence8");
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_BeginAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_InitialStarPiece__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  while (! self -> failed) {
    {
      unsigned int _iterationStart;
      unsigned int _eventMark;
      _iterationStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Piece8__pv(self)) {
        {
          self -> position = _iterationStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
          break;
        }
      }
      if (self -> position == _iterationStart) {
        break;
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_EndAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Sequence8");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Sequence8");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Piece8__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(34) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Piece8");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Atom8__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Quantifier__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Piece8");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Piece8");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Atom8__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  int _matched;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(35) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Atom8");
  _matched = 0;
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Group8__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Class__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Any__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Reference__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Escape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_UnsupportedEscape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Literal__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Atom8");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Atom8");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Group8__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(36) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Group8");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_GroupOpen__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Sequence9__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_GroupClose__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Group8");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Group8");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Sequence9__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(37) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Sequence9");
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_BeginAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_InitialStarPiece__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  while (! self -> failed) {
    {
      unsigned int _iterationStart;
      unsigned int _eventMark;
      _iterationStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Piece9__pv(self)) {
        {
          self -> position = _iterationStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
          break;
        }
      }
      if (self -> position == _iterationStart) {
        break;
      }
    }
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_EndAnchor__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Sequence9");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Sequence9");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Piece9__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(38) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Piece9");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Atom9__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Quantifier__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Piece9");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Piece9");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Atom9__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  int _matched;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(39) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Atom9");
  _matched = 0;
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_DepthOverflow__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Class__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Any__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Reference__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Escape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_UnsupportedEscape__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Literal__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Atom9");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Atom9");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_DepthOverflow__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(40) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "DepthOverflow");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_GroupOpen__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "DepthOverflow");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "DepthOverflow");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_BeginAnchor__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(41) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "BeginAnchor");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 11);
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "BeginAnchor");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "BeginAnchor");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_EndAnchor__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(42) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "EndAnchor");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 2);
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "EndAnchor");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "EndAnchor");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_InitialStarPiece__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(43) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "InitialStarPiece");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_InitialStar__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Quantifier__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "InitialStarPiece");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "InitialStarPiece");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_InitialStar__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(44) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "InitialStar");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 13);
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "InitialStar");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "InitialStar");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_GroupOpen__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(45) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "GroupOpen");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 4);
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 5);
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "GroupOpen");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "GroupOpen");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_GroupClose__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(46) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "GroupClose");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 4);
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 6);
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "GroupClose");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "GroupClose");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Any__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(47) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Any");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 14);
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Any");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Any");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Reference__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(48) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Reference");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 4);
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 23);
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Reference");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Reference");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Escape__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(49) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Escape");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 4);
  }
  {
    int _matchedAlternative;
    _matchedAlternative = 0;
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed) {
          MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 4);
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed) {
          MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 14);
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed) {
          MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 11);
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed) {
          MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 12);
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed) {
          MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 2);
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed) {
          MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 9);
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed) {
          MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 3);
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed) {
          MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 10);
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed) {
          MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 13);
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative) {
      self -> failed = 1;
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Escape");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Escape");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_UnsupportedEscape__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(50) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "UnsupportedEscape");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 4);
  }
  {
    int _matchedAlternative;
    _matchedAlternative = 0;
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed) {
          MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 15);
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed) {
          MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 16);
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed) {
          MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 17);
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed) {
          MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 22);
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed) {
          MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 24);
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed) {
          MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 18);
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed) {
          MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 19);
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed) {
          MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 20);
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed) {
          MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 21);
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative) {
      self -> failed = 1;
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "UnsupportedEscape");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "UnsupportedEscape");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Literal__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  int _matched;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(51) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Literal");
  _matched = 0;
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 22);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 23);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 24);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 15);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 16);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 17);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 5);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 6);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 7);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 8);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 18);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 19);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 20);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 21);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 11);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 12);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 10);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Literal");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Literal");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Quantifier__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  int _matched;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(52) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Quantifier");
  _matched = 0;
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_StarRepeat__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_ExactRepeat__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_OpenRepeat__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_BoundedRepeat__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Quantifier");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Quantifier");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_StarRepeat__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(53) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "StarRepeat");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 13);
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "StarRepeat");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "StarRepeat");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_ExactRepeat__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(54) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "ExactRepeat");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 4);
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 7);
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Number__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 4);
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 8);
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "ExactRepeat");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "ExactRepeat");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_OpenRepeat__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(55) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "OpenRepeat");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 4);
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 7);
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Number__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 21);
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 4);
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 8);
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "OpenRepeat");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "OpenRepeat");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_BoundedRepeat__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(56) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "BoundedRepeat");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 4);
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 7);
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Number__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 21);
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Number__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 4);
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 8);
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "BoundedRepeat");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "BoundedRepeat");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Number__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(57) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Number");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 23);
  }
  while (MaiaBreGenerated_maiaCC_matchToken__pvN12unsigned_int(self, 23)) {
    {
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Number");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Number");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Class__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(58) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Class");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_ClassOpen__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      unsigned int _optionalStart;
      unsigned int _eventMark;
      _optionalStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_Negation__pv(self)) {
        {
          self -> position = _optionalStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  {
    int _matchedAlternative;
    _matchedAlternative = 0;
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_InitialCloseRange__pv(self)) {
          self -> failed = 1;
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_InitialClose__pv(self)) {
          self -> failed = 1;
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative && ! self -> failed) {
      {
        unsigned int _alternativeStart;
        unsigned int _eventMark;
        _alternativeStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_ClassElement__pv(self)) {
          self -> failed = 1;
        }
        if (! self -> failed) {
          {
            _matchedAlternative = 1;
          }
        } else {
          {
            self -> position = _alternativeStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
          }
        }
      }
    }
    if (! _matchedAlternative) {
      self -> failed = 1;
    }
  }
  while (! self -> failed) {
    {
      unsigned int _iterationStart;
      unsigned int _eventMark;
      _iterationStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! MaiaBreGenerated_maiaCC_parse_ClassElement__pv(self)) {
        {
          self -> position = _iterationStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
          break;
        }
      }
      if (self -> position == _iterationStart) {
        break;
      }
    }
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 10);
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Class");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Class");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_ClassOpen__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  int _matched;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(59) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "ClassOpen");
  _matched = 0;
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 9);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 3);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "ClassOpen");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "ClassOpen");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Negation__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(60) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Negation");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 11);
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Negation");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Negation");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_InitialCloseRange__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(61) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "InitialCloseRange");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 10);
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 18);
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_ClassScalar__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "InitialCloseRange");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "InitialCloseRange");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_InitialClose__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(62) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "InitialClose");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 10);
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "InitialClose");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "InitialClose");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_ClassElement__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  int _matched;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(63) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "ClassElement");
  _matched = 0;
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_NamedClass__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Collating__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Equivalence__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_Range__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_ClassScalar__pv(self)) {
        self -> failed = 1;
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "ClassElement");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "ClassElement");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_NamedClass__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(64) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "NamedClass");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 3);
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 19);
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_ClassName__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 19);
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 10);
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "NamedClass");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "NamedClass");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_ClassName__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(65) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "ClassName");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 22);
  }
  while (MaiaBreGenerated_maiaCC_matchToken__pvN12unsigned_int(self, 22)) {
    {
    }
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "ClassName");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "ClassName");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Collating__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(66) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Collating");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 3);
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 14);
  }
  {
    unsigned int _count;
    _count = 0;
    while (! self -> failed) {
      {
        unsigned int _iterationStart;
        unsigned int _eventMark;
        _iterationStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! MaiaBreGenerated_maiaCC_parse_CollatingScalar__pv(self)) {
          {
            self -> position = _iterationStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
            break;
          }
        }
        if (self -> position == _iterationStart) {
          break;
        }
        ++ _count;
      }
    }
    if (_count == 0) {
      self -> failed = 1;
    }
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 14);
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 10);
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Collating");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Collating");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Equivalence__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(67) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Equivalence");
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 3);
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 20);
  }
  {
    unsigned int _count;
    _count = 0;
    while (! self -> failed) {
      {
        unsigned int _iterationStart;
        unsigned int _eventMark;
        _iterationStart = self -> position;
        _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
        if (! MaiaBreGenerated_maiaCC_parse_EquivalenceScalar__pv(self)) {
          {
            self -> position = _iterationStart;
            MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
            self -> failed = 0;
            break;
          }
        }
        if (self -> position == _iterationStart) {
          break;
        }
        ++ _count;
      }
    }
    if (_count == 0) {
      self -> failed = 1;
    }
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 20);
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 10);
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Equivalence");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Equivalence");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_CollatingScalar__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  int _matched;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(68) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "CollatingScalar");
  _matched = 0;
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 22);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 23);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 24);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 15);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 16);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 17);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 5);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 6);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 7);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 8);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 18);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 19);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 20);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 21);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 11);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 12);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 2);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 13);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 4);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 9);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "CollatingScalar");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "CollatingScalar");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_EquivalenceScalar__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  int _matched;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(69) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "EquivalenceScalar");
  _matched = 0;
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 22);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 23);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 24);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 15);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 16);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 17);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 5);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 6);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 7);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 8);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 18);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 19);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 14);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 21);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 11);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 12);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 2);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 13);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 4);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 9);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "EquivalenceScalar");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "EquivalenceScalar");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_Range__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(70) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "Range");
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_ClassScalar__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 18);
  }
  if (! self -> failed && ! MaiaBreGenerated_maiaCC_parse_ClassScalar__pv(self)) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "Range");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "Range");
  return 0;
}

int MaiaBreGenerated_maiaCC_parse_ClassScalar__pv(MaiaBreGenerated_MaiaCCParserState* self) {
  unsigned int __ruleStart;
  unsigned int __memoSlot;
  unsigned int __eventMark;
  int _matched;
  if (self -> failed) {
    return 0;
  }
  __ruleStart = self -> position;
  __memoSlot = (unsigned int)(71) * ( (unsigned int)(self -> tokenCount) + 1 ) + __ruleStart;
  if (self -> failureMemo && self -> failureMemo [ __memoSlot ]) {
    {
      self -> failed = 1;
      return 0;
    }
  }
  __eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
  MaiaBreGenerated_maiaCC_startNonterminal__pvpv(self, "ClassScalar");
  _matched = 0;
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 22);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 23);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 24);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 15);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 16);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 17);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 5);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 6);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 7);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 8);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 18);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 19);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 14);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 20);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 21);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 11);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 12);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 2);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 13);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 4);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched && ! self -> failed) {
    {
      unsigned int _alternativeStart;
      unsigned int _eventMark;
      _alternativeStart = self -> position;
      _eventMark = MaiaBreGenerated_maiaCC_checkpointEvents__pv(self);
      if (! self -> failed) {
        MaiaBreGenerated_maiaCC_expectToken__pvN12unsigned_int(self, 9);
      }
      if (! self -> failed) {
        {
          _matched = 1;
        }
      } else {
        {
          self -> position = _alternativeStart;
          MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, _eventMark);
          self -> failed = 0;
        }
      }
    }
  }
  if (! _matched) {
    self -> failed = 1;
  }
  if (! self -> failed) {
    {
      MaiaBreGenerated_maiaCC_endNonterminal__pvpv(self, "ClassScalar");
      return 1;
    }
  }
  self -> position = __ruleStart;
  if (self -> failureMemo) {
    self -> failureMemo [ __memoSlot ] = 1;
  }
  MaiaBreGenerated_maiaCC_restoreEvents__pvN12unsigned_int(self, __eventMark);
  MaiaBreGenerated_maiaCC_abortNonterminal__pvpv(self, "ClassScalar");
  return 0;
}

unsigned int bre_checkpoint__pv(void* context) {
  BreCompile* s;
  s = (BreCompile*)(context);
  return ( s -> count << 16 ) | (unsigned int)(s -> active + 1);
}

void bre_restore__pvN12unsigned_int(void* context, unsigned int mark) {
  BreCompile* s;
  s = (BreCompile*)(context);
  s -> count = mark >> 16;
  s -> active = (int)(mark & 65535u) - 1;
}

void bre_append__pvN12unsigned_intpvN12unsigned_int(BreCompile* s, unsigned int kind, const char* name, unsigned int token) {
  BreNode* n;
  if (s -> count == 8192) {
    {
      s -> overflow = 1;
      return;
    }
  }
  n = s -> nodes + s -> count;
  n -> kind = kind;
  n -> name = name;
  n -> token = token;
  n -> parent = s -> active;
  n -> end = s -> count + 1;
  n -> entry = 4294967295U;
  n -> tail = 4294967295U;
  n -> group = 0;
  if (kind == 1) {
    s -> active = (int)(s -> count);
  }
  ++ s -> count;
}

void bre_start__pvpvN12unsigned_int(void* context, const char* name, unsigned int p3) {
  bre_append__pvN12unsigned_intpvN12unsigned_int((BreCompile*)(context), 1, name, 0);
}

void bre_terminal__pvN12unsigned_intpvN12unsigned_intN12unsigned_int(void* context, unsigned int p2, const char* p3, unsigned int p4, unsigned int position) {
  bre_append__pvN12unsigned_intpvN12unsigned_int((BreCompile*)(context), 2, 0, position);
}

void bre_end__pvpvN12unsigned_int(void* context, const char* name, unsigned int p3) {
  BreCompile* s;
  s = (BreCompile*)(context);
  if (s -> active < 0) {
    {
      s -> overflow = 1;
      return;
    }
  }
  s -> nodes [ s -> active ] . end = s -> count;
  s -> active = s -> nodes [ s -> active ] . parent;
  if (! strcmp(name, "DepthOverflow")) {
    s -> depth_overflow = 1;
  }
}

void bre_abort__pvpvN12unsigned_int(void* p1, const char* p2, unsigned int p3) {
}

int bre_named__pvpv(const BreNode* n, const char* name) {
  return n -> kind == 1 && ! strcmp(n -> name, name);
}

int bre_numbered__pvpvN12unsigned_int(const BreNode* n, const char* prefix, unsigned int length) {
  return n -> kind == 1 && ! strncmp(n -> name, prefix, length) && n -> name [ length ] >= '0' && n -> name [ length ] <= '9' && ! n -> name [ length + 1 ];
}

int bre_work__pv(BreCompile* s) {
  if (s -> steps == s -> limits -> max_steps) {
    return 4;
  }
  ++ s -> steps;
  return 0;
}

unsigned int bre_emit__pvN12unsigned_intN12unsigned_intN12unsigned_int(BreCompile* s, unsigned int op, unsigned int a, unsigned int b) {
  MaiaBreProgram* p;
  unsigned int id;
  BreInstruction* c;
  p = s -> program;
  if (p -> code_count == p -> code_capacity) {
    return 4294967295U;
  }
  id = p -> code_count ++;
  c = p -> code + id;
  c -> op = op;
  c -> a = a;
  c -> b = b;
  c -> next = 4294967295U;
  c -> min = 0;
  c -> max = 0;
  return id;
}

int bre_scalar__pvN12unsigned_intN12unsigned_intpv(BreCompile* s, unsigned int node, unsigned int terminal_index, unsigned int* value) {
  unsigned int count;
  count = 0;
  {
    unsigned int i;
    i = node + 1;
    for (; i < s -> nodes [ node ] . end; ++ i) {
      if (s -> nodes [ i ] . kind == 2) {
        {
          if (count ++ == terminal_index) {
            {
              const MaiaBreGenerated_MaiaCCParserToken* t;
              unsigned int at;
              int r;
              t = s -> tokens + s -> nodes [ i ] . token;
              at = 0;
              r = bre_utf8_next((const unsigned char*)(t -> value), t -> length, & at, value);
              return r ? r : ( at == t -> length ? 0 : 2 );
            }
          }
        }
      }
    }
  }
  return 2;
}

int bre_add_range__pvN12unsigned_intN12unsigned_int(BreCompile* s, unsigned int a, unsigned int b) {
  MaiaBreProgram* p;
  if (a > b) {
    return 2;
  }
  p = s -> program;
  if (p -> range_count == p -> range_capacity) {
    return 4;
  }
  p -> ranges [ p -> range_count ] . first = a;
  p -> ranges [ p -> range_count ++ ] . last = b;
  return 0;
}

int bre_named_class__pvN12unsigned_int(BreCompile* s, unsigned int node) {
  char name[32];
  unsigned int size;
  unsigned int ranges[8];
  unsigned int count;
  size = 0;
  {
    unsigned int i;
    i = node + 1;
    for (; i < s -> nodes [ node ] . end; ++ i) {
      if (bre_named__pvpv(s -> nodes + i, "ClassName")) {
        {
          {
            unsigned int j;
            j = i + 1;
            for (; j < s -> nodes [ i ] . end; ++ j) {
              if (s -> nodes [ j ] . kind == 2) {
                {
                  if (size == 31) {
                    return 2;
                  }
                  name [ size ++ ] = s -> tokens [ s -> nodes [ j ] . token ] . value [ 0 ];
                }
              }
            }
          }
          break;
        }
      }
    }
  }
  name [ size ] = 0;
  count = 0;
  if (! strcmp(name, "alnum")) {
    {
      ranges [ 0 ] = 48;
      ranges [ 1 ] = 57;
      ranges [ 2 ] = 65;
      ranges [ 3 ] = 90;
      ranges [ 4 ] = 97;
      ranges [ 5 ] = 122;
      count = 6;
    }
  } else {
    if (! strcmp(name, "alpha")) {
      {
        ranges [ 0 ] = 65;
        ranges [ 1 ] = 90;
        ranges [ 2 ] = 97;
        ranges [ 3 ] = 122;
        count = 4;
      }
    } else {
      if (! strcmp(name, "blank")) {
        {
          ranges [ 0 ] = 9;
          ranges [ 1 ] = 9;
          ranges [ 2 ] = 32;
          ranges [ 3 ] = 32;
          count = 4;
        }
      } else {
        if (! strcmp(name, "cntrl")) {
          {
            ranges [ 0 ] = 0;
            ranges [ 1 ] = 31;
            ranges [ 2 ] = 127;
            ranges [ 3 ] = 127;
            count = 4;
          }
        } else {
          if (! strcmp(name, "digit")) {
            {
              ranges [ 0 ] = 48;
              ranges [ 1 ] = 57;
              count = 2;
            }
          } else {
            if (! strcmp(name, "graph")) {
              {
                ranges [ 0 ] = 33;
                ranges [ 1 ] = 126;
                count = 2;
              }
            } else {
              if (! strcmp(name, "lower")) {
                {
                  ranges [ 0 ] = 97;
                  ranges [ 1 ] = 122;
                  count = 2;
                }
              } else {
                if (! strcmp(name, "print")) {
                  {
                    ranges [ 0 ] = 32;
                    ranges [ 1 ] = 126;
                    count = 2;
                  }
                } else {
                  if (! strcmp(name, "punct")) {
                    {
                      ranges [ 0 ] = 33;
                      ranges [ 1 ] = 47;
                      ranges [ 2 ] = 58;
                      ranges [ 3 ] = 64;
                      ranges [ 4 ] = 91;
                      ranges [ 5 ] = 96;
                      ranges [ 6 ] = 123;
                      ranges [ 7 ] = 126;
                      count = 8;
                    }
                  } else {
                    if (! strcmp(name, "space")) {
                      {
                        ranges [ 0 ] = 9;
                        ranges [ 1 ] = 13;
                        ranges [ 2 ] = 32;
                        ranges [ 3 ] = 32;
                        count = 4;
                      }
                    } else {
                      if (! strcmp(name, "upper")) {
                        {
                          ranges [ 0 ] = 65;
                          ranges [ 1 ] = 90;
                          count = 2;
                        }
                      } else {
                        if (! strcmp(name, "xdigit")) {
                          {
                            ranges [ 0 ] = 48;
                            ranges [ 1 ] = 57;
                            ranges [ 2 ] = 65;
                            ranges [ 3 ] = 70;
                            ranges [ 4 ] = 97;
                            ranges [ 5 ] = 102;
                            count = 6;
                          }
                        } else {
                          return 2;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  {
    unsigned int i;
    i = 0;
    for (; i < count; i += 2) {
      {
        int r;
        r = bre_add_range__pvN12unsigned_intN12unsigned_int(s, ranges [ i ], ranges [ i + 1 ]);
        if (r) {
          return r;
        }
      }
    }
  }
  return 0;
}

int bre_class__pvN12unsigned_intpv(BreCompile* s, unsigned int node, unsigned int* instruction) {
  unsigned int first;
  unsigned int negative;
  first = s -> program -> range_count;
  negative = 0;
  {
    unsigned int i;
    i = node + 1;
    for (; i < s -> nodes [ node ] . end; ) {
      {
        BreNode* n;
        int r;
        if (bre_work__pv(s)) {
          return 4;
        }
        n = s -> nodes + i;
        r = 0;
        if (bre_named__pvpv(n, "Negation")) {
          {
            negative = 1;
            i = n -> end;
            continue;
          }
        }
        if (bre_named__pvpv(n, "Collating") || bre_named__pvpv(n, "Equivalence")) {
          return 7;
        }
        if (bre_named__pvpv(n, "NamedClass")) {
          {
            r = bre_named_class__pvN12unsigned_int(s, i);
            i = n -> end;
          }
        } else {
          if (bre_named__pvpv(n, "InitialClose")) {
            {
              r = bre_add_range__pvN12unsigned_intN12unsigned_int(s, 93, 93);
              i = n -> end;
            }
          } else {
            if (bre_named__pvpv(n, "Range") || bre_named__pvpv(n, "InitialCloseRange")) {
              {
                unsigned int a;
                unsigned int b;
                unsigned int count;
                a = 0;
                b = 0;
                count = 0;
                if (bre_named__pvpv(n, "InitialCloseRange")) {
                  {
                    a = 93;
                    count = 1;
                  }
                }
                {
                  unsigned int j;
                  j = i + 1;
                  for (; j < n -> end; ) {
                    if (bre_named__pvpv(s -> nodes + j, "ClassScalar")) {
                      {
                        unsigned int value;
                        value = 0;
                        r = bre_scalar__pvN12unsigned_intN12unsigned_intpv(s, j, 0, & value);
                        if (r) {
                          return r;
                        }
                        if (! count) {
                          a = value;
                        } else {
                          b = value;
                        }
                        ++ count;
                        j = s -> nodes [ j ] . end;
                      }
                    } else {
                      ++ j;
                    }
                  }
                }
                if (count != 2) {
                  return 2;
                }
                r = bre_add_range__pvN12unsigned_intN12unsigned_int(s, a, b);
                i = n -> end;
              }
            } else {
              if (bre_named__pvpv(n, "ClassScalar")) {
                {
                  unsigned int value;
                  value = 0;
                  r = bre_scalar__pvN12unsigned_intN12unsigned_intpv(s, i, 0, & value);
                  if (r) {
                    return r;
                  }
                  if (value == 45 && s -> program -> range_count != first && n -> end + 1 != s -> nodes [ node ] . end) {
                    return 2;
                  }
                  r = bre_add_range__pvN12unsigned_intN12unsigned_int(s, value, value);
                  i = n -> end;
                }
              } else {
                {
                  ++ i;
                  continue;
                }
              }
            }
          }
        }
        if (r) {
          return r;
        }
      }
    }
  }
  if (s -> program -> range_count == first) {
    return 2;
  }
  * instruction = bre_emit__pvN12unsigned_intN12unsigned_intN12unsigned_int(s, negative ? 4 : 3, first, s -> program -> range_count - first);
  return * instruction == 4294967295U ? 4 : 0;
}

int bre_quantity__pvN12unsigned_intpvpv(BreCompile* s, unsigned int node, unsigned int* minimum, unsigned int* maximum) {
  unsigned int values[2];
  unsigned int count;
  count = 0;
  * minimum = 0;
  * maximum = 4294967295U;
  if (bre_named__pvpv(s -> nodes + node, "StarRepeat")) {
    return 0;
  }
  {
    unsigned int i;
    i = node + 1;
    for (; i < s -> nodes [ node ] . end; ++ i) {
      if (bre_named__pvpv(s -> nodes + i, "Number")) {
        {
          unsigned int value;
          value = 0;
          {
            unsigned int j;
            j = i + 1;
            for (; j < s -> nodes [ i ] . end; ++ j) {
              if (s -> nodes [ j ] . kind == 2) {
                {
                  unsigned int d;
                  d = (unsigned int)(s -> tokens [ s -> nodes [ j ] . token ] . value [ 0 ] - '0');
                  if (d > s -> limits -> max_repeat || value > ( s -> limits -> max_repeat - d ) / 10) {
                    return 4;
                  }
                  value = value * 10 + d;
                }
              }
            }
          }
          if (count == 2) {
            return 2;
          }
          values [ count ++ ] = value;
        }
      }
    }
  }
  if (! count) {
    return 2;
  }
  * minimum = values [ 0 ];
  if (bre_named__pvpv(s -> nodes + node, "ExactRepeat")) {
    * maximum = * minimum;
  }
  if (bre_named__pvpv(s -> nodes + node, "BoundedRepeat")) {
    {
      if (count != 2) {
        return 2;
      }
      * maximum = values [ 1 ];
      if (* minimum > * maximum) {
        return 2;
      }
    }
  }
  return 0;
}

int bre_lower__pv(BreCompile* s) {
  MaiaBreProgram* p;
  unsigned int accept;
  p = s -> program;
  {
    unsigned int i;
    i = 0;
    for (; i < s -> count; ++ i) {
      {
        BreNode* n;
        n = s -> nodes + i;
        if (bre_work__pv(s)) {
          return 4;
        }
        if (bre_named__pvpv(n, "UnsupportedEscape")) {
          return 7;
        }
        if (bre_numbered__pvpvN12unsigned_int(n, "Group", 5)) {
          {
            unsigned int depth;
            if (p -> groups == s -> limits -> max_captures) {
              return 4;
            }
            n -> group = ++ p -> groups;
            s -> groups [ n -> group ] = i;
            depth = 1;
            {
              int a;
              a = n -> parent;
              for (; a >= 0; a = s -> nodes [ a ] . parent) {
                if (bre_numbered__pvpvN12unsigned_int(s -> nodes + a, "Group", 5)) {
                  ++ depth;
                }
              }
            }
            if (depth > s -> limits -> max_parse_depth) {
              return 4;
            }
            if (depth > p -> depth) {
              p -> depth = depth;
            }
          }
        }
      }
    }
  }
  {
    unsigned int i;
    i = s -> count;
    for (; i > 0; ) {
      {
        BreNode* n;
        unsigned int instruction;
        int r;
        -- i;
        n = s -> nodes + i;
        if (n -> kind != 1) {
          continue;
        }
        if (bre_work__pv(s)) {
          return 4;
        }
        instruction = 4294967295U;
        r = 0;
        if (bre_named__pvpv(n, "Literal") || bre_named__pvpv(n, "Escape") || bre_named__pvpv(n, "InitialStar")) {
          {
            unsigned int value;
            value = 42;
            if (! bre_named__pvpv(n, "InitialStar")) {
              {
                r = bre_scalar__pvN12unsigned_intN12unsigned_intpv(s, i, bre_named__pvpv(n, "Escape") ? 1 : 0, & value);
                if (r) {
                  return r;
                }
              }
            }
            instruction = bre_emit__pvN12unsigned_intN12unsigned_intN12unsigned_int(s, 1, value, 0);
          }
        } else {
          if (bre_named__pvpv(n, "Any")) {
            instruction = bre_emit__pvN12unsigned_intN12unsigned_intN12unsigned_int(s, 2, 0, 0);
          } else {
            if (bre_named__pvpv(n, "BeginAnchor")) {
              instruction = bre_emit__pvN12unsigned_intN12unsigned_intN12unsigned_int(s, 5, 0, 0);
            } else {
              if (bre_named__pvpv(n, "EndAnchor")) {
                instruction = bre_emit__pvN12unsigned_intN12unsigned_intN12unsigned_int(s, 6, 0, 0);
              } else {
                if (bre_named__pvpv(n, "Class")) {
                  {
                    r = bre_class__pvN12unsigned_intpv(s, i, & instruction);
                    if (r) {
                      return r;
                    }
                  }
                } else {
                  if (bre_named__pvpv(n, "Reference")) {
                    {
                      unsigned int value;
                      value = 0;
                      r = bre_scalar__pvN12unsigned_intN12unsigned_intpv(s, i, 1, & value);
                      if (r) {
                        return r;
                      }
                      value -= 48;
                      if (! value || value > p -> groups || s -> nodes [ s -> groups [ value ] ] . end > i) {
                        return 2;
                      }
                      instruction = bre_emit__pvN12unsigned_intN12unsigned_intN12unsigned_int(s, 9, value, 0);
                    }
                  } else {
                    {
                      unsigned int entry;
                      unsigned int tail;
                      unsigned int quantifier;
                      entry = 4294967295U;
                      tail = 4294967295U;
                      quantifier = 4294967295U;
                      {
                        unsigned int j;
                        j = i + 1;
                        for (; j < n -> end; ) {
                          {
                            BreNode* child;
                            child = s -> nodes + j;
                            if (child -> parent == (int)(i)) {
                              {
                                if (child -> entry != 4294967295U) {
                                  {
                                    if (entry == 4294967295U) {
                                      entry = child -> entry;
                                    } else {
                                      p -> code [ tail ] . next = child -> entry;
                                    }
                                    tail = child -> tail;
                                  }
                                }
                                if (bre_named__pvpv(child, "Quantifier")) {
                                  quantifier = j;
                                }
                              }
                            }
                            j = child -> end;
                          }
                        }
                      }
                      if (bre_numbered__pvpvN12unsigned_int(n, "Group", 5)) {
                        {
                          unsigned int open;
                          unsigned int close;
                          unsigned int last;
                          open = bre_emit__pvN12unsigned_intN12unsigned_intN12unsigned_int(s, 7, n -> group, 0);
                          close = bre_emit__pvN12unsigned_intN12unsigned_intN12unsigned_int(s, 8, n -> group, 0);
                          if (open == 4294967295U || close == 4294967295U) {
                            return 4;
                          }
                          last = n -> group;
                          {
                            unsigned int k;
                            k = n -> group + 1;
                            for (; k <= p -> groups; ++ k) {
                              if (s -> groups [ k ] < n -> end) {
                                last = k;
                              } else {
                                break;
                              }
                            }
                          }
                          p -> code [ open ] . b = last;
                          p -> code [ open ] . max = i;
                          p -> code [ open ] . next = entry == 4294967295U ? close : entry;
                          if (tail != 4294967295U) {
                            p -> code [ tail ] . next = close;
                          }
                          entry = open;
                          tail = close;
                        }
                      }
                      if (( bre_numbered__pvpvN12unsigned_int(n, "Piece", 5) || bre_named__pvpv(n, "InitialStarPiece") ) && quantifier != 4294967295U) {
                        {
                          unsigned int minimum;
                          unsigned int maximum;
                          unsigned int q;
                          unsigned int bound;
                          unsigned int repeat;
                          unsigned int end;
                          minimum = 0;
                          maximum = 0;
                          q = quantifier + 1;
                          if (q >= s -> nodes [ quantifier ] . end) {
                            return 2;
                          }
                          r = bre_quantity__pvN12unsigned_intpvpv(s, q, & minimum, & maximum);
                          if (r) {
                            return r;
                          }
                          bound = maximum == 4294967295U ? minimum : maximum;
                          if (bound > p -> repeat_bound) {
                            p -> repeat_bound = bound;
                          }
                          repeat = bre_emit__pvN12unsigned_intN12unsigned_intN12unsigned_int(s, 10, entry, 0);
                          end = bre_emit__pvN12unsigned_intN12unsigned_intN12unsigned_int(s, 11, repeat, 0);
                          if (repeat == 4294967295U || end == 4294967295U || entry == 4294967295U) {
                            return 4;
                          }
                          p -> code [ repeat ] . b = i;
                          p -> code [ repeat ] . min = minimum;
                          p -> code [ repeat ] . max = maximum;
                          p -> code [ tail ] . next = end;
                          entry = repeat;
                          tail = repeat;
                        }
                      }
                      n -> entry = entry;
                      n -> tail = tail;
                      continue;
                    }
                  }
                }
              }
            }
          }
        }
        if (instruction == 4294967295U) {
          return 4;
        }
        n -> entry = instruction;
        n -> tail = instruction;
      }
    }
  }
  accept = bre_emit__pvN12unsigned_intN12unsigned_intN12unsigned_int(s, 0, 0, 0);
  if (accept == 4294967295U) {
    return 4;
  }
  p -> entry = s -> nodes [ 0 ] . entry == 4294967295U ? accept : s -> nodes [ 0 ] . entry;
  if (s -> nodes [ 0 ] . tail != 4294967295U) {
    p -> code [ s -> nodes [ 0 ] . tail ] . next = accept;
  }
  return 0;
}

int maia_bre_compile_utf8(const unsigned char* pattern, unsigned int length, const MaiaBreLimits* limits, MaiaBreProgram** output) {
  int r;
  BreCompile* s;
  MaiaBreProgram* p;
  MaiaBreGenerated_MaiaCCLexerState lexer;
  r = bre_limits_valid(limits);
  if (r) {
    return r;
  }
  if (! output || ! pattern) {
    return 6;
  }
  if (length > limits -> max_pattern_bytes) {
    return 4;
  }
  r = bre_text_check(pattern, length);
  if (r) {
    return r;
  }
  if (sizeof ( BreCompile ) > limits -> max_workspace_bytes) {
    return 4;
  }
  s = (BreCompile*)(malloc(sizeof ( BreCompile )));
  if (! s) {
    return 5;
  }
  memset(s, 0, sizeof ( BreCompile ));
  s -> active = - 1;
  s -> limits = limits;
  memcpy(s -> source, pattern, length);
  s -> source [ length ] = 0;
  p = (MaiaBreProgram*)(calloc(1, sizeof ( MaiaBreProgram )));
  if (! p) {
    {
      free(s);
      return 5;
    }
  }
  s -> program = p;
  MaiaBreGenerated_maiaCCLexerStateInit__pvpvN12unsigned_int(& lexer, s -> source, length);
  if (! MaiaBreGenerated_maiaCCLexerTokenize__pvpvN12unsigned_int(& lexer, s -> tokens, 1025)) {
    {
      r = lexer . failed == 2 ? 5 : 2;
    }
  } else {
    {
      MaiaBreGenerated_MaiaCCParseEvents events;
      MaiaBreGenerated_MaiaCCParserState parser;
      int parsed;
      events . context = s;
      events . checkpoint = bre_checkpoint__pv;
      events . restore = bre_restore__pvN12unsigned_int;
      events . startNonterminal = bre_start__pvpvN12unsigned_int;
      events . terminal = bre_terminal__pvN12unsigned_intpvN12unsigned_intN12unsigned_int;
      events . endNonterminal = bre_end__pvpvN12unsigned_int;
      events . abortNonterminal = bre_abort__pvpvN12unsigned_int;
      events . matchesContextual = 0;
      MaiaBreGenerated_maiaCCParserStateInit__pvpvN12unsigned_intpv(& parser, s -> tokens, lexer . tokenCount, & events);
      parsed = MaiaBreGenerated_maiaCC_parse__pv(& parser);
      if (parser . resourceError == 1) {
        r = 5;
      } else {
        if (parser . resourceError == 2) {
          r = 4;
        } else {
          if (s -> overflow || s -> depth_overflow) {
            r = 4;
          } else {
            if (! parsed || parser . failed || parser . position != lexer . tokenCount || s -> active >= 0 || ! s -> count) {
              r = 2;
            } else {
              {
                p -> code_capacity = length * 2 + 16;
                if (p -> code_capacity > limits -> max_instructions) {
                  p -> code_capacity = limits -> max_instructions;
                }
                p -> range_capacity = length * 2 + 16;
                if (p -> range_capacity > limits -> max_ranges) {
                  p -> range_capacity = limits -> max_ranges;
                }
                p -> code = (BreInstruction*)(malloc(p -> code_capacity * sizeof ( BreInstruction )));
                p -> ranges = (BreRange*)(malloc(p -> range_capacity * sizeof ( BreRange )));
                if (! p -> code || ! p -> ranges) {
                  r = 5;
                } else {
                  r = bre_lower__pv(s);
                }
              }
            }
          }
        }
      }
    }
  }
  if (! r) {
    {
      p -> magic = 0x4D425231U;
      p -> storage_bytes = sizeof ( MaiaBreProgram ) + p -> code_capacity * sizeof ( BreInstruction ) + p -> range_capacity * sizeof ( BreRange );
      * output = p;
    }
  } else {
    maia_bre_free(p);
  }
  free(s);
  return r;
}

/* Lowering diagnostics: 111 event(s) (ast-c89-body=110, structured-cstyle-body=1) */
/* - MaiaBreGenerated_maiaCCParserTokenName: structured-cstyle-body (raw-body 31 line(s)) */
/* - MaiaBreGenerated_maiaCCLexerStateInit: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCCLexWhitespace: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCCLexDecode: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCCLexMatch: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCCLexerTokenize: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCCLexMatchesContextual: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCCParserStateInit: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCC_peek: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCC_recordError: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCC_checkpointEvents: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCC_restoreEvents: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCC_startNonterminal: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCC_endNonterminal: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCC_abortNonterminal: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCC_emitTerminal: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCC_matchToken: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCC_matchContextualToken: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCC_expectToken: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCC_expectContextualToken: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCC_parse: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCC_parse_Input: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCC_parse_Sequence0: ast-c89-body (ast-c89-statements) */
/* - MaiaBreGenerated_maiaCC_parse_Piece0: ast-c89-body (ast-c89-statements) */
/* - ... 87 more event(s) */
