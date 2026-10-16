// fn_117_E698 is the final function slot of the module's two 0x40-byte
// callback tables and is a plain constant-true getter: the original words at
// .text[0xE698,0xE6A0) are 38600001 4E800020 = li r3, 1 ; blr, with zero
// relocations of any type hitting the window in any import stream
// (m27/m117/m0; evidence/rel_decode_e698.py, which also reproduces the
// machine-confirmed anchors E2D8->0x13DD00, E2E0->0x13C7D0 and
// E2F0->0x13C724 exactly).
//
// Slot-run context: it is referenced at offset +0x3C (the final word) of both
// lbl_117_data_8690 and lbl_117_data_C408, and sits inside the tiny
// null-callback cluster E690-E6C4 (E690/E694 blr, E6A0 blr, E6A4 and E6B0
// li r3,0 ; blr, E6B8-E6C4 blr). Spelling follows the accepted
// constant-return convention in ft_metaknight_null_callbacks.cpp
// (fn_111_C8E4: int fn() { return 1; }).
#include <types.h>

extern "C" int fn_117_E698() {
    return 1;
}
