#pragma force_active on
struct S {
    char pad[8];
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
};

extern "C" void fn_50_6360(S* s, int v) {
    s->b = v;
}
