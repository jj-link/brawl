#include <types.h>
#pragma force_active on

struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" {
void fn_27_89D08(int, void*, int, void*, Vec3f*);
}

extern const float lbl_27_rodata_1FC0;

extern "C" {
void fn_27_1642D4(int, void* a, void* b, void* c) {
    float z = lbl_27_rodata_1FC0;
    Vec3f zero = {z, z, z};
    fn_27_89D08(3, c, 0xf, b, &zero);
}
}
