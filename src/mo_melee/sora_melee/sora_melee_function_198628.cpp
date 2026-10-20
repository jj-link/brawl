#pragma force_active on
struct Bits {
    unsigned int hi : 4;
    unsigned int rest : 28;
};

struct Obj {
    unsigned int pad[2];
    Bits bits;
};

extern "C" void fn_27_198628(Obj *p, unsigned int v) {
    p->bits.hi = v;
}
