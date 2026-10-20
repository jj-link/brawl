#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_1A6BC4_arg {
    u32 pad[2];
    u32 word8;
};

extern "C" s32 fn_27_1A6BC4(fn_27_1A6BC4_arg* p)
{
    return (s32)((p->word8 << 20) & 0xFFE00000) >> 22;
}
