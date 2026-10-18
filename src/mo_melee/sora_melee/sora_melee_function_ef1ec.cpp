#pragma force_active on
struct UnkStruct {
    int m_0x0;
    int m_0x4;
    short m_0x8;
    short m_0xa;
};

extern "C" {
void fn_27_EF1EC(UnkStruct* p) {
    p->m_0x4 = -1;
    p->m_0x8 = 0;
    p->m_0xa = -1;
}
}
