#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    char pad[8];
    u32 flags;
};

extern "C" {
s32 fn_27_FF0A0(Obj* obj)
{
    u32 t = (obj->flags >> 27) & 7;
    return (s32)(t << 29) >> 30;
}
}
