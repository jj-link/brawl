#include <types.h>
#include <gr/collision/gr_collision.h>
#include <mt/mt_coll2d.h>

#pragma force_active on

struct LineFlags {
    u8 pad[15];
    u8 unused : 4;
    u8 right : 1;
    u8 left : 1;
    u8 upper : 1;
    u8 under : 1;
};

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

    bool isRight() const {
        return ((LineFlags*)*(void* const*)this)->right;
    }

    bool isLeft() const {
        return ((LineFlags*)*(void* const*)this)->left;
    }

    bool valid() const {
        bool value = line && ground && collision;
        return value;
    }

    bool different(const Entry& other) const {
        bool value = true;
        if (same(other))
            value = false;
        return value;
    }

    bool same(const Entry& other) const {
        bool value = false;
        if (line == other.line)
            value = true;
        return value;
    }
};

struct Offset : Vec2f {
    Offset(float y, float x) : Vec2f(x, y) {}
};

struct Collection {
    u8 pad[0x1a];
    u16 count;
    Entry* entries;
};

struct Ctx {
    u8 pad[0x1c];
    Collection* collection;
};

struct Cand {
    u32 kind;
    Entry* entry;
};

extern "C" int fn_80113EC0(const Entry&, Entry&);
extern "C" int fn_80113DF8(const Entry&, Entry&);
extern "C" void fn_80116B1C(const Entry&, Entry&);
extern "C" void fn_80116CD8(const Entry&, Entry&);
extern "C" void fn_800407A0(clSegment2D*, const Vec2f&, Vec2f*);
extern "C" int fn_800403C4(clSegment2D*, clSegment2D*);

extern float lbl_805A2960;
extern float lbl_805A29A4;

extern "C" int fn_80120BB0(Ctx* self, Vec2f* pos, Cand* cand) {
    clSegment2D seg, other, rightSeg, leftSeg;
    Entry rec = *cand->entry;
    Entry right, left, temp;
    Vec2f displacement;
    Vec2f intersection;
    Vec2f intersection2;

    rec.collision->getSegment(&seg, rec.line);

    if ((s32)((cand->kind << 8) & 0xff800000) >> 24 == 1) {
        if (fn_80113EC0(rec, right) && right.isRight()) {
            right.collision->getSegment(&rightSeg, right.line);
            fn_800407A0(
                &rightSeg,
                seg.m_p0Pos + Offset(lbl_805A29A4, lbl_805A2960),
                &intersection);
            displacement = intersection - *pos;
        } else {
            displacement =
                (seg.m_p0Pos + Offset(lbl_805A29A4, lbl_805A2960)) - *pos;
        }
    } else {
        if (fn_80113DF8(rec, left) && left.isLeft()) {
            left.collision->getSegment(&leftSeg, left.line);
            fn_800407A0(
                &leftSeg,
                seg.m_p1Pos + Offset(lbl_805A29A4, lbl_805A2960),
                &intersection2);
            displacement = intersection2 - *pos;
        } else {
            displacement =
                (seg.m_p1Pos + Offset(lbl_805A29A4, lbl_805A2960)) - *pos;
        }
    }

    GroundData* ground;
    u16 count;
    Entry* e;
    u32 offset;
    s32 mode;
    int result;
    u32 i;

    mode = (s32)((cand->kind << 8) & 0xff800000) >> 24;

    clSegment2D ray;
    __memcpy(&ray.m_p0Pos, pos, sizeof(Vec2f));
    __memcpy(&ray.m_p1Pos, &displacement, sizeof(Vec2f));

    fn_80113EC0(rec, right);
    fn_80113DF8(rec, left);

    result = 1;
    i = 0;
    ground = rec.ground;
    count = self->collection->count;
    offset = 0;

    for (; i < count; offset += 0x10, i++) {
        e = (Entry*)((char*)self->collection->entries + offset);

        if (rec.same(*e))
            continue;

        if (mode == 0) {
            if (((LineFlags*)e->line)->left && left.same(*e))
                continue;
            if (((LineFlags*)e->line)->upper && left.same(*e))
                continue;
        } else {
            if (((LineFlags*)e->line)->right && right.same(*e))
                continue;
            if (((LineFlags*)e->line)->upper && right.same(*e))
                continue;
        }

        e->collision->getSegment(&other, e->line);

        if (!fn_800403C4(&ray, &other))
            continue;

        if (e->ground == ground) {
            s32 side = (s32)((cand->kind << 8) & 0xff800000) >> 24;

            if (side == 1) {
                if (((LineFlags*)e->line)->left) {
                    result = 0;
                    break;
                } else if (((LineFlags*)e->line)->right) {
                    fn_80116B1C(*e, temp);
                    fn_80113DF8(temp, left);
                    if (left.valid())
                        left = left;
                } else if (((LineFlags*)e->line)->upper) {
                    result = 0;
                    break;
                } else if (((LineFlags*)e->line)->under &&
                           e->different(right)) {
                    result = 0;
                    break;
                }
            } else if (side == 0) {
                if (((LineFlags*)e->line)->right) {
                    result = 0;
                    break;
                } else if (((LineFlags*)e->line)->left) {
                    fn_80116CD8(*e, temp);
                    fn_80113EC0(temp, left);
                    if (left.valid())
                        left = left;
                } else if (((LineFlags*)e->line)->upper) {
                    result = 0;
                    break;
                } else if (((LineFlags*)e->line)->under &&
                           e->different(left)) {
                    result = 0;
                    break;
                }
            }
        } else {
            result = 0;
            break;
        }
    }

    return result;
}
