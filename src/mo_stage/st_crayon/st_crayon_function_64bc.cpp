#pragma force_active on
struct S {
    char pad[8];
    unsigned int a : 2;
    unsigned int b : 30;
};

extern "C" void fn_56_64BC(S* s, unsigned int v) {
    s->a = v;
}
