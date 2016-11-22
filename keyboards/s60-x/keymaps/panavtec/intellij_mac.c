#include "intellij_mac.h"

uint8_t alt_pressed_mask() { 
    return (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT));
}

uint8_t ctl_pressed_mask() { 
    return (MOD_BIT(KC_LCTRL)|MOD_BIT(KC_RCTRL));
}

uint8_t sft_pressed_mask() { 
    return (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT));
}

void replace_mod(keyrecord_t *record, uint8_t key, uint8_t mod, uint8_t replace) {
    if (record->event.pressed) {
        add_key(key);
        uint8_t is_mod_pressed = get_mods()&mod;
        if (is_mod_pressed) {
            del_mods(is_mod_pressed);
            add_mods(replace);
        }
    } else {
        del_mods(replace);
        del_key(key);
    }
}

void replace_key(keyrecord_t *record, uint8_t mod, uint8_t key, uint8_t replace) {
    if (record->event.pressed && get_mods()&mod) {
        del_key(key);
        add_key(replace);
    } else {
        del_key(replace);
    }
}

void process_intellij_binding(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) { 
        case INTELLIJ_E  : replace_mod(record, KC_E, ctl_pressed_mask(), MOD_BIT(KC_LGUI)); break;
        case INTELLIJ_1  : replace_mod(record, KC_1, alt_pressed_mask(), MOD_BIT(KC_LGUI)); break;
        case INTELLIJ_2  : replace_mod(record, KC_2, alt_pressed_mask(), MOD_BIT(KC_LGUI)); break;
        case INTELLIJ_3  : replace_mod(record, KC_3, alt_pressed_mask(), MOD_BIT(KC_LGUI)); break;
        case INTELLIJ_4  : replace_mod(record, KC_4, alt_pressed_mask(), MOD_BIT(KC_LGUI)); break;
        case INTELLIJ_5  : replace_mod(record, KC_5, alt_pressed_mask(), MOD_BIT(KC_LGUI)); break;
        case INTELLIJ_6  : replace_mod(record, KC_6, alt_pressed_mask(), MOD_BIT(KC_LGUI)); break;
        case INTELLIJ_7  : replace_mod(record, KC_7, alt_pressed_mask(), MOD_BIT(KC_LGUI)); break;
        case INTELLIJ_8  : replace_mod(record, KC_8, alt_pressed_mask(), MOD_BIT(KC_LGUI)); break;
        case INTELLIJ_9  : replace_mod(record, KC_9, alt_pressed_mask(), MOD_BIT(KC_LGUI)); break;
        case INTELLIJ_0  : replace_mod(record, KC_0, alt_pressed_mask(), MOD_BIT(KC_LGUI)); break;
        case INTELLIJ_A  : replace_mod(record, KC_A, sft_pressed_mask()|ctl_pressed_mask(), MOD_BIT(KC_LSFT)|MOD_BIT(KC_LGUI)); break;
        case INTELLIJ_J:
            replace_key(record, alt_pressed_mask(), KC_J, KC_G);
            replace_mod(record, KC_G, alt_pressed_mask(), MOD_BIT(KC_LCTL)); 
            break;
        case INTELLIJ_T  :
            replace_mod(record, KC_T, ctl_pressed_mask()|alt_pressed_mask()|sft_pressed_mask(), MOD_BIT(KC_LGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_LSFT)); 
            replace_mod(record, KC_T, ctl_pressed_mask()|alt_pressed_mask(), MOD_BIT(KC_LGUI)|MOD_BIT(KC_LALT)); 
            break;
        case INTELLIJ_INS:
            if (get_mods()&sft_pressed_mask()) {
                replace_key(record, sft_pressed_mask()|alt_pressed_mask(), KC_INS, KC_8);
                replace_mod(record, KC_8, sft_pressed_mask()|alt_pressed_mask(), MOD_BIT(KC_LGUI)|MOD_BIT(KC_LSFT)); 
            } else if (get_mods()&ctl_pressed_mask()) {
                replace_key(record, ctl_pressed_mask()|alt_pressed_mask(), KC_INS, KC_N);
                replace_mod(record, KC_N, ctl_pressed_mask()|alt_pressed_mask(), MOD_BIT(KC_LCTL));
            } else if (get_mods()&alt_pressed_mask() || get_mods()&MOD_BIT(KC_LGUI)) {
                replace_key(record, alt_pressed_mask(), KC_INS, KC_N);
                replace_mod(record, KC_N, alt_pressed_mask(), MOD_BIT(KC_LGUI));
            }else {
                clear_mods();
                add_key(KC_INS);
            }
            break;
        case INTELLIJ_O  : replace_mod(record, KC_O, ctl_pressed_mask()|alt_pressed_mask(), MOD_BIT(KC_LGUI)|MOD_BIT(KC_LALT)); break;
        case INTELLIJ_L  : replace_mod(record, KC_L, ctl_pressed_mask()|alt_pressed_mask(), MOD_BIT(KC_LGUI)|MOD_BIT(KC_LALT)); break;
        case INTELLIJ_W  :
            if (get_mods()&sft_pressed_mask()) {
                replace_key(record, ctl_pressed_mask()|sft_pressed_mask(), KC_W, KC_DOWN);
                replace_mod(record, KC_DOWN, ctl_pressed_mask(), MOD_BIT(KC_LALT));
            } else {
                replace_key(record, ctl_pressed_mask(), KC_W, KC_UP);
                replace_mod(record, KC_UP, ctl_pressed_mask(), MOD_BIT(KC_LALT));
            }
            break;
        case INTELLIJ_UP   :
            if (get_mods()&ctl_pressed_mask()) { 
                replace_mod(record, KC_UP, ctl_pressed_mask()|sft_pressed_mask(), MOD_BIT(KC_LGUI)|MOD_BIT(KC_LSFT));
            } else {
                if (record->event.pressed) {
                    add_key(KC_UP);
                } else {
                    del_key(KC_UP);
                }
            }
            break;
        case INTELLIJ_DOWN : 
            if (get_mods()&ctl_pressed_mask()) {
                replace_mod(record, KC_DOWN, ctl_pressed_mask()|sft_pressed_mask(), MOD_BIT(KC_LGUI)|MOD_BIT(KC_LSFT));
            } else { 
                if (record->event.pressed) {
                    add_key(KC_DOWN);
                } else {
                    del_key(KC_DOWN);
                }
            } 
            break;
        case INTELLIJ_F12  : replace_mod(record, KC_F12, ctl_pressed_mask(), MOD_BIT(KC_LGUI)); break;
        case INTELLIJ_U    : replace_mod(record, KC_U, ctl_pressed_mask(), MOD_BIT(KC_LGUI)); break;
        case INTELLIJ_B    : replace_mod(record, KC_B, ctl_pressed_mask()|alt_pressed_mask(), MOD_BIT(KC_LGUI)|MOD_BIT(KC_LALT)); break;
        case INTELLIJ_I    : replace_mod(record, KC_I, ctl_pressed_mask()|alt_pressed_mask(), MOD_BIT(KC_LGUI)|MOD_BIT(KC_LALT)); break;
        case INTELLIJ_P    : replace_mod(record, KC_P, ctl_pressed_mask(), MOD_BIT(KC_LGUI)); break;
        case INTELLIJ_F6   : replace_mod(record, KC_F6, ctl_pressed_mask(), MOD_BIT(KC_LGUI)); break;
        case INTELLIJ_V    : 
            if (get_mods()&alt_pressed_mask()) {
                replace_mod(record, KC_V, ctl_pressed_mask()|alt_pressed_mask(), MOD_BIT(KC_LGUI)|MOD_BIT(KC_LALT));
            } else {
                replace_mod(record, KC_V, ctl_pressed_mask(), MOD_BIT(KC_LGUI));
            } 
            break;
        case INTELLIJ_M    : replace_mod(record, KC_M, ctl_pressed_mask()|alt_pressed_mask(), MOD_BIT(KC_LGUI)|MOD_BIT(KC_LALT)); break;
        case INTELLIJ_F    : replace_mod(record, KC_F, ctl_pressed_mask()|alt_pressed_mask(), MOD_BIT(KC_LGUI)|MOD_BIT(KC_LALT)); break;
        case INTELLIJ_C    : 
            if (get_mods()&alt_pressed_mask()) {
                replace_mod(record, KC_C, ctl_pressed_mask()|alt_pressed_mask(), MOD_BIT(KC_LGUI)|MOD_BIT(KC_LALT));
            } else {
                replace_mod(record, KC_C, ctl_pressed_mask(), MOD_BIT(KC_LGUI));
            } 
            break;
        case INTELLIJ_X    :
            if (get_mods()&sft_pressed_mask()) {
                replace_mod(record, KC_X, ctl_pressed_mask()|sft_pressed_mask(), MOD_BIT(KC_LGUI)|MOD_BIT(KC_LSFT));
            } else {
                replace_mod(record, KC_X, ctl_pressed_mask(), MOD_BIT(KC_LGUI));
            } 
            break;
        case INTELLIJ_F8   : replace_mod(record, KC_F8, ctl_pressed_mask(), MOD_BIT(KC_LGUI)); break;
        case INTELLIJ_F9   : 
            if (record->event.pressed) { 
                add_key(KC_R);
                add_mods(MOD_BIT(KC_LGUI)|MOD_BIT(KC_LALT));
            } else { 
                del_key(KC_R);
                del_mods(MOD_BIT(KC_LGUI)|MOD_BIT(KC_LALT));
            }
            break;
        case INTELLIJ_Z    : 
            if (get_mods()&alt_pressed_mask()) {
                replace_mod(record, KC_Z, ctl_pressed_mask()|alt_pressed_mask(), MOD_BIT(KC_LGUI)|MOD_BIT(KC_LALT));
            } else {
                replace_mod(record, KC_Z, ctl_pressed_mask(), MOD_BIT(KC_LGUI));
            } 
            break;
        case INTELLIJ_HOME : 
            if (record->event.pressed) { 
                add_key(KC_LEFT);
                add_mods(MOD_BIT(KC_LGUI));
            } else { 
                del_key(KC_LEFT);
                del_mods(MOD_BIT(KC_LGUI));
            }
            break;
        case INTELLIJ_END : 
            if (record->event.pressed) { 
                add_key(KC_RIGHT);
                add_mods(MOD_BIT(KC_LGUI));
            } else { 
                del_key(KC_RIGHT);
                del_mods(MOD_BIT(KC_LGUI));
            }
            break;
        case INTELLIJ_N  : 
            if (get_mods()&sft_pressed_mask()) {
                replace_mod(record, KC_N, ctl_pressed_mask()|sft_pressed_mask(), MOD_BIT(KC_LGUI)|MOD_BIT(KC_LSFT)); 
            } else {
                replace_mod(record, KC_N, ctl_pressed_mask(), MOD_BIT(KC_LGUI));
            }
            break;
        case BOOTLOADER:
            clear_keyboard();
            print("\n\nJump to bootloader... ");
            _delay_ms(250);
            bootloader_jump(); // should not return
            print("not supported.\n");
         return;
    }

    send_keyboard_report();
}

