#pragma force_active on
struct S {
    unsigned int pad0;
    unsigned int pad4;
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int rest : 28;
};

extern "C" void fn_56_6618(S* s, unsigned int v) {
    s->b = v;
}
