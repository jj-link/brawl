#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_80116E94(void* p, int arg1);
extern "C" void* fn_8027EA20(void* self, unsigned int arg, int align);

extern void* lbl_805A0EC8;
extern const float lbl_805A1BB8;
extern const float lbl_805A1BBC;

struct Fn80082438Obj {
    u32 f00;
    u32 f04;
    u32 f08;
    s32 f0c;
    void* f10;
    u8 f14;
    u32 f18;
    u32 f1c;
    void* f20;
    u32 f24;
    u32 f28;
    void* f2c;
    u32 f30;
    u32 f34;
    u8 f38;
    u8 f39;
    u8 f3a;
    u8 f3b;
    u8 f3c;
    u8 f3d;
    u32 f40;
    f32 f44;
    f32 f48;
    s32 f4c;
    u8 f50;
    u32 f54;
    f32 f58;
    u32 f5c;
    u32 f60;
    u32 f64;
    u8 f68;
    u32 f6c;
};

extern "C" Fn80082438Obj* fn_80082438(Fn80082438Obj* self) {
    self->f00 = 0;
    self->f04 = 0;
    self->f08 = 0x80000000;
    self->f0c = -1;
    self->f10 = 0;
    self->f14 = 0;
    self->f18 = 0;
    self->f1c = 0;
    self->f20 = fn_8027EA20(lbl_805A0EC8, 0, 0x15);
    self->f24 = 0;
    self->f28 = 0;
    self->f2c = fn_8027EA20(lbl_805A0EC8, 0, 0x15);
    self->f30 = 0;
    self->f34 = 0;
    self->f38 = 1;
    self->f39 = 0;
    self->f3a = 0;
    self->f3b = 0;
    self->f3c = 0;
    self->f3d = 0;
    self->f40 = 0;
    self->f44 = lbl_805A1BB8;
    self->f48 = lbl_805A1BB8;
    self->f4c = 1;
    self->f50 = 0;
    self->f54 = 0;
    self->f58 = lbl_805A1BBC;
    self->f5c = 0;
    self->f60 = 0;
    self->f64 = 0;
    self->f68 = 1;
    self->f6c = 0;
    void* p = __nw__FUlQ25Heaps8HeapType(0x20, 0xD);
    if (p != 0) {
        p = fn_80116E94(p, 0xDC);
    }
    self->f10 = p;
    return self;
}
