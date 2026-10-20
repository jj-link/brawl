#pragma force_active on
typedef unsigned int u32;

struct Obj08 {
    u32 pad[2];
    u32 top : 2;
};

extern "C" {
void fn_27_1D05E4(Obj08 *p, u32 v)
{
    p->top = v;
}
}
