#pragma force_active on
struct S {
    unsigned int a : 6;
    unsigned int b : 6;
    unsigned int c : 20;
};

struct T {
    unsigned int pad[2];
    S s;
};

extern "C" void fn_27_CF36C(T *p, unsigned int v) {
    p->s.b = v;
}
