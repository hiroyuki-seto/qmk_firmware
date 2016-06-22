// modified following file.
// https://github.com/msc654/qmk_firmware/blob/master/keyboard%2Fergodox_ez%2Fkeymaps%2Fdefault%2Fkeymap.c

#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define OSX     0  // default layer (for OSX)
#define FN      1  // functions

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: OS X layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  |  ¥   |           |   6  |   7  |   8  |   9  |   0  |   -  |   ^    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  NO  |           | DELT |   Y  |   U  |   I  |   O  |   P  |   @    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CTRL   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   :    |
 * |--------+------+------+------+------+------|  NO  |           | BSPC |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   _    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LGui |  ALT |  UP  | DOWN | MHEN |                                       | KANA | LEFT | RIGHT|   [  |   ]  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LGui | ESC  |       |  NO  |  NO  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  FN  |       | PGUP |        |      |
 *                                 |  SPC | BSPC |------|       |------|  ENT   | SPC  |
 *                                 |      |      |  FN  |       | PGDN |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[OSX] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,        KC_3,      KC_4,   KC_5,   KC_JYEN,
        KC_TAB,         KC_Q,         KC_W,        KC_E,      KC_R,   KC_T,   KC_NO,
        KC_LCTL,        KC_A,         KC_S,        KC_D,      KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,        KC_C,      KC_V,   KC_B,   KC_NO,
        KC_LGUI,        KC_LALT,      KC_UP,       KC_DOWN,   KC_MHEN,
                                                               KC_LGUI,       KC_ESC,
                                                                              TG(FN),
                                                               KC_SPC,KC_BSPC,MO(FN),
        // right hand
             KC_6,        KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,          KC_EQL,
             KC_DELT,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_LBRC,
                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
             KC_BSPC,     KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RO,
                                  KC_KANA,KC_LEFT,KC_RIGHT,KC_RBRC,         KC_BSLS,
             KC_NO,       KC_NO,
             KC_PGUP,
             KC_PGDN,KC_ENT,KC_SPC
    ),

/* Keymap 1: Function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           | F6   | F7   |  F8  |  F9  | F10  |  F11 |  F12   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | M-Up |      |      |      |      |           |      |      |  7   |  8   |  9   |  /   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  M-L | M-Dn | M-R  |      |      |------|           |------|      |  4   |  5   |  6   |  *   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  1   |  2   |  3   |  -   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      | PGUP | PGDN |      |                                       |  0   |  0   |  .   |  +   |  =   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | RESET|       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  FN  |       |      |      |      |
 *                                 |      |      |------|       |------|RClick|LClick|
 *                                 |      |      |  FN  |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Fnctions
[FN] = KEYMAP(
       // left hand
       KC_TRNS,     KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS,     KC_TRNS,    KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_MS_L,    KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_TRNS,    KC_PGUP, KC_PGDN, KC_TRNS,
                                                            KC_TRNS, RESET,
                                                                     TG(OSX),
                                                   KC_TRNS, KC_TRNS, MO(OSX),
       // right hand
       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,
       KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,     KC_SLSH, KC_TRNS,
                KC_TRNS, KC_4,    KC_5,    KC_6,     S(KC_QUOT), KC_TRNS,
       KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,     KC_MINUS,KC_TRNS,
                KC_0,    KC_0,    KC_DOT,  S(KC_SCLN),S(KC_MINS),
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_BTN1, KC_BTN2
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(FN)                // FN1 - Momentary Layer 1 (functions)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id) {
        case 0:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            break;
    }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    ergodox_board_led_off();
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    ergodox_board_led_off();
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    ergodox_board_led_off();    
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case OSX:
            ergodox_right_led_1_on();
            break;
        case FN:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
