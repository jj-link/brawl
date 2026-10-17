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
- The four explicitly authorized trial slots are separately coordinated from production. Production worker counts, roles and model pauses are those in Current worker arrangement below; the trial does not change that arrangement. Recheck competing Spark1 usage before an authorized trial launch without changing services or model configuration. No automatic model escalation is authorized.
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
- Each reconstruction agent owns one unit's genuine C/C++ implementation, candidate compilation, comparison, corrections, and unit verification in its exclusive linked worktree. Its job ends when it returns the preserved source and verification evidence. Reconstruction agents do not reconcile with newer MAIN commits, resolve shared-file conflicts, apply files to MAIN, prepare publication indices, or wait for commit/push or dashboard acknowledgment.
- One retained GPT-6.1 Sol integration and source-publication agent receives completed unit results, handles registration, complete-input integration, conflicts, required final verification, checked MAIN application, own-only staging, and a separate commit/push for each assignment. It does not consume a reconstruction slot or start an unauthorized reconstruction-model stage.
- The parent assigns work, reviews unit results, preserves attempt accounting, maintains this plan, and coordinates brief shared-write/index publication windows. The parent does not write code. The retained Sol integration/source publisher runs the automated checkpoint command after each source push; no separate dashboard-publisher agent or parent checkpoint-documentation acknowledgment is required.
- Maintain project work history and progress exclusively in the existing `CHANGELOG.md`.

### Dashboard startup and recovery

- Every observer root, including the selected primary, requires its own entry and unique `observerPort` in `build/live-dashboard/independent-roots.json`. Ports 8765 and 8766 are reserved. The HTTP server resolves the primary port from the entry matching its pinned `--session-id`; missing, invalid or revoked registration must not fall back to whichever session occupies a default port.
- The parent names one HTTP activation owner. After a restart, identify current process IDs, creation times, arguments, root UUIDs and listeners rather than reusing old process IDs. Preserve other sessions' observers. Reuse the verified correct HTTP listener or start the authorized listener on the existing endpoint; do not launch competing servers.
- An already-loaded observer's registration poll can activate an authorized root/port change without restarting OMP, model servers or workers. Source edits do not hot-reload that module. Fresh observer code retries a failed bind through its existing owner poll; changing session identity or restarting unrelated processes is not a recovery method.
- Verify the actual upstream root/PID, genuine child-agent SSE and local/public browser streams before declaring live recovery complete. A reachable page, recorded journal history or a connected observer belonging to another root is insufficient. Dashboard recovery does not gate independent private reconstruction; committed-checkpoint publication uses the separate automated command described below.

### Assignment lifecycle

1. Spawn a fresh agent for one bounded reconstruction assignment.
2. The reconstruction owner independently solves and verifies that unit, preserving its attempts, compiler inputs, source and comparison evidence.
3. Return `review-ready` with the evidence and terminal `unit-complete`. This closes the reconstruction assignment, not source publication or completion credit. Preserve the worktree and evidence in place; do not add a cleanup or publisher-acknowledgment wait. The parent reviews the delivered result, routes it to the retained Sol integration owner, closes the reconstruction session, and immediately refills its slot with a fresh owner.
4. Sol carries the preserved result through integration, required final verification, MAIN application and source commit/push independently of reconstruction slots. Reconstruction workers are not revived for publication chores. Any genuine later reconstruction defect is reported with evidence and preserved history; it is not disguised as an administrative continuation of a closed worker.

### Workspace cleanup

- Reconstruction workers leave their workspaces and evidence intact at delivery. The integration owner is responsible for any later authorized cleanup after publication; cleanup never holds a reconstruction slot. Current original/copy/junction/evidence HOLDs take precedence, and zero-delete retention is valid.
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
- The parent handles assignments, handoffs, attempt tracking, evidence review, plan/checkpoint documentation and brief publication coordination. Integration conflicts and publication failures belong to the dedicated Sol integration owner, not to reconstruction workers. A genuine reconstruction defect is reported separately with its preserved evidence and counts.
- “Helping,” speeding things up, integration, or an agent encountering difficulty are not exceptions.

## Canonical agent instructions

### Dispatch and assignment fields

