#include <types.h>
#pragma force_active on

extern "C" void fn_800B96E8(void*, int);

struct Obj {
    u8 pad[0x40];
    u8* p;
};

extern "C" void fn_2_6984(Obj* self) {
    u32 r7 = 0;
    u32 z = 0;
    u32 r6 = 0;
    int i;
    u32 off;

    *(u32*)(self->p + 0x0) = z;
    *(u32*)(self->p + 0x4) = z;
    *(u32*)(self->p + 0x10C) = z;
    *(u32*)(self->p + 0x110) = z;

    for (r7 = 0; r7 < 65; ++r7) {
        *(u32*)(self->p + 0x8 + r7 * 4) = z;
    }

    for (r7 = 0; r7 < 1305; ++r7) {
        *(u32*)(self->p + 0x114 + r7 * 4) = 0;
    }
    *(u32*)(self->p + 0x1578) = 0;
    *(u32*)(self->p + 0x157C) = 0;
    fn_800B96E8(self->p + 0x1580, 0xF0);
    *(u8*)(self->p + 0x1628) = 0;
    *(u16*)(self->p + 0x162A) = 0;
    *(u32*)(self->p + 0x162C) = 0;
    *(u32*)(self->p + 0x1630) = 0;
}
