#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_CA294_arg {
    u32 pad[2];
    u32 field8;
};

extern "C" {
s32 fn_27_CA294(fn_27_CA294_arg *p)
{
    return (s32)((p->field8 << 5) & 0xFC000000) >> 27;
}
}
