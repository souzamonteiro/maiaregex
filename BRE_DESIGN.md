# Additive UTF-8 BRE API — approved contract

Date: 2026-11-01. Status: selected implementation validated; Git publication/propagation approved (2026-11-02).
Owner: principal MaiaRegex, main e2ae3a8efa3601e78c3c3c75cf917acf76078e84.
Purpose: supply the regex facilities needed by expr and future text utilities.
The owner requested expansion of MaiaRegex. This document makes the new API,
matching profile, bootstrap dependencies and acceptance criteria reviewable.
Implementation approval does not authorize publication or consumer gitlinks.

## Compatibility boundary

Leave maia_regex.h/maia_regex.c and their ordered-program ABI/algorithm unchanged.
Existing generated lexers keep ordered first-success matching, UTF-16 offsets,
cycle/memoization semantics and existing limits. Do not add captures or longest
selection by changing the meaning of existing instructions or exec calls.
The legacy regex.h/regex.c API and its existing behavior/tests remain unchanged.

Add maia_bre.h with a separate C ABI, a C89 executor and a freestanding C++98
compiler/frontend. Its authoritative BRE EBNF generates JS and C++98 exclusively
through MaiaCC/tREx; no handwritten text parser, libc-regex delegation, host regex,
pattern-to-JavaScript conversion or generated-file patching. The semantic compiler
lowers generated trees to private immutable instructions. Matching is iterative,
with explicit work/state bounds, no recursive C execution or shared scratch state.
Document this as the profile below, not full POSIX/locale/ERE/PCRE conformance.

## Selected BRE profile

- Concatenation, scalar literals, dot, anchors and positive/negative brackets.
- Repetition *, escaped intervals \{m\}, \{m,\}, \{m,n\}, bounds0..255.
- Up to nine numbered groups \(...\) and backward references \1..\9 to groups
  already closed. Reject forward, undefined and still-open references.
- Plain +, ?, |, (, ), { and } are literals in the BRE positions where they have
  no special meaning. No GNU \+/\?/\| extensions in this increment.
- Anchor placement and initial literal * follow the selected BRE rules; the
  generated grammar must own context. No keyword/escape/source counters as a
  substitute parser. Reject malformed intervals, groups, classes and escapes.
- Twelve named bracket classes have explicit ASCII/C membership. Literal Unicode
  and ranges use scalar ordinal values. Locale-dependent collating/equivalence
  elements, Unicode categories/case folding and normalization remain unsupported.
- Match empty expressions/groups as empty text in this project profile; record
  this as a portability choice. The local system libc rejects an empty BRE.

Input/pattern buffers are explicit-length, strictly valid UTF-8. Reject overlong,
truncated, surrogate and out-of-range encoding before successful compilation or
matching. Embedded NUL is outside this text profile (ARGUMENT, not ENCODING).
Dot consumes one Unicode scalar, including LF; anchors refer to the complete
input buffer. No implicit multiline/newline flags, locale mutation or host ctype.
Ranges/classes never consume half a UTF-8 encoding. Combining marks are separate
scalars; a supplementary character counts as one. These are not grapheme counts.

## Match and capture semantics

SEARCH chooses the earliest scalar boundary at or after start_byte, then the
longest whole match at that boundary. ANCHORED tries only start_byte. An interior
byte of a UTF-8 scalar or offset beyond length is ARGUMENT. Anchor ^ still means
absolute buffer start, even with a later start_byte. Empty matches at EOF exist.
A future expr passes ANCHORED/start0; do not rewrite its pattern by inserting ^.

At equal whole-match extent, prefer earlier/higher-level subexpressions under
the selected POSIX subexpression rule. Preserve capture histories where required;
a final capture-vector comparison alone is not accepted without proof on nested,
repeated and empty-capture ambiguity. Report the last participating repetition
for a repeated group. Unmatched groups differ from matched empty groups.
Backreferences compare the exact captured scalar sequence/UTF-8 bytes, without
normalization; a reference to a nonparticipating group fails the path, while a
reference to an empty participating group consumes zero characters.

