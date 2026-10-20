#pragma force_active on
struct FnState {
    void* m_data;
    void* m_cur;
    unsigned int m_flags;
};

extern "C" {
extern unsigned char lbl_27_data_33F28[0x90];

void fn_27_1A66D0(FnState* p) {
    p->m_data = lbl_27_data_33F28;
    p->m_cur = lbl_27_data_33F28 + 0x48;
    p->m_flags &= 1;
}
}
