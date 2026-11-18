#include <gr/collision/gr_collision.h>
#include <mt/mt_coll2d.h>
#include <mt/mt_vector.h>
#include <types.h>

#pragma force_active on

struct GroundData {
    u8 pad[0x54];
    u8 flags;
};

struct Entry {
    grCollisionLine* line;
    GroundData* ground;
    grCollision* collision;
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
};

struct Self {
    u8 pad0[0x380];
    Vec2f m_pos;
    u8 pad1[0x8];
    Vec2f m_prevPos;
    u8 pad2[0x14];
    clRhombus2D m_rhombus;
};

struct Segment : clSegment2D {
    s32 extra;
};

struct Offset : Vec2f {
    Offset(f32 y, f32 x) : Vec2f(x, y) {}
};

extern "C" {
extern f32 lbl_805A29C8;
extern f32 lbl_805A29F0;
extern f32 lbl_805A29F4;
void fn_80113EC0(const Entry& in, Entry& out);
void fn_80111968(grCollision* coll, clSegment2D* seg, grCollisionLine* line, int unk);
void fn_800429C8(void* out, Segment* a, Segment* b);
int fn_80042FB4(void* out, Segment* seg);
int fn_80042C74(void* out, Vec2f* point);
int fn_8004094C(Segment* seg, Vec2f* point, Vec2f* out);
int fn_801162F4(const Entry& in, Entry& out);
void fn_80125250(Self* self, s32 id, Entry* arg1, f32 f);
}

extern "C" void fn_801316A0(Self* self, Entry* arg1, f32* arg2) {
    clRhombus2D& rh = self->m_rhombus;
    int moved = 0;
    Entry eA0;
    Entry e90;
    char buf100[32];
    Segment seg0;
    Segment segSelf;
    Segment segRh;
    Segment segB0;
    Vec2f pt88;
    Vec2f sp80;

    fn_80113EC0(*arg1, eA0);
    fn_80111968(arg1->collision, &seg0, arg1->line, 0);
    fn_80111968(eA0.collision, &segB0, eA0.line, 0);

    segSelf.m_p0Pos = self->m_pos;
    segSelf.m_p1Pos = self->m_prevPos;
    segSelf.extra = 0;
    segRh.m_p0Pos = rh.m_downPos;
    segRh.m_p1Pos = rh.m_rightPos;
    segRh.extra = 0;

    int same = 0;
    if (segSelf.m_p0Pos.m_x == segRh.m_p0Pos.m_x &&
        segSelf.m_p0Pos.m_y == segRh.m_p0Pos.m_y)
        same = 1;
    if (same == 0) {
        same = 0;
        if (segSelf.m_p1Pos.m_x == segRh.m_p1Pos.m_x &&
            segSelf.m_p1Pos.m_y == segRh.m_p1Pos.m_y)
            same = 1;
        if (same == 0) {
            fn_800429C8(buf100, &segSelf, &segRh);
            if (fn_80042FB4(buf100, &seg0) != 0 &&
                fn_80042C74(buf100, &seg0.m_p0Pos) != 0) {
                if (segRh.m_p1Pos.m_y > seg0.m_p0Pos.m_y) {
                    Vec2f* point;
                    if (fn_8004094C(&segRh, (point = &seg0.m_p0Pos), &pt88) != 0) {
                        sp80 = (*point - pt88) + Offset(lbl_805A29F0, lbl_805A29F4);
                        if (sp80.m_x < lbl_805A29F0)
                            moved = 1;
                    }
                } else if (segB0.m_p1Pos.m_y < rh.m_upPos.m_y) {
                    segRh.m_p0Pos = rh.m_upPos;
                    segRh.m_p1Pos = rh.m_rightPos;
                    Vec2f* point;
                    if (fn_8004094C(&segRh, (point = &segB0.m_p1Pos), &pt88) != 0) {
                        sp80 = (*point - pt88) + Offset(lbl_805A29F0, lbl_805A29F4);
                        if (sp80.m_x < lbl_805A29F0)
                            moved = 1;
                    }
                } else {
                    Vec2f* up = &rh.m_upPos;
                    int r28 = 0;
                    if (up->m_x <= segB0.m_p0Pos.m_x) {
                        if (segB0.m_p0Pos.m_y <= up->m_y &&
                            up->m_y <= segB0.m_p1Pos.m_y)
                            r28 = 1;
                    } else if (fn_801162F4(eA0, e90) != 0) {
                        if (e90.enabled()) {
                            r28 = 1;
                            fn_80111968(e90.collision, &segB0, e90.line, 0);
                        }
                    }
                    if (r28 != 0) {
                        if (fn_8004094C(&segB0, up, &pt88) != 0) {
                            sp80 = (pt88 - *up) + Offset(lbl_805A29F0, lbl_805A29F4);
                            if (sp80.m_x < lbl_805A29F0)
                                moved = 1;
                        }
                    }
                }

                if (moved) {
                    rh.move(sp80);
                    fn_80125250(self, 7, arg1, *arg2 = lbl_805A29C8);
                }
            }
        }
    }
}