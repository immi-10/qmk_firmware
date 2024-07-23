// Copyright 2022 Mark Stosberg (@markstos)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
// #include "keymap_german_mac_iso.h"

enum custom_keycodes { QWERTY = SAFE_RANGE, LOWER, RAISE, FUNC, PINKY, BACKLIT };

enum combos { DF_DASH, JK_ESC };

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    // Add commonly used dash to home row
    [DF_DASH] = COMBO(df_combo, KC_MINS),
    // For Vim, put Escape on the home row
    [JK_ESC] = COMBO(jk_combo, KC_ESC),
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers { _QWERTY, _LOWER, _RAISE, _FUNC, _PINKY, _L_LAYER };

// For _QWERTY layer
#define GUI_ENT GUI_T(KC_ENT)
#define GUI_COMM GUI_T(KC_COMM)
#define LOW_BSPC LT(_LOWER, KC_BSPC)
#define FUNC_A LT(_FUNC, KC_COLON)
#define RSE_SP LT(_RAISE, KC_SPC)
#define OSM_SFT OSM(MOD_LSFT)
#define PINKY_V LT(_PINKY, KC_COMM)

// For _RAISE layer..
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_QST LCTL_T(KC_SLSH)

#define GUI_SPACE LGUI(KC_SPC)

// Define the Alt + Command + Space shortcut
#define ALT_CMD_SPACE LALT(LGUI(KC_SPACE))
#define CM_BSPC LGUI(KC_BSPC)  // Tap for Backspace, hold for Command
#define AT_BSPC LALT(KC_BSPC)  // Tap for Backspace, hold for Command
#define ALT_LEFT LALT(KC_LEFT) // Alt + Left arrow
#define ALT_RGHT LALT(KC_RGHT) // Alt + Right arrow

#define CMD_LEFT LGUI(KC_LEFT) // Alt + Left arrow
#define CMD_RGHT LGUI(KC_RGHT) // Alt + Right arrow

#define S_ALT_LEFT LSFT(LALT(KC_LEFT)) // Shift + Alt + Left arrow
#define S_ALT_RGHT LSFT(LALT(KC_RGHT)) // Shift + Alt + Right arrow

#define S_CMD_LEFT LSFT(LGUI(KC_LEFT)) // Shift + Cmd + Left arrow
#define S_CMD_RGHT LSFT(LGUI(KC_RGHT)) // Shift + Cmd + Right arrow

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[_QWERTY] = LAYOUT(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                      KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_G,      KC_P,                      KC_Z,     KC_U,      KC_K,   KC_L,   CTL_QST, KC_DEL,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                    OSM_SFT,    KC_A,   KC_R,   KC_S,   KC_T,     KC_D,                        KC_H,      KC_N,      KC_E,   KC_I,   KC_O,   OSM_SFT,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                    OSM(MOD_LALT), S(KC_S), KC_Y, KC_V,     KC_C,   KC_X,                       KC_B,   KC_J,    KC_M,   KC_DOT, KC_COLON, OSM(MOD_LALT),
                                                                  //|-------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                                                    GUI_COMM, LOW_BSPC, CTL_ESC,    GUI_ENT, RSE_SP, FUNC_A
                                                                                                    //`--------------------------'  `--------------------------'
                                                                  ),

                                                              [_RAISE] = LAYOUT(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  KC_PLUS, KC_TILDE, KC_PIPE, KC_DQUO, KC_EXLM, KC_QUOT, XXXXXXX, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  S(KC_COMM), S(KC_DOT), KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, GUI_SPACE, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  KC_GRV, KC_BSLS, KC_AMPR, KC_HASH, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_CIRC, KC_DLR, KC_PERC, XXXXXXX, XXXXXXX, XXXXXXX
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),

                                                              [_LOWER] = LAYOUT(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ALT_CMD_SPACE, KC_UNDS, KC_UP, KC_RGHT,  KC_AT, S_ALT_RGHT,
                                                                  //|--------+--------+--------+----s----+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_UNDS, KC_MINUS, KC_ASTR,  KC_EQUAL,S_ALT_LEFT,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S_CMD_LEFT, KC_DOWN, CMD_RGHT, ALT_LEFT, ALT_RGHT, S_CMD_RGHT,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, CM_BSPC, AT_BSPC, CMD_LEFT
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),

                                                              [_FUNC] = LAYOUT(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  XXXXXXX, KC_9, KC_8, KC_7, KC_6, KC_5, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, KC_4, KC_3, KC_2, KC_1, KC_0, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  S_CMD_LEFT, CMD_LEFT, CMD_RGHT, ALT_LEFT, ALT_RGHT, S_CMD_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),

                                                              [_PINKY] = LAYOUT(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  XXXXXXX, XXXXXXX, S_ALT_LEFT, S_ALT_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  S_CMD_LEFT, CMD_LEFT, ALT_LEFT, ALT_RGHT, CMD_RGHT, S_CMD_RGHT, XXXXXXX, XXXXXXX, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, XXXXXXX, OSM_SFT,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, KC_ASTR, S(KC_V), XXXXXXX, XXXXXXX, XXXXXXX
                                                                  //`--------------------------'  `--------------------------'
                                                                  )};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_RAISE, KC_BSPC):
            return TAPPING_TERM_THUMB;
        case LT(_LOWER, KC_TAB):
            return TAPPING_TERM_THUMB;
        default:
            return TAPPING_TERM;
    }
}
