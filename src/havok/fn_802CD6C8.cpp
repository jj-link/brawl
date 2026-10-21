#pragma force_active on

struct Obj {
    char* m_00;
    char m_04[2];
    short m_06;
    char* m_08;
    char* m_0c;
    char* m_10;
    char* m_14;
};

extern "C" {
extern char lbl_80487320[];

void fn_802CD6C8(Obj* p) {
    if (p != 0) {
        p->m_06 = 1;
        p->m_00 = lbl_80487320;
        p->m_08 = lbl_80487320 + 0x10;
        p->m_0c = lbl_80487320 + 0x20;
        p->m_10 = lbl_80487320 + 0x30;
        p->m_14 = lbl_80487320 + 0x40;
    }
}
}
