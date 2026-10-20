#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
};

extern "C" {
void fn_27_1981D8(u32* p, u32 v)
{
    Bits* s = (Bits*)&p[2];
    s->b = v;
}
}
