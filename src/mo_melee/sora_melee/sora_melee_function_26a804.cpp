#include <types.h>

#pragma force_active on

extern const f32 lbl_27_rodata_4388;
extern "C" void fn_27_26AF10(void* self, float frame);

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct Sub {
    char pad0[4];
    u32 flags;
    Vec3 pos;
    Vec3 vel;
    char pad20[0x3C];
    f32 f5c;
    char pad60[0xC];
    f32 f6c;
    char pad70[0xC];
    f32 f7c;
};

struct CC {
    char pad0[0xD4];
    Sub* sub;
};

struct LocalGimmick {
    char pad0[0x6D];
    u8 f6d;
    char pad6e[0xCC - 0x6E];
    CC* cc;
    char padD0[4];
    Sub* d4;
    char padD8[8];
    u8 e0;

    inline void setPos(const Vec3* v) {
        Sub* d = d4;
        if (d != 0) {
            d->pos.x = v->x;
            d->pos.y = v->y;
            d->pos.z = v->z;
        }
    }
    inline void setVel(const Vec3* v) {
        Sub* d = d4;
        if (d != 0) {
            d->vel.x = v->x;
            d->vel.y = v->y;
            d->vel.z = v->z;
        }
    }
};

extern "C" void update__9grGimmickFf(LocalGimmick* g, float frame) {
    CC* cc = g->cc;
    if (cc != 0) {
        if (g->e0 & 1) {
            Vec3 v;
            const Vec3* p;
            Sub* s = cc->sub;
            if (s != 0) {
                if (s->flags & 8) {
                    f32 x, y, z;
                    z = s->f7c;
                    y = s->f6c;
                    x = s->f5c;
                    s->pos.x = x;
                    s->pos.y = y;
                    s->pos.z = z;
                }
                *(u32*)&v.x = *(u32*)&cc->sub->pos.x;
                *(u32*)&v.y = *(u32*)&cc->sub->pos.y;
                *(u32*)&v.z = *(u32*)&cc->sub->pos.z;
                p = &v;
            } else {
                v.x = lbl_27_rodata_4388;
                v.y = lbl_27_rodata_4388;
                v.z = lbl_27_rodata_4388;
                p = &v;
            }
            g->setPos(p);
        }
        if (g->e0 & 2) {
            Vec3 v;
            const Vec3* p;
            Sub* s = g->cc->sub;
            if (s != 0) {
                *(u32*)&v.x = *(u32*)&s->vel.x;
                *(u32*)&v.y = *(u32*)&s->vel.y;
                *(u32*)&v.z = *(u32*)&s->vel.z;
                p = &v;
            } else {
                v.x = lbl_27_rodata_4388;
                v.y = lbl_27_rodata_4388;
                v.z = lbl_27_rodata_4388;
                p = &v;
            }
            g->setVel(p);
        }
    }
    if ((u32)(g->f6d & 1) != 1) {
        fn_27_26AF10(g, frame);
    }
}
