#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_CBB5C_Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_CBB5C(fn_27_CBB5C_Obj *obj)
{
    return ((s32)((obj->unk8 >> 23) << 27)) >> 28;
}
