#pragma force_active on
struct Bits {
    unsigned int w0;
    unsigned int w1;
    unsigned int top : 5;
    unsigned int rest : 27;
};

extern "C" void fn_40_30C5C(Bits* p, unsigned int v) {
    p->top = v;
}
