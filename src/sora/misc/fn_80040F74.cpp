#include <mt/mt_vector.h>
#pragma force_active on
extern "C" int fn_80040C00(const Vec2f*, const Vec2f*, float*);
extern "C" int fn_80040F74(const Vec2f* line, const Vec2f* other, Vec2f* out) {
    float t;
    int result = fn_80040C00(line, other, &t);
    if (result) {
        *out = line[0] + (line[1] - line[0]) * t;
    }
    return result;
}