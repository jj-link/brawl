#pragma force_active on
struct Inner {
    char pad[0x170];
    void* m_170;
};

struct Entry {
    char pad[0x3c];
    Inner* m_3c;
};

extern Entry lbl_27_bss_3210[];

extern "C" {
void* fn_27_147C88() {
    return lbl_27_bss_3210->m_3c->m_170;
}
}
