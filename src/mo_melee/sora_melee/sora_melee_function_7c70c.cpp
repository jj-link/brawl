#include <types.h>
#pragma force_active on

struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
};

extern "C" {
extern const f32 lbl_27_rodata_B70;

void fn_27_7C70C(Vec3f* v) {
    f32 zero = lbl_27_rodata_B70;
    v->x = zero;
    v->y = zero;
    v->z = zero;
}
}
