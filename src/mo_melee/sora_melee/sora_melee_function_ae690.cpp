#include <types.h>
#pragma force_active on

struct Fn27Object
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_AE690(Fn27Object* self)
{
    return (s32)((self->unk8 & 0x0E000000u) << 4) >> 30;
}
