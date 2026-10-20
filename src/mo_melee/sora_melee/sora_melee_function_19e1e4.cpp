#pragma force_active on
typedef unsigned int u32;

struct Fn27Bits {
    u32 pad[2];
    u32 a : 6;
    u32 b : 6;
    u32 c : 20;
};

extern "C" void fn_27_19E1E4(Fn27Bits* p, u32 v) {
    p->b = v;
}
