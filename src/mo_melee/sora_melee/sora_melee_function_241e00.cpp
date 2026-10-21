#include <types.h>
#pragma force_active on

struct bss_loc_t {
    u32 unk0;
    s32 unk4;
};

extern bss_loc_t lbl_27_bss_5970;
extern bss_loc_t lbl_27_bss_5978;

extern "C" void fn_27_241E00() {
    lbl_27_bss_5970.unk0 = 0xFF;
    lbl_27_bss_5970.unk4 = 0;
    lbl_27_bss_5978.unk0 = 0xFF;
    lbl_27_bss_5978.unk4 = 1;
}

__declspec(section ".ctors") extern void* const fn_27_241E00_ctor = (void*)fn_27_241E00;
