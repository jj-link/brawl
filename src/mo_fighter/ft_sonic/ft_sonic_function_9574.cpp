#pragma force_active on
struct Vec2 {
    float m_x;
    float m_y;
};

extern "C" void fn_123_9574(Vec2& dst, const Vec2& src)
{
    dst.m_x = src.m_x;
    dst.m_y = src.m_y;
}
