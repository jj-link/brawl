#include <mt/mt_vector.h>
#pragma force_active on

extern "C" void fn_121_F12C(Vec3f* dst, const Vec3f* src) {
    dst->m_x = src->m_x;
    dst->m_y = src->m_y;
    dst->m_z = src->m_z;
}
