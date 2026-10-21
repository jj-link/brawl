#include <types.h>
#pragma force_active on

extern "C" void* memset(void* dst, int value, unsigned long size);

struct Fn16Obj {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 f0c;
    u8 pad0d[0x24 - 0x0d];
    u8 block24[0x14];
    u32 f38;
    u32 f3c;
    s32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
    u32 f50;
    u32 f54;
    u32 f58;
    u32 pad5c;
    u32 f60;
    u32 f64;
    u8 pad68[0x84 - 0x68];
    u32 f84;
    u8 pad88[0x8c - 0x88];
    s32 f8c;
    u32 f90;
};

extern "C" Fn16Obj* fn_16_3B4(Fn16Obj* self) {
    self->f00 = 0;
    self->f0c = 0;
    self->f3c = 0;
    self->f40 = 13;
    self->f44 = 0;
    self->f48 = 0;
    self->f4c = 0;
    self->f50 = 0;
    self->f54 = 0;
    self->f58 = 0;
    self->f60 = 0;
    self->f64 = 0;
    self->f84 = 0;
    self->f04 = 0;
    self->f08 = 0;
    self->f8c = 0x23;
    memset(self->block24, 0, 0x14);
    self->f38 = 0;
    self->f90 = 0;
    return self;
}
