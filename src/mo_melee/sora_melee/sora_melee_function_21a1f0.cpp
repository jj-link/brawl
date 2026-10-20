#include <math.h>
#pragma force_active on
extern "C" const float lbl_27_rodata_31B8[];
extern float mtSqrtf(float);
#pragma fp_contract off
extern "C" bool fn_27_21A1F0(float a, float b, float c, float d, float e, float* p, float* q, float* r, float* s)
{
    const float* k = lbl_27_rodata_31B8;
    double magnitude = fabs(c);
    if (magnitude > k[19]) {
        float center = -(b / c);
        a -= e;
        if (c < k[2]) {
            a *= k[26];
            b *= k[26];
            c *= k[26];
        }
        float product = b * center;
        float t = k[11] + center;
        float y = product + (k[11] * (t * (c * t)) - k[23] * c);
        float v = k[23] * c + ((a - d) - y);
        float lo;
        if (v < k[2])
            lo = k[29];
        else
            lo = mtSqrtf(v / (k[11] * c)) - k[11];
        v = k[23] * c + ((a + d) - y);
        float hi;
        if (v < k[2])
            hi = k[29];
        else
            hi = mtSqrtf(v / (k[11] * c)) - k[11];
        *p = center - hi;
        *q = center - lo;
        *r = center + lo;
        *s = center + hi;
        return true;
    }
    magnitude = fabs(b);
    if (magnitude > k[19]) {
        a -= e;
        if (b < k[2]) {
            a *= k[26];
            b *= k[26];
        }
        *p = (a - d) / b;
        *q = (a + d) / b;
        *r = k[30];
        *s = k[30];
        return true;
    }
    return false;
}
