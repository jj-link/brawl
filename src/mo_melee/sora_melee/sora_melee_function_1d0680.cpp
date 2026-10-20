#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 a : 4;
    u32 f : 2;
    u32 b : 26;
};

extern "C" {
void fn_27_1D0680(S* p, u32 v)
{
    ((S*)((char*)p + 8))->f = v;
}
}
