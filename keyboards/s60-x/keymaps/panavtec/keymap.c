#include "s60-x.h"
#include "intellij_mac.h"

#define QWERTY 0
#define SPACEFN 1
#define MOUSE 2
#define IJ 3
#define SFN_IJ 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = KEYMAP(
    // ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
    // │ ESC   │  1    │  2    │  3    │  4    │  5    │  6    │  7    │  8    │  9    │  0    │  -    │  =    │▒▒▒▒▒▒▒│ BKSPC │
         KC_ESC,  KC_1 ,  KC_2 ,  KC_3 ,  KC_4 ,  KC_5 ,  KC_6 ,  KC_7 ,  KC_8 ,  KC_9 ,  KC_0 ,KC_MINS, KC_EQL, KC_NO ,KC_BSPC, \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────────────┤
    // │ TAB   │  Q    │  W    │  E    │  R    │  T    │  Y    │  U    │  I    │  O    │  P    │  [    │  ]    │       \       │
         KC_TAB,  KC_Q ,  KC_W ,  KC_E ,  KC_R ,  KC_T ,  KC_Y ,  KC_U ,  KC_I ,  KC_O ,  KC_P ,KC_LBRC,KC_RBRC,    KC_BSLS    , \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────────────┤
    // │ CAPSL │  A    │  S    │  D    │  F    │  G    │  H    │  J    │  K    │  L    │  ;    │  '    │▒▒▒▒▒▒▒│     ENTER     │
    MO(SPACEFN),  KC_A ,  KC_S ,  KC_D ,  KC_F ,  KC_G ,  KC_H ,  KC_J ,  KC_K ,  KC_L ,KC_SCLN,KC_QUOT, KC_NO ,    KC_ENT     , \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    // │ LSHFT │▒▒▒▒▒▒▒│  Z    │  X    │  C    │  V    │  B    │  N    │  M    │  ,    │  .    │  /    │▒▒▒▒▒▒▒│ RSHFT │▒▒▒▒▒▒▒│
        KC_LSFT, KC_NO ,  KC_Z ,  KC_X ,  KC_C ,  KC_V ,  KC_B ,  KC_N ,  KC_M ,KC_COMM, KC_DOT,KC_SLSH, KC_NO ,KC_RSFT, KC_NO , \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────────────┤
    // │ LCTRL │ L_GUI │ L_ALT │███████│███████│███████│  SPC  │███████│███████│███████│ R_ALT │ R_GUI │  APP  │     RCTRL     │
        KC_LCTL,KC_LGUI,KC_LALT,                         F(5),                          KC_RALT,KC_RGUI,KC_CAPS,    KC_RCTL)   , \
    // └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘

    [SPACEFN] = KEYMAP(
    // ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
    // │  `~   │  F1   │  F2   │  F3   │  F4   │  F5   │  F6   │  F7   │  F8   │  F9   │  F10  │  F11  │  F12  │███████│  DEL  │
         KC_GRV, KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11, KC_F12,KC_TRNS, KC_DEL, \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────────────┤
    // │███████│  Q    │  W    │  ESC  │ MUTE  │  T    │███████│  HOME │  UP   │  END  │ PT SCR│SC LOCK│ PAUS  │      INS      │
        KC_TRNS,  F(4) ,  F(3) , KC_ESC,KC_MUTE,  F(3) ,KC_TRNS,KC_HOME, KC_UP , KC_END,KC_PSCR,KC_SLCK,KC_PAUS,    KC_INS     , \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────────────┤
    // │███████│  A    │███████│███████│ VOL UP│███████│ PG UP │  LEFT │ DOWN  │ RIGHT │███████│███████│███████│███████████████│
        KC_TRNS, TO(IJ),KC_TRNS,KC_TRNS,KC_VOLU,KC_TRNS,KC_PGUP,KC_LEFT,KC_DOWN,KC_RGHT,KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS    , \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    // │███████│▒▒▒▒▒▒▒│███████│███████│███████│ VOL DO│  SPC  │ PG DO │  M    │███████│███████│  /    │▒▒▒▒▒▒▒│ RSHFT │▒▒▒▒▒▒▒│
        KC_TRNS, KC_NO ,KC_TRNS,KC_TRNS,KC_TRNS,KC_VOLD,KC_SPC,KC_PGDN,TO(MOUSE),KC_TRNS,KC_TRNS,KC_APP, KC_NO ,KC_RSFT, KC_NO , \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────────────┤
    // │███████│███████│███████│███████│███████│███████│███████│███████│███████│███████│███████│███████│███████│███████████████│
        KC_TRNS,KC_TRNS,KC_TRNS,                        KC_TRNS,                        KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS),    \
    // └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘

    [MOUSE] = KEYMAP(
    // ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
    // │ QWERTY│███████│███████│███████│███████│███████│███████│███████│███████│███████│███████│███████│███████│███████│███████│
     TO(QWERTY),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────────────┤
    // │███████│███████│███████│███████│███████│███████│███████│WHEEL L│  UP   │WHEEL R│███████│███████│███████│███████████████│
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_WH_L,KC_MS_U,KC_WH_R,KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS    , \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────────────┤
    // │███████│███████│███████│███████│███████│███████│WHEEL U│  LEFT │ DOWN  │ RIGHT │███████│███████│███████│███████████████│
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_WH_U,KC_MS_L,KC_MS_D,KC_MS_R,KC_BTN2,KC_TRNS,KC_TRNS,    KC_TRNS    , \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    // │███████│███████│███████│███████│███████│███████│███████│WHEEL D│███████│███████│███████│███████│███████│███████████████│
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_WH_D,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────────────┤
    // │███████│███████│███████│███████│███████│███████│  BTN1 │███████│███████│███████│███████│███████│███████│███████████████│
        KC_TRNS,KC_TRNS,KC_TRNS,                        KC_BTN1,                        KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS),    \
    // └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘

    [IJ] = KEYMAP(
    // ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
    // │ ESC   │  1    │  2    │  3    │  4    │  5    │  6    │  7    │  8    │  9    │  0    │  -    │  =    │▒▒▒▒▒▒▒│ BKSPC │
     TO(QWERTY), F(12) , F(13) , F(14) , F(15) , F(16) , F(17) , F(18) , F(19) , F(20) , F(21) ,KC_MINS, KC_EQL, KC_NO, KC_BSPC, \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────────────┤
    // │ TAB   │  Q    │  W    │  E    │  R    │  T    │  Y    │  U    │  I    │  O    │  P    │  [    │  ]    │       \       │
         KC_TAB,  KC_Q , F(28) , F(10) ,  KC_R , F(24) ,  KC_Y , F(32) , F(34) , F(26) , F(35) ,KC_LBRC,KC_RBRC,    KC_BSLS    , \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────────────┤
    // │ CAPSL │  A    │  S    │  D    │  F    │  G    │  H    │  J    │  K    │  L    │  ;    │  '    │▒▒▒▒▒▒▒│     ENTER     │
     MO(SFN_IJ), F(22) ,  KC_S ,  KC_D ,  F(39),  KC_G ,  KC_H , F(23) ,  KC_K , F(27) ,KC_SCLN,KC_QUOT, KC_NO ,    KC_ENT     , \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    // │ LSHFT │▒▒▒▒▒▒▒│  Z    │  X    │  C    │  V    │  B    │  N    │  M    │  ,    │  .    │  /    │▒▒▒▒▒▒▒│ RSHFT │▒▒▒▒▒▒▒│
        KC_LSFT, KC_NO ,  F(43),  F(47),  F(40),  F(37),  F(33),  F(46),  F(38),KC_COMM, KC_DOT,KC_SLSH, KC_NO ,KC_RSFT, KC_NO , \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────────────┤
    // │ LCTRL │ L_GUI │ L_ALT │███████│███████│███████│  SPC  │███████│███████│███████│ R_ALT │ R_GUI │  APP  │     RCTRL     │
        KC_LCTL,KC_LGUI,KC_LALT,                        F(5),                           KC_RALT,KC_RGUI,KC_CAPS,     F(8)),      \
    // └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
    
    [SFN_IJ] = KEYMAP(
    // ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
    // │  `~   │  F1   │  F2   │  F3   │  F4   │  F5   │  F6   │  F7   │  F8   │  F9   │  F10  │  F11  │  F12  │▒▒▒▒▒▒▒│  DEL  │
        KC_GRV , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , F(36) , KC_F7 , F(41) , F(42) , KC_F10, KC_F11, F(31) ,KC_TRNS, KC_DEL, \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────────────┤
    // │███████│  Q    │  W    │  ESC  │ MUTE  │  T    │███████│  HOME │  UP   │  END  │ PT SCR│SC LOCK│ PAUS  │      INS      │
        KC_TRNS,  F(4) ,  F(3) , KC_ESC,KC_MUTE,  F(3) ,KC_TRNS,  F(44),  F(29),  F(45),KC_PSCR,KC_SLCK,KC_PAUS,     F(25)     , \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────────────┤
    // │███████│  A    │███████│███████│ VOL UP│███████│ PG UP │  LEFT │ DOWN  │ RIGHT │███████│███████│███████│███████████████│
        KC_TRNS, TO(IJ),KC_TRNS,KC_TRNS,KC_VOLU,KC_TRNS,KC_PGUP,KC_LEFT,  F(30),KC_RGHT,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS   , \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    // │███████│▒▒▒▒▒▒▒│███████│███████│███████│ VOL DO│  SPC  │ PG DO │  M    │███████│███████│  /    │▒▒▒▒▒▒▒│ RSHFT │▒▒▒▒▒▒▒│
        KC_TRNS, KC_NO ,KC_TRNS,KC_TRNS,KC_TRNS,KC_VOLD,KC_SPC,KC_PGDN,TO(MOUSE),KC_TRNS,KC_TRNS, KC_APP,  KC_NO,KC_RSFT, KC_NO, \
    // ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────────────┤
    // │███████│███████│███████│███████│███████│███████│███████│███████│███████│███████│███████│███████│███████│███████████████│
        KC_TRNS,KC_TRNS,KC_TRNS,                        KC_TRNS,                        KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS),    \
    // └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
};

