#pragma force_active on
typedef unsigned int u32;

extern void fn_80203E4C(u32 a, u32 b, u32 c, u32 d, u32 e);

u32 fn_802049BC(u32 arg0, u32 arg1, u32 arg2) {
    u32 end = (arg1 + arg0) & ~3;
    u32 start = (arg0 + 3) & ~3;
    u32 *p;

    if (start > end || (end - start) < 0x48) {
        return 0;
    }
    fn_80203E4C(start, 0x46524D48, start + 0x48, end, arg2);
    p = (u32 *)start;
    p[0x3C / 4] = p[0x18 / 4];
    p[0x40 / 4] = p[0x1C / 4];
    p[0x44 / 4] = 0;
    return start;
}
