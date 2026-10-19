#pragma force_active on
struct Vec3fCopy {
    float m_x;
    float m_y;
    float m_z;
};

extern "C" void fn_93_F174(Vec3fCopy* dst, const Vec3fCopy* src) {
    dst->m_x = src->m_x;
    dst->m_y = src->m_y;
    dst->m_z = src->m_z;
}
