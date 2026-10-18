#include <mt/mt_vector.h>
#pragma force_active on

extern "C" void fn_110_B860(Vec2f* dst, const Vec2f* src)
{
    dst->m_x = src->m_x;
    dst->m_y = src->m_y;
}
