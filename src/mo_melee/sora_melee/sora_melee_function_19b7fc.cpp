#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad0;
    u32 pad1;
    u32 a : 12;
    u32 b : 6;
    u32 c : 14;
};

extern "C" {
void fn_27_19B7FC(Bits *p, u32 v)
{
    p->b = v;
}
}
