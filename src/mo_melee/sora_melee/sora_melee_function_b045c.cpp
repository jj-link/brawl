#include <types.h>
#pragma force_active on

struct FnObj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
void fn_27_B045C(FnObj* p) {
    p->unk8 |= 0x10000;
}
}
