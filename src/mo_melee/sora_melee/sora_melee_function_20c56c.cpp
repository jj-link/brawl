#include <types.h>
#pragma force_active on

struct BssLoc {
    u32 unk0;
    s32 unk4;
};

extern "C" {
extern BssLoc lbl_27_bss_5528;
extern BssLoc lbl_27_bss_5530;

void fn_27_20C56C() {
    lbl_27_bss_5528.unk0 = 0xFF;
    lbl_27_bss_5528.unk4 = 0;
    lbl_27_bss_5530.unk0 = 0xFF;
    lbl_27_bss_5530.unk4 = 1;
}
}

__declspec(section ".ctors") extern void* const fn_27_20C56C_ctor = (void*)fn_27_20C56C;
