#pragma force_active on
#pragma fp_contract on
#include <nw4r/ut/ut_algorithm.h>

extern float lbl_805A4654;
extern float lbl_805A4658;
extern float lbl_805A465C;
extern float lbl_805A4660;

struct Vec { float x, y, z, w; } __attribute__((aligned(16)));
struct Plane { float value; char pad[12]; float tolerance; };
struct Result { char pad[0xc0]; Vec normal; Vec point; char rest[0x30]; } __attribute__((aligned(16)));
extern "C" void fn_803130EC(void*, Result*, float);

extern "C" float fn_80313520(void* obj, Plane* plane, Vec* point, float* out, float a, float b, float va, float vb) {
    float one, upper, lower, negTolerance, result, tolerance;
    tolerance = lbl_805A4654 * plane->tolerance;
    lower = lbl_805A4658;
    upper = lbl_805A465C;
    one = lbl_805A4660;
    negTolerance = -tolerance;
    result = a;
    int i = 0;
    do {
        if (va <= plane->value) break;
        float delta = vb - va;
        if (delta > negTolerance) break;
        float t = (plane->value - va) / delta;
        t = t > lower ? t : lower;
        t = t < upper ? t : upper;
        result = a * (one - t) + b * t;
        Result r;
        fn_803130EC(obj, &r, result);
        Vec diff;
        diff.x = point->x - r.point.x;
        diff.y = point->y - r.point.y;
        diff.z = point->z - r.point.z;
        diff.w = point->w - r.point.w;
        float target = plane->value;
        float value = r.normal.w + (r.normal.x * diff.x + r.normal.y * diff.y + r.normal.z * diff.z);
        signed char close = (float)(double)nw4r::ut::Abs(value - target) < tolerance;
        if ((unsigned int)(-close | close) >> 31) break;
        if (value < target) {
            b = result;
            vb = value;
        } else {
            a = result;
            va = value;
        }
        ++i;
    } while (i < 10);
    if (result < *out) *out = result;
    return result;
}