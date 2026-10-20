#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 7;
    u32 f : 7;
    u32 lo : 18;
};

extern "C" void fn_27_D0CEC(u32* obj, u32 v) {
    Bits* b = (Bits*)(obj + 2);
    b->f = v;
}
