#include <types.h>
#pragma force_active on

struct Obj {
    u8 pad[0x2c];
    u8 flags;
    u8 pad2[0x40 - 0x2d];
    u32 unk40;
    u32 unk44;
};

extern "C" {
void fn_800B092C(Obj* p) {
    p->unk40 = 0;
    p->flags &= ~2;
    p->unk44 = 0;
}
}
