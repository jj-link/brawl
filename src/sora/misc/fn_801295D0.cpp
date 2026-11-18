#include <gr/collision/gr_collision.h>
#include <mt/mt_coll2d.h>
#include <nw4r/math/math_arithmetic.h>
#include <types.h>
#pragma force_active on

// Approximation: this source has not been verified to match the original code.

struct GroundData {
    u8 padding[0x54];
    u8 flags;
};

struct CollisionEntry {
    grCollisionLine* line;
    GroundData* ground;
    grCollision* collision;
    u8 byte;
    u8 flag : 1;
    u8 rest : 7;

    CollisionEntry() : line(0), ground(0), collision(0), byte(0), flag(0) {}

    bool valid() const {
        return line && ground && collision;
    }

    int enabled() const {
        bool ok = valid();
        if (ok && ((ground->flags >> 4) & 1) && ((*((u8*)collision + 0x2c) >> 7) & 1)) return 1;
        return 0;
    }
};

struct Owner {
    u8 pad00[0x0c];
    u8 flags;
    u8 pad0d[0x0b];
    void* object;
    u8 pad1c[0x2ae];
    u8 collisionFlags;
    u8 pad2cb[0x25];
    float previousY;
    Vec2f contact;
    u8 pad2fc[0x20];
    CollisionEntry contactEntry;
    u8 pad32c[0x18];
    Vec2f previousPosition;
    u8 pad34c[0x24];
    clRhombus2D rhombus;
    u8 pad3a8[0x88];
    Vec2f reference;
};

struct SegmentWithData : clSegment2D {
    u8 data[4];
};

extern "C" {
extern const float lbl_805A29DC;
extern const float lbl_805A29EC;
extern const float lbl_805A29F0;
extern const float lbl_805A29C8;
void fn_80111968(void*, clSegment2D*, grCollisionLine*, int);
void fn_80111AF4(void*, clSegment2D*, grCollisionLine*, int);
void fn_801119F8(grCollision*, clSegment2D*, grCollisionLine*);
int fn_800408C4(const clSegment2D*, const Vec2f*, Vec2f*);
void fn_800429C8(void*, const clSegment2D*, const clSegment2D*);
int fn_80042C74(void*, const Vec2f*);
int fn_80113DF8(const CollisionEntry*, CollisionEntry*);
int fn_80113EC0(const CollisionEntry*, CollisionEntry*);
int fn_801150D0(const CollisionEntry*, CollisionEntry*, float);
int fn_8011557C(const CollisionEntry*, CollisionEntry*, float);
void fn_80125250(Owner*, int, const CollisionEntry*, float);
}

#define segmentContainsX(s, x) \
    ((s).m_p0Pos.m_x <= (x) && (x) <= (s).m_p1Pos.m_x)

static inline void recordContactImpl(Owner* owner, const CollisionEntry* entry, clRhombus2D& rhombus, Vec2f& down) {
    if (!((owner->collisionFlags >> 4) & 1)) {
        owner->collisionFlags |= 0x10;
        owner->contact = rhombus.m_downPos;
        owner->contactEntry = *entry;
    } else if (owner->contact.m_y < down.m_y) {
        owner->contact = rhombus.m_downPos;
        owner->contactEntry = *entry;
    }
}

#define recordContact(owner, entry) recordContactImpl(owner, entry, rhombus, down)

