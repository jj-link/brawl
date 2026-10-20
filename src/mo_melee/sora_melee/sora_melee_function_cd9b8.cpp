#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct S {
    u32 pad[2];
    u32 val;
};

extern "C" s32 fn_27_CD9B8(S* p)
{
    u32 x = p->val;
    u32 y = (x << 2) | (x >> 30);
    y &= 0xE0000000;
    return (s32)y >> 30;
}
