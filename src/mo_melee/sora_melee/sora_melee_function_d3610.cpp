#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 a : 5;
    u32 b : 5;
    u32 c : 22;
} Bits;

extern "C" void fn_27_D3610(u32* p, u32 v) {
    Bits* bf = (Bits*)&p[2];
    bf->b = v;
}
