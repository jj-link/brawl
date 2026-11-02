#include <revolution/GX/GXGeometry.h>
#include <revolution/GX/GXVert.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_801ECD70(void*, void*, void*);

void fn_8017A4E0(void* arg0, void* arg1, s32 arg2) {
    f32 v0[3], v1[3], v2[3], v3[3];

    fn_801ECD70(arg0, arg1, v0);
    fn_801ECD70(arg0, (u8*)arg1 + 0xC, v1);
    fn_801ECD70(arg0, (u8*)arg1 + 0x18, v2);
    fn_801ECD70(arg0, (u8*)arg1 + 0x24, v3);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    {
        f32 z0 = v0[2];
        f32 y0 = v0[1];
        f32 x0 = v0[0];
        GXPosition3f32(x0, y0, z0);
    }
    if (arg2 != 0) {
        GXPosition1x8(0);
    }
    {
        f32 z1 = v1[2];
        f32 y1 = v1[1];
        f32 x1 = v1[0];
        GXPosition3f32(x1, y1, z1);
    }
    if (arg2 != 0) {
        GXPosition1x8(1);
    }
    {
        f32 z2 = v2[2];
        f32 y2 = v2[1];
        f32 x2 = v2[0];
        GXPosition3f32(x2, y2, z2);
    }
    if (arg2 != 0) {
        GXPosition1x8(2);
    }
    {
        f32 z3 = v3[2];
        f32 y3 = v3[1];
        f32 x3 = v3[0];
        GXPosition3f32(x3, y3, z3);
    }
    if (arg2 != 0) {
        GXPosition1x8(3);
    }
}
}
