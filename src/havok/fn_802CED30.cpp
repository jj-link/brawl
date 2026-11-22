#include <types.h>
#pragma force_active on

typedef struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

extern "C" void fn_802CED30(char* arg0, u16* arg1, s32 arg2, Vec4* arg3) {
    arg2--;
    char* base = arg0 + 0x10;
    while (arg2-- >= 0) {
        u16 off = *arg1++;
        Vec4* s = (Vec4*)(base + off);
        *arg3 = *s;
        *(u32*)&arg3->w = off;
        ++arg3;
    }
}
