#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 pad[2];
    u32 a : 7;
    u32 b : 7;
    u32 c : 18;
} Bits;

extern "C" void fn_27_1D0494(Bits* p, u32 v)
{
    p->b = v;
}
