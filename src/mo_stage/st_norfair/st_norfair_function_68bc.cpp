#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 pad0 : 4;
    u32 f : 4;
    u32 rest : 24;
} Bits;

extern "C" void fn_54_68BC(void *r3, u32 r4)
{
    Bits *b = (Bits *)((char *)r3 + 8);
    b->f = r4;
}
