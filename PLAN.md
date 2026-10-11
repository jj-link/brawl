# Brawl matching-decompilation plan

## Goal

Systematically develop a matching decompilation of Super Smash Bros. Brawl in the user's own fork of `doldecomp/brawl`, reusing upstream's history and infrastructure while progressing independently of upstream review.

The deliverable is reconstructed C/C++ that reproduces the original binaries for USA Rev 2 (`RSBE01_02`). A functional rewrite, a native PC port, and recovery of the exact original source text are outside this plan.

## Scope

- Use the user's fork as `origin`, `doldecomp/brawl` as the reference `upstream`, and `local-models` as the working branch. Preserve upstream history and the user's existing work.
- Accept verified changes locally without waiting for upstream review. Pushes and upstream contributions require the user's instruction; inspect and verify upstream changes before incorporating them.
- Use the project's existing source structure, headers, symbols, splits, compiler toolchain, and build infrastructure. Check provenance and license compatibility before importing external source.
- Use native Windows tooling. Do not introduce Docker, move builds onto the Spark cluster, change cluster services or model-serving configuration, or build a model router, scheduler, inference client, or orchestration platform.
- The user controls model selection and switching. Model changes do not alter the acceptance criteria.
- Reconstruct C/C++, not assembly transcriptions. Do not count existing assembly, inline-assembly substitutions, stubs, or merely plausible implementations as completed C/C++ reconstruction.
- Keep game dumps, extracted originals, generated binaries, and credentials out of commits.

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
- Begin with small, low-dependency objects or nearly matching implementations to establish the workflow; then prioritize shared types and helpers that unblock other work, followed by coherent subsystem groups.
- Define each target's boundaries, original size, compiler settings, dependencies, matching requirements, and known blockers before implementation.
- Use Brawl headers and related reverse-engineering work as evidence. Verify layouts and implementations against Brawl's binaries rather than assuming another project's code is interchangeable.
- Organize independent targets for parallel work without overlapping edits. Keep per-function assignments and status separate from this plan.

#### Current worker arrangement

This is the current arrangement, not a permanent restriction; the user may change worker counts and models.

| Model | Workers | Role |
| --- | ---: | --- |
| GPT-6.1 Sol | 8 | Nonoverlapping reconstruction assignments: either fresh work or preserved GLM handoffs. |
| GLM | 2 | Nonoverlapping reconstruction assignments, handing unmatched work to an available worker in the eight-Sol pool after ten corrections. |

The pool contains eight Sol workers and two GLM workers. GLM is not a mandatory first stage: each Sol assignment may start fresh or inherit GLM progress. A GLM handoff uses an available worker among those eight Sol workers, not an additional Sol pool. Reconstruction subagents own source edits and their targeted compile–compare–revise loops, using the existing compiler and object-comparison tooling without waiting for parent feedback after each attempt. Unmatched Sol work is handed to a spawned Astra reconstruction subagent. The parent handles assignments, progress-preserving handoffs, integration, independent verification of registered objects, final binary verification, commits, and progress reporting; it does not take over reconstruction edits. Existing correction counts carry forward when work resumes.

### 3. Reconstruct and compare

1. Read the target assembly, relevant callers and callees, declarations, data references, and object boundaries.
2. Implement a bounded C/C++ candidate in the repository's existing source and header structure.
3. The assigned subagent compiles its candidate with the project's compiler version and the settings appropriate to that object or library.
4. The subagent compares the candidate with the original using the existing object-comparison tooling, including relevant data and relocations.
5. The subagent uses the observed differences to revise and recompile within its allowance, preserving the best draft and each measured attempt. It does not wait for the parent to run this loop or author corrections.
6. Return a matching candidate with its compiler recipe and comparison evidence for parent integration. Return an unmatched draft for escalation only after completing the stage's ten correction attempts. Report any integration-owned data migration separately rather than claiming a complete object match.

Do not change global compiler settings merely to improve one candidate's score. Investigate compiler-setting changes only when supported by binary and project evidence. Recheck affected objects when shared declarations or layouts change.

#### Escalation for unmatched code

