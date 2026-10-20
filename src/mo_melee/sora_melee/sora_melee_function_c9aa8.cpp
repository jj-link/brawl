#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int a : 2;
    unsigned int f : 2;
    unsigned int rest : 28;
};

extern "C" void fn_27_C9AA8(S* p, unsigned int v) {
    p->f = v;
}
