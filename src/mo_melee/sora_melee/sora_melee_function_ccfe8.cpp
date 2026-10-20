#pragma force_active on
struct fn_27_Obj {
    unsigned int m_0;
    unsigned int m_4;
    unsigned int m_flags_hi : 3;
    unsigned int m_flags_lo : 29;
};

extern "C" {
void fn_27_CCFE8(fn_27_Obj* p, unsigned int v) {
    p->m_flags_hi = v;
}
}