At each model stage, make one initial draft or continuation of the inherited draft, then continue the compile–compare–revise loop until the candidate matches or ten correction attempts have been completed. This applies to GLM, GPT-6.1 Sol, and Astra. A correction attempt is a revised candidate responding to compiler/comparison feedback, not an individual line edit. Lack of further ideas is not an early-stop condition. Existing attempts carry forward; a workflow change does not reset them. If the candidate matches sooner, proceed to integration and verification.

1. After GLM completes ten correction attempts without a match, hand the same function to an available GPT-6.1 Sol worker in the eight-worker pool. GLM is optional history, not a prerequisite for a Sol assignment.
2. After GPT-6.1 Sol completes ten correction attempts without a match, hand the same function to a spawned Astra reconstruction subagent, not to the parent. This applies whether or not the assignment has GLM history.
3. After that Astra subagent completes ten correction attempts without a match, set the function aside for now.

At every handoff, preserve the best draft, compiler settings, remaining binary differences, and previous attempts. The next model continues from that progress rather than starting over. Preserve the best draft even if a later attempt regresses.

The parent must not accept an unmatched stage as complete before its ten correction attempts. Actual tool or environment failures are reported as blocked work, not as a completed or exhausted stage. The user's stop instructions take precedence.

Setting a function aside does not discard its reconstruction or count it as complete. Retain the draft and comparison evidence for future work; keep the original assembly in the build until a reconstructed source replacement meets the acceptance criteria.

### 4. Integrate, verify, and commit

1. Register a matching reconstruction using the existing source/split/build conventions.
2. Confirm that the matching build actually includes the reconstructed source object rather than retaining its original-code replacement.
3. Build and verify all expected DOL/REL hashes, including outputs affected by shared changes.
4. Review the change for unexplained assumptions, unrelated edits, original game material, and regressions.
5. Commit accepted changes in small, independently reviewable units.
6. Record completed work, observed verification results, and progress measurements in `CHANGELOG.md`, not in this plan.
7. Continue with related targets to reuse verified types and compiler knowledge; do not wait for an upstream pull request.

Where runtime behavior needs investigation and Dolphin is available, run the rebuilt game and exercise the affected path. Record exactly what was exercised or that runtime verification was unavailable. Booting is not a replacement for matching checks; a build alone does not establish that a gameplay path was exercised.

### 5. Record source-reconstruction progress

After the linked hash check passes, regenerate the report and calculate accepted source progress:

```sh
ninja --quiet build/RSBE01_02/report.json
python tools/reconstruction_progress.py build/RSBE01_02/report.json
```

- Measure accepted, source-linked C/C++ code against objdiff's target code-byte total across the main DOL and all 126 RELs for `RSBE01_02`.
- Exclude assembly registrations, assembly source overrides, mixed inline-assembly units, unregistered drafts, and partial or nonmatching units. The calculator uses each unit's resolved `source_path` and `complete` flag.
- Calculate completion as `accepted source code bytes / total target code bytes × 100`, and remaining bytes as `total target code bytes − accepted source code bytes`.
- Record the accepted change's code-byte delta, whole-project percentage to six decimal places, accepted/total code bytes, and remaining code bytes in `CHANGELOG.md`.
- Keep batch or wave subtotals distinct from whole-project progress. Do not substitute aggregate matched/linked percentages, generated source-line counts, data bytes, executable-section spans, or ISO size for accepted C/C++ code progress.

## Acceptance criteria

A reconstruction is complete only when all applicable gates pass:

- It is reconstructed C/C++ and compiles under the intended project settings.
- Object comparison matches the original code and applicable data and relocation requirements.
- The matching build actually links the reconstructed source object.
- Final DOL/REL hash checks pass, including outputs affected by shared changes.
- Progress reporting reflects the accepted source contribution without regressions.
- The proposed commit has been reviewed for unexplained assumptions, accidental unrelated edits, and original game material.

A worker's success report, model switch, plausible implementation, successful compilation, or unchanged final binary alone does not prove that a new source object was accepted. Upstream review or merge status is not an additional acceptance gate.
