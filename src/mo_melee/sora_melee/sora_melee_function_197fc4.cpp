#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 4;
    u32 b : 2;
    u32 c : 26;
};

extern "C" void fn_27_197FC4(Bits* p, u32 v) {
    ((Bits*)((u32*)p + 2))->b = v;
}
