#pragma force_active on
typedef unsigned int u32;
typedef int s32;
s32 fn_803B5984(u32 *, s32, u32 *, u32 *);
s32 fn_803B65B0(u32 *, s32, s32, s32, u32 *, u32 *);
s32 fn_803B6B18(u32 *a, s32 b, s32 c, u32 *p) {
    u32 sp10, spC, sp8;
    u32 *r7, *r8, *out;
    u32 t, n;
    s32 ret;
    r7 = (u32 *)a[2];
    r8 = (u32 *)a[0xD];
    t = r7[0];
    n = r8[7];
    out = (u32 *)a[0xC];
    if (t == 0 && c == 0) {
        *p = -1;
        return 0;
    }
    if (t == 1) {
        if (n <= 1) {
            *p = -1;
            return 0;
        }
        r7[0] = r8[4];
    }
    if (a[7] != 0 && c == 0) {
        ret = fn_803B5984(a, b, p, &sp10);
        if (ret != 0) return ret;
        if (sp10 == 1) {
            out[2] = a[0];
            out[0] = b;
            out[1] = *p;
            return 0;
        }
    }
    *p = -1;
    ret = fn_803B65B0(a, b, c != 0, 0, &sp8, &spC);
    switch (ret) {
    case 0:
        if (spC >= 2 && spC < ((u32 *)a[0xD])[0xD] + 2) *p = spC;
        ret = 0;
        break;
    default:
        break;
    }
    if (ret != 0) return ret;
    if ((u32)(*p + 0x10000) == 0xffff) return 0;
    out[2] = a[0];
    out[0] = b;
    out[1] = *p;
    return 0;
}