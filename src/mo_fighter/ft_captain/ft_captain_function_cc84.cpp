#include <mt/mt_vector.h>
#pragma force_active on

// Builds a rotation/axis vector: writes the three components straight into the
// caller's storage (f1 -> m_x, f2 -> m_y, f3 -> m_z) and hands the vector back.
extern "C" Vec3f* fn_100_CC84(Vec3f* vec, float x, float y, float z)
{
    vec->m_x = x;
    vec->m_y = y;
    vec->m_z = z;
    return vec;
}
