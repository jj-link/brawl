#include <types.h>
#pragma force_active on

struct BssPair {
    u32 unk0;
    s32 unk4;
};

extern "C" {
extern BssPair lbl_27_bss_3148;
extern BssPair lbl_27_bss_3150;

void fn_27_13FFA8() {
    lbl_27_bss_3148.unk0 = 0xFF;
    lbl_27_bss_3148.unk4 = 0;
    lbl_27_bss_3150.unk0 = 0xFF;
    lbl_27_bss_3150.unk4 = 1;
}
}

__declspec(section ".ctors") extern void* const fn_27_13FFA8_ctor = (void*)fn_27_13FFA8;
