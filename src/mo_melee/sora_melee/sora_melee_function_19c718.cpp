#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" void fn_27_19C718(void *p, u32 x)
{
    Bits *b = (Bits *)((char *)p + 8);
    b->hi = x;
}
