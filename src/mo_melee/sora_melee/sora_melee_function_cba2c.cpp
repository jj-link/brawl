#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int a : 4;
    unsigned int f : 4;
    unsigned int b : 24;
};

extern "C" void fn_27_CBA2C(S *p, unsigned int v) {
    p->f = v;
}
