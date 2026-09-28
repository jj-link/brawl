# Brawl matching-decompilation plan

## Goal and working agreement

Systematically develop a matching decompilation of Super Smash Bros. Brawl in the user's own fork of `doldecomp/brawl`, reusing upstream's history and infrastructure while progressing independently of upstream review.

- Use `local-models` as the working branch, based on the upstream default branch.
- The user's fork is the primary repository (`origin`); `doldecomp/brawl` is the reference repository (`upstream`).
- Accept verified work in the user's fork and continue to the next target without waiting for upstream pull requests.
- The user runs models on the DGX Spark cluster and handles model selection and switching.
- Whichever assistant/model is active executes this same plan normally: inspect the repository, implement a bounded change, run verification, and record the result.
- Do not build a model router, scheduler, inference client, or multi-agent orchestration system. Do not change cluster services or model-serving configuration.
- Start with one target object at a time. Switching models does not change the acceptance criteria or require a different development workflow.
- This document is the plan, not a record of completed implementation. Repository setup, branch creation, and builds have not yet been performed.

The target is reconstructed C/C++ that reproduces the original binaries. A functional rewrite, a native PC port, and recovering the exact original source text are different goals and are not part of this plan.

## Repository ownership and upstream relationship

- Create or reuse the user's GitHub fork rather than starting a fresh implementation.
- Keep accepted work under the user's control. The matching and verification gates in this plan determine technical completion; an upstream merge is not an acceptance or completion gate.
- Use `origin` for the user's fork and as the default push destination once configured. Use `upstream` to inspect and fetch changes from `doldecomp/brawl`, not as a push destination.
- Preserve the upstream base history so changes can be compared and exchanged.
- Upstream contributions are optional and require the user's instruction. Open, delayed, or rejected upstream pull requests do not block local work or acceptance in the fork.
- Selectively incorporate useful upstream changes after inspection and matching verification; do not automatically merge updates into unfinished work.

## Starting evidence

The upstream reports inspected while preparing this plan showed:

| Project | Decompiled | Fully linked | Tracked machine code |
| --- | ---: | ---: | ---: |
| Brawl | 1.20% | 1.01% | 15.83 MB |
| Melee | 100.00% | 100.00% | 3.88 MB |

Brawl's report referenced commit `345952a32ac4182720e28f4151c635294fcd8822` (`Decompile nt_send.cpp`). These are reference observations, not a local baseline; record the actual checkout revision and freshly generated reports when execution begins.

Useful existing infrastructure:

- Supported game revision: USA Rev 2, `RSBE01_02`.
- Python/Ninja build with compiler and tool versions specified in `configure.py`.
- `objdiff` integration for comparing reconstructed objects with the original code.
- Symbols, object splits, and binary hashes for the main DOL and REL modules.
- The `BrawlHeaders` submodule and related community reverse-engineering work.

A low matching percentage does not mean the remaining code is entirely unexplored. Conversely, readable source or a functional reimplementation is not automatically a binary match.

## Milestone 1: Establish the fork, checkout, and branch

- [ ] Create or locate the user's GitHub fork and verify its actual owner and URL.
- [ ] Set up an upstream-based checkout while preserving this plan and any user files.
- [ ] Configure `origin` to the verified fork URL and `upstream` to `doldecomp/brawl`; make `origin` the default push destination.
- [ ] Create or select the `local-models` branch without resetting existing work.
- [ ] Initialize submodules recursively.
- [ ] Record the upstream base commit and inspect the current build instructions.

This directory contains `PLAN.md`, so do not assume `git clone ... .` can run into an empty directory. For the initial workspace, if it is still not a Git repository, the following non-destructive commands establish the upstream-based local checkout. Fork creation and `origin` configuration are separate steps:

```sh
git init
git remote add upstream https://github.com/doldecomp/brawl.git
git fetch upstream
git remote set-head upstream --auto
git switch --no-track -c local-models upstream/HEAD
git submodule update --init --recursive
```

