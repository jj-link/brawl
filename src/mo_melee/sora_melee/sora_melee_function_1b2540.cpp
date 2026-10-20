#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_1B2540_arg {
    u32 pad[2];
    u32 bits;
};

extern "C" {
s32 fn_27_1B2540(fn_27_1B2540_arg* p)
{
    u32 x = p->bits;
    s32 t = (s32)(((x << 12) | (x >> 20)) & 0xFE000000u);
    return t >> 26;
}
}
