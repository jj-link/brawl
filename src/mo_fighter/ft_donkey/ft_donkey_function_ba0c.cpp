#pragma force_active on
struct Vec2fLocal {
    float m_x;
    float m_y;
};

extern "C" void fn_92_BA0C(Vec2fLocal* dst, const Vec2fLocal* src)
{
    dst->m_x = src->m_x;
    dst->m_y = src->m_y;
}
