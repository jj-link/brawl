#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad[2];
    u32 f : 10;
    u32 b : 22;
};

extern "C" void fn_27_385BBC(Obj* p, u32 v)
{
    p->f = v;
}
