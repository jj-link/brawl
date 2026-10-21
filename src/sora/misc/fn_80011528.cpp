#pragma force_active on

struct DstObj {
    char pad_00[0x1C];
    unsigned char m_1C;
    char pad_1D[0x48 - 0x1D];
    float m_48;
    float m_4C;
    float m_50;
};

struct SrcObj {
    float m_00;
    float m_04;
};

extern "C" void fn_80011528(DstObj* dst, const SrcObj* src, float f) {
    dst->m_48 = src->m_00;
    dst->m_4C = src->m_04;
    dst->m_50 = f;
    dst->m_1C |= 0x20;
}
