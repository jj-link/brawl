#pragma force_active on
typedef unsigned char u8;
typedef signed int s32;
typedef signed long long s64;
extern s64 fn_803F1470(s64, s64);
extern s64 fn_803F168C(s64, s64);
extern void fn_803A183C(u8 *, u8 *, u8 *, s32);
s32 fn_803A13E8(u8 *p, int unused, s64 t)
{
    s32 q;
    s32 v;
    if (t + 2208988800LL < 0)
        t = -2208988800LL;
    p[5] = fn_803F168C(t + 2208988800LL, 60);
    v = fn_803F1470(t + 2208988800LL, 60);
    if (v < 0)
        v = 0;
    q = v / 1440;
    v %= 1440;
    p[4] = v / 60;
    p[6] = v % 60;
    fn_803A183C(p, p + 2, p + 3, q);
    return 0;
}