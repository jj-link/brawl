#include <types.h>
#pragma force_active on

struct fn27Obj {
    u8 pad[8];
    u32 flags;
};

extern "C" {
void fn_27_1A24D0(fn27Obj* obj)
{
    obj->flags |= 0x10000;
}
}
