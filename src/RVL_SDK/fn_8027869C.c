#include <revolution/GX.h>
#include <revolution/MTX/mtx.h>
#pragma force_active on

extern void fn_801EC158(void*);
extern void fn_801F51DC(const void*, unsigned int);
extern void fn_801F52E4(int);
extern void fn_801EFB10(void);
extern void fn_801EF280(int, int);
extern void fn_801EFB44(int, int, int, int, int);
extern void fn_801F3C30(int, int, int, int, int);
extern void fn_801F3CB0(int, int, int, int, int, int);
extern void fn_801F3C70(int, int, int, int, int);
extern void fn_801F3D08(int, int, int, int, int, int);
extern void fn_801F4748(int);
extern void fn_801F1D10(int);
extern void fn_801F3F5C(int, int, int, int, int);
extern void fn_801F3F20(int, int, int);

void fn_8027869C(void)
{
    Mtx m;

    fn_801EC158(m);
    fn_801F51DC(m, 0);
    fn_801F52E4(0);
    fn_801EFB10();
    fn_801EF280(9, 1);
    fn_801EFB44(0, 9, 0, 4, 0);
    GXSetNumChans(1);
    GXSetChanCtrl(4, 0, 0, 0, 0, 0, 2);
    GXSetChanCtrl(5, 0, 0, 0, 0, 0, 2);
    GXSetNumTexGens(0);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0xFF, 0xFF, 0xFF);
    fn_801F3C30(0, 0xF, 0xF, 0xF, 2);
    fn_801F3CB0(0, 0, 0, 0, 1, 0);
    fn_801F3C70(0, 7, 7, 7, 1);
    fn_801F3D08(0, 0, 0, 0, 1, 0);
    GXSetAlphaCompare(7, 0, 1, 7, 0);
    GXSetBlendMode(1, 4, 5, 5);
    fn_801F4748(0);
    GXSetZMode(0, 7, 0);
    fn_801F1D10(0);
    GXSetNumIndStages(0);
    fn_801F3F5C(0, 0, 1, 2, 3);
    fn_801F3F20(0, 0, 0);
    GXSetCullMode(0);
}
