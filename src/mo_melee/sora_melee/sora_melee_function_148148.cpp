#pragma force_active on
struct Sub {
    char pad[0x98];
    void* f98;
};

struct Entry {
    char pad[0x54];
    Sub* p54;
    char rest[0x298 - 0x58];
};

extern Entry lbl_27_bss_3210[];

extern "C" {
void* fn_27_148148() {
    return lbl_27_bss_3210->p54->f98;
}
}
