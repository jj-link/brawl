#include <types.h>
#pragma force_active on

struct Fn801Target {
    char pad[0x140];
    u32* m140;
};

struct Fn801Obj {
    Fn801Target* m0;
    u32 m4;
    char pad8[0x10];
    u32 m18;
};

extern "C" s32 fn_801B0024(Fn801Obj* self, s32 arg) {
    if (self->m0 != 0 && self->m18 != 0) {
        if (arg != 0) {
            u32* p = self->m0->m140;
            char* base = (char*)p;
            u32 off = self->m4 << 2;
            *(u32*)(base + off) |= 0x10;
        }
        return self->m18;
    }
    return 0;
}
