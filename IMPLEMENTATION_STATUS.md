# MaiaRegex BRE — implementation and validation checkpoint

Reviewed: 2026-11-02. Principal main e2ae3a8. New library sources/artifacts remain
uncommitted. No Regex/MaiaOS publication, npm/version/history or shell integration.
The selected BRE API/bootstrap was approved, followed by the two owner fixes and
their tested publication/propagation. The separately approved parenthesized
function correction is now published and propagated; the final guest allocator-
fault gate passes. Publication and downstream integration remain excluded.

## Published prerequisites

| Principal | Published main | Evidence |
| --- | --- | --- |
| MaiaCC |4cf1083|118 tests; native bootstrap/emitter parity;32 focused resource assertions|
| MaiaWASM |9a1c1ce|Full npm test after published MaiaCC synchronization|
| MaiaC |9793ab9|Pointer regression20 positive/2 negative; function identity39 positive/5 negative C89 native/ASan/UBSan/WASM; full suite plus13 extras; example rebuilt/validated23,395bytes|
| MaiaCpp |a638403|Default suite;32 resource assertions x50 guest calls; pointer regressions; complete3-generation MaiaCC guest bootstrap, both emitters/seven grammars,27 memory growths|
| MaiaJS |40bdb8a|Complete test:full after all four direct gitlinks recorded;11 C++/11 JS suite cases,48 course WASM programs and distribution example|

Intermediate pointer-only commits follow protocol. MaiaJS's first full test passed
before its direct MaiaWASM pointer was recorded; the complete second round is the
publication evidence. Its46 tracked manifests only changed generated timestamps
and temporary input paths (JSON equality reviewed excluding those two fields).
Its unchanged course harness reports48 missing native output references and48
missing JS ports; those are not independent native/JS comparisons.

The explicitly approved Regex bootstrap advancement now pins MaiaCppa638403, including MaiaC9793ab9.
All16 recursive checkouts are clean, lock exact, and five unique pins verified
reachable from live intended remotes. Historical dependencies still terminate in
old Regexe2ae3a8; they do not follow the new uncommitted BRE library. Root Regex
has no git_pull.sh; explicit authorized recursive submodule update was used.
Only .gitmodules/tools/maiacpp are staged; no root commit was created.

## Implemented and functionally validated within the selected profile

- [x] Authoritative finite-depth grammar/bre.ebnf and JS/C++98/XML generated
  exclusively by pinned MaiaCC, with generated identifier adapters.
- [x] Separate C ABI, C++98 semantic compiler and iterative C89 UTF-8 executor:
  literals/classes/anchors,12 ASCII classes, intervals,9 groups/references,
  search/anchoring, byte/scalar spans and atomic outputs.
- [x] Hierarchical scope histories select longest whole extent and subgroup
  priority, including overlapping repeated bodies. Complete histories, not final
  capture vectors or first-success order, determine ties. Per-call persistent
  nodes share/reclaim prefixes by refcount; all operations are iterative/bounded.
- [x] Native and own-chain WASM pass1,591 fixed vectors, including all9 capture
  IDs and all9 backward references, UTF-8 offsets, empty/unmatched groups,
  malformed/unsupported syntax and the added overlap counterexample.
- [x] Independent finite AST interpreter passes538 authored/seeded trees over all
  binary inputs length0..6:68,326 guest comparisons of whole match/captures.
- [x] Independent arithmetic decompositions pass1,533 native AND guest vectors
  for the three libc-discrepancy families. Raw libc comparison:41,148 cases,
 163 visible differences in exactly31/64/68 reviewed cases; no other families.
- [x] JS/native/guest exact tokens, raw UTF-16 spans, original UTF-8 byte spans
  and complete collector trees on51 cases. Maximum retained successful rule-event
  depth41; this is not a native C-stack byte measurement. Grammar unroll bounds
  descent before the10th group; status/depth cases are checked separately.
- [x] Native strict C89/C++98 ASan/UBSan:467 public API checks,1,591 vectors and
  four threads /2,000 shared-program executions after source mutation.