After verifying the actual fork URL, add it as `origin` and set `remote.pushDefault` to `origin`. Do not invent an owner or URL. Local checkout and toolchain preparation can proceed while fork access is unresolved, but this milestone remains incomplete until the fork and remotes are verified.

Inspect existing repository state before using these commands. If the repository, remote, or branch already exists, reuse it rather than repeating initialization. If checkout would overwrite a local file, stop and preserve the file; do not force checkout or reset. Do not push changes or open pull requests without the user's instruction.

**Exit criterion:** the user's fork is identified and accessible, `origin` and `upstream` have the intended destinations, and a usable checkout on `local-models` has initialized submodules and a recorded upstream base revision.

## Milestone 2: Establish a verified build baseline

- [ ] Check the native Windows prerequisites against the upstream instructions: Git, Python, and Ninja.
- [ ] Obtain the location of the user's own supported game dump and verify its revision through the project's extraction/hash checks.
- [ ] Place the required input under `orig/RSBE01_02` as documented upstream.
- [ ] Configure and build using the project's existing toolchain and settings.
- [ ] Verify the rebuilt DOL and REL outputs against `config/RSBE01_02/build.sha1`.
- [ ] Generate and record baseline matching/linked progress, including exact byte counts where available.
- [ ] Confirm that `objdiff` can compare a reconstructed object against its original counterpart.

The documented basic build sequence is:

```sh
python configure.py
ninja
```

Upstream CI also uses the following source/progress targets; confirm they exist in the checked-out revision before running them:

```sh
ninja all_source progress build/RSBE01_02/report.json
```

Use native Windows tooling, as recommended upstream. Do not introduce Docker or move the build onto the Spark cluster as part of this plan. Keep game dumps, extracted original files, generated binaries, and credentials out of commits; verify ignore coverage before staging.

A successful baseline build can still incorporate original code for undecompiled regions. It proves that the build environment works, not that those regions have been reconstructed from source.

**Exit criterion:** reproducible local build and successful original-binary hash verification, with an actual baseline report. If the game dump is unavailable, finish reachable setup and report that prerequisite explicitly; do not invent substitute input or claim build verification.

## Milestone 3: Select a bounded first target

- [ ] Inspect existing source, headers, symbols, splits, and progress reports before choosing a target.
- [ ] Check upstream activity for overlapping work.
- [ ] Identify a previously unmatched object with known boundaries, reasonably understood types, and limited dependencies.
- [ ] Record its original size, current matching status, relevant compiler settings, and known blockers.
- [ ] Define success as replacing that object's original-code contribution with verified reconstructed source.

Selection order:

1. Small, low-dependency objects or nearly matching existing implementations to establish the workflow.
2. Shared types, layouts, or helper implementations that unblock multiple objects.
3. Coherent groups within a subsystem, rather than permanently chasing isolated easy functions.

Use existing Brawl headers and related reverse-engineering work as evidence. Check provenance and license compatibility before importing external source. Melee is a reference for techniques and potentially related code, not a substitute for checking Brawl's binaries. Do not assume a class layout or implementation is correct merely because it appears in another project.

**Exit criterion:** one concrete object selected, its required context understood, and its acceptance checks identified. No throughput estimate is justified yet.

## Milestone 4: Complete the first source-to-binary match

For the selected object:

1. Read its assembly, callers/callees as needed, existing declarations, data references, and object boundaries.
2. Implement a bounded candidate in the repository's existing source/header structure.
3. Compile with the project's compiler version and the flags for that object or library.
4. Compare against the original with `objdiff`.
5. Resolve differences using evidence: types, signedness, class layout, calling conventions, control flow, data placement, inlining, and compiler behavior.
6. Repeat until the object meets the project's matching requirements, including relevant data and relocation differences.
7. Enable the reconstructed object in the matching build using the existing project convention.
8. Run the matching build and verify all expected DOL/REL hashes. Confirm the source object was actually linked, rather than silently retaining its original-code replacement.
9. Compare progress against the baseline and record the exact accepted change.