- The parent uses this section unchanged for every assignment, selecting the common instructions and the applicable role below. Only the assignment fields vary. Do not replace these instructions with an independently rewritten lifecycle.
- The user-approved Qwen fresh-session instruction trial uses the concise execution guidance in `.omp/agents/spark1-qwen.md` in addition to these unchanged common and Reconstruction owner rules. This model-specific guidance changes neither attempt accounting, acceptance criteria, adaptive sizing nor role ownership. GLM instructions remain unchanged. A replacement Qwen session preserves its predecessor's work and history; replacing the agent does not authorize restarting Spark1's model-serving process.
- Read this section from the parent checkout, not an older copy in an isolated workspace, at assignment start and whenever the parent sends a new instruction revision. The parent supplies its absolute path and committed revision.
- Every assignment supplies: role; agent name; parent recipient; parent checkout; instruction revision; exclusive workspace; full baseline commit; exact owned paths or target boundaries; current user overrides; preserved evidence paths; and the next required result. Record the actual workspace kind, common Git directory and private index path during setup.
- Reconstruction fields additionally name the module, symbol, section start/end, original code size, model stage, compiler/build/comparison recipe, best draft, attempt ledger and its covered-through checkpoint, target/best objects, input manifest, and exact predecessor journal paths. Record initial candidates and measured corrections separately by model. Use `NONE` only for a confirmed absence; use `UNKNOWN` with the responsible owner and records to inspect when recovery is incomplete. Do not invent paths or counts.
- Integration-owner fields name the received unit/worktree/evidence paths, original attempt history, reviewed source scope, current accepted input baseline, integration workspace, any already-applied MAIN changes, and source-publication destination. Reuse delivered evidence where its input identities remain applicable; do not send publication preparation back to the reconstruction worker.
- Checkpoint command inputs name the fixed committed source, previous checkpoint evidence, verified integration build and packet, receipt/report destinations, local/public endpoints and expected root session. Sol supplies the actual post-source-commit HEAD/index guards within the existing publication window.
- Audit fields name the exact instruction files/session records, questions, read-only boundaries, and requested findings. Audit results are proposed changes, not authorization to edit instructions.
- Current user overrides are copied literally into the assignment fields. Worker counts, pauses, model selection, and unrelated file ownership are not silently inferred from an older plan copy or changed by standardizing wording.

### Common execution and reporting

- Work only within the assigned role and owned paths. Preserve other owners' changes. Use native Windows and existing project tooling; do not restart services or change model configuration. Do not create files in temporary directories.
- Use absolute paths inside the assigned exclusive workspace for file-tool reads and edits. A shell's working directory does not change the file tools' root; a repo-relative file-tool path can address the parent checkout instead. Before an edit, read the same absolute path that will be edited. If a match failure mentions unexpected content, verify that exact path and current contents before diagnosing line endings or retrying with a different anchor. A MAIN grant authorizes only its explicitly named parent paths.
- Report observed evidence, its source commit/input identities, and remaining qualifications. A private match, an applied patch, a main working-tree change, a commit, a successful push, and a verified dashboard checkpoint are different states; name the actual state.
- Send parent notifications with the `write` tool: `path` is the supplied parent recipient and `content` contains the complete report or exact evidence-file paths. In the current root session the verified recipient is `agent://Main`. A label such as `review-ready` without its evidence is not a report.
- Use `write` for `review-ready`, `reconciled`, `report-published`, `checkpoint-verified`, and concrete blocker notifications. Include assignment/checkpoint identity, completed checks, evidence paths, and the exact next parent action.
- A reconstruction owner with its unit result delivered returns terminal `data` with `status: unit-complete`, assignment identity and evidence paths. It does not wait for integration or publication. The retained integration/source publisher uses terminal `data` with `status: awaiting-parent` only when blocked on a specific parent action; omit `type`. This retains its identity and does not authorize cleanup or replacement.
- Do not use incremental `yield` sections as a substitute for a parent notification. Do not poll Git, files, or status endpoints, repeat unchanged verification, or invent additional work while awaiting a parent action. Use `wait` only for a background job started by that agent.
- A tool/setup failure is a concrete blocker, not an exhausted correction allowance. State the failed operation, observed error, preserved artifacts, and required prerequisite.
- Inspect full tool arguments and results before diagnosing reporting failures. Rendered history may abbreviate a `yield` call to its type while omitting a submitted evidence payload. An incremental section uses `yield` with an actual array in `type` and the evidence in `data`; it is not terminal assignment closure.

