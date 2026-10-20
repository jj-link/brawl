#pragma force_active on
extern "C" {
extern char lbl_27_data_3BA20[];
}

struct Fn27Iface {
    void *m_00;
    void *m_04;
    unsigned int m_08;
};

extern "C" void fn_27_198148(Fn27Iface *p) {
    p->m_00 = lbl_27_data_3BA20;
    p->m_04 = lbl_27_data_3BA20 + 0x48;
    p->m_08 = p->m_08 & 0x7FFFF;
}
