#include <st/st_utility.h>
#pragma force_active on

struct RD {
    float f[10];
};

extern "C" const RD lbl_81_rodata_0;
extern "C" void* fn_27_222878(void*, unsigned int);

struct Ent {
    float x;
    float y;
    float z;
    char pad[0x3c - 12];
};

struct Obj {
    char pad[0x378];
    Ent e[4];
};

inline void init(Vec3f& v, float y, float x, float z) {
    v.m_x = x;
    v.m_y = y;
    v.m_z = z;
}

extern "C" void fn_81_37E0(Obj* obj, Vec3f* a, Vec3f* b, int idx) {
    const float* r = (const float*)&lbl_81_rodata_0 + 8;
    Vec3f start;
    init(start, r[0], obj->e[idx].x, obj->e[idx].z);
    Vec3f dir;
    dir.m_x = r[-8];
    dir.m_y = r[1];
    dir.m_z = r[-8];
    stRayCheck(&start, &dir, a, b, true,
               (grCollision*)fn_27_222878(obj, 0), false, 1);
}
