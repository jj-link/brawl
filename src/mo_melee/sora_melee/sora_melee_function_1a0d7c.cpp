#pragma force_active on
typedef unsigned int u32;

struct Outer {
    u32 w0;
    u32 w1;
    u32 hi : 6;
    u32 f : 3;
    u32 lo : 23;
};

extern "C" {
void fn_27_1A0D7C(Outer* p, u32 v)
{
    p->f = v;
}
}
