#pragma force_active on
struct Unk30 {
    unsigned char pad_0[0x30];
    unsigned char flag_30;
    unsigned char pad_31[0xE0 - 0x31];
    int m_E0;
};

struct Mngr {
    char pad_0[0x78];
    Unk30* m_78;
};

extern "C" void fn_80105240(Unk30*);

extern "C" void fn_800DCE54(Mngr* mgr, int value) {
    Unk30* p = mgr->m_78;
    p->m_E0 = value;
    if (p->flag_30 != 0)
        fn_80105240(p);
}
