#pragma force_active on
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 flags;
} fn_27_Obj;

extern "C" s32 fn_27_19FC0C(fn_27_Obj* p)
{
    u32 v = p->flags;
    return (s32)(((v << 6) | (v >> 26)) & 0xF0000000) >> 29;
}
