#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_1D44C_arg {
    u32 pad0;
    u32 pad4;
    u32 unk8;
};

extern "C" s32 fn_27_1D44C(fn_27_1D44C_arg* p)
{
    return (s32)((p->unk8 << 4) & 0xE0000000) >> 30;
}
