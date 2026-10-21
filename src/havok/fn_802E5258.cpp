#include <types.h>
#pragma force_active on

struct fn_802E5258_obj {
    void* unk0;
    u8 unk4;
    u8 unk5;
    u16 unk6;
};

extern char lbl_80488088[0x78];

extern "C" void fn_802E5258(fn_802E5258_obj* arg0) {
    if (arg0 != NULL) {
        arg0->unk6 = 1;
        arg0->unk0 = &lbl_80488088;
    }
}
