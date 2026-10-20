#pragma peephole off
#include <math.h>
#pragma force_active on

extern "C" const unsigned char lbl_27_rodata_B90[12];

extern "C" float fn_27_89794(float value, float limit)
{
    const float* constants = (const float*)lbl_27_rodata_B90;
    float zero = constants[0];
    if (zero == value)
        return value;
    if (limit >= zero) {
        float absolute = (float)fabs(value);
        if (limit < absolute) {
            return limit * (value > zero
                ? constants[1] : constants[2]);
        }
    }
    return value;
}
