#pragma force_active on
extern "C" {
struct S {
    unsigned int w0;
    unsigned int w1;
    unsigned int a : 12;
    unsigned int b : 6;
    unsigned int c : 14;
};

void fn_27_1A1B0C(S* p, unsigned int v) {
    p->b = v;
}
}
