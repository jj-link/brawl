#pragma force_active on
struct S {
    char pad[8];
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
};

extern "C" void fn_56_64CC(S* s, unsigned int v) {
    s->b = v;
}
