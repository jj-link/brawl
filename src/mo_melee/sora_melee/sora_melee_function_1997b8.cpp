#pragma force_active on
typedef unsigned int u32;

struct fn_27_Obj {
    char pad[8];
    u32 hi : 4;
    u32 f : 4;
    u32 lo : 24;
};

extern "C" {
void fn_27_1997B8(fn_27_Obj* p, u32 v)
{
    p->f = v;
}
}
