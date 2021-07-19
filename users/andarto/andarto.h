#pragma once

#ifndef ANDARTO
#define ANDARTO


#include "quantum.h"

#define LAYOUT_preonic_grid_wrapper(...)    LAYOUT_preonic_grid(__VA_ARGS__)

#define _________________NUMBER_L1_________________        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _________________NUMBER_R1_________________        KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define ______NUMBER_B13______                             DE_1,    DE_2,    DE_3
#define ______NUMBER_B46______                             DE_4,    DE_5,    DE_6
#define ______NUMBER_B46______                             DE_4,    DE_5,    DE_6
#define ______NUMBER_B79______                             DE_7,    DE_8,    DE_9
#define ______NUMBER_B00______                             _______, DE_0, _______

#define _________________SYMBOL_L1_________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________SYMBOL_R1_________________        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN

#define _________________QWERTY_L1_________________        DE_Q,    DE_W,    DE_E,    DE_R,    DE_T
#define _________________QWERTY_L2_________________        DE_A,    DE_S,    DE_D,    DE_F,    DE_G
#define _________________QWERTY_L3_________________        DE_Z,    DE_X,    DE_C,    DE_V,    DE_B

#define _________________QWERTY_R1_________________        DE_Y,    DE_U,    DE_I,    DE_O,    DE_P
#define _________________QWERTY_R2_________________        DE_H,    DE_J,    DE_K,    DE_L,    DE_SCLN
#define _________________QWERTY_R3_________________        DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_SLSH

#define _________________QWERTZ_L3_________________        DE_Y,    DE_X,    DE_C,    DE_V,    DE_B
#define _________________QWERTZ_R1_________________        DE_Z,    DE_U,    DE_I,    DE_O,    DE_P

#define _________________KAYNEO_L1_________________        DE_K,    DE_DOT,  DE_A,    DE_COMM, DE_Y
#define _________________KAYNEO_L2_________________        DE_H,    DE_O,    DE_E,    DE_I,    DE_U
#define _________________KAYNEO_L3_________________        DE_Z,    DE_Q,    N_HS,    DE_X,    DE_SLSH

#define _________________KAYNEO_R1_________________        DE_P,    DE_D,    DE_L,    DE_M,    DE_J
#define _________________KAYNEO_R2_________________        DE_G,    DE_T,    DE_R,    DE_N,    DE_S
#define _________________KAYNEO_R3_________________        DE_B,    DE_C,    DE_W,    DE_V,    DE_F

#define ____________FUNCTION_1____________                 KC_F1,   KC_F2,   KC_F3,   KC_F4
#define ____________FUNCTION_2____________                 KC_F5,   KC_F6,   KC_F7,   KC_F8
#define ____________FUNCTION_3____________                 KC_F9,   KC_F10,  KC_F11,  KC_F12

#define ___SQBRACKETS___                                   KT_LBRC, KT_RBRC
#define _____PARENS_____                                   KC_LPRN, KC_RPRN
#define ____CRBRACES____                                   KC_LCBR, KC_RCBR
#define ___ANBRACKETS___                                   KC_LT,   KC_GT

#endif
