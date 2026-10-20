#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_D100C_Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_D100C(fn_27_D100C_Obj* p)
{
    u32 x = p->unk8;
    return (s32)((x << 8) & 0xFF800000) >> 24;
}
