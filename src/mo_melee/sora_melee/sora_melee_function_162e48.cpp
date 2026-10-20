#include <types.h>
#pragma force_active on

struct Vec2f { float x, y; };
struct Vec3f { float x, y, z; };
class soModuleAccesser;

extern const float lbl_27_rodata_1FC0;

extern "C" {
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
void fn_27_162E48(int, int, Vec2f* vec2, soModuleAccesser* accesser) {
    Vec3f v1 = {lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0};
    fn_27_89D08(2, accesser, 8, vec2, &v1);
    Vec2f v2 = {lbl_27_rodata_1FC0, lbl_27_rodata_1FC0};
    Vec3f v3 = {lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0};
    fn_27_89D08(0, accesser, 2, &v2, &v3);
}
}
