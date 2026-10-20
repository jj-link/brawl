#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 10;
    u32 f : 5;
    u32 lo : 17;
};

struct S {
    u32 pad[2];
    Bits b;
};

extern "C" void fn_27_CA308(S* p, u32 v)
{
    p->b.f = v;
}