### Git isolation and checked handoff

- The MAIN/preimage/private-index/publication checks below belong to the dedicated integration owner. Reconstruction workers supply their unit sources, recipe, inputs, attempts and comparison evidence; they are not required to construct raw MAIN mirrors or publication-index packets.

- For each new reconstruction assignment, create one detached linked worktree at its supplied full baseline: `git -C <parent-checkout> worktree add --detach <exclusive-workspace> <full-baseline>`. Verify its HEAD, common Git directory and distinct index using `rev-parse HEAD`, `rev-parse --git-common-dir` and `rev-parse --git-path index`. Keep its generated build outputs exclusive. Linked worktrees isolate working files and indices; objects, refs and ordinary repository configuration remain shared. Do not change shared refs or repository configuration to work around a private setup problem.
- Existing active clones and worktrees retain their owner, drafts, attempt counts, inputs and evidence through the current assignment. Apply the standard worktree setup to the next fresh assignment; do not reset, re-clone or convert active workspaces, or automatically prune registrations. Retain the integration/source publisher's identity and checkout. The retired dashboard publisher's worktree and all historical evidence remain preserved.
- Treat committed-index bytes and dirty working-file bytes as separate representations. Checkout/clean filters can change line endings, and a successful `git add` can normalize unrelated committed bytes. Record actual index blobs separately from raw file hashes. DTK's split operation can rewrite tracked configuration, but that does not establish that a particular dirty change is generated or disposable. Attribute changes individually; preserve unrelated source/configuration edits and line endings.
- Canonical line endings for `configure.py` and `config/RSBE01_02/rels/ft_dedede/splits.txt` are LF in committed blobs and new checkouts. `.gitattributes` explicitly sets `configure.py text eol=lf`; the existing `config/**/*.txt text eol=lf` rule covers the split file. Historical baselines can still contain mixed LF/CRLF blobs. Existing owners retain their workspaces, drafts and attempt counts, then reconcile their own changes onto the published normalization baseline; do not copy an old mixed-ending whole file over the normalized version.
- `core.autocrlf=false` does not disable all attribute-driven conversion: files explicitly marked `text` without an `eol` attribute use `core.eol`, whose default is `native` (CRLF on Windows). A clean filter can normalize those files. Distinguish the committed blob, the checkout bytes, and dirty parent bytes; different hashes across these representations are not by themselves corruption. Use recorded baseline-specific evidence, and investigate again only when the relevant baseline, attributes, configuration or file identity changes. `git ls-files --eol -- <owned-paths>` reports index/worktree endings and applicable attributes.
- Construct an own-only staging patch from the stated baseline's committed bytes plus the owned changes. Construct live materialization separately from saved actual parent preimages. Do not stage a dirty shared file wholesale or run repository-wide renormalization. The user-approved normalization is a separate maintenance change to the two named registration files, not permission for reconstruction owners to change unrelated line endings.
- Validate an own-only staging patch with an absolute, assignment-owned `GIT_INDEX_FILE`, initialized by `git read-tree <full-baseline>`, followed by actual `git apply --cached --binary`. Read the actual changed paths with `git diff-index --cached --name-only --no-renames -z <full-baseline> --` and stages/modes/blob IDs with `git ls-files --stage -z`. Require exact declared-path equality, including newly created sources, expected stage-0 modes/blobs and no conflict stages. A private index does not require an additional worktree. Review the patch contents as well: correct path/blob declarations do not establish that unrelated bytes were preserved.
- Working-file materialization belongs to the integration owner's brief MAIN publication window, after private integration and required verification. Save current raw preimages, absent-new-file conditions, expected owner-only postimages, verified-input and index identities; preview exact postimages and unrelated-byte preservation, then recheck before application. `git apply --cached` alone never materializes working files. Do not reserve the parent index or block checkpoint documentation during private builds. A documentation-only commit refreshes administrative HEAD/index guards, not unchanged compiler inputs or builds.
- Raw diff evidence must actually preserve bytes. The investigation found that `git diff --no-index` inside a configured repository could normalize external snapshot inputs. Its successful raw comparison used a proven non-repository child mirror, an appropriate `GIT_CEILING_DIRECTORIES`, command-local `core.autocrlf=false`, and `--no-ext-diff --no-textconv --binary --full-index`. Preserve raw pre/post hashes as independent evidence; an EOL-ignoring diff is insufficient.