const macro_t *process_intellij_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;
    //uint8_t tap_count = record->tap_count;

    switch (id) {
        case TESTS_IN_SPLITTER:
            return (event.pressed ?
                        MACRO( D(LCTL), D(LSFT), D(LALT), D(A), // Press unsplit all
                               U(LCTL), U(LSFT), U(LALT), U(A), 
                               W(100),
                               D(LALT), D(RBRC), // split
                               U(LALT), U(RBRC),
                               W(100),
                               D(LCTL), D(LSFT), D(T), // go to test
                               U(LCTL), U(LSFT), U(T),
                               W(100),
                               T(ENT), // confirm 1st test imp.
                               END ) : MACRO( END )
                    );
        case SWITCH_SPLITTER_FILES:
            return (event.pressed ?
                        MACRO( D(LCTL), D(LSFT), D(0), // Toggle fav button 0
                               U(LCTL), U(LSFT), U(0), 
                               W(100),
                               D(LALT), D(LCTL), D(SCLN), // change splitter
                               U(LALT), U(LCTL), U(SCLN),
                               W(100),
                               D(LCTL), D(LSFT), D(LALT), D(Q), // Open in opposite group
                               U(LCTL), U(LSFT), U(LALT), U(Q), 
                               W(100),
                               D(LALT), D(LCTL), D(SCLN), // change splitter
                               U(LALT), U(LCTL), U(SCLN),
                               W(100),
                               D(LCTL), D(0), // restore fav
                               U(LCTL), U(0),
                               W(10),
                               D(LCTL), D(LSFT), D(0), // Toggle fav button 0
                               U(LCTL), U(LSFT), U(0), 
                               END ) : MACRO( END )
                    );
    }
    return MACRO_NONE;
}