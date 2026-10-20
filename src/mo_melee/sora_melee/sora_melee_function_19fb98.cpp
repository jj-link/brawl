#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 3;
    u32 lo : 29;
};

extern "C" {
void fn_27_19FB98(void *p, u32 v)
{
    Bits *b = (Bits *)((char *)p + 8);
    b->hi = v;
}
}