#### Planned checked command — implementation and activation gate

- Target interface: `checked-handoff --parent <checkout> --packet <owned-packet-directory> --mode validate|materialize`. This command is **proposed, not implemented or callable**. Until an implementation is verified and activated, the integration owner uses the recorded native checks below; do not invent helper output or make helper implementation a prerequisite for unit publication.
- The packet binds the assignment and owned paths to a full baseline, complete verified-input identities and reconstruction evidence. It contains the complete own-only committed-index patch, expected stage/mode/blob identities, a separate raw materialization patch with explicit path stripping, saved raw preimages/postimages and parent-index identity.
- `validate` uses a private index and plain preview files only. `materialize` repeats validation and identity guards, then uses native working-file application without `--index`. The dedicated integration owner performs these operations and source staging/commit/push in its publication window. The helper must not introduce a shared private-build queue or impose publication duties on reconstruction workers.
- Refuse before live writes on stale baseline/inputs/preimages/index, missing or unexpected paths, occupied new-source paths, independently staged changes on touched paths, conflicts, unexpected modes/links, incorrect staged identities, or unrelated EOL/content changes. Refresh the packet and perform only input-required re-verification; unchanged measurements may be reused with matching identities.
- Initial implementation scope is the exercised regular-text modifications and new files. Reject untested renames, deletions, binary changes, links and mode changes. Do not use `--reject`, `--3way`, whitespace-ignoring/fixing options, automatic reset/checkout replacement or blanket normalization for live materialization.
- Validation can change disposable candidate indices/previews before rejecting them, but must leave live files and the parent index unchanged. Hash guards and `--check` do not provide a crash-safe multi-file transaction or prevent concurrent writes; the exclusive MAIN grant remains necessary. After a partial write, preserve evidence and report the actual state. Restore only proven owner-written outputs that still equal the owner's recorded postimages; never overwrite later edits or staging with old backups.
- Before activation, exercise the real helper against isolated fixtures covering mixed line endings, dirty shared files, new-source inclusion, actual staged path/blob checks, stale full inputs, stale index/preimages, conflicts and unchanged live state on refusal. Retain command results and recovery limitations. Native primitive experiments are not proof that an unimplemented helper works.

### Reconstruction owner

1. Independently investigate the assigned function and preserve inherited evidence. Inspect supplied draft, ledger, recipe, and journal paths before broader searches. Missing history remains unknown until recovered; setup recovery and unchanged-input verification do not consume correction attempts.
2. Reconstruct genuine C/C++ using the existing project conventions. Make the initial candidate and perform the compile–compare–revise loop until matched or the model stage has used ten corrections, carrying prior counts forward. Before compiling each initial or revised candidate, retain its exact source/header changes in separate files that later attempts do not overwrite, or in an own-change patch against a named baseline; retain compiler diagnostics, comparison results, and references to the applicable compiler recipe and input identities. A failed compilation is an attempt result even when no object comparison runs; a subsequent candidate revised in response to that compiler feedback counts as a correction. The attempt ledger lists these paths and identifies the best draft. A mutable working-source path is not a preserved attempt draft. The parent supplies no implementation or compiler-tuning advice.
3. Verify the unit in the exclusive worktree: compile the candidate, compare the required code/data/relocations against the original, and record the compiler recipe, exact input identities and runtime verification performed or unavailable. Private registration needed to obtain a valid target comparison is allowed. Full-project integration and the final 127-artifact verification belong to Sol; a reconstruction worker need not perform a second full build or update to newer MAIN commits before delivering a solved unit. Preserve any already-completed full-build evidence for reuse.
4. Send `review-ready` using `write`: target, baseline, exact source/header changes, observed initial/correction counts, best-source and candidate/target objects, comparison results, recipe/input identities, known qualifications and existing evidence paths. Include an existing own-only patch if available; creating publication indices, raw MAIN previews or new handoff infrastructure is not a reconstruction duty.
5. Return terminal `data` with `status: unit-complete` and the same evidence paths. Leave the workspace intact. Do not wait for MAIN grants, integration, commit/push, dashboard updates or a cleanup acknowledgment; do not take another function in the same session.
6. For an exhausted stage, preserve the best draft and all measured corrections, identify the original fallback and unmatched status, and deliver the existing handoff/set-aside evidence. The integration owner handles canonical nonmatching publication; only user-authorized models may take another reconstruction stage. A tool failure or pause does not exhaust an allowance.

