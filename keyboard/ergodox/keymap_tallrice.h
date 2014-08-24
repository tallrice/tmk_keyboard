#include "action_util.h"
#include "action_layer.h"
#define KC_SW0 KC_FN0
#define DEBUG_ACTION

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Keymap 0: Based on Norman (https://normanlayout.info) with R&H and J&K swapped, etc.
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * | Enter  |   1  |   2  |   3  |   4  |   5  |PScrn |           |PausBk|   6  |   7  |   8  |   9  |   0  |   =    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   D  |   F  |   J  | Del  |           |  L6: |   K  |   U  |   H  |   L  |   ;  |   -    |
     * |--------+------+------+------+------+------|      |           |  FN8 |------+------+------+------+------+--------|
     * |   `    |   A  |   S  |   E  |   T  |   G  |------|           |------|   Y  |   N  |   I  |   O  |   R  |   '    |
     * |--------+------+------+------+------+------|  [   |           |   ]  |------+------+------+------+------+--------|
     * |   \    |   Z  |   X  |   C  |   V  |   B  |      |           |      |   P  |   M  |   ,  |   .  |   :  |   /    |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      | LGui/| LAlt/|                                       | RGui/|      |      |      |      |
     *   | Left | Right|  Up  | Down:| Home:|                                       |  End:| Down |  Up  | Left | Right|
     *   |      |      |      | FN21 |  FN22|                                       |  FN23|      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                        | Tab  | Space|       |  F11 |  F12 |
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      | PgUp |       | RAlt |      |      |
     *                                 |LShft/|LCtrl/|      |       |      |  L1/ |      |
     *                                 |Bkspc:| Esc: |------|       |------|Enter:|Space |
     *                                 | FN24 | FN25 | L2/  |       |RCtrl/| FN28 |      |
     *                                 |      |      | PgDn:|       | Esc: |      |      |
     *                                 |      |      | FN26 |       | FN27 |      |      |
     *                                 `--------------------'       `--------------------'
     */

    // KM0: BASE, WINDOWS-OPTIMIZED
    KEYMAP(
            ENT,    1,      2,      3,      4,      5,     PSCR,
            TAB,    Q,      W,      D,      F,      J,      DEL,
            GRV,    A,      S,      E,      T,      G,
            BSLS,   Z,      X,      C,      V,      B,      LBRC,
            LEFT,   RIGHT,  UP,     FN29,   FN30,

                                                    TAB,     SPC,
                                                            PGUP,
                                            FN24,   FN25,   FN26,
                                                                   PAUS,    6,      7,      8,      9,      0,      EQL,
                                                                    FN8,    K,      U,      H,      L,      SCLN,   MINS,
                                                                            Y,      N,      I,      O,      R,      QUOT,
                                                                    RBRC,   P,      M,      COMM,   DOT,    FN10,   SLSH,
                                                                                    FN31,   DOWN,   UP,     LEFT,   RGHT,

                                                                     F11,    F12,
                                                                    RALT,
                                                                    FN27,   FN28,    SPC
          ),
    // KM1: FUNCTIONS/SYMBOLS/NUMBERS
    KEYMAP(
            TRNS,   F1,     F2,     F3,     F4,     F5,     TRNS,
            TRNS,   FN11,   FN12,   FN13,   FN14,   FN15,   TRNS,
            TRNS,   1,      2,      3,      4,      5, 
            TRNS,   F11,    F12,    LEFT,  RIGHT,   TRNS,   TRNS,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,

                                                    TRNS,   TRNS,
                                                            TRNS,
                                            TRNS,   TRNS,   TRNS,
                                                                    TRNS,   F6,     F7,     F8,     F9,     F10,    TRNS,
                                                                    TRNS,   FN16,   FN17,   FN18,   FN19,   FN20,   TRNS,
                                                                            6,      7,      8,      9,      0,      TRNS,
                                                                    TRNS,   TRNS,   DOWN,     UP,   TRNS,   TRNS,   TRNS,
                                                                                    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,

                                                                    TRNS,   TRNS,
                                                                    TRNS,
                                                                    TRNS,   TRNS,   TRNS
          ),
    // KM2: RIGHT HAND MOUSE/LEFT HAND MIRROR
    KEYMAP(
            EQL,    0,      9,      8,      7,      6,     PAUS,
            MINS,   SCLN,   L,      H,      U,      K,      FN8,
            QUOT,   R,      O,      I,      N,      Y,          
            SLSH,   FN10,   DOT,    COMM,   M,      P,     RBRC,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,             

                                                    TRNS,   TRNS,
                                                            TRNS,
                                            TRNS,   TRNS,   TRNS,
                                                                    ACL0,   NO,     NO,     NO,     NO,     NO,     NO,
                                                                    ACL1,   NO,     WH_D,   WH_U,   NO,     NO,     NO,
                                                                            MS_L,   MS_D,   MS_U,   MS_R,   NO,     NO,
                                                                    ACL2,   NO,     BTN1,   BTN2,   BTN3,   NO,     NO,
                                                                                    BTN4,   BTN5,   NO,     NO,     NO,

                                                                    TRNS,   TRNS,
                                                                    TRNS,
                                                                    TRNS,   TRNS,   TRNS
          ),

    // KM3: NUMBERS SHIFTED TO SYMBOLS
    KEYMAP(
            TRNS,   FN11,   FN12,   FN13,   FN14,   FN15,   TRNS,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,

                                                    TRNS,   TRNS,
                                                            TRNS,
                                            TRNS,   TRNS,   TRNS,
                                                                    TRNS,   FN16,   FN17,   FN18,   FN19,   FN20,   TRNS,
                                                                    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
                                                                            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
                                                                    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
                                                                                    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,

                                                                    TRNS,   TRNS,
                                                                    TRNS,
                                                                    TRNS,   TRNS, TRNS
          ),
     // KM4: CONTROL CHARACTERS CHANGED TO MAC-OPTIMIZED (GUI&ALT SWAPPED)
    KEYMAP(
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
            TRNS,   TRNS,   TRNS,   FN21,   FN22,

                                                    TRNS,   TRNS,
                                                            TRNS,
                                            TRNS,   TRNS,   TRNS,
                                                                    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
                                                                    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
                                                                            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
                                                                    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
                                                                                    FN23,   TRNS,   TRNS,   TRNS,   TRNS,

                                                                    TRNS,   TRNS,
                                                                    RGUI,
                                                                    TRNS,   TRNS, TRNS   
          ),
     // KM5: QWERTY CHANGES FROM NORMAN
    KEYMAP(
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
            TRNS,   TRNS,   TRNS,   E,      R,      T,      TRNS,
            TRNS,   TRNS,   TRNS,   D,      F,      TRNS,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,

                                                    TRNS,   TRNS,
                                                            TRNS,
                                            TRNS,   TRNS,   TRNS,
                                                                    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
                                                                    TRNS,   Y,      TRNS,   I,      O,      P,      TRNS,
                                                                            H,      J,      K,      L,      SCLN,   TRNS,
                                                                    TRNS,   N,      TRNS,   TRNS,   TRNS,   SLSH,   TRNS,
                                                                                    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,

                                                                    TRNS,   TRNS,
                                                                    TRNS,
                                                                    TRNS,   TRNS, TRNS   
          ),
     // KM6: LAYER ACCESS
    KEYMAP(
            TRNS,   FN1,    FN2,    FN3,    FN4,    FN5,    TRNS,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,

                                                    TRNS,   TRNS,
                                                            TRNS,
                                            TRNS,   TRNS,   TRNS,
                                                                    FN9,    TRNS,   TRNS,   TRNS,   TRNS,    FN0,   TRNS,
                                                                    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
                                                                            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
                                                                    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
                                                                                    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,

                                                                    TRNS,   TRNS,
                                                                    TRNS,
                                                                    TRNS,   TRNS,   TRNS
          ),


};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    // LAYERS
    ACTION_LAYER_SET(0, ON_BOTH),                   // FN0 - Set L0
    ACTION_LAYER_SET(1, ON_BOTH),                   // FN1 - Set L1
    ACTION_LAYER_SET(2, ON_BOTH),                   // FN2 - Set L2
    ACTION_LAYER_SET(3, ON_BOTH),                   // FN3 - Set L3
    ACTION_LAYER_SET(4, ON_BOTH),                   // FN4 - Set L4
    ACTION_LAYER_SET(5, ON_BOTH),                   // FN5 - Set L5
    ACTION_LAYER_MOMENTARY(1),                      // FN6 - Momentary L1
    ACTION_LAYER_MOMENTARY(2),                      // FN7 - Momentary L2
    ACTION_LAYER_MOMENTARY(6),                      // FN8 - Momentary L6
    ACTION_FUNCTION(TEENSY_KEY),                    // FN9 - Teensy key


    // SYMBOLS
    ACTION_MODS_KEY(MOD_LSFT, KC_SCLN),             // FN10 - :
    ACTION_MODS_KEY(MOD_LSFT, KC_1),                // FN11 - !
    ACTION_MODS_KEY(MOD_LSFT, KC_2),                // FN12 - @
    ACTION_MODS_KEY(MOD_LSFT, KC_3),                // FN13 - #
    ACTION_MODS_KEY(MOD_LSFT, KC_4),                // FN14 - $
    ACTION_MODS_KEY(MOD_LSFT, KC_5),                // FN15 - %
    ACTION_MODS_KEY(MOD_LSFT, KC_6),                // FN16 - ^
    ACTION_MODS_KEY(MOD_LSFT, KC_7),                // FN17 - &
    ACTION_MODS_KEY(MOD_LSFT, KC_8),                // FN18 - *
    ACTION_MODS_KEY(MOD_LSFT, KC_9),                // FN19 - (
    ACTION_MODS_KEY(MOD_LSFT, KC_0),                // FN20 - )

    // TAP FUNCTIONS
    ACTION_MODS_TAP_KEY(MOD_LALT, KC_DOWN),         // FN21  = LALT   with tap Down
    ACTION_MODS_TAP_KEY(MOD_LGUI, KC_HOME),         // FN21  = LGUI   with tap Home
    ACTION_MODS_TAP_KEY(MOD_RALT, KC_END),          // FN23  = RALT   with tap End
    ACTION_MODS_TAP_KEY(MOD_LSFT, KC_BSPC),         // FN24  = LSHIFT with tap BackSpace
    ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),          // FN25  = LCTL   with tap Escape
    ACTION_LAYER_TAP_KEY(2, KC_PGDN),               // FN26  = L2     with tap PageDown
    ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ESC),          // FN27  = RCTL   with tap Escape
    ACTION_LAYER_TAP_KEY(1, KC_ENT),                // FN28  = L1     with tap Enter 
    ACTION_MODS_TAP_KEY(MOD_LGUI, KC_DOWN),         // FN29  = LGUI   with tap Down
    ACTION_MODS_TAP_KEY(MOD_LALT, KC_HOME),         // FN30  = LAlt   with tap Home
    ACTION_MODS_TAP_KEY(MOD_RGUI, KC_END),          // FN31  = RGui   with tap End

};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    print("action_function called\n");
    print("id  = "); phex(id); print("\n");
    print("opt = "); phex(opt); print("\n");
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}
