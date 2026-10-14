/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "tapHold.h"

enum tap_dance_codes {
  TD_Z_UNDO,
  TD_X_CUT,
  TD_C_COPY,
  TD_V_PASTE,
  TD_B_PASTE,
  TD_DOT_EXLM,
  TD_SLSH_UND,
  TD_COMM_MINS,
  TD_QUOTE_GRAVE,
  TD_SCLN_QUOTE,
  TD_BKSL_HME,
  TD_PIPE_END,
  TD_1_F1,
  TD_2_F2,
  TD_3_F3,
  TD_4_F4,
  TD_5_F5,
  TD_6_F6,
  TD_7_F7,
  TD_8_F8,
  TD_9_F9,
  TD_DOT_F11,
  TD_DOT_F12
};

tap_dance_action_t tap_dance_actions[] = {
  [TD_Z_UNDO] = ACTION_TAP_HOLD(KC_Z, LCTL(KC_Z)),
  [TD_X_CUT] = ACTION_TAP_HOLD(KC_X, LCTL(KC_X)),
  [TD_C_COPY] = ACTION_TAP_HOLD(KC_C, LCTL(KC_C)),
  [TD_V_PASTE] = ACTION_TAP_HOLD(KC_V, LCTL(KC_V)),
  [TD_B_PASTE] = ACTION_TAP_HOLD(KC_B, LCTL(KC_V)),
  [TD_DOT_EXLM] = ACTION_TAP_HOLD(KC_DOT, KC_EXLM),
  [TD_COMM_MINS] = ACTION_TAP_HOLD(KC_COMM, KC_MINS),
  [TD_SLSH_UND] = ACTION_TAP_HOLD(KC_SLSH,  S(KC_MINS)),
  [TD_QUOTE_GRAVE] = ACTION_TAP_HOLD(KC_QUOTE,  S(KC_GRAVE)),
  [TD_SCLN_QUOTE] = ACTION_TAP_HOLD(KC_SCLN, KC_QUOTE),
  [TD_BKSL_HME] = ACTION_TAP_HOLD(KC_BSLS,  KC_HOME),
  [TD_PIPE_END] = ACTION_TAP_HOLD(KC_PIPE,  KC_END),
  [TD_1_F1] = ACTION_TAP_HOLD(KC_1,  KC_F1),
  [TD_2_F2] = ACTION_TAP_HOLD(KC_2,  KC_F2),
  [TD_3_F3] = ACTION_TAP_HOLD(KC_3,  KC_F3),
  [TD_4_F4] = ACTION_TAP_HOLD(KC_4,  KC_F4),
  [TD_5_F5] = ACTION_TAP_HOLD(KC_5,  KC_F5),
  [TD_6_F6] = ACTION_TAP_HOLD(KC_6,  KC_F6),
  [TD_7_F7] = ACTION_TAP_HOLD(KC_7,  KC_F7),
  [TD_8_F8] = ACTION_TAP_HOLD(KC_8,  KC_F8),
  [TD_9_F9] = ACTION_TAP_HOLD(KC_9,  KC_F9),
  [TD_DOT_F11] = ACTION_TAP_HOLD(KC_DOT,  KC_F11),
  [TD_DOT_F12] = ACTION_TAP_HOLD(KC_DOT,  KC_F12),
};


