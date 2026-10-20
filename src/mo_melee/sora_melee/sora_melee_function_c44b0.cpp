#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 pad[2];
    u32 a : 6;
    u32 b : 6;
    u32 c : 20;
};

extern "C" {
void fn_27_C44B0(Flags *p, u32 v)
{
    p->b = v;
}
}
