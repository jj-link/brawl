# Brawl matching-decompilation plan

## Goal

Systematically develop a matching decompilation of Super Smash Bros. Brawl in the user's own fork of `doldecomp/brawl`, reusing upstream's history and infrastructure while progressing independently of upstream review.

The deliverable is reconstructed C/C++ that reproduces the original binaries for USA Rev 2 (`RSBE01_02`). A functional rewrite, a native PC port, and recovery of the exact original source text are outside this plan.

## Scope

- Use the user's fork as `origin`, `doldecomp/brawl` as the reference `upstream`, and `main` as the working and publication branch. Preserve upstream history and the user's existing work.
- Commit and push accepted changes to the user's `main` without waiting for upstream review. Upstream contributions require a separate user instruction; inspect and verify upstream changes before incorporating them.
- Use the project's existing source structure, headers, symbols, splits, compiler toolchain, and build infrastructure. Check provenance and license compatibility before importing external source.
- Track the existing BrawlHeaders files directly under `include/lib/BrawlHeaders` in this repository, preserving accepted contents and license notices. Do not require a separate BrawlHeaders repository or submodule for a normal checkout.
- Use native Windows tooling. Do not introduce Docker, move builds onto the Spark cluster, change cluster services or model-serving configuration, or build a model router, scheduler, inference client, or orchestration platform.
- User-authorized exception: implement and evaluate a bounded Prefect–OMP integration under `tools/orchestration_eval/`, using isolated development worktrees and project-owned evaluation data, sessions, processes, and local Git fixtures. This exception covers persistent assignment/attempt/evidence records, fresh-session and model-slot enforcement, explicit run/publication/research/stop authorization, verified cancellation, relevant-input verification reuse, and duplicate-safe commit/push recovery. It does not activate a replacement reconstruction orchestrator. The existing orchestrator retains its workers, MAIN reconciliation grants, parent index, source publication, dashboard, services, and current user overrides while evaluation proceeds; publication of the integration and its documentation must be coordinated with that owner. Coding remains delegated, native Windows and existing models remain required, and Docker, Spark service changes, live-worker adoption/control, and production cutover require separate user authorization. The evaluation uses independent state and fixture repositories; it must refuse mutations of the active reconstruction repository or processes.
- The user controls model selection and switching. Model changes do not alter the acceptance criteria.
- Reconstruct C/C++, not assembly transcriptions. Do not count existing assembly, inline-assembly substitutions, stubs, or merely plausible implementations as completed C/C++ reconstruction.
- Keep game dumps, extracted originals, generated binaries, and credentials out of commits.

### Authorized Prefect–OMP evaluation

The published control-session and Git-fixture commands below run from the detached evaluation worktree at `build/isolated-workers/PrefectOmpEvaluation`. Its native-Windows commands use project-owned storage under that worktree's `build/orchestration-eval/`; the parent checkout, reconstruction processes, dashboard, and shared Git configuration remain outside that evaluation's mutation boundary. The tested interfaces are Python 3.13, Prefect 3.8.8, and OMP 18.10.1. The separately authorized real-function trial below has its own fresh implementation workspace and explicit production boundaries; the existing control-only commands are not already a real-function trial interface.

The user requires maximizing both productive throughput and consistent behavior of the agents and the orchestration process. Evaluate both goals together:

- **Consistency:** enforce assignment and fresh-session ownership, authorized model slots, preserved attempts/evidence, STOP precedence, and reviewed duplicate-safe publication. Record actual violations and recovery outcomes; a model's assertion that it followed the plan is not evidence.
- **Productive concurrency:** keep authorized slots occupied when eligible independent work exists. Separate lack of eligible work, explicit pauses, true input dependencies, tool failures, parent-decision waits, and publication waits. Preserve required exclusive MAIN materialization and commit/push ownership without making independent engineering or verification wait for a publication batch.
- **Measurements:** retain timestamps and workload/model/slot identities for eligible idle-slot time, time blocked on the parent, manual interventions, and accepted work per hour. Report unfinished attempts separately from accepted output. Compare equivalent workloads and unchanged verification requirements rather than treating more active sessions or more tool calls as increased throughput.

Passing the bounded safety exercises alone does not establish these combined goals. A sustained real-assignment trial must have explicit assignment, model/slot, ownership, acceptance, and stop boundaries agreed with the existing orchestrator before activation. The current control-session/Git-fixture results remain infrastructure evidence with zero accepted reconstruction credit; this goal update does not transfer production ownership.

Install the pinned dependencies once, then reuse the resulting environment:

```powershell
python -B -m tools.orchestration_eval.setup_env --authorize-isolated-install
```

Use a fresh run ID for each test or exercise. Existing runs retain their evidence and cannot be overwritten:

```powershell
.\build\orchestration-eval\dependencies\venv\Scripts\python.exe -B -m tools.orchestration_eval test --authorize-isolated-evaluation --run-id behavior-001
.\build\orchestration-eval\dependencies\venv\Scripts\python.exe -B -m tools.orchestration_eval exercise --authorize-isolated-evaluation --run-id native-001 --astra-capacity 1 --omp C:\Users\josep\AppData\Local\omp\omp.exe
.\build\orchestration-eval\dependencies\venv\Scripts\python.exe -B -m tools.orchestration_eval status --run-id native-001
```

`status` is the non-executing default. `--astra-capacity 1` is an explicit evaluation policy, not a production worker-count instruction. The finite exercise uses real OMP control sessions, a private Prefect server, and independently initialized local Git repositories; fixture measurements receive zero accepted reconstruction credit. Preserve `acceptance.json`, `behavioral-tests.json`, lifecycle snapshots, process-exit receipts, RPC records, and Git observations, including failed runs.

If a run is interrupted, stop and recover only that exact owned run:

