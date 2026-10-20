#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_7AB7C_Arg {
    u32 pad_a;
    u32 pad_b;
    u32 pad0 : 6;
    s32 val : 6;
    u32 pad1 : 20;
};

extern "C" s32 fn_27_7AB7C(fn_27_7AB7C_Arg* p)
{
    return p->val;
}
