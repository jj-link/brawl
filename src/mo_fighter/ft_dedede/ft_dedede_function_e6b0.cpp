// fn_117_E6B0 is one of the shared null-callback slots filled by the module's
// 0x40-byte callback tables and is a plain constant-false getter: the original
// words at .text[0xE6B0,0xE6B8) are 38600000 4E800020 = li r3, 0 ; blr, with
// zero relocations of any type hitting the window in any import stream
// (m27/m117/m0; evidence/rel_decode_e6b0.py, which also reproduces the
// machine-confirmed anchors E20C->0x135468, E274->0x135EB4 and E27C->0x13C428
// exactly).
//
// Slot-run context: the tiny null-callback cluster E690-E6C4 holds E690/E694
// blr, E6A0 blr, E6A4 and E6B0 li r3,0 ; blr, and E6B8-E6C4 blr. E6B0 is
// referenced twelve times in .data (section 5: 0x08510, 0x085AC, 0x08634,
// 0x086BC, 0x08744, 0x087CC, 0x0884C, 0x088D4, 0x08964, 0x0A10C, 0x0C3BC and
// 0x0C434), each the +0x2C slot of a 0x40-byte callback table whose remaining
// slots point at the other null callbacks or real handlers - including
// lbl_117_data_8690 +0x2C and lbl_117_data_C408 +0x2C
// (evidence/rel_datarefs_e6b0.py). Spelling follows the accepted
// constant-return convention in ft_metaknight_null_callbacks.cpp
// (fn_111_C8F0/C8FC: int fn() { return 0; }) and the published fn_117_E698.
#include <types.h>

extern "C" int fn_117_E6B0() {
    return 0;
}