const uint16_t PROGMEM fn_actions[] = {
    [5] = ACTION_LAYER_TAP_KEY(1, KC_SPC),     // activate spacefn layer with spacebar
    
    [10] = ACTION_FUNCTION(INTELLIJ_E),
    [11] = ACTION_FUNCTION(BOOTLOADER),
    [12] = ACTION_FUNCTION(INTELLIJ_1),
    [13] = ACTION_FUNCTION(INTELLIJ_2),
    [14] = ACTION_FUNCTION(INTELLIJ_3),
    [15] = ACTION_FUNCTION(INTELLIJ_4),
    [16] = ACTION_FUNCTION(INTELLIJ_5),
    [17] = ACTION_FUNCTION(INTELLIJ_6),
    [18] = ACTION_FUNCTION(INTELLIJ_7),
    [19] = ACTION_FUNCTION(INTELLIJ_8),
    [20] = ACTION_FUNCTION(INTELLIJ_9),
    [21] = ACTION_FUNCTION(INTELLIJ_0),
    [22] = ACTION_FUNCTION(INTELLIJ_A),
    [23] = ACTION_FUNCTION(INTELLIJ_J),
    [24] = ACTION_FUNCTION(INTELLIJ_T),
    [25] = ACTION_FUNCTION(INTELLIJ_INS),
    [26] = ACTION_FUNCTION(INTELLIJ_O),
    [27] = ACTION_FUNCTION(INTELLIJ_L),
    [28] = ACTION_FUNCTION(INTELLIJ_W),
    [29] = ACTION_FUNCTION(INTELLIJ_UP),
    [30] = ACTION_FUNCTION(INTELLIJ_DOWN),
    [31] = ACTION_FUNCTION(INTELLIJ_F12),
    [32] = ACTION_FUNCTION(INTELLIJ_U),
    [33] = ACTION_FUNCTION(INTELLIJ_B),
    [34] = ACTION_FUNCTION(INTELLIJ_I),
    [35] = ACTION_FUNCTION(INTELLIJ_P),
    [36] = ACTION_FUNCTION(INTELLIJ_F6),
    [37] = ACTION_FUNCTION(INTELLIJ_V),
    [38] = ACTION_FUNCTION(INTELLIJ_M),
    [39] = ACTION_FUNCTION(INTELLIJ_F),
    [40] = ACTION_FUNCTION(INTELLIJ_C),
    [41] = ACTION_FUNCTION(INTELLIJ_F8),
    [42] = ACTION_FUNCTION(INTELLIJ_F9),
    [43] = ACTION_FUNCTION(INTELLIJ_Z),
    [44] = ACTION_FUNCTION(INTELLIJ_HOME),
    [45] = ACTION_FUNCTION(INTELLIJ_END),
    [46] = ACTION_FUNCTION(INTELLIJ_N),
    [47] = ACTION_FUNCTION(INTELLIJ_X),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    process_intellij_binding(record, id, opt);
}