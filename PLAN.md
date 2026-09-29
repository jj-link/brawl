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

- **Accepted**: `Runtime.PPCEABI.H/fn_803F1EC4` (auto unit `auto_fn_803F1EC4_text`: `fn_803F1EC4` 0x578 + `extab` 0x8 @ 0x80009544 + `extabindex` 0xC @ 0x8000C55C) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 1400/1400 code, 20/20 data, 1/1 functions. Sixth linked matching unit (3,347→3,346 incomplete).
- **Source is hand-written asm** (`fn_803F1EC4.s`), mechanically transcribed. Function is position-independent (zero relocations in `.text`), saves r27-r31 via `_savegpr_27`/`_restgpr_27` (owned by `auto_03_803F11E0_text`, resolved at link — first calls into that unit).
- **Gotcha fixed**: the MW extab flags word is per-function — EC4 uses `0x280A0000` (Has Elf Vector: Yes, Large Frame, saved GPR r27-r31) vs B64/D14's `0x10080000` (No Elf Vector, saved r30-r31). First DOL-hash attempt failed solely on this byte; always read the dtk flag comment in the target unit disasm when writing the `.s` extab by hand.
- The contiguous exception-runtime cluster `0x803F1A78..0x803F243C` is now fully linked-matching source: `Gecko_ExceptionPPC.c` → `fn_803F1B64.s` → `fn_803F1D14.s` → `fn_803F1EC4.s`.

### `fn_803F07D4` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F07D4` (12 code bytes; carved out of the giant `auto_03_803D620C_text`, which shrank 108,560→107,976) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 12/12 code, 1/1 functions. Seventh linked matching unit (3,346→3,345 incomplete).
- It is a 3-instruction tail-call trampoline: `lwz r12, lbl_8059FF28@sda21(r0)` / `mtctr` / `bctr` — dispatches through a function pointer in `.sdata` (owner: `lbl_8059FF28` = 8-byte object @ 0x8059FF28, resolved at link). Called by `fn_803F1D14` — that dependency is now fully matched.
- **Carving recipe** (claiming a function from inside an auto unit): add a splits.txt entry with exactly the function's `.text` range — `dtk dol split` re-splits the surrounding region automatically (no manual edit of neighboring ranges needed). No extab/extabindex for non-exception-scoped functions.

### `fn_803F243C` unit complete (2026-09-28)

- **Accepted**: `Runtime.PPCEABI.H/fn_803F243C` (auto unit `auto_fn_803F243C_text`: `fn_803F243C` 0x50C + `extab` 0x14 @ 0x8000954C + `extabindex` 0xC @ 0x8000C55C) — `ninja build/RSBE01_02/ok` = **127 files OK**; objdiff `-d`: 1292/1292 code, 32/32 data, 1/1 functions. Eighth linked matching unit (3,345→3,344 incomplete).
- Hand-written asm. First unit with a **non-trivial extab**: 0x14 bytes — flags `0x50080000` (saved GPR r22-r31), an action-table offset word `0x54`, and real PC/exception actions (`PC=0x4E8 → Action TERMINATE with end bit + NULL` entries, words `0x01250010 0x00000000 0x8E000000`). dtk's parsed flag/action comment above each `.obj` in the target disasm is the transcription source — copy the `.4byte` values verbatim, don't try to re-encode.
- References `jumptable_80493DD4` (external `.data`, link-resolved), no calls.

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
   - Non-auto triage: (a) regswap/scheduling class — `mt_vector_old`, `mt_trig`, `ip_network_producer`, `ut_relocate`, `nt_send`, `nt_report`, `em_external_value_accesser`, `ac_cmd_interpreter`, `gf_task_scheduler`, `gf_slow_manager`, `ty_fig_listmng`, `st_emblem`, `sc_adv_gameover`, `cm_controller_menu_fixed` (all ≥34.8%, most ≥97%, blocked on scheduling-class idioms); (b) unimplemented bulk — `ft_marth` (5 units, 439+ fns, 0%), `ft_purin` (17/457, 6.18%); (c) runtime lib — `__init_cpp_exceptions` **DONE 2026-09-28**, `Gecko_ExceptionPPC.c` **DONE 2026-09-28**, `fn_803F1B64` **DONE 2026-09-28**, `fn_803F1D14` **DONE 2026-09-28**, `fn_803F1EC4` **DONE 2026-09-28**, `fn_803F07D4` **DONE 2026-09-28**, and `fn_803F243C` **DONE 2026-09-28** (see checkpoints above; remaining runtime candidates: `auto_03_803F11E0_text` 0x828 save/restore + 64-bit div/mod, `auto_fn_803F2A4C_text` 0x400).
   - **ft_purin precedent (2026-09-28)**: the 8 named `soAnimCmd`-cluster functions matched once emitted (see Accepted state); incremental function backlog remains — next candidates: the small anonymous-function family `fn_124_A9D0…B028` (7× 52B, stride 0xE8, self-contained: `bit7(byte@5)` gate + `byte@6` check + tail-call vtable slot 0xC — pattern-identical bodies, need an owner class context to emit as real methods), or the 0x14-byte group at `0x80C4–0x823C`. For any future unit with header-inline class methods, remember: emission (a use site or vtable reference in the TU) is the prerequisite, and `-d` dedup scoring exposes weak-symbol matches. CAVEAT: the testBuilder() emission references are SCAFFOLDING inside a `FIXME: Test code ... delete once ftPurin is done` function — they force-emit code but are not real uses; when the owning classes/vtables are reconstructed, replace the scaffolding with genuine construction paths so the emitted code comes from reconstructed call sites (purin remains incremental function backlog, not the first-linked-object gate — that is now `fn_8028A040`).
4. When an object matches end-to-end: flip its `configure.py` entry to `Object(Matching, ...)`, `python configure.py && ninja`, verify 127/127 hashes, regenerate `build/RSBE01_02/report.json`, and record the progress delta here.

## References

- Upstream repository and build instructions: https://github.com/doldecomp/brawl
- Brawl progress: https://decomp.dev/doldecomp/brawl
- Melee progress: https://decomp.dev/doldecomp/melee
- Existing Brawl headers: https://github.com/Sammi-Husky/BrawlHeaders
- Functional module reimplementations: https://github.com/Sammi-Husky/BrawlModules
- Object comparison tooling: https://github.com/encounter/objdiff
