#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 10;
    u32 lo : 22;
};

extern "C" void fn_27_1A44B8(void *p, u32 v)
{
    Bits *b = (Bits *)((char *)p + 8);
    b->hi = v;
}
