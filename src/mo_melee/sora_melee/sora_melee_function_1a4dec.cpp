#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct S {
    u32 a;
    u32 b;
    u32 c;
};

extern "C" s32 fn_27_1A4DEC(S* p)
{
    u32 v = p->c;
    v = (v << 5) & 0xFC000000;
    return (s32)v >> 27;
}
