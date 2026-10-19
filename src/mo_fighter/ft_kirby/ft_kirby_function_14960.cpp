#pragma force_active on
struct Vec3f {
    float m_x;
    float m_y;
    float m_z;
};

extern "C" void fn_96_14960(Vec3f* dst, const Vec3f* src) {
    dst->m_x = src->m_x;
    dst->m_y = src->m_y;
    dst->m_z = src->m_z;
}
