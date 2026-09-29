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

**Fork relationship (clarified 2026-09-28)**: the fork was branched directly from upstream tip `345952a` (the commit cited above) — session commit `78f739a` (`Add decompilation plan`) has it as parent. `local-models` is therefore a strict superset of `upstream/main`; `git merge upstream/main` reports 'Already up to date'. No upstream merge is pending. The 1.20%/1.01% figures on decomp.dev describe upstream's tree; the fork adds this plan's work on top (see Current checkpoint). Note upstream's 'Decompile nt_send.cpp' (#125), nt_report (#124), and mt_trig (#122) landed source files still wired as `Object(NonMatching, ...)` on both sides — they raise the decomp.dev 'decompiled' fuzzy figure but not 'fully linked'.

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

## Batch Log

- **thirtieth–thirty-third units** (agent batch 1): `fn_803F524C`, `fn_803F5C38`, `fn_803F5EF4`, `fn_803F5EA8` — Runtime.PPCEABI.H; 4 + 172 + 128 + 4 B; agents transcribed from dtk disasm in junctioned worktrees; integrated through `59ebcc1`; incomplete 3,324 → 3,320.
- **thirty-fourth–thirty-sixth units** (agent batch 2): `fn_803F0F04`, `fn_803F11A0` (64 B each; extab 0x8 + extabindex 0xC; `bl __dl__FPv`), `fn_803F5898` (188 B; calls `fn_803F5954`/`fn_803F342C`); verified instruction-exact against targets before merge; integrated through `dfa76c7`; incomplete 3,320 → 3,317.
- **thirty-seventh–thirty-ninth units** (agent batch 3): `fn_803F5954` (308 B; calls `fn_803F3684`/`fn_803F5CE0`/`__flush_buffer`), `fn_803F7404` (296 B; text-only), `fn_803F8ACC` (368 B; extab-carrying; shift-heavy); verified instruction-exact (77/74/92 insns) before merge; integrated through `2311e80`; incomplete 3,317 → 3,314.
- **fortieth–forty-second units** (agent batch 4): `fn_803F8C64` (1716 B; 429 insns; no calls), `fn_803FC0AC` (1220 B; 305 insns; `__div2u`), `fn_803F9318` (3424 B; 856 insns; 13 calls incl. cross-refs to still-auto labels); verified instruction-exact before merge; integrated through `7164e3b`; incomplete 3,314 → 3,311.
- **forty-third–forty-fifth units** (agent batch 5): `fn_803FA804` (5108 B; 1285 insns; calls `fn_803F48B0` still-auto, `fn_80400D90`, `memset`), `fn_803FBC7C` (1072 B; 268 insns), `fn_803F60F8` (884 B; 7 functions incl. `memchr`/`__memrchr`); verified instruction-exact (robust pair-compare) before merge; integrated through `59b453e`; incomplete 3,311 → 3,308.
- **forty-sixth–forty-eighth units** (agent batch 6): `fn_803F5250` (832 B; 208 insns; `fwide` x3, `fn_803F3600`, `fn_803F5098`, `memcpy`, `__prep_buffer`; extab+extabindex), `fn_803F07E0` (572 B; 143 insns), `fn_803F6B74` (552 B; 138 insns); verified instruction-exact before merge; integrated through `fe1e25d`; incomplete 3,308 → 3,305.
- **forty-ninth–fifty-first units** (agent batch 7): `fn_803FA280` (848 B; 212 insns; 8 libc str functions — `strcpy`, `strncpy`, `strcat`, `strncat`, `strcmp`, `strncmp` + 2 more), `fn_803F5B48` (240 B; 60 insns; `strlen`), `fn_803FC618` (236 B; 59 insns; calls matched `fn_803FBC7C`); verified instruction-exact before merge; integrated through `32e0b43`; incomplete 3,305 → 3,302.
- **fifty-second–fifty-fourth units** (agent batch 8): `fn_803FC7C8` (228 B; 57 insns; 3 fns incl. `fwide`), `fn_803FC8AC` (208 B; 52 insns; calls `fn_801D536C`/`fn_802285C0`/`fn_80228608`), `fn_803F602C` (204 B; 51 insns; calls `fn_803F619C`/`fn_803F6258`/`fn_803F6300`/`fn_803F63C0` still-auto); verified instruction-exact before merge; integrated through `9486138`; incomplete 3,302 → 3,299.
- **fifty-fifth–fifty-seventh units** (agent batch 9): `fn_803F5A88` (192 B; 48 insns), `dtor_803F0B20` (188 B; 47 insns; `__dl__FPv`), `fn_803F0DCC` (184 B; 46 insns; 4 fns — `__ptmf_test`, `__ptmf_scall` + 2); verified instruction-exact before merge; integrated through `35cc6d8`; incomplete 3,299 → 3,296.
- **fifty-eighth–sixtieth units** (agent batch 10): `fn_803F861C` (200 B; 50 insns; `__pformatter_803F7CFC`, `fwide`), `fn_803F86E4` (196 B; 49 insns; same calls), `fn_803FA1D0` (176 B; 44 insns; `exit`); verified instruction-exact before merge; integrated through `6d40e5e`; incomplete 3,296 → 3,293.
- **sixty-first–sixty-third units** (agent batch 11): `fn_803FC570` (168 B; 42 insns; calls matched `fn_803FBC7C`), `fn_803FA078` (144 B; 36 insns), `fn_803FBBF8` (132 B; 33 insns; calls matched `fn_803FA804`); verified instruction-exact before merge; integrated through `e94b99e`; incomplete 3,293 → 3,290.
- **sixty-fourth–sixty-sixth units** (agent batch 12): `fn_803F0D4C` (128 B; 32 insns; `__dla__FPv`), `fn_803F0E84` (128 B; 32 insns; `fn_803F2E4C`), `fn_803F64E8` (128 B; 32 insns; no calls); verified instruction-exact before merge; integrated through `d8e30c7`; incomplete 3,290 → 3,287.
- **sixty-seventh–sixty-ninth units** (agent batch 13): `fn_803F88A4` (128 B; 32 insns; `__pformatter_803F7CFC`), `fn_803FA798` (108 B; 27 insns; libc `strstr`), `fn_803F646C` (100 B; 25 insns; no calls); verified instruction-exact before merge; integrated through `cc839aa`; incomplete 3,287 → 3,284.
- **seventieth–seventy-second units** (agent batch 14): `fn_803F5EAC` (72 B; 18 insns; `_fseek`), `fn_803FC9BC` (64 B; 16 insns; `fn_804006F0`/`fn_80400778`), `fn_803FC984` (52 B; 13 insns; `exit`/`fn_803FA1D0`); verified instruction-exact before merge; integrated through `ce7cc58`; incomplete 3,284 → 3,281.
- **seventy-third–seventy-fifth units** (agent batch 15): `fn_803F8C3C` (40 B; 10 insns; 2 fns `rand`/`fn_803F8C5C`), `fn_803F64D0` (24 B; 6 insns), `fn_803F6568` (16 B; 4 insns; libc `__stdio_atexit`); verified instruction-exact before merge; integrated through `06231cf`; incomplete 3,281 → 3,278.
- **seventy-sixth–seventy-seventh units** (agent batch 16): `fn_803FC97C` (8 B; 2 insns), `fn_803FC9B8` (4 B; 1 insn); verified instruction-exact before merge; integrated through `417f167`; incomplete 3,278 → 3,276. Small 803F-unit pool exhausted (only `auto_03_803FC9FC_text` 39624 B remains in 803F).
- **seventy-eighth–seventy-ninth units** (agent batch 17): `fn_803F48B0` (1968 B; 492 insns; savegpr/restgpr, ~20 calls), `fn_803FC9FC` (172 B; 43 insns; 2 fns `stricmp`/`fn_803FCAA4`, first carve-out of the 39624-B C9FC libc block — remainder regenerates as `auto_03_803FCAA8_text`); verified instruction-exact before merge; integrated through `bb03932`; incomplete 3,276 → 3,274.
- **eightieth–eighty-first units** (agent batch 18): `fn_803FCAA8` (880 B; 220 insns; 3 fns `fn_803FCAA8`/`itoa`/`fn_803FCB54`), `fn_803FCE18` (1288 B; 322 insns; 2 fns `fn_803FCE18`/`fn_803FD0B0`); verified instruction-exact before merge; integrated through `9a4c1dc`; incomplete 3,274 → 3,272.
- **eighty-second–eighty-third units** (agent batch 19): `fn_803FD320` (1508 B; 377 insns; 2 fns `fn_803FD320`/`fn_803FD650`), `fn_803FD904` (2396 B; 599 insns; 2 fns `fn_803FD904`/`fn_803FDA18`); verified instruction-exact before merge; integrated through `0ab8fb9` (+`650640b` dtk blank-line separation); incomplete 3,272 → 3,270. C9FC libc block now carved through 0x803FE260 (6,852 B claimed of 39,624).
- **eighty-fourth–eighty-fifth units** (agent batch 20): `fn_803FE260` (1192 B; 298 insns; 2 fns `fn_803FE260`/`fn_803FE5F8`), `fn_803FE708` (5900 B; 1475 insns; single fn — largest transcription yet); verified instruction-exact before merge; integrated through `ea3e2fc` (+`fa65915` dtk blank-line separation); incomplete 3,270 → 3,268. C9FC libc block carved through 0x803FFE14 (13,948 B of 39,624 claimed).
- **eighty-sixth–eighty-seventh units** (agent batch 21): `fn_803FFE14` (792 B; 198 insns; 2 fns `fn_803FFE14`/`fn_803FFED4`), `fn_8040012C` (896 B; 224 insns; 2 fns `fn_8040012C`/`fn_8040036C`); verified instruction-exact before merge; integrated through `6608b4c` (+`9c7dff6` dtk blank-line separation); incomplete 3,268 → 3,266. C9FC libc block carved through 0x804004AC (15,636 B of 39,624 claimed).
- **eighty-eighth–eighty-ninth units** (agent batch 22): `fn_804004AC` (256 B; 64 insns; 2 fns `fn_804004AC`/`cos`), `fn_804006F0` (500 B; 125 insns; 2 fns `fn_804006F0`/`fn_80400778`); verified instruction-exact before merge; integrated through `af29cda` (+`acb333d` dtk blank-line separation); incomplete 3,266 → 3,264. C9FC libc block carved through 0x804008E4 (16,392 B of 39,624 claimed).
- **ninetieth–ninety-first units** (agent batch 23): `fn_804008E4` (468 B; 117 insns; 2 fns `fn_804008E4`/`sin` — recipe end corrected to authoritative 0x80400AB8), `fn_80400B30` (608 B; 152 insns; 7 tiny fns `fn_80400B30`/`fn_80400B34`/`atan2`/`fn_80400B3C`/`fn_80400B40`/`fn_80400B44`/`fn_80400B48`); verified instruction-exact before merge; integrated through `689f790` (+`93bc484` dtk blank-line separation); incomplete 3,264 → 3,262. C9FC libc block carved through 0x80400D90 (17,464 B of 39,624 claimed).
- **ninety-second–ninety-third units** (agent batch 24): `fn_80400D90` (292 B; 73 insns; 4 fns `fn_80400D90`/`fn_80400D94`/`TRKNubMainLoop`/`TRKDestructEvent`), `fn_8040123C` (284 B; 71 insns; 2 fns `fn_8040123C`/`fn_80401268`, first mid-range carve-out splitting the remainder into two auto units); verified instruction-exact before merge; integrated through `a9051f0` (+`6c555ba` dtk blank-line separation); incomplete 3,262 → 3,260.
- **ninety-fourth–ninety-fifth units** (agent batch 25): `fn_80401358` (384 B; 96 insns; 2 fns `fn_80401358`/`fn_804013F0`), `fn_804014D8` (356 B; 89 insns; 2 fns `fn_804014D8`/`fn_804015D4`); verified instruction-exact before merge; integrated through `465c230` (+`0f730ca` dtk blank-line separation); incomplete 3,260 → 3,258.
- **ninety-sixth–ninety-seventh units** (agent batch 26): `fn_8040163C` (392 B; 98 insns; 2 fns `fn_8040163C`/`fn_80401738`), `fn_804017C4` (212 B; 53 insns; 2 fns `fn_804017C4`/`fn_80401868`); verified instruction-exact before merge; integrated through `86006c8` (+`9609295` dtk blank-line separation); incomplete 3,258 → 3,256.
- **ninety-eighth–ninety-ninth units** (agent batch 27): `fn_80401898` (164 B; 41 insns; 2 fns `fn_80401898`/`fn_804018D8` — recipe end corrected to authoritative 0x8040193C, `TRKGetBuffer` stays auto), `fn_80401968` (360 B; 90 insns; 4 fns `fn_80401968`/`TRKInitializeMessageBuffers`/`fn_80401AA4`/`TRKInitializeSerialHandler`); verified instruction-exact before merge; integrated through `11fd3de` (+`8f6fafc` dtk blank-line separation); incomplete 3,256 → 3,254.
- **hundredth–hundred-first units** (agent batch 28): `fn_80401AD0` (176 B; 44 insns; 2 fns `fn_80401AD0`/`TRKGetInput` — recipe end corrected to authoritative 0x80401B80), `fn_80401C54` (456 B; 114 insns; 2 fns `fn_80401C54`/`TRKDispatchMessage`); verified instruction-exact before merge; integrated through `134207c` (+`5460156` dtk blank-line separation); incomplete 3,254 → 3,252.

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

