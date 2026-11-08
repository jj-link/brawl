#include <mt/mt_vector.h>
#pragma force_active on
extern "C" void fn_80162B40(Vec3f* out, const float* mat, const Vec3f* v) {
    Vec3f tmp;
    tmp.m_x = (mat[2] * v->m_z) + ((mat[0] * v->m_x) + (mat[1] * v->m_y));
    tmp.m_y = (mat[6] * v->m_z) + ((mat[4] * v->m_x) + (mat[5] * v->m_y));
    tmp.m_z = (mat[10] * v->m_z) + ((mat[8] * v->m_x) + (mat[9] * v->m_y));
    *out = tmp;
}