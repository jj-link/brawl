#pragma force_active on
struct FooWork {
    void* m_00;
    short m_04;
    short m_06;
    char* m_08;
    char* m_0c;
    char* m_10;
    char* m_14;
    int m_18;
    int values[32];
};

extern "C" {
extern char lbl_804872B8[];

void fn_802CD0B0(FooWork* p) {
    p->m_06 = 1;
    p->m_00 = lbl_804872B8;
    p->m_08 = lbl_804872B8 + 0x10;
    p->m_0c = lbl_804872B8 + 0x20;
    p->m_10 = lbl_804872B8 + 0x30;
    p->m_14 = lbl_804872B8 + 0x40;
    for (int i = 0; i < 32; ++i) {
        p->values[i] = -1;
    }
    p->m_18 = 0;
}
}
