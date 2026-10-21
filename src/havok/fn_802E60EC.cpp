#include <types.h>
#pragma force_active on

extern u8 lbl_80487D38[];

struct FnObj60 {
    void* unk0;
    u16 unk4;
    u16 unk6;
};

extern "C" void fn_802E60EC(FnObj60* p) {
    if (p != NULL) {
        p->unk6 = 1;
        p->unk0 = lbl_80487D38;
    }
}
