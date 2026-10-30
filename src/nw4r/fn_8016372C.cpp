#include <nw4r/math/math_types.h>
#include <nw4r/math/math_geometry.h>
#pragma force_active on

extern float lbl_805A2C5C;

extern "C" s32 fn_8016372C(const void* arg0, const void* arg1) {
    const u8* a = (const u8*)arg0;
    const u8* b = (const u8*)arg1;

    const nw4r::math::VEC3* aMin = (const nw4r::math::VEC3*)(a + 0x78);
    const nw4r::math::VEC3* aMax = (const nw4r::math::VEC3*)(a + 0x84);
    const nw4r::math::VEC3* bMin = (const nw4r::math::VEC3*)(b + 0x0);
    const nw4r::math::VEC3* bMax = (const nw4r::math::VEC3*)(b + 0xc);

    s32 r0;
    if (bMin->x > aMax->x || aMin->x > bMax->x ||
        bMin->y > aMax->y || aMin->y > bMax->y ||
        bMin->z > aMax->z || aMin->z > bMax->z) {
        r0 = 0;
    } else {
        r0 = 1;
    }
    if (r0 == 0) {
        return 0;
    }

    const u8* o = a;
    nw4r::math::PLANE* pl = (nw4r::math::PLANE*)(o + 0x90);
    s32 result = 1;
    for (int i = 0; i < 6; i++) {
        const nw4r::math::VEC3* n = (const nw4r::math::VEC3*)(o + 0x90);
        nw4r::math::VEC3 cf;
        nw4r::math::VEC3 cs;

        if (n->x >= lbl_805A2C5C) {
            cf.x = bMin->x;
            cs.x = bMax->x;
        } else {
            cf.x = bMax->x;
            cs.x = bMin->x;
        }
        if (n->y >= lbl_805A2C5C) {
            cf.y = bMin->y;
            cs.y = bMax->y;
        } else {
            cf.y = bMax->y;
            cs.y = bMin->y;
        }
        if (n->z >= lbl_805A2C5C) {
            cf.z = bMin->z;
            cs.z = bMax->z;
        } else {
            cf.z = bMax->z;
            cs.z = bMin->z;
        }

        f32 v = pl->Test(cf);
        if (v > lbl_805A2C5C) {
            return 0;
        }
        f32 v2 = pl->Test(cs);
        if (v2 > lbl_805A2C5C) {
            result = 2;
        }

        o = (const u8*)(o + 0x10);
        pl = (nw4r::math::PLANE*)((const u8*)pl + 0x10);
    }
    return result;
}
