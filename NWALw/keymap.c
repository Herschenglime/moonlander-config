#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
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
const uint16_t PROGMEM combo23[] = { KC_L, KC_U, KC_Y, COMBO_END};

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
    COMBO(combo16, KC_CAPS),
    COMBO(combo17, KC_UNDS),
    COMBO(combo18, KC_PLUS),
    COMBO(combo19, KC_LEFT_GUI),
    COMBO(combo20, LALT(KC_TAB)),
    COMBO(combo21, LGUI(KC_TAB)),
    COMBO(combo22, KC_ESCAPE),
    COMBO(combo23, KC_BSLS),
};



extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

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
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
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
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}





bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;

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

