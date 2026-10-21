#include <types.h>
#pragma force_active on

struct Vec2F {
    float x;
    float y;
};

struct MarthVec2Block {
    u32 vtable;
    u32 pad04;
    Vec2F v08;
    Vec2F v10;
    Vec2F v18;
    Vec2F v20;
    Vec2F v28;
    u8 pad30;
    u8 b31;
    u8 b32;
};

extern "C" {
extern const float lbl_106_rodata_8;
extern const float lbl_106_rodata_18;
Vec2F* fn_106_954C(Vec2F* dst, const Vec2F* src);

void fn_106_9560(MarthVec2Block* self) {
    Vec2F temp;
    temp.x = lbl_106_rodata_8;
    temp.y = lbl_106_rodata_8;
    Vec2F* r = fn_106_954C(&self->v20, &temp);
    r = fn_106_954C(&self->v10, r);
    fn_106_954C(&self->v08, r);

    Vec2F temp2;
    temp2.x = lbl_106_rodata_18;
    temp2.y = lbl_106_rodata_18;
    Vec2F* q = fn_106_954C(&self->v28, &temp2);
    fn_106_954C(&self->v18, q);

    self->b31 = 0;
    self->pad30 = 0;
    self->b32 = 1;
}
}
