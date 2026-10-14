// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

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

//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /* 0 COLEMAK-DH
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ F │ P │ B │       │ J │ L │ U │ Y │; '│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ R │ S │ T │ G │       │ M │ N │ E │ I │ O │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Z*A│X  │C  │ D │V  │       │ K │ H │, -│. !│/ _│
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Win├───┐           ┌───┤Bks│
      *               └───┤Sp2├───┐   ┌───┤(2)├───┘
      *                   └───┤Sft│   │Ctl├───┘
      *                       └───┘   └───┘
      */
    [0] = LAYOUT_split_3x6_3(
        KC_NO,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,  /**/    KC_J,    KC_L,    KC_U,    KC_Y,    TD(TD_SCLN_QUOTE),    KC_NO,
        KC_NO,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,  /**/    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,       KC_NO,
        KC_NO,  MT(MOD_LALT, KC_Z) ,    KC_X,    KC_C,    KC_D,    KC_V,  /**/    KC_K,    KC_H,    TD(TD_COMM_MINS), TD(TD_DOT_EXLM),  TD(TD_SLSH_UND), KC_NO,
                                        KC_LGUI, LT(2, KC_SPACE), OSM(MOD_LSFT),       OSM(MOD_LCTL) , TO(2), KC_BSPC
     ),
     /* 1 QWERTY (For Korean Typing)
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Z*A│ X │ C │ V │ B │       │ N │ M │, ?│. !│/ -│
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Win├───┐           ┌───┤Bks│
      *               └───┤Sp2├───┐   ┌───┤(2)├───┘
      *                   └───┤Sft│   │Ctl├───┘
      *                       └───┘   └───┘
      */
    [1] = LAYOUT_split_3x6_3(
        KC_NO,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
        KC_NO,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_NO,
        KC_NO,  MT(MOD_LALT, KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    TD(TD_COMM_MINS), TD(TD_DOT_EXLM),  TD(TD_SLSH_UND), KC_NO,
                                        KC_LGUI, LT(2, KC_SPACE), OSM(MOD_LSFT),       OSM(MOD_LCTL) , TO(2), KC_BSPC
    ),
     /* 2 Symbols
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │Esc│ @ │ # │ $ │ % │       │ ^ │ & │ * │ = │BSp│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Tab│ ` │ ~ │Alt│Del│       │\ h│ { │ } │| e│Ent│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │(1)│Cut│Cpy│Und│Pst│       │ [ │ ( │ ) │ ] │(4)│
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Win├───┐           ┌───┤Alt│
      *               └───┤(0)├───┐   ┌───┤(3)├───┘
      *                   └───┤Sft│   │Ctl├───┘
      *                       └───┘   └───┘
      */
    [2] = LAYOUT_split_3x6_3(
        KC_NO,  KC_ESCAPE,    KC_AT, LSFT(KC_3),    LSFT(KC_4),    KC_PERC,  /* */ KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_EQL, KC_BSPC,    KC_NO,
        KC_NO, KC_TAB,KC_GRAVE    ,LSFT(KC_GRAVE)    ,KC_LALT    ,KC_DEL,     /* */  TD(TD_BKSL_HME),LSFT(KC_LBRC),LSFT(KC_RBRC),TD(TD_PIPE_END),KC_ENTER, KC_NO,
        KC_NO,  TO(1), LCTL(KC_X)   ,LCTL(KC_C)   ,LCTL(KC_Z)   ,LCTL(KC_V)    /* */ ,KC_LBRC,  KC_LPRN, KC_RPRN, KC_RBRC   ,TO(4), KC_NO,
                                            KC_LGUI, TO(0), OSM(MOD_LSFT),          OSM(MOD_LCTL)   ,TO(3),  KC_RALT
    ),
     /* 3 Numbers and volume
      * ┌───┬───┬───┬───┬───┐       ┌─────┬───┬───┬───┬───┐
      * │Esc│V D│V U│ * │ + │       │./F11│7/F│4/F│9/F│BSp│
      * ├───┼───┼───┼───┼───┤       ├─────┼───┼───┼───┼───┤
      * │Tab│Mut│ ; │ / │ - │       │./F12│4/F│3/F│6/F│Ent│
      * ├───┼───┼───┼───┼───┤       ├─────┼───┼───┼───┼───┤
      * │(1)│(5)│ , │ = │Spc│       │  0  │1/F│2/F│3/F│(4)│
      * └───┴───┴───┴───┴───┘       └─────┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Win├───┐           ┌───┤Alt│
      *               └───┤(0)├───┐   ┌───┤(2)├───┘
      *                   └───┤Sft│   │Ctl├───┘
      *                       └───┘   └───┘
      */
  [3] = LAYOUT_split_3x6_3(
   KC_NO, KC_ESCAPE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, LSFT(KC_8), LSFT(KC_EQL), /* */ TD(TD_DOT_F11),   TD(TD_7_F7),  TD(TD_8_F8), TD(TD_9_F9),KC_BSPC, KC_NO,
    KC_NO, KC_TAB, KC_MUTE, KC_SCLN, KC_SLSH ,KC_MINS,   /* */ TD(TD_DOT_F12),   TD(TD_4_F4), TD(TD_5_F5), TD(TD_6_F6),   KC_ENTER, KC_NO,
    KC_NO, TO(1),   TO(5), KC_COMM, KC_EQL, KC_SPACE, /* */  KC_0,   TD(TD_1_F1), TD(TD_2_F2), TD(TD_3_F3),   TO(4), KC_NO,
                                            KC_LGUI, TO(0), OSM(MOD_LSFT),          OSM(MOD_LCTL)   ,TO(2), OSM(MOD_LALT)
  ),
     /* 4 Navigation
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │Esc│S L│M U│S R│CtQ│       │Bck│Pre│Nex│Fwd│BSp│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Tab│M L│M D│M R│DEL│       │LFT│DWN│UP │RHT│Ent│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │(1)│RBn│S U│S D│Spc│       │LBn│PDn│PUp│Ac2│Ac3│
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Win├───┐           ┌───┤Alt│
      *               └───┤(0)├───┐   ┌───┤(2)├───┘
      *                   └───┤Sft│   │Ctl├───┘
      *                       └───┘   └───┘
      */
  [4] = LAYOUT_split_3x6_3(
        KC_NO, KC_ESCAPE, KC_MS_WH_LEFT, KC_MS_UP, KC_MS_WH_RIGHT, LCTL(KC_Q),  /* */ LALT(KC_LEFT), LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), LALT(KC_RIGHT),KC_BSPC, KC_NO,
	    KC_NO, KC_TAB,KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_DEL, /* */ KC_LEFT,   KC_DOWN, KC_UP,   KC_RIGHT,   KC_ENTER, KC_NO,
        KC_NO, TO(1),   KC_MS_BTN2,     KC_MS_WH_UP,    KC_MS_WH_DOWN, KC_SPACE, /* */ KC_MS_BTN1,     KC_PAGE_DOWN,   KC_PAGE_UP,   KC_MS_ACCEL1,   KC_MS_ACCEL2, KC_NO,
                                            KC_LGUI, TO(0), OSM(MOD_LSFT),          OSM(MOD_LCTL)   ,TO(2), OSM(MOD_LALT)

    ),
     /* 5 LOL
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ 1 │ 2 │ 3 │ 4 │ 5 │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Q │ W │ E │ R │ T │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Sft│Tab│ D │ F │ G │       │   │   │   │   │   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤(0)│
      *               └───┤Spc├───┐   ┌───┤(0)├───┘
      *                   └───┤   │   │(0)├───┘
      *                       └───┘   └───┘
      */
  [5] = LAYOUT_split_3x6_3(
        KC_NO,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,  KC_LSFT,    KC_TAB,    KC_D,    KC_F,    KC_G,                               KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO,
                                        KC_NO, KC_SPACE, KC_NO,       TO(0) , TO(0), TO(0)

    )
};

/*
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 0:
            tap_code16(KC_F20);
            break;
        case 1:
            tap_code16(KC_F21);
            break;
        case 2:
            tap_code16(KC_F22);
            break;
        case 3:
            tap_code16(KC_F23);
            break;
        case 4:
            tap_code16(KC_F24);
            break;
        case 5:
            tap_code16(KC_F19);
            break;
        default:
            break;
    }
    return state;
}
*/
