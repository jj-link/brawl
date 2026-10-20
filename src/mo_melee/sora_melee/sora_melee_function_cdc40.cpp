#include <types.h>
#pragma force_active on

struct Fn27CDC40Obj {
    u8 pad[8];
    u32 m8;
};

extern "C" {
s32 fn_27_CDC40(Fn27CDC40Obj* obj) {
    return ((s32)(((obj->m8 >> 21) & 0x3F) << 26)) >> 27;
}
}
