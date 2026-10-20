#pragma force_active on
struct Inner {
    char pad[0xa0];
    void* m_a0;
};

struct Entry {
    char pad[0x138];
    Inner* m_138;
};

extern Entry lbl_27_bss_3210[];

extern "C" void* fn_27_148EFC() {
    return lbl_27_bss_3210->m_138->m_a0;
}
