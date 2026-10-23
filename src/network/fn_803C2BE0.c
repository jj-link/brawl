#pragma force_active on
typedef int s32;
extern void fn_803BC750(s32, s32, s32, s32, s32 *);

s32 fn_803C2BE0(void) {
    s32 sp8;
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    fn_803BC750(a, b, c, d, &sp8);
    return sp8;
}
