#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _QWERTY = 0,
  _FN,
  _MOV,
  _NUM,
};

enum custom_keycodes {
  RGB_RST = SAFE_RANGE,
  W_COPY,
  W_CUT,
};

// タップダンスの宣言
enum tap_dance_keycodes {
  VIM_DD,
  VIM_YY
};

enum {
  VIM_DD_ACTION = 0,
  VIM_YY_ACTION,
};

void dance_vim_dd_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    register_code (KC_HOME);
    unregister_code (KC_HOME);
    register_code (KC_LSFT);
    register_code (KC_END);
    unregister_code (KC_END);
    unregister_code (KC_LSFT);
    SEND_STRING (SS_LCTRL("x"));
  }
}

void dance_vim_dd_reset (qk_tap_dance_state_t *state, void *user_data) {
  return;
}

void dance_vim_yy_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    register_code (KC_LGUI);
    register_code (KC_LEFT);
    unregister_code (KC_LEFT);
    register_code (KC_LEFT);
    unregister_code (KC_LEFT);
    register_code (KC_LSFT);
    register_code (KC_RIGHT);
    clear_keyboard();
    SEND_STRING (SS_LGUI("c"));
  }
}

void dance_vim_yy_reset (qk_tap_dance_state_t *state, void *user_data) {
  return;
}

// タップダンスの定義
qk_tap_dance_action_t tap_dance_actions[] = {
    // 1回タップすると Escape キー、2回タップすると Caps Lock。
    //[TD_Y_X]  = ACTION_TAP_DANCE_DOUBLE(KC_Y, HELLO)
    [VIM_DD_ACTION] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_vim_dd_finished, dance_vim_dd_reset),
    [VIM_YY_ACTION] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_vim_yy_finished, dance_vim_yy_reset),
};

#define TD_DD TD(VIM_DD_ACTION)
#define TD_YY TD(VIM_YY_ACTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      KC_LGUI,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, MO(_FN),
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
              KC_LCTRL,MO(_MOV), KC_LALT,  KC_SPC,               KC_ENT,MO(_NUM),          KC_RALT,KC_RCTRL
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_FN] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
     TG(_NUM),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,   KC_UP, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
  _______,KC__VOLDOWN,KC__VOLUP,KC__MUTE, KC_BTN1, KC_BTN2,     _______, _______, KC_HOME, KC_PGUP, KC_LEFT,KC_RIGHT, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______,  KC_END, KC_PGDN, KC_DOWN, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______,              _______, _______,          _______, _______
          //`---------------------------------------------|   |--------------------------------------------'
  ),
  
  [_MOV] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
     TG(_NUM),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
  _______,KC__VOLDOWN,KC__VOLUP,KC__MUTE, KC_BTN1, KC_BTN2,     KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______,   W_CUT,  W_COPY, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______,              _______, _______,          _______, _______
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_NUM] = LAYOUT( /* Base */
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
     TG(_NUM), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   RESET,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        KC_0,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX
          //`---------------------------------------------|   |--------------------------------------------'
  )
};


//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
    case _FN:
      rgblight_sethsv_at(HSV_BLUE, 0);
      break;
    case _NUM:
      rgblight_sethsv_at(HSV_PURPLE, 0);
      break;
    default: //  for any other layers, or the default layer
      rgblight_sethsv_at( 0, 0, 0, 0);
      break;
    }
    rgblight_set_effect_range( 1, 4);
#endif
return state;
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool result = false;
  switch (keycode) {
    #ifdef RGBLIGHT_ENABLE
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGB_RST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
      case W_COPY:
          if (record->event.pressed) {
            SEND_STRING("yiw");
          }
        break;
      case W_CUT:
          if (record->event.pressed) {
            SEND_STRING("ciw");
          }
        break;
    default:
      result = true;
      break;
  }

  return result;
}
