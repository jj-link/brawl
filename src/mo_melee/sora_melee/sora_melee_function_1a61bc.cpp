#pragma force_active on
extern char lbl_27_data_34400[];

struct fn_27_1A61BC_work {
    void* m_0;
    void* m_4;
    unsigned int m_8;
};

extern "C" {
void fn_27_1A61BC(fn_27_1A61BC_work* p)
{
    char* base = lbl_27_data_34400;
    p->m_0 = base;
    p->m_4 = base + 0x48;
    p->m_8 = p->m_8 & 1;
}
}
