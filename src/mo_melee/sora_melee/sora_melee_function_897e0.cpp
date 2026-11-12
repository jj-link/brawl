#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
struct Vec2 { float x, y; };
static inline float clampf(float v, float limit)
{
    if (0.0f != v) {
        if (limit >= 0.0f) {
            float absolute = (float)(double)nw4r::math::FAbs(v);
            if (limit < absolute) {
                v = limit * (v > 0.0f ? 1.0f : -1.0f);
            }
        }
    }
    return v;
}
extern "C" Vec2 fn_27_897E0(const Vec2* arg0, const Vec2* arg1)
{
    Vec2 result = *arg0;
    result.x = clampf(arg0->x, arg1->x);
    result.y = clampf(arg0->y, arg1->y);
    return result;
}
