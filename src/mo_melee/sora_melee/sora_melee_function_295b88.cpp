#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 3;
    u32 b : 3;
    u32 c : 26;
};

struct Holder {
    u32 pad[2];
    Bits bits;
};

extern "C" {
void fn_27_295B88(Holder *p, u32 v) {
    p->bits.b = v;
}
}
