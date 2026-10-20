#pragma force_active on
struct Sub {
    char pad[0xa4];
    int m_a4;
};

struct Holder {
    char pad[0x138];
    Sub* m_138;
};

extern "C" {
extern Holder lbl_27_bss_3210;

int fn_27_148F10() {
    return lbl_27_bss_3210.m_138->m_a4;
}
}
