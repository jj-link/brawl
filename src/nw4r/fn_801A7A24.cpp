#include <types.h>
#pragma force_active on

struct Fn801A7A24Obj {
    u8 pad0[0x70];
    u32 flags70;
    u8 pad74[0xA8 - 0x74];
    u32 unkA8;
    f32 unkAC;
    f32 unkB0;
    f32 unkB4;
    f32 unkB8;
};

extern "C" void fn_801A7A24(Fn801A7A24Obj** arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    Fn801A7A24Obj* obj = *arg0;
    if (obj == 0) {
        return;
    }
    obj->unkA8 = 0;
    obj->unkAC = farg0;
    obj->unkB0 = farg1;
    obj->unkB4 = farg2;
    obj->unkB8 = farg3;
    obj->flags70 = (obj->flags70 & 0xFFFFFF0F) | 0x20;
}
