#include <types.h>
#pragma force_active on

struct Vec2f {
    float x;
    float y;
};

struct Vec3f {
    float x;
    float y;
    float z;
};

class soModuleAccesser;

extern "C" {
extern const float lbl_27_rodata_1FC0;
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);

void fn_27_164750(int, int, int, soModuleAccesser* accesser) {
    float zero = lbl_27_rodata_1FC0;
    Vec3f v3 = {zero, zero, zero};
    Vec2f v2 = {zero, zero};
    fn_27_89D08(0, accesser, 3, &v2, &v3);
}
}
