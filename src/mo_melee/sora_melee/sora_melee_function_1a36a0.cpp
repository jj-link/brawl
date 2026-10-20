#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad0;
    u32 pad1;
    u32 a : 10;
    u32 b : 10;
    u32 c : 12;
};

extern "C" {
void fn_27_1A36A0(Bits* p, u32 v);
}

void fn_27_1A36A0(Bits* p, u32 v)
{
    p->b = v;
}
