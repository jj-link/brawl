#include <types.h>
#pragma force_active on

extern char lbl_80486EB8[];

struct UnkObj {
    void* unk0;
    u8 pad4[2];
    s16 unk6;
    s32 unk8;
};

extern "C" void fn_802C0590(UnkObj* arg0) {
    arg0->unk6 = 1;
    arg0->unk8 = 0;
    arg0->unk0 = lbl_80486EB8;
}
