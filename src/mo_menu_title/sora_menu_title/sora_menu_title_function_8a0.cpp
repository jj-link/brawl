#include <types.h>
#pragma force_active on

struct Obj {
    u8 pad[0x2c];
    u8 flags;
    u8 pad2[0x50 - 0x2d];
    u32 unk50;
};

extern "C" {
void fn_24_8A0(Obj* p) {
    p->unk50 = 0;
    p->flags &= ~2;
}
}
