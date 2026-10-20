#include <math.h>
#pragma force_active on

struct Vector3 {
    float x;
    float y;
    float z;
};

struct ObjectBase {
    unsigned char reserved00[0x0C];
    float scale;
    unsigned char reserved10[0x20];

    virtual void reservedVirtual();
    virtual int getType();
};

struct Object : ObjectBase {
    unsigned char reserved34[0x3C];
    Vector3 dimensions;
};

extern "C" {
    extern const float lbl_27_rodata_8[];

    unsigned int fn_27_118(Object*, Object*);
    unsigned int fn_27_228(Object*, Object*);
    unsigned int fn_27_2140(Object*, const Vector3*, Object*, const Vector3*);
    unsigned int fn_27_1E18(Object*, Object*, float);
    unsigned int fn_27_1504(Object*, Object*);
}

extern "C" unsigned int fn_27_2718(Object* self, Object* other)
{
    if (fn_27_118(self, other) == 1) {
        if (fn_27_228(self, other) == 1)
            return 1;

        switch (other->getType()) {
        case 1: {
            Vector3 dimensions = other->dimensions;

            float differenceY = self->dimensions.x - self->dimensions.y;
            float differenceZ = self->dimensions.x - self->dimensions.z;
            float absoluteY = (float)__fabs(differenceY);
            float absoluteZ;

            if (absoluteY >= lbl_27_rodata_8[0] ||
                (absoluteZ = (float)__fabs(differenceZ)) >= lbl_27_rodata_8[0]) {
                return fn_27_2140(self, &self->dimensions, other, &dimensions);
            }

            differenceY = dimensions.x - dimensions.y;
            differenceZ = dimensions.x - dimensions.z;
            absoluteY = (float)__fabs(differenceY);

            if (absoluteY >= lbl_27_rodata_8[0] ||
                (absoluteZ = (float)__fabs(differenceZ)) >= lbl_27_rodata_8[0]) {
                return fn_27_2140(other, &dimensions, self, &self->dimensions);
            }

            return fn_27_1E18(self, other, self->scale * self->dimensions.x);
        }

        case 0:
            return fn_27_1504(self, other);
        }
    }

    return 0;
}
