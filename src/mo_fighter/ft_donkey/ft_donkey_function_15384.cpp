#include <types.h>
#pragma force_active on

struct Vec3f {
    float m_x, m_y, m_z;
};

extern "C" void fn_92_15384(Vec3f* dst, const Vec3f* src) {
    dst->m_x = src->m_x;
    dst->m_y = src->m_y;
    dst->m_z = src->m_z;
}
