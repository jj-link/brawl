#pragma force_active on
typedef struct fn_80390014_Obj {
    char pad[0x7C4];
    int m_7C4;
    int m_7C8;
    int m_7CC;
    int m_7D0;
    int m_7D4;
    int m_7D8;
    int m_7DC;
    int m_7E0;
    int m_7E4;
} fn_80390014_Obj;

void fn_80390014(fn_80390014_Obj* p) {
    p->m_7D4 = 0;
    p->m_7D8 = 0;
    p->m_7C4 = 0;
    p->m_7C8 = 0;
    p->m_7CC = 0;
    p->m_7D0 = -1;
    p->m_7DC = 0;
    p->m_7E0 = 0;
    p->m_7E4 = 0;
}
