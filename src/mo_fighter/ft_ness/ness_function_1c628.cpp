#include <mt/mt_vector.h>
#pragma force_active on

extern "C" Vec3f* fn_101_1C628(Vec3f* destination, const Vec3f* source)
{
    destination->m_x = source->m_x;
    destination->m_y = source->m_y;
    destination->m_z = source->m_z;
    return destination;
}
