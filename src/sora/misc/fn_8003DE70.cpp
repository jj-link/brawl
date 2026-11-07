#include <mt/mt_common.h>
#pragma force_active on

extern "C" void fn_8003DE70(float* v) {
    float inv = rsqrtf(v[2] * v[2] + (v[0] * v[0] + v[1] * v[1]));
    v[0] = v[0] * inv;
    v[1] = v[1] * inv;
    v[2] = v[2] * inv;
}
