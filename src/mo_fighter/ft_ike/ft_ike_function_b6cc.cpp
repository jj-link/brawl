#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

#pragma dont_inline on
extern "C" void fn_119_B6CC(Vec2f& object, const Vec2f& value) {
    object.m_x = value.m_x;
    object.m_y = value.m_y;
}
#pragma dont_inline reset
