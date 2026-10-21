#include <types.h>
#pragma force_active on

struct bss_loc_t {
    u32 unk0;
    s32 unk4;
};

extern "C" {
extern bss_loc_t lbl_27_bss_5658;
extern bss_loc_t lbl_27_bss_5660;
void fn_27_21BE10(void);
}

extern "C" void fn_27_21BE10(void)
{
    lbl_27_bss_5658.unk0 = 0xFF;
    lbl_27_bss_5658.unk4 = 0;
    lbl_27_bss_5660.unk0 = 0xFF;
    lbl_27_bss_5660.unk4 = 1;
}

__declspec(section ".ctors") extern void* const fn_27_21BE10_ctor = (void*)fn_27_21BE10;
