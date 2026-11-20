#include <types.h>
#include <revolution/GX.h>
#include <gf/gf_draw.h>

#pragma force_active on
extern "C" {
void fn_801F3AFC(int);
void fn_801F256C(int, GXColor*);
void fn_801F2494(int, GXColor*, u8, u8, u8);

void fn_8001025C(GXColor* arg) {
    GXColor c0;
    GXColor c1;
    u8 t3, t2, t1, t0;

    GXSetNumTexGens(0);
    GXSetTevOp((GXTevStageID)0, (GXTevMode)4);
    GXSetTevOrder((GXTevStageID)0, (GXTexCoordID)255, (GXTexMapID)255, (GXChannelID)4);
    fn_801F3AFC(0);
    GXSetNumTevStages(1);
    GXSetNumIndStages(0);
    GXSetChanCtrl((GXChannelID)4, 0, (GXColorSrc)0, (GXColorSrc)0, (GXLightID)0, (GXDiffuseFn)0, (GXAttnFn)2);
    GXSetChanCtrl((GXChannelID)5, 0, (GXColorSrc)0, (GXColorSrc)0, (GXLightID)0, (GXDiffuseFn)0, (GXAttnFn)2);
    t0 = arg->r;
    t1 = arg->g;
    t2 = arg->b;
    t3 = arg->a;
    c0.r = t0;
    c0.g = t1;
    c0.b = t2;
    c0.a = t3;
    fn_801F256C(4, &c0);
    t2 = arg->r;
    t1 = arg->g;
    t0 = arg->b;
    t3 = arg->a;
    c1.r = t2;
    c1.g = t1;
    c1.b = t0;
    c1.a = t3;
    fn_801F2494(4, &c1, t0, t1, t2);
    GXSetNumChans(1);
    GXSetZMode(1, (GXCompare)3, 1);
    GXSetBlendMode((GXBlendMode)0, (GXBlendFactor)0, (GXBlendFactor)0, (GXLogicOp)3);
    gfDrawResetLight();
}
}
