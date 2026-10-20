#include <types.h>
#pragma force_active on

struct Fn27Obj {
    u8 pad0[8];
    s32 m8;
};

extern "C" {
void* fn_27_1AF724(Fn27Obj* self, s32 idx) {
    s32 n = (self->m8 >> 22) + idx;
    if (n >= 0x139) {
        n -= 0x139;
    }
    return (u8*)self + (n << 2) + 0xc;
}
}
