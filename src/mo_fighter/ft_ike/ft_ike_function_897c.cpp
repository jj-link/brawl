#include <math.h>
#pragma force_active on

struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" extern const float lbl_119_rodata_1C;
extern "C" extern const float lbl_119_rodata_24;
float rsqrtf(float);

extern "C" {
float fn_119_897C(Vec3* v) {
    float sq = v->z * v->z + (v->x * v->x + v->y * v->y);
    double d = fabs((double)sq);
    float len = (float)d;
    if (len <= lbl_119_rodata_24) {
        return lbl_119_rodata_1C;
    }
    return sq * rsqrtf(sq);
}
}
