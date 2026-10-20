#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad[2];
    u32 mode : 3;
    u32 rest : 29;
};

extern "C" void fn_27_1A0CF8(Obj* p, u32 v)
{
    p->mode = v;
}
