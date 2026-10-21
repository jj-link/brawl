#pragma force_active on
struct fn_8015BF9CWork {
    unsigned int m_00;
    unsigned int m_04;
    unsigned short m_08;
    unsigned short m_0A;
};

extern "C" void fn_8015BF9C(fn_8015BF9CWork* p, short arg1) {
    p->m_0A = arg1;
    p->m_00 = 0;
    p->m_04 = 0;
    p->m_08 = 0;
}
