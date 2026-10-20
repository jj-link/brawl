#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_199C18_arg {
    u32 pad0;
    u32 pad4;
    u32 value;
};

extern "C" s32 fn_27_199C18(struct fn_27_199C18_arg *p)
{
    u32 v = p->value;
    return (s32)(((v << 5) | (v >> 27)) & 0xFC000000) >> 27;
}
