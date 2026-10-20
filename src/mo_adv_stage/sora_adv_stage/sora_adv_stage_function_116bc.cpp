#pragma force_active on
struct S {
    char pad[8];
    unsigned int a : 5;
    unsigned int b : 5;
    unsigned int c : 22;
};

extern "C" void fn_40_116BC(S* s, int v) {
    s->b = v;
}
