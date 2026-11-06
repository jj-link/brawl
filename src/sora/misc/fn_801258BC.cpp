#include <gr/collision/gr_collision_shape_rhombus.h>
#pragma force_active on

extern "C" void fn_801173C0(void*);
extern "C" char lbl_8045DA18[];
extern "C" char __vt__18grCollShapeRhombus[];

extern "C" void* fn_801258BC(void* self) {
    char* p = (char*)self;
    fn_801173C0(self);
    *(void**)(p + 0x32C) = lbl_8045DA18;
    *(void**)(p + 0x330) = __vt__18grCollShapeRhombus;
    *(void**)(p + 0x36C) = __vt__18grCollShapeRhombus;
    *(void**)(p + 0x3A8) = __vt__18grCollShapeRhombus;
    *(void**)(p + 0x3E4) = __vt__18grCollShapeRhombus;
    *(void**)(p + 0x2BC) = p + 0x36C;
    *(void**)(p + 0x2C0) = p + 0x3A8;
    *(void**)(p + 0x2C4) = p + 0x3E4;
    *(void**)(p + 0x2B8) = p + 0x330;
    return self;
}