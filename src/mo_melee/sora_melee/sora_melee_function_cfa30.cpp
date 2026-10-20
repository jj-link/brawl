#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 6;
    u32 f : 3;
    u32 b : 23;
};

extern "C" void fn_27_CFA30(void* p, u32 v) {
    Bits* w = (Bits*)((char*)p + 8);
    w->f = v;
}
