#pragma force_active on
struct S {
    int a;
    int b;
    unsigned int f : 2;
    unsigned int rest : 30;
};

extern "C" void fn_56_6554(S* s, unsigned int v) {
    s->f = v;
}