```powershell
.\build\orchestration-eval\dependencies\venv\Scripts\python.exe -B -m tools.orchestration_eval stop --authorize-isolated-evaluation --run-id native-001
```

Use persisted native exit receipts, not a Prefect task state alone, to establish cancellation. The ledger distinguishes `RUN`, `PUBLISH_EXISTING`, `RESEARCH`, `STOPPING`, and `STOPPED`; publishing existing results does not authorize waking a reconstruction owner. The running reconstruction orchestrator retains its original responsibilities under the exception above.

The `test` command also creates an owned run ledger and contains its real pytest process in a Windows job. Exact-run STOP and parent-exit recovery use that recorded identity. Forbidden OMP work frames terminate the owned job even without a pending RPC receiver. Native shutdown shares one five-second wait budget across the owned process set instead of spending a separate RPC timeout on each control.

Initial fixture Git setup and initial source/probe/expected-file materialization run inside one admitted native job, gated on durable process registration. Later steps check the captured authorization revision; these checkpoints are not independent atomic admissions. An effect checked before STOP may remain in flight until verified job exit. No ledger/runtime lock spans Git, filesystem effects, or native waits. Partial stopped fixtures and their evidence are retained; an existing root is never adopted, overwritten, or automatically retried.

Publication review and materialization bind the exact repository, remote, branch, and complete request identity. Each branch update or push requires its own durable admission, ordered with STOP. An already-admitted effect may finish after STOP; its actual outcome remains recordable and recoverable, but a later mutation needs a fresh authorization check. Observation-only recovery does not restore invalidated verification or authorize new work. This ref/push boundary is not a crash-atomic transaction covering private index and unreferenced-object preparation.

The exercise deliberately submits a launch after STOP; that individual Prefect task reports `PolicyError`. Overall success requires the real flow to reach `COMPLETED`, `acceptance.json` to record `success: true` and `all_owned_processes_exited: true`, and final authorization to remain `STOPPED`.

### Authorized four-Qwen real-function trial

The user authorized preparation now, followed by **four concurrent Qwen3.8-Flash-Next Spark1 reconstruction owners** once execution and dashboard prerequisites are verified. This is a bounded eight-assignment trial, not a replacement for the existing orchestrator and not a single-agent stage.

- Reserve the fresh detached engineering worktree `build/isolated-workers/PrefectOmpRealFunctionTrial` at `d0d182fcfc11d69fcf72c2e8fcc6dd709a93658f` for the trial coordinator's fresh engineering owners. Extend `tools/orchestration_eval/` privately and retain project-local execution/timing evidence. The previous `PrefectOmpEvaluation` workspace, immutable packets and failed/successful receipts remain retained and unchanged.
- Each reconstruction assignment gets a fresh owner and its own detached linked worktree/private index. The same owner retains that one function through reconciliation, publication acknowledgment and evidence-preserving cleanup. Refill each completed slot independently from the four queued assignments; do not wait for a four-owner publication or cleanup batch.
- Execution uses **four owned native RPC root processes**, each with **zero root-provider prompts and one genuine native Qwen task child**. Retain each root and its owned job through that same child's review, reconciliation, push acknowledgment, cleanup and verified close; replace that slot independently for its queued function. Use the native `getToolForEvalBridge` task/write APIs so native agent ownership is preserved, not a custom provider client.
- The narrow journal exception permits only these exact trial-owned native roots and children to create fresh journals in the standard OMP session store, with each root journal header's `cwd` equal to the original MAIN project path. Record actual native UUIDs and journal paths in the ownership ledger. Do not adopt foreign journals or edit global configuration. All other generated data and environment remain private/project-owned; reconstruction file operations still target the assigned absolute worktree, not MAIN.
- Load the original-project observer only after registering each actual root UUID with its unique port. Each genuine child must inherit the observer factory, native AgentRegistry ownership and actual journal ancestry. A job-local journal store is not dashboard-discoverable; separately launched roots require separate registrations/ports and must not be represented as children.
- The original production Qwen roles remain paused; these four explicitly authorized trial slots are separate. Existing three-GLM production ownership and the retained SolPublisherDB04 role continue. Recheck competing Spark1 usage before launch. No service/model reconfiguration or automatic model escalation is authorized.
- The original orchestrator retains MAIN grants, the parent index, docs, commit/push and source/dashboard publication. Trial owners request exact scoped materialization grants and return canonical evidence; the trial does not gain shared Git ref or parent-index authority. Independent private implementation and verification do not wait for a shared-file publication window.

All eight reserved targets are module 117 `ft_dedede`, each **8 original code bytes**. Each owns its named source under `src/mo_fighter/ft_dedede/` plus only its registration insertions in `configure.py` and `config/RSBE01_02/rels/ft_dedede/splits.txt`:

| Queue | Symbol | `.text` interval | Source file | Worktree under `build/isolated-workers/` |
|---|---|---|---|---|
| Initial 1 | `fn_117_E228` | `[0xE228,0xE230)` | `ft_dedede_function_e228.cpp` | `QwenTrialE228` |
| Initial 2 | `fn_117_E230` | `[0xE230,0xE238)` | `ft_dedede_function_e230.cpp` | `QwenTrialE230` |
| Initial 3 | `fn_117_E238` | `[0xE238,0xE240)` | `ft_dedede_function_e238.cpp` | `QwenTrialE238` |
| Initial 4 | `fn_117_E240` | `[0xE240,0xE248)` | `ft_dedede_function_e240.cpp` | `QwenTrialE240` |
| Refill 1 | `fn_117_E248` | `[0xE248,0xE250)` | `ft_dedede_function_e248.cpp` | `QwenTrialE248` |
| Refill 2 | `fn_117_E250` | `[0xE250,0xE258)` | `ft_dedede_function_e250.cpp` | `QwenTrialE250` |
| Refill 3 | `fn_117_E258` | `[0xE258,0xE260)` | `ft_dedede_function_e258.cpp` | `QwenTrialE258` |
| Refill 4 | `fn_117_E260` | `[0xE260,0xE268)` | `ft_dedede_function_e260.cpp` | `QwenTrialE260` |

