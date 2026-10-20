#pragma force_active on
struct F {
    char _11C[0x11C];
    bool m_flag;
    char _11D[3];
};

extern "C" void fn_27_25BDCC(F* p) {
    p->m_flag = true;
}
