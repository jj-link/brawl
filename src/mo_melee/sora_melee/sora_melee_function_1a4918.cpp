#include <types.h>
#pragma force_active on

struct fn_27_1A4918_Obj {
    u8 pad[8];
    u32 flags;
};

extern "C" {
void fn_27_1A4918(fn_27_1A4918_Obj* p) {
    p->flags &= ~0x2;
}
}
