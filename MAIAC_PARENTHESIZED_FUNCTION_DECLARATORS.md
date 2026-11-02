# Parenthesized function identity — owner correction proposal

2026-11-02. Reproduced in published MaiaC6c01465. Owner correction specifically authorized on 2026-11-02. MaiaC9793ab9 is
validated and published; tested propagation is complete through MaiaCppa638403,
MaiaJS40bdb8a and the exact Regex bootstrap lock. The guest fault gate passes
420 compile +10 execution allocation sites with NOMEM, atomic outputs/no leaks.

The original isolated guest allocator-fault module could not pass validation: a
parenthesized function prototype and its ordinary definition create duplicate
exports for the same internal function. Native fault injection and production
BRE guest matching/resources passed; the fault-guest gate was initially blocked.

Minimal C89 input, independent of macros/BRE/generated code:

```
void (release)(void *pointer);
void release(void *pointer) { (void)pointer; }
int test_entry(void) { release(0); return 7; }
```

Source: tests/bre/parenthesized-function.c. Strict Clang C89 accepts it. Compile
via principal MaiaC compileSource with validate:true/serializeParseTrees:false:
no valid wasm, validationError `Duplicate export name 'release' for function 0
and function 0`. The fault unit gets this valid C89 form from identity-only
allocator macro aliases. This is a source identity defect, not a missing import,
not BRE syntax and not a memory-failure expectation to relax.

## Smallest proposed owner fix

In principal MaiaC normalize redundant parentheses in named function declarators
before reconciling prototypes/definitions and publishing exports. The declaration
and definition must resolve to one semantic function, one body and one export.
Preserve call binding, pointer/function-pointer distinctions, storage/linkage and
existing incompatible-declaration diagnostics. Do not merely hide duplicate
export rows while leaving conflicting function identities in the semantic model.

Regression matrix: prototype/definition orders, ordinary/parenthesized/nested
parentheses, repeated compatible prototypes, direct calls and callback pointers,
actual once-only side effects, static controls and incompatible declarations.
Compare strict native C89/ASan/UBSan with own-chain WASM. Run full owner suite and
required example. After tests, publish and propagate through MaiaCpp/MaiaJS in
protocol order, including explicit tested advancement of the Regex bootstrap;
rerun its guest fault gate and required consumer/full-bootstrap checks.
No npm/version/history, shell integration or Regex/MaiaOS commit/push.

No source-style workaround was introduced. The approved semantic correction
was made in the owning MaiaC principal. The original raw failure remains recorded in /tmp/maia-bre-guest-fault-build.log.
The test harness separately preprocesses library instrumentation and real runtime
units with the published MaiaC preprocessor to preserve macro boundaries; it
never substitutes a host parser/matcher or installs production allocator hooks.

## Validated result

MaiaC9793ab9 follows the declarator spine through transparent grouping and stops
at the first binding pointer/suffix. Its39 positive and5 negative strict native
C89/ASan/UBSan/WASM cases, full suite plus13 extras and example passed. MaiaCpp
default tests and complete three-generation guest bootstrap passed (both
emitters/seven grammars/27 growths). MaiaJS full suite passed after its updated
gitlinks were recorded; its documented native/JS course exclusions remain.
The five unique historical bootstrap pins are published/reachable, all16
checkouts clean. No root Regex/OS commit, version, npm or shell integration.

The new fault module validates at1,438,205 bytes. Every instrumented allocation
site passes fault injection; measured guest peaks are285,316 compile/17,384
temporary execution bytes. Library instrumentation remains test-only and uses
the actual guest allocator. The previous failing log is retained separately;
new logs are /tmp/maia-bre-parenthesized-fault-{build,sweep}.log.
