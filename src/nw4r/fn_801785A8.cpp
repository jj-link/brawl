#include <nw4r/math/math_types.h>
#include <revolution/GX/GXGeometry.h>
#include <revolution/GX/GXVert.h>
#pragma force_active on

extern "C" void fn_801785A8(const nw4r::math::VEC3* a, const nw4r::math::VEC3* b, const nw4r::math::VEC3* c, int flag) {
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    nw4r::math::VEC3 v0 = *a - *b;
    { float z = v0.z, y = v0.y, x = v0.x; GXPosition3f32(x, y, z); }
    if (flag) GXPosition1x8(0);
    nw4r::math::VEC3 v1 = *a - *c;
    { float z = v1.z, y = v1.y, x = v1.x; GXPosition3f32(x, y, z); }
    if (flag) GXPosition1x8(1);
    nw4r::math::VEC3 v2 = *a + *b;
    { float z = v2.z, y = v2.y, x = v2.x; GXPosition3f32(x, y, z); }
    if (flag) GXPosition1x8(2);
    nw4r::math::VEC3 v3 = *a + *c;
    { float z = v3.z, y = v3.y, x = v3.x; GXPosition3f32(x, y, z); }
    if (flag) GXPosition1x8(3);
}