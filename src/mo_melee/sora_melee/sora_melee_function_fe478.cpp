#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 w0;
    u32 w1;
    u32 a : 2;
    u32 b : 2;
    u32 rest : 28;
};

extern "C" {
void fn_27_FE478(Flags *p, u32 v)
{
    p->b = v;
}
}
