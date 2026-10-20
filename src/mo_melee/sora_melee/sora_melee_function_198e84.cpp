#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_198E84_Obj {
    char pad[8];
    u32 field;
};

extern "C" s32 fn_27_198E84(fn_27_198E84_Obj* obj)
{
    return (s32)(((obj->field >> 27) & 7) << 29) >> 30;
}
