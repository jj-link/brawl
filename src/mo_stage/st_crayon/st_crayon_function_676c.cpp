#pragma force_active on
struct S {
    int a;
    int b;
    unsigned int pad : 8;
    unsigned int f : 4;
    unsigned int rest : 20;
};

extern "C" void fn_56_676C(S* s, unsigned int v) {
    s->f = v;
}
