#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)

// Right-hand home row mods
#define HOME_N RCTL_T(KC_N)
#define HOME_E LSFT_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)

// Right-hand home row mods layer 1
#define HOME_DOWN RCTL_T(KC_DOWN)
#define HOME_UP LSFT_T(KC_UP)
#define HOME_RIGHT LALT_T(KC_RIGHT)

// Right-hand home row mods layer 2
#define HOME_EQL RCTL_T(KC_EQL)
#define HOME_LBRC LSFT_T(KC_LBRC)
#define HOME_RBRC LALT_T(KC_RBRC)
#define HOME_BSLS RGUI_T(KC_BSLS)

// Space and enter
#define LT_ENT LT(1,KC_ENT)
#define LT_TAB LT(2,KC_TAB)

// One-shot modifiers
#define OSM_RALT OSM(MOD_RALT)
#define OSM_LSFT OSM(MOD_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    #if defined AUTO_SHIFT || defined HRM_SHIFT
    [0] = LAYOUT_split_3x6_3_ex2(
        KC_LBRC, KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,   KC_GRV,   KC_SLEP, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_RBRC,
        CW_TOGG, HOME_A, HOME_R, HOME_S, HOME_T, KC_G,   MO(3),    MO(3),   KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,  KC_QUOT,
        KC_LPRN, KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,                      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RPRN,
                                 KC_ESC, KC_SPC, LT_TAB,                    LT_ENT,  KC_BSPC, OSM_RALT
    ),
    #endif
    #ifdef DEDICATED_SHIFT
    [0] = LAYOUT_split_3x6_3_ex2(
        KC_LBRC, KC_Q,   KC_W,     KC_F,     KC_P,   KC_B,   KC_GRV,   KC_SLEP, KC_J,    KC_L,     KC_U,    KC_Y,    KC_SCLN, KC_RBRC,
        KC_ESC,  HOME_A, HOME_R,   HOME_S,   HOME_T, KC_G,   MO(3),    MO(3),   KC_M,    HOME_N,   HOME_E,  HOME_I,  HOME_O,  KC_QUOT,
        KC_LPRN, KC_Z,   KC_X,     KC_C,     KC_D,   KC_V,                      KC_K,    KC_H,     KC_COMM, KC_DOT,  KC_SLSH, KC_RPRN,
                                   OSM_RALT, KC_SPC, LT_TAB,                    LT_ENT,  OSM_LSFT, KC_BSPC
    ),
    #endif
    [1] = LAYOUT_split_3x6_3_ex2(
        KC_NO, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,  KC_PGUP, KC_6,    KC_7,      KC_8,    KC_9,       KC_0,    KC_NO,
        KC_NO, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO,   KC_NO,    KC_PGDN, KC_LEFT, HOME_DOWN, HOME_UP, HOME_RIGHT, KC_RGUI, KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,     KC_COMM, KC_DOT,     KC_NO,   KC_NO,
                                 KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS,   KC_TRNS
    ),
    [2] = LAYOUT_split_3x6_3_ex2(
        KC_NO, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,  KC_NO, KC_CIRC, KC_AMPR,  KC_ASTR,   KC_LPRN,   KC_RPRN,   KC_NO,
        KC_NO, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO,   KC_NO,    KC_NO, KC_MINS, HOME_EQL, HOME_LBRC, HOME_RBRC, HOME_BSLS, KC_GRV,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                    KC_UNDS, KC_PLUS,  KC_LCBR,   KC_RCBR,   KC_PIPE,   KC_TILD,
                                 KC_TRNS, KC_TRNS, KC_TRNS,                  KC_TRNS, KC_TRNS,  KC_TRNS
    ),
    [3] = LAYOUT_split_3x6_3_ex2(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_TRNS,  QK_BOOT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        RGB_VAI, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO,   KC_TRNS,  KC_TRNS, KC_NO,   KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, KC_NO,
        RGB_VAD, RGB_MOD, RGB_TOG, KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                   KC_VOLD, KC_VOLU, KC_MUTE,                    KC_MPLY, KC_MPRV, KC_MNXT
    )
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_3_ex2(
        'L', 'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', 'R',
                       '*', '*', '*',            '*', '*', '*'
    );

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_S:
        case HOME_E:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

bool is_flow_tap_key(uint16_t keycode) {
    switch (keycode) {
        #ifdef HRM_SHIFT
        case HOME_S:
        case HOME_E:
        case HOME_UP:
        case HOME_LBRC:
        #endif
        case LT_ENT:
        case LT_TAB:
            return false;
        default:
            return true;
    }
}

#ifdef AUTO_SHIFT
bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case HOME_A:
        case HOME_R:
        case HOME_S:
        case HOME_T:
        case HOME_N:
        case HOME_E:
        case HOME_I:
        case HOME_O:
        case KC_LBRC:
        case KC_RBRC:
            return true;
        default:
            return false;
    }
}
#endif

#ifdef HRM_SHIFT
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_S:
        case HOME_E:
        case HOME_UP:
        case HOME_LBRC:
        case LT_ENT:
        case LT_TAB:
            return TAPPING_TERM_SHIFT;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_S:
        case HOME_E:
        case HOME_UP:
        case HOME_LBRC:
            return true;
        default:
            return false;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_S:
        case HOME_E:
        case HOME_UP:
        case HOME_LBRC:
            return true;
        default:
            return false;
    }
}
#endif

#ifdef DEDICATED_SHIFT
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LSFT:
        case OSM(MOD_LSFT):
            return TAPPING_TERM_SHIFT;
        default:
            return TAPPING_TERM;
    }
}
#endif


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 3:
                rgb_matrix_set_color(i, RGB_YELLOW);
                break;
            case 2:
                rgb_matrix_set_color(i, RGB_BLUE);
                break;
            case 1:
                rgb_matrix_set_color(i, RGB_GREEN);
                break;
            default:
                break;
        }
        if (get_mods() == MOD_BIT(KC_LSFT) || get_mods() == MOD_BIT(KC_RSFT)) {
            rgb_matrix_set_color(i, RGB_RED);
        }
        if (host_keyboard_led_state().caps_lock) {
            rgb_matrix_set_color(i, RGB_RED);
        }
    }
    if (is_caps_word_on()) {
        for (uint8_t i = 15; i < 21; i++) {
            rgb_matrix_set_color(i, RGB_RED);
        }
    }
    return false;
}