### Completion audit (2026-09-28, commit `1ffc2d5`)

- Reproducibility: deleted `ok`, the matched unit object, and `objdiff-report.json`, then rebuilt — `ninja build/RSBE01_02/ok` → **127 files OK**; fresh `-d` report regenerates identical state (3,351 incomplete; `fn_8028A040` 100%; ft_purin 17/457, 6.18%).
- Coverage: 3,351 of 4,417 units incomplete = 22 source-mapped + 3,329 auto/original (~15,531,732 code bytes). First linked matching object: `sora/misc/fn_8028A040.cpp`.
- Open prerequisites (concrete): (1) scheduling-class units (14) need original-idiom recovery via Melee source comparison; (2) `ft_marth` (5 units, 0/510 fns) and `ft_purin` (17/457) need whole-file decompilation; (3) `__init_cpp_exceptions` (112 B) needs runtime-lib idioms; (4) 3,329 auto/original units need the splits→source→Matching recipe applied per unit; (5) ft_purin testBuilder() scaffolding must be replaced by reconstructed call paths before that unit can flip; (6) cross-module import `lbl_27_bss_1B18` (ft_purin → sora_melee) is resolved-by-evidence, pending full-link proof at ft_purin completion.

### Milestone status

- Milestones 1–3 complete (fork/checkout, verified baseline, target selection).
- Milestone 4 in progress. **First linked matching object achieved 2026-09-28: `sora/misc/fn_8028A040.cpp`** (8 B, `li r3,0; blr`, DOL `.text:0x8028A040..0x8028A048`) — converted from auto unit `auto_03_8028A040_text` via: append range to `config/RSBE01_02/splits.txt` under the source filename → `rm build/RSBE01_02/config.json && ninja build/RSBE01_02/config.json` (regenerates the unit with the source-mapped name) → add `Object(Matching, "sora/misc/fn_8028A040.cpp")` to the `sora` lib in `configure.py` → write source (`extern "C"` REQUIRED: plain C++ mangling produced `fn_8028A040__Fv` and failed the DOL link with `undefined: 'fn_8028A040'`) → `ninja build/RSBE01_02/ok` = 127/127. Incomplete units 3352→3351. This is the repeatable recipe for all 3,330 remaining auto/original units. Detailed findings below.

