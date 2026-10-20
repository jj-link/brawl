#pragma force_active on
struct Bits {
    unsigned int hi : 6;
    unsigned int rest : 26;
};

struct Obj {
    unsigned int w0;
    unsigned int w1;
    Bits bits;
};

extern "C" void fn_27_1A1D70(Obj* o, unsigned int v) {
    o->bits.hi = v;
}
