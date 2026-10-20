#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 a : 2;
    u32 b : 2;
    u32 c : 28;
};

extern "C" void fn_27_1D4C0(void *self, u32 v) {
    Flags *p = (Flags *)((char *)self + 8);
    p->b = v;
}
