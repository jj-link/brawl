#pragma force_active on
struct Vec2fCopyDst {
    unsigned int header[2];
    float m_x;
    float m_y;
};

struct Vec2fCopySrc {
    float m_x;
    float m_y;
};

extern "C" void fn_110_16DF8(Vec2fCopyDst* dst, const Vec2fCopySrc* src) {
    dst->m_x = src->m_x;
    dst->m_y = src->m_y;
}
