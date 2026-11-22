#include <mt/mt_coll2d.h>
#include <types.h>
#pragma force_active on

struct GroundData {
    u8 pad[0x54];
    u8 flags;
};

struct Entry {
    u8* line;
    GroundData* ground;
    u8* collision;
    u8 byte;
    u8 flag : 1;
    u8 rest : 7;

    Entry() : line(0), ground(0), collision(0), byte(0), flag(0) {}

    bool valid() const {
        int result = 0;
        if (*(u32*)&line && ground && collision)
            result = 1;
        return result;
    }

    bool enabledLast() const {
        bool ok = line && ground && collision;
        if (ok && ((ground->flags >> 4) & 1) &&
            ((collision[0x2c] >> 7) & 1))
            return true;
        return false;
    }

    bool enabled() const {
        bool ok = valid();
        if (ok && ((ground->flags >> 4) & 1) &&
            ((collision[0x2c] >> 7) & 1))
            return true;
        return false;
    }
};

struct Segment : clSegment2D { int extra; };

struct CollisionState {
    u8 pad0[0x14];
    u16 mask;
    u8 pad16[2];
    void* filter;
    u8 pad1c[0x2ca - 0x1c];
    u8 flags;
    u8 pad2cb[0x2e4 - 0x2cb];
    float previousX;
    u8 pad2e8[4];
    Vec2f lowerHit;
    Vec2f upperHit;
    u8 pad2fc[8];
    Vec2f rightHit;
    Entry lowerEntry;
    Entry upperEntry;
    u8 pad32c[0x370 - 0x32c];
    clRhombus2D rhombus;
};

extern const float lbl_805A29C8, lbl_805A29DC, lbl_805A29F0, lbl_805A29F4;

extern "C" int fn_80113EC0(const Entry*, Entry*);
extern "C" int fn_80113DF8(const Entry*, Entry*);
extern "C" void fn_80111968(void*, clSegment2D*, void*, int);
extern "C" void fn_801119F8(void*, clSegment2D*, void*);
extern "C" int fn_8004094C(const void*, const void*, Vec2f*);
extern "C" int fn_800408C4(const void*, const void*, Vec2f*);
extern "C" void fn_80125250(CollisionState*, int, const Entry*, float);
extern "C" int fn_80137114(void*, const Entry*);

/*
 * This reconstruction has not been verified against the original machine code.
 */
