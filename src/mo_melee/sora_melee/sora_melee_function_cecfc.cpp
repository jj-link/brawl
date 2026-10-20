#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_CECFC(Obj* obj)
{
    u32 x = obj->unk8;
    return (s32)((x << 6 | x >> 26) & 0xFE000000) >> 26;
}
