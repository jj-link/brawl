#include <types.h>
#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
#include <nw4r/math/math_types.h>
#include <nw4r/math/math_arithmetic.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(Vec2f*);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual nw4r::math::_VEC2 slot10();
};

struct Object_vptr_32c_base {
    char pad0[4];
    float f4;
    char pad8[6];
    u8 flagE;
    char padF[0x2bc - 0xf];
    Object_vptr_0* p2bc;
    Object_vptr_0* p2c0;
    Object_vptr_0* p2c4;
    char pad2c8[0x32c - 0x2c8];
};
class Object_vptr_32c : public Object_vptr_32c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(float, float, float);
};

struct Arg1 {
    void* node;
    char pad4[4];
    void* owner;
};

struct Segment {
    Vec2f a;
    Vec2f b;
};

extern "C" float lbl_805A2994;
extern "C" float lbl_805A2960;
extern "C" float lbl_805A295C;
extern "C" void fn_80111968(void*, Segment*, void*, int);

inline float lowerBound(float value, float lo) {
    return nw4r::math::FSelect(value - lo, value, lo);
}

extern "C" void fn_8011A4D8(Object_vptr_32c* self, Arg1* arg1) {
    Segment seg;
    Vec2f A, B;
    Vec2f P;
    nw4r::math::_VEC2 cv;
    nw4r::math::_VEC2 c2;
    nw4r::math::_VEC2 value = self->p2c4->slot10();
    __memcpy(&cv, &value, sizeof(cv));

    fn_80111968(arg1->owner, &seg, arg1->node, 0);

    int var = 0;
    if (self->flagE & 4) {
        A = seg.b;
        B = seg.a;
        if (cv.y > B.m_y) {
            var = 1;
            B.m_y = B.m_y + self->f4;
        }
    } else {
        A = seg.a;
        B = seg.b;
        if (cv.y < B.m_y) {
            var = 1;
            B.m_y = B.m_y - self->f4;
        }
    }

    if (var) {
        P = B;
    } else {
        float dy = B.m_y - A.m_y;
        float t;
        float absolute = (float)(double)nw4r::ut::Abs(dy);
        if (absolute > lbl_805A2994)
            t = (cv.y - A.m_y) / dy;
        else
            t = (cv.x - A.m_x) / (B.m_x - A.m_x);
        P = A + (B - A) * t;
    }

    __memcpy(&c2, &self->p2bc->slot10(), sizeof(c2));
    float d = cv.y - c2.y;
    float absolute = (float)(double)nw4r::ut::Abs(d);
    if (absolute > lbl_805A2994) {
        float c0 = lowerBound((P.m_y - c2.y) / d, lbl_805A2960);
        float c1 = nw4r::math::FSelect(c0 - lbl_805A295C, lbl_805A295C, c0);
        self->slot2(c1, lbl_805A295C, c0 - lbl_805A295C);
    }

    self->p2c0->slot4(&P);
}
