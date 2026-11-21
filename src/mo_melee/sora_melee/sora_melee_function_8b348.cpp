#pragma force_active on
#pragma fp_contract off
#include <nw4r/math/math_arithmetic.h>
#include <nw4r/math/math_types.h>
struct Vec2 {
    float x, y;
    Vec2(float a, float b) : x(a), y(b) {}
};
class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_8B348();
    virtual Vec2 fn_27_8A624();
    char pad04[4];
    Vec2 v8, v10, v18, v20, v28;
    char pad30[4];
    float f34;
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
};
extern "C" const float lbl_27_rodata_BE0[];
extern "C" float rsqrtf__Ff(float);
extern "C" void fn_27_8A098(soNullable*, void*);
inline bool nearZero(float x, const float* c) {
    bool result = false;
    if ((float)(double)nw4r::math::FAbs(x) < c[2])
        result = true;
    return result;
}
inline bool isZero(Vec2 v, const float* c) {
    bool result = false;
    if (nearZero(v.x, c)) {
        if (nearZero(v.y, c)) result = true;
    }
    return result;
}
inline float lengthSquared(Vec2 v) { return v.x * v.x + v.y * v.y; }
inline nw4r::math::VEC2 scale(const Vec2& v, float delta, float len, const float* c) {
    float s = delta / len - c[4];
    nw4r::math::VEC2 r;
    r.x = v.x * s;
    r.y = v.y * s;
    return r;
}
extern "C" void fn_27_8B348(soNullable* self, void* arg) {
    const float* c = lbl_27_rodata_BE0;
    if (isZero(self->fn_27_8A624(), c)) {
        self->v8 = Vec2(c[1], c[1]);
        self->v20 = Vec2(c[1], c[1]);
    } else if (self->f34 > c[1]) {
        float len = lengthSquared(self->fn_27_8A624());
        if ((float)(double)nw4r::math::FAbs(len) <= c[3])
            len = c[1];
        else
            len = len * rsqrtf__Ff(len);
        float delta = len - self->f34;
        if (delta < c[1]) {
            self->v20 = Vec2(c[1], c[1]);
            self->v10 = Vec2(c[1], c[1]);
            self->v8 = Vec2(c[1], c[1]);
        } else {
            nw4r::math::VEC2 out = scale(self->fn_27_8A624(), delta, len, c);
            self->v10.x = out.x;
            self->v10.y = out.y;
        }
    }
    fn_27_8A098(self, arg);
}