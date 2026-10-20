#include <types.h>
#pragma force_active on

typedef struct FnObj {
    u8 pad[8];
    u32 flags;
} FnObj;

extern "C" s32 fn_27_D1CC0(FnObj *obj)
{
    u32 v = obj->flags;
    return ((s32)((v << 12) & 0xFE000000)) >> 26;
}
