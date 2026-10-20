#pragma force_active on
struct S {
    int a;
    int b;
    unsigned int f0 : 2;
    unsigned int f1 : 2;
    unsigned int rest : 28;
};

extern "C" void fn_77_3C88(S* s, unsigned int v) {
    s->f1 = v;
}
