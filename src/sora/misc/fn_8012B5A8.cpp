#include <types.h>
#include <mt/mt_coll2d.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

struct GroundData {
    u8 pad[0x54];
    u8 flags;
};

struct CollisionLine {
    u8 pad[0xf];
    u8 otherFlags : 6;
    u8 nextFlag : 1;
    u8 previousFlag : 1;
    u16 mask;
};

struct Entry {
    CollisionLine* line;
    GroundData* ground;
    void* collision;
    u8 byte;
    u8 flag : 1;
    u8 rest : 7;

    Entry() : line(0), ground(0), collision(0), byte(0), flag(0) {}

    bool valid() const {
        return line && ground && collision;
    }

    int enabled() const {
        bool ok = valid();
        if (ok && ((ground->flags >> 4) & 1) &&
            ((*(u8*)((char*)collision + 0x2c) >> 7) & 1))
            return 1;
        return 0;
    }

    CollisionLine* const& getLine() const {
        return line;
    }

    bool hasNextFlag() const {
        return getLine()->nextFlag;
    }

    bool hasPreviousFlag() const {
        return getLine()->previousFlag;
    }
};

struct Segment : clSegment2D {
    int extra;
};

struct Self {
    u8 pad0[0x14];
    u16 mask;
    u8 pad1[2];
    void* object;
    u8 pad2[0x2ca - 0x1c];
    u8 flags;
    u8 pad3[0x370 - 0x2cb];
    clRhombus2D rhombus;
    u8 pad4[0x3b4 - 0x3a8];
    Vec2f previousUp;
    Vec2f previousDown;
    Vec2f previousLeft;
    u8 pad5[0x458 - 0x3cc];
    u16 f458;
    u16 f45a;
};

extern f32 lbl_805A29C8;
extern f32 lbl_805A29DC;
extern f32 lbl_805A29F0;

extern "C" {
void fn_80111968(void*, Segment*, void*, int);
int fn_80125308(Vec2f*, Vec2f*, Segment*, f32*);
void fn_80125250(Self*, int, Entry*, f32);
int fn_8004094C(Segment*, Vec2f*, Vec2f*);
int fn_800408C4(Segment*, Vec2f*, Vec2f*);
int fn_80113EC0(const Entry&, Entry&);
int fn_80113DF8(const Entry&, Entry&);
int fn_80137114(void*, Entry*);
}

#define LIMIT_HIT(v) do { \
    f32 t = nw4r::math::FSelect((v) - lbl_805A29F0, (v), lbl_805A29F0); \
    (v) = nw4r::math::FSelect(t - lbl_805A29C8, lbl_805A29C8, t); \
} while (0)

#define minimum(value, hit) do { \
    register f32 v, h, diff; \
    h = hit; \
    v = *value; \
    asm { ps_sub diff, v, h } \
    asm { ps_sel diff, diff, h, v } \
    *value = diff; \
} while (0)

extern "C" int fn_8012B5A8(Self* self, Entry* arg, f32* value) {
    Segment seg;
    clRhombus2D* rhombus;
    int result = 0;

    fn_80111968(arg->collision, &seg, arg->line, 0);
    rhombus = &self->rhombus;

    Vec2f start, end, delta;
    f32 hit;

    if (!(self->f45a & 8)) {
        start = rhombus->m_leftPos;
        end = self->previousLeft;
        delta = end - start;
        result = fn_80125308(&start, &delta, &seg, &hit);

        if (result > 0) {
            fn_80125250(self, 1, arg, hit);
            minimum(value, hit);
            self->f458 |= 1;
            self->flags |= 0x40;
        }
    }

    Vec2f point;
    if (fn_8004094C(&seg, &rhombus->m_centerPos, &point) &&
        rhombus->m_centerPos.m_x < point.m_x)
        return result > 0;

    if (!(self->f45a & 1)) {
        Entry next;
        fn_80113EC0(*arg, next);

        if (next.enabled() && next.hasNextFlag()) {
            start = rhombus->m_upPos;
            end = self->previousUp;
            delta = end - start;

            Segment nextSeg;
            fn_80111968(next.collision, &nextSeg, next.line, 0);

            Vec2f intersection;
            if (end.m_x <= nextSeg.m_p0Pos.m_x &&
                fn_800408C4(&nextSeg, &end, &intersection) &&
                intersection.m_y > start.m_y &&
                end.m_y >= intersection.m_y) {
                hit = ((intersection.m_y - lbl_805A29DC) - start.m_y) /
                      (end.m_y - start.m_y);
                LIMIT_HIT(hit);
                fn_80125250(self, 0, &next, hit);
                minimum(value, hit);
                self->f458 |= 4;
                self->flags |= 0x20;

                result = fn_80125308(&start, &delta, &seg, &hit);
                if (result > 0) {
                    fn_80125250(self, 1, arg, hit);
                    minimum(value, hit);
                    self->f458 |= 1;
                    self->flags |= 0x40;
                }
            }
        }
    }

    if (!(self->f45a & 2)) {
        Entry next;
        fn_80113DF8(*arg, next);

        if (next.enabled() &&
            next.hasPreviousFlag() &&
            !(next.line->mask & self->mask) &&
            !fn_80137114(self->object, &next)) {
            start = rhombus->m_downPos;
            end = self->previousDown;
            delta = end - start;

            Segment nextSeg;
            fn_80111968(next.collision, &nextSeg, next.line, 0);

            Vec2f intersection;
            if (end.m_x <= nextSeg.m_p1Pos.m_x &&
                fn_800408C4(&nextSeg, &end, &intersection) &&
                intersection.m_y < start.m_y &&
                end.m_y <= intersection.m_y) {
                hit = ((lbl_805A29DC + intersection.m_y) - start.m_y) /
                      (end.m_y - start.m_y);
                LIMIT_HIT(hit);
                fn_80125250(self, 3, &next, hit);
                minimum(value, hit);
                self->f458 |= 1;
                self->flags |= 0x10;

                result = fn_80125308(&start, &delta, &seg, &hit);
                if (result > 0) {
                    fn_80125250(self, 1, arg, hit);
                    minimum(value, hit);
                    self->f458 |= 1;
                    self->flags |= 0x40;
                }
            }
        }
    }

    if ((*(s32*)((char*)self->object + 8) >> 24) == 1 &&
        !(self->f45a & 2)) {
        start = rhombus->m_downPos;
        end = self->previousDown;
        delta = end - start;

        if (fn_80125308(&start, &delta, &seg, &hit) > 0) {
            fn_80125250(self, 1, arg, hit);
            minimum(value, hit);
            self->f458 |= 1;
            self->flags |= 0x40;
        }
    }

    return result > 0;
}
