#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* LayoutQwerty
 * ,-----------------------------------------.  ,-----------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  | Esc  |  | Alt  |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  | Tab  |  | Enter|   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  | Ctrl |  | Ctrl |   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |Shift | Lower| GUI  | Bksp |      |Raise |  |Raise |      |   [  |   ]  | Lower| Shift|
 * `-----------------------------------------'  `-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_ESC,  KC_LALT, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     \
   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,  KC_ENT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  \
   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCTL, KC_RCTL , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  \
   KC_LSFT, LOWER,   KC_LGUI, KC_BSPC, KC_SPC,   RAISE,  RAISE,  KC_SPC,   KC_LBRC, KC_RBRC,    LOWER, KC_RSHIFT  \
),

// MISSING: ADJUST

/* LayoutRaise
 * ,-----------------------------------------.  ,-----------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |      |  |      |   !  |   @  |   #  |   $  |   %  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |   6  |   7  |   8  |   9  |   0  |      |  |      | Left | Down | Up   | Right|   '  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |   `  |   ~  |   _  |   =  |   +  |      |  |      |   ^  |   &  |   *  |  "   |   \  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |Shift | Lower|      | Del  |   -  | Raise|  | Raise|   |  |   (  |   )  | Lower| Shift|
 * `-----------------------------------------'  `-----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,    KC_DEL,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   \
  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, \
  KC_GRV,  LSFT(KC_GRV), KC_UNDS, KC_EQL,  KC_PLUS, _______,   _______, KC_CIRC, KC_AMPR, KC_ASTR, LSFT(KC_QUOT), KC_BSLS, \
  KC_LSHIFT, LOWER,   _______, KC_DEL, KC_MINS, RAISE,     RAISE, KC_PIPE, KC_LPRN, KC_RPRN, LOWER,   KC_RSHIFT \
),

/* LayoutLower
 * ,-----------------------------------------.  ,-----------------------------------------.
 * | F1   | F2   | F3   | F4   | F5   |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | F6   | F7   | F8   | F9   | F10  |      |  | Play |      | Vol- | Vol+ |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | F11  | F12  |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      | Next |      |      |      |
 * `-----------------------------------------'  `-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,    _______,     _______,  _______, _______, _______,  _______,  _______,  \
  KC_F6,   KC_F7,   KC_F8,   KC_F9, KC_F10,  _______,         KC_MPLY,  _______, KC_VOLD, KC_VOLU, _______, _______, \
  KC_F11, KC_F12, _______, _______,  _______,  _______,     _______,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______,  _______,  _______,     _______,  _______, KC_MNXT, _______, _______, _______ \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|      |      |      |      |      | Del  |      |      |      |      |Reset |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  RESET,   _______,   _______, _______, _______, _______, KC_DEL, _______, _______, _______, _______, RESET, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
  }
  return true;
}
