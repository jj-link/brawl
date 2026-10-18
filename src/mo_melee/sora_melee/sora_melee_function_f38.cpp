#include <types.h>
#include <math.h>
#pragma force_active on

float rsqrtf(float);

extern float lbl_27_rodata_1C;
extern float lbl_27_rodata_14;

class Vec3f {
public:
    float length();
    float x;
    float y;
    float z;
};

float Vec3f::length() {
    float sq = z * z + (x * x + y * y);
    if ((float)fabs(sq) <= lbl_27_rodata_1C) {
        return lbl_27_rodata_14;
    }
    return sq * rsqrtf(sq);
}
