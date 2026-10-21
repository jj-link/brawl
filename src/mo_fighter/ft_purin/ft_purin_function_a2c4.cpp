#include <types.h>
#pragma force_active on

struct Vec2f {
    float x;
    float y;
};

extern "C" Vec2f* fn_124_A2B0(Vec2f* dst, const Vec2f* src);
extern const float lbl_124_rodata_8;
extern const float lbl_124_rodata_C;

extern "C" void fn_124_A2C4(u8* self) {
    Vec2f v;
    Vec2f w;
    v.x = lbl_124_rodata_8;
    v.y = lbl_124_rodata_8;
    Vec2f* p = fn_124_A2B0(reinterpret_cast<Vec2f*>(self + 0x20), &v);
    p = fn_124_A2B0(reinterpret_cast<Vec2f*>(self + 0x10), p);
    fn_124_A2B0(reinterpret_cast<Vec2f*>(self + 0x8), p);
    w.x = lbl_124_rodata_C;
    w.y = lbl_124_rodata_C;
    p = fn_124_A2B0(reinterpret_cast<Vec2f*>(self + 0x28), &w);
    fn_124_A2B0(reinterpret_cast<Vec2f*>(self + 0x18), p);
    self[0x31] = 0;
    self[0x30] = 0;
    self[0x32] = 1;
}
