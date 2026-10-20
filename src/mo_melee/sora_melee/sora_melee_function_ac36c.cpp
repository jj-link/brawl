#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad[2];
    u32 a : 12;
    u32 f : 6;
    u32 b : 14;
};

extern "C" void fn_27_AC36C(Bits* p, u32 v) {
    p->f = v;
}
