#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad[2];
    u32 a : 10;
    u32 b : 10;
    u32 c : 12;
};

extern "C" {
void fn_27_1A6D78(Bits* p, u32 v)
{
    p->b = v;
}
}
