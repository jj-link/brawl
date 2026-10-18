#pragma force_active on
struct UnkStruct {
    char pad[4];
    int m_4;
    unsigned short m_8;
    short m_a;
};

extern "C" void fn_27_C4690(UnkStruct* p) {
    p->m_4 = -1;
    p->m_8 = 0;
    p->m_a = -1;
}