### `__init_cpp_exceptions` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/__init_cpp_exceptions` now links the rebuilt object — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d` report: unit 100% (112/112 code bytes, 20/20 data, 2/2 functions). Second linked matching unit (3,351→3,350 incomplete).
- **Source is hand-written assembly** (`src/Runtime.PPCEABI.H/__init_cpp_exceptions.s`), not C++. Reason (verified, not guessed): the extracted original object carries `.comment` metadata `Compiler version: 4.0.0.1` (MWCC 4.x), while this project pins MWCC 3.0a5.2. The C++ reconstruction reproduced both functions byte-exactly (proven: `register char* toc; asm { mr toc, r2 }` inlines the TOC read — `static asm` functions are NOT inlined by 3.0a5.2) and `static int fragmentID = -2` lands in `.sdata` correctly, **but 3.0a5.2 emits sections in the order `.text, .sdata, .ctors$10, .dtors$10, .dtors$15` while the original object is `.text, .ctors$10, .dtors$10, .dtors$15, .sdata` — and mwldeppc silently DROPS the `.ctors$10`/`.dtors$15` fragments when `.sdata` precedes them** (verified via link maps with `--map`: with our C++ object the DOL lost the `__init_cpp_exceptions_reference`/`__fini_cpp_exceptions_reference` entries and main.dol FAILED; no source/declaration permutation changed MWCC's section order). Assembly emits sections in declaration order, reproducing the original object layout exactly.
- **configure.py wiring**: unit name must stay `__init_cpp_exceptions.cpp` (it must match the dtk config.json unit key); the asm source is selected via `Object(Matching, "Runtime.PPCEABI.H/__init_cpp_exceptions.cpp", source="Runtime.PPCEABI.H/__init_cpp_exceptions.s")` — `Object.options["source"]` override, resolved by `file_is_asm` → GNU as path.
- **Build-system fix shipped**: `--defsym VERSION_{version}` in `config.asflags` lacked `=value`, a fatal GNU-as error for ANY asm source build (latent — no asm units were built before). Now `=1`.
- **GNU-as gotchas recorded for future asm units**: (1) forward-referenced local labels collapse `@sda21` relocations to the section symbol (addend-equivalent only when the symbol sits at section offset 0 — true for `fragmentID`, but avoid relying on it); define small-data labels BEFORE the code that uses them, or expect section-relative relocs. (2) sda21 operand must be written `sym@sda21(r13)` to match the original object's raw `ra=13` encoding. (3) `dtk elf fixup` post-processes asm objects for MW-linker compatibility.
- **Provenance**: structure follows doldecomp/melee `src/Runtime/__init_cpp_exceptions.c` (fragmentID −2 sentinel, `__register_fragment(_eti_init_info, TOC)`, ctors$10/dtors$10/dtors$15 reference objects). The `.sdata` "gap" (`gap_09_8059FF4C_sdata`, 4 zero bytes after `fragmentID`) is **linker padding, not a variable**: our object contributes only 4 `.sdata` bytes and the following auto unit's `.balign 8` recreates the pad at `0x8059FF4C` — DOL layout verified identical to the original link.
- Cleanups: `melee_probe/` sparse clone and all throwaway disasm/DOL/MAP test artifacts deleted.

### `Gecko_ExceptionPPC.c` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/Gecko_ExceptionPPC.c` (auto unit `auto_03_803F1A78_text`: `__register_fragment` 0x34, `__unregister_fragment` 0x30, `fn_803F1ADC` 0x88 — 236 code bytes + `fragmentinfo` 0xC `.bss`) links rebuilt — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 236/236 code, 12/12 data, 3/3 functions. Third linked matching unit (3,350→3,349 incomplete).
- **splits.txt multi-section claim**: the source entry claims BOTH `.text 0x803F1A78..0x803F1B64` AND `.bss 0x80599BE0..0x80599BEC` — the bss range was previously part of the giant `auto_08_8049ECF8_bss` auto unit, and defining `fragmentinfo` in this TU without claiming its bss range would double-define it at link. dtk handles the sub-range claim (auto bss unit now ends at 0x80599BE0). This is the pattern for every auto unit with cross-section state.
- **Symbol scope**: `fragmentinfo` is `scope:local` in symbols.txt → the variable must be `static` (tentative non-static = global symbol ≠ target). Functions are global.
- **fn_803F1ADC semantics** (derived purely from target asm; name kept from symbols.txt): exception-fragment address lookup — if `fragmentinfo[0].active` is set, walks the registered `__eti_init_info` table (16-byte entries: eti_start, eti_end, code_start, code_size) for the entry whose `[code_start, code_start+code_size)` contains `addr`, then fills a 0x20-byte out-struct `{eti_start, eti_end, 0,0,0,0, TOC, active}` and returns 1; returns 0 otherwise.
- **Matching idioms recovered (all verifyable in the diff history of this session)**:
  - `__register_fragment` needed **Melee's exact loop shape** (`for (i = 0, f = fragmentinfo; i < 1; ++i, ++f)` with `return i`) — a plain `if`-guard version differs by one scheduler swap (`li r0,1` hoisted above the first store). Melee's shape unrolls to identical scheduling. Flags swept (`-O3/-O2/-O4,s/-opt noschedule/±peephole`): default `-O4,p` with the loop shape is the only exact match.
  - `fn_803F1ADC` needed: pointer variable `pInfo = fragmentinfo` hoisted **above** the guard (single address materialization kept live in `r6` across the loop; per-access `fragmentinfo[0].x` made MWCC re-derive the address and clobber registers), and the loop wrapped in `if (pInfo->active != 0) { for (;;) { ... } }` with a single trailing `return 0` — this prevents MWCC's while-loop rotation (which duplicates the exit test) and merges both return-0 paths into one tail (target `beq .L_803F1B5C`).
  - `__unregister_fragment` matched Melee's source verbatim (`if (id >= 0 && id < 1)` guards + `&fragmentinfo[fragmentID]` pointer; MWCC emits the `mulli`/`stwux` fusion itself under default flags). `#pragma peephole off` BREAKS that fusion — do not use it here.
  - `#pragma section`+`__declspec` vs GCC `__attribute__((section))`: the latter rejects `$` in section names on MWCC.
- C89 declaration discipline: MWCC `-lang=c` rejects mid-block declarations; all declarations first.

### `fn_803F1B64` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F1B64` (auto unit `auto_fn_803F1B64_text`: `fn_803F1B64` 0x1B0 + `extab` 0x8 @ 0x80009534 + `extabindex` 0xC @ 0x8000C538) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 432/432 code, 20/20 data, 1/1 functions. Fourth linked matching unit (3,349→3,348 incomplete).
- **Source is hand-written asm** (`src/Runtime.PPCEABI.H/fn_803F1B64.s`, precedent: `__init_cpp_exceptions.s`). The C reconstruction (deleted `fn_803F1B64.cpp`, ~15 source-shape iterations) reproduced the exact 108-instruction sequence but never MWCC's register allocation: mulhw accumulator reg, key scratch (`r0` vs `r6`/`r30`), `low`/`count`/`mid`/table/entry colorings, and loop-head placement all shifted with every statement-order permutation tried (statement orders, `key` as variable vs inline vs parameter-reassignment, `int` vs `unsigned long` temp, typed-struct temp, `register` hints). MWCC's division-by-constant template wants the magic-constant register as the accumulator; whether `lis`/`subi` share a register is scheduler-internal and was not controllable from source. Per-section byte comparison of the asm-built object vs the extracted original: `.text`/`extab`/`extabindex`/relocations all IDENTICAL.
- **Wiring**: per-unit source in `splits.txt` must use the SAME name as the `configure.py` `Object(...)` entry (`.s` here) — a `.cpp:` splits entry with a `.s` Object silently produced no AS edge ("Missing configuration" warn) and the link kept the extracted object (127-OK was then meaningless for the unit). Watch for that warn on every new unit.
- **extab/extabindex facts** (for all future exception-carrying units): the original TU was compiled with `-Cpp_exceptions on` (per-unit `extra_cflags` — MWCC then emits the per-function `extab` (flags `0x10080000`: Large Frame, saved r30-r31, no FP/CR) and `extabindex` (`{fn_start, fn_size, extab_ptr}`) fragments automatically; GNU-as units must emit these sections by hand. `.section extab, "a"` / `.section extabindex, "a"` + `.balign 4`, objects declared with the `.obj`/`.endobj` macros from `macros.inc`; `dtk elf fixup` post-processes (ninja `as` rule does this).
- **fn_803F1B64 semantics** (derived from target asm): exception throw-helper. Prologue zeroes `out[0]`/`out[2]`; calls `fn_803F1ADC(addr, sp+8)`; returns 0 (callee's r3) if unregistered. Copies `{code_start, unk4, TOC}` (descriptor words 2/4/6) to `out[3..5]`; `key = addr - code_start`; `high = (eti_end - eti_start) / 12` (MWCC magic `0x2AAAAAAB`, `mulhw`+`srawi 1`+sign-fix); top-tested binary search over 12-byte eti entries `{start, size31|flags<<31, value}`; on hit: `out[1] = code_start + entry.start` (absolute), actions = `(size_flags & 0x80000000) ? &entry.value : TOC + entry.value`, `out[0] = actions`; `rel = key - entry.start`; bit 3 (`extrwi. 1,28`) of the actions header u16 selects record format: clear → word-keyed stride-8 `{u32 key, u16 span<<2, u16 off}` walk with `sum = key + (span<<2)` computed unconditionally; set → halfword-keyed stride-6 `{u16 key, u16 end, u16 off}` walk; both loop on `while ((k = *rec) != 0)` and write `out[2] = actions + off` on `key <= rel <= end`. No return-value store on the hit path — falls through with `li r3, 1`.
- `objdiff.json`: new units need a `base_path` (and `complete`/`source_path` metadata) added to their entry or the report has no match counters for them.
- **Next runtime-lib candidates**: `auto_fn_803F1EC4_text` (0x578).

### `fn_803F1D14` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F1D14` (auto unit `auto_fn_803F1D14_text`: `fn_803F1D14` 0x1B0 + `extab` 0x8 @ 0x8000953C + `extabindex` 0xC @ 0x8000C544) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 432/432 code, 20/20 data, 1/1 functions. Fifth linked matching unit (3,348→3,347 incomplete).
- **Source is hand-written asm** (`fn_803F1D14.s`), transcribed mechanically from the target disasm (fn_803F1B64.s precedent). Same `extab` flags (`0x10080000`).
- **NOT a clone of fn_803F1B64** (only 3 of 108 aligned rows identical): this is the exception-**propagation** walk — a state machine (byte flags via `rlwinm. r,24,24` bit tests, `srawi.` shift tests) that calls `fn_803F1B64` (our previous unit — first cross-unit call between linked runtime units), `fn_803F07D4` (an adjacent auto unit, not yet matched), and dispatches through jump table `jumptable_80493D90` (`.data`, owned by another unit — undefined external resolved at link). Frame is 0x10 bytes; saves r30/r31 only.
- Wiring recipe refined: splits entry + `Object(Matching, ".../X.s")` + manual `objdiff.json` entry (name/target_path/base_path/metadata) → `rm build/RSBE01_02/config.json && ninja config.json` → verify no "Missing configuration" warn → `127 files OK` → objdiff 100%.
- **Next candidate completed below**: `fn_803F1EC4`.

### `fn_803F1EC4` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F1EC4` (auto unit `auto_fn_803F1EC4_text`: `fn_803F1EC4` 0x578 + `extab` 0x8 @ 0x80009544 + `extabindex` 0xC @ 0x8000C550) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 1400/1400 code, 20/20 data, 1/1 functions. Sixth linked matching unit (3,347→3,346 incomplete).
- **Source is hand-written asm** (`fn_803F1EC4.s`), mechanically transcribed. No data relocations; `.text` has 2 call relocations (`_savegpr_27`, `_restgpr_27`), saves r27-r31 via `_savegpr_27`/`_restgpr_27` (owned by `auto_03_803F11E0_text`, resolved at link — first calls into that unit).
- **Gotcha fixed**: the MW extab flags word is per-function — EC4 uses `0x280A0000` (Has Elf Vector: Yes, Large Frame, saved GPR r27-r31) vs B64/D14's `0x10080000` (No Elf Vector, saved r30-r31). First DOL-hash attempt failed solely on this byte; always read the dtk flag comment in the target unit disasm when writing the `.s` extab by hand.
- The contiguous exception-runtime cluster `0x803F1A78..0x803F243C` is now fully linked-matching source: `Gecko_ExceptionPPC.c` → `fn_803F1B64.s` → `fn_803F1D14.s` → `fn_803F1EC4.s`.

### `fn_803F07D4` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F07D4` (12 code bytes; carved out of the giant `auto_03_803D620C_text`, which shrank 108,560→107,976) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 12/12 code, 1/1 functions. Seventh linked matching unit (3,346→3,345 incomplete).
- It is a 3-instruction tail-call trampoline: `lwz r12, lbl_8059FF28@sda21(r0)` / `mtctr` / `bctr` — dispatches through a function pointer in `.sdata` (owner: `lbl_8059FF28` = 8-byte object @ 0x8059FF28, resolved at link). Called by `fn_803F1D14` — that dependency is now fully matched.
- **C-attempt blocker: `__prep_buffer` (unit `fn_803F5060`)** — 2026-09-28. `fn_803F5060` (`x < 0 ? -x : x`) is byte-exact in C with project flags. `__prep_buffer` is not: ~30 C variants (declaration/statement permutations, temp-vs-named for all four field reads, both `&` operand orders, all 6 store orders, pointer-typed fields, both-fns-one-TU, all usable GC compiler versions 3.0a3–3.0a5.2) never reproduce the target register coloring `x18→r4, x2c→r0, x1c→r6, x20→r5`; best variants (`unsigned long size = f->x20; f->x24 = f->x1c; f->x28 = size - (f->x18 & f->x2c); f->x34 = f->x18;`) match 8/10 instructions but swap the `x1c`/`x20` colors (r5/r6). Semantics are proven (same instruction set, stores identical); only MWCC 3.0a5.2's schedule-dependent coloring differs. Unit stays asm; the abs helper keeps working C as documentation of the proven form. This is the second documented C-unmatchable case after fn_803F1B64.
- **C-first policy (2026-09-28)**: PLAN.md's goal is reconstructed C/C++. New runtime units get a C attempt first; asm is reserved for units where C demonstrably cannot match (the fn_803F1B64 register-allocation case; the standalone `__prep_buffer`). Lesson from fn_803F5098: an inlined static helper can match where the standalone function cannot — try defining helpers `static inline` in the same TU before declaring a coloring unmatchable. Small GPR/FPR save-restore stubs, syscall trampolines (`fn_803F07D4`), and compiler-helper math (__div2u etc.) are canonical asm in MW's own runtime library — those stay asm without a C attempt.
- **Carving recipe** (claiming a function from inside an auto unit): add a splits.txt entry with exactly the function's `.text` range — `dtk dol split` re-splits the surrounding region automatically (no manual edit of neighboring ranges needed). No extab/extabindex for non-exception-scoped functions.

### `fn_803F243C` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F243C` (auto unit `auto_fn_803F243C_text`: `fn_803F243C` 0x50C + `extab` 0x14 @ 0x8000954C + `extabindex` 0xC @ 0x8000C55C) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 1292/1292 code, 32/32 data, 1/1 functions. Eighth linked matching unit (3,345→3,344 incomplete).
- Hand-written asm. First unit with a **non-trivial extab**: 0x14 bytes — flags `0x50080000` (saved GPR r22-r31), an action-table offset word `0x54`, and real PC/exception actions (`PC=0x4E8 → Action TERMINATE with end bit + NULL` entries, words `0x01250010 0x00000000 0x8E000000`). dtk's parsed flag/action comment above each `.obj` in the target disasm is the transcription source — copy the `.4byte` values verbatim, don't try to re-encode.
- Calls `fn_803F07D4`, `fn_803F1B64`, `fn_803F1EC4`; references `jumptable_80493DD4` (external `.data`, link-resolved).

### `fn_803F2A4C` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F2A4C` (auto unit `auto_fn_803F2A4C_text`: `fn_803F2A4C` 0x400 + `extab` 0x14 @ 0x80009560 + `extabindex` 0xC @ 0x8000C568) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 1024/1024 code, 32/32 data, 1/1 functions. Ninth linked matching unit (3,344→3,343 incomplete).
- Hand-written asm; extab `0x30080000` (saved GPR r26-r31) + TERMINATE/NULL actions, `jumptable_80493E18` external ref, no calls.

### `runtime_emu_803F11E0` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/runtime_emu_803F11E0` (auto unit `auto_03_803F11E0_text`: 16 functions, 0x828 code, no extab) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 2088/2088 code, 16/16 functions. Tenth linked matching unit (3,343→3,342 incomplete).
- MW runtime emulation helpers, transcribed as one asm unit: `__cvt_fp2unsigned`, `__save_fpr`/`__restore_fpr` + `__save_gpr`/`__restore_gpr` with all 72 `_savefpr_XX`/`_restfpr_XX`/`_savegpr_XX`/`_restgpr_XX` (XX=14..31) entry `.sym` labels (these are the externals referenced by compiler-generated prologues in our other units — fn_803F1EC4 calls `_savegpr_27`/`_restgpr_27` here), 64-bit unsigned div/mod (`__div2u`, `__mod2u`), signed 64-bit div/mod (`fn_803F1470`, `fn_803F168C`), 64-bit shift helpers (`fn_803F1798` = shift-left-double, `fn_803F17BC` = shift-right-unsigned-double), and double→u64/s64 conversions (`fn_803F17E0`, `__cvt_dbl_ull`, `fn_803F1960`).
- Data refs: `lbl_80493D80`/`lbl_80493D74` (getters fn_803F11E0/fn_803F11EC return them) and `lbl_8041F460` (fp conversion constant table) — all external, link-resolved.

### `fn_803F2948` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F2948` (auto unit `auto_03_803F2948_text`: `fn_803F2948` 0x104, no extab, no refs) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 260/260 code, 1/1 functions. Eleventh linked matching unit (3,342→3,341 incomplete). Hand-written asm; fills the gap between `fn_803F243C` and `fn_803F2A4C`.

### `fn_803F2E4C` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F2E4C` (auto unit `auto_03_803F2E4C_text`: `fn_803F2E4C` + `fn_803F2F90`, 0x1FC code, no extab) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 508/508 code, 2/2 functions. Twelfth linked matching unit (3,341→3,340 incomplete). Hand-written asm; refs `lbl_8041F478` (rodata) + `lbl_8059E9B0` (.sdata) external. Only the named units are matched — still-auto gaps remain between them (e.g. `auto_03_803F07E0_text`, `auto_03_803F0D4C_text`, `auto_03_803F0DCC_text`, `auto_fn_803F0E84_text`, `auto_fn_803F0F04_text`, `auto_fn_803F11A0_text`).

### `fn_803F3048` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F3048` (auto unit `auto_fn_803F3048_text`: `fn_803F3048` 0x150 + `extab` 0x8 @ 0x80009574 + `extabindex` 0xC @ 0x8000C574) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 336/336 code, 20/20 data, 1/1 functions. Thirteenth linked matching unit (3,340→3,339 incomplete). Hand-written asm; extab `0x10080000` (saved r30-r31); calls `fn_803F3198`.

### `fn_803F3198` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F3198` (auto unit `auto_03_803F3198_text`: `fn_803F3198` 0xA8, no extab, no refs) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 168/168 code, 1/1 functions. Fourteenth linked matching unit (3,339→3,338 incomplete). Hand-written asm.

### `fn_803F3240` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F3240` (auto unit `auto_fn_803F3240_text`: `fn_803F3240` 0x1EC + `extab` 0x8 @ 0x8000957C + `extabindex` 0xC @ 0x8000C580) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 492/492 code, 20/20 data, 1/1 functions. Fifteenth linked matching unit (3,338→3,337 incomplete). Hand-written asm; extab `0x10080000`, ref `lbl_8041F4E8` (rodata) external.

### `fn_803F342C` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F342C` (auto unit `auto_fn_803F342C_text`: `fn_803F342C` 0x130 + `extab` 0x8 @ 0x80009584 + `extabindex` 0xC @ 0x8000C58C) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 304/304 code, 20/20 data, 1/1 functions. Sixteenth linked matching unit (3,337→3,336 incomplete). Hand-written asm; refs `lbl_80599BF0` (rodata) + `lbl_805A12D8` (.sdata2) external.

### `__close_all` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/__close_all` (named auto unit `auto_close_all_text`: `__close_all` 0xA4 + `extab` 0x8 @ 0x8000958C + `extabindex` 0xC @ 0x8000C598) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 164/164 code, 20/20 data, 1/1 functions. Seventeenth linked matching unit (3,336→3,335 incomplete). MW stdio `__close_all` (closes all open FILE streams); extab `0x18080000`; ref `__files` external. Hand-written asm.

### `fn_803F3600` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F3600` (auto unit `auto_fn_803F3600_text`: `fn_803F3600` 0x84 + `extab` 0x8 @ 0x80009594 + `extabindex` 0xC @ 0x8000C5A4) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 132/132 code, 20/20 data, 1/1 functions. Eighteenth linked matching unit (3,335→3,334 incomplete). Hand-written asm; extab `0x10080000`; calls `fn_803F5954` (still-auto unit), refs `__files`.

### `fn_803F3684` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F3684` (auto unit `auto_fn_803F3684_text`: `fn_803F3684` 0x6C + `extab` 0x8 @ 0x8000959C + `extabindex` 0xC @ 0x8000C5B0) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 108/108 code, 20/20 data, 1/1 functions. Nineteenth linked matching unit (3,334→3,333 incomplete). Hand-written asm; extab `0x10080000`; calls `fn_803F5954` (still-auto unit), refs `__files`.

### `fn_803F36F0` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F36F0` (auto unit `auto_fn_803F36F0_text`: `fn_803F36F0` 0xDC + `extab` 0x8 @ 0x800095A4 + `extabindex` 0xC @ 0x8000C5BC) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 220/220 code, 20/20 data, 1/1 functions. Twentieth linked matching unit (3,333→3,332 incomplete). Hand-written asm; extab `0x18080000`; calls `__div2u`/`__mod2u` (runtime_emu_803F11E0).

### `fn_803F37CC` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F37CC` (auto unit `auto_fn_803F37CC_text`: `fn_803F37CC` 0x288 + `extab` 0x8 @ 0x800095AC + `extabindex` 0xC @ 0x8000C5C8) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 648/648 code, 20/20 data, 1/1 functions. Twenty-first linked matching unit (3,332→3,331 incomplete). Hand-written asm; extab `0x18080000`, no external refs.

### `fn_803F3A54` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F3A54` (auto unit `auto_03_803F3A54_text`: `fn_803F3A54` 0xEC, no extab, no refs) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 236/236 code, 1/1 functions. Twenty-second linked matching unit (3,331→3,330 incomplete). Hand-written asm.

### `fn_803F3B40` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F3B40` (auto unit `auto_fn_803F3B40_text`: `fn_803F3B40` 0x36C + `extab` 0x8 @ 0x800095B4 + `extabindex` 0xC @ 0x8000C5D4) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 876/876 code, 20/20 data, 1/1 functions. Twenty-third linked matching unit (3,330→3,329 incomplete). Hand-written asm; extab `0x10080000`, refs `jumptable_80493FA0` (.data) + `lbl_8041F500` (rodata) external.

### `fn_803F3EAC` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F3EAC` (auto unit `auto_03_803F3EAC_text`: `fn_803F3EAC` + `fn_803F3F90`, 0x1E4 code @ 0x803F3EAC..0x803F4090, no extab) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 484/484 code, 2/2 functions. Twenty-fourth linked matching unit (3,329→3,328 incomplete). Hand-written asm.
- **Gotcha**: unit end = last instruction address + 4, NOT the next unit's fn start — dtk refuses ranges that end *inside* a symbol (`... ends within symbol 'fn_803F4090' (0x803F4090..0x803F45AC)`). Derive the end from the disasm's last row, don't guess from neighbors.

### `fn_803F4090` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F4090` (auto unit `auto_fn_803F4090_text`: `fn_803F4090` 0x51C + `extab` 0x8 @ 0x800095BC + `extabindex` 0xC @ 0x8000C5E0) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 1308/1308 code, 20/20 data, 1/1 functions. Twenty-fifth linked matching unit (3,328→3,327 incomplete). Hand-written asm; extab `0x68080000` (largest saved-GPR range yet: r20-r31 + FPR saves), no external refs or calls.

### `fn_803F45AC` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F45AC` (auto unit `auto_fn_803F45AC_text`: `fn_803F45AC` 0x164 + `extab` 0x8 @ 0x800095C4 + `extabindex` 0xC @ 0x8000C5EC) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 356/356 code, 20/20 data, 1/1 functions. Twenty-sixth linked matching unit (3,327→3,326 incomplete). Hand-written asm; extab `0x18480000`; calls `fn_803F1960`, `fn_803F36F0`, `fn_803F37CC`, `fn_803F3B40`, `fn_803F64D0`, `fn_803F64E8`, `fn_804006F0`, `fn_80400778`; ref `lbl_805A4B68` (.sdata2) external.

### `fn_803F4710` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F4710` (auto unit `auto_fn_803F4710_text`: `fn_803F4710` 0x1A0 + `extab` 0x8 @ 0x800095CC + `extabindex` 0xC @ 0x8000C5F8) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 416/416 code, 20/20 data, 1/1 functions. Twenty-seventh linked matching unit (3,326→3,325 incomplete). Hand-written asm; extab `0x10080000`; calls `fn_803F45AC`.

### `fn_803F5060` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F5060` (auto unit `auto_03_803F5060_text`: `fn_803F5060` + `__prep_buffer` 0x38 total, no extab, no refs) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 56/56 code, 2/2 functions. Twenty-eighth linked matching unit (3,325→3,324 incomplete). Hand-written asm.
- **Accepted (C-first success)**: `Runtime.PPCEABI.H/fn_803F5098` (auto unit `auto_fn_803F5098_text`: `fn_803F5098` + extab 0x8 @ 0x800095DC + extabindex 0xC @ 0x8000C610, 0xFC code) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 252/252 code, 20/20 data, 1/1 functions. Twenty-ninth linked matching unit (3,325→3,324 incomplete). RECONSTRUCTED IN C — first C-matched unit: MSL `__write_buffer`; `__prep_buffer` defined `static inline` in the same TU and fully inlined by MWCC (its standalone form is the C-unmatchable `fn_803F5060` unit), `-Cpp_exceptions on` via per-unit `extra_cflags` for the extab/extabindex sections; calls `f->[0x3c]` through a function pointer, reloads `f->x28` for the out-param, early-returns the raw write result when nonzero, else advances `buffer` by `buffer_length` and rescans `buffer_base` counting newline bytes unless FILE flag bit 19 (`(x4 >> 19) & 1`) is set; returns 0. The 1c/2c register-color swap that blocked the standalone `__prep_buffer` does NOT occur in the inlined context — the v17 shape matches exactly when inlined.

### Target investigations (evidence, not accepted work)

1. `mt_vector_old.cpp` `vlRotateFix` (280 B, 98%): target allocates `cos(theta)` to `f5`; current build allocates `f2`. Declaration-order permutations (temps-first, sin/cos-first, load reorder) do not change the allocation. Source restored to upstream; blocked.
2. `ip_network_producer.cpp` `networkInCallback` (244 B, 98.5%): reconstructed instruction **sequence** is identical for all 62 words; only register roles differ — target assigns producer pointer→`r7`/cursor→`r6`, our build assigns pointer→`r6`/cursor→`r7` (plus `add` operand order from the same swap). Tried: byte-alias vs struct-field access forms, cursor/pointer declaration order, `int` cursor, explicit `u8 b = r7[0]` local, ternary clamp, separate `r4 = r7 + unk0` base for the `unk1` store, `u16*` message base — none changed the allocation (21-word best). Working tree restored to upstream.
3. `cm_controller_menu_fixed.cpp` `init` (108 B, 23.2%): target writes `unkFA` as three u16 RMW stores on `0xfa` accumulating from the ORIGINAL value (`|0x80`, `|0x82`, `|0x82|0x40`) with `lwz r5, 0x0(r3)` cached once and two dead `stfs f0` spill slots; the final `|0x40` sets `gfCamera::TransformFlag::m_rotate` (0x40 per header), NOT `m_flag2` (0x4) — **the reconstructed source's `m_flag2 = true` was a semantic error, corrected 2026-09-28 to `m_rotate`**. With the corrected flag the *value sequence* is identical; the remaining delta is shape, not semantics: bool-bitfield writes (`m_flag7 = true`) compile to byte RMW on `0xfb`; writing `unkFA.m_mask |= 0x80/0x2/0x40` with a `gfCamera&` local reproduces the accumulating u16 RMW with identical stored values (orig|0x80, orig|0x82, orig|0xC2) but 23 vs 27 words — target keeps a spill frame (`stwu -0x10` + two dead `stfs f0, 0x8/0xc(r1)`) and distributes the masks across three `ori` on different registers, ours has no frame and folds to a single `ori r0, r5, 0xc2` for the last store. Scalar `m_rot.m_x/y/z = 0.0f` (no `Vec3f` temporary — the temp adds a third spill slot) is closest. Remaining delta = dead-spill/frame + reg-role class (same class as findings 2/4/6), NOT a semantic error; `fn_800A69AC` shares the corrected `m_rotate` meaning for its `0x40` store.
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
3. **Incomplete-unit inventory (2026-09-28 report)**: 3,351 of 4,417 units are incomplete = **22 non-auto units with source mapping** (the active reconstruction backlog, listed in the report; triage below) + **3,329 auto/original units (~15.53 MB code)** — machine-split pieces of the original DOL/RELs not yet assigned to source units. The auto units are the long-term bulk of Milestone-4 scope; the systematic loop is: pick a small auto split → add its range to `splits.txt` → write source → flip `Matching` → hash-verify (recipe proven on `fn_8028A040`, see Milestone status).
   - Non-auto triage: (a) regswap/scheduling class — `mt_vector_old`, `mt_trig`, `ip_network_producer`, `ut_relocate`, `nt_send`, `nt_report`, `em_external_value_accesser`, `ac_cmd_interpreter`, `gf_task_scheduler`, `gf_slow_manager`, `ty_fig_listmng`, `st_emblem`, `sc_adv_gameover`, `cm_controller_menu_fixed` (all ≥34.8%, most ≥97%, blocked on scheduling-class idioms; upstream has partial C sources landed for `mt_trig` #122, `nt_report` #124, `nt_send` #125 — still `Object(NonMatching, ...)`, worth rebasing our regswap work against those sources); (b) unimplemented bulk — `ft_marth` (5 units, 439+ fns, 0%), `ft_purin` (17/457, 6.18%); (c) runtime lib — `__init_cpp_exceptions`, `Gecko_ExceptionPPC.c`, `fn_803F1B64`, `fn_803F1D14`, `fn_803F1EC4`, `fn_803F07D4`, `runtime_emu_803F11E0`, `fn_803F243C`, `fn_803F2948`, `fn_803F2A4C`, `fn_803F2E4C`, `fn_803F3048`, `fn_803F3198`, `fn_803F3240`, `fn_803F342C`, `__close_all`, `fn_803F3600`, `fn_803F3684`, `fn_803F36F0`, `fn_803F37CC`, `fn_803F3A54`, `fn_803F3B40`, `fn_803F3EAC`, `fn_803F4090`, `fn_803F45AC`, `fn_803F4710`, and `fn_803F5098` all **DONE 2026-09-28** (see checkpoints above; only these named units are matched — still-auto gaps remain between them, e.g. `auto_03_803F07E0_text` 0x23C, `auto_03_803F0D4C_text` 0x80, `auto_03_803F0DCC_text` 0xB8, `auto_fn_803F0E84_text` 0x80, `auto_fn_803F0F04_text` 0x40, `auto_fn_803F11A0_text` 0x40, `auto_fn_803F48B0_text` 0x7B0).
   - **ft_purin precedent (2026-09-28)**: the 8 named `soAnimCmd`-cluster functions matched once emitted (see Accepted state); incremental function backlog remains — next candidates: the small anonymous-function family `fn_124_A9D0…B028` (7× 52B, stride 0xE8, self-contained: `bit7(byte@5)` gate + `byte@6` check + tail-call vtable slot 0xC — pattern-identical bodies, need an owner class context to emit as real methods), or the 0x14-byte group at `0x80C4–0x823C`. For any future unit with header-inline class methods, remember: emission (a use site or vtable reference in the TU) is the prerequisite, and `-d` dedup scoring exposes weak-symbol matches. CAVEAT: the testBuilder() emission references are SCAFFOLDING inside a `FIXME: Test code ... delete once ftPurin is done` function — they force-emit code but are not real uses; when the owning classes/vtables are reconstructed, replace the scaffolding with genuine construction paths so the emitted code comes from reconstructed call sites (purin remains incremental function backlog, not the first-linked-object gate — that is now `fn_8028A040`).
4. When an object matches end-to-end: flip its `configure.py` entry to `Object(Matching, ...)`, `python configure.py && ninja`, verify 127/127 hashes, regenerate `build/RSBE01_02/report.json`, and record the progress delta here.

## References

- Upstream repository and build instructions: https://github.com/doldecomp/brawl
- Brawl progress: https://decomp.dev/doldecomp/brawl
- Melee progress: https://decomp.dev/doldecomp/melee
- Existing Brawl headers: https://github.com/Sammi-Husky/BrawlHeaders
- Functional module reimplementations: https://github.com/Sammi-Husky/BrawlModules
- Object comparison tooling: https://github.com/encounter/objdiff