These reservations exclude production E210/E218/E220 and the independent Astra owner's module-27 `fn_27_1F38E4` with its declared target-local jump tables. Each dispatch carries the full baseline, current canonical instruction revision, recipe/input/evidence/history pointers and recovered per-model initial/correction counts. Missing history remains explicitly unknown; related E208 evidence is not an E228–E260 attempt or a substitute for recovering those targets' own history.

Prepare all four genuine native Qwen children together, holding their first requests with the native `Agent.addBeforeModelCall` AbortSignal-aware gate. While held, require zero provider dispatch and verify the actual native execution/ownership/STOP path, root/child AgentRegistry identities, standard-store journals, native SSE and dashboard card visibility. These real pre-inference lifecycle events satisfy the pre-release visibility check; model tokens are not required before model work is authorized. After the parent accepts that execution/ownership/dashboard evidence, release all four first requests together and immediately verify actual model deltas. The same owners continue their assignments; no one-agent preliminary stage, fake events or pre-release model trial. STOP must terminate both held and active root jobs within the existing shared bound. Gate implementation remains unverified until integrated native evidence is observed. Recorded root history or merely implemented relay code is insufficient. Preserve the original dashboard root and its explicitly registered observer port; a listener on the former default port 8766 is not proof of that root's identity. Unsupported plugin reloads, session switching and unapproved process restarts are not activation methods.

Instrument the whole lifecycle: admission, eligible slot/start, candidate measurements, review-ready, parent waits, MAIN grant/materialization, source commit/push, publication acknowledgment, cleanup/closure and independent refill. Report eligible idle-slot time, parent-blocked time, manual interventions, accepted work/hour, actual instruction/ownership violations and recovery. Keep setup/packaging work and unaccepted attempts separate from accepted output; use equivalent workload and verification criteria when comparing throughput.

Stop dispatch after this eight-assignment queue, or earlier on the user's STOP. Preserve every measured attempt and best work. A nonmatching Qwen stage that reaches the canonical ten-correction limit follows the existing nonmatching publication/handoff rules with its original-code fallback and retained evidence; this trial does not activate another model stage.

## Work ownership

- The parent must not write or modify code under any circumstances, including inline or throwaway code. All coding belongs to subagents.
- Each reconstruction agent owns its unit's source and build changes, data ownership changes, code removal, compilation, comparison, corrections, integration, merge-conflict resolution, and final verification. The same agent carries its work through completion; there is no separate integration worker or pool. New assignments use registered linked Git worktrees and exclusive build directories under the canonical Git-isolation policy below, not a parent-controlled shared-build queue.
- The parent assigns work, manages handoffs and preserved attempt counts, reviews agent-provided changes and evidence, maintains this plan and the changelog, reports progress, and commits accepted work. If a task requires code, the parent delegates it rather than writing or supplying the code.
- One dedicated dashboard-update subagent generates and publishes cumulative progress from committed results and verifies dashboard progress and history through the existing data endpoints independently of the reconstruction worker slots.
- Maintain project work history and progress exclusively in the existing `CHANGELOG.md`.

### Dashboard startup and recovery

- Every observer root, including the selected primary, requires its own entry and unique `observerPort` in `build/live-dashboard/independent-roots.json`. Ports 8765 and 8766 are reserved. The HTTP server resolves the primary port from the entry matching its pinned `--session-id`; missing, invalid or revoked registration must not fall back to whichever session occupies a default port.
- The parent names one HTTP activation owner. After a restart, identify current process IDs, creation times, arguments, root UUIDs and listeners rather than reusing old process IDs. Preserve other sessions' observers. Reuse the verified correct HTTP listener or start the authorized listener on the existing endpoint; do not launch competing servers.
- An already-loaded observer's registration poll can activate an authorized root/port change without restarting OMP, model servers or workers. Source edits do not hot-reload that module. Fresh observer code retries a failed bind through its existing owner poll; changing session identity or restarting unrelated processes is not a recovery method.
- Verify the actual upstream root/PID, genuine child-agent SSE and local/public browser streams before declaring live recovery complete. A reachable page, recorded journal history or a connected observer belonging to another root is insufficient. Dashboard recovery does not gate independent private reconstruction; the dedicated publisher retains its separate committed-checkpoint role.

### Assignment lifecycle

1. Spawn a fresh agent for one bounded reconstruction assignment.
2. Keep that agent responsible for the assignment through integration and final verification or the agreed model handoff.
3. A privately verified patch is review-ready, not a completed assignment. The same owner retains the needed workspace and completes reconciliation with the current main working branch, including conflicts and required re-verification. After the parent commits and pushes the accepted assignment, the owner performs evidence-preserving cleanup and ends its session. The next function goes to a fresh agent. This sequence does not gate other workers’ private implementation, compilation, comparison, or verification.
4. Fill the available worker slot with a fresh agent for the next assignment, carrying forward relevant verified knowledge and preserved handoff artifacts.

### Workspace cleanup

- The reconstruction owner cleans its completed workspace as part of finishing the assignment.
- Preserve source drafts, every measured attempt, compiler recipes, input identities, comparison results, best and target objects used as evidence, verification logs and hashes, progress reports, and handoff or set-aside packets.
- Keep the workspace's source, header, and configuration trees and its Git metadata in place.
- Before deleting redundant workspace input copies or disposable generated outputs, save a file-by-file deletion manifest with exact paths and file-content byte counts. Exclude tracked files from that manifest, including those beneath `build/` or `orig/`. Verify that retained originals and reconstruction evidence remain available, and resolve filesystem links and shared dependencies before removal. Delete the listed files individually; afterward remove only empty directories. A recursive directory deletion does not enforce a file-level exclusion list.
- Keep active, blocked, or still-needed workspaces intact. Before cleaning a handed-off workspace, confirm that the receiving owner has the required preserved inputs and evidence.
- Verify that retained evidence and the project's original game files are unchanged. Return cleanup results, removed byte counts, and any retained files requiring further decisions privately to the parent.

