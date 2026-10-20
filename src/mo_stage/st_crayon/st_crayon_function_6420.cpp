#pragma force_active on
struct S {
    char pad[8];
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int rest : 28;
};

extern "C" void fn_56_6420(S* s, int v) {
    s->b = v;
}
