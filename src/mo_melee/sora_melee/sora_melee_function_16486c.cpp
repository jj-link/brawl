#include <types.h>
#pragma force_active on

struct Vec3f {
    float x;
    float y;
    float z;
};

struct Vec2f {
    float x;
    float y;
};

class soModuleAccesser;

extern const float lbl_27_rodata_1FC0;

extern "C" {
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);

void fn_27_16486C(int, int, Vec2f* vec, soModuleAccesser* accesser) {
    Vec3f zero;
    zero.x = lbl_27_rodata_1FC0;
    zero.y = lbl_27_rodata_1FC0;
    zero.z = lbl_27_rodata_1FC0;
    fn_27_89D08(0, accesser, 7, vec, &zero);
}
}
