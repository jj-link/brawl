#pragma pool_data on

#include <mt/mt_common.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

extern const float lbl_27_rodata_868[];
extern "C" {
double atan2(double, double);
float rsqrtf__Ff(float);
}

extern "C" float fn_27_60AF4(
    int self, int kind, int flag, const float* vec, unsigned int flip,
    float a, float b, float c, float d, float e, float f)
{
    if (kind == 0x16B || kind == 0x16D) {
        float sum = vec[0] * vec[0] + vec[1] * vec[1];
        float absLen = static_cast<float>(nw4r::math::FAbs(sum) * 1.0);
        float length;

        if (absLen <= 1.1754944e-38f) {
            length = 0.0f;
        } else {
            length = sum * rsqrtf__Ff(sum);
        }

        if (length <= 0.0f) {
            goto fallback;
        }

        float angle = 57.29578f * (float)atan2(vec[1], vec[0] * -b);
        if (angle < 0.0f) {
            angle += 360.0f;
        }
        return 0.017453292f * angle;
    }

    if (kind == 0x169) {
        goto l169;
    }

    return 0.017453292f * (float)kind;

l169:
    if (flag != 0) {
        return c;
    }

fallback:
    if (a < d) {
        return 0.0f;
    }

    {
        float num = a - d;
        float den = e - d;
        float value = 0.017453292f * (1.0f + f * (num / den));

        if (value > 0.017453292f * f) {
            value = 0.017453292f * f;
        }

        if (flip == 1) {
            value = 1.5707964f - value;
        }

        return value;
    }
}