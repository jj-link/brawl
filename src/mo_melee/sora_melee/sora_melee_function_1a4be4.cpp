#include <types.h>
#pragma force_active on

struct fn_27_1A4BE4_Obj {
    u8 pad[8];
    u32 unk8;
};

extern "C" s32 fn_27_1A4BE4(fn_27_1A4BE4_Obj* p)
{
    return (s32)((p->unk8 << 4) & 0xF8000000) >> 28;
}
