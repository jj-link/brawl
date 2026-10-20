#include <types.h>
#pragma force_active on

typedef struct {
    u8 pad[8];
    u32 x;
} FnObj;

extern "C" {
s32 fn_27_1A65AC(FnObj* obj)
{
    u32 x = obj->x;
    u32 r = (x << 20) | (x >> 12);
    return (s32)(r & 0xFFE00000) >> 22;
}
}
