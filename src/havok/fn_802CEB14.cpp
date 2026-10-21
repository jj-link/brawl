#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_80487408[];

struct UnkObj {
    u8* unk0;
    u8 pad4[2];
    s16 unk6;
};

void fn_802CEB14(UnkObj* arg0) {
    if (arg0 != 0) {
        arg0->unk6 = 1;
        arg0->unk0 = lbl_80487408;
    }
}
}
