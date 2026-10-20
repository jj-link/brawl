#include <types.h>
#pragma force_active on

struct fn_27_CC040_arg {
    u32 pad[2];
    u32 field;
};

extern "C" s32 fn_27_CC040(fn_27_CC040_arg* p)
{
    return (s32)((p->field >> 25) & 7) << 29 >> 30;
}
