#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 pad0;
    u32 pad4;
    u32 field8;
};

extern "C" {
s32 fn_27_199E98(Obj* obj)
{
    u32 bits = (obj->field8 >> 23) & 0x1F;
    return (s32)(bits << 27) >> 28;
}
}
