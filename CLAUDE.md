# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

A ZSA Moonlander (rev A, the original board) keymap that merges a layout designed in the Oryx web configurator with hand-written QMK code. It is a fork of poulainpi's "Oryx with custom QMK" template (remote `upstream`). The upstream template builds in GitHub Actions (`.github/workflows/fetch-and-build-layout.yml`, still present but unused); this fork builds and flashes locally with `merge_configs.sh`.

The firmware built from this repo runs on the user's daily-driver keyboard. Don't run the build/flash script or edit the keymap unless asked to.

## Build / flash

```bash
./merge_configs.sh
```

There are no tests or linters. This one script handles the whole cycle and has side effects at every step:

1. Uses `rsync` to copy `~/dev/qmk_firmware/keyboards/zsa/moonlander/keymaps/NWALw/` **into** this repo's `NWALw/`. Code edits are normally made in the qmk_firmware copy, where clangd/LSP works.
2. Runs `git commit -a -m "some local changes"` and pushes it (this is where all the "some local changes" commits come from).
3. Checks out the `oryx` branch, downloads the latest Oryx source zip for layout `NWALw` from `oryx.zsa.io`, unzips it over `NWALw/`, then commits it as `✨(oryx): <Oryx change note>` and pushes.
4. Checks out `main`, runs `git merge -Xignore-all-space oryx`, and pushes.
5. Uses `rsync` to copy `NWALw/` back into qmk_firmware, then runs `qmk compile -kb zsa/moonlander/reva -km NWALw` and flashes `~/dev/qmk_firmware/zsa_moonlander_reva_NWALw.bin` with `wally-cli`.

To compile without touching git or flashing, run this from `~/dev/qmk_firmware`:

```bash
qmk compile -kb zsa/moonlander/reva -km NWALw
```

`~/dev/qmk_firmware` is ZSA's fork (`zsa/qmk_firmware`), checked out on a `firmwareNN` branch that matches the Oryx `qmkVersion` (currently `firmware25`). The `qmk_firmware` submodule in `.gitmodules` exists only for the CI workflow. Locally, the external checkout is what gets used.

## Branch model

- `oryx`: contains only the raw Oryx export. Never edit it by hand. Each Oryx "Compile" plus a script run adds one commit here.
- `main`: Oryx output with custom QMK code merged on top. Merge conflicts in `NWALw/keymap.c`, `config.h`, and `rules.mk` happen when Oryx regenerates a region that was also hand-edited.

Oryx owns and regenerates the `keymaps[]` array, the `combo*`/`key_combos[]` definitions, `ledmap[]`, `COMBO_COUNT`, `SERIAL_NUMBER`, the RGB `#undef` block, and the Oryx-generated `rules.mk` flags. Change those in Oryx rather than in code, or they will conflict or be overwritten. Everything else in `keymap.c` is custom, including the layer enum, key overrides, `combo_should_trigger`, `layer_state_set_user`, the oneshot timers, the RGB indicators, and the swapper.

## Keymap architecture (`NWALw/`)

- Layers: `MAIN`, `GAMING` (toggle), `NAV` (`OSL(2)`, left thumb cluster), `SYM` (`OSL(3)`, right thumb cluster), `NUM`. `NUM` is a tri-layer: `layer_state_set_user` calls `update_tri_layer_state(NAV, SYM, NUM)`, and it also turns Auto Shift off on `GAMING`.
- `NAV` and `SYM` put one-shot home-row mods (`OSM`) under the home-row keys. `housekeeping_task_user` and `oneshot_mods_changed_user` clear the one-shot layer 40 ms after a one-shot mod fires, so the mod and the next key can be chorded.
- Combos: `COMBO_ONLY_FROM_LAYER 0` means combo keys always resolve against the MAIN layer, whatever layer is active. `combo_should_trigger` (enabled by `COMBO_SHOULD_TRIGGER`) turns off home-row combos by **index** while in `NAV`/`SYM`, so the one-shot mods underneath can be chorded. The indices refer to positions in the Oryx-generated `key_combos[]`, so re-check them whenever combos change in Oryx. `process_combo_event` has the same dependency (combo 16 is Caps Word).
- `features/swapper.c`: Callum-style alt-tab/super-tab swapper, called from `process_record_user`.
- `features/led_positions.h`: maps matrix positions to LED indexes, used for the one-shot mod/layer indicator lighting in `rgb_matrix_indicators_user`.

## QMK processing-order gotcha

For each key event, `pre_process_record_user` runs first, then combo processing (`process_combo`), then the tap-hold state machine (`action_tapping_process`), then `process_record_user`. `OSL()` counts as a tap action, so its layer is only turned on once QMK decides tap vs. hold (on release, at `TAPPING_TERM`, or through permissive hold). Combos and `combo_should_trigger` that run before that decision see the layer as inactive. See `quantum/quantum.c` (`pre_process_record_quantum`) and `quantum/action.c` (`is_tap_action`) in qmk_firmware. This is why `pre_process_record_user` tracks the physical OSL holds (`nav_held`/`sym_held`) for `combo_should_trigger`.

QMK tracks only **one** one-shot layer at a time (`oneshot_layer_data` in `quantum/action_util.c`). A second `OSL` overwrites it, and every OSL release clears whichever layer is in the slot. Holding both thumbs for NUM used to leave the first layer stuck on. The `num_chorded` handling in `process_record_user` fixes that by treating a NUM chord as momentary. Separately, `update_tri_layer_state` in `layer_state_set_user` turns NUM off unless NAV and SYM are both on, so a one-shot NUM won't stick without an exception there.