### Dedicated integration and source publisher

1. Remain the retained GPT-6.1 Sol owner across unit results. Receive the preserved reconstruction workspace and evidence; do not require its worker to stay active or redo packaging. Keep the original attempt ledger and candidate evidence unchanged. Record integration changes separately, without resetting counts or silently starting another model's reconstruction stage.
2. Use an isolated integration worktree. Reconcile the delivered unit with the complete accepted source input set, including registrations, required declarations and conflicts. Reuse applicable measurements; perform final code/data/relocation, actual source-linkage and expected DOL/REL hash verification for the integrated inputs. Private work does not reserve MAIN or block checkpoint publication.
3. Prepare and validate the own-only staging patch and separate raw MAIN materialization using the Git checks above. Preserve other accepted units, unrelated dirty bytes/EOLs, original fallback and all active HOLDs. Report exact paths, source/input identities, qualification and readiness for the brief publication window; no reconstruction-worker action is required.
4. Within the granted source-and-checkpoint window, refresh actual HEAD/index/preimage checks, materialize only the reviewed result, verify within-file preservation, and stage only the validated owned changes plus that assignment's changelog entry. Commit and push one assignment separately to `origin/main`. Do not stage a dirty shared file wholesale or combine unrelated assignments.
5. Record `source-published` with the actual full source commit/push and preservation evidence, then immediately run the automated checkpoint command below using that commit and actual post-source index guards. The same grant covers its report, checkpoint-only changelog commit/push and endpoint verification; do not add a second parent approval, documentation ACK or agent handoff. Return the source and checkpoint receipts and release the window. If checkpoint publication fails, preserve and report the successfully pushed source and the exact command failure separately; never claim a verified dashboard update.
6. Keep received workspaces and evidence available. Follow the cleanup/HOLD rules without waking the closed reconstruction worker or delaying its replacement. With no queued unit, return `awaiting-parent`; the integration role remains retained.


### Automated dashboard publication

1. The retained integration/source publisher runs `python tools/live_dashboard/publish_checkpoint.py` after each source push. Supply `--root`, exact full `--source`, `--integration-root`, `--evidence`, project-owned `--receipts`, `--session`, `--public-url`, `--publish`, actual post-source `--expected-head` and `--expected-index-sha256`. The local URL defaults to `http://127.0.0.1:8765`; supply the configured public endpoint. Without `--publish`, the command verifies an already recorded checkpoint without live publication.
2. Use the saved integration packet and matching build artifacts. The command binds compiler inputs to committed source, preserves prior accepted-source proof, checks allocated code/relocations and actual source linkage, verifies expected final binary hashes and computes accepted-source accounting. Reuse verified unchanged artifacts; do not regenerate an unchanged build/report or substitute later mutable outputs.
3. The command publishes the verified report, inserts the cumulative `Committed-source checkpoint` changelog record, stages only that record, commits/pushes it separately from the source commit, and checks both endpoints' full source identity, counters, all unit/module classifications and served/persisted history. Ordinary assignment entries remain separate from cumulative checkpoint records.
4. Require its actual successful result and `final-endpoint-agreement.json`, not merely a pushed source or changed report. Duplicate runs reuse the existing checkpoint rather than add another documentation commit. Preserve frozen inputs, command receipts and failures; a failed update reports its actual phase and does not assert new verified progress.
5. No separate dashboard-publisher agent is retained or refilled. This command does not control observers, workers, model services or dashboard layout. Original/evidence HOLDs remain in effect.


### Read-only instruction auditor

- Read the supplied plan, assignment prompts, follow-up instructions, and session records. Distinguish instruction defects from failures to follow clear instructions. Cite exact text and record locations.
- Return concrete ambiguities/conflicts, observed consequences, exact proposed replacement wording, and where each replacement belongs. Verify tool names and recipient syntax from available schemas or successful calls; mark unresolved prerequisites explicitly.
- Do not edit files, run builds, contact workers, change services, or turn the investigation into a prerequisite for reconstruction or publication.

