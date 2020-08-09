#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"
#include "action_layer.h"
#include "mousekey.h"

extern keymap_config_t keymap_config;

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MOUSE,
  _NUMBERS
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE
};

// TODO: Add tap/tap dance actions to mods, ex.: LOWER MT(MO(_LOWER), KC_SPC)
#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define MOUSE  MO(_MOUSE)
#define NUMBERS MO(_NUMBERS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------------------------------------------------------.
 * |Tab     |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp      |
 * |--------+------+------+------+------+-------------+------+------+------+------+-----------|
 * |Esc/Ctrl|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "        |
 * |--------+------+------+------+------+------|------+------+------+------+------+-----------|
 * |Shift   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter/Shift|
 * |--------+------+------+------+------+------+------+------+------+------+------+-----------|
 * |Mouse   | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right      |
 * `------------------------------------------------------------------------------------------'
 * added: ASDF on hold shift/ctrl/alt/cmd, same way on jkl; (;lkj mirrored)
 */
[_QWERTY] = {
  {KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
      KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC},
  {LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G,
      KC_H, KC_J, KC_K, KC_L, KC_SCLN, RCTL_T(KC_QUOT)},
  /*{LCTL_T(KC_ESC), LSFT_T(KC_A), LCTL_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F), KC_G,*/
      /*KC_H, RGUI_T(KC_J), RALT_T(KC_K), RCTL_T(KC_L), RSFT_T(KC_SCLN), RCTL_T(KC_QUOT)},*/
  {KC_LSFT, LT(NUMBERS, KC_Z), KC_X, KC_C, KC_V, KC_B,
      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_ENT)},
  {MOUSE, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC,
      KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF,_______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Mouse layer
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |  h   |  j   |  k   |  l   |      |      | scroll
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |  h   |  j   |  k   |  l   |      |      | cursor
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  b1  |  b2  |  b3  |  b4  |  b5  |      |  s2  |  s1  |  s0  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | layer|      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = {
  {_______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_WH_U, _______},
  {_______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MS_U, _______},
  {_______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, _______, KC_ACL2, KC_ACL1, KC_ACL0, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Numbers layer
 * Hold Z and have a numpad where 4 is at your right index.
 */
[_NUMBERS] = {
  {_______, _______, _______, _______, _______, _______, _______,    KC_P7,  KC_P8,  KC_P9, KC_KP_SLASH, _______},
  {_______, _______, _______, _______, _______, _______, _______,    KC_P4,  KC_P5,  KC_P6, KC_KP_ASTERISK, _______},
  {_______, _______, _______, _______, _______, _______, _______,    KC_P1,  KC_P2,  KC_P3, KC_KP_MINUS, _______},
  {_______, _______, _______, _______, _______, _______, _______,    KC_P0,KC_COMM, KC_DOT, KC_KP_PLUS, _______}
}

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}

#endif
