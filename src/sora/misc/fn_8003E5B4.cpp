#include <mt/mt_common.h>
#pragma force_active on
extern "C" void fn_8003E5B4(float (*m)[4]) {
    float x = rsqrtf(m[2][0]*m[2][0] + (m[0][0]*m[0][0] + m[1][0]*m[1][0]));
    float y = rsqrtf(m[2][1]*m[2][1] + (m[0][1]*m[0][1] + m[1][1]*m[1][1]));
    float z = rsqrtf(m[2][2]*m[2][2] + (m[0][2]*m[0][2] + m[1][2]*m[1][2]));
    m[0][0] *= x;
    m[1][0] *= x;
    m[2][0] *= x;
    m[0][1] *= y;
    m[1][1] *= y;
    m[2][1] *= y;
    m[0][2] *= z;
    m[1][2] *= z;
    m[2][2] *= z;
}