#include <types.h>
#pragma force_active on

struct bss_loc_t {
    u32 unk0;
    s32 unk4;
};

extern "C" {
extern bss_loc_t lbl_27_bss_5920;
extern bss_loc_t lbl_27_bss_5928;

void fn_27_23EFD8() {
    lbl_27_bss_5920.unk0 = 0xFF;
    lbl_27_bss_5920.unk4 = 0;
    lbl_27_bss_5928.unk0 = 0xFF;
    lbl_27_bss_5928.unk4 = 1;
}
}

__declspec(section ".ctors") extern void* const fn_27_23EFD8_ctor = (void*)fn_27_23EFD8;
