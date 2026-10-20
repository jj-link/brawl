#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad[2];
    u32 a : 10;
    u32 b : 22;
};

extern "C" void fn_27_1A3FA4(Obj* p, u32 v)
{
    p->a = v;
}
