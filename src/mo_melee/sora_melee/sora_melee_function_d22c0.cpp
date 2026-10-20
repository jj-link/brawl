#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 8;
    u32 f : 4;
    u32 b : 20;
};

extern "C" void fn_27_D22C0(void* self, u32 v) {
    Bits* w = (Bits*)((char*)self + 8);
    w->f = v;
}
