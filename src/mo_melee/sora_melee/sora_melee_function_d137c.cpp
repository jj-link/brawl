#include <types.h>
#pragma force_active on

struct fn27Obj {
    u8 pad[8];
    u32 flags;
};

extern "C" void fn_27_D137C(fn27Obj* obj) {
    obj->flags &= ~0x80;
}
