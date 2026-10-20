#pragma force_active on
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 flags;
} FnObj;

extern "C" s32 fn_27_D3524(FnObj* p)
{
    return (s32)((p->flags << 6) & 0xF0000000) >> 29;
}