### Hands-off orchestration

- The parent must not write code or solve an agent’s assigned reconstruction problem.
- The parent must not send implementation advice, compiler-tuning suggestions, diagnoses, proposed fixes, pseudocode, or step-by-step correction instructions.
- Assignments and handoffs provide scope, preserved artifact locations, actual attempt counts, and acceptance criteria—not the parent’s preferred solution.
- Agents independently investigate, implement, compile, compare, correct, and verify their work.
- The parent handles assignments, isolated-workspace ownership, handoffs, attempt tracking, evidence review, documentation, and commits. An unmet acceptance criterion or merge conflict goes back to its reconstruction owner without a prescribed technical fix.
- “Helping,” speeding things up, integration, or an agent encountering difficulty are not exceptions.

## Canonical agent instructions

### Dispatch and assignment fields

- The parent uses this section unchanged for every assignment, selecting the common instructions and the applicable role below. Only the assignment fields vary. Do not replace these instructions with an independently rewritten lifecycle.
- Read this section from the parent checkout, not an older copy in an isolated workspace, at assignment start and whenever the parent sends a new instruction revision. The parent supplies its absolute path and committed revision.
- Every assignment supplies: role; agent name; parent recipient; parent checkout; instruction revision; exclusive workspace; full baseline commit; exact owned paths or target boundaries; current user overrides; preserved evidence paths; and the next required result. Record the actual workspace kind, common Git directory and private index path during setup.
- Reconstruction fields additionally name the module, symbol, section start/end, original code size, model stage, compiler/build/comparison recipe, best draft, attempt ledger and its covered-through checkpoint, target/best objects, input manifest, and exact predecessor journal paths. Record initial candidates and measured corrections separately by model. Use `NONE` only for a confirmed absence; use `UNKNOWN` with the responsible owner and records to inspect when recovery is incomplete. Do not invent paths or counts.
- Publisher fields additionally name the fixed committed source checkpoint, previous published checkpoint and evidence, report destination, local/public endpoints, and expected root session. A new checkpoint changes these fields, not the publisher's identity or instructions.
- Audit fields name the exact instruction files/session records, questions, read-only boundaries, and requested findings. Audit results are proposed changes, not authorization to edit instructions.
- Current user overrides are copied literally into the assignment fields. Worker counts, pauses, model selection, and unrelated file ownership are not silently inferred from an older plan copy or changed by standardizing wording.

### Common execution and reporting

- Work only within the assigned role and owned paths. Preserve other owners' changes. Use native Windows and existing project tooling; do not restart services or change model configuration. Do not create files in temporary directories.
- Use absolute paths inside the assigned exclusive workspace for file-tool reads and edits. A shell's working directory does not change the file tools' root; a repo-relative file-tool path can address the parent checkout instead. Before an edit, read the same absolute path that will be edited. If a match failure mentions unexpected content, verify that exact path and current contents before diagnosing line endings or retrying with a different anchor. A MAIN grant authorizes only its explicitly named parent paths.
- Report observed evidence, its source commit/input identities, and remaining qualifications. A private match, an applied patch, a main working-tree change, a commit, a successful push, and a verified dashboard checkpoint are different states; name the actual state.
- Send parent notifications with the `write` tool: `path` is the supplied parent recipient and `content` contains the complete report or exact evidence-file paths. In the current root session the verified recipient is `agent://Main`. A label such as `review-ready` without its evidence is not a report.
- Use `write` for `review-ready`, `reconciled`, `report-published`, `checkpoint-verified`, and concrete blocker notifications. Include assignment/checkpoint identity, completed checks, evidence paths, and the exact next parent action.
- If no work is actionable until a parent message arrives, submit the available `yield` tool with `data` containing the assignment identity, `status: awaiting-parent`, the pending action, and evidence paths; omit `type`. This is a terminal task result, not a process-kill or assignment-closure command. The registered agent remains available for the parent's next `write` message, as observed with the existing publisher. The parent retains that owner; this result does not authorize cleanup or a replacement agent.
- Do not use incremental `yield` sections as a substitute for a parent notification. Do not poll Git, files, or status endpoints, repeat unchanged verification, or invent additional work while awaiting a parent action. Use `wait` only for a background job started by that agent.
- A tool/setup failure is a concrete blocker, not an exhausted correction allowance. State the failed operation, observed error, preserved artifacts, and required prerequisite.
- Inspect full tool arguments and results before diagnosing reporting failures. Rendered history may abbreviate a `yield` call to its type while omitting a submitted evidence payload. An incremental section uses `yield` with an actual array in `type` and the evidence in `data`; it is not terminal assignment closure.

### Git isolation and checked handoff

