#pragma force_active on
struct FnObj {
    char pad0[0x10];
    void* f10;
    void* f14;
    void* f18;
    char pad1[0x24 - 0x1c];
    void* f24;
    void* f28;
    void* f2c;
    unsigned int f30;
};

extern "C" {
void fn_27_6F314(FnObj* p) {
    unsigned int v = p->f30;
    void* z = 0;
    p->f10 = z;
    v &= 0xFE;
    p->f18 = z;
    p->f14 = p;
    p->f24 = z;
    p->f2c = z;
    p->f28 = p;
    p->f30 = v;
}
}
