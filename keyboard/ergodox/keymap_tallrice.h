#include "action_util.h"
#include "action_layer.h"
#define KC_SW0 KC_FN0
#define DEBUG_ACTION

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // KM0: BASE
    KEYMAP(
            LBRC,   1,      2,      3,      4,      5,      RBRC,
            EQL,    Q,      W,      D,      F,      J,      ESC,
            FN17,   A,      S,      E,      T,      G,
            FN16,   Z,      X,      C,      V,      B,      DEL,
            GRV,    FN11,   FN12,   FN13,   FN14,
                                                    FN27,   LBRC,
                                                            RBRC,
                                            FN21,   FN20,   FN18,
                                                                    SPC,    6,      7,      8,      9,      0,      BSPC,
                                                                    LBRC,   K,      U,      H,      L,      SCLN,   GRV,
                                                                            Y,      N,      I,      O,      R,      QUOT,
                                                                    RBRC,   P,      M,      COMM,   DOT,    SLSH,   BSLS,
                                                                                    FN15,   LEFT,   DOWN,   UP,     RGHT,
                                                                    CALC,   PAUS,
                                                                    LALT,
                                                                    APP,    FN19,   FN22
          ),
    // KM1: NUMBERS/SYMBOLS/FUNCTIONS
    KEYMAP(
            TRNS,   F1,     F2,     F3,     F4,     F5,     TRNS,
            TRNS,   FN1,    FN2,    FN3,    FN4,    FN5,    TRNS,
            TRNS,   1,      2,      3,      4,      5,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
                                                    TRNS,   TRNS,
                                                            TRNS,
                                            TRNS,   TRNS,   TRNS,
                                                                    FN0,    F6,     F7,     F8,     F9,     F10,    TRNS,
                                                                    TRNS,   FN6,    FN7,    FN8,    FN9,    FN10,   TRNS,
                                                                            6,      7,      8,      9,      0,      TRNS,
                                                                    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
                                                                                    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,

                                                                    TRNS,   TRNS,
                                                                    TRNS,
                                                                    TRNS,   TRNS,   TRNS
          ),
          // KM2: ARROWS, FUNCTIONS, VIM OPTIMIZED
    KEYMAP(
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
            TRNS,   F1,     F2,     F3,     F4,     F5,     TRNS,
            TRNS,   HOME,   TRNS,   FN25,   FN26,   TRNS,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,

                                                    TRNS,   TRNS,
                                                            TRNS,
                                            TRNS,   TRNS,   TRNS,
                                                                    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
                                                                    TRNS,   F6,     F7,     F8,     F9,     F10,    TRNS,
                                                                            LEFT,   DOWN,   UP,     RGHT,   END,    TRNS,
                                                                    TRNS,   TRNS,   WH_D,   WH_U,   TRNS,   TRNS,   TRNS,
                                                                                    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,

                                                                    TRNS,   TRNS,
                                                                    TRNS,
                                                                    TRNS,   TRNS,   TRNS
          ),
          // KM3: LEFT ARROWS, FUNCTIONS, Tap TAB
    KEYMAP(
            TRNS,   F11,    F12,    F13,    F14,    F15,    TRNS,
            TRNS,   F1,     UP,     F3,     F4,     F5,     TRNS,
            TRNS,   LEFT,   DOWN,   RGHT,   F11,    F2,
            TRNS,   F10,    F9,     F8,     F7,     F6,     TRNS,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,

                                                    TRNS,   TRNS,
                                                            TRNS,
                                            TRNS,   TRNS,   TRNS,
                                                                    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
                                                                    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
                                                                            MS_L,   MS_D,   MS_U,   MS_R,   BTN1,   TRNS,
                                                                    TRNS,   TRNS,   WH_D,   WH_U,   TRNS,   TRNS,   TRNS,
                                                                                    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,

                                                                    TRNS,   TRNS,
                                                                    TRNS,
                                                                    ACL0,   ACL1,   ACL2
          ),
    // KM4: LEFT HAND MIRROR, RIGHT NUMERIC KEYPAD
    KEYMAP(
            GRV,    0,      9,      8,      7,      6,     TRNS,
            GRV,    SCLN,   L,      H,      U,      K,     TRNS,
            QUOT,   R,      O,      I,      N,      Y,          
            BSLS,   SLSH,   DOT,    COMM,   M,      P,     TRNS,
            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,             

                                                    TRNS,  TRNS,
                                                           TRNS,
                                            SPC,    TRNS,  TRNS,
                                                                    NLCK,   TRNS,   NLCK,   PSLS,   PAST,   PEQL,   TRNS,
                                                                    CAPS,   TRNS,   P7,     P8,     P9,     PMNS,   TRNS,
                                                                            TRNS,   P4,     P5,     P6,     PPLS,   TRNS,
                                                                    SLCK,   TRNS,   P1,     P2,     P3,     PENT,   TRNS,
                                                                                    P0,     TRNS,   PDOT,   PENT,   TRNS,

                                                                    SLEP,   PWR,
                                                                    TRNS,
                                                                    BTN3,   BTN2,   BTN1
          ),
};

