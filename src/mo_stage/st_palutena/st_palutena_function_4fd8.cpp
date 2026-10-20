#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad0 : 4;
    u32 a : 2;
    u32 rest : 26;
};

extern "C" {
void fn_67_4FD8(void *p, u32 v)
{
    Bits *b = (Bits *)((char *)p + 8);
    b->a = v;
}
}
