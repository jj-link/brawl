#pragma force_active on
struct fn_27_291D7C_struct
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08_a : 9;
    unsigned int m_08_b : 1;
    unsigned int m_08_c : 22;
};

extern "C" int fn_27_291D7C(fn_27_291D7C_struct* p)
{
    return p->m_08_b;
}
