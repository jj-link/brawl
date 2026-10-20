#pragma force_active on
struct S {
    char pad[8];
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int c : 24;
};

extern "C" void fn_56_66E0(S* s, int v) {
    s->b = v;
}
