#include <types.h>
#pragma force_active on

struct FnObj {
    void* unk0;
    u16 unk4;
    u16 unk6;
};

extern u8 lbl_80487380[];

extern "C" {
void fn_802CD884(FnObj* arg0) {
    if (arg0 != 0) {
        arg0->unk6 = 1;
        arg0->unk0 = lbl_80487380;
    }
}
}
