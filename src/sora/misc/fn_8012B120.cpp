#include <mt/mt_coll2d.h>
#include <types.h>

#pragma force_active on

struct Outer {
    u8 pad0[0x2ca];
    u8 flags;
    u8 pad1[0x378 - 0x2cb];
    Vec2f a;
    Vec2f b;
    u8 pad2[0x3b4 - 0x388];
    Vec2f c;
    Vec2f d;
    u8 pad3[0x458 - 0x3c4];
    u16 f458;
    u16 f45a;
};

struct Entry {
    void* line;
    void* ground;
    void* collision;
    u8 byte;
    u8 flag : 1;

    Entry() : line(0), ground(0), collision(0), byte(0), flag(0) {}

    bool valid() const {
        return line && ground && collision;
    }
};

extern float lbl_805A29F0;

extern "C" void fn_80111968(void*, void*, void*, int);
extern "C" int fn_80125308(Vec2f*, Vec2f*, clSegment2D*, float*);
extern "C" void fn_80125250(Outer*, int, Entry*, float);
extern "C" int fn_800408C4(clSegment2D*, Vec2f*, Vec2f*);
extern "C" int fn_801167A4(Entry*, Entry*);
extern "C" int fn_80116960(Entry*, Entry*);
extern "C" int fn_80113EC0(Entry*, Entry*);
extern "C" int fn_80113DF8(Entry*, Entry*);
extern "C" void fn_801251F8(Outer*, Entry*);

extern "C" int fn_8012B120(Outer* self, Entry* arg, float* value) {
    struct Segment : clSegment2D {
        u8 extra[8];
    } seg;
    int result = 0;
    int done = 0;

    fn_80111968(arg->collision, &seg, arg->line, 0);

    Vec2f start;
    Vec2f end;
    Vec2f delta;
    float hit;

    if (!(self->f45a & 2)) {
        start = self->b;
        end = self->d;
        delta = end - start;
        result = fn_80125308(&start, &delta, &seg, &hit);

        if (result > 0) {
            fn_80125250(self, 3, arg, hit);
            register f32 v;
            register f32 h;
            register f32 diff;
            h = hit;
            v = *value;
            asm {
                ps_sub diff, v, h
                ps_sel diff, diff, h, v
            }
            *value = diff;
            self->f458 |= 8;
            self->flags |= 0x10;
        } else if (seg.m_p0Pos.m_x <= end.m_x &&
                   end.m_x <= seg.m_p1Pos.m_x) {
            Vec2f point;
            if (fn_800408C4(&seg, &end, &point) && end.m_y < point.m_y) {
                bool valid = false;
                Entry next;
                Entry other;

                if (delta.m_x > lbl_805A29F0) {
                    if (fn_801167A4(arg, &next)) {
                        if (next.line && next.ground && next.collision)
                            valid = true;

                        int enabled;
                        if (valid && ((((u8*)next.ground)[0x54] >> 4) & 1) &&
                            ((((u8*)next.collision)[0x2c] >> 7) & 1))
                            enabled = 1;
                        else
                            enabled = 0;

                        if (enabled && !fn_80113EC0(&next, &other))
                            done = 1;
                    }
                } else if (delta.m_x < lbl_805A29F0) {
                    if (fn_80116960(arg, &next)) {
                        if (next.line && next.ground && next.collision)
                            valid = true;

                        int enabled;
                        if (valid && ((((u8*)next.ground)[0x54] >> 4) & 1) &&
                            ((((u8*)next.collision)[0x2c] >> 7) & 1))
                            enabled = 1;
                        else
                            enabled = 0;

                        if (enabled && !fn_80113DF8(&next, &other))
                            done = 1;
                    }
                }

                if (done)
                    fn_801251F8(self, arg);
            }
        }
    }

    if ((unsigned)done != 1) {
        Entry next;
        if (!(fn_80113EC0(arg, &next) && ((((u8*)next.line)[0xf] >> 3) & 1)) &&
            !(fn_80113DF8(arg, &next) && ((((u8*)next.line)[0xf] >> 2) & 1))) {
            start = self->a;
            end = self->c;
            delta = end - start;

            int below = 0;
            Vec2f point;

            if (start.m_x < seg.m_p0Pos.m_x) {
                if (start.m_y < seg.m_p0Pos.m_y)
                    below = 1;
            } else if (seg.m_p1Pos.m_x < start.m_x) {
                if (start.m_y < seg.m_p1Pos.m_y)
                    below = 1;
            } else if (fn_800408C4(&seg, &start, &point) &&
                       start.m_y < point.m_y) {
                below = 1;
            }

            if (below && seg.m_p0Pos.m_x <= end.m_x &&
                end.m_x <= seg.m_p1Pos.m_x &&
                fn_800408C4(&seg, &end, &point) &&
                point.m_y <= end.m_y) {
                fn_801251F8(self, arg);
            }
        }
    }

    return result > 0;
}
