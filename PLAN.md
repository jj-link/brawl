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
- The user controls model selection and switching. Model changes do not alter the acceptance criteria.
- Reconstruct C/C++, not assembly transcriptions. Do not count existing assembly, inline-assembly substitutions, stubs, or merely plausible implementations as completed C/C++ reconstruction.
- Keep game dumps, extracted originals, generated binaries, and credentials out of commits.

## Work ownership

- The parent must not write or modify code under any circumstances, including inline or throwaway code. All coding belongs to subagents.
- Each reconstruction agent owns its unit's source and build changes, data ownership changes, code removal, compilation, comparison, corrections, integration, merge-conflict resolution, and final verification. The same agent carries its work through completion; there is no separate integration worker or pool. Each agent uses an isolated working copy and build directory, not a parent-controlled shared-build queue.
- The parent assigns work, manages handoffs and preserved attempt counts, reviews agent-provided changes and evidence, maintains this plan and the changelog, reports progress, and commits accepted work. If a task requires code, the parent delegates it rather than writing or supplying the code.
- One dedicated dashboard-update subagent generates and publishes cumulative progress from committed results and verifies dashboard progress and history through the existing data endpoints independently of the reconstruction worker slots.
- Maintain project work history and progress exclusively in the existing `CHANGELOG.md`.

### Assignment lifecycle

1. Spawn a fresh agent for one bounded reconstruction assignment.
2. Keep that agent responsible for the assignment through integration and final verification or the agreed model handoff.
3. A privately verified patch is review-ready, not a completed assignment. The same owner retains the needed workspace and completes reconciliation with the current main working branch, including conflicts and required re-verification. After the parent commits and pushes the accepted assignment, the owner performs evidence-preserving cleanup and ends its session. The next function goes to a fresh agent. This sequence does not gate other workers’ private implementation, compilation, comparison, or verification.
4. Fill the available worker slot with a fresh agent for the next assignment, carrying forward relevant verified knowledge and preserved handoff artifacts.

### Workspace cleanup

- The reconstruction owner cleans its completed workspace as part of finishing the assignment.
- Preserve source drafts, every measured attempt, compiler recipes, input identities, comparison results, best and target objects used as evidence, verification logs and hashes, progress reports, and handoff or set-aside packets.
- Keep the workspace's source, header, and configuration trees and its Git metadata in place.
- Remove redundant workspace copies of game inputs and disposable generated build outputs after verifying that retained originals and reconstruction evidence remain available. Resolve filesystem links and shared dependencies before removal so cleanup affects only the intended workspace files.
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
- Every assignment supplies: role; agent name; parent recipient; parent checkout; instruction revision; exclusive workspace; full baseline commit; exact owned paths or target boundaries; current user overrides; preserved evidence paths; and the next required result.
- Reconstruction fields additionally name the module, symbol, section start/end, original code size, model stage, compiler/build/comparison recipe, best draft, attempt ledger and its covered-through checkpoint, target/best objects, input manifest, and exact predecessor journal paths. Record initial candidates and measured corrections separately by model. Use `NONE` only for a confirmed absence; use `UNKNOWN` with the responsible owner and records to inspect when recovery is incomplete. Do not invent paths or counts.
- Publisher fields additionally name the fixed committed source checkpoint, previous published checkpoint and evidence, report destination, local/public endpoints, and expected root session. A new checkpoint changes these fields, not the publisher's identity or instructions.
- Audit fields name the exact instruction files/session records, questions, read-only boundaries, and requested findings. Audit results are proposed changes, not authorization to edit instructions.
- Current user overrides are copied literally into the assignment fields. Worker counts, pauses, model selection, and unrelated file ownership are not silently inferred from an older plan copy or changed by standardizing wording.

### Common execution and reporting

- Work only within the assigned role and owned paths. Preserve other owners' changes. Use native Windows and existing project tooling; do not restart services or change model configuration. Do not create files in temporary directories.
- Report observed evidence, its source commit/input identities, and remaining qualifications. A private match, an applied patch, a main working-tree change, a commit, a successful push, and a verified dashboard checkpoint are different states; name the actual state.
- Send parent notifications with the `write` tool: `path` is the supplied parent recipient and `content` contains the complete report or exact evidence-file paths. In the current root session the verified recipient is `agent://Main`. A label such as `review-ready` without its evidence is not a report.
- Use `write` for `review-ready`, `reconciled`, `report-published`, `checkpoint-verified`, and concrete blocker notifications. Include assignment/checkpoint identity, completed checks, evidence paths, and the exact next parent action.
- If no work is actionable until a parent message arrives, submit the available `yield` tool with `data` containing the assignment identity, `status: awaiting-parent`, the pending action, and evidence paths; omit `type`. This is a terminal task result, not a process-kill or assignment-closure command. The registered agent remains available for the parent's next `write` message, as observed with the existing publisher. The parent retains that owner; this result does not authorize cleanup or a replacement agent.
- Do not use incremental `yield` sections as a substitute for a parent notification. Do not poll Git, files, or status endpoints, repeat unchanged verification, or invent additional work while awaiting a parent action. Use `wait` only for a background job started by that agent.
- A tool/setup failure is a concrete blocker, not an exhausted correction allowance. State the failed operation, observed error, preserved artifacts, and required prerequisite.
- Inspect full tool arguments and results before diagnosing reporting failures. Rendered history may abbreviate a `yield` call to its type while omitting a submitted evidence payload. An incremental section uses `yield` with an actual array in `type` and the evidence in `data`; it is not terminal assignment closure.

