#include <gr/collision/gr_collision.h>
#include <gr/collision/gr_collision_line.h>
#include <mt/mt_coll2d.h>
#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

struct Entry {
    grCollisionLine* line;
    void* ground;
    grCollision* collision;
    u8 byte;
    u8 flag : 1;
    u8 rest : 7;
    Entry() : line(0), ground(0), collision(0), byte(0), flag(0) {}
    bool valid() const { return line && ground && collision; }
};

struct Pair { u32 hi, lo; };
union Position { Pair pair; struct { f32 x, y; } f; };

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(Vec2f*);
    virtual void slot4(Vec2f*);
    virtual void slot5(Vec2f*);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual Pair slot10();
    virtual Pair slot11();
};

struct Part { u8 pad[0x75]; u8 flags; };
struct Self {
    u8 pad0[0xc];
    u8 flags;
    u8 padD;
    u8 direction;
    u8 padF[9];
    Part* part;
    u8 pad1C[0x54-0x1c];
    Entry left;
    u8 pad64[8];
    Entry right;
    u8 pad7C[8];
    Entry hit;
    u8 pad94[0x2bc-0x94];
    Object_vptr_0* obj;
};

struct Offset : Vec2f {
    Offset(f32 y, f32 x) : Vec2f(x, y) {}
};

extern "C" {
int fn_80113DF8(const Entry&, Entry&);
int fn_80113EC0(const Entry&, Entry&);
int fn_80115E44(const Entry&, Entry&);
int fn_801162F4(const Entry&, Entry&);
int fn_8004094C(clSegment2D*, Vec2f*, Vec2f*);
extern f32 lbl_805A2960;
extern f32 lbl_805A2994;
extern f32 lbl_805A2998;
}

extern "C" s32 fn_8011D6E0(Self* self, Entry* arg, s32 force) {
    int result = 0;
    Entry next;
    Entry cur;
    clSegment2D seg;
    Vec2f target;
    Vec2f displacement;
    Vec2f moved;
    Vec2f point;

    arg->collision->getSegment(&seg, arg->line);
    if (self->direction & 2) {
        Position pos;
        pos.pair = self->obj->slot11();
        if (!(pos.f.x < seg.m_p1Pos.m_x)) {
            fn_80113DF8(*arg, cur);
            if (cur.valid() && ((*(u8*)((char*)*(grCollisionLine**)(void*)&cur + 0xf) >> 3) & 1)) {
                cur.collision->getSegment(&seg, cur.line);
                f32 segY = seg.m_p0Pos.m_y;
                f32 posY = pos.f.y;
                if (segY > posY) {
                    if (seg.m_p0Pos.m_x <= pos.f.x) {
                        Offset delta(lbl_805A2960, seg.m_p0Pos.m_x - pos.f.x);
                        target = *(Vec2f*)&pos + delta;
                        self->obj->slot5(&target);
                        result = 1;
                    }
                } else if (fn_801162F4(cur, next)) {
                    next.collision->getSegment(&seg, next.line);
                    if (fn_8004094C(&seg, (Vec2f*)&pos, &point)) {
                        displacement = (point - *(Vec2f*)&pos) + Offset(lbl_805A2960, lbl_805A2998);
                        if (displacement.m_x < lbl_805A2960) {
                            point.m_x -= lbl_805A2994;
                            self->obj->slot5(&point);
                            result = 1;
                        }
                    }
                }
                if (result) {
                    self->right = cur;
                    self->part->flags |= 0x10;
                } else if (force) {
                    arg->collision->getSegment(&seg, arg->line);
                    f32 y = seg.m_p1Pos.m_y;
                    f32 x = seg.m_p1Pos.m_x;
                    target.m_y = y;
                    target.m_x = x - lbl_805A2994;
                    self->obj->slot3(&target);
                    result = 1;
                }
            }
        }
    } else if (self->direction & 1) {
        Position pos;
        pos.pair = self->obj->slot10();
        if (!(seg.m_p0Pos.m_x < pos.f.x)) {
            fn_80113EC0(*arg, cur);
            if (cur.valid() && ((*(u8*)((char*)*(grCollisionLine**)(void*)&cur + 0xf) >> 2) & 1)) {
                cur.collision->getSegment(&seg, cur.line);
                f32 segY = seg.m_p1Pos.m_y;
                f32 posY = pos.f.y;
                if (segY > posY) {
                    if (pos.f.x <= seg.m_p1Pos.m_x) {
                        Offset delta(lbl_805A2960, seg.m_p1Pos.m_x - pos.f.x);
                        target = *(Vec2f*)&pos + delta;
                        self->obj->slot4(&target);
                        result = 1;
                    }
                } else if (fn_80115E44(cur, next)) {
                    next.collision->getSegment(&seg, next.line);
                    if (fn_8004094C(&seg, (Vec2f*)&pos, &point)) {
                        displacement = (point - *(Vec2f*)&pos) + Offset(lbl_805A2960, lbl_805A2994);
                        if (displacement.m_x > lbl_805A2960) {
                            point.m_x += lbl_805A2994;
                            self->obj->slot4(&point);
                            result = 1;
                        }
                    }
                }
                if (result) {
                    self->left = cur;
                    self->part->flags |= 0x20;
                } else if (force) {
                    arg->collision->getSegment(&seg, arg->line);
                    f32 y = seg.m_p0Pos.m_y;
                    f32 x = seg.m_p0Pos.m_x;
                    target.m_y = y;
                    target.m_x = x + lbl_805A2994;
                    self->obj->slot3(&target);
                    result = 1;
                }
            }
        }
    }
    if (result) {
        self->hit = *arg;
        self->flags |= 0x80;
    }
    return result;
}