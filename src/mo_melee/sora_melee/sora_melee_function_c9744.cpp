#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Fn27Obj {
    char pad[8];
    u32 field8;
};

extern "C" s32 fn_27_C9744(Fn27Obj *obj)
{
    return (s32)(((obj->field8 >> 27) & 7) << 29) >> 30;
}
