#pragma force_active on
struct S {
    char pad[8];
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int rest : 26;
};

extern "C" void fn_56_63E4(S* s, int v) {
    s->b = v;
}
