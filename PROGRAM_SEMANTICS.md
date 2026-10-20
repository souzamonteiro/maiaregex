# Instruction program semantics and cycle review

The generated-program API is strict C89 and usable from C++98. It is separate
from the legacy textual regex API. MaiaCC compiles patterns; MaiaRegex executes
the immutable tables. No ECMAScript text parser belongs in this runtime.

## Execution contract

- Input is UTF-16 code units. Start is explicit; matching does not search.
- SPLIT tries its first branch before its second. The first successful path
  determines the end offset, including greedy/lazy behavior encoded by MaiaCC.
- END means absolute buffer end, including when the last unit is a newline.
- ACCEPT succeeds at the current position. Structural validation does not
  require a reachable ACCEPT. A reachable assertion of a nonmatching program
  still has its usual positive/negative meaning.
- Reentering the same active instruction/position at the same assertion depth
  cuts that path as failure, allowing an ordered fallback for empty repetitions.
- Reentering it across an assertion boundary returns INVALID. This policy
  rejects both positive and negative recursive assertions when encountered;
  the runtime does not attempt fixed-point semantics. A cycle that consumes
  input before reentry is a different state and does not trigger this rule.
- An INVALID result is an execution error, not a failed branch to backtrack over.
  Unexecuted branches do not trigger runtime cycle checks.
- On failure or error the caller's end offset is unchanged.

## Why separate visiting state and cycle-dependent results

An in-progress state is not a completed failure. The runtime marks it VISITING
and detects its matching active frame. A cycle counter advances whenever an
empty path is cut. A frame caches its result only if the counter has not changed
since evaluation began. Results of affected frames must be recomputed under a
different active-ancestor context. Independent completed children remain cached.
The counter is conservative: it may suppress harmless cache entries too.

`test_cycle_context` is a concrete counterexample to the original runtime.
Its input is `ab`; the entry tries a positive assertion followed by `z`, then
a fallback. Inside the assertion, a mutually recursive pair of SPLIT states
temporarily cuts one branch and caches a successful prefix ending at 1. Once
the `z` continuation fails, that prefix cannot be reused for the fallback:
without the assertion's active ancestors, the ordered fallback matches `ab`
and must end at 2. The old runtime returns end 1. The negative-assertion variant
exhibits the same stale prefix. Both cases are in the 38-check program suite.

`test_regex_program_reference.c` independently interprets small graphs by
recursive ordered DFS with an active-path table and no memoization. It compares
100,000 deterministic graph/input/start combinations against the production
runtime. It covers consuming transitions, ordered alternatives, absolute END,
positive/negative assertions, unreachable ACCEPT and cyclic graphs. Existing
program tests separately cover ranges, Unicode, long input and resource limits.
This is bounded differential evidence, not a formal proof over all programs.

## Resource cost

Dense memo storage is `sizeof(int) * instruction_count * (length - start + 1)`.
An explicit heap stack stores frames, including assertion depth and cycle epoch.
Ancestor detection scans that stack on a cycle hit. Avoiding context-dependent
caches can increase work on cyclic graphs; no linear-time guarantee is claimed.
Sparse storage remains deferred until measured benchmarks justify it.

Callers can bound memo bytes, frames and execution steps. Zero means no
caller-imposed limit, not a small embedded budget. Overflow checks still apply
to memo and frame allocation/growth and to the cycle counter. Generated MaiaCC
scanners currently supply no explicit limits; integration must measure their
actual memory/work requirements before claiming embedded feasibility.

## Reproducible native verification

From this principal repository, write outputs outside the checkout:

```sh
set -e
task_tmp=$(mktemp -d /tmp/maiaregex-verified.XXXXXX)
for suite in test_regex_program test_regex_program_reference; do
  clang -std=c89 -pedantic-errors -Wall -Wextra -Werror \
    -fsanitize=address,undefined maia_regex.c "$suite.c" -o "$task_tmp/$suite-c89"
  "$task_tmp/$suite-c89"
  clang++ -std=c++98 -pedantic-errors -Wall -Wextra -Werror -x c++ \
    maia_regex.c "$suite.c" -o "$task_tmp/$suite-cpp98"
  "$task_tmp/$suite-cpp98"
done
```

Native checks do not certify MaiaC/WASM or downstream lexer integration. Those
gates must consume a published commit through each consumer's own submodules.
