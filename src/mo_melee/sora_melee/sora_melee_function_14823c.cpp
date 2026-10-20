#pragma force_active on
struct Inner {
    char pad[0x98];
    void* m_98;
};

struct Outer {
    char pad[0x15c];
    Inner* m_15c;
};

extern Outer lbl_27_bss_3210[];

extern "C" void* fn_27_14823C(void) {
    return lbl_27_bss_3210[0].m_15c->m_98;
}
