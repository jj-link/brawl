#include <types.h>
#pragma force_active on

struct soModuleAccesser;
struct Vec2f { float x, y; };
struct Vec3f { float x, y, z; };

extern "C" {
extern const float lbl_27_rodata_1FC0;
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
}

extern "C" void fn_27_160C98(int, int, int, soModuleAccesser* accesser) {
    Vec3f v3 = {lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0};
    Vec2f v2 = {lbl_27_rodata_1FC0, lbl_27_rodata_1FC0};
    fn_27_89D08(1, accesser, 6, &v2, &v3);
}
