# Keymaps
Keymaps for my QMK keyboard(s).

## Building
- `make <keyboard>`
  - Supported keyboards: `preonic`

## Flashing
- Use the output `.bin` files in the `build/` directory.

## Updating Submodules
- `git submodule update --remote`
  - Updates `qmk_firmware` to the latest commit.
  - DO NOT use `--recursive` here. It will pull everything to the latest, which is not what we want.
- `git commit` the updated submodule.
- `make` or simply `git submodule update --init --recursive`
  - Once committed, `update` will pick up the new HEAD and setup the submodules accordingly.