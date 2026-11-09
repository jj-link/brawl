#include <types.h>
#include <gr/collision/gr_collision.h>
#include <gr/collision/gr_collision_line.h>
#include <mt/mt_coll2d.h>

#pragma force_active on

extern float lbl_805A2994;

struct Pair {
    s32 hi;
    s32 lo;
};

union FloatBits {
    Pair p;
    float f;
};

class Obj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(float* p);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual Pair slot9();
};

struct Data {
    u8 pad[0x0c];
    u32 word0c;
    u8 pad2[0x62];
    u8 byte72;
};

struct Self {
    u8 pad[0x0e];
    u8 flag;
    u8 pad2[9];
    Data* data;
    u8 pad3[4];
    int mode;
    u8 pad4[0x298];
    Obj* obj;
};

struct Arg1 {
    grCollisionLine* line;
    u8 pad[4];
    grCollision* collision;
};

extern "C" int fn_8011DD10(Self* self, Arg1* arg1) {
    Data* data = self->data;
    int mode;
    int result = 0;
    if ((data->byte72 >> 5) & 1) {
        mode = self->mode;
        if (!(mode == 1 && ((s32)((data->word0c << 8) & 0xFF800000) >> 24) == 1 && (self->flag & 2))) {
            if (!(mode == 0 && ((s32)((data->word0c << 8) & 0xFF800000) >> 24) == 0 && (self->flag & 1))) {
                clSegment2D seg;
                FloatBits fb;

                arg1->collision->getSegment(&seg, arg1->line);

                fb.p = self->obj->slot9();

                if (fb.f <= seg.m_p0Pos.m_x) {
                    fb.f = lbl_805A2994 + seg.m_p0Pos.m_x;
                } else if (seg.m_p1Pos.m_x <= fb.f) {
                    fb.f = seg.m_p1Pos.m_x - lbl_805A2994;
                }

                self->obj->slot3(&fb.f);
                result = 1;
            }
        }
    }
    return result;
}
