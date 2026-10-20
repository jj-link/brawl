#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern char lbl_27_data_17E50[];

struct FooWork {
    s32 m_00;
    char* m_04;
    char* m_08;
    u32 m_0c;
};

extern "C" {
void fn_27_C4134(FooWork* p)
{
    u32 c = p->m_0c;
    char* base = lbl_27_data_17E50;
    p->m_00 = -1;
    p->m_04 = base;
    p->m_08 = base + 0x48;
    p->m_0c = c & 0x1FFF;
}
}