- For each new reconstruction assignment, create one detached linked worktree at its supplied full baseline: `git -C <parent-checkout> worktree add --detach <exclusive-workspace> <full-baseline>`. Verify its HEAD, common Git directory and distinct index using `rev-parse HEAD`, `rev-parse --git-common-dir` and `rev-parse --git-path index`. Keep its generated build outputs exclusive. Linked worktrees isolate working files and indices; objects, refs and ordinary repository configuration remain shared. Do not change shared refs or repository configuration to work around a private setup problem.
- Existing active clones and worktrees retain their owner, drafts, attempt counts, inputs and evidence through the current assignment. Apply the standard worktree setup to the next fresh assignment; do not reset, re-clone or convert active workspaces, or automatically prune registrations. Retain the dedicated publisher identity and its current checkout; any later checkout transition occurs between checkpoints.
- Treat committed-index bytes and dirty working-file bytes as separate representations. Checkout/clean filters can change line endings, and a successful `git add` can normalize unrelated committed bytes. Record actual index blobs separately from raw file hashes. DTK's split operation can rewrite tracked configuration, but that does not establish that a particular dirty change is generated or disposable. Attribute changes individually; preserve unrelated source/configuration edits and line endings.
- Canonical line endings for `configure.py` and `config/RSBE01_02/rels/ft_dedede/splits.txt` are LF in committed blobs and new checkouts. `.gitattributes` explicitly sets `configure.py text eol=lf`; the existing `config/**/*.txt text eol=lf` rule covers the split file. Historical baselines can still contain mixed LF/CRLF blobs. Existing owners retain their workspaces, drafts and attempt counts, then reconcile their own changes onto the published normalization baseline; do not copy an old mixed-ending whole file over the normalized version.
- `core.autocrlf=false` does not disable all attribute-driven conversion: files explicitly marked `text` without an `eol` attribute use `core.eol`, whose default is `native` (CRLF on Windows). A clean filter can normalize those files. Distinguish the committed blob, the checkout bytes, and dirty parent bytes; different hashes across these representations are not by themselves corruption. Use recorded baseline-specific evidence, and investigate again only when the relevant baseline, attributes, configuration or file identity changes. `git ls-files --eol -- <owned-paths>` reports index/worktree endings and applicable attributes.
- Construct an own-only staging patch from the stated baseline's committed bytes plus the owned changes. Construct live materialization separately from saved actual parent preimages. Do not stage a dirty shared file wholesale or run repository-wide renormalization. The user-approved normalization is a separate maintenance change to the two named registration files, not permission for reconstruction owners to change unrelated line endings.
- Validate an own-only staging patch with an absolute, assignment-owned `GIT_INDEX_FILE`, initialized by `git read-tree <full-baseline>`, followed by actual `git apply --cached --binary`. Read the actual changed paths with `git diff-index --cached --name-only --no-renames -z <full-baseline> --` and stages/modes/blob IDs with `git ls-files --stage -z`. Require exact declared-path equality, including newly created sources, expected stage-0 modes/blobs and no conflict stages. A private index does not require an additional worktree. Review the patch contents as well: correct path/blob declarations do not establish that unrelated bytes were preserved.
- Working-file materialization is a separate operation under the same owner's MAIN grant. Save current raw preimages, absent-new-file conditions, expected owner-only postimages, the full verified-input identity and the parent-index identity. Preview the raw working-file patch in a plain byte mirror; require exact intended postimages and preservation of unrelated bytes. Recheck those identities before live application and prove actual within-file preservation afterward. `git apply --cached` alone never materializes working files.
- Raw diff evidence must actually preserve bytes. The investigation found that `git diff --no-index` inside a configured repository could normalize external snapshot inputs. Its successful raw comparison used a proven non-repository child mirror, an appropriate `GIT_CEILING_DIRECTORIES`, command-local `core.autocrlf=false`, and `--no-ext-diff --no-textconv --binary --full-index`. Preserve raw pre/post hashes as independent evidence; an EOL-ignoring diff is insufficient.

#### Planned checked command — implementation and activation gate

- Target interface: `checked-handoff --parent <checkout> --packet <owned-packet-directory> --mode validate|materialize`. This command is **proposed, not implemented or callable**. Until an implementation is verified and its activation revision is committed, use the recorded native checks above and reconstruction steps 5–6; do not invent helper output or claim automated protection.
- The packet binds the assignment and owned paths to a full baseline, complete verified-input identities and reconstruction evidence. It contains the complete own-only committed-index patch, expected stage/mode/blob identities, a separate raw materialization patch with explicit path stripping, saved raw preimages/postimages and parent-index identity.
- `validate` must use a private index and plain preview files only. `materialize` must repeat validation and identity guards, then use default native working-file application without `--index`. Only the reconstruction owner invokes materialization, after its MAIN grant; the parent reviews, stages, commits and pushes. The helper must not introduce a shared private-build queue or a separate integration owner.
- Refuse before live writes on stale baseline/inputs/preimages/index, missing or unexpected paths, occupied new-source paths, independently staged changes on touched paths, conflicts, unexpected modes/links, incorrect staged identities, or unrelated EOL/content changes. Refresh the packet and perform only input-required re-verification; unchanged measurements may be reused with matching identities.
- Initial implementation scope is the exercised regular-text modifications and new files. Reject untested renames, deletions, binary changes, links and mode changes. Do not use `--reject`, `--3way`, whitespace-ignoring/fixing options, automatic reset/checkout replacement or blanket normalization for live materialization.
- Validation can change disposable candidate indices/previews before rejecting them, but must leave live files and the parent index unchanged. Hash guards and `--check` do not provide a crash-safe multi-file transaction or prevent concurrent writes; the exclusive MAIN grant remains necessary. After a partial write, preserve evidence and report the actual state. Restore only proven owner-written outputs that still equal the owner's recorded postimages; never overwrite later edits or staging with old backups.
- Before activation, exercise the real helper against isolated fixtures covering mixed line endings, dirty shared files, new-source inclusion, actual staged path/blob checks, stale full inputs, stale index/preimages, conflicts and unchanged live state on refusal. Retain command results and recovery limitations. Native primitive experiments are not proof that an unimplemented helper works.

### Reconstruction owner

