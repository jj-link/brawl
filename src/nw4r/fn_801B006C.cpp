#include <types.h>
#pragma force_active on

struct Fn801Inner {
    u8 pad[0x140];
    u32* m140;
};

struct Fn801Obj {
    Fn801Inner* m0;
    u32 m4;
    u8 pad8[0x14];
    void* m1c;
};

extern "C" void* fn_801B006C(Fn801Obj* self, s32 arg) {
    if (self->m0 != 0 && self->m1c != 0) {
        if (arg != 0) {
            u32* table = self->m0->m140;
            table[self->m4] |= 0x20;
        }
        return self->m1c;
    }
    return 0;
}