### Parent result handling

- On a delivered unit, review the source and unit evidence, route the preserved result to the retained Sol integration owner, and close the reconstruction session using `write` to `proc://<exact-agent-name>/kill`. Inspect the result; a closure error is not proof of closure. Refill immediately with a fresh owner, without waiting for integration, cleanup, source publication or dashboard publication. User-paused slots remain paused.
- On integration readiness, grant the brief shared-write/index window covering the own-only source commit/push and its automated checkpoint publication. Parent plan changes use separate commits around those mutations; never reserve the index throughout a private build.
- After Sol reports source and checkpoint publication, record the actual command receipt and result. Do not add a second review, parent-authored checkpoint commit, documentation ACK or dashboard-agent handoff before running the command. Reconstruction refills and independent private work continue.
- Treat `awaiting-parent` from a retained integration/publisher role as an outstanding parent action. A reconstruction `unit-complete` result instead ends that worker's assignment; do not revive it for publication chores. Distinguish delivered unit, integrated source, pushed commit and verified dashboard checkpoint.
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
- Assign larger independent functions to Sol reconstruction workers only when that reconstruction role is explicitly authorized; the integration/publishing Sol is not such a worker.
- Give each authorized reconstruction owner one function and continue its model's recorded adaptive target. Historical initial targets were roughly 32 bytes for GLM and 8 bytes for Luna and production Qwen; do not reset current sizing or activate paused models. Select the nearest suitable size with independent ownership and recoverable inputs, and report the actual byte size.
- Track adaptive sizing separately for each model, beginning from its current target. At each evaluated size, use three behaviorally different real functions, selecting the nearest suitable available sizes and recording their actual bytes. Do not treat near-identical helpers, such as three copies of the same destructor pattern, as three diverse samples. Record function types (for example field access, cleanup/destructors, branching logic, and loops) and their outcomes separately.
- During size exploration, two fully verified, accepted matches out of those three functions make that size successful: record it as the last successful size and approximately double the next target. Two functions still unmatched after the existing ten corrections make that size a failed upper bound. Evaluate all three outcomes; a private match awaiting acceptance or a tool/input/publication blocker is not an exhausted reconstruction failure.
- After a failed size, select a target halfway between the last successful size and the failed upper bound, using the nearest suitable available function sizes within that interval. Apply the same diverse three-function, two-of-three rule at this midpoint. A passing midpoint becomes the held working target; a failing midpoint replaces the failed upper bound and the next midpoint is lower. Do not resume upward exploration after a midpoint passes: ordinary subsequent successes at a held target do not increase it.
- Preserve the existing 8-byte floor. If there is no successful lower bound or no suitable intermediate size, record that limitation rather than inventing a midpoint result; retain a known successful working size when available. The result is a tested working size, not a claimed maximum model capability.
- Keep candidate/correction counts, actual size, function type, sample membership, sizing phase (exploration, midpoint search, or held), observed bounds, matching result and assignment timing in the existing assignment evidence and changelog. Preserve prior measurements, unmatched work and the original-code fallback; do not reset function histories or change correction allowances or acceptance criteria.
- Existing in-flight assignments finish unchanged. Refill slots independently; sample collection does not create a synchronized build batch or a new approval gate. Current results may contribute where they meet the diversity requirement, but several near-identical in-flight functions do not establish a diverse three-function result. A size-policy update does not authorize paused models or additional workers.
- The separately authorized four-Qwen/eight-function trial retains its separately coordinated boundaries; this production arrangement does not resize, launch or adopt it. The user has paused the production Qwen worker; do not refill or resume it without renewed authorization.
- Let current workers finish their existing assignments; apply this target selection when assigning subsequent work.
- Define each target's boundaries, original size, compiler settings, dependencies, matching requirements, and known blockers before implementation.
- Use Brawl headers and related reverse-engineering work as evidence. Verify layouts and implementations against Brawl's binaries rather than assuming another project's code is interchangeable.
- Organize independent targets in isolated working copies with separate mutable configuration, headers and outputs. Reconstruction owners perform unit compilation/comparison without a shared-build slot; the integration owner performs final project registration and builds independently of their slots. Keep per-function assignments and status separate from this plan.

