#include <types.h>
#pragma force_active on

struct Fn27Obj {
    u8 pad[8];
    u32 flags;
};

extern "C" {
void fn_27_10EC08(Fn27Obj* obj) {
    obj->flags &= ~0x00010000;
}
}
