#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct S {
    char pad[8];
    u32 field;
};

extern "C" s32 fn_27_1D5D0(S* p)
{
    return (s32)((p->field << 8) & 0xF8000000) >> 28;
}