Do not reuse ordered first-success as a longest matcher. Any memoization must
include capture/loop context sufficient for both references and tie resolution;
(pc,position) alone is unsound. No polynomial/linear-time guarantee is claimed.
A budget exhausted after finding a candidate is still LIMIT, not partial success.
Termination guards for zero-progress repetition must preserve empty captures and
references. Search restarts, alternative paths, references, capture comparisons
and cycle handling share a single execution budget; never reset it per candidate.

## Approved public interface

Use a distinct namespace and opaque immutable compiled program:

```c
typedef struct MaiaBreProgram MaiaBreProgram;
typedef struct MaiaBreLimits {
    unsigned int max_pattern_bytes, max_input_bytes;
    unsigned int max_instructions, max_ranges, max_captures;
    unsigned int max_repeat, max_parse_depth, max_frames;
    size_t max_steps, max_workspace_bytes;
} MaiaBreLimits;
typedef struct MaiaBreCapture {
    unsigned int matched;
    unsigned int start_byte, end_byte;
    unsigned int start_scalar, end_scalar;
} MaiaBreCapture;
typedef struct MaiaBreInfo {
    unsigned int capture_count, instruction_count, range_count;
    size_t storage_bytes;
} MaiaBreInfo;

void maia_bre_default_limits(MaiaBreLimits *out);
int maia_bre_compile_utf8(const unsigned char *pattern, unsigned int length,
    const MaiaBreLimits *limits, MaiaBreProgram **out);
int maia_bre_info(const MaiaBreProgram *program, MaiaBreInfo *out);
int maia_bre_exec_utf8(const MaiaBreProgram *program,
    const unsigned char *input, unsigned int length, unsigned int start_byte,
    unsigned int mode, const MaiaBreLimits *limits,
    MaiaBreCapture *captures, unsigned int capacity);
void maia_bre_free(MaiaBreProgram *program);
```

Header includes stddef.h and C++ extern-C guards. Status constants: OK=0,
NOMATCH=1, BADPAT=2, ENCODING=3, LIMIT=4, NOMEM=5, ARGUMENT=6, UNSUPPORTED=7,
all prefixed MAIA_BRE_. Modes MAIA_BRE_SEARCH=0 and MAIA_BRE_ANCHORED=1.
Successful compilation/info use OK; successful matching also uses OK. Unknown
modes, null required objects and invalid limit descriptors are ARGUMENT.
Unsupported recognized dialect/locale constructs return UNSUPPORTED, malformed
selected-profile syntax BADPAT. Distinguish allocation failure from quota failure.

Supply nonnull finite limits. Default profile: pattern1024bytes,input65535bytes,
4096instructions,4096ranges,9captures,repeat255,parse-depth9,4096frames,
1,000,000execution steps and1MiB managed workspace. Positive values are required;
requests beyond implementation ceilings return LIMIT, not silent clamping.
These independent ceilings do not promise every maximum-size combination fits.
The shell will need its own smaller measured profile in a later integration.

max_steps/max_workspace_bytes cover the new executor and new semantic compiler's
managed work. They must not be advertised as hard total CPU/heap bounds on the
existing generated lexer or runtime. Its temporary allocations/parser work are
separately bounded by finite pattern/token/tree/depth envelopes and must have
measured peaks and overflow/failure checks. Document both contributions. If a
new owner API is needed to control them, reproduce and request that change;
do not silently add global allocator hooks or weaken the stated budget.

The BRE grammar must bound group nesting to nine before recursive generated
parser descent can overflow; use finite-depth generated productions, not a
handwritten group scanner or a post-parse check alone. Caller limits smaller
than the grammar ceiling are validated before lowering/execution. All size/count
products are checked before allocation/writes. Match state/capture histories stay
within the workspace/frame budgets; release all temporary allocations on every
success/error/limit path. No exceptions, STL or C++11 facilities in new code.