### Reconstruction owner

1. Independently investigate the assigned function and preserve inherited evidence. Inspect supplied draft, ledger, recipe, and journal paths before broader searches. Missing history remains unknown until recovered; setup recovery and unchanged-input verification do not consume correction attempts.
2. Reconstruct genuine C/C++ using the existing project conventions. Make the initial candidate and perform the compile–compare–revise loop until matched or the model stage has used ten corrections, carrying prior counts forward. Preserve every measured attempt and the best draft. The parent supplies no implementation or compiler-tuning advice.
3. Independently integrate in the exclusive workspace. Verify registered code, applicable data/relocations, actual reconstructed-source linkage, and all expected DOL/REL hashes. Record the compiler recipe, input identities, measured source bytes, and runtime verification performed or unavailable. No parent-issued private-build permission is required.
4. Send `review-ready` using `write`. Include target, baseline, initial/correction counts, best-source and own-only patch paths, exact changed paths, comparison evidence, source-link proof, native hash outcomes, compiler/input identities, source contribution, and whether the main working tree has been modified. Retain all files needed for reconciliation and re-verification.
5. The same owner reconciles with the current main working tree, preserving other units and unrelated dirty bytes. The stated reconciliation baseline covers the full tracked input set, including previously accepted sources, not just changed configuration files; final verification evidence must correspond to that complete input set. The parent identifies which owner may modify overlapping main files next; this sequences only shared-file reconciliation and publication, not private work. Resolve conflicts and perform input-required re-verification yourself. Materialize only your verified changes; do not stage, commit, or push.
6. Send `reconciled` using `write`: current baseline, exact own-only staging patch, main source identity, proof that unrelated bytes were preserved, and applicable final comparison/link/hash evidence. Await the parent's commit-and-push acknowledgment while retaining needed inputs.
7. Source-publication acknowledgment names the assignment, accepted patch/input identity, full source commit, destination branch, and successful push. It does not wait for dashboard publication. After that acknowledgment, perform the existing evidence-preserving cleanup. Send the cleanup receipt with removed paths/byte counts, retained evidence paths/hashes, shared-link checks, and original-input checks. Return terminal `data` with `status: assignment-closed`. The parent closes this session and assigns the next function to a fresh agent.
8. For an exhausted stage, preserve the best draft and all measured corrections, keep the original-code fallback, and send the existing handoff/set-aside evidence. Apply the plan's escalation and nonmatching-publication rules only within current user-authorized models. A pause or tool failure does not exhaust a stage.

### Dedicated dashboard publisher

1. Remain the single publisher across committed checkpoints. A completed checkpoint is not closure of the publisher role. The parent sends subsequent checkpoint fields to this same agent with `write`; replace it only when the user requests replacement or the session is unavailable.
2. Use an isolated checkout of the explicit committed source checkpoint. Exclude uncommitted work. Generate the report and accepted-source accounting with the existing commands and verification criteria in this plan. Reuse evidence only where recorded input identities remain applicable, and distinguish reused measurements from newly executed checks.
3. Publish the verified report to the supplied dashboard input path. Send `report-published` with source commit, report hash, accepted/total/remaining bytes, six-decimal percentage, accepted-unit count, checkpoint delta, exact evidence paths, and qualifications.
4. The parent records those verified measurements in a new `CHANGELOG.md` section headed `## Committed-source checkpoint <short source SHA>`. Include the full committed source SHA, report SHA-256, verification outcome and evidence paths, six-decimal percentage, `<accepted> / <total> accepted code bytes`, `<remaining> code bytes remaining`, and `<units> accepted source units`. All counters must come from this publisher's report for that source commit. Commit and push the complete record, then send its documentation commit to this same publisher. Until then, distinguish updated report-derived data from the previous changelog-backed headline/history; do not declare all surfaces updated. Ordinary function entries are separate records, not cumulative checkpoints.
5. After that message, verify local/public headline counters, report-derived unit/module data, and served/persisted latest history against the committed checkpoint. Send `checkpoint-verified` with the observed values, timestamps, evidence paths, and any discrepancies. No service restart or dashboard code change belongs to this role.
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
