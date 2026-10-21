#include <types.h>
#pragma force_active on

extern "C" {
extern u8 __vt__6mtRand[];

struct UnkRandSlot {
    void* vtbl;
    u32 unk4;
};

extern UnkRandSlot lbl_805A0420;

void fn_80147418(void) {
    lbl_805A0420.vtbl = __vt__6mtRand;
    lbl_805A0420.unk4 = 0;
}
}

__declspec(section ".ctors") extern void* const fn_80147418_ctor = (void*)fn_80147418;
