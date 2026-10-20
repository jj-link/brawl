#pragma force_active on
typedef unsigned int u32;

struct Bits8 {
    u32 pad[2];
    u32 hi : 6;
    u32 f : 3;
    u32 lo : 23;
};

extern "C" void fn_27_1991E0(Bits8* p, u32 v) {
    p->f = v;
}
