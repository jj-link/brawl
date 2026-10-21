#pragma force_active on
extern unsigned char lbl_80488170[];

struct Object {
    void* p;
    unsigned short pad;
    unsigned short s;
    char data[0xF8];
};

extern "C" void* fn_802E5B14() {
    __declspec(align(16)) Object f;
    if (&f != 0) {
        f.s = 1;
        f.p = lbl_80488170;
    }
    return f.p;
}
