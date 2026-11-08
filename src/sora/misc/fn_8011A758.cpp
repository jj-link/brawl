#include <types.h>
#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
#include <nw4r/math/math_types.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7(Vec2f*);
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual nw4r::math::_VEC2 slot12();
};

struct Self {
    u8 pad[14];
    u8 flag;
    u8 pad2[0x2c0 - 15];
    Object_vptr_0* output;
    Object_vptr_0* input;
};

struct Source {
    void* node;
    u32 pad;
    void* owner;
};

struct Segment {
    Vec2f a;
    Vec2f b;
    float extra;
};

extern "C" void fn_80111968(void*, Segment*, void*, int);
extern "C" float lbl_805A2994;

extern "C" void fn_8011A758(Self* self, Source* source) {
    Segment segment;
    Vec2f other, corner;
    nw4r::math::_VEC2 point;
    Vec2f result;
    nw4r::math::_VEC2 p0 = self->input->slot12();
    __memcpy(&point, &p0, sizeof(point));

    fn_80111968(source->owner, &segment, source->node, 0);

    int flag = 0;
    if (self->flag & 2) {
        other = segment.b;
        corner = segment.a;
        if (point.x > corner.m_x)
            flag = 1;
    } else {
        other = segment.a;
        corner = segment.b;
        if (point.x < corner.m_x)
            flag = 1;
    }

    if (flag) {
        result = corner;
    } else {
        float dx = corner.m_x - other.m_x;
        float t;
        float absolute = (float)(double)nw4r::ut::Abs(dx);
        if (absolute > lbl_805A2994)
            t = (point.x - other.m_x) / dx;
        else
            t = (point.y - other.m_y) / (corner.m_y - other.m_y);
        result = other + (corner - other) * t;
    }

    self->output->slot7(&result);
}
