#include <revolution/GX.h>
#pragma force_active on

extern "C" {
void fn_801F52E4(int);
void fn_801F55EC(int);
void fn_801F3AFC(int);
void fn_801F256C(int, GXColor);
void fn_801F2494(int, GXColor);
void fn_801EFB10();
void fn_801EF280(int, int);
void fn_801EFB44(int, int, int, int, int);
extern float lbl_805A1460;
extern float lbl_805A1464;
extern float lbl_805A1468;

void gfDrawSetVtxPosColorTexPrimEnvironment__Fv() {
    GXColor color;
    fn_801F52E4(0);
    fn_801F55EC(0);
    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 255;
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 60, 0, 125);
    GXSetNumTexGens(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
    GXSetNumTevStages(1);
    fn_801F3AFC(0);
    GXSetNumIndStages(0);
    GXSetNumChans(1);
    GXSetChanCtrl(GX_COLOR0A0, 0, GX_SRC_REG, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetChanCtrl(GX_COLOR1A1, 0, GX_SRC_REG, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    fn_801F256C(4, color);
    fn_801F2494(4, color);
    GXSetZMode(1, GX_ALWAYS, 0);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    fn_801EFB10();
    fn_801EF280(9, 1);
    fn_801EF280(11, 1);
    fn_801EF280(13, 1);
    fn_801EFB44(1, 9, 1, 4, 0);
    fn_801EFB44(1, 11, 1, 5, 0);
    fn_801EFB44(1, 13, 1, 4, 0);
    color.b = 0;
    color.g = 0;
    color.r = 0;
    GXSetFog(GX_FOG_NONE, color, lbl_805A1460, lbl_805A1464, lbl_805A1468, lbl_805A1464);
}
}