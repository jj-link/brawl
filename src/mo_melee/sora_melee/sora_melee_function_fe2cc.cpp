#pragma force_active on
struct S {
    unsigned int a;
    unsigned int b;
    unsigned int hi : 12;
    unsigned int f : 6;
    unsigned int lo : 14;
};

extern "C" void fn_27_FE2CC(S *p, unsigned int x) {
    p->f = x;
}
