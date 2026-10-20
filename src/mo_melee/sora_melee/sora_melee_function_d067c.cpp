#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_Obj {
    u32 pad[2];
    u32 flags;
};

extern "C" s32 fn_27_D067C(fn_27_Obj* p)
{
    return ((s32)((p->flags << 7) & 0xFF000000)) >> 25;
}
