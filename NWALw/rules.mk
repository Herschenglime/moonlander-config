# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = yes
COMMAND_ENABLE = no
AUTO_SHIFT_ENABLE = yes
MOUSEKEY_ENABLE = no
ORYX_ENABLE = yes
RGB_MATRIX_CUSTOM_KB = yes
SPACE_CADET_ENABLE = no
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes

# add callum swapper feature
SRC += features/swapper.c

AUDIO_ENABLE = yes

# tri layer support since the oryx version is kinda mid
TRI_LAYER_ENABLE = yes

KEY_OVERRIDE_ENABLE = yes
