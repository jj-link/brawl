#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad[2];
    u32 a : 6;
    u32 b : 6;
    u32 c : 20;
};

extern "C" void fn_27_1CF9CC(Bits *p, u32 v)
{
    p->b = v;
}
