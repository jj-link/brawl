#include <types.h>
#include <math.h>
#include <nw4r/math/math_arithmetic.h>
#include <mt/mt_vector.h>
#include <orch_helpers.h>
#include <gr/collision/gr_collision.h>
#pragma force_active on

extern "C" float rsqrtf__Ff(float);

bool stRayCheck(Vec3f* start, Vec3f* dir, Vec3f* hit, Vec3f* normal, bool flag,
                grCollision* coll, bool flag2, unsigned char mask);

extern "C" const float lbl_27_rodata_3C0[];

extern "C" float fn_27_2A578(void* arg0, Vec3f* pos, bool arg2, float f) {
    const float* k = lbl_27_rodata_3C0;
    Vec3f dir;
    Vec3f hit;
    Vec3f normal;

    if (f <= k[1]) {
        return k[3];
    }

    f = (f32)(double)nw4r::math::FAbs(f);

    dir.m_x = k[1];
    dir.m_z = k[1];
    dir.m_y = -f;

    if (!stRayCheck(pos, &dir, &hit, &normal, arg2, nullptr, false, 1)) {
        return k[3];
    }

    Vec3f delta;
    Vec3fSub_vb75923(&delta, pos, &hit);

    float len2 = delta.m_z * delta.m_z + (delta.m_x * delta.m_x + delta.m_y * delta.m_y);

    if ((f32)(double)nw4r::math::FAbs(len2) <= k[10]) {
        return k[1];
    }

    return len2 * rsqrtf__Ff(len2);
}
