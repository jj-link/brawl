#pragma force_active on
typedef unsigned int u32;

struct Obj {
    char pad[8];
    u32 top : 2;
    u32 rest : 30;
};

extern "C" {
void fn_27_1A4EE0(Obj* p, u32 v)
{
    p->top = v;
}
}
