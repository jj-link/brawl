#include <types.h>
#pragma force_active on

class soModuleAccesser;
struct Vec2f { float x, y; };
struct Vec3f { float x, y, z; };

extern "C" {
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
}

extern const float lbl_27_rodata_1FC0;

extern "C" {
void fn_27_163FFC(int, int, Vec2f* v, soModuleAccesser* accesser) {
    Vec3f zero;
    zero.x = lbl_27_rodata_1FC0;
    zero.y = lbl_27_rodata_1FC0;
    zero.z = lbl_27_rodata_1FC0;
    fn_27_89D08(3, accesser, 0, v, &zero);
}
}
