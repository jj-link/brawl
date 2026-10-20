#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 4;
    u32 f : 4;
    u32 lo : 24;
};

extern "C" {
void fn_27_198B10(unsigned char* p, u32 v) {
    Bits* b = (Bits*)(p + 8);
    b->f = v;
}
}
