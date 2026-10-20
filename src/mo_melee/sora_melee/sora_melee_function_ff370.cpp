#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad[2];
    u32 hi : 2;
    u32 rest : 30;
};

extern "C" void fn_27_FF370(Bits *p, u32 v) {
    p->hi = v;
}
