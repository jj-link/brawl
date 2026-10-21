#pragma force_active on

struct fn_80204EB4Work {
    unsigned int m_00;
    unsigned int m_04;
    unsigned short m_08;
    unsigned short m_0A;
};

void fn_80204EB4(struct fn_80204EB4Work* p, unsigned short val) {
    p->m_0A = val;
    p->m_00 = 0;
    p->m_04 = 0;
    p->m_08 = 0;
}
