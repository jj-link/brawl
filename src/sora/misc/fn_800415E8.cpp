#include <types.h>
#include <gf/gf_camera.h>
#include <gf/gf_draw.h>
#include <revolution/GX.h>
#include <revolution/GX/GXHardware.h>
#include <math.h>
#include <nw4r/ut/ut_Color.h>
#pragma force_active on
#pragma fp_contract off
extern const float lbl_805A17A8;
extern const float lbl_805A17C4;
extern const float lbl_805A17C8;
extern const float lbl_805A17CC;
extern "C" void fn_800415E8(float* arg, u32* color, u32 flag) {
    Vec3f points[18];
    ((gfCamera*)gfCameraManager::getManager())->setGX();
    float x0, y0;
    y0 = arg[1];
    x0 = arg[0];
    Vec3f center(x0, y0, lbl_805A17A8);
    u32 c = *color;
    Vec3f* pointPtr = points;
    points[0] = center;
    for (int i = 0; i < 16; ++i) {
        float angle = lbl_805A17C8 * (lbl_805A17C4 * (lbl_805A17CC * (float)i));
        float y = arg[1] + arg[2] * (float)sin(angle);
        float x = arg[0] + arg[2] * (float)cos(angle);
        Vec3f point(x, y, lbl_805A17A8);
        pointPtr[1] = point;
        ++pointPtr;
    }
    points[17] = points[1];
    gfDrawSetVtxPosColorPrimEnvironment();
    GXSetZMode(1, GX_LEQUAL, 0);
    GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
    GXBegin(GX_TRIANGLEFAN, GX_VTXFMT1, 18);
    for (int i = 0; i < 18; ++i) {
        GXPosition3f32(points[i].m_x, points[i].m_y, points[i].m_z);
        WGPIPE.ui = c;
    }
    if (flag == 1) {
        GXColor col;
        ((nw4r::ut::Color*)&col)->Set(255, 255, 255, 128);
        gfCameraManager::getManager();
    }
}