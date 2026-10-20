#include <types.h>
#pragma force_active on

typedef struct {
    u8 pad[8];
    u32 bits;
} FnObj;

extern "C" s32 fn_27_1A0454(FnObj* obj)
{
    return ((s32)((obj->bits >> 10) & 0xFF) << 24) >> 25;
}
