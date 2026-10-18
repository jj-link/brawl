#include <mt/mt_vector.h>
#pragma force_active on

extern "C" Vec2f& fn_112_CC3C(Vec2f& object, const Vec2f& value) {
    object.m_x = value.m_x;
    object.m_y = value.m_y;
    return object;
}
