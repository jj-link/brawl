#include <types.h>
#pragma force_active on

union Vec2 {
    struct { f32 x, y; };
    u32 words[2];
};

struct Obj {
    u8 pad0[0x20];
    Vec2 off;
    u8 pad1[0x48 - 0x28];
    Vec2 points[3];
};

extern "C" void fn_80042034(void*, void*);

extern "C" void fn_800117FC(Obj* obj) {
    Vec2 tmp[3];
    tmp[0] = obj->points[0];
    tmp[1] = obj->points[1];
    tmp[2] = obj->points[2];

    tmp[0].x += obj->off.x;
    tmp[0].y += obj->off.y;
    tmp[1].x += obj->off.x;
    tmp[1].y += obj->off.y;
    tmp[2].x += obj->off.x;
    tmp[2].y += obj->off.y;

    fn_80042034(tmp, (u8*)obj + 0x2c);
}
