// qmk compile -kb avalanche/v4 -km default
// qmk flash -kb avalanche/v4 -km default

#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

enum custom_keycodes {
    AE = 0x6660,
    OE = 0x6661,
    UE = 0x6662,
    SZ = 0x6663
};

enum layer {
    LAYER_0,
    LAYER_1,
    LAYER_2,
};

#define M1 MO(LAYER_1)
#define M2 MO(LAYER_2)
#define L1 LALT_T(KC_ESC)
#define L2 LSFT_T(KC_SPC)
#define R1 RSFT_T(KC_ENT)
#define R2 RALT_T(KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_0] = LAYOUT(
                 KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                                KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
        KC_CAPS, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,
                 KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
                                            KC_LGUI, KC_INS,  KC_DEL,  L2,      L1,               R1,      R2,      M1,      M2,      KC_APP
    ),
    [LAYER_1] = LAYOUT(
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_0,    KC_1,    KC_2,    KC_3,    KC_LBRC,                                              KC_RBRC, KC_EXLM, KC_AT,   KC_HASH, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_0,    KC_4,    KC_5,    KC_6,    KC_LPRN,                                              KC_RPRN, KC_DLR,  KC_PERC, KC_CIRC, KC_MINS, KC_EQL, KC_TRNS,
                 KC_TRNS, KC_0,    KC_7,    KC_8,    KC_9,    KC_LCBR, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_RCBR, KC_AMPR, KC_ASTR, KC_TRNS, KC_TRNS,  KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [LAYER_2] = LAYOUT(
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_HOME, KC_UP,   KC_END,  UE,      UE,
        KC_TRNS, KC_TRNS, KC_TRNS, SZ,      KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, OE,      AE,      KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    debug_enable=true;
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef CONSOLE_ENABLE
    uprintf("KC: 0x%04X, MOD: 0x%04X, COL: %2u, ROW: %2u, PRESSED: %u, TIME: %5u, INT: %u, COUNT: %u\n", keycode, get_mods() & MOD_MASK_SHIFT, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

    switch (keycode) {
        case AE:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    SEND_STRING("Ä");
                }
                else {
                    SEND_STRING("ä");
                }
            }
            break;
        case OE:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    SEND_STRING("Ö");
                }
                else {
                    SEND_STRING("ö");
                }
            }
            break;
        case UE:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    SEND_STRING("Ü");
                }
                else {
                    SEND_STRING("ü");
                }
            }
            break;
        case SZ:
            if (record->event.pressed) {
                SEND_STRING("ß");
            }
            break;
    }
    return true;
}
