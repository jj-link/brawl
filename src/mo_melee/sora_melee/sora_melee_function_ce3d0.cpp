#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Fn27Obj {
    char pad[8];
    u32 flags;
};

extern "C" s32 fn_27_CE3D0(Fn27Obj* p)
{
    return ((s32)((p->flags << 10) & 0xFC000000u)) >> 27;
}
