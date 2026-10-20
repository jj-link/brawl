#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad[2];
    u32 a : 5;
    u32 b : 27;
};

extern "C" void fn_27_B041C(Bits *p, u32 v) {
    p->a = v;
}
