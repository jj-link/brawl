#pragma force_active on
struct Sub {
    char pad[0x98];
    void* m_98;
};

struct Entry {
    char pad[0xd8];
    Sub* m_d8;
};

extern Entry lbl_27_bss_3210[];

extern "C" {
void* fn_27_1498D8() {
    return lbl_27_bss_3210[0].m_d8->m_98;
}
}
