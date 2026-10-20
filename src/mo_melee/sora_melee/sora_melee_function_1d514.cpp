#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_1D514_arg {
    u32 pad[2];
    u32 flags;
};

extern "C" s32 fn_27_1D514(fn_27_1D514_arg *p)
{
    u32 x = p->flags;
    s32 v = (s32)(((x << 4) | (x >> 28)) & 0xE0000000);
    return v >> 30;
}
