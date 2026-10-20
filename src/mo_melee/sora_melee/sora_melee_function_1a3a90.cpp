#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Bits {
    u32 a : 10;
    u32 b : 22;
};

extern "C" {
void fn_27_1A3A90(void* p, u32 v) {
    Bits* w = (Bits*)((u8*)p + 8);
    w->a = v;
}
}
