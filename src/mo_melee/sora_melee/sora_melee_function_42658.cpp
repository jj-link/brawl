#pragma force_active on
struct Obj {
    char pad_00[0x20];
    int m20;
    int m24;
    int m28;
    char pad_2c[0x31 - 0x2c];
    unsigned char m31;
    unsigned char m32;
};

extern "C" void fn_27_42658(Obj* p, int arg) {
    p->m24 = arg;
    if (p->m31 == 1 || arg != 0) {
        p->m20 = 2;
        return;
    }
    if (p->m32 == 1 || p->m28 != 0) {
        p->m20 = 1;
        return;
    }
    p->m20 = 0;
}
