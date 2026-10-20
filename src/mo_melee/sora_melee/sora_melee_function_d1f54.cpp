#include <types.h>
#pragma force_active on

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
} fn_27_D1F54_Obj;

extern "C" s32 fn_27_D1F54(fn_27_D1F54_Obj* p)
{
    return ((s32)((p->unk8 << 4) & 0xF8000000)) >> 28;
}
