#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_295BDC_arg {
    char pad[8];
    u32 field8;
};

extern "C" s32 fn_27_295BDC(fn_27_295BDC_arg* p)
{
    u32 x = p->field8;
    u32 r = (x << 6) | (x >> 26);
    return (s32)(r & 0xF0000000) >> 29;
}
