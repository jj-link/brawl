#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_1A3280(Fn27Obj *obj)
{
    return (s32)((obj->unk8 << 10) & 0xFFE00000) >> 22;
}
