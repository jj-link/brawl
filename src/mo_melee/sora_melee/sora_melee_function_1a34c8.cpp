#include <types.h>
#pragma force_active on

struct FlagHolder {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_1A34C8(FlagHolder* p)
{
    p->flags &= ~2;
}
