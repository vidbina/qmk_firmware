/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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

// Based on ../default/keymap.c
// and borrowing from Callum: https://github.com/callum-oakley/qmk_firmware
#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NAV,
    LAYER_SYM,
    LAYER_NUM,
    LAYER_DEV
};

#define NAV MO(LAYER_NAV)
#define SYM MO(LAYER_SYM)
#define DEV MO(LAYER_DEV)

#define ONESHOT_TAP_TOGGLE 2

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_RALT OSM(MOD_RALT)
#define OS_RGUI OSM(MOD_RGUI)

#define TH_L_IN LALT_T(KC_SPC)
#define TH_R_IN RCTL_T(KC_SPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_split_3x5_2(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_RGUI,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                      NAV, TH_L_IN,    TH_R_IN,     SYM
  //                            ╰──────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NAV] = LAYOUT_split_3x5_2(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX,  KC_TAB,  KC_ESC, XXXXXXX, KC_VOLU,    XXXXXXX, KC_HOME,  KC_END,  KC_DEL, KC_BSPC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       OS_LSFT, OS_LCTL, OS_LALT, OS_LGUI, KC_VOLD,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
           DEV, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY,     KC_ENT, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                  _______, _______,    _______, _______
  //                            ╰──────────────────╯ ╰──────────────────╯
  ),

  [LAYER_SYM] = LAYOUT_split_3x5_2(
  // TODO: Map symbols closer to QWERTY mapping (especially top-row)
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
        KC_GRV, KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD,    KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_SCLN,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_MINS, KC_ASTR,  KC_EQL, KC_UNDS,  KC_DLR,    KC_HASH, OS_RGUI, OS_RALT, OS_RCTL, OS_RSFT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_PLUS, KC_PIPE,   KC_AT, KC_SLSH, KC_PERC,    KC_EXLM, KC_BSLS, KC_AMPR, KC_QUES,     DEV,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                  _______, _______,    _______, _______
  //                            ╰──────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NUM] = LAYOUT_split_3x5_2(
  // Number row from https://github.com/callum-oakley/qmk_firmware
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_7,    KC_5,    KC_3,    KC_1,    KC_9,       KC_8,    KC_0,    KC_2,    KC_4,    KC_6,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,  KC_F11,     KC_F12, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                  _______, _______,    _______, _______
  //                            ╰──────────────────╯ ╰──────────────────╯
  ),

  [LAYER_DEV] = LAYOUT_split_3x5_2(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, EEP_RST,    EEP_RST, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
           DEV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     DEV,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                  _______, _______,    _______, _______
  //                            ╰──────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, LAYER_NAV, LAYER_SYM, LAYER_NUM);
}
