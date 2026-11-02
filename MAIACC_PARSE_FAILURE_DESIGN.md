# Generated parser allocation failure — owner correction proposal

2026-11-02. Status: owner correction/publication/bootstrap advancement approved (2026-11-02).

The approved BRE API distinguishes NOMEM from BADPAT. Fault injection at the
418th allocation of compiling `\(a*\)*\1` returns BADPAT for valid syntax. The
allocation is the generated parser's failure-memo calloc, not BRE lowering.
An isolated probe excludes both new BRE semantic compiler and matcher:

```
node scripts/build-bre-native.mjs
clang++ -std=c++98 -pedantic-errors -I. tests/bre/parser-allocation.cpp build/bre/ordered.o -o /tmp/maia-bre-parser-allocation
/tmp/maia-bre-parser-allocation
```

Observed with pinned generator df4c3b5:

```
valid pattern; rejected memo calloc: accepted=0 failed=1 errors=0 position=0
malformed pattern; successful calloc: accepted=0 failed=1 errors=53 position=0
```

Generated `maiaCC_parse` uses `failed=1` for overflow, allocation failure and
syntax failure. Its failureMemo is null both before allocation and after normal
cleanup. Error counters describe parsing, not a documented resource status.
Inferring allocation failure from incidental counters, replacing calloc through
production global hooks, or editing generated sources would violate the approved
contract. Current allocation test intentionally remains failing.

## Smallest owner change for review

In principal MaiaCC's C++98 backend template, add an explicit resourceError field
to generated MaiaCCParserState, initialized/reset to zero. Preserve failed as a
boolean and all existing parsing behavior. Set resourceError to named NOMEM and
LIMIT statuses when memo allocation or checked size multiplication fails. Syntax
failure leaves resourceError zero. Generate/update the self-hosted template
assets through their normal generator. Do not hand-edit assets.

Test valid/invalid parsing, injected memo allocation failure, checked-overflow
path, reset/reuse and collector rollback in generated native C++98, MaiaCpp strict
C89 and own-chain WASM. Compare JavaScript-generator and self-hosted generator
artifacts and run unchanged MaiaCC regressions/bootstrap gates.

After validation, publication and a separately reviewed bootstrap advancement
are required before principal Regex can consume this correction through its
pinned tools/maiacpp. Follow the synchronization protocol and verify published
recursive pins. No dirty dependency checkout or local generator fallback.

This proposal does not authorize compiler edits, publication, toolchain pin
changes, shell integration, npm or versions. Existing Regex and consumer sources
remain untouched. The BRE implementation can continue independent native/WASM,
semantic and resource tests while this owner decision is pending.

## Authorization and progress

The owner explicitly approved this correction, tested commit/push and protocol
propagation through an explicit bootstrap advancement. MaiaCC4cf1083 is published;
118 owner tests/native bootstrap pass, with32 focused resource assertions.
MaiaWASM9a1c1ce is published after its suite passed. Downstream propagation and
the guest resource fixture remain in progress; no consumer acceptance is inferred
from native owner tests. No MaiaRegex/MaiaOS publication is authorized.
