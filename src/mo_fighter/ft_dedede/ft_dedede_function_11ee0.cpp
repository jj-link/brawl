// fn_117_11EE0 initializes a small state record pointed to by r3: the byte at
// +0x04 is cleared, the shared 0x1C-byte .data block lbl_117_data_89B0 is
// stored at +0x08, and lbl_117_data_89B0 + 8 is stored at +0x00. The original
// words at .text[0x11EE0,0x11F00) are 38000000 98030004 3C800000 38840000
// 90830008 38040008 90030000 4E800020, with exactly two relocations in the
// m117 (self) import stream: R_PPC_ADDR16_HA at 0x11EEA and R_PPC_ADDR16_LO
// at 0x11EEE, both against .data + 0x89B0 (evidence/rel_decode_11ee0.py,
// which also reproduces the machine-confirmed anchors E20C->0x135468,
// E274->0x135EB4 and E27C->0x13C428 exactly). lbl_117_data_89B0 itself is
// zero-initialized in the original .data and sits directly before the
// "ftDedede..." name strings at .data 0x89CC.
//
// No relocation with addend 0x11EE0 exists in any import stream of
// ft_dedede.rel (m27/m117/m0), so this unit is reached from other modules or
// through unrelocated data; the comparison target is the canonical dtk-sliced
// gap-fallback object build/RSBE01_02/ft_dedede/obj/
// auto_00_00011EE0_text.o (sha1 66025bb0bc1f09653c25a6d815f9231334586b27,
// byte-identical to the retained E6B0 copy of the same slice).
#include <types.h>

struct DededeSearchState {
    void* cursor;
    u8 flag;
    void* base;
};

extern "C" {
extern u8 lbl_117_data_89B0[0x1C];

void fn_117_11EE0(DededeSearchState* state) {
    state->flag = 0;
    state->base = lbl_117_data_89B0;
    state->cursor = &lbl_117_data_89B0[8];
}
}