extern "C" int fn_80127524(CollisionState* self, const Entry* entry, int mode) {
    clRhombus2D* rhombus = &self->rhombus;
    int moved = 0;
    Segment otherSegment;
    Segment segment;
    Segment edge;
    Entry next;
    Entry previous;
    Vec2f intersection;
    Vec2f displacement;
    Vec2f previousIntersection;

    fn_80113EC0(entry, &next);
    fn_80113DF8(entry, &previous);
    fn_80111968(entry->collision, &segment, entry->line, 0);
    {
    Vec2f* right = &rhombus->m_rightPos;

    if (segment.m_p0Pos.m_y <= right->m_y &&
        right->m_y <= segment.m_p1Pos.m_y &&
        fn_8004094C(&segment, right, &intersection)) {
        int shouldMove = 0;

        if (self->previousX < intersection.m_x) {
            shouldMove = 1;
        } else {
            clSegment2D oldSegment;
            fn_801119F8(entry->collision, &oldSegment, entry->line);
            if (oldSegment.m_p0Pos.m_y <= right->m_y &&
                right->m_y <= oldSegment.m_p1Pos.m_y) {
                if (fn_8004094C(&oldSegment, right, &previousIntersection) &&
                    right->m_x < previousIntersection.m_x) {
                    shouldMove = 1;
                }
            } else if (oldSegment.m_p0Pos.m_y > right->m_y) {
                if (right->m_x < oldSegment.m_p0Pos.m_x)
                    shouldMove = 1;
            } else if (right->m_x < oldSegment.m_p1Pos.m_x) {
                shouldMove = 1;
            }
        }

        if (shouldMove) {
            displacement = (intersection - rhombus->m_rightPos) + Vec2f(lbl_805A29F4, lbl_805A29F0);
            if (displacement.m_x < lbl_805A29F0) {
                rhombus->move(displacement);
                moved = 1;
                if (!((self->flags >> 7) & 1)) {
                    self->flags |= 0x80;
                    self->rightHit = rhombus->m_rightPos;
                    fn_80125250(self, 2, entry, lbl_805A29C8);
                } else if (rhombus->m_rightPos.m_x < self->rightHit.m_x) {
                    self->rightHit = rhombus->m_rightPos;
                    fn_80125250(self, 2, entry, lbl_805A29C8);
                }
            }
        }
    }

    }
    if (fn_8004094C(&segment, rhombus, &intersection)) {
        register f32 a, b, c;
        b = self->previousX;
        a = rhombus->m_centerPos.m_x;
        asm { ps_sub c, a, b }
        asm { ps_sel c, c, b, a }
        if (intersection.m_x <= c)
            return moved;
    }

    if (previous.enabled() && (previous.line[0xf] & 1)) {
        int found;
        float y = segment.m_p1Pos.m_y;
        Vec2f* right = &rhombus->m_rightPos;
        if (rhombus->m_downPos.m_y <= y &&
            y <= right->m_y) {
        found = 0;
        edge.m_p0Pos = rhombus->m_downPos;
        edge.m_p1Pos = *right;

        if (segment.m_p1Pos.m_y <= right->m_y &&
            fn_8004094C(&edge, &segment.m_p1Pos, &intersection)) {
            found = 1;
            displacement = (segment.m_p1Pos - intersection) + Vec2f(lbl_805A29F4, lbl_805A29F0);
        } else if (fn_8004094C(&segment, right, &intersection)) {
            found = 1;
            displacement = (intersection - *right) + Vec2f(lbl_805A29F4, lbl_805A29F0);
        }

        if (found && displacement.m_x < lbl_805A29F0) {
            rhombus->move(displacement);
            moved = 1;
            if (!((self->flags >> 7) & 1)) {
                self->flags |= 0x80;
                self->rightHit = rhombus->m_rightPos;
            } else if (rhombus->m_rightPos.m_x < self->rightHit.m_x) {
                self->rightHit = rhombus->m_rightPos;
            }
        }
    }

    }

    if (next.enabled() && ((next.line[0xf] >> 1) & 1)) {
        Vec2f* right = &rhombus->m_rightPos;
        f32 rightY, y;
        y = segment.m_p0Pos.m_y;
        edge.m_p0Pos = *right;
        edge.m_p1Pos = rhombus->m_upPos;
        rightY = right->m_y;

        if (rightY <= y &&
            y <= rhombus->m_upPos.m_y) {
            int found = 0;

            if (right->m_y <= segment.m_p0Pos.m_y &&
                fn_8004094C(&edge, &segment.m_p0Pos, &intersection)) {
                found = 1;
                displacement = (segment.m_p0Pos - intersection) + Vec2f(lbl_805A29F4, lbl_805A29F0);
            } else if (fn_8004094C(&segment, right, &intersection)) {
                found = 1;
                displacement = (intersection - *right) + Vec2f(lbl_805A29F4, lbl_805A29F0);
            }

            if (found && displacement.m_x < lbl_805A29F0) {
                rhombus->move(displacement);
                moved = 1;
                if (!((self->flags >> 7) & 1)) {
                    self->rightHit = rhombus->m_rightPos;
                    self->flags |= 0x80;
                } else if (rhombus->m_rightPos.m_x < self->rightHit.m_x) {
                    self->rightHit = rhombus->m_rightPos;
                }
            }
        }
    }

    if ((mode & 1) && previous.enabled() && ((previous.line[0xf] >> 1) & 1)) {
        Vec2f* up = &rhombus->m_upPos;

        if (fn_8004094C(&segment, up, &intersection)) {
            displacement = (intersection - *up) + Vec2f(lbl_805A29F4, lbl_805A29F0);
            if (displacement.m_x < lbl_805A29F0) {
                rhombus->move(displacement);
                moved = 1;
                if (!((self->flags >> 7) & 1)) {
                    self->rightHit = rhombus->m_rightPos;
                } else if (rhombus->m_rightPos.m_x < self->rightHit.m_x) {
                    self->rightHit = rhombus->m_rightPos;
                }
                self->flags |= 0x80;
            }
        }

        fn_80111968(previous.collision, &otherSegment, previous.line, 0);
        if (otherSegment.m_p1Pos.m_x <= up->m_x &&
            fn_800408C4(&otherSegment, up, &intersection)) {
            displacement = (intersection - *up) + Vec2f(lbl_805A29F0, lbl_805A29F4);
            if (displacement.m_y < lbl_805A29F0) {
                rhombus->move(displacement);
                moved = 1;
                if (!((self->flags >> 5) & 1)) {
                    self->lowerHit = *up;
                    self->lowerEntry = *entry;
                } else if (self->lowerHit.m_y > up->m_y) {
                    self->lowerHit = *up;
                    self->lowerEntry = *entry;
                }
                self->flags |= 0x20;
            }
        }
    }

    if (next.enabledLast() && (((u8*)*(u32*)&next.line)[0xf] & 1) &&
        !(*(u16*)(next.line + 0x10) & self->mask) &&
        !fn_80137114(self->filter, &next)) {
        Vec2f* down = &rhombus->m_downPos;

        fn_80111968(next.collision, &otherSegment, next.line, 0);
        if (fn_800408C4(&otherSegment, rhombus, &intersection) &&
            rhombus->m_centerPos.m_y > intersection.m_y) {
            if (fn_8004094C(&segment, down, &intersection) &&
                rhombus->m_leftPos.m_x < intersection.m_x) {
                displacement = (intersection - *down) + Vec2f(lbl_805A29F4, lbl_805A29F0);
                if (displacement.m_x < lbl_805A29F0) {
                    rhombus->move(displacement);
                    moved = 1;
                    if (!((self->flags >> 7) & 1)) {
                        self->flags |= 0x80;
                        self->rightHit = rhombus->m_rightPos;
                    } else if (rhombus->m_rightPos.m_x < self->rightHit.m_x) {
                        self->rightHit = rhombus->m_rightPos;
                    }
                }
            }

            if (otherSegment.m_p0Pos.m_x <= down->m_x &&
                fn_800408C4(&otherSegment, down, &intersection)) {
                displacement = (intersection - *down) + Vec2f(lbl_805A29F0, lbl_805A29DC);
                if (displacement.m_y > lbl_805A29F0) {
                    displacement.m_x = otherSegment.m_p1Pos.m_x - down->m_x - lbl_805A29DC;
                    if (displacement.m_x > lbl_805A29F0)
                        displacement.m_x = lbl_805A29F0;
                    rhombus->move(displacement);
                    moved = 1;
                    if (!((self->flags >> 4) & 1)) {
                        self->flags |= 0x10;
                        self->upperHit = *down;
                        self->upperEntry = next;
                    } else if (self->upperHit.m_y < down->m_y) {
                        self->upperHit = *down;
                        self->upperEntry = next;
                    }
                }
            }
        }
    }

    return moved;
}
