#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(Vec2f*);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual unsigned long long slot9();
};

struct Self {
    char pad0[0xe];
    unsigned char flags;
    char pad1[0x2c0 - 0xf];
    Object_vptr_0* target;
    Object_vptr_0* source;
    char pad2[0xc];
    float x;
};

struct Arg {
    void* node;
    char pad[4];
    void* owner;
};

struct Pair {
    unsigned long a;
    unsigned long b;
};

struct Segment {
    Vec2f a;
    Vec2f b;
    char padding[16];
};

extern "C" void fn_80111968(void*, Segment*, void*, int);
extern float lbl_805A2994;
extern float lbl_805A2960;

static inline bool isFinite(float value) {
    bool finite = true;
    if (((*(unsigned long*)&value >> 23) & 0xff) == 0xff)
        finite = false;
    return finite;
}

static inline void setPoint(Vec2f& point, float x, float y) {
    point.m_x = x;
    point.m_y = y;
}

extern "C" void fn_8011A02C(Self* self, Arg* arg, int mode) {
    Segment segment;
    Vec2f start, end, result;
    Pair position;
    Vec2f point;
    unsigned long long value = self->source->slot9();
    position = *(Pair*)&value;
    fn_80111968(arg->owner, &segment, arg->node, 0);

    if (self->flags & 2) {
        start = segment.a;
        end = segment.b;
        if (mode)
            end.m_x -= lbl_805A2994;
    } else {
        start = segment.b;
        end = segment.a;
        if (mode)
            end.m_x -= lbl_805A2994;
    }

    if (mode) {
        result = end;
    } else {
        setPoint(point, self->x, *(float*)&position.b);
        float dx = end.m_x - start.m_x;
        float absDx = (float)(double)nw4r::math::FAbs(dx);
        float t;

        if (absDx > lbl_805A2994)
            t = (point.m_x - start.m_x) / dx;
        else
            t = (point.m_y - start.m_y) / (end.m_y - start.m_y);

        if (!isFinite(t))
            t = lbl_805A2960;

        result = start + (end - start) * t;
    }

    self->target->slot3(&result);
}
