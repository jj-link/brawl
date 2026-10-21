#pragma force_active on
typedef signed int s32;

extern "C" {
extern char lbl_80488D58[];

struct Foo {
    char* m_00;
    short m_04;
    short m_06;
    char* m_08;
    char* m_0c;
    char* m_10;
    char* m_14;
    char* m_18;
};

void fn_8032BDE4(Foo* p) {
    if (p == 0) return;
    p->m_06 = 1;
    p->m_00 = lbl_80488D58;
    p->m_08 = lbl_80488D58 + 0x10;
    p->m_0c = lbl_80488D58 + 0x20;
    p->m_10 = lbl_80488D58 + 0x30;
    p->m_14 = lbl_80488D58 + 0x40;
    p->m_18 = lbl_80488D58 + 0x60;
}
}