#### Current worker arrangement

This is the current arrangement, not a permanent restriction; the user may change worker counts and models.

| Model | Workers | Role |
| --- | ---: | --- |
| GLM | 3 | Solve and verify one unit per fresh owner; adaptive sizing as specified above; finish on delivery. |
| Qwen3.8-Flash-Next on Spark1 | 0 active | User-paused; retain work, attempts and the independent 8-byte adaptive target. No refill or resumption without authorization. |
| GPT-6.1 Sol | 1 | Retained integration/source publisher; commits/pushes units and runs the automated dashboard-checkpoint command. |
| GPT-6 Luna and other reconstruction models | 0 active | Remain paused. Preserved work and attempt histories remain available. |

The user-approved arrangement separates reconstruction from integration/publication. Three GLM workers deliver unit solutions; a fresh GLM owner fills each completed slot immediately. One retained Sol owner integrates and pushes those results, then runs the automated dashboard-publication command. Qwen is user-paused; preserve its separate samples, outcomes, bounds, 8-byte target and all function attempts. GLM's current size and results do not change Qwen's size. This arrangement does not activate Luna, additional workers or the separately coordinated four-Qwen trial.

Reconstruction workers independently run their compile–compare–revise loops and unit verification without parent implementation advice. Sol handles shared-file integration, input-required final verification and source publication. Existing attempts and evidence carry forward; changing these roles does not reset a stage or authorize additional reconstruction models.

#### Approved dashboard-publication automation

The separate dashboard-publisher agent is replaced by `tools/live_dashboard/publish_checkpoint.py`, run by the retained Sol integration/source publisher after each source push. That owner maintains the command as needed; this does not authorize another reconstruction owner or an orchestration redesign.

The command must perform the existing committed-checkpoint workflow: bind saved verification evidence to the exact source commit, publish the verified report, record and commit/push the checkpoint entry in `CHANGELOG.md`, and verify local/public dashboard source identity, totals, unit/module map and persisted progress history. Reuse verified unchanged inputs and outputs; preserve existing acceptance criteria, own-only publication boundaries and original/evidence HOLDs. A failed update must report its concrete error without presenting unverified progress as accepted.

Retain three GLM reconstruction owners and one Sol integration/source publisher. The separate dashboard-publisher role is retired; preserve its worktree and evidence. Do not introduce another per-checkpoint approval or documentation handoff, hold independent reconstruction, or activate paused models.

### 3. Reconstruct and compare

1. Read the target assembly, relevant callers and callees, declarations, data references, and object boundaries.
2. Implement a bounded C/C++ candidate in the repository's existing source and header structure.
3. The assigned subagent compiles its candidate with the project's compiler version and the settings appropriate to that object or library.
4. The subagent compares the candidate with the original using the existing object-comparison tooling, including relevant data and relocations.
5. The subagent uses the observed differences to revise and recompile within its allowance, preserving the best draft and each measured attempt. It does not wait for the parent to run this loop or author corrections.
6. Return a matching candidate with its compiler recipe, exact source/input identities and comparison evidence. Return an unmatched draft for escalation only after completing the stage's ten correction attempts. Finish unit-level code/data verification in the private workspace, then deliver and end the reconstruction assignment. Sol handles final project integration and publication; do not claim accepted source credit before those checks and publication complete.

Do not change global compiler settings merely to improve one candidate's score. Investigate compiler-setting changes only when supported by binary and project evidence. Recheck affected objects when shared declarations or layouts change.

#### Escalation for unmatched code

At each authorized reconstruction-model stage, make one initial draft or continuation of the inherited draft, then continue the compile–compare–revise loop until the candidate matches or ten correction attempts have been completed. A correction is a revised candidate responding to compiler/comparison feedback, not an individual line edit. Lack of further ideas is not an early-stop condition. Existing attempts carry forward; a workflow change does not reset them. If the candidate matches sooner, verify and deliver the unit to the integration owner. The integration Sol role does not itself activate the paused Sol reconstruction pool or another model stage.

