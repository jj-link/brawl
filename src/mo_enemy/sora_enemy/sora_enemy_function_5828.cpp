#include <types.h>
#include <math.h>
#pragma force_active on

extern const float lbl_41_rodata_18;
extern const float lbl_41_rodata_2C;

extern "C" void fn_41_58A4(const void* a, const void* b, float* out);
float rsqrtf(float);

extern "C" float fn_41_5828(const void* a, const void* b) {
    float v[2];
    fn_41_58A4(a, b, v);
    float sum = v[0] * v[0] + v[1] * v[1];
    if ((float)fabs(sum) <= lbl_41_rodata_2C) {
        return lbl_41_rodata_18;
    }
    return sum * rsqrtf(sum);
}