1. Independently investigate the assigned function and preserve inherited evidence. Inspect supplied draft, ledger, recipe, and journal paths before broader searches. Missing history remains unknown until recovered; setup recovery and unchanged-input verification do not consume correction attempts.
2. Reconstruct genuine C/C++ using the existing project conventions. Make the initial candidate and perform the compile–compare–revise loop until matched or the model stage has used ten corrections, carrying prior counts forward. Before compiling each initial or revised candidate, retain its exact source/header changes in separate files that later attempts do not overwrite, or in an own-change patch against a named baseline; retain compiler diagnostics, comparison results, and references to the applicable compiler recipe and input identities. A failed compilation is an attempt result even when no object comparison runs; a subsequent candidate revised in response to that compiler feedback counts as a correction. The attempt ledger lists these paths and identifies the best draft. A mutable working-source path is not a preserved attempt draft. The parent supplies no implementation or compiler-tuning advice.
3. Independently integrate in the exclusive workspace. Verify registered code, applicable data/relocations, actual reconstructed-source linkage, and all expected DOL/REL hashes. Record the compiler recipe, input identities, measured source bytes, and runtime verification performed or unavailable. No parent-issued private-build permission is required.
4. Send `review-ready` using `write`. Include target, baseline, initial/correction counts, best-source and own-only patch paths, exact changed paths, comparison evidence, source-link proof, native hash outcomes, compiler/input identities, source contribution, and whether the main working tree has been modified. Retain all files needed for reconciliation and re-verification.
5. The same owner reconciles with the current main working tree, preserving other units and unrelated dirty bytes. Before changing a shared main file, save its exact current contents and hash in the assignment evidence; a committed or private-workspace blob is not a backup of a dirty working file. The stated reconciliation baseline covers the full tracked input set, including previously accepted sources, not just changed configuration files; final verification evidence must correspond to that complete input set. The parent identifies which owner may modify overlapping main files next; this sequences only shared-file reconciliation and publication, not private work. Resolve conflicts and perform input-required re-verification yourself. Materialize only your verified changes; do not stage, commit, or push.
6. After materializing those verified changes in the parent main working tree, send `reconciled` using `write`: current baseline, exact own-only staging patch, main source identity, proof that unrelated bytes were preserved, and applicable final comparison/link/hash evidence. For each changed shared file, show that its actual before/after difference contains only your changes, preserving unrelated contents and line endings. Unchanged hashes for other paths do not prove preservation within a changed file. Apply the complete patch to a private index initialized from the stated committed baseline, without changing the parent's index. Verify that the actual staged changed-path set equals the declared owned changes, including new files, and report the successful staging invocation and resulting blob identities read from that private index. A working-tree diff, including one that ignores line endings, or hashes of unstaged files is not this validation. The index-only patch and the dirty main working files are separate artifacts; validation of the former does not prove preservation of the latter. A verified private patch with the parent checkout untouched is still `review-ready`, not `reconciled`. Await the parent's commit-and-push acknowledgment while retaining needed inputs.
7. Source-publication acknowledgment names the assignment, accepted patch/input identity, full source commit, destination branch, and successful push. It does not wait for dashboard publication. After that acknowledgment, perform the existing evidence-preserving cleanup. Send the cleanup receipt with removed paths/byte counts, retained evidence paths/hashes, shared-link checks, and original-input checks. Return terminal `data` with `status: assignment-closed`. The parent closes this session and assigns the next function to a fresh agent.
8. For an exhausted stage, preserve the best draft and all measured corrections, keep the original-code fallback, and send the existing handoff/set-aside evidence. Apply the plan's escalation and nonmatching-publication rules only within current user-authorized models. A pause or tool failure does not exhaust a stage.

### Dedicated dashboard publisher

1. Remain the single publisher across committed checkpoints. A completed checkpoint is not closure of the publisher role. The parent sends subsequent checkpoint fields to this same agent with `write`; replace it only when the user requests replacement or the session is unavailable.
2. Use an isolated checkout of the explicit committed source checkpoint. Exclude uncommitted work. Generate the report and accepted-source accounting with the existing commands and verification criteria in this plan. Reuse evidence only where recorded input identities remain applicable, and distinguish reused measurements from newly executed checks.
3. Publish the verified report to the supplied dashboard input path. Send `report-published` with source commit, report hash, accepted/total/remaining bytes, six-decimal percentage, accepted-unit count, checkpoint delta, exact evidence paths, and qualifications.
4. The parent records those verified measurements in a new `CHANGELOG.md` section headed `## Committed-source checkpoint <short source SHA>`. Include the full source SHA using the literal words `committed snapshot` followed by whitespace and the 40-character SHA enclosed in backticks; this is the source-identity field recognized by the existing dashboard reader. Include report SHA-256, verification outcome and evidence paths, six-decimal percentage, `<accepted> / <total> accepted code bytes`, `<remaining> code bytes remaining`, and `<units> accepted source units`. All counters must come from this publisher's report for that source commit. Commit and push the complete record, then send its documentation commit to this same publisher. Until then, distinguish updated report-derived data from the previous changelog-backed headline/history; do not declare all surfaces updated. Ordinary function entries are separate records, not cumulative checkpoints.
5. After that message, verify local/public headline counters, source identity (`/api/state` field `progress.commit` must equal the full source SHA), report-derived unit/module data, and served/persisted latest history against the committed checkpoint. Send `checkpoint-verified` with the observed values, timestamps, evidence paths, and any discrepancies. No service restart or dashboard code change belongs to this role.
6. Preserve checkpoint evidence and complete safe cleanup. Return checkpoint results without declaring the publisher role closed. With no next checkpoint supplied, use the common `awaiting-parent` result; do not poll for commits or perform unrelated work.

### Read-only instruction auditor

- Read the supplied plan, assignment prompts, follow-up instructions, and session records. Distinguish instruction defects from failures to follow clear instructions. Cite exact text and record locations.
- Return concrete ambiguities/conflicts, observed consequences, exact proposed replacement wording, and where each replacement belongs. Verify tool names and recipient syntax from available schemas or successful calls; mark unresolved prerequisites explicitly.
- Do not edit files, run builds, contact workers, change services, or turn the investigation into a prerequisite for reconstruction or publication.

### Parent result handling

