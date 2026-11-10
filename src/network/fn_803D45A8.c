#include <types.h>
#include <revolution/GX.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/MTX/mtx.h>
#pragma force_active on
extern void fn_801EC158(Mtx);
extern void fn_801EC8DC(Mtx, Mtx, float, float, float);
extern void fn_801EC5DC(Mtx, s8, float);
extern void fn_801EC1B8(Mtx, Mtx, Mtx);
extern void fn_801EC868(Mtx, Mtx, float, float, float);
extern void fn_801F51DC(Mtx, int);
extern void fn_801F52E4(int);
extern float lbl_805A4A34, lbl_805A4A38, lbl_805A4A5C;
extern double lbl_805A4A70;
extern float lbl_805A4AD8, lbl_805A4ADC, lbl_805A4AE0, lbl_805A4AE4, lbl_805A4AE8;
void fn_803D45A8(int arg0, float a, float b, float c, float d, float e)
{
 Mtx sp38, sp8;
 int v31;
 float f31, f;
 double temp;
 fn_801EC158(sp8);
 fn_801EC8DC(sp8, sp8, c, d, lbl_805A4A34);
 fn_801EC5DC(sp38, 0x7a, lbl_805A4AD8 * e);
 fn_801EC1B8(sp38, sp8, sp8);
 fn_801EC8DC(sp8, sp8, lbl_805A4A5C, lbl_805A4ADC, lbl_805A4A34);
 fn_801EC868(sp8, sp8, a, b, lbl_805A4A38);
 fn_801F51DC(sp8, 0);
 fn_801F52E4(0);
 f31 = e;
 switch (arg0) {
 case 0: f31 = lbl_805A4AE0; v31 = 0x100; arg0 = 0; break;
 case 2: f31 = lbl_805A4AE4; v31 = 0x100; arg0 = 0; break;
 case 1: f31 = lbl_805A4A38; v31 = 0; arg0 = 0x100; break;
 }
 GXBegin(0x80, 0, 4);
 temp = lbl_805A4A70 + (double)f31;
 f = (float)temp;
 WGPIPE.f = f; WGPIPE.f = lbl_805A4AE0; WGPIPE.ui = 0xff; WGPIPE.us = v31; WGPIPE.us = 0;
 WGPIPE.f = f; WGPIPE.f = lbl_805A4AE8; WGPIPE.ui = 0xff; WGPIPE.us = v31; WGPIPE.us = 0x100;
 WGPIPE.f = f31; WGPIPE.f = lbl_805A4AE8; WGPIPE.ui = 0xff; WGPIPE.us = arg0; WGPIPE.us = 0x100;
 WGPIPE.f = f31; WGPIPE.f = lbl_805A4AE0; WGPIPE.ui = 0xff; WGPIPE.us = arg0; WGPIPE.us = 0;
}