#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_CC45C_obj {
    char pad[8];
    u32 field8;
};

extern "C" s32 fn_27_CC45C(fn_27_CC45C_obj *obj)
{
    u32 x = obj->field8;
    u32 r = (x << 5) | (x >> 27);
    return (s32)(r & 0xFC000000) >> 27;
}
