#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 3;
    u32 f : 3;
    u32 rest : 26;
};

extern "C" {
void fn_27_D34D0(void *p, u32 v)
{
    Bits *b = (Bits *)((char *)p + 8);
    b->f = v;
}
}
