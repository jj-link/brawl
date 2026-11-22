#include <types.h>
#pragma force_active on
extern void fn_801E1D80(s64, void*);
extern u32 lbl_80534008[9];
u32* fn_8034F5C4(s64* arg0) {
    u64 divisor;
    s64 time;
    u32 sp8[10];
    u32 *base = lbl_80534008;
    divisor = (u32)*(u32*)0x800000F8 >> 2;
    time = *arg0 - 946684800LL;
    fn_801E1D80(time * (s64)divisor, sp8);
    base[0] = sp8[0];
    base[1] = sp8[1];
    base[2] = sp8[2];
    base[3] = sp8[3];
    base[4] = sp8[4];
    base[5] = sp8[5] - 0x76C;
    base[6] = sp8[6];
    base[7] = sp8[7];
    base[8] = 0;
    return base;
}
