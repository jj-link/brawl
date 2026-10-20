#pragma force_active on
struct S {
    char pad[8];
    unsigned int f : 2;
    unsigned int rest : 30;
};

extern "C" void fn_56_65F8(S* s, unsigned int v) {
    s->f = v;
}
