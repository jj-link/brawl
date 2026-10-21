#include <types.h>
#pragma force_active on

struct bss_loc_t {
    u32 unk0;
    s32 unk4;
};

extern "C" {
    extern bss_loc_t lbl_27_bss_31E8;
    extern bss_loc_t lbl_27_bss_31F0;
}

extern "C" void fn_27_145448() {
    lbl_27_bss_31E8.unk0 = 0xFF;
    lbl_27_bss_31E8.unk4 = 0;
    lbl_27_bss_31F0.unk0 = 0xFF;
    lbl_27_bss_31F0.unk4 = 1;
}

__declspec(section ".ctors") extern void* const fn_27_145448_ctor = (void*)fn_27_145448;
