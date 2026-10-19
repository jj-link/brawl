#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern const f32 lbl_103_rodata_14;

struct Vec2f {
    f32 x;
    f32 y;
};

struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
};

Vec3f* fn_103_9594(Vec3f* dst, f32 x, f32 y, f32 z);
void fn_27_89D08(int, void* accesser, int, Vec2f* vec2, Vec3f* vec3);

void fn_103_E27C(void* unusedA, void* unusedB, const f32* src, void* accesser) {
    Vec2f a;
    Vec3f d;
    a.x = *src;
    a.y = lbl_103_rodata_14;
    fn_27_89D08(2, accesser, 0, &a, fn_103_9594(&d, lbl_103_rodata_14, lbl_103_rodata_14, lbl_103_rodata_14));
}
}
