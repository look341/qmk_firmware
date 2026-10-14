#define ACTION_TAP_HOLD(kc1, kc2) \
    { .fn = {tap_hold_on_each_tap, tap_hold_on_dance_finished, tap_hold_on_dance_reset, NULL}, .user_data = (void *)&((tap_dance_pair_t){kc1, kc2}), }

void tap_hold_on_each_tap(tap_dance_state_t *state, void *user_data);
void tap_hold_on_dance_finished(tap_dance_state_t *state, void *user_data);
void tap_hold_on_dance_reset(tap_dance_state_t *state, void *user_data);
