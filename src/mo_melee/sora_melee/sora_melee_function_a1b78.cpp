#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_A1B78_Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_A1B78(fn_27_A1B78_Obj* p)
{
    u32 x = p->unk8;
    return ((s32)(((x << 4) | (x >> 28)) & 0xE0000000u)) >> 30;
}
