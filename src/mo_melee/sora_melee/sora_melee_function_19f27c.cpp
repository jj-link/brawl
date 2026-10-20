#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    char pad[8];
    u32 flags;
};

extern "C" s32 fn_27_19F27C(Obj* obj)
{
    u32 v = (obj->flags << 12) & 0xFE000000;
    return (s32)v >> 26;
}
