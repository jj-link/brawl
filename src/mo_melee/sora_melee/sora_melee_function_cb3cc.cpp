#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 16;
    u32 f : 8;
    u32 lo : 8;
};

extern "C" void fn_27_CB3CC(u32* p, u32 v) {
    ((Bits*)&p[2])->f = v;
}
