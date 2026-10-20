#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct S {
    u32 pad[2];
    u32 flags;
};

extern "C" s32 fn_27_FE2F8(S* p)
{
    return ((s32)((p->flags >> 27) & 7) << 29) >> 30;
}
