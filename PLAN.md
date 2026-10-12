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
3. After verified source integration and binary verification, return the source patch and evidence, perform the evidence-preserving workspace cleanup below, and end the reconstruction agent's session. Preserved model handoffs and Astra set-aside outcomes follow the same evidence-preserving cleanup lifecycle.
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
