#include <math.h>
#pragma force_active on

struct Vector3 {
    float x, y, z;
};

struct Object {
    unsigned char reserved00[0x0C];
    float scale;
    unsigned char reserved10[0x60];
    Vector3 dimensions;
};

extern "C" {
    extern const float lbl_27_rodata_20[];
    unsigned int fn_27_744(Object*, Object*, float);
    unsigned int fn_27_1058(Object*, const Vector3*, Object*);
}

extern "C" unsigned int fn_27_1504(Object* self, Object* other)
{
    Vector3 dimensions = self->dimensions;
    if ((float)__fabs(dimensions.x - dimensions.y) < lbl_27_rodata_20[0] &&
        (float)__fabs(dimensions.x - dimensions.z) < lbl_27_rodata_20[0]) {
        return fn_27_744(self, other, self->scale * dimensions.x);
    } else {
        return fn_27_1058(self, &dimensions, other);
    }
}
