#include <types.h>
#pragma force_active on

struct bss_loc_t {
    u32 unk0;
    s32 unk4;
};

extern bss_loc_t lbl_27_bss_2E78;
extern bss_loc_t lbl_27_bss_2E80;

extern "C" void fn_27_113030() {
    lbl_27_bss_2E78.unk0 = 0xFF;
    lbl_27_bss_2E78.unk4 = 0;
    lbl_27_bss_2E80.unk0 = 0xFF;
    lbl_27_bss_2E80.unk4 = 1;
}

__declspec(section ".ctors") extern void* const fn_27_113030_ctor = (void*)fn_27_113030;
