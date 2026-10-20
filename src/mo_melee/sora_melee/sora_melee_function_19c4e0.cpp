#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Fn27Bits {
    u32 pad;
    u32 pad2;
    u32 a : 4;
    s32 b : 4;
    u32 c : 24;
};

extern "C" s32 fn_27_19C4E0(Fn27Bits* p)
{
    return p->b;
}
