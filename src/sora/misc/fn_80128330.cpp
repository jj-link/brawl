#include <mt/mt_coll2d.h>
#include <types.h>
#pragma force_active on

struct GroundData {
    u8 pad[0x54];
    u8 flags;
};

struct CollisionEntry {
    void* line;
    GroundData* ground;
    void* collision;
    u8 byte;
    u8 flag : 1;
    u8 rest : 7;

    CollisionEntry() : line(0), ground(0), collision(0), byte(0), flag(0) {}

    bool valid() const {
        int result = 0;
        if (*(u32*)&line && ground && collision)
            result = 1;
        return result;
    }

    bool enabledLast() const {
        bool ok = line && ground && collision;
        if (ok && ((ground->flags >> 4) & 1) &&
            ((((u8*)collision)[0x2c] >> 7) & 1))
            return true;
        return false;
    }

    bool enabled() const {
        if (valid() && ((ground->flags >> 4) & 1) &&
            ((((u8*)collision)[0x2c] >> 7) & 1))
            return true;
        return false;
    }
};

struct Segment {
    Vec2f p0;
    Vec2f p1;
    u32 extra;
};

struct CollisionState {
    u8 pad0[0x14];
    u16 mask;
    u8 pad16[2];
    void* owner;
    u8 pad1c[0x2ca - 0x1c];
    u8 flags;
    u8 pad2cb[0x2e4 - 0x2cb];
    float limitX;
    u8 pad2e8[4];
    Vec2f ceilingPos;
    Vec2f floorPos;
    Vec2f wallPos;
    u8 pad304[8];
    CollisionEntry ceilingEntry;
    CollisionEntry floorEntry;
    u8 pad32c[0x370 - 0x32c];
    clRhombus2D rhombus;
};

extern const float lbl_805A29C8;
extern const float lbl_805A29DC;
extern const float lbl_805A29F0;
extern const float lbl_805A29F4;

extern "C" int fn_80113EC0(const CollisionEntry&, CollisionEntry&);
extern "C" int fn_80113DF8(const CollisionEntry&, CollisionEntry&);
extern "C" void fn_80111968(void*, Segment*, void*, int);
extern "C" void fn_80111AF4(void*, Segment*, void*, int);
extern "C" int fn_8004094C(const void*, const void*, Vec2f*);
extern "C" int fn_800408C4(const void*, const void*, Vec2f*);
extern "C" void fn_80125250(CollisionState*, int, const CollisionEntry&, float);
extern "C" int fn_80137114(void*, const CollisionEntry&);

