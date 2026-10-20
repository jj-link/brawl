#pragma force_active on
struct Inner {
    char pad[0x130];
    void* m130;
};

struct Outer {
    char pad[0x3c];
    Inner* m3c;
};

extern Outer lbl_27_bss_3210;

extern "C" void* fn_27_147C24() {
    return lbl_27_bss_3210.m3c->m130;
}
