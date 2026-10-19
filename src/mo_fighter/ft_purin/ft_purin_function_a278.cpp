#include <types.h>
#pragma force_active on

extern const float lbl_124_rodata_8;

struct Vec2f {
    float x;
    float y;
};

extern "C" {
void fn_124_A278(u8* self);
void fn_124_A2B0(Vec2f* dst, const Vec2f* src);
}

extern "C" void fn_124_A278(u8* self) {
    Vec2f v;
    v.x = lbl_124_rodata_8;
    v.y = lbl_124_rodata_8;
    fn_124_A2B0(reinterpret_cast<Vec2f*>(self + 8), &v);
}
