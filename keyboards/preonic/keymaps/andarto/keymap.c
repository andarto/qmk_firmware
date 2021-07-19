/* Copyright 2019-2021 Andarto
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
#include <keymap_german.h>
#include <sendstring_german.h>
#include "andarto.h"
#include "oneshot.h"
#include "version.h"

extern keymap_config_t keymap_config;

enum preonic_layers {
  _QWERTY,
  _KAYNEO,
  _SYMB,
  _NAVI,
  _LANG,
  _FUNC,
  _ADJUST,
  _PRG,
  _OSM
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  KAYNEO,
  COLEQ,
  PLUSEQ,
  MINUSEQ,
  HOMESLSH,
  CWDTAB,
  SHCMD,
  SHVAR,
  COLCOM,
  GOCUBR,
  KB_MAKE,
  KB_VRSN,
  OS_SHFT,
  OS_CTRL,
  OS_ALT,
  OS_CMD,
  OS_MEH,
  OS_HYPR
};

enum unicode_names {
    U_EACUTE,
    U_IRONY,
    U_CHECK,
    U_CROSS,
    U_BULL,
    U_TBULL,
    U_HBULL,
    U_OPDOT,
    U_SPACE,
    U_EMDSH,
    U_ARRLF,
    U_ARRUP,
    U_ARRRT,
    U_ARRDN,
    U_NEQ
};

const uint32_t PROGMEM unicode_map[] = {
    [U_EACUTE] = 0x00E9, // é
    [U_IRONY]  = 0x2E2E, // ⸮
    [U_CHECK]  = 0x2713, // ✓
    [U_CROSS]  = 0x2717, // ✗
    [U_BULL]   = 0x2022, // •
    [U_TBULL]  = 0x2023, // ‣
    [U_HBULL]  = 0x2043, // ⁃
    [U_OPDOT]  = 0x2219, // ∙
    [U_SPACE]  = 0x2423, // ␣
    [U_EMDSH]  = 0x2014, // —
    [U_ARRLF]  = 0x2190, // ←
    [U_ARRUP]  = 0x2191, // ↑
    [U_ARRRT]  = 0x2192, // →
    [U_ARRDN]  = 0x2193, // ↓
    [U_NEQ]    = 0x2260, // ≠
};


#define N_LT KC_NONUS_BSLASH
#define N_HS KC_NONUS_HASH
#define N_DOTS RALT(KC_DOT) // …
#define N_USC LSFT(KC_SLASH) // _
#define N_LSQBR RALT(KC_8) // [
#define N_RSQBR RALT(KC_9) // ]
#define N_CIRC KC_GRAVE // ^
#define N_EXKL LSFT(KC_1) // !
#define N_PARA LSFT(KC_3) // §
#define N_GT LSFT(KC_NONUS_BSLASH) // >
#define N_EQ LSFT(KC_0) // =
#define N_AMP LSFT(KC_6) // &
#define N_BSLS RALT(KC_MINS) // \ backslash
#define N_SLSH LSFT(KC_7) // /
#define N_LCUBR RALT(KC_7) // {
#define N_RCUBR RALT(KC_0) // }
#define N_ASTR LSFT(KC_RBRC) // *
#define N_QUES LSFT(KC_MINS) // ?
#define N_LPARN LSFT(KC_8) // (
#define N_RPARN LSFT(KC_9) // )
#define N_MINS KC_SLASH // -
#define N_COLN LSFT(KC_DOT) // :
#define N_HASH KC_BSLASH // #
#define N_DLR LSFT(KC_4) // $
#define N_PIPE RALT(KC_NONUS_BSLASH) // |
#define N_TILD RALT(KC_RBRC) // ~
#define N_GRAVE LSFT(KC_EQUAL) // `
#define N_PLUS KC_RBRC // +
#define N_PERC LSFT(KC_5) // %
#define N_QUOT LSFT(KC_2) // "
#define N_SING LSFT(KC_BSLASH) // '
#define N_SEMI LSFT(KC_COMM) // ;
#define N_EURO RALT(KC_E) // €
#define N_AT RALT(KC_Q) // @
#define N_Z KC_Y
#define N_Y KC_Z
#define N_AE KC_QUOTE // ä
#define N_OE KC_SCOLON // ö
#define N_UE KC_LBRACKET // ü
#define N_MU RALT(KC_M) // µ
#define N_SS KC_MINS // ß
#define N_DEGRE LSFT(KC_GRAVE) // °
#define N_PASTE LCTL(KC_V) // CTRL+V
#define N_COPY LCTL(KC_C) // CTRL+C
#define N_CUT LCTL(KC_X) // CTRL+X
#define N_UNDO LCTL(N_Z) // CTRL+Z

#define N_EAC X(U_EACUTE)
#define N_IRONY X(U_IRONY)
#define N_CHECK X(U_CHECK)
#define N_CROSS X(U_CROSS)
#define N_YESNO XP(U_CHECK, U_CROSS)
#define N_UNIDOT XP(U_BULL, U_OPDOT)
#define N_HBULL X(U_HBULL)
#define N_TBULL X(U_TBULL)
#define N_VSPC X(U_SPACE)
#define N_EMDSH X(U_EMDSH)
#define N_ARRLF X(U_ARRLF)
#define N_ARRUP X(U_ARRUP)
#define N_ARRRT X(U_ARRRT)
#define N_ARRDN X(U_ARRDN)
#define N_NEQ X(U_NEQ)

#define LA_SYMB MO(_SYMB)
#define LA_NAVI MO(_NAVI)
#define LA_LANG MO(_LANG)
#define LA_FUNC MO(_FUNC)
#define LA_OSM MO(_OSM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* empty grid for copying
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
*/

