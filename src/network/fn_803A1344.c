#pragma force_active on
typedef unsigned char u8;
typedef signed int s32;

extern void fn_803A183C(u8 *, u8 *, u8 *, s32);

s32 fn_803A1344(u8 *p, s32 t)
{
    s32 q;

    if (t < 0) {
        t = 0;
    }

    q = t / 1440;
    t %= 1440;
    p[4] = t / 60;
    p[6] = t % 60;
    fn_803A183C(p, p + 2, p + 3, q);
    return 0;
}
