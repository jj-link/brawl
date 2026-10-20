#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad[2];
    u32 a : 12;
    u32 b : 6;
    u32 c : 14;
};

extern "C" void fn_27_CF700(void* p, u32 x)
{
    Bits* s = (Bits*)p;
    s->b = x;
}