Do not change global compiler settings just to improve one candidate's score. Investigate compiler-setting changes only when supported by binary and project evidence. Do not accept stubs, unexplained assembly substitutions, or merely plausible C++ as a completed decompilation.

**Exit criterion:** one previously unmatched object reconstructed from source, linked into the matching build, with passing binary verification and no matching regressions elsewhere.

## Milestone 5: Repeat systematically

- [ ] Build a small work queue from the observed results and existing progress data; do not build a separate orchestration platform.
- [ ] For each target, record its subsystem/object, dependencies, status, concrete blocker if any, and next action.
- [ ] Continue with related objects to reuse verified types and compiler knowledge.
- [ ] Address shared-header blockers deliberately and recheck affected objects when layouts or declarations change.
- [ ] Keep accepted changes small and independently reviewable in the user's fork; retain the option of contributing them upstream later.
- [ ] Assess progress using matched bytes, source-linked objects, and resolved blockers, not generated source lines or model output volume.
- [ ] Continue to the next target as soon as the current change meets local acceptance gates; never wait for an upstream pull request.

Use the first small batch to learn which targets the workflow handles well and where human investigation is needed. Do not assume that local-model assistance guarantees any particular rate of progress or completion date.

## Verification rules

An object is complete only when all applicable gates pass:

- Its reconstructed source compiles under the intended project settings.
- Object comparison satisfies the project's matching requirements.
- The matching build actually includes the reconstructed source.
- Final DOL/REL hash checks pass, including outputs affected by shared changes.
- Progress reporting reflects the accepted source contribution without regressions.
- Changes are reviewed for unexplained assumptions, accidental unrelated edits, and original game material in the proposed commit.

These are local technical acceptance gates. Upstream review or merge status is not an additional requirement.

Where runtime behavior needs investigation and Dolphin is available, run the rebuilt game and exercise the affected path. Record exactly what was exercised or that runtime verification was unavailable. Booting successfully is not a replacement for matching checks, and do not claim a gameplay path was tested based only on a build.

Keep partial or non-matching work explicitly labeled. A model switch, plausible implementation, successful compilation, or unchanged final binary alone does not establish that a new source object was accepted.

## Continuity between models and sessions

The user controls model switching. Before a handoff, leave a short factual checkpoint in this document so the next active model can continue ordinary repository work:

- Fork URL, configured remotes, current branch, upstream base revision, and last accepted checkpoint.
- Current milestone and exact target object/function.
- Changed files, including unfinished work that must be preserved.
- Commands actually run and their observed results.
- Remaining mismatches or blockers, with evidence rather than guesses.
- The next concrete action.

Separate attempted work from accepted work. Never mark a milestone complete based on an intended command or an unverified claim. Do not discard another model's uncommitted changes or repeat a reported failing check merely to reconfirm the failure; investigate the recorded evidence and rerun after a relevant change.

## Current checkpoint

- Planning only; this document is the first workspace file created for this effort.
- The user has chosen an independently maintained GitHub fork as the primary repository. No fork has been created or verified as part of this work, and its owner/URL have not yet been established.
- Repository checkout and `local-models` branch creation have not been performed.
- Game dump location, local toolchain availability, baseline build, and matching progress have not been verified locally.
- No decompilation changes or cluster/model configuration changes have been made.
- Next execution step: Milestone 1, identifying or creating the user's fork and preserving this plan while establishing the checkout, remotes, and `local-models` branch.

## References

- Upstream repository and build instructions: https://github.com/doldecomp/brawl
- Brawl progress: https://decomp.dev/doldecomp/brawl
- Melee progress: https://decomp.dev/doldecomp/melee
- Existing Brawl headers: https://github.com/Sammi-Husky/BrawlHeaders
- Functional module reimplementations: https://github.com/Sammi-Husky/BrawlModules
- Object comparison tooling: https://github.com/encounter/objdiff
