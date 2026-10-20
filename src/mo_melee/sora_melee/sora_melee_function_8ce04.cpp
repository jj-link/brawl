#pragma force_active on
struct C {
    char pad[0x44];
    C* p;
};

struct B {
    char pad[0xD8];
    C* p;
};

struct A {
    char pad[0x60];
    B* p;
};

extern "C" void* fn_27_8CE04(A* a) {
    return a->p->p->p;
}
