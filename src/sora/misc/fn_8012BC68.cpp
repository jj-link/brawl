#include <mt/mt_coll2d.h>
#include <nw4r/math/math_arithmetic.h>
#include <types.h>
#pragma force_active on

struct Segment {
    Vec2f a, b;
    float extra;
};

struct GroundData {
    u8 pad[0x54];
    u8 flags;
};

struct Line {
    u8 pad[15];
    u8 flags;
    u16 mask;
};

struct Entry {
    Line* line;
    GroundData* ground;
    void* collision;
    u8 byte;
    u8 flag : 1;
    u8 rest : 7;

    Entry() : line(0), ground(0), collision(0), byte(0), flag(0) {}

    bool valid() const {
        return line && ground && collision;
    }

    bool enabled() const {
        return valid() && ((ground->flags >> 4) & 1) &&
            ((*(u8*)((char*)collision + 0x2c) >> 7) & 1);
    }
};

struct Owner {
    u8 pad[8];
    int kind;
};

struct Outer {
    u8 pad0[0x14];
    u16 mask;
    u8 pad1[2];
    Owner* owner;
    u8 pad2[0x2ca - 0x1c];
    u8 flags;
    u8 pad3[0x370 - 0x2cb];
    Vec2f points[8];
    u8 gap[4];
    Vec2f endLeft, endRight, unused, endTop;
    u8 pad4[0x458 - 0x3d4];
    u16 state;
    u16 disabled;
};

extern "C" {
extern float lbl_805A29DC, lbl_805A29F0, lbl_805A29C8;

void fn_80111968(void*, Segment*, Line*, int);
int fn_80125308(Vec2f*, Vec2f*, Segment*, float*);
void fn_80125250(Outer*, int, const Entry*, float);
int fn_8004094C(Segment*, Vec2f*, Vec2f*);
int fn_800408C4(Segment*, Vec2f*, Vec2f*);
int fn_80113DF8(const Entry*, Entry*);
int fn_80113EC0(const Entry*, Entry*);
int fn_80137114(Owner*, Entry*);
}

static inline float PsSelectValue(float cur, float t) {
    register f32 a;
    register f32 b;
    register f32 diff;
    a = cur;
    b = t;
    asm { ps_sub diff, a, b }
    asm { ps_sel diff, diff, b, a }
    return diff;
}

extern "C" int fn_8012BC68(Outer* self, const Entry* entry, float* result) {
    Segment segment;
    Segment leftSegment;
    Segment rightSegment;
    Vec2f start;
    Vec2f end;
    Vec2f delta;
    Vec2f hit;
    float time;
    Vec2f* points;
    int found = 0;

    fn_80111968(entry->collision, &segment, entry->line, 0);
    points = self->points;

    if (!(self->disabled & 4)) {
        start = points[4];
        end = self->endTop;
        delta = end - start;
        found = fn_80125308(&start, &delta, &segment, &time);
        if (found > 0) {
            fn_80125250(self, 2, entry, time);
            *result = PsSelectValue(*result, time);
            self->state |= 2;
            self->flags |= 0x80;
        }
    }

    if (fn_8004094C(&segment, points, &hit) && hit.m_x < points[0].m_x)
        return found > 0;

    if (!(self->disabled & 1)) {
        Entry next;
        fn_80113DF8(entry, &next);

        bool valid = next.valid();
        int enabled;
        if (valid && ((next.ground->flags >> 4) & 1) &&
            ((*(u8*)((char*)next.collision + 0x2c) >> 7) & 1))
            enabled = 1;
        else
            enabled = 0;

        if (enabled && ((*(u8*)((char*)*(Line**)&next + 0xf) >> 1) & 1)) {
            start = points[1];
            end = self->endLeft;
            delta = end - start;
            fn_80111968(next.collision, &leftSegment, next.line, 0);

            Vec2f crossing;
            if (leftSegment.b.m_x <= end.m_x &&
                fn_800408C4(&leftSegment, &end, &crossing) &&
                crossing.m_y > start.m_y && end.m_y >= crossing.m_y) {
                float numerator = (crossing.m_y - lbl_805A29DC) - start.m_y;
                const float& value = numerator / (end.m_y - start.m_y);
                const float& lower = nw4r::math::FSelect(
                    value - lbl_805A29F0, value, lbl_805A29F0);
                time = nw4r::math::FSelect(
                    lower - lbl_805A29C8, lbl_805A29C8, lower);

                fn_80125250(self, 0, &next, time);
                *result = PsSelectValue(*result, time);
                self->state |= 4;
                self->flags |= 0x20;

                found = fn_80125308(&start, &delta, &segment, &time);
                if (found > 0) {
                    fn_80125250(self, 2, entry, time);
                    *result = PsSelectValue(*result, time);
                    self->state |= 2;
                    self->flags |= 0x80;
                }
            }
        }
    }

    if (!(self->disabled & 2)) {
        Entry next;
        fn_80113EC0(entry, &next);

        bool valid = next.valid();
        int enabled;
        if (valid && ((next.ground->flags >> 4) & 1) &&
            ((*(u8*)((char*)next.collision + 0x2c) >> 7) & 1))
            enabled = 1;
        else
            enabled = 0;

        if (enabled && ((*(Line**)&next)->flags & 1) &&
            !(next.line->mask & self->mask) &&
            !fn_80137114(self->owner, &next)) {
            start = points[2];
            end = self->endRight;
            delta = end - start;
            fn_80111968(next.collision, &rightSegment, next.line, 0);

            Vec2f crossing;
            if (rightSegment.a.m_x <= end.m_x &&
                fn_800408C4(&rightSegment, &end, &crossing) &&
                crossing.m_y < start.m_y && end.m_y <= crossing.m_y) {
                const float& value = ((lbl_805A29DC + crossing.m_y) - start.m_y) /
                              (end.m_y - start.m_y);
                float lower = nw4r::math::FSelect(
                    value - lbl_805A29F0, value, lbl_805A29F0);
                time = nw4r::math::FSelect(
                    lower - lbl_805A29C8, lbl_805A29C8, lower);

                fn_80125250(self, 3, &next, time);
                *result = PsSelectValue(*result, time);
                self->state |= 2;
                self->flags |= 0x10;

                found = fn_80125308(&start, &delta, &segment, &time);
                if (found > 0) {
                    fn_80125250(self, 2, entry, time);
                    *result = PsSelectValue(*result, time);
                    self->state |= 2;
                    self->flags |= 0x80;
                }
            }
        }
    }

    if ((self->owner->kind >> 24) == 1 && !(self->disabled & 2)) {
        start = points[2];
        end = self->endRight;
        delta = end - start;
        found = fn_80125308(&start, &delta, &segment, &time);
        if (found > 0) {
            fn_80125250(self, 2, entry, time);
            *result = PsSelectValue(*result, time);
            self->state |= 2;
            self->flags |= 0x80;
        }
    }

    return found > 0;
}
