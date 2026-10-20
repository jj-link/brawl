#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad0[2];
    u32 a : 20;
    u32 f : 10;
    u32 b : 2;
};

extern "C" {
void fn_27_1A63B4(Obj* p, u32 v)
{
    p->f = v;
}
}