- [x] Native allocation sweep:420 compile +10 execution sites, correct NOMEM,
  unchanged outputs/program pointer and no leaks. This includes history/sort
  growth. The old parser-memory BADPAT result is corrected via resourceError.
- [x] Guest resources:8,818 checks, including invalid UTF-8/NUL, capacities,
  descriptor ceilings, instruction/range/group/depth/repeat/frame/step/workspace
  limits, failed optimality search,1024-byte pattern/65535-byte input and65536
  rejection.500 compile/execute/free cycles stable at19 memory pages.
- [x] Generated JS/C++98/XML/adapters and wasm32 C89 compiler reproduce byte for
  byte. Authored sources and generation commands are retained.
- [x] Unchanged make test passes:38 ordered checks,100,000 DFS/dense/sparse
  comparisons,16,384 resource comparisons, sparse tests and both legacy suites.
  Unchanged ordered source also passes38 checks through actual MaiaC/MaiaWASM.
  All old production sources/artifacts retain baseline hashes.

## Final guest acceptance gate — passed

- [x] Isolated guest allocation-fault module: the approved MaiaC parenthesized
  function identity fix9793ab9 is published and propagated. The valid C89 named
  function prototype now resolves to the same function as its definition, with
  one semantic body/export and no falsely global object. The owner regression
  has39 positive/five negative cases; its full suite/example and complete
  consumer bootstrap passed. See MAIAC_PARENTHESIZED_FUNCTION_DECLARATORS.md.
- [x] Actual instrumented guest sweeps420 compile +10 execution allocation sites:
  NOMEM, unchanged output/program pointer, intact retained allocation and zero
  leaks/invalid frees. Measured guest peaks:285,316 bytes compiling /17,384
  temporary bytes executing. Native values below are separate ABI measurements.

The harness uses the actual published C preprocessor/stdlib and separately
preprocesses instrumented library/runtime translation units to preserve macro
boundaries. There is no host parser/matcher or production allocator hook.
Logs:/tmp/maia-bre-parenthesized-fault-{build,sweep}.log. The old failed build
log is historical evidence, superseded by this successful guest sweep.

- [ ] Regex publication/downstream library consumption and shell/expr integration
  require separate authorization; excluded from the approved work.

## Reproduce

From principal MaiaRegex:

```
node scripts/check-bre-bootstrap.mjs --remote
node scripts/generate-bre.mjs
node scripts/test-bre-syntax.mjs
node scripts/build-bre-native.mjs
./build/bre/api
./build/bre/concurrent
node scripts/test-bre-frontends.mjs
node scripts/test-bre-matching.mjs
node scripts/test-bre-reference.mjs --native-only
node scripts/build-bre-native.mjs --sanitize
./build/bre-sanitize/api
./build/bre-sanitize/concurrent
node scripts/test-bre-matching.mjs --sanitize
node scripts/test-bre-allocation.mjs
node --max-old-space-size=16384 scripts/build-bre-wasm.mjs
node scripts/test-bre-matching.mjs --wasm
node scripts/test-bre-model.mjs
node scripts/test-bre-reference.mjs
node scripts/test-bre-resources.mjs
node --max-old-space-size=16384 scripts/build-bre-wasm.mjs --frontend
node scripts/test-bre-frontends.mjs --wasm
node scripts/test-bre-ordered-wasm.mjs
node scripts/check-bre-generated.mjs --compiler
make test
```

The final fault gate is reproduced with `node scripts/build-bre-fault-wasm.mjs`
and `node scripts/test-bre-fault-wasm.mjs`; both now pass.
The raw build/bre/system-reference
still exits1 for the documented observations; the integrated reference gate
runs it visibly and checks independent arithmetic expectations plus exact known
families. No discrepancy or changed observation is silently discarded.

## Artifacts and practical limits

