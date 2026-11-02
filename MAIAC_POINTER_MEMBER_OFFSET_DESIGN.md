# Pointer member subtraction — owner correction proposal

2026-11-02. Reproduced in pinned MaiaC bd19cac. Owner correction and tested publication/propagation approved (2026-11-02).

The syntax-parity test adapter needs original byte offsets for generated tokens,
whose start/end are deliberately UTF-16. An ordinary C89 expression subtracting
its `const char*` token.value from the source array fails in MaiaC with
`Integer minus pointer is not supported yet (additiveExpression)`. Strict Clang
C89 accepts the same expression. This is separate from the NOMEM signal in MaiaCC.
No production BRE workaround was introduced. The approved owner correction
is published as MaiaC6c01465; see IMPLEMENTATION_STATUS.md for tested propagation.

Minimal standalone input: tests/bre/pointer-offset.c. It has one struct, one
static struct array, one static source array and one function. It does not
include any generated parser, BRE implementation or runtime.

```
clang --target=wasm32-unknown-unknown -std=c89 -pedantic-errors -ffreestanding -fsyntax-only tests/bre/pointer-offset.c
```

Compile its text through tools/maiacpp/maiac/compiler/c-compiler.js compileSource
with validate:true and serializeParseTrees:false to reproduce the failure.

Proposed owner scope: correct inferred pointer type for a pointer-valued member
of a struct array element, preserving C pointer-difference result scaling and
signedness. Regress C89 and emitted C++98 cases for char*, int*, start/end offsets,
nonzero subscripts, global/static/local struct arrays, native-versus-WASM results,
and still reject genuine integer-minus-pointer expressions. Run existing owner
suites; publish only after passing, then advance the bootstrap by protocol along
with the separately proposed MaiaCC correction. No versions, npm, shell edits,
rewriting history, consumer fallback or hand-editing emitted C89.

The production BRE compiler/executor WASM already passes its own tests without
this expression. Its acceptance is still incomplete. Exact frontend byte-span
comparison is currently blocked by this test-adapter compile failure. The prior
frontend WASM binary predates byte-span accessors and must not be presented as
current passing evidence.

## Authorization and progress

The owner approved this fix and its tested publication/propagation up to the
MaiaRegex bootstrap. The principal MaiaC implementation resolves the selected
member for pointer identity/stride and retains that metadata through derived
additive expressions. Focused C89 native/ASan/UBSan/WASM:20 positive and2 negative
cases pass. Full suite/example validation and publication are still in progress.
No compiler implementation changes were made in downstream dependency checkouts.
