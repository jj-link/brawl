#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a;
    u32 b;
    u32 hi : 10;
    u32 rest : 22;
};

extern "C" void fn_27_1A3D9C(Bits *p, u32 v) {
    p->hi = v;
}
