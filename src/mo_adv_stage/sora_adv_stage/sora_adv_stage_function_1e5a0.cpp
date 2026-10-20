#pragma force_active on
struct Bits {
    unsigned int a : 6;
    unsigned int f : 6;
    unsigned int b : 20;
};

struct Holder {
    unsigned int pad[2];
    Bits bits;
};

extern "C" void fn_40_1E5A0(Holder* p, unsigned int v) {
    p->bits.f = v;
}
