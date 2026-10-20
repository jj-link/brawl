#include <types.h>
#pragma force_active on

struct FnTarget27 {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_A1C18(FnTarget27* p)
{
    p->flags &= ~0x00010000;
}
