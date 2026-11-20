#include <gf/gf_camera.h>
#include <revolution/GX/GXTypes.h>
#include <revolution/GX/GXGeometry.h>
#include <revolution/GX/GXPixel.h>
#include <revolution/GX/GXTev.h>
#include <revolution/GX/GXVert.h>
#include <types.h>
#pragma force_active on

void gfDrawSetVtxPosColorPrimEnvironment();
extern f32 lbl_805A17B8;
extern f32 lbl_805A17A8;

extern "C" void fn_80041104(gfCameraManager* arg0, u32* arg1, s32 arg2, f32 farg0) {
    f32* v = (f32*)arg0;
    ((gfCamera*)gfCameraManager::getManager())->setGX();
    u32 color = *arg1;
    gfDrawSetVtxPosColorPrimEnvironment();
    if (arg2 != 0) {
        GXSetZMode(1, GX_LEQUAL, 0);
    } else {
        GXSetZMode(0, GX_LEQUAL, 0);
    }
    GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
    GXSetLineWidth((u8)(lbl_805A17B8 * farg0), 2);
    GXBegin(GX_LINES, GX_VTXFMT1, 2);
    f32 x0 = v[0];
    f32 y0 = v[1];
    WGPIPE.f = x0;
    f32 x1 = v[2];
    WGPIPE.f = y0;
    y0 = lbl_805A17A8;
    f32 y1 = v[3];
    WGPIPE.f = y0;
    WGPIPE.ui = color;
    WGPIPE.f = x1;
    WGPIPE.f = y1;
    WGPIPE.f = lbl_805A17A8;
    WGPIPE.ui = color;
}