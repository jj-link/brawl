#include <types.h>
#pragma force_active on

struct FEEA8Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_FEEA8(FEEA8Obj* obj) {
    obj->flags |= 0x10000;
}
