#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad[2];
    u32 hi : 5;
    u32 lo : 27;
};

extern "C" {
void fn_27_B12F8(Bits *p, u32 v)
{
    p->hi = v;
}
}
