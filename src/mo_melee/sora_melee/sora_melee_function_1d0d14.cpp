#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int a : 6;
    unsigned int b : 26;
};

extern "C" void fn_27_1D0D14(S *p, unsigned int v) {
    p->a = v;
}
