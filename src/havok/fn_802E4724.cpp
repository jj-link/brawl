#include <types.h>
#pragma force_active on

extern "C" u8 lbl_80487CD0[];

struct FnObj {
    void* unk0;
    u8 pad[6 - 4];
    u16 unk6;
};

extern "C" void fn_802E4724(FnObj* p) {
    if (p != 0) {
        p->unk6 = 1;
        p->unk0 = lbl_80487CD0;
    }
}
