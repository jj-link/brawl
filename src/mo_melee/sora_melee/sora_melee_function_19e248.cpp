#pragma force_active on
struct fn_27_S {
    int a0;
    int a1;
    unsigned int a : 12;
    unsigned int b : 6;
    unsigned int c : 14;
};

extern "C" void fn_27_19E248(struct fn_27_S *p, unsigned int v) {
    p->b = v;
}