/* Qwerty
 * ,-------------------------------------------------------------------------------------------------------------------------------.
 * | Esc         |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |    0    | Bksp        |
 * | LA_LANG     |    Q    |    W    |    E    |    R    |    T    |    Y    |    U    |    I    |    O    |    P    | LA_LANG/Del |
 * | LA_SYMB/Tab |    A    |    S    |    D    |    F    |    G    |    H    |    J    |    K    |    L    |    ;    | LA_SYMB/Ent |
 * | Shift/App   |    Z    |    X    |    C    |    V    |    B    |    N    |    M    |    ,    |    .    |    /    | Shift/Ent   |
 * | LCtrl       |   GUI   |   LAlt  | LA_OSM  | LA_NAVI |       Space       | LA_NAVI | LA_OSM  |   RAlt  | LA_FUNC | RCtrl       |
 * `-------------------------------------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid_wrapper(
    KC_ESC,            _________________NUMBER_L1_________________, _________________NUMBER_R1_________________, KC_BSPC,
    LA_LANG,           _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, LT(_LANG, KC_DEL),
    LT(_SYMB, KC_TAB), _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, LT(_SYMB, KC_ENT),
    LSFT_T(KC_APP),    _________________QWERTZ_L3_________________, _________________QWERTY_R3_________________, KC_SFTENT ,
    KC_LCTL,           KC_LGUI, KC_LALT,  LA_OSM,  LA_NAVI, KC_SPC, KC_SPC,  LA_NAVI,  LA_OSM, KC_RALT, LA_FUNC, KC_RCTL
),

/* KayNeo (adapted)
 * ,-------------------------------------------------------------------------------------------------------------------------------.
 * | Esc         |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |    0    | Bksp        |
 * | LA_LANG     |    K    |    .    |    A    |    ,    |    Y    |    P    |    D    |    L    |    M    |    J    | LA_LANG/Del |
 * | LA_SYMB/Tab |    H    |    O    |    E    |    I    |    U    |    G    |    T    |    R    |    N    |    S    | LA_SYMB/Ent |
 * | Shift/App   |    Z    |    Q    |    #    |    X    |    /    |    B    |    C    |    W    |    V    |    F    | Shift/Ent   |
 * | LCtrl       |   LWin  |   LAlt  | LA_OSM  | LA_NAVI |       Space       | LA_NAVI | LA_OSM  |   RAlt  | LA_FUNC | RCtrl       |
 * `-------------------------------------------------------------------------------------------------------------------------------'
 */
