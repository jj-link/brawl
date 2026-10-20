#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 a : 8;
    u32 b : 4;
    u32 c : 20;
};

extern "C" void fn_27_D32DC(Flags *p, u32 v)
{
    p[2].b = v;
}