Final regular guest probe:1,307,363bytes, SHA256
`7b4790807c531559d061cc40f42d9e1130fec3f2657b492056d01bdd84ac4907`.
Frontend probe:1,416,196bytes, SHA256
`773d4f93c0040e6d9862cdc41e4388978b1a63fa50e866df1f8d01cf426d76d3`.
Generated wasm32 C89 compiler SHA256
`1c0d7988d9f677d75de8ed6e644552e40fd19e8ddccb570b1c5d7642e92ff1f3`.
Instrumented fault probe:1,438,205bytes, SHA256
`c7df5dfed7abd5f0573e443f296c6397eae940eafa1b10c8f0a28f8441de4abd`.
Test binaries/WASM/logs stay in ignored build/; generated production sources stay
in generated/. Native libmaiabre.a links ordinary C89 with no C++ standard
runtime; building its compiler object requires C++98. Generated C89 is wasm32,
not a portable LP64 compiler artifact. Node WebAssembly is the reference runtime;
MaiaWASMVM/device/browser integration was not run in this library increment.

Measured native compilation of `\(a*\)*\1`:364,080 peak requested heap bytes,
420 allocations,1,152 retained. Its twelve-a execution:19,048 peak temporary heap
bytes,10 allocations. A1024-byte literal compiles at435,528-byte peak/47,110 calls.
The generated frontend uses fixed finite token/tree/depth envelopes; these measured
profiles do not promise total CPU/heap bounds for every maximum combination.
For guest a*/aaaa the exact abstract budget threshold is29 steps and6,372 managed
workspace bytes. Histories, priority buffers, current/best/exit states and frames
share the quota; growth includes old+new arrays.500 guest representative cycles
took about1.5seconds at stable19pages on this host. No universal speed/complexity,
embedded-fit or total generated-parser allocation guarantee is claimed.

New authored code follows this repository's Apache2 convention; no libc/GNU or
legacy matcher source was copied. Both old Regex APIs/algorithms remain unchanged.
See BRE_CAPTURE_SELECTION.md, BRE_REFERENCE_DIFFERENCES.md and BRE_DESIGN.md for
selection/resource/profile details. Old engine hashes, root Regex/MaiaOS HEADs,
unrelated work and indexes are preserved except the approved bootstrap additions.

## Final owner-fix revalidation

After the explicit function-identity authorization, MaiaC9793ab9,
MaiaCppa638403 and MaiaJS40bdb8a are clean/published. Updated consumer gitlinks
were recorded before tests; the root Regex bootstrap pin/lock are advanced but
uncommitted as authorized. No new Regex/OS publication or shell integration.

Rebuilt normal and frontend modules have identical hashes to those above.
Repeated with the new chain:1,591 fixed vectors;538 AST patterns/68,326 inputs;
1,533 independent arithmetic native/guest references;8,818 resource checks and
500 cycles at stable19pages;51 frontend parity cases;38 old ordered guest checks.
Generated JS/C++98/XML/adapters/C89 compiler reproduce byte for byte. The final
instrumented fault module passes420 compile+10 execution allocation failures.

Logs:/tmp/maia-bre-parenthesized-{remotes,reproduction,fault-build,fault-sweep,
guest-build,regressions,frontend-build,frontends}.log. Old production hashes,
root Regex/OS HEADs and the complete preexisting OS index match baseline. All
six checked compiler/library principals are clean at their published main.

## Git publication authorization — 2026-11-02

The user explicitly approved PUBLICATION_REVIEW.md: Git commit/push of this
library and tested propagation through MaiaCC/MaiaWASM/MaiaC/MaiaCpp/MaiaJS/
MaiaGlob. No npm, versions, compiler implementation changes or root MaiaOS
commit/push. Publication is in progress; prior no-publication notes above
record the earlier implementation checkpoint.

Before publication, the development submodule gained `update = none` to enforce
the approved fixed historical bootstrap during consumers' `--remote --recursive`
synchronization. The local Git regression passes ordinary recursive clone,
explicit exact-pin initialization and remote recursion without moving a pinned
historical descendant. No library source, generated artifact or ABI changed.
