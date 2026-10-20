#include <types.h>
#pragma force_active on

struct Vec2f { float x, y; };
struct Vec3f { float x, y, z; };
struct soModuleAccesser;

extern "C" {
extern const float lbl_27_rodata_1FC0;
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*, int, int, int);

void fn_27_1628A4(int a1, soModuleAccesser* a2, int a3, soModuleAccesser* a4,
                  int a5, int a6, int a7, int a8) {
    Vec3f zero = {lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0};
    fn_27_89D08(0, (soModuleAccesser*)a4, 5, (Vec2f*)a3, &zero, a6, a7, a8);
}
}
