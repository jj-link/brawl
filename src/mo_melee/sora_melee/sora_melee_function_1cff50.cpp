#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad0;
    u32 pad1;
    u32 pad : 8;
    u32 f : 4;
    u32 rest : 20;
};

extern "C" void fn_27_1CFF50(Obj* p, u32 v)
{
    p->f = v;
}
