#include <types.h>
#pragma force_active on

struct fn801A76C4Obj {
    u8 pad[0x70];
    u32 flags;
    float x;
    float y;
    float z;
};

extern "C" void fn_801A76C4(fn801A76C4Obj** arg0, float f1, float f2, float f3) {
    fn801A76C4Obj* obj = *arg0;
    if (obj == 0) {
        return;
    }
    obj->x = f1;
    obj->y = f2;
    obj->z = f3;
    obj->flags &= 0xFFFFFFF7;
}
