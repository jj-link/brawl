#pragma force_active on
class Src {
public:
    char pad[0x70];
    float m_70;
    float m_74;
    float m_78;
    float m_7c;
    float m_80;
    float m_84;
    float m_88;
    float m_8c;
};

extern "C" void fn_802E802C(Src* src, float* dst)
{
    dst[0] = src->m_70;
    dst[1] = src->m_74;
    dst[2] = src->m_78;
    dst[3] = src->m_7c;
    dst[4] = src->m_80;
    dst[5] = src->m_84;
    dst[6] = src->m_88;
    dst[7] = src->m_8c;
}
