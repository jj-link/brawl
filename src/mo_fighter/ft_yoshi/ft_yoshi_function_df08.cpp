#pragma force_active on
extern "C" {
struct Vec2f_95 {
    float m_x;
    float m_y;
};

void fn_95_DF08(Vec2f_95* dst, const Vec2f_95* src) {
    dst->m_x = src->m_x;
    dst->m_y = src->m_y;
}
}
