#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 pad[2];
    u32 a : 12;
    u32 b : 6;
    u32 c : 14;
};

extern "C" void fn_27_122C7C(Flags *p, u32 v) {
    p->b = v;
}
