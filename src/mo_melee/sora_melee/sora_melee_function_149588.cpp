#pragma force_active on
struct Inner {
    char pad[0xa4];
    void* v;
};

struct Outer {
    char pad[0x18c];
    Inner* p;
};

extern char lbl_27_bss_3210[];

extern "C" {
void* fn_27_149588() {
    return ((Outer*)lbl_27_bss_3210)->p->v;
}
}
