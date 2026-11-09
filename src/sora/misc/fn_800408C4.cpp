#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
extern float lbl_805A17AC;
struct Vec2Base { float x; float y; };
struct Vec2 : Vec2Base {
    Vec2() {}
    Vec2(float b, float a) { y = b; x = a; }
    Vec2 operator-(const Vec2& b) const {
        return Vec2(y - b.y, x - b.x);
    }
};
struct Line { Vec2 start; Vec2 end; };
extern "C" int fn_800408C4(const Line* line, const float* x, Vec2* out) {
    Vec2 d = line->end - line->start;
    double ax = nw4r::math::FAbs(d.x);
    if ((float)ax > lbl_805A17AC) {
        out->x = *x;
        out->y = line->start.y + d.y * ((*x - line->start.x) / d.x);
        return 1;
    }
    return 0;
}