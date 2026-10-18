#include <types.h>
#pragma force_active on

extern "C" {
// 64-byte table in .data (lbl_114_data_A8B0); only its address is taken here,
// so no bytes for it are emitted by this translation unit.
extern const u32 lbl_114_data_A8B0[16];
}

extern "C" void fn_114_1C5E0(const u32** out) {
    *out = lbl_114_data_A8B0;
}
