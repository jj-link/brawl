#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_19C0B4_Obj {
    char pad[8];
    u32 field;
};

extern "C" s32 fn_27_19C0B4(fn_27_19C0B4_Obj *obj)
{
    return ((s32)((obj->field << 6) & 0xF0000000)) >> 29;
}
