#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int f : 5;
};

extern "C" void fn_27_19D414(S* p, unsigned int v) {
    p->f = v;
}
