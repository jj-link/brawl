#include <gr/collision/gr_collision_shape_circle.h>
#pragma force_active on

extern "C" void fn_801173C0(void*);
extern "C" char lbl_8045DA50[];
extern "C" char __vt__17grCollShapeCircle[];

extern "C" void* fn_80132004(void* self) {
    char* p = (char*)self;
    fn_801173C0(self);
    *(void**)(p + 0x32C) = lbl_8045DA50;
    *(void**)(p + 0x330) = __vt__17grCollShapeCircle;
    *(void**)(p + 0x340) = __vt__17grCollShapeCircle;
    *(void**)(p + 0x350) = __vt__17grCollShapeCircle;
    *(void**)(p + 0x360) = __vt__17grCollShapeCircle;
    *(void**)(p + 0x2BC) = p + 0x340;
    *(void**)(p + 0x2C0) = p + 0x350;
    *(void**)(p + 0x2C4) = p + 0x360;
    *(void**)(p + 0x2B8) = p + 0x330;
    return self;
}
