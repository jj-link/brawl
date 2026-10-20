#pragma force_active on
struct S {
    unsigned int a : 5;
    unsigned int b : 5;
    unsigned int c : 22;
};

extern "C" void fn_27_761EC(S *p, unsigned int v) {
    p[2].b = v;
}
