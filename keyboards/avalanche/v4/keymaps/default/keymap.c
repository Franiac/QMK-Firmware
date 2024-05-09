#include QMK_KEYBOARD_H

enum custom_keycodes {
    AE = SAFE_RANGE,
    OE,
    UE,
    SZ
};

enum layer {
    LAYER_0,
    LAYER_1,
    LAYER_2,
};

#define MO1 MO(LAYER_1)
#define MO2 MO(LAYER_2)
#define SFT_SPC LSFT_T(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_0] = LAYOUT(
                 KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                                KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
        KC_CAPS, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,
                 KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
                                            KC_NUM,  KC_LALT, KC_LGUI, SFT_SPC, KC_ESC,           KC_ENT,  MO1,     MO2,     KC_RALT, KC_APP
    ),
    [LAYER_1] = LAYOUT(
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_0,    KC_1,    KC_2,    KC_3,    KC_LPRN,                                              KC_RPRN, KC_HOME, KC_UP,   KC_END,  KC_NO,   KC_NO,
        KC_TRNS, KC_TRNS, KC_0,    KC_4,    KC_5,    KC_6,    KC_DEL,                                               KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_MINS, KC_EQL,  KC_NO,
                 KC_TRNS, KC_0,    KC_7,    KC_8,    KC_9,    KC_LCBR, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_RCBR, KC_PGDN, KC_INS,  KC_PGUP, KC_NO,   KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [LAYER_2] = LAYOUT(
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_NO,                                                KC_NO,   KC_EXLM, KC_AT,   KC_HASH, UE,      SZ,
        KC_TRNS, KC_TRNS, KC_P0,   KC_P4,   KC_P5,   KC_P6,   KC_NO,                                                KC_NO,   KC_DLR,  KC_PERC, KC_CIRC, OE,      AE,      KC_NO,
                 KC_TRNS, KC_P0,   KC_P7,   KC_P8,   KC_P9,   KC_LBRC, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_RBRC, KC_AMPR, KC_ASTR, KC_NO,   KC_NO,   KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mods = get_mods();
    uint8_t shift = mods & MOD_MASK_SHIFT;

    switch (keycode) {
        case AE:
            clear_mods();

            if (record->event.pressed) {
                if (shift) {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P1)SS_TAP(X_P9)SS_TAP(X_P6)));
                }
                else {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P2)SS_TAP(X_P8)));
                }
            }

            set_mods(mods);
            break;
        case OE:
            clear_mods();

            if (record->event.pressed) {
                if (shift) {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P1)SS_TAP(X_P4)));
                }
                else {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P4)SS_TAP(X_P6)));
                }
            }

            set_mods(mods);
            break;
        case UE:
            clear_mods();

            if (record->event.pressed) {
                if (shift) {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P2)SS_TAP(X_P0)));
                }
                else {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P5)SS_TAP(X_P2)));
                }
            }

            set_mods(mods);
            break;
        case SZ:
            clear_mods();

            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_RALT)SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P2)SS_TAP(X_P3)SS_UP(X_RALT));
            }

            set_mods(mods);
            break;
    }

    return true;
}
