#include <revolution/GX.h>
#pragma force_active on

extern const float lbl_805A4A34;
extern const float lbl_805A4A38;
extern const float lbl_805A4A48;
extern const float lbl_805A4A4C;

extern void fn_801ECF4C(void *p, float f1, float f2, float f3, float f4, float f5, float f6);
extern void fn_801F50EC(void *p, int v);
extern void fn_801F5484(float f1, float f2, float f3, float f4, float f5, float f6);
extern void fn_801F54D0(float x, float y);
extern void fn_801EFB10(void);
extern void fn_801F0248(void);
extern void fn_801EF280(int a, int b);
extern void fn_801EFB44(int a, int b, int c, int d, int e);
extern void fn_801F4748(int a);
extern void fn_801F4880(int a);
extern void fn_801F3F5C(int a, int b, int c, int d, int e);

void fn_803D3164(void)
{
    char sp8[0x40];

    fn_801ECF4C(sp8, lbl_805A4A38, lbl_805A4A48, lbl_805A4A38, lbl_805A4A4C, lbl_805A4A38, lbl_805A4A34);
    fn_801F50EC(sp8, 1);
    fn_801F5484(lbl_805A4A38, lbl_805A4A38, lbl_805A4A4C, lbl_805A4A48, lbl_805A4A38, lbl_805A4A34);
    fn_801F54D0(lbl_805A4A34, lbl_805A4A38);
    GXSetCullMode(2);
    GXSetZMode(0, 3, 0);
    GXSetZCompLoc(0);
    GXSetAlphaCompare(4, 0, 1, 0, 0);
    fn_801F4748(1);
    fn_801F4880(0);
    fn_801EFB10();
    fn_801F0248();
    fn_801EF280(9, 1);
    fn_801EF280(0xB, 1);
    fn_801EF280(0xD, 1);
    fn_801EFB44(0, 9, 0, 4, 0);
    fn_801EFB44(0, 0xB, 1, 5, 0);
    fn_801EFB44(0, 0xD, 1, 3, 8);
    GXSetNumChans(1);
    GXSetChanCtrl(4, 0, 0, 1, 0, 0, 2);
    GXSetNumTexGens(1);
    GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
    fn_801F3F5C(0, 0, 1, 2, 3);
    fn_801F3F5C(1, 0, 0, 0, 3);
    fn_801F3F5C(2, 1, 1, 1, 3);
    fn_801F3F5C(3, 2, 2, 2, 3);
}
