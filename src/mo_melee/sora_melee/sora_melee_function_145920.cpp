#pragma force_active on
struct Entry {
    int m_0;
    int m_4[1];
    int m_8;
};

extern Entry lbl_27_bss_3210[];

extern "C" void fn_27_145920(int kind) {
    lbl_27_bss_3210[kind].m_0 = 0;
    lbl_27_bss_3210[kind].m_4[0] = 0;
    lbl_27_bss_3210[kind].m_8 = 0;
}
