#pragma force_active on
struct Bits {
    unsigned int a : 10;
    unsigned int b : 22;
};

struct Holder {
    unsigned int pad[2];
    Bits bits;
};

extern "C" void fn_27_1A45BC(Holder *p, unsigned int v) {
    p->bits.a = v;
}
