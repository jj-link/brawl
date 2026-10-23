#pragma force_active on
extern "C" {

extern char lbl_80488088[0x78];

struct S {
    void* vtable;
    char _4[2];
    short flag;
    char _8[0x100];
} __attribute__((aligned(16)));

void* fn_802E52F0() {
    S s;
    if (&s != 0) {
        s.flag = 1;
        s.vtable = lbl_80488088;
    }
    return s.vtable;
}

}
