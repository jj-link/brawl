#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" void fn_27_19B9C0(u32* p, u32 v) {
    ((Bits*)(p + 2))->hi = v;
}
