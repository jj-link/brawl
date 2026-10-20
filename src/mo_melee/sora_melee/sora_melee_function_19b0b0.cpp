#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FnObj {
    char pad[8];
    u32 flags;
};

extern "C" s32 fn_27_19B0B0(FnObj *p)
{
    return ((s32)((p->flags << 5) & 0xFC000000)) >> 27;
}