[_KAYNEO] = LAYOUT_preonic_grid_wrapper(
    KC_ESC,            _________________NUMBER_L1_________________, _________________NUMBER_R1_________________, KC_BSPC,
    LA_LANG,           _________________KAYNEO_L1_________________, _________________KAYNEO_R1_________________, LT(_LANG, KC_DEL),
    LT(_SYMB, KC_TAB), _________________KAYNEO_L2_________________, _________________KAYNEO_R2_________________, LT(_SYMB, KC_ENT) ,
    LSFT_T(KC_APP),    _________________KAYNEO_L3_________________, _________________KAYNEO_R3_________________, KC_SFTENT,
    KC_LCTL,           KC_LGUI, KC_LALT,  LA_OSM,  LA_NAVI, KC_SPC, KC_SPC, LA_NAVI,  LA_OSM,  KC_RALT, LA_FUNC, KC_RCTL
),

/* KayNeo: Symbols
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |   ^  |   °  |   :  |   [  |   ]  |   $  |   !  |   <  |   >  |   =  |   &  |      |
 * |      |   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   +  |      |
 * |      |   `  |   $  |   |  |   ~  |   #  |   @  |   "  |   '  |   _  |   %  |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMB] = LAYOUT_preonic_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    N_CIRC,  N_DEGRE, N_COLN,  N_LSQBR, N_RSQBR, N_DLR,   N_EXKL,  N_LT,    N_GT,    N_EQ,    N_AMP,   _______,
    _______, N_BSLS,  N_SLSH,  N_LCUBR, N_RCUBR, N_ASTR,  N_QUES,  N_LPARN, N_RPARN, N_MINS,  N_PLUS,  _______,
    _______, N_GRAVE, N_DLR,   N_PIPE,  N_TILD,  N_HASH,  N_AT,    N_QUOT,  N_SING,  N_USC,   N_PERC,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* KayNeo: Navigation
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * | NUML |      | PGUP |  UP  | PGDN |      |   /  |   7  |   8  |   9  |   -  | DEL  |
 * |      | HOME | LEFT | DOWN | RGHT | END  |   *  |   4  |   5  |   6  |   +  |      |
 * |      | UNDO | CUT  | COPY | PSTE | APP  |   0  |   1  |   2  |   3  |   .  |      |
 * |      |      |      |      |      |      |      |      |   0  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAVI] = LAYOUT_preonic_grid_wrapper(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_F9,   KC_F10,   KC_DEL,
    KC_NLCK, _______, KC_PGUP, KC_UP,   KC_PGDN,  _______, DE_SLSH, DE_7,    DE_8,  DE_9,    DE_MINS,  _______,
    _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,  DE_ASTR, DE_4,    DE_5,  DE_6,    DE_PLUS,  _______,
    _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE, KC_APP,  DE_0,    DE_1,    DE_2,  DE_3,    DE_DOT,   _______,
    _______, _______, _______, _______, _______,  _______, _______, _______, DE_0,  _______, _______,  _______
),

/* KayNeo: Programming (NAVI + SYMB) shortcuts/macros
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |  +=  |  :=  |  -=  | DEL  |
 * |      |      |      |      |  ${} | go{} |      |      |  $() |      |      |      |
 * |      |      |      |      |      |  ~/  |  ./  |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PRG] = LAYOUT_preonic_grid_wrapper(
    _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
    _______, _______, COLCOM,  _______, _______,  _______, _______, _______, PLUSEQ,  COLEQ,   MINUSEQ, KC_DEL,
    _______, _______, _______, SHVAR,   GOCUBR,   _______, _______, SHCMD,   _______, _______, _______, _______,
    _______, _______, _______, _______, HOMESLSH, CWDTAB,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______
),

/* KayNeo: language specific shortcuts
 */
