#include <types.h>
#pragma force_active on

extern f32 lbl_805A3640;
extern f32 lbl_805A3644;

extern "C" void fn_801D049C(u8* p, u32 a, u32 b, u32 c, u32 d) {
    f32 zero;
    f32 one = lbl_805A3640;
    u32 zi = 0;
    zero = lbl_805A3644;
    u32 oi = 1;
    *(u32*)(p + 0x9C) = a;
    *(u32*)(p + 0xA0) = b;
    *(u32*)(p + 0xA4) = c;
    *(u32*)(p + 0xA8) = d;
    *(u8*)(p + 0xB1) = zi;
    *(u8*)(p + 0xAF) = zi;
    *(u8*)(p + 0xB0) = zi;
    *(u8*)(p + 0xAE) = zi;
    *(f32*)(p + 0x110) = one;
    *(f32*)(p + 0x114) = zero;
    *(f32*)(p + 0x118) = one;
    *(f32*)(p + 0xC0) = one;
    *(f32*)(p + 0xB8) = zero;
    *(f32*)(p + 0xBC) = zero;
    *(u32*)(p + 0xC4) = oi;
    *(f32*)(p + 0xC8) = one;
    *(f32*)(p + 0xCC) = one;
    *(f32*)(p + 0xD0) = zero;
    *(f32*)(p + 0xD4) = zero;
    *(f32*)(p + 0xD8) = zero;
    *(f32*)(p + 0xDC) = one;
    *(f32*)(p + 0xEC) = one;
    *(f32*)(p + 0xFC) = zero;
    *(f32*)(p + 0xE0) = one;
    *(f32*)(p + 0xF0) = one;
    *(f32*)(p + 0x100) = zero;
    *(f32*)(p + 0xE4) = one;
    *(f32*)(p + 0xF4) = one;
    *(f32*)(p + 0x104) = zero;
    *(f32*)(p + 0xE8) = one;
    *(f32*)(p + 0xF8) = one;
    *(f32*)(p + 0x108) = zero;
    *(f32*)(p + 0x10C) = one;
    *(u8*)(p + 0xB2) = zi;
    *(u32*)(p + 0x11C) = zi;
    *(u32*)(p + 0x120) = zi;
}
