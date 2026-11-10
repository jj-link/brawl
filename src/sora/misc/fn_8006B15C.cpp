#include <types.h>
#define GXSetLineWidth GXSetLineWidth_decl
#include <revolution/GX.h>
#pragma force_active on
#undef GXSetLineWidth
extern "C" {
void GXSetLineWidth(int, int);
void fn_801EFB44(int, int, int, int, int);
void fn_801EFB10(void);
void fn_801EF280(int, int);
void drawBoxLine__7MessageFlllfffff(long color, long width, long depth, float x0, float y0, float x1, float y1, float z) {
 GXSetNumTexGens(0);
 GXSetNumChans(1);
 GXSetNumTevStages(1);
 GXSetChanCtrl((GXChannelID)4, 0, (GXColorSrc)0, (GXColorSrc)1, (GXLightID)0, (GXDiffuseFn)0, (GXAttnFn)2);
 GXSetTevOrder((GXTevStageID)0, (GXTexCoordID)255, (GXTexMapID)255, (GXChannelID)4);
 GXSetTevOp((GXTevStageID)0, (GXTevMode)4);
 GXSetBlendMode((GXBlendMode)1, (GXBlendFactor)4, (GXBlendFactor)5, (GXLogicOp)15);
 if (depth) GXSetZMode(1, (GXCompare)7, 1);
 fn_801EFB44(0,9,1,4,0);
 fn_801EFB44(0,11,1,5,0);
 fn_801EFB10();
 fn_801EF280(9,1);
 fn_801EF280(11,1);
 if (width) {
 GXSetLineWidth(width, 0);
 GXBegin((GXPrimitive)0xB0, (GXVtxFmt)0, 5);
 GXPosition3f32(x0,y0,z); GXColor1u32(color);
 GXPosition3f32(x1,y0,z); GXColor1u32(color);
 GXPosition3f32(x1,y1,z); GXColor1u32(color);
 GXPosition3f32(x0,y1,z); GXColor1u32(color);
 GXPosition3f32(x0,y0,z); GXColor1u32(color);
 } else {
 GXBegin((GXPrimitive)0x80, (GXVtxFmt)0, 4);
 GXPosition3f32(x0,y0,z); GXColor1u32(color);
 GXPosition3f32(x1,y0,z); GXColor1u32(color);
 GXPosition3f32(x1,y1,z); GXColor1u32(color);
 GXPosition3f32(x0,y1,z); GXColor1u32(color);
 }
}
}