extern "C" int fn_801295D0(
    Owner* owner, const CollisionEntry* entry, int flags
) {
    clRhombus2D& rhombus = owner->rhombus;
    SegmentWithData current;
    SegmentWithData previous;
    u8 swept[0x20];
    struct ExtendedSegment : clSegment2D { u8 data[8]; } segment;
    Vec2f intersection;
    Vec2f displacement;
    Vec2f platformIntersection;
    int moved = 0;
    register float limit;

    fn_80111968(entry->collision, &current, entry->line, 0);
    fn_80111AF4(entry->collision, &previous, entry->line, 0);

    Vec2f& down = rhombus.m_downPos;
    CollisionEntry neighbor;
    CollisionEntry result;

    if (!((owner->flags >> 6) & 1)) {
        int hit = 0;

        if (!fn_800408C4(&current, &down, &intersection) ||
            !(intersection.m_y < rhombus.m_downPos.m_y - lbl_805A29DC)) {
            bool unchanged =
                current.m_p0Pos.m_x == previous.m_p0Pos.m_x &&
                current.m_p0Pos.m_y == previous.m_p0Pos.m_y &&
                current.m_p1Pos.m_x == previous.m_p1Pos.m_x &&
                current.m_p1Pos.m_y == previous.m_p1Pos.m_y;

            if (unchanged) {
                float x = rhombus.m_downPos.m_x;
                if (segmentContainsX(current, x) &&
                    fn_800408C4(&current, &down, &intersection) &&
                    (float)(double)nw4r::math::FAbs(down.m_y - intersection.m_y) <= lbl_805A29EC) {
                    hit = 1;
                }
            } else {
                fn_800429C8(swept, &previous, &current);
                if (fn_80042C74(swept, &down)) {
                    hit = 1;
                } else {
                    float x = rhombus.m_downPos.m_x;
                    float y = rhombus.m_downPos.m_y;
                    Vec2f currentIntersection;
                    Vec2f previousIntersection;
                    if (segmentContainsX(current, x) &&
                        fn_800408C4(&current, &down, &currentIntersection) &&
                        y - lbl_805A29DC <= currentIntersection.m_y) {
                        if (segmentContainsX(previous, x)) {
                            if (fn_800408C4(
                                    &previous, &down, &previousIntersection
                                ) &&
                                previousIntersection.m_y <= y) {
                                hit = 1;
                            } else if (
                                currentIntersection.m_y < rhombus.m_centerPos.m_y
                            ) {
                                hit = 1;
                            }
                        } else if (x < previous.m_p0Pos.m_x) {
                            if (previous.m_p0Pos.m_y <= y) {
                                hit = 1;
                            } else {
                                CollisionEntry next;
                                if (fn_80113EC0(entry, &next) &&
                                    ((*((u8*)next.line + 0x0f) >> 3) & 1)) {
                                    hit = 1;
                                }
                            }
                        } else {
                            if (previous.m_p1Pos.m_y <= y) {
                                hit = 1;
                            } else {
                                CollisionEntry next;
                                if (fn_80113DF8(entry, &next) &&
                                    ((*((u8*)next.line + 0x0f) >> 2) & 1)) {
                                    hit = 1;
                                }
                            }
                        }

                        if (!hit &&
                            fn_8011557C(entry, &result, owner->reference.m_x)) {
                            clSegment2D segment;
                            fn_801119F8(result.collision, &segment, result.line);
                            if (fn_800408C4(&previous, &owner->reference, &previousIntersection) &&
                                previousIntersection.m_y < owner->reference.m_y) {
                                hit = 1;
                            }
                        }
                    }
                }
            }
        }

        if (hit && fn_800408C4(&current, &down, &intersection) &&
            intersection.m_y < owner->previousY - lbl_805A29DC) {
            displacement = (intersection - down) + Vec2f(lbl_805A29F0, lbl_805A29DC);
            if (displacement.m_y > lbl_805A29F0) {
                rhombus.move(displacement);
                moved = 1;
                recordContact(owner, entry);
            }
        }
    }

    if (!moved && segmentContainsX(current, down.m_x) &&
        fn_800408C4(&current, &down, &intersection) &&
        rhombus.m_downPos.m_y < intersection.m_y &&
        fn_801150D0(entry, &result, owner->reference.m_x)) {
        clSegment2D segment;
        Vec2f p;
        result.collision->getSegment(&segment, result.line);
        if (fn_800408C4(&segment, &owner->reference, &p) &&
            p.m_y < owner->reference.m_y) {
            displacement = (intersection - down) + Vec2f(lbl_805A29F0, lbl_805A29DC);
            if (displacement.m_y > lbl_805A29F0) {
                rhombus.move(displacement);
                moved = 1;
                recordContact(owner, entry);
            }
        }
    }

    if (((owner->flags >> 6) & 1) && segmentContainsX(current, down.m_x) &&
        fn_800408C4(&current, &down, &intersection) &&
        down.m_y < intersection.m_y) {
        int hit = 0;
        Vec2f previousPosition;
        __memcpy(&previousPosition, &owner->previousPosition, sizeof(Vec2f));
        if (previousPosition.m_x < current.m_p0Pos.m_x) {
            if (current.m_p0Pos.m_y < previousPosition.m_y) {
                hit = 1;
                goto hit_checked;
            }
        } else if (current.m_p1Pos.m_x < previousPosition.m_x) {
            if (current.m_p1Pos.m_y < previousPosition.m_y) {
                hit = 1;
                goto hit_checked;
            }
        } else {
            if (fn_800408C4(&current, &previousPosition, &platformIntersection) &&
                platformIntersection.m_y < previousPosition.m_y) {
                hit = 1;
                goto hit_checked;
            }
        }

        if (!(rhombus.m_centerPos.m_y < intersection.m_y)) {
            CollisionEntry next;
            if (!(*((u8*)entry->line + 0x10) & 1)) {
                hit = 1;
            } else if (fn_80113EC0(entry, &next) &&
                       ((*((u8*)next.line + 0x0f) >> 3) & 1)) {
                hit = 1;
            } else if (fn_80113DF8(entry, &next) &&
                       ((*((u8*)next.line + 0x0f) >> 3) & 1)) {
                hit = 1;
            }
        }

    hit_checked:
        if (hit) {
            displacement = (intersection - down) + Vec2f(lbl_805A29F0, lbl_805A29DC);
            if (displacement.m_y > lbl_805A29F0) {
                rhombus.move(displacement);
                moved = 1;
                recordContact(owner, entry);
            }
        }
    }

    if ((*(int*)((u8*)owner->object + 8) >> 24) == 1 && (flags & 6)) {
        Vec2f left;
        Vec2f right;
        __memcpy(&left, &current.m_p0Pos, sizeof(Vec2f));
        __memcpy(&right, &current.m_p1Pos, sizeof(Vec2f));

        fn_80113EC0(entry, &neighbor);
        if (neighbor.enabled() && ((*((u8**)&neighbor) + 0x0f)[0] & 1)) {
            fn_80111968(neighbor.collision, &segment, neighbor.line, 0);
            left = segment.m_p1Pos;
        }

        fn_80113DF8(entry, &neighbor);
        if (neighbor.enabled() && ((*((u8**)&neighbor) + 0x0f)[0] & 1)) {
            fn_80111968(neighbor.collision, &segment, neighbor.line, 0);
            right = segment.m_p0Pos;
        }

        register float a = rhombus.m_centerPos.m_y;
        register float b = lbl_805A29C8 + down.m_y;
        asm { ps_sub limit, a, b }
        asm { ps_sel limit, limit, b, a }

        if (left.m_x <= down.m_x && down.m_x <= right.m_x &&
            fn_800408C4(&current, &down, &intersection) &&
            intersection.m_y < limit) {
            displacement = (intersection - down) + Vec2f(lbl_805A29F0, lbl_805A29DC);
            if (displacement.m_y > lbl_805A29F0) {
                rhombus.move(displacement);
                moved = 1;
                recordContact(owner, entry);
                fn_80125250(owner, 3, entry, lbl_805A29C8);
            }
        }
    }

    return moved;
}
