#include <types.h>
#pragma force_active on

typedef struct {
    u8 pad[8];
    u32 field;
} fn_27_1A6034_arg;

extern "C" s32 fn_27_1A6034(fn_27_1A6034_arg* p)
{
    s32 v = (s32)((p->field << 10) & 0xFFE00000);
    return v >> 22;
}
