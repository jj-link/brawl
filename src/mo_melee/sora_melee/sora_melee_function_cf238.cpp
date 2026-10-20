#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Bits {
    u32 a : 12;
    u32 b : 6;
    u32 c : 14;
};

extern "C" void fn_27_CF238(u8* p, u32 v) {
    Bits* w = (Bits*)(p + 8);
    w->b = v;
}
