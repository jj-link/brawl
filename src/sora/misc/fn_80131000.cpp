#include <types.h>
#include <mt/mt_vector.h>
#include <mt/mt_coll2d.h>

#pragma force_active on

struct Seg : clSegment2D {
    s32 flag;
};

extern "C" {
s32 fn_80113EC0(void*, void*);
void fn_80111968(void*, void*, void*, s32);
void fn_800429C8(void*, void*, void*);
s32 fn_80042FB4(void*, void*);
s32 fn_80042C74(void*, Vec2f*);
s32 fn_8004094C(Seg*, Vec2f*, Vec2f*);
s32 fn_80115E44(void*, void*);
void fn_80125250(void*, s32, void*, f32);
}

extern f32 lbl_805A29C8, lbl_805A29DC, lbl_805A29F0;

struct Entry {
    void* line;
    void* ground;
    void* collision;
    u8 byte;
    u8 flag : 1;
    u8 rest : 7;

    Entry() : line(0), ground(0), collision(0), byte(0), flag(0) {}
    bool valid() const { return line && ground && collision; }
    int enabled() const {
        bool ok = valid();
        if (ok && ((*(u8*)((char*)ground + 0x54) >> 4) & 1) &&
            ((*(u8*)((char*)collision + 0x2c) >> 7) & 1)) return 1;
        return 0;
    }
};

struct ObjB {
    u8 pad[0x54];
    u8 flags;
};

struct ObjC {
    u8 pad[0x2C];
    u8 flags;
};

struct Offset : Vec2f {
    Offset(f32 y, f32 x) : Vec2f(x, y) {}
};

struct Self {
    u8 pad0[0x378];
    Vec2f m_378;
    Vec2f m_380;
    Vec2f m_388;
    u8 pad1[0x3AC - 0x390];
    clRhombus2D m_rhombus;
};

extern "C" void fn_80131000(Self* self, Entry* arg1, f32* out) {
    clRhombus2D* rh = &self->m_rhombus;
    s32 moved = 0;
    Entry la, lb;
    char area[32];
    Seg line, prev, cur, seg;
    Vec2f q, r;

    fn_80113EC0(arg1, &la);
    fn_80111968(arg1->collision, &line, arg1->line, 0);

    prev.m_p0Pos.m_x = self->m_378.m_x;
    prev.m_p0Pos.m_y = self->m_378.m_y;
    prev.m_p1Pos.m_x = self->m_388.m_x;
    prev.m_p1Pos.m_y = self->m_388.m_y;
    prev.flag = 0;

    cur.m_p0Pos.m_x = rh->m_upPos.m_x;
    cur.m_p0Pos.m_y = rh->m_upPos.m_y;
    cur.m_p1Pos.m_x = rh->m_leftPos.m_x;
    cur.m_p1Pos.m_y = rh->m_leftPos.m_y;
    cur.flag = 0;

    s32 same = 0;
    if (prev.m_p0Pos.m_x == cur.m_p0Pos.m_x &&
        prev.m_p0Pos.m_y == cur.m_p0Pos.m_y)
        same = 1;

    if (same == 0) {
        same = 0;
        if (prev.m_p1Pos.m_x == cur.m_p1Pos.m_x &&
            prev.m_p1Pos.m_y == cur.m_p1Pos.m_y)
            same = 1;

        if (same == 0) {
            fn_800429C8(area, &prev, &cur);
            if (fn_80042FB4(area, &line) != 0 &&
                fn_80042C74(area, &line.m_p0Pos) != 0) {
                if (line.m_p0Pos.m_y > cur.m_p1Pos.m_y) {
                    Vec2f* point;
                    if (fn_8004094C(&cur, (point = &line.m_p0Pos), &q) != 0) {
                        r = (*point - q) +
                            Offset(lbl_805A29F0, lbl_805A29DC);
                        if (r.m_x > lbl_805A29F0)
                            moved = 1;
                    }
                } else {
                    cur.m_p0Pos.m_x = self->m_380.m_x;
                    cur.m_p0Pos.m_y = self->m_380.m_y;
                    cur.m_p1Pos.m_x = self->m_388.m_x;
                    cur.m_p1Pos.m_y = self->m_388.m_y;
                    cur.flag = 0;

                    fn_80111968(la.collision, &seg, la.line, 0);
                    Vec2f* down = &rh->m_downPos;
                    if (down->m_y < seg.m_p1Pos.m_y) {
                        if (fn_8004094C(&cur, down, &q) != 0) {
                            r = (*down - q) +
                                Offset(lbl_805A29F0, lbl_805A29DC);
                            if (r.m_x > lbl_805A29F0)
                                moved = 1;
                        }
                    } else {
                        f32 segX = seg.m_p1Pos.m_x;
                        s32 r28 = 0;
                        f32 downX = down->m_x;
                        if (segX <= downX) {
                            r28 = 1;
                        } else if (fn_80115E44(&la, &lb) != 0) {
                            if (lb.enabled()) {
                                fn_80111968(lb.collision, &seg, lb.line, 0);
                                r28 = 1;
                            }
                        }

                        if (r28 != 0 &&
                            fn_8004094C(&seg, down, &q) != 0) {
                            r = (q - *down) +
                                Offset(lbl_805A29DC, lbl_805A29F0);
                            if (r.m_x > lbl_805A29F0)
                                moved = 1;
                        }
                    }
                }

                if (moved != 0) {
                    rh->move(r);
                    fn_80125250(self, 5, arg1, *out = lbl_805A29C8);
                }
            }
        }
    }
}