[_LANG] = LAYOUT_preonic_grid_wrapper(
    _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, N_UNIDOT, N_AE,    _______, _______, N_PARA,  _______, _______, N_NEQ,   N_MU,    KC_DEL,
    _______, N_HBULL, N_OE,     N_EURO,  _______, N_UE,    N_IRONY, N_TBULL, _______, N_EMDSH, N_SS,    _______,
    _______, _______, _______,  N_EAC,   _______, _______, N_CROSS, N_YESNO, _______, _______, DE_COMM, _______,
    _______, _______, _______,  _______, _______, _______, N_VSPC,  _______, N_ARRLF, N_ARRDN, N_ARRUP, N_ARRRT
),

/* KayNeo: function keys
 */
[_FUNC] = LAYOUT_preonic_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_INS,
    _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
    _______, KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_FN25, KC_FN26, KC_FN27, KC_FN28, KC_FN29, KC_FN30, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* KayNeo: user space one shot home row mods
 */
[_OSM] = LAYOUT_preonic_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, _______, _______, OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  _______,
    _______, _______, _______, OS_HYPR, OS_MEH,  _______, _______, OS_MEH,  OS_HYPR, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* KayNeo: Adjust (NAVI + LANG)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|KayNeo|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|UCMod |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid_wrapper(
    _______, KB_VRSN, KB_MAKE, _______, _______,  _______, _______, _______, _______, _______, _______, KC_DEL,
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  KAYNEO,   _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, UC_MOD,  UC_M_LN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};


/* user space one shot home row mods based on
   - users/callum
   - https://precondition.github.io/home-row-mods
*/

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_OSM:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_OSM:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
    case OS_MEH:
    case OS_HYPR:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;
oneshot_state os_meh_state = os_up_unqueued;
oneshot_state os_hypr_state = os_up_unqueued;

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _NAVI, _LANG, _ADJUST);
  state = update_tri_layer_state(state, _SYMB, _NAVI, _PRG);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );
    update_oneshot(
        &os_meh_state, KC_MEH, OS_MEH,
        keycode, record
    );
    update_oneshot(
        &os_hypr_state, KC_HYPR, OS_HYPR,
        keycode, record
    );



  switch (keycode) {
    case COLEQ:
      if (record->event.pressed) {
          SEND_STRING(":=");
      }
      return false;
    case MINUSEQ:
      if (record->event.pressed) {
          SEND_STRING("-=");
      }
      return false;
    case PLUSEQ:
      if (record->event.pressed) {
          SEND_STRING("+=");
      }
      return false;
    case HOMESLSH:
      if (record->event.pressed) {
          SEND_STRING("~/");
      }
      return false;
    case CWDTAB:
      if (record->event.pressed) {
          SEND_STRING("./" SS_TAP(X_TAB));
      }
      return false;
    case SHCMD:
      if (record->event.pressed) {
          SEND_STRING("$()" SS_TAP(X_LEFT));
      }
      return false;
    case SHVAR:
      if (record->event.pressed) {
          SEND_STRING("${}" SS_TAP(X_LEFT));
      }
      return false;
    case COLCOM:
      if (record->event.pressed) {
          SEND_STRING(": ," SS_TAP(X_LEFT));
      }
      return false;
    case GOCUBR:
      if (record->event.pressed) {
          SEND_STRING("{}" SS_TAP(X_LEFT) SS_TAP(X_ENTER) SS_TAP(X_TAB) SS_TAP(X_ENTER) SS_TAP(X_UP) SS_TAP(X_END));
      }
      return false;
    case KB_MAKE:
      if (!record->event.pressed) {
        SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP SS_TAP(X_ENTER));
      }
      return false;
      break;

    case KB_VRSN:
      if (!record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;

    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case KAYNEO:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_KAYNEO);
      }
      return false;
    default:
      return true;
  }
}

