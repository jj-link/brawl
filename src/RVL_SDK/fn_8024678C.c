#include <types.h>
#pragma force_active on
#pragma optimize_for_size on
extern void fn_80242908(u8 *p);
void fn_8024678C(u8 *arg0, s32 arg1, u8 *arg2) {
    u16 zero;
    s32 size;
    u8 a;
    u8 *dst;
    u8 *src;
    s32 i;
    zero = 0;
    size = ((arg1 * 4) & 0x3FC) - arg1 + 4;
    *(u16 *)(arg0 + 2) = size;
    a = (u8)((u16)size - 3);
    dst = arg0 + 0xC;
    *(u16 *)(arg0 + 4) = zero;
    arg0[8] = 0x3A;
    arg0[9] = 0xC;
    arg0[0xA] = a;
    arg0[0xB] = (u8)arg1;
    src = arg2;
    for (i = 0; i < arg1; i++) {
        dst[0] = src[2];
        dst[1] = src[1];
        dst[2] = src[0];
        src += 3;
        dst += 3;
    }
    fn_80242908(arg0);
}