#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_4E604(u8* p, s32 v, f32* a, f32* b) {
    f32 b2;
    f32 b1;
    f32 b0;
    f32 a2;
    f32 a1;
    f32 a0;
    a0 = a[0];
    a1 = a[1];
    a2 = a[2];
    b0 = b[0];
    b1 = b[1];
    b2 = b[2];
    *(f32*)(p + 0xDC) = a0;
    *(f32*)(p + 0xE0) = a1;
    *(f32*)(p + 0xE4) = a2;
    *(f32*)(p + 0xE8) = b0;
    *(f32*)(p + 0xEC) = b1;
    *(f32*)(p + 0xF0) = b2;
    *(s32*)(p + 0xF4) = v;
}
}
