#include <revolution/GX.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/MTX/mtx.h>
#pragma force_active on

extern void fn_801EFB10(void);
extern void fn_801EF280(int, int);
extern void fn_801EFB44(int, int, int, int, int);
extern void fn_801EC834(Mtx, float, float, float);
extern void fn_801F51DC(const void*, unsigned int);
extern const float lbl_805A3B70;

void fn_80278D9C(unsigned char width, unsigned int* color, float x1, float y1, float x2, float y2, float z)
{
    Mtx m;
    fn_801EFB10();
    fn_801EF280(9, 1);
    fn_801EF280(11, 1);
    fn_801EFB44(0, 9, 1, 4, 0);
    fn_801EFB44(0, 11, 1, 5, 0);
    GXSetCullMode(0);
    GXSetNumChans(1);
    GXSetChanCtrl(4, 0, 1, 1, 0, 0, 2);
    GXSetNumTexGens(0);
    GXSetNumTevStages(1);
    GXSetTevOp(0, 4);
    GXSetTevOrder(0, 255, 255, 4);
    GXSetBlendMode(0, 0, 0, 5);
    fn_801EC834(m, lbl_805A3B70, lbl_805A3B70, lbl_805A3B70);
    fn_801F51DC(m, 0);
    GXSetLineWidth(width, 0);
    GXBegin(0xA8, 0, 2);
    WGPIPE.f = x1;
    WGPIPE.f = y1;
    WGPIPE.f = z;
    WGPIPE.ui = *color;
    WGPIPE.f = x2;
    WGPIPE.f = y2;
    WGPIPE.f = z;
    WGPIPE.ui = *color;
}