- On a reconstruction result, inspect its stated state and evidence. Advance the same owner through any remaining reconciliation; then stage only its reviewed patch, record the observed result, and commit and push that assignment separately.
- Send the source-publication acknowledgment to that owner for cleanup. After its cleanup receipt, close its session using `write` to `proc://<exact-agent-name>/kill`, inspect the result, and refill the authorized slot with a fresh agent using these same instructions. A closure error is not proof of closure. User-paused slots remain paused.
- Send each newly accepted committed checkpoint to the retained publisher. Complete the changelog acknowledgment and final checkpoint verification without replacing that publisher or delaying reconstruction refills.
- Treat `awaiting-parent` as an outstanding parent action, not a failed worker or completed assignment. Resume the same registered agent with `write` when that action is complete. Do not report publication or closure before its required evidence arrives.
- Administrative fields may be corrected with explicit follow-up messages. Changes to role ownership, acceptance criteria, lifecycle, or allowed scope require the user's authorization and an update to this canonical text, rather than a contradictory one-off prompt.

### Instruction revisions

- When an instruction problem is observed, identify the affected role, exact instruction, session/evidence path, and observed consequence. Distinguish ambiguous wording from a clear instruction that was not followed before proposing a wording change.
- Refine the applicable instruction in this canonical section instead of creating a second template or introducing a conflicting follow-up prompt. Preserve the user's current overrides and the parent result-handling authorization requirements.
- The parent commits and pushes the approved revision, then sends each affected active owner a `write` notification containing the absolute parent `PLAN.md` path, committed instruction revision, changed section, and any action required for that owner's current assignment. The owner reads that revision and acknowledges its role, revision, and next required action with `write` to the supplied parent recipient. Keep the same assignment, workspace, and attempt ledger; an instruction revision does not restart or replace its owner or resume a user-paused role.


## Work sequence

### 1. Establish or reuse a verified baseline

- Inspect the existing checkout, remotes, branch, submodules, original game input, and build configuration. Reuse completed setup rather than resetting or overwriting it.
- Verify the supported game revision and use the compiler and tool versions specified by the project.
- Configure and build using the existing workflow:

  ```sh
  python configure.py
  ninja
  ```

- Verify the rebuilt DOL and REL outputs against `config/RSBE01_02/build.sha1` and generate a baseline progress report.
- Confirm that `objdiff` can compare reconstructed source objects with their original counterparts.
- If required input is unavailable, report the missing prerequisite rather than inventing substitute input or claiming verification.

### 2. Select bounded reconstruction targets

- Inspect source, headers, symbols, object splits, progress reports, dependencies, and overlapping upstream work.
- Assign larger, independent functions within coherent subsystem groups to available Sol workers.
- Assign 8-byte functions to available GLM and Qwen workers. Preserve unmatched local-model work after ten corrections for later pickup by a Sol worker.
- Let current workers finish their existing assignments; apply this target selection when assigning subsequent work.
- Define each target's boundaries, original size, compiler settings, dependencies, matching requirements, and known blockers before implementation.
- Use Brawl headers and related reverse-engineering work as evidence. Verify layouts and implementations against Brawl's binaries rather than assuming another project's code is interchangeable.
- Organize independent targets for parallel work in isolated working copies with separate mutable configuration, headers, and build outputs. Agents perform their own registration and final builds without requesting a shared-build slot. Keep per-function assignments and status separate from this plan.

#### Current worker arrangement

This is the current arrangement, not a permanent restriction; the user may change worker counts and models.

| Model | Workers | Role |
| --- | ---: | --- |
| GPT-6.1 Sol | 8 | Larger, independent functions within coherent subsystem groups, or preserved GLM/Qwen work picked up later. |
| GLM | 2 | 8-byte functions; preserve unmatched work after ten corrections for later Sol pickup. |
| Qwen3.8-Flash-Next (Spark1) | 3 | 8-byte functions, with the same ten-correction and later Sol-pickup rules as GLM. |
| GPT-6.1 Sol | 1 | Dedicated dashboard publication from committed results, separate from the reconstruction slots. |

GLM concurrency is capped at two active subagents across all assignments, including recovery work.

The pool contains eight Sol worker slots, two GLM worker slots, and three Qwen worker slots. Neither local model is a mandatory first stage: each Sol assignment may start fresh or inherit GLM or Qwen progress. A local-model handoff spawns a fresh agent in an available slot among those eight Sol workers, not an additional Sol pool. Reconstruction subagents own source edits and their targeted compile–compare–revise loops, using the existing compiler and object-comparison tooling without waiting for parent feedback after each attempt. Unmatched Sol work is handed to a fresh Astra reconstruction subagent. Subagents also perform integration and verification; the parent coordinates that work and reviews its evidence without writing code or supplying technical advice. Existing correction counts carry forward when work resumes.

### 3. Reconstruct and compare

1. Read the target assembly, relevant callers and callees, declarations, data references, and object boundaries.
2. Implement a bounded C/C++ candidate in the repository's existing source and header structure.
3. The assigned subagent compiles its candidate with the project's compiler version and the settings appropriate to that object or library.
4. The subagent compares the candidate with the original using the existing object-comparison tooling, including relevant data and relocations.
5. The subagent uses the observed differences to revise and recompile within its allowance, preserving the best draft and each measured attempt. It does not wait for the parent to run this loop or author corrections.
6. Return a matching candidate with its compiler recipe and comparison evidence for parent review. Return an unmatched draft for escalation only after completing the stage's ten correction attempts. Finish integration and any data migration in the same owner's isolated working copy without waiting for a parent-issued build grant. Do not claim a complete object match before that work is verified.

Do not change global compiler settings merely to improve one candidate's score. Investigate compiler-setting changes only when supported by binary and project evidence. Recheck affected objects when shared declarations or layouts change.

#### Escalation for unmatched code

