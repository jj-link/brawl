#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

// Placeholder layout: the owning object type is not identified.
// The function copies a Vec3f from *src into the object at offset 0x1e8.
struct StFn67Object {
    u8 pad_000[0x1e8];
    Vec3f m_vec1e8;
};

// Scheduling is disabled so each lfs/stfs pair stays adjacent, as in the original.
#pragma scheduling off
extern "C" void fn_67_148C(StFn67Object* object, const Vec3f* src) {
    object->m_vec1e8.m_x = src->m_x;
    object->m_vec1e8.m_y = src->m_y;
    object->m_vec1e8.m_z = src->m_z;
}
#pragma scheduling reset
