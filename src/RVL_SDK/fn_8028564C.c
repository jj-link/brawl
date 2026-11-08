#include <stl/internal/fdlibm_public.h>
#pragma force_active on
void fn_8028564C(float* dst, const float* src, float angle) {
    float scaledAngle = 0.5f * angle;
    float sine = (float)sin(scaledAngle);
    float value0 = sine * src[0];
    float value1 = sine * src[1];
    float value2 = sine * src[2];
    float value3 = sine * src[3];
    dst[0] = value0;
    dst[1] = value1;
    dst[2] = value2;
    dst[3] = value3;
    dst[3] = (float)cos(scaledAngle);
}