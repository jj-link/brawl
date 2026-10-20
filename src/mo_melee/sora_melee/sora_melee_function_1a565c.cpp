#include <types.h>
#pragma force_active on

struct Flags32 {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" int fn_27_1A565C(Flags32* f)
{
    return (f->flags >> 19) & 1;
}
