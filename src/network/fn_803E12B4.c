#include <types.h>
#pragma force_active on

s32 fn_803E100C(u8 *ctx, u32 key, u32 mode, u32 *out);
s32 fn_803E119C(u8 *ctx, u32 key, u32 count, u32 *out);

s32 fn_803E12B4(u8 *ctx, u32 key, u32 mode, u32 val, u32 *out) {
    u8 *obj;
    u32 sp8;
    u32 shifted;
    u32 flag;
    s32 r;

    obj = *(u8 **)(ctx + 0x34);
    flag = *(u32 *)(obj + 0x1C);
    if (**(u32 **)(ctx + 0x8) == 1 && flag <= 1) {
        if (key >= *(u16 *)(obj + 0x24)) {
            *out = -1;
            r = 0;
        } else {
            *out = *(u32 *)(obj + 0x2C) + key;
            r = 0;
        }
        if (r != 0) {
            return r;
        }
        return 0;
    }

    shifted = key >> obj[0x21];
    if (mode == 2) {
        u32 unit = *(u16 *)obj;
        u32 n = obj[0x6];
        u32 blocks = val / unit;
        u32 rem = (val - blocks * unit) != 0;
        u32 t = blocks + rem;
        u32 pages = t / n;
        u32 rem2 = (t - pages * n) != 0;
        r = fn_803E119C(ctx, shifted, pages + rem2, &sp8);
        if (r != 0) {
            return r;
        }
    } else {
        r = fn_803E100C(ctx, shifted, mode, &sp8);
        if (r != 0) {
            return r;
        }
    }

    if ((u32)(sp8 + 0x10000) == 0xFFFF) {
        *out = -1;
        return 0;
    }
    *out = *(u32 *)(obj + 0x30) + ((sp8 - 2) << obj[0x21]) +
           (key & (obj[0x6] - 1));
    return 0;
}