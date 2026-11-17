#include <types.h>
#pragma force_active on

extern s64 fn_801E1B54(void);
extern s32 fn_803A7FF0(void);
extern s32 fn_803A86F8(s32, s32, s32, s32 *, s32 *);
extern void OSSleepTicks(s64 ticks);

s32 fn_803A6D5C(s32 timeout) {
    s32 spC;
    s32 sp8;
    s32 ret = 0;
    s32 r;
    s64 deadline = 0;
    s64 now = 0;
    u32 ticks;
    u32 prod;

    if (timeout != 0) {
        now = fn_801E1B54();
        ticks = (*(u32 *)0x800000F8 >> 2) / 1000;
        prod = (u32)timeout * ticks;
        deadline = prod + now;
    }
    for (;;) {
        ticks = (*(u32 *)0x800000F8 >> 2) / 1000;
        OSSleepTicks(10 * (s64)ticks);
        sp8 = 4;
        r = fn_803A86F8(0, 0xFFFE, 0x1003, &spC, &sp8);
        if (r != 0) {
            ret = r;
            break;
        } else if (r == 0 && spC != 0) {
            ret = spC;
            break;
        } else if (fn_803A7FF0() != 0) {
            break;
        } else if (deadline != 0) {
            now = fn_801E1B54();
            if (deadline < now) {
                ret = -0x4C;
                break;
            }
        }
    }
    return ret;
}
