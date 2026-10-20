#pragma force_active on
struct Bits {
    unsigned int a : 4;
    signed int b : 4;
    unsigned int c : 24;
};

struct Holder {
    int pad0;
    int pad1;
    struct Bits bits;
};

extern "C" int fn_27_1A26B0(Holder *p) {
    return p->bits.b;
}
