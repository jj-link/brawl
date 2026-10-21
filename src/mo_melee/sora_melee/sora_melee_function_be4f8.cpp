#include <types.h>
#pragma force_active on

struct bss_loc_2B88_t {
    u32 unk0;
    s32 unk4;
};

extern "C" bss_loc_2B88_t lbl_27_bss_2B88;
extern "C" bss_loc_2B88_t lbl_27_bss_2B90;

extern "C" void fn_27_BE4F8() {
    lbl_27_bss_2B88.unk0 = 0xFF;
    lbl_27_bss_2B88.unk4 = 0;
    lbl_27_bss_2B90.unk0 = 0xFF;
    lbl_27_bss_2B90.unk4 = 1;
}

__declspec(section ".ctors") extern void* const fn_27_BE4F8_ctor = (void*)fn_27_BE4F8;
