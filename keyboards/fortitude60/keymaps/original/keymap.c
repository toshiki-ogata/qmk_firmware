#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

enum user_macro {
  UM_EMHL,
  UM_KHKR
};
#define M_EMHL MACROTAP(UM_EMHL)
#define M_KHKR MACROTAP(UM_KHKR)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  GUI |  Alt |Space |Lower |  Esc |Enter |Raise | Bksp |  Alt |  GUI |
 *               `---------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,  KC_1, KC_2,    KC_3,    KC_4,          KC_5,                                   KC_6,                KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,  KC_Q, KC_W,    KC_E,    KC_R,          KC_T,                                   KC_Y,                KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,  \
  KC_LCTL, KC_A, KC_S,    KC_D,    KC_F,          KC_G,                                   KC_H,                KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z, KC_X,    KC_C,    KC_V,          KC_B,                 KC_LBRC, KC_RBRC, KC_N,                KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,\
                 KC_LGUI, KC_LALT, ALT_T(KC_SPC), M_EMHL,  KC_ESC,  KC_ENT,  M_KHKR, KC_BSPC, KC_RALT, KC_RGUI\
),

/* Lower
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      |C+S+T |   ↑  |C + T |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      |  ←   |   ↓  |  →   |      |             |      |      | Home | PgUp |      |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |      |G + ← |G + ↑ |G + → |      |      |      |      | Del  | End  |PgDwn |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  _______, _______, _______,      _______,  _______,    _______,                    _______, _______, _______, _______,   _______, _______,  \
  _______, _______, S(C(KC_TAB)), KC_UP,    C(KC_TAB),  _______,                    _______, _______, _______, _______,   _______, _______, \
  _______, _______, KC_LEFT,      KC_DOWN,  KC_RGHT,    _______,                    _______, _______, KC_HOME, KC_PGUP,   _______, _______, \
  _______, _______, G(KC_LEFT),   G(KC_UP), G(KC_RGHT), _______, _______, _______,  _______, KC_DEL , KC_END,  KC_PGDOWN, _______, _______, \
                    _______,      _______,  _______,    _______, _______, _______,  _______, _______, _______, _______\
),

/* Raise
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |  -   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |   +  |   =  |   {  |   }  |   :  |  "   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   |  |   '  |   [  |   ]  |   ?  |  \   |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PMNS, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,  \
  _______, _______, _______, _______, _______, _______,                   KC_PPLS, KC_EQL,  KC_LCBR, KC_RCBR, KC_SCLN, KC_QUOT, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, KC_QUOT, KC_LBRC, KC_RBRC, KC_SLSH, KC_BSLS,\
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |Brt Up|Brt Dn|      |      |      |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |Val Dn|Val Up| Mute |      |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, _______, _______, _______, _______, _______,                   _______, KC_BRIU, KC_BRID, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, \
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
        case UM_EMHL:
            return MACRO_TAP_HOLD_LAYER( record, MACRO(T(MHEN), T(LANG2), END), _LOWER );
            break;

        case UM_KHKR:
            return MACRO_TAP_HOLD_LAYER( record, MACRO(T(HENK), T(LANG1), END), _RAISE );
            break;
    }
    return MACRO_NONE;
}
