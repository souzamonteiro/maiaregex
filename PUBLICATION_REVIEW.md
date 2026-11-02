# BRE publication review

2026-11-02. Explicitly approved by the owner; publication in progress. This is a Git publication;
no npm/release version change, history rewrite or shell execution change.

## Proposed MaiaRegex commit

Include the additive API/runtime/compiler (`maia_bre.h`, `maia_bre.c`,
`maia_bre_compile.cpp`, `maia_bre_internal.h`, `maia_bre_history.h`), authoritative
`grammar/bre.ebnf`, reproducible sources in `generated/`, `scripts/`, `tests/bre/`,
`.gitmodules`, the exact published `tools/maiacpp` gitlink/bootstrap-lock,
Makefile/ignore/README and the BRE design, evidence and owner-fix review notes.
The legacy and ordered engines and their existing production artifacts remain
byte-identical. Test executables, temporary files and build/ stay excluded.
Generated C89 is a wasm32 artifact; native compilation uses C++98 sources.

## Verified acceptance

See IMPLEMENTATION_STATUS.md for commands and exact limits: native C89/C++98,
ASan/UBSan/API/concurrency;1,591 fixed vectors;68,326 independent finite model
cases;1,533 independently adjudicated reference cases;8,818 guest resource
checks;51 complete JS/native/guest frontend traces;420 compile+10 execution
allocation-fault sites; byte-for-byte generated-source reproduction. Regular
and frontend guest hashes remain stable after the published compiler fixes.
The raw libc diagnostic still exits1 for163 differences in three documented
families; they are independently adjudicated, not hidden. This is the selected
UTF-8/ASCII-class profile, not full locale/POSIX/VM/device conformance.

## Propagation after approval

Publish principal MaiaRegex first, then synchronize/test/publish affected
principals in protocol order: MaiaCC, MaiaWASM, MaiaC, MaiaCpp, MaiaJS, MaiaGlob.
Wait for each git_pull completion; review recursive published pins and record
consumer gitlinks before testing. The development tools/maiacpp submodule has
`update = none`; its local Git regression passed, including explicit exact-pin
initialization and a newer remote descendant that must stay unconsumed. The Regex development bootstrap remains at
its exact reviewed historical lock; do not recursively advance it to follow a
consumer that now embeds this new Regex. Historical dependencies must terminate.

MaiaOS's unrelated uncommitted shell/kernel/I/O work remains preserved. No root
MaiaOS commit/push is part of this publication review. Consumption and expr
execution require their concrete approved contract. Source publication does
not imply npm publication or approval for a compiler implementation change.

Diff review:55 task-owned files; no temporary binaries/caches are staged.
Authored whitespace checks pass. Seven trailing-whitespace lines in the untouched
MaiaCC JavaScript generator output are retained for byte-for-byte reproduction;
the generated parser is never hand-formatted. All old production hashes match.
