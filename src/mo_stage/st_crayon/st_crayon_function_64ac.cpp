#pragma force_active on
struct S {
    char pad[8];
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
};

extern "C" void fn_56_64AC(S* s, unsigned int v) {
    s->b = v;
}
