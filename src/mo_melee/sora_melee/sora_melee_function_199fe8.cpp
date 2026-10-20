#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
};

struct Outer {
    u32 w0;
    u32 w1;
    Bits bits;
};

extern "C" {
void fn_27_199FE8(Outer* p, u32 v) {
    p->bits.b = v;
}
}
