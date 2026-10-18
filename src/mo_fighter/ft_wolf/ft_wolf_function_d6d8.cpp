#pragma force_active on
struct Vec2f {
    float m_x;
    float m_y;
};

extern "C" void fn_125_D6D8(Vec2f* dst, const Vec2f* src) {
    dst->m_x = src->m_x;
    dst->m_y = src->m_y;
}
