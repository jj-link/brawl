#include <types.h>
#pragma force_active on

struct Vec2f {
    f32 m_x;
    f32 m_y;
};

extern "C" void fn_113_B7F0(Vec2f* dst, const Vec2f* src) {
    dst->m_x = src->m_x;
    dst->m_y = src->m_y;
}
