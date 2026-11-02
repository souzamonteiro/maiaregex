# Hierarchical capture selection and bounded histories

2026-11-02. Selected BRE profile only; not a claim of full POSIX/locale support.

An extra independent libc comparison exposed a genuine first-trace defect:
`\(aba*\)*.*` on `abaaba` has whole [0,6). The initial executor retained the
first equal-extent trace: repeated-group aggregate [0,4), capture [0,4), then
trailing dot-star [4,6). The earlier repeated piece can consume all six characters
instead: iterations [0,3), [3,6), with final capture [3,6) and empty trailing
piece. The system reference independently reports that latter capture.
The fixed vectors retain this counterexample and the corresponding two-group
form `\(aba*\)*\(.*\)`. The earlier finite a/b corpus did not cover this overlap;
it was insufficient evidence for general subgroup priority.

## Selection representation

The executor still enumerates complete paths and selects earliest start then
longest whole extent. Equal extents now compare complete scope histories. Every
group and quantified piece has a semantic preorder identity from the generated
AST. The compiler records those private identities in otherwise unused private
instruction fields; no public API or existing ordered-engine ABI changes.

Each participation opens a scope at a scalar position and closes it at another.
The repetition scope surrounds all iterations; each group participation remains
inside that outer scope. Its aggregate span is therefore compared before spans
of its iterations, including all earlier iterations rather than only final
capture slots. Successful histories become a preorder sequence of scope identity
and length. At equal whole extent, earlier/higher-level scopes prefer longer
spans. Empty participating child scopes precede absence of those scopes. Final
capture slots are copied only from the selected complete state.

This addresses the overlap counterexample because aggregate length6 beats4
before the first iteration's length is considered. It also preserves the earlier
`a*\(a*\)` behavior: the leading quantified piece has priority over the group.
For `\(a*\)*\1`, aggregate repetition extent is compared before the last group's
capture; comparing only final capture length would select the wrong path.

For this concatenation/repetition profile, these are the only ambiguous scopes:
individual literals, classes and dot consume one scalar; anchors consume zero;
a reference's value is determined by its preceding capture history. Preorder
comparison expresses parent-before-child and earlier-sibling priority directly.
An iterative heap sort of opening serials reconstructs preorder from completed
scope records. This is not `(pc,position)` memoization or final-vector ranking.
The independent test interpreter instead constructs nested scope traces from
finite AST derivations; it does not parse BRE text or read VM instructions.

## Ownership, limits and empty progress

Histories are persistent linked records. Alternative frames and the winning
candidate retain their roots; predecessor references retain shared prefixes.
Backtracking and replacing a candidate release unreachable records iteratively.
Freed slots are reused. Opening serials remain monotonic despite slot reuse, so
allocation order cannot corrupt priority. Group/repeat open indices always refer
to ancestors retained by their current history chain. There is no shared global
scratch state or recursive executor/collector cleanup.

History nodes, priority scratch buffers, current/best/exit states and alternative
frames share the managed workspace limit. Array growth accounts for old and new
buffers at the allocation peak. Scope creation, traversal, sorting and comparisons
share the same execution budget as decoding/dispatch/range/reference work. An
allocation or quota failure during ranking is NOMEM/LIMIT, with outputs unchanged,
even after a possible winning match was found. Native and guest fault sweeps must
exercise these new allocation sites before acceptance.

Existing explicit empty-progress rules stay in force: required empty iterations
remain real; a first empty participation is representable; a subsequent optional
empty iteration cannot overwrite prior participation. Captures inside a new outer
iteration are reset to unmatched until they participate again. There is no claim
that every system libc implements all empty/backreference cases identically;
reference differences remain separately recorded rather than hidden.

This note explains the selected ordering and representation. Broad finite tests,
independent fixed/reference vectors, resource/fault tests and actual own-chain
execution remain required; the explanation does not replace those gates.
