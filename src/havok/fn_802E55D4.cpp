#include <types.h>
#pragma force_active on

extern u8 lbl_80487E28[];

struct UnkObj {
    u8* unk0;
    u8 pad4[2];
    u16 unk6;
};

extern "C" {
void fn_802E55D4(UnkObj* arg0) {
    if (arg0 != 0) {
        u8* p = lbl_80487E28;
        arg0->unk6 = 1;
        arg0->unk0 = p;
    }
}
}
