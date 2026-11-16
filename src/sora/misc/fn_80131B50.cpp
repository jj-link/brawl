#include <mt/mt_coll2d.h>
#include <gr/collision/gr_collision.h>
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
        if (ok && ((ground->flags >> 4) & 1) && ((*(u8*)((char*)collision + 0x2c) >> 7) & 1))
            return 1;
        return 0;
    }
};

struct Object {
    u8 pad[0x380];
    Vec2f previous0;
    Vec2f previous1;
    u8 pad2[0x3ac - 0x390];
    clRhombus2D rhombus;
};

struct Segment : clSegment2D {
    int extra;
};

struct Offset : Vec2f {
    Offset(float y, float x) : Vec2f(x, y) {}
};

extern "C" {
int fn_80113DF8(const Entry&, Entry&);
void fn_80111968(grCollision*, Segment*, grCollisionLine*, int);
void fn_800429C8(void*, Segment*, Segment*);
int fn_80042FB4(void*, Segment*);
int fn_80042C74(void*, Vec2f*);
int fn_8004094C(Segment*, Vec2f*, Vec2f*);
int fn_80115E44(Entry*, Entry*);
void fn_80125250(Object*, int, Entry*, float);
}

extern "C" float lbl_805A29C8;
extern "C" float lbl_805A29DC;
extern "C" float lbl_805A29F0;

extern "C" void fn_80131B50(Object* self, Entry* in, float* out) {
    clRhombus2D* rhombus = &self->rhombus;
    int didMove = 0;
    Entry current;
    Entry found;
    char area[32];
    Segment segment;
    Segment previous;
    Segment now;
    Segment other;
    Vec2f intersection;
    Vec2f displacement;

    fn_80113DF8(*in, current);
    fn_80111968(in->collision, &segment, in->line, 0);
    fn_80111968(current.collision, &other, current.line, 0);

    previous.m_p0Pos = self->previous0;
    previous.m_p1Pos = self->previous1;
    previous.extra = 0;
    now.m_p0Pos = rhombus->m_downPos;
    now.m_p1Pos = rhombus->m_leftPos;
    now.extra = 0;

    bool same = previous.m_p0Pos.m_x == now.m_p0Pos.m_x &&
                previous.m_p0Pos.m_y == now.m_p0Pos.m_y;

    if (!same) {
        bool same2 = previous.m_p1Pos.m_x == now.m_p1Pos.m_x &&
                     previous.m_p1Pos.m_y == now.m_p1Pos.m_y;

        if (!same2) {
            fn_800429C8(area, &previous, &now);
            if (!fn_80042FB4(area, &segment))
                goto done;
            if (!fn_80042C74(area, &segment.m_p1Pos))
                goto done;

            if (segment.m_p1Pos.m_y < now.m_p1Pos.m_y) {
                Vec2f* point;
                if (fn_8004094C(&now, (point = &segment.m_p1Pos), &intersection)) {
                    displacement = (*point - intersection) +
                                   Offset(lbl_805A29F0, lbl_805A29DC);
                    if (displacement.m_x > lbl_805A29F0)
                        didMove = 1;
                }
            } else if (other.m_p0Pos.m_y < rhombus->m_upPos.m_y) {
                now.m_p0Pos = rhombus->m_upPos;
                now.m_p1Pos = rhombus->m_leftPos;
                Vec2f* point;
                if (fn_8004094C(&now, (point = &other.m_p0Pos), &intersection)) {
                    displacement = (*point - intersection) +
                                   Offset(lbl_805A29F0, lbl_805A29DC);
                    if (displacement.m_x > lbl_805A29F0)
                        didMove = 1;
                }
            } else {
                Vec2f* up = &rhombus->m_upPos;
                float otherX = other.m_p1Pos.m_x;
                int hit = 0;
                float upX = up->m_x;

                if (otherX <= upX) {
                    if (other.m_p1Pos.m_y <= up->m_y && up->m_y <= other.m_p0Pos.m_y)
                        hit = 1;
                } else if (fn_80115E44(&current, &found)) {
                    if (found.enabled()) {
                        hit = 1;
                        fn_80111968(found.collision, &other, found.line, 0);
                    }
                }

                if (hit) {
                    Vec2f* point;
                    if (fn_8004094C(&other, (point = up), &intersection)) {
                        displacement = (intersection - *point) +
                                       Offset(lbl_805A29F0, lbl_805A29DC);
                        if (displacement.m_x > lbl_805A29F0)
                            didMove = 1;
                    }
                }
            }

            if (didMove) {
                rhombus->move(displacement);
                fn_80125250(self, 6, in, *out = lbl_805A29C8);
            }
        }
    }

done:
    return;
}
