#pragma force_active on
struct S {
    unsigned int a0 : 7;
    unsigned int a1 : 7;
    unsigned int a2 : 18;
};

struct T {
    unsigned int w0;
    unsigned int w1;
    struct S s;
};

extern "C" void fn_27_D01C4(T* p, unsigned int v) {
    p->s.a1 = v;
}
