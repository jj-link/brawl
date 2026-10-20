#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 6;
    u32 f : 6;
    u32 b : 20;
};

extern "C" {
void fn_27_1A1AA8(u32* self, u32 val)
{
    Bits* p = (Bits*)(self + 2);
    p->f = val;
}
}
