#include <types.h>
#pragma force_active on

extern s32 fn_803E12B4(void *, u32, s32, s32, s32 *);
extern s32 fn_803E0E0C(void *, s32, u32, s32, s32 *);

s32 fn_803E1494(u8 *arg0, u32 arg1, u32 arg2, s32 *arg3, s32 *arg4)
{
    u8 *d;
    s32 n;
    s32 v;
    s32 t;
    s32 m;

    v = *arg3;
    d = *(u8 **)(arg0 + 0x34);
    n = -1;
    if ((u32)(v + 0x10000) != 0xFFFF) {
        n = ((u32)(v - *(s32 *)(d + 0x30)) >> d[0x21]) + 2;
    } else {
        t = fn_803E12B4(arg0, arg1, 0, 0, arg3);
        m = t & ((s32)((-t | t) >> 0x1F));
        if (m != 0) {
            return m;
        }
        v = *arg3;
        if ((u32)(v + 0x10000) != 0xFFFF) {
            n = ((u32)(v - *(s32 *)(d + 0x30)) >> d[0x21]) + 2;
        }
    }

    if ((u32)(v + 0x10000) != 0xFFFF) {
        *arg4 = (*(s32 *)(d + 0x30) + ((n - 1) << d[0x21])) - v;
    } else {
        *arg4 = 0;
    }

    if (((u32)(*arg3 + 0x10000) != 0xFFFF) && (((u32)*arg4 << d[0x20]) < arg2)) {
        t = fn_803E0E0C(arg0, n, (arg1 >> d[0x21]) + 1, arg2, arg4);
        if (t != 0) {
            return t;
        }
    }
    return 0;
}