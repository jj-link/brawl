#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 7;
    u32 mid : 7;
    u32 lo : 18;
};

extern "C" void fn_27_1D0C7C(char *p, u32 v)
{
    Bits *b = (Bits *)(p + 8);
    b->mid = v;
}