Compile success returns a new owned program; failures leave *out unchanged.
The program retains no caller pattern/input pointer and may be shared across
independent concurrent exec calls. Free(NULL) is safe; callers own lifetime.
Info failures leave output unchanged. Exec outputs remain unchanged on any
non-OK result. On success slot0 is the whole match,slots1..9 are numbered groups;
write at most capacity slots (0..10); capacity>10 is ARGUMENT. Unmatched/unused slots use matched0 and
zero offsets; matched empty groups use matched1 with equal boundaries. Internal
capture tracking remains complete even when caller requests fewer output slots.
Offsets are absolute in original input; both scalar and byte endpoints are
exclusive. The caller allocates the output array; capacity>0 requires its pointer.

## Bootstrap and build ownership

Add one development-only tools/maiacpp submodule pinned initially to published
84758122c62307d59e765b003bc821d74ae68455. Use its in-repository maiacc generator
(df4c3b5b7d17832cf0a94658cd89f2359fe2d71c) and complete compiler chain. Verify
those pins and recursive objects in their intended remotes before adding them.
No sibling checkout, vendored ad hoc parser or implicit system compiler fallback.
Native Clang is an independent oracle; WASM comes from the pinned Maia Suite.

That bootstrap generator/compiler already pins the old Regex e2ae3a8. Keep this
bootstrap pin fixed: it is a finite historical dependency graph, not a toolchain
that follows the newly built Regex back into itself. Recursively audit every
bootstrap gitlink; fail on a missing/unpublished pin. Do not upgrade bootstrap
as an incidental propagation step. Advancing it is a separate reviewed change.
The development submodule declares `update = none`, so normal recursive consumer
updates skip it. Explicit `git submodule update --init --checkout --recursive
tools/maiacpp` initializes exact historical pins. The Git policy regression checks
that normal remote recursion cannot enter or move those descendants.

Preserve authored EBNF/compiler sources and generated JS/XML/C++98 adapters and
reproducible strict C89 artifacts as needed for C89 distribution. Ordinary C89
users must not need a C++11 toolchain or runtime dependency on MaiaCC. Makefile
adds explicit generation/new BRE targets without changing old test flags or
removing old library objects/tests. New artifacts are produced by scripts, not
edited by hand; temporary binaries/caches remain out of commits.

## Acceptance gates

- [x] JS grammar first: independent token/span/tree fixtures for all profile
  features/context and invalid/unsupported/depth-bound cases; exact parity with
  generated C++98 and actual strict-own-chain C89/WASM. Reproduce artifacts.
- [x] Native C89/C++98 ASan/UBSan and own-WASM compiler/executor cases for all
  syntax, all9capture IDs, backreferences, repeated/empty/nested captures,
  whole-match/subgroup ambiguity, search/anchors, start boundaries and no-match.
- [x] Independent libc regcomp/regexec ASCII/C-profile comparison and fixed
  expected Unicode byte/scalar vectors. Keep empty BRE/undefined syntax/locale
  differences separate; do not derive expected results from the new matcher.
- [x] Invalid UTF8/NUL,255/256 repeat limits,9/10 groups/depth,exact token/tree/
  instruction/range/frame/step/workspace bounds; canaries,allocation failures,
  overflow,optimality not yet proven on LIMIT and untouched outputs on failures.
- [x] Differential bounded exhaustive grammar/input/capture corpus and fuzzing;
  deterministic results,zero-progress termination,concurrent/reused programs,
  source mutation after compilation and stable memory/resources after free.
- [x] Run unchanged make test (legacy and all ordered dense/sparse/memo/resource
  checks); compare native/WASM old ordered behavior on existing regressions.
  Preserve all old production source hashes and every old semantic expectation.
- [x] Record native/own-WASM performance,peak scratch and generated-front-end
  allocation/depth measurements for representative and adversarial profiles.
  No universal speed/complexity/embedded-memory claim without evidence.
