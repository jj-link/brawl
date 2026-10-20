#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 14;
    u32 f : 7;
    u32 lo : 11;
};

extern "C" void fn_48_B934(void *p, u32 v)
{
    struct Bits *b = (struct Bits *)((char *)p + 8);
    b->f = v;
}
