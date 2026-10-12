# Moonlander Layout
See the base keymap at https://configure.zsa.io/moonlander/layouts/NWALw/latest/0.

Core features:
- Colemak-dh layout
- Home-row mods
- Limited layering
- Lots of combos

Most of the added features in the QMK code involve extra tri-state layer handling, some fancier combos and exclusions, and layer indicators on the keys themselves.

This repository is based on the exceptional work of the upstream project, [poulainpi/oryx-with-custom-qmk](https://github.com/poulainpi/oryx-with-custom-qmk), but tweaked to compile on a local install of QMK so I don't have to wait for GitHub actions to run every time I make a change - see [merge_configs.sh](./merge_configs.sh) for a (very brittle) local reimplementation of the GitHub actions script. 

See also: https://github.com/Herschenglime/zmk-config-local

This is a parallel implementation of the layout on my wireless Ferris Sweep in ZMK - most of the core ideas from this layout are present there, and its layering conventions are replicated here to make it easier to switch between them.

The standard readme from the project is below.

# Oryx with custom QMK

This repository allows combining the convenience of [Oryx’s](https://www.zsa.io/oryx) graphical layout editing with the power of [QMK](https://qmk.fm), allowing you to customize your Oryx layout with advanced QMK features like Achordion and Repeat Key, while automating firmware builds through GitHub Actions.

For a detailed guide, check out the full [blog post here](https://blog.zsa.io/oryx-custom-qmk-features).

## How it works

Each time you run the GitHub Action, the workflow will:
1. Fetch the latest changes made in Oryx.
2. Merge them with any QMK features you've added in the source code.
3. Build the firmware, incorporating modifications from both Oryx and your custom source code.

## How to use

1. Fork this repository (be sure to **uncheck the "Copy the main branch only" option**).
2. To initialize the repository with your layout:
   - Go to the **Actions** tab.
   - Select **Fetch and build layout**.
   - Click **Run workflow**.
   - Input your layout ID and keyboard type (your layout must be public in Oryx), then run the workflow.
   - (To avoid having to input values each time, you can modify the default values at the top of the `.github/workflows/fetch-and-build-layout.yml` file).
3. A folder containing your layout will be generated at the root of the repository.
4. You can now add your custom QMK features to this folder:
   - Edit `config.h`, `keymap.c` and `rules.mk` according to the [QMK documentation](https://github.com/qmk/qmk_firmware/tree/master/docs/features).
   - Commit and push to the **main** branch.
5. You can continue editing your layout through Oryx:
   - Make your changes in Oryx. 
   - Optionally, add a description of your changes in the **Some notes about what you changed** field; if provided, this will be used as commit message.
   - Confirm changes by clicking the **Compile this layout** button.
6. To build the firmware (including both Oryx and code modifications), rerun the GitHub Action. The firmware will be available for download in the action’s artifacts.
7. Flash your downloaded firmware using [Keymapp](https://www.zsa.io/flash#flash-keymap).
8. Enjoy!

## Oryx Chrome extension

To make building even easier, [@nivekmai](https://github.com/nivekmai) created an [Oryx Chrome extension](https://chromewebstore.google.com/detail/oryx-extension/bocjciklgnhkejkdfilcikhjfbmbcjal) to be able to trigger the GitHub Actions from inside Oryx itself.