At each model stage, make one initial draft or continuation of the inherited draft, then continue the compile–compare–revise loop until the candidate matches or ten correction attempts have been completed. This applies to GLM, Qwen, GPT-6.1 Sol, and Astra. A correction attempt is a revised candidate responding to compiler/comparison feedback, not an individual line edit. Lack of further ideas is not an early-stop condition. Existing attempts carry forward; a workflow change does not reset them. If the candidate matches sooner, proceed to integration and verification.

1. After GLM or Qwen completes ten correction attempts without a match, preserve the same function and its handoff artifacts for later pickup by a fresh GPT-6.1 Sol agent in an available slot in the eight-worker pool. Local-model history is optional, not a prerequisite for a Sol assignment.
2. After GPT-6.1 Sol completes ten correction attempts without a match, hand the same function to a fresh Astra reconstruction subagent, not to the parent. This applies whether or not the assignment has local-model history.
3. After that Astra subagent completes ten correction attempts without a match, set the function aside for now.

At every handoff, preserve the best draft, compiler settings, remaining binary differences, and previous attempts. The next model continues from that progress rather than starting over. Preserve the best draft even if a later attempt regresses.

The parent must not accept an unmatched stage as complete before its ten correction attempts. Actual tool or environment failures are reported as blocked work, not as a completed or exhausted stage. The user's stop instructions take precedence.

Setting a function aside does not discard its reconstruction or count it as complete. Retain the draft and comparison evidence for future work; keep the original assembly in the build until a reconstructed source replacement meets the acceptance criteria.

When an assignment is set aside after exhausting its correction limits, the parent must commit and push its best final source attempt to the user's `main`, one separate commit per reconstruction assignment, labeled `nonmatching—attempts exhausted`. Publish the selected best attempt even if the last attempt regressed; include any source/header dependencies needed to retain that attempt. Keep the original-code build fallback active and exclude these drafts from completed-reconstruction totals. A nonmatching result is not a reason to leave the best attempt uncommitted or unpushed.

### 4. Integrate, verify, and commit

1. The same reconstruction agent registers its matching reconstruction in its isolated working copy using the existing source/split/build conventions.
2. The subagent compares the registered source object with the original and confirms that the matching build actually includes it rather than retaining its original-code replacement.
3. The subagent builds and verifies all expected DOL/REL hashes in its own build directory, including outputs affected by shared declarations, and returns the observed evidence with the verified baseline and exact changed paths.
4. The parent reviews the change and verification evidence for unexplained assumptions, unrelated edits, original game material, and regressions. The reconstruction owner reconciles its changes with the current main working branch and handles any merge conflicts or required re-verification; there is no separate integration worker.
5. The parent commits accepted changes in small, independently reviewable units and pushes them to the user's `main`. Main-branch commits and pushes are sequential, but there is no shared-build queue or permission gate that halts other agents' reconstruction and verification.
6. The parent records completed work, observed verification results, and progress measurements in `CHANGELOG.md`, not in this plan.
7. Assign the next related target to a fresh agent in the available worker slot, passing on verified types and compiler knowledge.

Where runtime behavior needs investigation and Dolphin is available, the reconstruction agent runs the rebuilt game and exercises the affected path. Record exactly what was exercised or that runtime verification was unavailable. Booting is not a replacement for matching checks; a build alone does not establish that a gameplay path was exercised.

### 5. Record source-reconstruction progress

Reconstruction owners return their verified unit contribution and evidence with their source changes. The dedicated dashboard-update agent generates cumulative progress from committed results using the existing commands:

```sh
ninja --quiet build/RSBE01_02/report.json
python tools/reconstruction_progress.py build/RSBE01_02/report.json
```

- Measure accepted, source-linked C/C++ code against objdiff's target code-byte total across the main DOL and all 126 RELs for `RSBE01_02`.
- Exclude assembly registrations, assembly source overrides, mixed inline-assembly units, unregistered drafts, and partial or nonmatching units. The calculator uses each unit's resolved `source_path` and `complete` flag.
- Calculate completion as `accepted source code bytes / total target code bytes × 100`, and remaining bytes as `total target code bytes − accepted source code bytes`.
- Record the accepted change's code-byte delta, whole-project percentage to six decimal places, accepted/total code bytes, and remaining code bytes in `CHANGELOG.md`.
- The dashboard-update agent uses an isolated checkout of committed results to generate and verify cumulative progress while reconstruction owners continue their assignments independently.
- The dashboard-update agent publishes the verified `build/RSBE01_02/report.json` to the existing dashboard input location and reports its source commit and exact measurements to the parent. The parent records the same checkpoint in `CHANGELOG.md`.
- Refresh every dashboard progress surface for that checkpoint: completion percentage, accepted/total/remaining bytes, accepted-unit count, module totals, the unit map, and the accepted-bytes history graph.
- Use the existing dashboard data endpoints and persisted history to verify that headline counters, report-derived module/unit data, and the latest graph point agree with the accepted checkpoint before completing publication.
- Maintain accurate current-agent status and activity in the dashboard as work proceeds.
- Keep batch or wave subtotals distinct from whole-project progress. Do not substitute aggregate matched/linked percentages, generated source-line counts, data bytes, executable-section spans, or ISO size for accepted C/C++ code progress.

## Acceptance criteria

A reconstruction is complete only when all applicable gates pass:

- It is reconstructed C/C++ and compiles under the intended project settings.
- Object comparison matches the original code and applicable data and relocation requirements.
- The matching build actually links the reconstructed source object.
- Final DOL/REL hash checks pass, including outputs affected by shared changes.
- The reconstruction owner returns the verified source contribution and supporting evidence for cumulative progress reporting.
- The proposed commit has been reviewed for unexplained assumptions, accidental unrelated edits, and original game material.

A worker's success report, model switch, plausible implementation, successful compilation, or unchanged final binary alone does not prove that a new source object was accepted. Upstream review or merge status is not an additional acceptance gate.
