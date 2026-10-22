#pragma force_active on
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned char u8;
typedef signed char s8;

extern s32 fn_803B68D8(u8 *, s32, u32, u32, s32 *);
extern s32 fn_803B7080(u8 *, u32, s32);

s32 fn_803B722C(u8 *arg0, u32 arg1, u32 arg2, s32 *arg3, s32 *arg4)
{
    u8 *d;
    s32 n;
    s32 v;
    s32 r;

    n = -1;
    if (arg0 == 0) {
        return 0xA;
    }
    if (*(u8 **)(arg0 + 0x30) == 0) {
        return 0xA;
    }
    if (*(u32 *)arg0 == 0) {
        return 0xA;
    }
    if (*(u32 *)(*(u8 **)(arg0 + 0x30) + 8) > *(u32 *)arg0) {
        return 0xA;
    }
    d = *(u8 **)(arg0 + 0x34);
    if ((s8)d[0x187a] < 0x41 || (s8)d[0x187a] > 0x5A) {
        return 0x23;
    }
    if (arg1 >= ((0xFFFFFFFFu >> d[0x20]) + 1)) {
        return 0x25;
    }

    v = *arg3;
    if ((u32)(v + 0x10000) != 0xFFFF) {
        n = ((u32)(v - *(s32 *)(d + 0x30)) >> d[0x21]) + 2;
    } else {
        r = fn_803B7080(arg0, arg1, 0);
        if (r != 0) {
            return r;
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
        r = fn_803B68D8(arg0, n, (arg1 >> d[0x21]) + 1, arg2, arg4);
        if (r != 0) {
            return r;
        }
    }
    return 0;
}
