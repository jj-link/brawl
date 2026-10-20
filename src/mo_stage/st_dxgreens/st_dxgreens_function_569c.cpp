#pragma force_active on
struct S {
    char pad[8];
    unsigned int a : 6;
    unsigned int b : 26;
};

extern "C" void fn_79_569C(S* s, unsigned int v) {
    s->a = v;
}
