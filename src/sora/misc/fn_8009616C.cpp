#define GXSetFog GXSetFog_decl
#include <revolution/GX.h>
#pragma force_active on
#undef GXSetFog
extern "C" void GXSetFog(int, unsigned char*, float, float, float, float);

extern "C" {
void fn_801A12AC(unsigned int);
void fn_801EFB10();
void fn_801EFB44(int, int, int, int, int);
void fn_801F471C(int);
void fn_801F4748(int);
void fn_801EF280(int, int);
void fn_801F52E4(int);
extern unsigned char lbl_805A1D08, lbl_805A1D09, lbl_805A1D0A, lbl_805A1D0B;
extern float lbl_805A1D0C, lbl_805A1D10, lbl_805A1D14;

void fn_8009616C() {
    fn_801A12AC(0x7ff);
    fn_801EFB10();
    fn_801EFB44(1, 9, 1, 4, 0);
    fn_801EFB44(1, 11, 1, 5, 0);
    fn_801F471C(1);
    fn_801F4748(0);
    GXSetBlendMode((GXBlendMode)1, (GXBlendFactor)4, (GXBlendFactor)5, (GXLogicOp)5);
    GXSetAlphaCompare((GXCompare)4, 0, (GXAlphaOp)0, (GXCompare)4, 0);
    GXSetZMode(1, (GXCompare)3, 1);
    GXSetZCompLoc(0);
    GXSetNumTexGens(0);
    GXSetNumTevStages(1);
    GXSetTevOrder((GXTevStageID)0, (GXTexCoordID)255, (GXTexMapID)255, (GXChannelID)4);
    GXSetTevOp((GXTevStageID)0, (GXTevMode)4);
    GXSetChanCtrl((GXChannelID)4, 0, (GXColorSrc)0, (GXColorSrc)1, (GXLightID)0, (GXDiffuseFn)0, (GXAttnFn)2);
    GXSetNumChans(1);
    GXSetCullMode((GXCullMode)0);
    unsigned char color[4];
    color[0] = lbl_805A1D08;
    color[1] = lbl_805A1D09;
    color[2] = lbl_805A1D0A;
    color[3] = lbl_805A1D0B;
    GXSetFog(0, color, lbl_805A1D0C, lbl_805A1D10, lbl_805A1D14, lbl_805A1D10);
    fn_801EF280(9, 1);
    fn_801EF280(11, 1);
    fn_801F52E4(0);
    GXSetLineWidth(6, 5);
}
}