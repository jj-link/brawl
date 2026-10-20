#pragma force_active on
struct Inner {
    char pad[0x8c];
    void* m_8c;
};

struct Outer {
    char pad[0x120];
    Inner* m_120;
};

extern "C" {
    extern Outer lbl_27_bss_3210;
}

extern "C" void* fn_27_148BBC() {
    return lbl_27_bss_3210.m_120->m_8c;
}
