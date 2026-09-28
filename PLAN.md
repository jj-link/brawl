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

Last updated: 2026-09-28 (branch `local-models`).

### Accepted state

- Repository: `C:\Users\josep\Projects\personal\games\brawl-decomp`; remotes `origin` = https://github.com/jj-link/brawl.git (push default), `upstream` = https://github.com/doldecomp/brawl.git (fetch only).
- Branch `local-models`, first commit `78f739a` ("Add decompilation plan") on top of upstream base `345952a` ("Decompile nt_send.cpp (#125)"). Submodules: BrawlHeaders `e1c66b3`, OpenRVL `5acdab3`.
- Game input `orig/RSBE01_02/` = USA Rev 2 ISO, SHA-1 `59432f150bf6b871ab378bb5b28e92005e0862f6`.
- Baseline build verified: `python configure.py` + `ninja` → **127/127 files OK** against `config/RSBE01_02/build.sha1` (checked via dtk CHECK and Python re-hash; note: Git-for-Windows `sha1sum -c` misreports 6 files as FAILED — trust the Python/dtk check).
- Baseline progress (objdiff report, 4417 units): **All 1.27% matched** (dedup scoring; pre-ft_purin-batch baseline was 1.20%) / 1.01% linked; Code 189,716/15,833,548 bytes (2,429/92,524 functions); Data 826,796/5,667,492. 22 incomplete source units.
- **ft_purin first matched batch accepted** (2026-09-28): 10 functions — `soAnimCmdAddressPackArraySeparate::{isNull, size, at×2, atSub, dtor}`, `soArrayFixed<soAnimCmdAddressPackConv>::isEmpty`, `soValueAccesser::getValueVariation`, `ftExtendParamAccesserEx<3999,49,24999,4>::{getParamFloat, getParamInt}` — all 100% (verified word-by-word incl. branch-target index equivalence and relocation rows). Unit went 15→17 fns (getParamFloat/Int counted here; getParamIndefinite dedups to sora_melee's 100% unit), 4.57%→6.18%.
  - Emission: `src/mo_fighter/ft_purin/ft_purin.cpp` testBuilder() constructs `soAnimCmdAddressPackArraySeparate` and calls `at/size/isNull` (forces vtable + out-of-line weak virtuals); the header inline definitions in `so_anim_cmd_module_impl.h` were already correct.
  - **`getValueVariation` reads sora_melee storage, NOT TU-local data**: target loads `lbl_27_bss_1B18`, defined in `config/RSBE01_02/rels/sora_melee/symbols.txt` at `.bss:0x1B18` (size 0x8, module 27). Implementation is `extern "C" u8 lbl_27_bss_1B18[];` + `int soValueAccesser::getValueVariation() { return *(s32*)lbl_27_bss_1B18; }` — byte-identical `lis/lwz` against the true cross-module symbol. Cross-module resolution is empirically supported: during forced relink tests dtk rel make never reported `lbl_27_bss_1B18` unresolvable (it resolved earlier relocations including this import before failing on unrelated partial-TU gaps like `lbl_124_data_5A6C`); full rel-link proof lands when the unit completes. [INFERENCE: resolution-by-name against module 27's symbol table]
  - **Inlining shape**: `getParamFloat`/`getParamInt` inline bodies were removed from `include/lib/BrawlHeaders/Brawl/Include/ft/ft_extend_param_accesser.h` (declaration-only now; only consumers are ft_purin.cpp and sora_melee's non-instantiating cpp) and defined in ft_purin.cpp as explicit specializations in TARGET ORDER (getParamFloat → getter → getParamInt, matching target .text order 0x88F8/0x8950/0x895C). The getter definition needs `#pragma dont_inline on/reset` (repo-precedent lever from em_extend_param_accesser.cpp) — without it MWCC's `-ipa file` inlines the 3-instruction getter into both callers and breaks their match (both previously-matched functions regressed to inlined-variant mismatches before the pragma was added).
  - Report regenerated with `objdiff-cli report generate -d` (**deduplicate mode is REQUIRED to score weak/duplicated symbols**). Hashes unaffected: unit is `NonMatching` (rel links the extracted object); `ninja build/RSBE01_02/ok` = 127/127 verified after these changes. NOTE: the extracted object at `build/RSBE01_02/ft_purin/obj/mo_fighter/ft_purin/ft_purin.o` is regenerated by `dtk dol split` (delete it + `build/RSBE01_02/config.json`, then `ninja build/RSBE01_02/config.json`) if ever clobbered — it is an input to the ft_purin rel link and replacing it with a rebuilt object breaks makerel with missing `lbl_124_*` imports.
- Working files: `src/sora/mt/mt_vector_old.cpp` and `src/sora/ip/ip_network_producer.cpp` restored to upstream state (`d0e7803` content); no uncommitted source changes pending.
- Upstream `main` is still at `345952a` — no upstream work to incorporate as of this checkpoint.

### Milestone status

- Milestones 1–3 complete (fork/checkout, verified baseline, target selection).
- Milestone 4 in progress. No object fully matched yet; detailed findings below.

### Target investigations (evidence, not accepted work)

1. `mt_vector_old.cpp` `vlRotateFix` (280 B, 98%): target allocates `cos(theta)` to `f5`; current build allocates `f2`. Declaration-order permutations (temps-first, sin/cos-first, load reorder) do not change the allocation. Source restored to upstream; blocked.
2. `ip_network_producer.cpp` `networkInCallback` (244 B, 98.5%): reconstructed instruction **sequence** is identical for all 62 words; only register roles differ — target assigns producer pointer→`r7`/cursor→`r6`, our build assigns pointer→`r6`/cursor→`r7` (plus `add` operand order from the same swap). Tried: byte-alias vs struct-field access forms, cursor/pointer declaration order, `int` cursor, explicit `u8 b = r7[0]` local, ternary clamp, separate `r4 = r7 + unk0` base for the `unk1` store, `u16*` message base — none changed the allocation (21-word best). Working tree restored to upstream.
3. `cm_controller_menu_fixed.cpp` `init` (108 B, 23.2%): target writes `unkFA` as u16 RMW on `0xfa` (`lhz/ori/sth`, three stores `|0x80`, `|0x82`, `|0x82|0x40`) and stages values through stack spills (`stfs f0, 0x8(r1)`, `stfs f1, 0xc(r1)`); our builds either use byte bitfields on `0xfb` (`lbz/stb`) or fold the three mask stores into two (`ori r0, r0, 0xC2`). Tried: locals for CC/angle/rot, cached `gfCamera*`, u16 `m_mask |=` chains, explicit mask local, bitfield orders, flag2-before-rot reorder — none reproduced the three-store u16 shape. Source restored to upstream.
4. `ut_relocate.cpp` `resolveReference` (272 B, 98.75%): same regswap class as (2) — callee-saved roles differ (`symtab` r23↔r26, `limit` r24↔r23, `step` r25↔r24, outer step r26↔r25, found addr r27↔r23); instruction sequence otherwise identical.
5. **Compiler-flag sweep (ip_network_producer, direct mwcceppc invocations)**: `-O3`, `-O4,s`, `-O2`, `-inline noauto/none/all/off`, `-ipa function`, `-opt noschedule/nopeephole/schedule`, `-fp_contract on`, `-str noreuse`, and every other available GC compiler version (3.0a3…3.0a5) were tried. All are **worse or equal** to the pinned `-O4,p -ipa file` (21-word minimum). The pinned configuration is already optimal; the delta is not a configuration error.
6. `nt_send.cpp` `create` (444 B, 98.7%): only 19 differing words — 16 are the unrolled loop's `add r3, r0, r4` (ours) vs `add r3, r4, r0` (target) operand order; 3 are benign `bl`/`@sda21` rows. Commuting the source (`i + base` vs `base + i`) and hoisting the base into a local did **not** change MWCC's operand order (hoisting made it worse: 51). Source restored.
7. `em_external_value_accesser.cpp` `getFaceTexPtr` (132 B, 90.8%): 18–19 differing words. Target uses the `GetManagedWeaponFromTaskID` result in place (`lwz r4, 0x21ec(r3)`, null path inline); our builds always emit an extra `mr r4, r3` copy and lay the paths out inverted. Tried ternary, `if (!wn)`, `if (wn)`-first, assignment-in-condition — same shape. Source restored.
8. `sc_adv_gameover.cpp` `create` (216 B, 90.1%): only **6 differing words** — constant-def scheduling inside the inlined ctor (`lis r4,lbl_1_data_6600` / `li r5,0` / `li r0,1` / `lis r4,adList@ha` interleave). Store sequence and values identical. Ctor init-list reorder (header is single-consumer) did not change it. Header reverted; tree clean.

### Interpretation

Findings 2, 4, 6, 8 share one root cause: **MWCC 3.0a5.2 instruction-scheduling / register-role / add-operand-order decisions that are not reachable by reordering source text**. The reconstructed semantics are right (instruction sequences and store orders match); the compiler's internal ordering differs. Finding 5 rules out flag/version misconfiguration. Finding 7's `mr r4, r3` copy is the same class. Progress on these requires either recovering the original source idioms that change allocator cost models, or deeper MWCC allocator research — not more declaration shuffles.

### Next concrete actions

1. **Diff-measurement infrastructure**: batch-compile candidate variants headlessly (direct `sjiswrap.exe mwcceppc.exe` calls with the object's `build.ninja` cflags, quoted pragmas rejoined) and word-diff against `build/RSBE01_02/<module>/asm/...` targets — established and working in this session.
2. Study the MWCC scheduling deltas via Melee (100% decompiled, same compiler family): find Melee functions with equivalent constructs (inlined ctor constant scheduling, `base + i` add operand order, call-result-in-place usage) and compare their SOURCE text to ours to recover the original idioms.
3. Remaining 22 incomplete units: triage into (a) regswap/scheduling class (documented above), (b) genuinely unimplemented functions needing new decompilation, (c) data-only gaps. Prefer class (b) — where writing new source can yield whole-function matches rather than fighting 1–6 word scheduling deltas. **ft_purin precedent (2026-09-28)**: the 8 named `soAnimCmd`-cluster functions matched once emitted (see Accepted state); the next ft_purin class-b step is the small anonymous-function family `fn_124_A9D0…B028` (7× 52B, stride 0xE8, self-contained: `bit7(byte@5)` gate + `byte@6` check + tail-call vtable slot 0xC — pattern-identical bodies, need an owner class context to emit as real methods), or the 0x14-byte group at `0x80C4–0x823C`. For any future unit with header-inline class methods, remember: emission (a use site or vtable reference in the TU) is the prerequisite, and `-d` dedup scoring exposes weak-symbol matches.
4. When an object matches end-to-end: flip its `configure.py` entry to `Object(Matching, ...)`, `python configure.py && ninja`, verify 127/127 hashes, regenerate `build/RSBE01_02/report.json`, and record the progress delta here.

## References

- Upstream repository and build instructions: https://github.com/doldecomp/brawl
- Brawl progress: https://decomp.dev/doldecomp/brawl
- Melee progress: https://decomp.dev/doldecomp/melee
- Existing Brawl headers: https://github.com/Sammi-Husky/BrawlHeaders
- Functional module reimplementations: https://github.com/Sammi-Husky/BrawlModules
- Object comparison tooling: https://github.com/encounter/objdiff
