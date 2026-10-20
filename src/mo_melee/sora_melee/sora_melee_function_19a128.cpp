#pragma force_active on
typedef unsigned int u32;

struct BF {
    u32 hi : 5;
    u32 f : 5;
    u32 lo : 22;
};

struct Outer {
    u32 pad[2];
    BF bf;
};

extern "C" void fn_27_19A128(Outer *p, u32 v)
{
    p->bf.f = v;
}
