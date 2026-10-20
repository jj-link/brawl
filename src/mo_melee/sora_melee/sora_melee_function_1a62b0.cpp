#pragma force_active on
struct Bits {
    unsigned int pad0;
    unsigned int pad1;
    unsigned int a : 20;
    unsigned int b : 10;
    unsigned int c : 2;
};

extern "C" void fn_27_1A62B0(Bits *p, unsigned int v) {
    p->b = v;
}
