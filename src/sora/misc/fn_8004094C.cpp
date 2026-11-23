#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
extern float lbl_805A17AC;
struct Vec2Base { float x; float y; };
struct Vec2 : Vec2Base {
    Vec2() {}
    Vec2(float b, float a) { y = b; x = a; }
    Vec2 operator-(const Vec2& b) const {
        Vec2 result;
        result.x = x - b.x;
        result.y = y - b.y;
        return result;
    }
};
struct Line { Vec2 start; Vec2 end; };
extern "C" int fn_8004094C(const Line* line, const Vec2* p, Vec2* out) {
    Vec2 d = line->end - line->start;
    double ay = nw4r::math::FAbs(d.y);
    if ((float)ay > lbl_805A17AC) {
        out->y = p->y;
        out->x = line->start.x + d.x * ((p->y - line->start.y) / d.y);
        return 1;
    }
    return 0;
}