1. After GLM or Qwen completes ten corrections without a match, preserve the same function and its handoff artifacts for later pickup by a fresh Sol reconstruction agent only when that model stage is user-authorized. The retained Sol integration/publishing agent is not a reconstruction-model escalation. Local-model history is optional, not a prerequisite for a separately authorized Sol reconstruction assignment.
2. After GPT-6.1 Sol completes ten correction attempts without a match, hand the same function to a fresh Astra reconstruction subagent, not to the parent. This applies whether or not the assignment has local-model history.
3. After that Astra subagent completes ten correction attempts without a match, set the function aside for now.

At every handoff, preserve the best draft, compiler settings, remaining binary differences, and previous attempts. The next model continues from that progress rather than starting over. Preserve the best draft even if a later attempt regresses.

The parent must not accept an unmatched stage as complete before its ten correction attempts. Actual tool or environment failures are reported as blocked work, not as a completed or exhausted stage. The user's stop instructions take precedence.

Setting a function aside does not discard its reconstruction or count it as complete. Retain the draft and comparison evidence for future work; keep the original assembly in the build until a reconstructed source replacement meets the acceptance criteria.

When an assignment is set aside after exhausting its correction limits, the integration owner commits and pushes its best final source attempt to the user's `main`, one separate commit per assignment, labeled `nonmatching—attempts exhausted`. Publish the selected best attempt even if the last attempt regressed, retaining required source/header dependencies. Keep the original-code fallback and exclude these drafts from completed-reconstruction totals. A nonmatching result is not a reason to leave the best attempt uncommitted or to hold its reconstruction worker open.

### 4. Integrate, verify, and commit

1. The reconstruction worker delivers its unit source and comparison evidence and finishes; it does not wait for these integration steps.
2. The retained Sol integration owner registers the delivered reconstruction in its isolated worktree and resolves integration conflicts against the accepted input set.
3. Sol verifies the registered source object, relevant data/relocations, actual source linkage and all expected DOL/REL hashes. Reuse existing evidence only when the applicable inputs are unchanged.
4. The parent reviews the result for unexplained assumptions, unrelated edits, original game material and regressions. Sol handles any remaining integration correction; the closed reconstruction worker is not reopened for it.
5. Sol applies, stages, commits and pushes one accepted assignment in a brief coordinated MAIN publication window. Only actual shared-file/index mutations are sequential; private reconstruction, private verification and ready checkpoint publication are not held behind a private build.
6. Sol records the assignment and verification with its source commit, then runs the checkpoint command for a separate cumulative changelog commit/push in the same authorized window. The parent maintains plan changes; no separate parent checkpoint-documentation step is required.
7. Reconstruction slots are refilled immediately after unit delivery, before this publication workflow completes, using fresh agents and preserved verified knowledge.

Where runtime behavior needs investigation and Dolphin is available, the reconstruction agent runs the rebuilt game and exercises the affected path. Record exactly what was exercised or that runtime verification was unavailable. Booting is not a replacement for matching checks; a build alone does not establish that a gameplay path was exercised.

### 5. Record source-reconstruction progress

Reconstruction owners return their verified unit contribution and evidence with their source changes. Sol's integration verification generates the report using the existing commands when relevant inputs require it; the checkpoint command reuses that verified report rather than rebuilding:

```sh
ninja --quiet build/RSBE01_02/report.json
python tools/reconstruction_progress.py build/RSBE01_02/report.json
```

- Measure accepted, source-linked C/C++ code against objdiff's target code-byte total across the main DOL and all 126 RELs for `RSBE01_02`.
- Exclude assembly registrations, assembly source overrides, mixed inline-assembly units, unregistered drafts, and partial or nonmatching units. The calculator uses each unit's resolved `source_path` and `complete` flag.
- Calculate completion as `accepted source code bytes / total target code bytes × 100`, and remaining bytes as `total target code bytes − accepted source code bytes`.
- Record the accepted change's code-byte delta, whole-project percentage to six decimal places, accepted/total code bytes, and remaining code bytes in `CHANGELOG.md`.
- The checkpoint command binds frozen integration inputs and outputs to the exact committed source, excluding uncommitted work, while reconstruction owners continue independently.
- It publishes verified `build/RSBE01_02/report.json`, creates and pushes the checkpoint-only `CHANGELOG.md` record, and returns the exact source commit, measurements and verification receipt to the parent.
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
