#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 w0;
    u32 w1;
    u32 top : 5;
    u32 rest : 27;
};

extern "C" void fn_27_295FD8(Obj* p, u32 v)
{
    p->top = v;
}
