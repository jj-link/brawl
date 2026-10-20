#pragma force_active on
struct Bits {
    unsigned int a : 10;
    unsigned int f : 5;
    unsigned int b : 17;
};

extern "C" void fn_40_30AE0(Bits *p, unsigned int v) {
    p[2].f = v;
}
