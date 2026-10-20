#pragma force_active on
typedef unsigned int u32;

struct Outer {
    u32 a;
    u32 b;
    u32 hi : 20;
    u32 f : 10;
    u32 lo : 2;
};

extern "C" void fn_27_1A64B8(Outer* p, u32 v)
{
    p->f = v;
}
