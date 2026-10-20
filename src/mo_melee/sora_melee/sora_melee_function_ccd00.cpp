#pragma force_active on
struct S27 {
    unsigned int a : 3;
    unsigned int f : 3;
    unsigned int b : 26;
};

struct Holder27 {
    unsigned int w0;
    unsigned int w1;
    S27 s;
};

extern "C" void fn_27_CCD00(Holder27* p, unsigned int x) {
    p->s.f = x;
}
