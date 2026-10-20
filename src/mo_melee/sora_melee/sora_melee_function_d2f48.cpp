#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int : 3;
    unsigned int f : 3;
    unsigned int : 26;
};

extern "C" void fn_27_D2F48(S* s, unsigned int v) {
    s->f = v;
}
