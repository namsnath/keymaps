# Inspired by https://medium.com/@patrick.elmquist/separate-keymap-repo-for-qmk-136ff5a419bd
# https://github.com/patrick-elmquist/keymaps

# User to use for keymap name and QMK userspace
USER = namsnath
# Space separated list of supported keyboards
KEYBOARDS = preonic

# Paths to use for building QMK for the keyboards
## String to use as the keyboard name when building
BUILD_NAME_preonic = preonic/rev3
## Path under qmk_firmware/keyboards where the keymaps need to be symlinked
KEYMAP_PATH_preonic = preonic


# Build all keyboards
all: $(KEYBOARDS)

# Register a phony target for all the keyboards
.PHONY: $(KEYBOARDS)
$(KEYBOARDS):
	@echo [[Keymap Make]] Init submodules
	git submodule update --init --recursive

	@echo [[Keymap Make]] Cleaning up all old symlinks
	for f in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/$(KEYMAP_PATH_$@)/keymaps/$(USER); done
	# rm -rf qmk_firmware/users/$(USER)

	@echo [[Keymap Make]] Adding new symlinks
	# ln -s $(shell pwd)/user qmk_firmware/users/$(USER)
	ln -s $(shell pwd)/keyboards/$@ qmk_firmware/keyboards/$(KEYMAP_PATH_$@)/keymaps/$(USER)

	@echo [[Keymap Make]] Running lint check
	cd qmk_firmware; qmk lint -km $(USER) -kb $(BUILD_NAME_$@) --strict

	@echo [[Keymap Make]] Building $@
	make BUILD_DIR=$(shell pwd)/build -j1 -C qmk_firmware $(BUILD_NAME_$@):$(USER)

	@echo [[Keymap Make]] Cleaning symlinks
	for f in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/$(KEYMAP_PATH_$@)/keymaps/$(USER); done
	# rm -rf qmk_firmware/users/$(USER)

	@echo [[Keymap Make]] Fin.

clean:
	rm -rf build/

# In normal use, .SILENT recipe prevents echoing
# When V is not set, .SILENT is set, and only explicit echos are printed
# When V=1 is set, 1.SILENT is set, which has no special meaning
# https://make.mad-scientist.net/managing-recipe-echoing/
$(V).SILENT: