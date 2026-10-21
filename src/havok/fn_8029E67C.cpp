#pragma force_active on
struct Obj {
    unsigned int unk0;
    unsigned int unk4;
};

struct A {
    char data[48];
};

struct B {
    char data[12];
};

extern "C" void* fn_8029E67C(Obj* arg0, A* arg1) {
    unsigned int n = arg0->unk4;
    B* p = (B*)(arg1 + n);
    unsigned int* q = (unsigned int*)(p + n);
    return (void*)(((unsigned int)(q + (n + 1)) + 15) & ~15U);
}
