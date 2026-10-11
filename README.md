Super Smash Bros. Brawl  
[![Build Status]][actions] [![Code Progress]][progress] [![Data Progress]][progress] [![Discord Badge]][discord]
=============

[Build Status]: https://github.com/doldecomp/brawl/actions/workflows/build.yml/badge.svg
[actions]: https://github.com/doldecomp/brawl/actions/workflows/build.yml
[Code Progress]: https://decomp.dev/doldecomp/brawl.svg?mode=shield&measure=code&label=Code
[Data Progress]: https://decomp.dev/doldecomp/brawl.svg?mode=shield&measure=data&label=Data
[progress]: https://decomp.dev/doldecomp/brawl
[Discord Badge]: https://img.shields.io/discord/727908905392275526?color=%237289DA&logo=discord&logoColor=%23FFFFFF
[discord]: https://discord.gg/hKx3FJJgrV

A work-in-progress decompilation of Super Smash Bros. Brawl.

This repository does **not** contain any game assets or assembly whatsoever. An existing copy of the game is required.

Supported versions:

<!--
- `RSBJ01_00`: Japan Rev 0
- `RSBJ01_01`: Japan Rev 1
- `RSBE01_01`: USA Rev 1
-->
- `RSBE01_02`: USA Rev 2
<!--
- `RSBP01_00`: PAL Rev 0
- `RSBP01_01`: PAL Rev 1
- `RSBK01_00`: Korea Rev 0
-->

Dependencies
============

Windows
--------

On Windows, it's **highly recommended** to use native tooling. WSL or msys2 are **not** required.  
When running under WSL, [objdiff](#diffing) is unable to get filesystem notifications for automatic rebuilds.

- Install [Python](https://www.python.org/downloads/) and add it to `%PATH%`.
  - Also available from the [Windows Store](https://apps.microsoft.com/store/detail/python-311/9NRWMJP3717K).
- Download [ninja](https://github.com/ninja-build/ninja/releases) and add it to `%PATH%`.
  - Quick install via pip: `pip install ninja`

macOS
------

- Install [ninja](https://github.com/ninja-build/ninja/wiki/Pre-built-Ninja-packages):

  ```sh
  brew install ninja
  ```

- Install [wine-crossover](https://github.com/Gcenx/homebrew-wine):

  ```sh
  brew install --cask --no-quarantine gcenx/wine/wine-crossover
  ```

After OS upgrades, if macOS complains about `Wine Crossover.app` being unverified, you can unquarantine it using:

```sh
sudo xattr -rd com.apple.quarantine '/Applications/Wine Crossover.app'
```

Linux
------

- Install [ninja](https://github.com/ninja-build/ninja/wiki/Pre-built-Ninja-packages).
- For non-x86(_64) platforms: Install wine from your package manager.
  - For x86(_64), [wibo](https://github.com/decompals/wibo), a minimal 32-bit Windows binary wrapper, will be automatically downloaded and used.

Building
========

- Clone the repository:

  ```sh
  git clone https://github.com/doldecomp/brawl.git
  ```

- Update and Initialize submodules:

  ```sh
  git submodule update --init --recursive
  ```

- Copy your game's disc image to `orig/RSBE01_02` (or the appropriate version).
  - Supported formats: ISO (GCM), RVZ, WIA, WBFS, CISO, NFS, GCZ, TGC
  - After the initial build, the disc image can be deleted to save space.

- Configure:

  ```sh
  python configure.py
  ```

  To use a version other than `RSBE01_02` (USA Rev 2), specify it with `--version`.

- Build:

  ```sh
  ninja
  ```

Diffing
=======

Once the initial build succeeds, an `objdiff.json` should exist in the project root.

Download the latest release from [encounter/objdiff](https://github.com/encounter/objdiff). Under project settings, set `Project directory`. The configuration should be loaded automatically.

Select an object from the left sidebar to begin diffing. Changes to the project will rebuild automatically: changes to source files, headers, `configure.py`, `splits.txt` or `symbols.txt`.

![](assets/objdiff.png)

Live reconstruction dashboard
=============================

From the repository root, run:

```sh
python tools/live_dashboard/server.py --port 8765
```

Open **http://127.0.0.1:8765/**. Only Python's standard library and a modern
browser are required; there is no frontend build or package installation.

- The byte-weighted map shows all modules. Select a module to inspect its
  source units; amber means accepted C/C++, while cyan means a byte match
  that has not met the source-acceptance rules.
- Agent cards and the event feed update approximately every two seconds from
  this project's OMP session journals. Search or filter agents, then select
  one for its recorded activity. A quiet agent has no recent recorded
  activity; it is not automatically considered stopped. A completed agent
  turn does not itself mean its source was accepted.
- Progress uses `tools/reconstruction_progress.py` and
  `build/RSBE01_02/report.json`, not the aggregate fuzzy-match percentage.
  New byte totals appear when reconstruction workers refresh that report.
  The report's age is shown separately from the live connection status.
- Pause buffers incoming updates until resumed. Motion can be disabled
  independently. The map supports arrow keys, Enter, and Escape.

The server discovers the newest session belonging to this checkout, including
nested agents. Use `--session-dir PATH` to select a session directory explicitly,
or `--report PATH` for another build report. Run `--help` for all options.
Missing inputs are reported in the UI; disconnected clients retain their last
snapshot with a stale indicator and reconnect automatically.

The dashboard is read-only with respect to reconstruction work: it does not
compile, launch agents, or modify source, configuration, or journals. Observed
progress history is stored in the ignored `build/live-dashboard/` directory.
It binds only to loopback, does not expose raw journals or reasoning, and
requires a local server; publishing the static files alone cannot provide
live agent data.
