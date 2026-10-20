#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 3;
    u32 f : 3;
    u32 b : 26;
};

struct Holder {
    u32 w0;
    u32 w1;
    Bits bits;
};

extern "C" void fn_27_295E68(Holder* p, u32 v) {
    p->bits.f = v;
}
