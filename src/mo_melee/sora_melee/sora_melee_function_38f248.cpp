#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_38F248_arg {
    u32 pad[2];
    u32 flags;
};

extern "C" s32 fn_27_38F248(fn_27_38F248_arg *p)
{
    u32 t = ((p->flags >> 22) & 0xF) << 28;
    return (s32)t >> 29;
}
