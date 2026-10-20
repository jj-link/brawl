#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 a;
    u32 b;
    u32 c;
};

struct Bits {
    u32 hi : 2;
    u32 val : 2;
    u32 lo : 28;
};

extern "C" {
void fn_27_19C2A8(S* p, u32 v)
{
    ((Bits*)&p->c)->val = v;
}
}
