#include <types.h>
#pragma force_active on

struct fn_27_1B2450_arg {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_1B2450(fn_27_1B2450_arg* p)
{
    return ((s32)((p->unk8 << 8) & 0xF8000000)) >> 28;
}
