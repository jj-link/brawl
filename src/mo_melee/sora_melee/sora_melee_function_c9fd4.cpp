#pragma force_active on
struct fn_27_C9FD4_S {
    unsigned int a;
    unsigned int b;
    unsigned int hi : 6;
    unsigned int f : 3;
    unsigned int lo : 23;
};

extern "C" void fn_27_C9FD4(fn_27_C9FD4_S* p, unsigned int v) {
    p->f = v;
}
