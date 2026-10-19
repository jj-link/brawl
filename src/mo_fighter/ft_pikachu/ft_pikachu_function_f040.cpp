#include <math.h>
#pragma force_active on

extern "C" {
extern const float lbl_98_rodata_44;
extern const float lbl_98_rodata_20;
float rsqrtf__Ff(float);

struct Vec2f {
    float m_x;
    float m_y;
};

float fn_98_F040(const Vec2f* vec) {
    float a = vec->m_x * vec->m_x;
    float b = vec->m_y * vec->m_y;
    float squaredLength = a + b;
    if (static_cast<float>(fabs(squaredLength)) <= lbl_98_rodata_44) {
        return lbl_98_rodata_20;
    } else {
        return squaredLength * rsqrtf__Ff(squaredLength);
    }
}
}
