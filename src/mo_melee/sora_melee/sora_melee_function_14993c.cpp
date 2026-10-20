#pragma force_active on
struct Sub {
    char pad[0xac];
    int v;
};

struct Entry {
    char pad[0xd8];
    Sub* s;
};

extern Entry lbl_27_bss_3210[];

extern "C" {
int fn_27_14993C() {
    return lbl_27_bss_3210[0].s->v;
}
}
