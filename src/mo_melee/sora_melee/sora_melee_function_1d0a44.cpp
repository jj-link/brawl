#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_1D0A44_arg {
    char pad[8];
    u32 field8;
};

extern "C" s32 fn_27_1D0A44(fn_27_1D0A44_arg *p)
{
    u32 t = (p->field8 >> 25) & 0xF;
    return (s32)(t << 28) >> 29;
}