extern "C" int fn_80128330(CollisionState* state,
                            const CollisionEntry& entry,
                            int options) {
    clRhombus2D* rhombus = &state->rhombus;
    int moved = 0;
    CollisionEntry next;
    CollisionEntry prev;
    Segment other;
    Segment segment;
    Segment edge;
    Segment adjacent;
    Vec2f point;
    Vec2f displacement;
    Vec2f adjacentPoint;

    fn_80113EC0(entry, next);
    fn_80113DF8(entry, prev);
    fn_80111968(entry.collision, &segment, entry.line, 0);

    {
        Vec2f* left = &rhombus->m_leftPos;

        if (segment.p1.m_y <= left->m_y &&
            left->m_y <= segment.p0.m_y &&
            fn_8004094C(&segment, left, &point)) {
            int accept = 0;

            if (point.m_x < state->limitX) {
                accept = 1;
            } else {
                fn_80111AF4(entry.collision, &adjacent, entry.line, 0);
                if (adjacent.p0.m_y >= left->m_y &&
                    left->m_y >= adjacent.p1.m_y) {
                    if (fn_8004094C(&adjacent, left, &adjacentPoint) &&
                        adjacentPoint.m_x < left->m_x)
                        accept = 1;
                } else if (adjacent.p0.m_y < left->m_y) {
                    if (adjacent.p0.m_x < left->m_x)
                        accept = 1;
                } else if (adjacent.p1.m_x < left->m_x) {
                    accept = 1;
                }
            }

            if (accept) {
                displacement = (point - *left) + Vec2f(lbl_805A29DC, lbl_805A29F0);
                if (displacement.m_x > lbl_805A29F0) {
                    rhombus->move(displacement);
                    moved = 1;
                    if (!((state->flags >> 6) & 1)) {
                        state->flags |= 0x40;
                        state->wallPos = rhombus->m_leftPos;
                        fn_80125250(state, 1, entry, lbl_805A29C8);
                    } else if (state->wallPos.m_x < rhombus->m_leftPos.m_x) {
                        state->wallPos = rhombus->m_leftPos;
                        fn_80125250(state, 1, entry, lbl_805A29C8);
                    }
                }
            }
        }
    }

    if (fn_8004094C(&segment, rhombus, &point)) {
        register f32 a, b, c;
        b = state->limitX;
        a = rhombus->m_centerPos.m_x;
        asm { ps_sub c, a, b }
        asm { ps_sel c, c, a, b }
        if (c <= point.m_x) {
            return moved;
        }
    }

    if (next.enabled() && (((u8*)next.line)[0x0f] & 1)) {
        float y = segment.p0.m_y;
        Vec2f* left = &rhombus->m_leftPos;
        if (rhombus->m_downPos.m_y <= y && y <= left->m_y) {
            int hit = 0;
            edge.p0 = rhombus->m_downPos;
            edge.p1 = *left;

            if (segment.p0.m_y <= left->m_y &&
                fn_8004094C(&edge, &segment, &point)) {
                hit = 1;
                displacement = (segment.p0 - point) + Vec2f(lbl_805A29DC, lbl_805A29F0);
            } else if (fn_8004094C(&segment, left, &point)) {
                hit = 1;
                displacement = (point - *left) + Vec2f(lbl_805A29DC, lbl_805A29F0);
            }

            if (hit & (displacement.m_x > lbl_805A29F0)) {
                rhombus->move(displacement);
                moved = 1;
                if (!((state->flags >> 6) & 1)) {
                    state->wallPos = rhombus->m_leftPos;
                    state->flags |= 0x40;
                } else if (rhombus->m_leftPos.m_x > state->wallPos.m_x) {
                    state->wallPos = rhombus->m_leftPos;
                }
            }
        }
    }

    if (prev.enabled() && ((((u8*)prev.line)[0x0f] >> 1) & 1)) {
        Vec2f* left = &rhombus->m_leftPos;
        f32 leftY, y;
        y = segment.p1.m_y;
        edge.p0 = rhombus->m_leftPos;
        edge.p1 = rhombus->m_upPos;
        leftY = left->m_y;

        if (leftY <= y &&
            y <= rhombus->m_upPos.m_y) {
            if (leftY <= y &&
                fn_8004094C(&edge, &segment.p1, &point)) {
                displacement = (segment.p1 - point) + Vec2f(lbl_805A29DC, lbl_805A29F0);
                if (displacement.m_x > lbl_805A29F0) {
                    rhombus->move(displacement);
                    moved = 1;
                    if (!((state->flags >> 6) & 1))
                        state->wallPos = rhombus->m_leftPos;
                    else if (rhombus->m_leftPos.m_x > state->wallPos.m_x)
                        state->wallPos = rhombus->m_leftPos;
                    state->flags |= 0x40;
                }
            } else if (fn_8004094C(&segment, left, &point)) {
                displacement = (point - *left) + Vec2f(lbl_805A29DC, lbl_805A29F0);
                if (displacement.m_x > lbl_805A29F0) {
                    rhombus->move(displacement);
                    moved = 1;
                    if (!((state->flags >> 6) & 1))
                        state->wallPos = rhombus->m_leftPos;
                    else if (rhombus->m_leftPos.m_x < state->wallPos.m_x)
                        state->wallPos = rhombus->m_leftPos;
                    state->flags |= 0x40;
                }
            }
        }
    }

    if ((options & 8) && next.enabled() &&
        ((((u8*)next.line)[0x0f] >> 1) & 1)) {
        Vec2f* up = &rhombus->m_upPos;

        if (fn_8004094C(&segment, up, &point)) {
            displacement = (point - *up) + Vec2f(lbl_805A29DC, lbl_805A29F0);
            if (displacement.m_x > lbl_805A29F0) {
                rhombus->move(displacement);
                moved = 1;
                if (!((state->flags >> 6) & 1))
                    state->wallPos = rhombus->m_leftPos;
                else if (state->wallPos.m_x < rhombus->m_leftPos.m_x)
                    state->wallPos = rhombus->m_leftPos;
                state->flags |= 0x40;
            }
        }

        fn_80111968(next.collision, &other, next.line, 0);
        if (up->m_x <= other.p0.m_x &&
            fn_800408C4(&other, up, &point)) {
            displacement = (point - *up) + Vec2f(lbl_805A29F0, lbl_805A29F4);
            if (displacement.m_y < lbl_805A29F0) {
                rhombus->move(displacement);
                moved = 1;
                if (!((state->flags >> 5) & 1)) {
                    state->ceilingPos = *up;
                    state->ceilingEntry = entry;
                } else if (state->ceilingPos.m_y > up->m_y) {
                    state->ceilingPos = *up;
                    state->ceilingEntry = entry;
                }
                state->flags |= 0x20;
            }
        }
    }

    if (prev.enabledLast() && (((u8*)*(u32*)&prev.line)[0x0f] & 1) &&
        !(*(u16*)((u8*)prev.line + 0x10) & state->mask) &&
        !fn_80137114(state->owner, prev)) {
        Vec2f* down = &rhombus->m_downPos;
        fn_80111968(prev.collision, &other, prev.line, 0);

        if (fn_800408C4(&other, rhombus, &point) &&
            rhombus->m_centerPos.m_y > point.m_y) {
            if (fn_8004094C(&segment, down, &point) &&
                point.m_x < rhombus->m_rightPos.m_x) {
                displacement = (point - *down) + Vec2f(lbl_805A29DC, lbl_805A29F0);
                if (displacement.m_x > lbl_805A29F0) {
                    rhombus->move(displacement);
                    moved = 1;
                    if (!((state->flags >> 6) & 1)) {
                        state->flags |= 0x40;
                        state->wallPos = rhombus->m_leftPos;
                    } else if (state->wallPos.m_x < rhombus->m_leftPos.m_x) {
                        state->wallPos = rhombus->m_leftPos;
                    }
                }
            }

            if (down->m_x <= other.p1.m_x &&
                fn_800408C4(&other, down, &point)) {
                displacement = (point - *down) + Vec2f(lbl_805A29F0, lbl_805A29DC);
                if (displacement.m_y > lbl_805A29F0) {
                    displacement.m_x = lbl_805A29DC + (other.p0.m_x - down->m_x);
                    if (displacement.m_x < lbl_805A29F0)
                        displacement.m_x = lbl_805A29F0;
                    rhombus->move(displacement);
                    moved = 1;
                    if (!((state->flags >> 4) & 1)) {
                        state->flags |= 0x10;
                        state->floorPos = *down;
                        state->floorEntry = prev;
                    } else if (state->floorPos.m_y < down->m_y) {
                        state->floorPos = *down;
                        state->floorEntry = prev;
                    }
                }
            }
        }
    }

    return moved;
}
