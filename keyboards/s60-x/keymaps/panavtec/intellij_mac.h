#include "s60-x.h"
#include "action_util.h"

void process_intellij_binding(keyrecord_t *record, uint8_t id, uint8_t opt);
const macro_t *process_intellij_macro(keyrecord_t *record, uint8_t id, uint8_t opt);

enum function_id {
    INTELLIJ_E,
    INTELLIJ_1,
    INTELLIJ_2,
    INTELLIJ_3,
    INTELLIJ_4,
    INTELLIJ_5,
    INTELLIJ_6,
    INTELLIJ_7,
    INTELLIJ_8,
    INTELLIJ_9,
    INTELLIJ_0,
    INTELLIJ_A,
    INTELLIJ_J,
    INTELLIJ_T,
    INTELLIJ_INS,
    INTELLIJ_O,
    INTELLIJ_L,
    INTELLIJ_W,
    INTELLIJ_UP,
    INTELLIJ_DOWN,
    INTELLIJ_F12,
    INTELLIJ_U,
    INTELLIJ_B,
    INTELLIJ_I,
    INTELLIJ_P,
    INTELLIJ_F6,
    INTELLIJ_V,
    INTELLIJ_M,
    INTELLIJ_F,
    INTELLIJ_C,
    INTELLIJ_F8,
    INTELLIJ_F9,
    INTELLIJ_Z,
    INTELLIJ_HOME,
    INTELLIJ_END,
    INTELLIJ_N,
    INTELLIJ_X,
    BOOTLOADER,
};

enum macro_id {
    TESTS_IN_SPLITTER,
    SWITCH_SPLITTER_FILES
};