- [x] Review exact diff,license/provenance,generated reproducibility,toolchain
  bootstrap graph and whole indexes. Update README and implementation evidence.

The original implementation approval excluded MaiaCC/MaiaC/MaiaCpp/other owner source changes, existing ordered/legacy API
changes, shell integration, kernel/I/O/worker changes or downstream gitlink
updates were part of that original approval. Subsequent explicit owner approvals and
Git publication authorization are recorded in IMPLEMENTATION_STATUS.md. No npm,
versions or history changes. If an owner defect prevents the specified build, request its
separate correction with a minimal reproduction. After local acceptance, obtain
publication approval and propagate tested published pins before consumers use it.

## Preparation evidence — 2026-11-01

Before preparation, principal Regex main e2ae3a8 was clean. Unchanged make test passes:38 ordered-program
checks,100000 independent DFS/dense/sparse comparisons,16384 resource comparisons,
sparse allocation/collision/budget tests and both legacy suites. Log:
/tmp/maia-bre-baseline.log. No old artifact was rebuilt or modified.

A separate C89 probe against system libc passes11 fixed ASCII/C-locale capture
vectors (longest whole match,earlier-group priority,repeated/empty captures,
backreferences,intervals,classes,search/no-match). It separately records that
system libc rejects an empty expression. Reproducer:
clang -std=c89 -pedantic-errors -Wall -Wextra /tmp/maia-bre-native-reference.c -o
/tmp/maia-bre-native-reference; run that binary. Log:
/tmp/maia-bre-native-reference.log. This validates reference expectations only;
no new MaiaRegex API/parser/matcher or WASM implementation exists yet.

Preparation touches only this proposal and linked README/MaiaOS planning/handoff
notes. Full file/index/HEAD baselines:/tmp/maia-bre-proposal-before.json. No
production source,bootstrap checkout/gitlink,consumer pointer or publication.

Reference material:

- [OpenBSD regex format](https://man.openbsd.org/re_format.7): BRE/capture and
  longest-selection reference; implementation-specific cases remain explicit.
- [GNU grep regex manual](https://www.gnu.org/software/grep/manual/grep.html):
  reference/capture behavior and dialect distinctions,not authorization to add
  GNU extensions or locale dependencies.
- [Current program semantics](PROGRAM_SEMANTICS.md) and [README](README.md):
  the ordered API contract that this additive API must preserve.
- [Maia synchronization protocol](../maiaos/docs/Maia_Ecosystem_Synchronization_Protocol.md)
  and [engineering instructions](../maiaos/AGENTS.md).

## Implementation checkpoint — 2026-11-02

Approved implementation and the subsequent owner corrections are exercised
through published prerequisites and the explicitly advanced bootstrapa638403.
[Current evidence](IMPLEMENTATION_STATUS.md) records1,591 fixed vectors,68,326
finite AST comparisons,1,533 independent arithmetic/native/guest reference cases,
8,818 guest resource checks and51 complete frontend parity cases. Hierarchical
capture histories fix the added overlapping-repeat counterexample; see
BRE_CAPTURE_SELECTION.md. The raw libc differences remain explicitly adjudicated,
not erased. Original ordered/legacy sources and semantics remain untouched.

The final guest allocator-fault gate now passes420 compile +10 execution sites,
with NOMEM, atomic outputs and no leaks. The separately approved MaiaC named
function identity correction is published as9793ab9 and propagated through
MaiaCppa638403/MaiaJS40bdb8a. Owning full suites and the complete three-generation
guest bootstrap pass. All16 bootstrap checkouts are clean, exact lock, five
unique published pins verified reachable from intended live remotes.

The selected implementation/acceptance profile passes in the working tree.
This is not a full POSIX/locale, VM/device/browser or shell/expr integration
claim. No Regex/OS publication or npm/version/history change occurred. Initial
bootstrap8475812 advanced explicitly through2b964ce toa638403; the finite
old-Regex dependency graph remains fixed until another reviewed advancement.
