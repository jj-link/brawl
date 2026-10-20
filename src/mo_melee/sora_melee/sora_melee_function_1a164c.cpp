#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
};

extern "C" void fn_27_1A164C(S *p, unsigned int v) {
    p->b = v;
}
