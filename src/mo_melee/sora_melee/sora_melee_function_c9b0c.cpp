#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 pad0;
    u32 pad1;
    u32 a : 4;
    u32 b : 2;
    u32 c : 26;
};

extern "C" void fn_27_C9B0C(Flags *p, u32 v)
{
    p->b = v;
}
