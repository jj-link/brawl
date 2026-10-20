#pragma force_active on
struct Inner {
    char pad[0x8c];
    void* m_8c;
};

struct Outer {
    char pad[0x150];
    Inner* m_150;
};

extern "C" {
extern Outer lbl_27_bss_3210;

void* fn_27_148308() {
    return lbl_27_bss_3210.m_150->m_8c;
}
}
