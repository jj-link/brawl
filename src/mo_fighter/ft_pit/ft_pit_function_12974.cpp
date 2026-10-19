#pragma force_active on
extern "C" {

struct PitFloats
{
    float m_x;
    float m_y;
    float m_z;
};

void fn_112_12974(PitFloats* dst, const PitFloats* src)
{
    dst->m_x = src->m_x;
    dst->m_y = src->m_y;
    dst->m_z = src->m_z;
}

}
