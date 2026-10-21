#include <types.h>
#pragma force_active on

extern u32 lbl_805A3968;

void fn_80204E7C(void* dst, u32 a, u32 b) {
    ((u32*)dst)[0] = (u32)&lbl_805A3968;
    ((u32*)dst)[1] = a;
    ((u32*)dst)[2] = b;
    ((u32*)dst)[3] = 0;
}
