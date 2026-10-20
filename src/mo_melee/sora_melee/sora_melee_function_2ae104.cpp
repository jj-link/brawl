#include <types.h>
#pragma force_active on

struct Fn27Obj {
    u8 pad[8];
    u32 flags;
};

extern "C" {
void fn_27_2AE104(Fn27Obj* obj)
{
    obj->flags &= 0xFDFFFFFF;
}
}