//Macro IDs
enum macro_id {
    GUI_GR,
    GUI_TAB,
    HELLO,
    VOLUP,
    CTL_GUI_DEL,
    CTL_Y,
    MAC_SLEEP,
    MAC_SHUTDOWN,
    OPEN,
    CLOSE,
    INSERT,
    DELETE,
    RENAME,
    ACROBAT,
    IASUP,
    IASDOWN,
    IASRGHT,
    IASLEFT,
    CTRLLEFT,
    CTRLRGHT,
    NEWTERM,
};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {

    // TEENSY KEY
    ACTION_FUNCTION(TEENSY_KEY),                    // FN0 - Teensy key

    // SYMBOLS
    ACTION_MODS_KEY(MOD_LSFT, KC_1),                // FN1 - !
    ACTION_MODS_KEY(MOD_LSFT, KC_2),                // FN2 - @
    ACTION_MODS_KEY(MOD_LSFT, KC_3),                // FN3 - #
    ACTION_MODS_KEY(MOD_LSFT, KC_4),                // FN4 - $
    ACTION_MODS_KEY(MOD_LSFT, KC_5),                // FN5 - %
    ACTION_MODS_KEY(MOD_LSFT, KC_6),                // FN6 - ^
    ACTION_MODS_KEY(MOD_LSFT, KC_7),                // FN7 - &
    ACTION_MODS_KEY(MOD_LSFT, KC_8),                // FN8 - *
    ACTION_MODS_KEY(MOD_LSFT, KC_9),                // FN9 - (
    ACTION_MODS_KEY(MOD_LSFT, KC_0),                // FN10 - )

    // LOWER ROW
    ACTION_MODS_TAP_KEY(MOD_LSFT, KC_HOME),         // FN11 - LSFT with tap Home
    ACTION_MODS_TAP_KEY(MOD_LCTL, KC_END),          // FN12 - LCTL with tap End
    ACTION_MODS_TAP_KEY(MOD_LALT, KC_PGUP),         // FN13 - LALT with tap PgUp
    ACTION_MODS_TAP_KEY(MOD_LGUI, KC_PGDN),         // FN14 - LGUI with tap PgDn
    ACTION_MODS_TAP_KEY(MOD_LGUI, KC_ESC),          // FN15 - LGUI   with tap Esc
    ACTION_MODS_TAP_KEY(MOD_LALT, KC_MINS),         // FN16 - LALT with tap Minus
    ACTION_LAYER_TAP_KEY(3, KC_TAB),                // FN17 - KM3 (INVERTED T) with tap Tabj

    // THUMB CLUSTERS
    ACTION_LAYER_MOMENTARY(4),                      // FN18 - KM4 (MIRROR)
    ACTION_LAYER_MOMENTARY(1),                      // FN19 - KM1 (NUMBERS)
    ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ENT),          // FN20 - LCTL   with tap Enter
    ACTION_MODS_TAP_KEY(MOD_LSFT, KC_BSPC),         // FN21 - LSHIFT with tap BackSpace
    ACTION_LAYER_TAP_KEY(2, KC_SPC),                // FN22 - KM2 (Right Arrows, Left IAS) with tap Space

    // MACROS
    ACTION_MACRO(CLOSE),                            // FN23 - CLOSE
    ACTION_MACRO(ACROBAT),                          // FN24 - SET ACROBAT VIEWING OPTIONS
    ACTION_MACRO(IASUP),                            // FN25 - 20 UP THEN 1 DOWN
    ACTION_MACRO(IASDOWN),                          // FN26 - 20 DN THEN 1 UP
    ACTION_MACRO(NEWTERM),                          // FN27 - New Terminal at Folder
    ACTION_MACRO(RENAME),                           // FN28 - RENAME
    ACTION_MACRO(CTL_Y),                            // FN29 - CTRL+Y
    ACTION_LAYER_SET(0, ON_PRESS),                  // FN30 - KM0 Set - BASE LAYER
    ACTION_MODS_ONESHOT(MOD_LSFT),                  // FN31 - Oneshot Shift

};

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case GUI_GR:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(LGUI), END ) :
                    MACRO( U(LCTL), U(LGUI), T(ESC), END ));
        case GUI_TAB:
            return (record->event.pressed ?
                    MACRO( D(LGUI), T(TAB), END ) :
                    MACRO( T(LGUI), END ));
        case HELLO:
            return (record->event.pressed ?
                    MACRO( I(0), T(H), T(E), T(L), T(L), W(255), T(O), END ) :
                    MACRO_NONE );
        case VOLUP:
            return (record->event.pressed ?
                    MACRO( D(VOLU), U(VOLU), END ) :
                    MACRO_NONE );
        case CTL_GUI_DEL:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(LGUI), T(DEL), END ) :
                    MACRO( U(LGUI), U(LCTL), END ));
        case CTL_Y:
            return (record->event.pressed ?
                    MACRO( D(LCTL), T(Y), U(LCTL), END ) :
                    MACRO_NONE );
        case MAC_SLEEP:
            return (record->event.pressed ?
                    MACRO( D(LALT), D(LGUI), D(F12), END ) :
                    MACRO_NONE );
        case MAC_SHUTDOWN:
            return (record->event.pressed ?
                    MACRO( D(LALT), D(LGUI), D(LCTL), D(F12), END ) :
                    MACRO_NONE );
        case OPEN:
            return (record->event.pressed ?
                    MACRO( D(LCTL), T(O), END ) :
                    MACRO( U(LCTL), T(ESC), END ));
        case CLOSE:
            return (record->event.pressed ?
                    MACRO( D(LGUI), T(F4), U(LGUI), T(ESC), END ) :
                    MACRO_NONE );
                    /* MACRO( U(LGUI), END )); */
                    /* MACRO( D(LGUI), D(F4), END ) : */
                    /* MACRO( U(LGUI), U(F4), END )); */
        case INSERT:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(LSFT), T(EQL), U(LSFT), U(LCTL), END ) :
                    MACRO_NONE);
        case DELETE:
            return (record->event.pressed ?
                    MACRO( D(LCTL), T(MINS), U(LCTL), END ) :
                    MACRO_NONE);
        case RENAME:
            return (record->event.pressed ?
                    MACRO( T(F2), T(LEFT), T(RGHT), END ) :
                    MACRO_NONE);
        case ACROBAT:
            return (record->event.pressed ?
                    MACRO( D(LGUI), T(V), U(LGUI), T(Z), T(H), W(255), END ) :
                    MACRO( D(LGUI), T(V), U(LGUI), T(P), T(S), END ));
                    /* MACRO_NONE); */
        case IASUP:
            return (record->event.pressed ?
                    MACRO( T(UP), T(UP), T(UP), T(UP), T(UP), T(UP), T(UP), T(UP), T(UP), T(UP), T(UP), END ) :
                    MACRO( T(UP), T(UP), T(UP), T(UP), T(UP), T(UP), T(UP), T(UP), T(UP), T(UP), T(DOWN), END ));
        case IASDOWN:
            return (record->event.pressed ?
                    MACRO( T(DOWN), T(DOWN), T(DOWN), T(DOWN), T(DOWN), T(DOWN), T(DOWN), T(DOWN), T(DOWN), T(DOWN), T(DOWN), END ) :
                    MACRO( T(DOWN), T(DOWN), T(DOWN), T(DOWN), T(DOWN), T(DOWN), T(DOWN), T(DOWN), T(DOWN), T(DOWN), T(UP), END ));
        case IASRGHT:
            return (record->event.pressed ?
                    MACRO( T(RGHT), T(RGHT), T(RGHT), T(RGHT), T(RGHT), T(RGHT), T(RGHT), T(RGHT), T(RGHT), T(RGHT), END ) :
                    MACRO( T(RGHT), T(RGHT), T(RGHT), T(RGHT), T(RGHT), T(RGHT), T(RGHT), T(RGHT), T(RGHT), T(RGHT), END ));
                    /* MACRO_NONE); */
        case IASLEFT:
            return (record->event.pressed ?
                    MACRO( T(LEFT), T(LEFT), T(LEFT), T(LEFT), T(LEFT), T(LEFT), T(LEFT), T(LEFT), T(LEFT), T(LEFT), END ) :
                    MACRO( T(LEFT), T(LEFT), T(LEFT), T(LEFT), T(LEFT), T(LEFT), T(LEFT), T(LEFT), T(LEFT), T(LEFT), END ));
                    /* MACRO_NONE); */
        case CTRLLEFT:
            return (record->event.pressed ?
                    MACRO( D(LCTL), T(LEFT), U(LCTL), END ) :
                    MACRO_NONE);
        case CTRLRGHT:
            return (record->event.pressed ?
                    MACRO( D(LCTL), T(RGHT), U(LCTL), END ) :
                    MACRO_NONE);
        case NEWTERM:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(LALT), D(LGUI), T(N), END) :
                    /* MACRO_NONE); */
                    MACRO( U(LCTL), U(LALT), U(LGUI), END ));
    }
    return MACRO_NONE;
}

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
