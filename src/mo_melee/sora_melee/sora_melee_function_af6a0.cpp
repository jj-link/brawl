#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Fn27Obj {
    char pad[8];
    u32 field8;
};

extern "C" s32 fn_27_AF6A0(Fn27Obj* p)
{
    u32 x = p->field8;
    return (s32)(((x << 18) | (x >> 14)) & 0xFFC00000u) >> 23;
}