enum planck_layers {
  _COLEMAK,
  _QWERTY,
  _SYMBOLS,
  _NUMBERS,
  _NAV,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Colemak dh
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |Enter |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |  , - |  . ! |  / _ |Ctrl  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      | GUI  |(Symb)|    Space    |(Symb)| Alt  | Left |      |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_COLEMAK] = LAYOUT_planck_mit(
    KC_ESC,        KC_Q,          KC_W,         KC_F,    KC_P,         KC_B,    KC_J,      KC_L,           KC_U,          KC_Y,    KC_SCLN, KC_BSPC,
    KC_TAB,        KC_A,          KC_R,         KC_S,    KC_T,         KC_G,    KC_M,      KC_N,           KC_E,          KC_I,    KC_O,    KC_ENT,
    OSM(MOD_LSFT), KC_Z,          KC_X,         KC_C,    KC_D,         KC_V,    KC_K,      KC_H,           KC_COMM,       KC_DOT,  KC_SLSH, OSM(MOD_LCTL),
    KC_NO,         KC_NO,         KC_NO,        KC_LGUI, MO(_SYMBOLS),       KC_SPC,       TO(_SYMBOLS),   OSM(MOD_LALT), KC_LEFT, KC_NO,   KC_RIGHT
  ),

  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Ctrl  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      | GUI  |(Symb)|    Space    |(Symb)| Alt  | Left |      |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT_planck_mit(
    KC_ESC,        KC_Q,    KC_W,         KC_E,    KC_R,         KC_T,    KC_Y,      KC_U,         KC_I,          KC_O,    KC_P,    KC_BSPC,
    KC_TAB,        KC_A,    KC_S,         KC_D,    KC_F,         KC_G,    KC_H,      KC_J,         KC_K,          KC_L,    KC_SCLN, KC_ENT,
    OSM(MOD_LSFT), KC_Z,    KC_X,         KC_C,    KC_V,         KC_B,    KC_N,      KC_M,         KC_COMM,       KC_DOT,  KC_SLSH, OSM(MOD_LCTL),
    KC_NO,         KC_NO,   KC_NO,        KC_LGUI, MO(_SYMBOLS),       KC_SPC,       TO(_SYMBOLS), OSM(MOD_LALT), KC_LEFT, KC_NO,   KC_RIGHT
  ),


  /* Symbols
   * ,-----------------------------------------------------------------------------------.
   * |      |      |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   =  |      |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |   `  |   ~  |  Alt |  DEL |   \  |  {   |   }  |   |  |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |(Kor) |  Cut | Copy | Undo |Paste |   [  |  (   |   )  |   ]  |TO(4) |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |(alph)|             |(Sym) | Alt* |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_SYMBOLS] = LAYOUT_planck_mit(
    _______, KC_NO,       KC_AT,      LSFT(KC_3),      LSFT(KC_4),     KC_PERC,     KC_CIRC,           KC_AMPR,          KC_ASTR,        KC_EQL,          KC_NO,    _______,
    _______, KC_NO,       KC_GRAVE,   LSFT(KC_GRAVE),  KC_LALT,        KC_DEL,      TD(TD_BKSL_HME),   LSFT(KC_LBRC),    LSFT(KC_RBRC),  TD(TD_PIPE_END), KC_NO,    _______,
    _______, TO(_QWERTY), LCTL(KC_X), LCTL(KC_C),      LCTL(KC_Z),     LCTL(KC_V),  KC_LBRC,           KC_LPRN,          KC_RPRN,        KC_RBRC,         TO(4),    _______,
    _______, _______,     _______,    _______,         TO(_COLEMAK),          _______,                 TO(_NUMBERS),     KC_RALT,        _______,         _______,  _______
  ),

  /* Numbers and volume
   * ,-----------------------------------------------------------------------------------.
   * |      |      | V D  | V U  |  *   |  +   |./F11 |  7/F | 8/F  | 9/F  |      |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      | Mute |  ;   |  /   |  -   |./F12 |  4/F | 3/F  | 6/F  |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |(Kor) |      |  ,   |  =   |      |  0   |  1/F | 2/F  | 3/F  |TO(4) |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |(alph)|             |(Sym) |  0   |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_NUMBERS] = LAYOUT_planck_mit(
    _______,    KC_NO,       KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, LSFT(KC_8),   LSFT(KC_EQL), TD(TD_DOT_F11),  TD(TD_7_F7),  TD(TD_8_F8), TD(TD_9_F9),    KC_NO,   _______,
    _______,    KC_NO,       KC_MUTE,           KC_SCLN,         KC_SLSH,      KC_MINS,      TD(TD_DOT_F12),  TD(TD_4_F4),  TD(TD_5_F5), TD(TD_6_F6),    KC_NO,   _______,
    _______,    TO(_QWERTY), KC_NO,             KC_COMM,         KC_EQL,       KC_NO,        KC_0,            TD(TD_1_F1),  TD(TD_2_F2), TD(TD_3_F3),    TO(4),   _______,
    _______,    _______,     _______,           _______,         TO(_COLEMAK),        _______,                TO(_SYMBOLS), KC_0,        _______,        _______, _______
  ),

  /* Navigation
   * ,-----------------------------------------------------------------------------------.
   * |      |      | S L  │ M U  │ S R  │ CtQ  | Bck  │ Pre  │ Nex  │ Fwd  |      |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      | M L  │ M D  │ M R  │ DEL  | LFT  │ DWN  │  UP  │ RHT  |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |(Kor) | RBn  │ S U  │ S D  │ Spc  | LBn  │ PDn  │ PUp  │ Ac2  │ Ac3  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |(alph)|             |(Sym) |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_NAV] = LAYOUT_planck_mit(
    _______,    KC_NO,       KC_MS_WH_LEFT, KC_MS_UP,    KC_MS_WH_RIGHT, LCTL(KC_Q),  LALT(KC_LEFT), LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), LALT(KC_RIGHT),  KC_NO,        _______,
    _______,    KC_NO,       KC_MS_LEFT,    KC_MS_DOWN,  KC_MS_RIGHT,    KC_DEL,      KC_LEFT,       KC_DOWN,            KC_UP,        KC_RIGHT,        KC_NO,        _______,
    _______,    TO(_QWERTY), KC_MS_BTN2,    KC_MS_WH_UP, KC_MS_WH_DOWN,  KC_SPACE,    KC_MS_BTN1,    KC_PAGE_DOWN,       KC_PAGE_UP,   KC_MS_ACCEL1,    KC_MS_ACCEL2, _______,
    _______,    _______,     _______,       _______,     TO(_COLEMAK),        _______,               TO(_SYMBOLS),       _______,      _______,         _______,      _______
  ),

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
  [_ADJUST] = LAYOUT_planck_mit(
    _______, QK_BOOT, DB_TOGG, _______, _______, _______, _______, _______, _______,  _______, _______, KC_DEL ,
    _______, _______, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK,  DVORAK,  PLOVER,  _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______,  _______, _______, _______
  )

};


/*
#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user1(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}
*/
