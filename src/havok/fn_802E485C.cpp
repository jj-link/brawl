#pragma force_active on
extern char lbl_80488020[];

struct Obj {
    void* p;
    char c[2];
    short s;
    char pad[0x100 - 8];
};

extern "C" void* fn_802E485C(void) {
    __attribute__((aligned(16))) Obj big;
    void* p = &big;
    if (p) {
        big.s = 1;
        big.p = (void*)lbl_80488020;
    }
    return big.p;
}