#include QMK_KEYBOARD_H
#include "tapHold.h"

#define ACTION_TAP_HOLD(kc1, kc2) \
    { .fn = {tap_hold_on_each_tap, tap_hold_on_dance_finished, tap_hold_on_dance_reset, NULL}, .user_data = (void *)&((tap_dance_pair_t){kc1, kc2}), }

/* Tap Dance Setup */

typedef struct {
    uint16_t tapCode;
    uint16_t holdCode;
} tapHoldData;

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state = {
    .is_press_action = true,
    .step = 0
};


void tap_hold_on_each_tap(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_t *pair = (tap_dance_pair_t *)user_data;

    if(state->count == 3) {
        tap_code16(pair->kc1);
        tap_code16(pair->kc1);
        tap_code16(pair->kc1);
    }
    if(state->count > 3) {
        tap_code16(pair->kc1);
    }
}

uint8_t get_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void tap_hold_on_dance_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_t *pair = (tap_dance_pair_t *)user_data;

    dance_state.step = get_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(pair->kc1); break;
        case SINGLE_HOLD: register_code16(pair->kc2); break;
        case DOUBLE_TAP: register_code16(pair->kc1); register_code16(pair->kc1); break;
        case DOUBLE_SINGLE_TAP: tap_code16(pair->kc1); register_code16(pair->kc1); break;
        case DOUBLE_HOLD: register_code16(pair->kc1); break;
    }
}

void tap_hold_on_dance_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_t *pair = (tap_dance_pair_t *)user_data;

    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(pair->kc1); break;
        case SINGLE_HOLD: unregister_code16(pair->kc2); break;
        case DOUBLE_TAP: unregister_code16(pair->kc1); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(pair->kc1); break;
        case DOUBLE_HOLD: unregister_code16(pair->kc1); break;
    }
    dance_state.step = 0;
}
