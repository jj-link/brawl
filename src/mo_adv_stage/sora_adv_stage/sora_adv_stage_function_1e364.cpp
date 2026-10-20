#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 6;
    u32 b : 6;
    u32 c : 20;
};

extern "C" {
void fn_40_1E364(Bits* p, u32 v)
{
    p[2].b = v;
}
}
