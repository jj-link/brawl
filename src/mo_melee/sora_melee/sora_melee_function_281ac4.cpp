#include <types.h>
#pragma force_active on

struct fn_Obj {
    u32 pad[0x9c / 4];
    u32 val;
};

struct fn_Outer {
    u8 pad[0xd8];
    fn_Obj* obj;
};

extern "C" u32 fn_27_281AC4(fn_Outer* self) {
    return self->obj->val;
}
