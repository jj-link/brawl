#include <types.h>
#pragma force_active on

struct SoObjFlags {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_1A1964(SoObjFlags* p)
{
    p->flags &= ~0x2000;
}
}
