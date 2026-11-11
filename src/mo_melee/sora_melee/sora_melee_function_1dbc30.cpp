#pragma force_active on
#include <types.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_types.h>
#include <nw4r/ut/ut_algorithm.h>

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_1DBC30();
    virtual Vec2f fn_27_8A624();

    char pad0[0xC];
    Vec2f out;
    char pad1[0x8];
    Vec2f delta;
    char pad2[0xC];
    int state;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
};

extern "C" const float lbl_27_rodata_27A0[];
extern "C" void fn_27_8A098(void*, int);

inline nw4r::math::VEC2 scaleVector(const Vec2f& value, float diff, float length, const float* c) {
    float t = diff / length - c[4];
    nw4r::math::VEC2 result;
    result.x = value.m_x * t;
    result.y = value.m_y * t;
    return result;
}

extern "C" void fn_27_1DBC30(soNullable* self, int arg1) {
    const float* c = lbl_27_rodata_27A0;
    switch (self->state) {
    case 0:
        break;
    case 1: {
        float len_sq = self->fn_27_8A624().lengthSq();
        float len;
        if ((float)(double)nw4r::ut::Abs(len_sq) <= c[2])
            len = c[1];
        else
            len = len_sq * rsqrtf(len_sq);

        if (len <= c[3]) {
            self->out = Vec2f(c[1], c[1]);
        } else if (len > c[3]) {
            float cx = self->delta.m_x;
            float cy = self->delta.m_y;
            float len2_sq = cx * cx + cy * cy;
            float len2;
            if ((float)(double)nw4r::ut::Abs(len2_sq) <= c[2])
                len2 = c[1];
            else
                len2 = len2_sq * rsqrtf(len2_sq);

            float diff = len - len2;
            if (diff < c[1]) {
                self->out = Vec2f(c[1], c[1]);
            } else {
                nw4r::math::VEC2 out = scaleVector(self->fn_27_8A624(), diff, len, c);
                self->out.m_x = out.x;
                self->out.m_y = out.y;
            }
        }
    }
    }
    fn_27_8A098(self, arg1);
}
