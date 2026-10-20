#pragma force_active on
struct Sub {
    char pad[0xa8];
    void* m_a8;
};

struct Holder {
    char pad[0x18];
    Sub* m_18;
};

extern Holder lbl_27_bss_3210[];

extern "C" {
void* fn_27_147EFC() {
    return lbl_27_bss_3210->m_18->m_a8;
}
}
