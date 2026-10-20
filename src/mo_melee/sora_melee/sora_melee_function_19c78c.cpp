#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_19C78C(Fn27Obj* obj)
{
    return (s32)((obj->unk8 << 8) & 0xF8000000) >> 28;
}
