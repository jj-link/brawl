#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int rest : 28;
};

extern "C" void fn_49_6D9C(S* p, unsigned int v) {
    p->b = v;
}
