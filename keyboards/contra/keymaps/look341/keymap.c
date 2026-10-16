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
   * |   Q  |   W  |   F  |   P  |   B  | Esc  | Bksp |   J  |   L  |   U  |   Y  |   ;  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |   A  |   R  |   S  |   T  |   G  | Tab  | Enter|   M  |   N  |   E  |   I  |   O  |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |   Z  |   X  |   C  |   D  |   V  | (Num)| (Nav)|   K  |   H  |  , - |  . ! |  / _ |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |(Cole)|(Qwer)|  GUI | Space| Shift|  (ADJUST)   | Ctrl | Alt  | Bksp |  Del |(Symb)|
   * `-----------------------------------------------------------------------------------'
   */
  [_COLEMAK] = LAYOUT_planck_mit(
    KC_Q,         KC_W,        KC_F,    KC_P,         KC_B,         KC_ESCAPE,     KC_BSPC,   KC_J,          KC_L,     KC_U,             KC_Y,             KC_SCLN,
    KC_A,         KC_R,        KC_S,    KC_T,         KC_G,         KC_TAB,        KC_ENTER,  KC_M,          KC_N,     KC_E,             KC_I,             KC_O,
    KC_Z,         KC_X,        KC_C,    KC_D,         KC_V,         TO(_NUMBERS),  TO(_NAV),  KC_K,          KC_H,     TD(TD_COMM_MINS), TD(TD_DOT_EXLM),  TD(TD_SLSH_UND),
    TO(_COLEMAK), TO(_QWERTY), KC_LGUI, KC_SPC,       OSM(MOD_LSFT),    TO(_ADJUST),         OSM(MOD_LCTL),  KC_RALT,  KC_BSPC,          KC_DEL,           TO(_SYMBOLS)
  ),

  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * |   Q  |   W  |   E  |   R  |   T  | Esc  | Bksp |   Y  |   U  |   I  |   O  |   P  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |   A  |   S  |   D  |   F  |   G  | Tab  | Enter|   H  |   J  |   K  |   L  |   ;  |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |   Z  |   X  |   C  |   V  |   B  | (Num)| (Nav)|   N  |   M  |   , - |  . ! |  / _|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |(Cole)|(Qwer)|  GUI | Space| Shift|  (ADJUST)   | Ctrl | Alt  | Bksp |  Del |(Symb)|
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT_planck_mit(
    KC_Q,    KC_W,      KC_E,    KC_R,    KC_T, _______, _______, KC_Y,  KC_U,  KC_I,             KC_O,             KC_P,
    KC_A,    KC_S,      KC_D,    KC_F,    KC_G, _______, _______, KC_H,  KC_J,  KC_K,             KC_L,             KC_SCLN,
    KC_Z,    KC_X,      KC_C,    KC_V,    KC_B, _______, _______, KC_N,  KC_M,  TD(TD_COMM_MINS), TD(TD_DOT_EXLM),  TD(TD_SLSH_UND),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),


  /* Symbols
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   @  |   #  |   $  |   %  | Esc  | Bksp |   ^  |   &  |   *  |   =  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  |   `  |   ~  |  Alt |  DEL | Tab  | Enter|   \  |  {   |   }  |   |  | Enter|
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |  Cut | Copy | Undo |Paste | (Num)| (Nav)|   [  |  (   |   )  |   ]  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |(Cole)|(Qwer)|  GUI | Space| Shift|  (ADJUST)   | Ctrl | Alt  | Bksp |  Del |(Symb)|
   * `-----------------------------------------------------------------------------------'
   */
  [_SYMBOLS] = LAYOUT_planck_mit(
    KC_ESCAPE,  KC_AT,     LSFT(KC_3),      LSFT(KC_4),   KC_PERC,     _______, _______, KC_CIRC,           KC_AMPR,          KC_ASTR,        KC_EQL,          KC_BSPC,
    KC_TAB,     KC_GRAVE,   LSFT(KC_GRAVE),  KC_LALT,      KC_DEL,      _______, _______, TD(TD_BKSL_HME),   LSFT(KC_LBRC),    LSFT(KC_RBRC),  TD(TD_PIPE_END), KC_ENTER,
    KC_NO,      LCTL(KC_X), LCTL(KC_C),      LCTL(KC_Z),   LCTL(KC_V),  _______, _______, KC_LBRC,           KC_LPRN,          KC_RPRN,        KC_RBRC,         KC_NO,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Numbers and volume
   * ,-----------------------------------------------------------------------------------.
   * | Esc  | V D  | V U  |  *   |  +   | Esc  | Bksp |./F11 |  7/F | 8/F  | 9/F  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  | Mute |  ;   |  /   |  -   | Tab  | Enter|./F12 |  4/F | 3/F  | 6/F  | Enter|
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |  ,   |  =   |      | (Num)| (Nav)|  0   |  1/F | 2/F  | 3/F  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |(Cole)|(Qwer)|  GUI | Space| Shift|  (ADJUST)   | Ctrl | Alt  | Bksp |  Del |(Symb)|
   * `-----------------------------------------------------------------------------------'
   */
  [_NUMBERS] = LAYOUT_planck_mit(
    KC_ESCAPE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, LSFT(KC_8),   LSFT(KC_EQL), _______, _______, TD(TD_DOT_F11),  TD(TD_7_F7),  TD(TD_8_F8), TD(TD_9_F9),    KC_BSPC,
    KC_TAB,    KC_MUTE,           KC_SCLN,         KC_SLSH,      KC_MINS,      _______, _______, TD(TD_DOT_F12),  TD(TD_4_F4),  TD(TD_5_F5), TD(TD_6_F6),    KC_ENTER,
    KC_NO,     KC_NO,             KC_COMM,         KC_EQL,       KC_NO,        _______, _______, KC_0,            TD(TD_1_F1),  TD(TD_2_F2), TD(TD_3_F3),    KC_NO,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Navigation
   * ,-----------------------------------------------------------------------------------.
   * | Esc  | S L  │ M U  │ S R  │ CtQ  | Esc  | Bksp | Bck  │ Pre  │ Nex  │ Fwd  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  || M L  │ M D  │ M R │ DEL  | Tab  | Enter| LFT  │ DWN  │  UP  │ RHT  | Enter|
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      | RBn  │ S U  │ S D  │ Spc  | (Num)| (Nav)| LBn  │ PDn  │ PUp  │ Ac2  │ Ac3  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |(Cole)|(Qwer)|  GUI | Space| Shift|  (ADJUST)   | Ctrl | Alt  | Bksp |  Del |(Symb)|
   * `-----------------------------------------------------------------------------------'
   */
  [_NAV] = LAYOUT_planck_mit(
    KC_ESCAPE, MS_WHLL,    MS_UP,    MS_WHLR,  LCTL(KC_Q),  _______, _______, LALT(KC_LEFT), LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), LALT(KC_RIGHT),  KC_BSPC,
    KC_TAB,    MS_LEFT,    MS_DOWN,  MS_RGHT,  KC_DEL,      _______, _______, KC_LEFT,       KC_DOWN,            KC_UP,        KC_RIGHT,        KC_ENTER,
    KC_NO,     MS_BTN2,    MS_WHLU,  MS_WHLD,  KC_SPACE,    _______, _______, MS_BTN1,       KC_PAGE_DOWN,       KC_PAGE_UP,   MS_ACL1,         MS_ACL2,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | (Nav)| (Num)|(Symb)|Colemk|Qwerty|AGnorm|AGswap|Qwerty|Colemk|(Symb)| (Num)| (Nav)|
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT_planck_mit(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,
    TO(_NAV), TO(_NUMBERS), TO(_SYMBOLS), TO(_COLEMAK),   TO(_QWERTY),  KC_NO, KC_NO, TO(_QWERTY),  TO(_COLEMAK),  TO(_SYMBOLS),  TO(_NUMBERS),  TO(_NAV),
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _______, _______,  KC_NO, KC_NO, KC_NO,
    _______, _______, KC_NO, KC_NO, KC_NO,     KC_NO,      KC_NO, KC_NO,  KC_NO, KC_NO, _______
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
