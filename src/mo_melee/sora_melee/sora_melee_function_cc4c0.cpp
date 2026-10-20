#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Fn27Obj {
    char pad[8];
    u32 field;
};

extern "C" s32 fn_27_CC4C0(Fn27Obj* obj)
{
    u32 v = obj->field;
    u32 rot = (v << 10) | (v >> 22);
    return (s32)(rot & 0xFC000000u) >> 27;
}
