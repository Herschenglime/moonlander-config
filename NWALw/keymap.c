#include QMK_KEYBOARD_H
#include "version.h"
#include "features/swapper.h"
#include "features/led_positions.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,

  // from callum swapper
  SW_WIN_FWD,  // Switch to next window         (alt-tab)
  SW_WIN_BACK,  // Switch to prev window         (alt-sft-tab)
  SW_WSPC_FWD,  // Switch to next workspace         (mod-tab)
  SW_WSPC_BACK,  // Switch to prev workspace       (mod-sft-tab)
};


// define layer names separately from oryx for easier use in code
enum layer_names {
  MAIN,
  GAMING,
  NAV,
  SYM,
  NUM
};

const key_override_t prev_track_override = ko_make_basic(MOD_MASK_SHIFT, KC_AUDIO_VOL_DOWN, KC_MEDIA_PREV_TRACK);
const key_override_t next_track_override = ko_make_basic(MOD_MASK_SHIFT, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK);

// This globally defines all key overrides to be used
// different syntax than off the docs, originally wouldn't compile
// https://www.reddit.com/r/olkb/comments/1gfvz2a/comment/m084xre/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button
const key_override_t **key_overrides = (const key_override_t *[]){
	&prev_track_override,
  &next_track_override,
	NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_PSCR,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           TG(1),                                          TG(1),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_INSERT,      
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           CW_TOGG,                                        CW_TOGG,        KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_A,           KC_R,           KC_S,           KC_T,           KC_G,           MT(MOD_RALT, KC_CAPS),                                                                MT(MOD_RALT, KC_CAPS),KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                                           KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
    KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       OSL(2),         TG(1),                                                                                                          TG(1),          OSL(3),         KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       
    MT(MOD_LSFT, KC_SPACE),MT(MOD_LCTL, KC_ESCAPE),KC_TRANSPARENT,                 KC_TRANSPARENT, MT(MOD_LALT, KC_TAB),MT(MOD_LGUI, KC_ENTER)
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_TRANSPARENT,                                 KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           AS_TOGG,                                                                        KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_DQUO,        
    KC_TRANSPARENT, KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_D,                                           KC_V,           KC_B,           KC_N,           KC_M,           KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SPACE,       KC_ESCAPE,      KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TAB,         KC_ENTER
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         KC_F12,         
    KC_TRANSPARENT, OSM(MOD_LALT),  OSM(MOD_LGUI),  OSM(MOD_LSFT),  OSM(MOD_LCTL),  KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, 
    KC_TRANSPARENT, LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     KC_ESCAPE,      LCTL(KC_V),                                     KC_TRANSPARENT, KC_TAB,         LCTL(KC_MINUS), LCTL(KC_EQUAL), KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F8,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F12,         
    KC_TRANSPARENT, KC_SLASH,       KC_ASTR,        KC_MINUS,       KC_PLUS,        KC_BSLS,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, OSM(MOD_LCTL),  OSM(MOD_LSFT),  OSM(MOD_LGUI),  OSM(MOD_LALT),  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_GRAVE,       KC_ESCAPE,      KC_TILD,                                        KC_TRANSPARENT, KC_TAB,         KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         QK_BOOT,        
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_PSCR,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_DELETE,      KC_7,           KC_8,           KC_9,           KC_ENTER,       KC_F11,         
    KC_TRANSPARENT, KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_INSERT,      KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_BSPC,        KC_4,           KC_5,           KC_6,           KC_0,           KC_F12,         
    KC_TRANSPARENT, KC_F9,          KC_F10,         KC_F11,         KC_F12,         QK_BOOT,                                        KC_COMMA,       KC_1,           KC_2,           KC_3,           KC_DOT,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


const uint16_t PROGMEM combo0[] = { KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_F, KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_H, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo9[] = { KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM combo10[] = { KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo11[] = { KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo12[] = { KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo13[] = { KC_M, KC_N, COMBO_END};
const uint16_t PROGMEM combo14[] = { KC_N, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM combo15[] = { MT(MOD_LCTL, KC_ESCAPE), MT(MOD_LALT, KC_TAB), MT(MOD_LGUI, KC_ENTER), MT(MOD_LSFT, KC_SPACE), COMBO_END};
const uint16_t PROGMEM combo16[] = { MT(MOD_LSFT, KC_SPACE), MT(MOD_LGUI, KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo17[] = { KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM combo18[] = { KC_K, KC_H, COMBO_END};
const uint16_t PROGMEM combo19[] = { KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM combo20[] = { MT(MOD_LSFT, KC_SPACE), MT(MOD_LCTL, KC_ESCAPE), COMBO_END};
const uint16_t PROGMEM combo21[] = { MT(MOD_LALT, KC_TAB), MT(MOD_LGUI, KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo22[] = { KC_X, KC_C, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_BSPC),
    COMBO(combo1, KC_DELETE),
    COMBO(combo2, TG(1)),
    COMBO(combo3, KC_LPRN),
    COMBO(combo4, KC_LCBR),
    COMBO(combo5, KC_LBRC),
    COMBO(combo6, KC_RPRN),
    COMBO(combo7, KC_RCBR),
    COMBO(combo8, KC_RBRC),
    COMBO(combo9, KC_QUOTE),
    COMBO(combo10, KC_TAB),
    COMBO(combo11, KC_DQUO),
    COMBO(combo12, KC_MINUS),
    COMBO(combo13, KC_EQUAL),
    COMBO(combo14, LGUI(KC_ENTER)),
    COMBO(combo15, LGUI(LCTL(KC_ENTER))),
    COMBO_ACTION(combo16),
    COMBO(combo17, KC_UNDS),
    COMBO(combo18, KC_PLUS),
    COMBO(combo19, KC_LEFT_GUI),
    COMBO(combo20, LALT(KC_TAB)),
    COMBO(combo21, LGUI(KC_TAB)),
    COMBO(combo22, KC_ESCAPE),
};


extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {182,136,142}, {0,0,0}, {0,0,0}, {0,0,0}, {182,136,142}, {255,153,188}, {128,225,209}, {128,225,209}, {128,225,209}, {182,136,142}, {255,153,188}, {128,225,209}, {128,225,209}, {128,225,209}, {182,136,142}, {255,153,188}, {128,225,209}, {128,225,209}, {128,225,209}, {182,136,142}, {255,153,188}, {128,225,209}, {128,225,209}, {128,225,209}, {105,133,220}, {255,153,188}, {128,225,209}, {128,225,209}, {128,225,209}, {227,245,255}, {182,136,142}, {182,136,142}, {140,134,209}, {182,136,142}, {0,0,0}, {128,233,96}, {182,136,142}, {0,0,0}, {0,0,0}, {0,0,0}, {182,136,142}, {255,153,188}, {255,153,188}, {128,225,209}, {255,153,188}, {182,136,142}, {255,153,188}, {128,225,209}, {128,225,209}, {255,153,188}, {182,136,142}, {255,153,188}, {128,225,209}, {128,225,209}, {255,153,188}, {182,136,142}, {255,153,188}, {128,225,209}, {128,225,209}, {128,225,209}, {105,133,220}, {255,153,188}, {128,225,209}, {128,225,209}, {128,225,209}, {227,245,255}, {182,136,142}, {182,136,142}, {140,134,209}, {182,136,142}, {0,0,0}, {128,233,96} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {117,209,255}, {172,178,255}, {227,245,255}, {0,0,0}, {188,255,255}, {117,209,255}, {172,178,255}, {227,245,255}, {0,0,0}, {188,255,255}, {117,209,255}, {172,178,255}, {227,245,255}, {0,0,0}, {188,255,255}, {117,209,255}, {172,178,255}, {117,209,255}, {0,0,0}, {188,255,255}, {0,0,0}, {0,0,0}, {227,245,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {227,245,255}, {227,245,255}, {0,0,0}, {0,0,0}, {188,255,255}, {227,245,255}, {227,245,255}, {227,245,255}, {0,0,0}, {188,255,255}, {227,245,255}, {227,245,255}, {227,245,255}, {0,0,0}, {188,255,255}, {227,245,255}, {227,245,255}, {117,209,255}, {0,0,0}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {16,254,255}, {16,254,255}, {16,254,255}, {0,0,0}, {188,255,255}, {16,254,255}, {16,254,255}, {16,254,255}, {0,0,0}, {188,255,255}, {16,254,255}, {16,254,255}, {16,254,255}, {0,0,0}, {188,255,255}, {16,254,255}, {16,254,255}, {117,209,255}, {0,0,0}, {188,255,255}, {16,254,255}, {16,254,255}, {16,254,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {0,0,0}, {172,178,255}, {117,209,255}, {0,0,0}, {188,255,255}, {0,0,0}, {172,178,255}, {117,209,255}, {0,0,0}, {188,255,255}, {0,0,0}, {172,178,255}, {117,209,255}, {0,0,0}, {188,255,255}, {0,0,0}, {172,178,255}, {117,209,255}, {0,0,0}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {188,255,255}, {163,110,255}, {163,110,255}, {0,255,102}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,102}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {163,110,255}, {105,133,220}, {10,252,246}, {0,0,0}, {188,255,255}, {105,133,220}, {105,133,220}, {105,133,220}, {0,0,0}, {188,255,255}, {105,133,220}, {105,133,220}, {105,133,220}, {0,0,0}, {188,255,255}, {105,133,220}, {105,133,220}, {105,133,220}, {0,0,0}, {188,255,255}, {163,110,255}, {163,110,255}, {10,252,246}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );   
    }
  }
}

// light keys based on active oneshot mods
void light_mods(uint8_t mods, uint8_t r, uint8_t g, uint8_t b) {
    // get matrix positions with `qmk info -kb zsa/moonlander -m`
    // also in keyboard.json
    if (mods & MOD_BIT_LCTRL) {
      // should light left and right home key
      rgb_matrix_set_color(LED_2E, r, g, b);
      rgb_matrix_set_color(LED_8C, r, g, b);
    }
    if (mods & MOD_BIT_LSHIFT) {
      // should light left and right home key
      rgb_matrix_set_color(LED_2D, r, g, b);
      rgb_matrix_set_color(LED_8D, r, g, b);
    }
    if (mods & MOD_BIT_LGUI) {
      // should light left and right home key
      rgb_matrix_set_color(LED_2C, r, g, b);
      rgb_matrix_set_color(LED_8E, r, g, b);
    }
    if (mods & MOD_BIT_LALT) {
      // should light left and right home key
      rgb_matrix_set_color(LED_2B, r, g, b);
      rgb_matrix_set_color(LED_8F, r, g, b);
    }
}

void light_layers(uint8_t layer, uint8_t r, uint8_t g, uint8_t b) {
    // get matrix positions with `qmk info -kb zsa/moonlander -m`
    // also in keyboard.json
    // light the key of active osl blue
    if (layer == NAV) {
      rgb_matrix_set_color(LED_4E, r, g, b);
    }
    if (layer == SYM) {
      rgb_matrix_set_color(LED_AC, r, g, b);
    }
}

void light_locked_layers(uint8_t layer, uint8_t r, uint8_t g, uint8_t b) {
    // get matrix positions with `qmk info -kb zsa/moonlander -m`
    // also in keyboard.json
    // since no explicit "get_locked_state", manually query layer state
    if (get_oneshot_layer_state() == ONESHOT_TOGGLED) {
        if (layer == NAV) {
            rgb_matrix_set_color(LED_4E, r, g, b);
        }
        if (layer == SYM) {
            rgb_matrix_set_color(LED_AC, r, g, b);
        }
    }
}


bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }

  // blue is oneshots
  light_mods(get_oneshot_mods(), RGB_BLUE);

  // red is locked oneshots
  light_mods(get_oneshot_locked_mods(), RGB_RED);

  // blue is osl, red is locked osl
  light_layers(get_oneshot_layer(), RGB_BLUE);

  // typedef enum { ONESHOT_PRESSED = 0b01, ONESHOT_OTHER_KEY_PRESSED = 0b10, ONESHOT_START = 0b11, ONESHOT_TOGGLED = 0b100 } oneshot_fullfillment_t;
  light_locked_layers(get_oneshot_layer(), RGB_RED);

  return true;
}

// swapper state boolean
bool sw_win_active = false;
bool sw_wspc_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // handle alt tab and alt shift tab in swapper
  update_swapper(
      &sw_win_active, KC_LALT, KC_TAB, SW_WIN_FWD, SW_WIN_BACK, KC_LSFT,
      keycode, record
  );
  // mod tab for paperwm workspaces
  update_swapper(
      &sw_wspc_active, KC_LGUI, KC_TAB, SW_WSPC_FWD, SW_WSPC_BACK, KC_LSFT,
      keycode, record
  );

  switch (keycode) {

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}

//caps word combo
void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case 16:
      if (pressed) {
        caps_word_toggle();  // Activate Caps Word!
      }
      break;

    // Other combos...
  }
}

// disable combos that interfere with mods in layers to enable chording
//https://docs.qmk.fm/#/feature_combo?id=generic-hook-to-disallow-a-combo-activation
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {


  // since num is a combination of the below layers, catch this before disabling combos
  if (layer_state_is(NUM)) {
    return true;
  }

  // disable home row combos on left in sym layer
  if (layer_state_is(NAV)) {
    switch (combo_index) {
      case 0:
      case 3:
      case 19:
        return false;
    }
  }
  else if (layer_state_is(SYM)) {
    switch (combo_index) {
      case 6:
      case 9:
      case 14:
        return false;
    }
  }

  // otherwise let the combo pass
  return true;
}


// manually create tri-layer with oneshot keys
// https://docs.qmk.fm/ref_functions#update-tri-layer-state-state-x-y-z
// bug - doesn't work after each one-shot is pressed, will have to debug or manually config
layer_state_t layer_state_set_user(layer_state_t state) {
    // check for autoshift so it can be disabled on gaming layer
    if ((state & (1 << GAMING))) {
        autoshift_disable();
    } else {
        autoshift_enable();
    }
    return update_tri_layer_state(state, NAV, SYM, NUM);
}
// might interfere with other key thing, comment for now


// oneshot mod timer
static uint16_t osl_timer = 0;

// use oneshot mod callback such that if a mod is pressed, starts a 40 second timer, after which will kill the oneshot layer
void oneshot_mods_changed_user(uint8_t mods) {
    // if a mod is pressed, start the timer to clear the oneshot layer
    if (mods) {
        osl_timer = timer_read();
    }
}


static uint8_t OSL_MOD_TIMEOUT = 40;
// check timer state if in oneshot layer so it can be disabled if needed
// could affect performance, monitor afterwards
void housekeeping_task_user() {
    if (is_oneshot_layer_active() &&
        osl_timer != 0 &&
        // use the same amount of time as combo so it feels natural to hit modifiers at the same time
        timer_elapsed(osl_timer) > OSL_MOD_TIMEOUT) {
        // clear example: https://github.com/qmk/qmk_firmware/blob/58807b02887c116a22f860cd80d5b94ddd77122b/keyboards/handwired/ortho5x14/keymaps/2u/keymap.c#L561
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        osl_timer = 0;
    }
}

/* // TODO: fiddle with layer states so that the num layer properly stacks when trig'd as oneshot */

/* uint8_t last_osl = 0; */

/* // if you get notified to change into the next layer while a oneshot layer is already active, go to sym layer instead */
/* void oneshot_layer_changed_user(uint8_t layer) { */
/*     // layer debug doesn't work so just call function guts directly */
/*     printf("oneshot layer is %d\n", layer); */
/*     printf("last layer is %d\n", last_osl); */

/*   // if get 0, clear the last layer state as it probably wasn't on anymore */
/*   if (layer == 0) { */
/*       println("layer turned off"); */
/*       last_osl = 0; */
/*   } else { */
/*       last_osl = layer; */
/*       // account for sym and nav or sym and nav */
/*       if (last_osl != layer) { */
/*           // manually switch to num layer */
/*           set_oneshot_layer(NUM, ONESHOT_START); */
/*       } */
/*   } */

/* } */

/* // maybe keep track of last layer to see if it's cleared before the next goes up? */
