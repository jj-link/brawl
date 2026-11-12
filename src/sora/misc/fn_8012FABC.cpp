#include <mt/mt_coll2d.h>
#include <types.h>

#pragma force_active on

struct GroundData {
    u8 pad[0x54];
    u8 flags;
};

struct Entry {
    void* line;
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
};

struct Offset : Vec2f {
    Offset(float y, float x) : Vec2f(x, y) {}
};

struct Segment : clSegment2D {
    int extra;
};

struct Self {
    u8 pad[0x380];
    Vec2f prev0;
    u8 pad2[8];
    Vec2f prev1;
    u8 pad3[0x14];
    clRhombus2D rhombus;
};

extern float lbl_805A29C8, lbl_805A29F0, lbl_805A29F4;

extern "C" {
void fn_80111968(void*, void*, void*, int);
void fn_800429C8(void*, Segment*, Segment*);
int fn_80042FB4(void*, Segment*);
int fn_80042C74(void*, Vec2f*);
int fn_8004094C(Segment*, Vec2f*, Vec2f*);
int fn_801162F4(Entry*, Entry*);
void fn_80125250(Self*, int, Entry*, float);
}

extern "C" void fn_8012FABC(Self* self, Entry* arg, float* result) {
    clRhombus2D* rhombus = &self->rhombus;
    char area[32];
    Segment line;
    Segment previous;
    Segment now;
    Vec2f intersection;
    Vec2f displacement;

    fn_80111968(arg->collision, &line, arg->line, 0);
    Entry found;
    int didMove = 0;

    previous.m_p0Pos = self->prev0;
    previous.m_p1Pos = self->prev1;
    previous.extra = 0;
    now.m_p0Pos = rhombus->m_downPos;
    now.m_p1Pos = rhombus->m_rightPos;
    now.extra = 0;

    bool same = false;
    if (previous.m_p0Pos.m_x == now.m_p0Pos.m_x && previous.m_p0Pos.m_y == now.m_p0Pos.m_y)
        same = true;
    if (!same) {
        bool same2 = false;
        if (previous.m_p1Pos.m_x == now.m_p1Pos.m_x && previous.m_p1Pos.m_y == now.m_p1Pos.m_y)
            same2 = true;
        if (!same2) {
            fn_800429C8(area, &previous, &now);
            if (fn_80042FB4(area, &line) && fn_80042C74(area, &line.m_p1Pos)) {
                if (line.m_p1Pos.m_y < now.m_p1Pos.m_y) {
                    Vec2f* point;
                    if (fn_8004094C(&now, (point = &line.m_p1Pos), &intersection)) {
                        displacement = (*point - intersection) + Offset(lbl_805A29F0, lbl_805A29F4);
                        if (displacement.m_x < lbl_805A29F0)
                            didMove = 1;
                    }
                } else {
                    int use = 0;
                    Vec2f* pos = &now.m_p1Pos;
                    if (now.m_p1Pos.m_y >= line.m_p0Pos.m_y) {
                        use = 1;
                    } else if (fn_801162F4(arg, &found) != 0) {
                        if (found.enabled()) {
                            fn_80111968(found.collision, &line, found.line, 0);
                            use = 1;
                        }
                    }
                    if (use && fn_8004094C(&line, pos, &intersection)) {
                        displacement = (intersection - *pos) + Offset(lbl_805A29F0, lbl_805A29F4);
                        if (displacement.m_x < lbl_805A29F0)
                            didMove = 1;
                    }
                }
                if (didMove) {
                    rhombus->move(displacement);
                    fn_80125250(self, 7, arg, *result = lbl_805A29C8);
                }
            }
        }
    }
}
