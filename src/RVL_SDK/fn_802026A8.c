#pragma force_active on
typedef float f32;
typedef unsigned char u8;
typedef int s32;

extern void fn_80202934(u8 *p);
extern const f32 lbl_805A3910;
extern const f32 lbl_805A3914;

void fn_802026A8(u8 *p)
{
    f32 f0, f1, f2, f3, f4, f5, f6, f7;

    f7 = *(f32 *)(p + 0x158);
    f6 = *(f32 *)(p + 0x150);
    f5 = *(f32 *)(p + 0x148);
    f4 = *(f32 *)(p + 0x154);
    f3 = *(f32 *)(p + 0x15C);
    f2 = lbl_805A3910;
    f1 = lbl_805A3914;
    f0 = *(f32 *)(p + 0x14C);

    *(s32 *)(p + 0x110) = 5;
    *(f32 *)(p + 0x114) = f7;
    *(f32 *)(p + 0x118) = f7;
    *(s32 *)(p + 0x11C) = 0;
    *(f32 *)(p + 0x120) = f6;
    *(f32 *)(p + 0x124) = f5;
    *(f32 *)(p + 0x128) = f4;
    *(f32 *)(p + 0x12C) = f3;
    *(f32 *)(p + 0x130) = f2;
    *(f32 *)(p + 0x134) = f1;
    *(s32 *)(p + 0x138) = 0;
    *(s32 *)(p + 0x13C) = 0;
    *(f32 *)(p + 0x140) = f0;
    *(f32 *)(p + 0x144) = f2;

    fn_80202934(p);
}
