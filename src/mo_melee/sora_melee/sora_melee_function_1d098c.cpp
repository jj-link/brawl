#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_1D098C_arg {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_1D098C(fn_27_1D098C_arg *p)
{
    u32 t = (p->unk8 << 4) | (p->unk8 >> 28);
    return (s32)(t & 0xF8000000) >> 28;
}
