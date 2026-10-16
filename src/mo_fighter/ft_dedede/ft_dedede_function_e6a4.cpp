// fn_117_E6A4 is a plain constant-false callback in the module's tiny
// null-callback cluster: the original words at .text[0xE6A4,0xE6AC) are
// 38600000 4E800020 = li r3, 0 ; blr, with zero relocations of any type
// hitting the window in any import stream (m27/m117/m0;
// evidence/rel_decode_e6a4.py, which also reproduces the machine-confirmed
// anchors E20C->0x135468, E274->0x135EB4 and E27C->0x13C428 exactly).
//
// Reference set: the function's address is stored at offset +0x34 of
// lbl_117_data_84E4 (the class vtable whose typeinfo pointer at +0x00 targets
// lbl_117_data_855C, whose name entry targets lbl_117_data_8524, the string
// "ftDededeStatusUniqProcessSpecialSuperJump"; offset-to-top zero at +0x04),
// at the same +0x34 slot of the further status-class vtables at data offsets
// 0x085B4, 0x0863C, 0x086C4, 0x0874C, 0x087D4, 0x08854, 0x088DC, 0x0896C,
// 0x0A114 and 0x0C3C4, and at +0x34 of both 0x40-byte callback tables
// lbl_117_data_8690 and lbl_117_data_C408.
//
// Slot-run context: it sits inside the tiny null-callback cluster E690-E6C4
// that fills the tails of both callback tables (E690/E694 blr, E698
// li r3,1 ; blr, E6A0 blr, E6A4 and E6B0 li r3,0 ; blr, E6AC/E6B8/E6BC/E6C0/
// E6C4 blr). Spelling follows the accepted constant-return convention of this
// cluster: the registered fn_117_E698 (constant true) and the
// ft_metaknight_null_callbacks.cpp stubs (fn_111_C8F0/fn_111_C8FC constant
// false) are all parameterless int functions.
#include <types.h>

extern "C" int fn_117_E6A4() {
    return 0;
}
