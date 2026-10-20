#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_FE3B0_Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_FE3B0(fn_27_FE3B0_Obj *p)
{
    return (s32)((p->unk8 << 2) & 0xE0000000) >> 30;
}
