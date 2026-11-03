#include <revolution/GX/GXGeometry.h>
#pragma force_active on

extern f32 lbl_805A3AF8;

typedef struct Vec2 {
    f32 x;
    f32 y;
} Vec2;

typedef struct Target {
    u8 pad[0x44];
    Vec2 pos;
} Target;

typedef struct Holder {
    u8 pad[0x10];
    Target *target;
} Holder;

typedef struct Src {
    u8 pad[0x20];
    s32 unk20;
    u8 pad2[0x10];
    Vec2 pos;
} Src;

typedef struct Self {
    u8 pad0[0x4];
    Src *src;
    u8 pad1[0x7F];
    u8 flag87;
    u8 pad2[0x160];
    Holder *h1e8;
    Holder *h1ec;
    Holder *h1f0;
    Holder *h1f4;
    Holder *h1f8;
    u8 pad3[0x5C];
    u8 bits258a : 2;
    u8 flag258 : 1;
    u8 bits258b : 5;
} Self;

void fn_802782A0(Self *arg0, s32 arg1) {
    f32 buf[6];
    f32 *pb;
    Target *t;
    Src *src;
    u32 r4;
    u32 r5;
    f32 f0;
    f32 f1;

    pb = buf;
    r5 = -arg1;
    r5 = r5 | arg1;
    r4 = r5 >> 31;
    arg0->flag87 = r4;
    arg0->flag258 = r5 >> 31;
    if (r4 != 0) {
        src = arg0->src;
        f1 = src->pos.y;
        f0 = src->pos.x;
        t = arg0->h1e8->target;
        pb[2] = f0;
        t->pos.x = f0;
        t->pos.y = f1;
        pb[3] = f1;
        pb[4] = f0;
        pb[5] = f1;
        if (arg0->src->unk20 == 0) {
            t = arg0->h1ec->target;
            t->pos.x = f0;
            t->pos.y = f1;
            t = arg0->h1f0->target;
            t->pos.x = f0;
            t->pos.y = f1;
            t = arg0->h1f4->target;
            t->pos.x = f0;
            t->pos.y = f1;
            t = arg0->h1f8->target;
            t->pos.x = f0;
            t->pos.y = f1;
        }
    } else {
        f0 = lbl_805A3AF8;
        pb[0] = f0;
        t = arg0->h1e8->target;
        t->pos.x = f0;
        t->pos.y = f0;
        pb[1] = f0;
        pb[4] = f0;
        pb[5] = f0;
        if (arg0->src->unk20 == 0) {
            t = arg0->h1ec->target;
            t->pos.x = f0;
            t->pos.y = f0;
            t = arg0->h1f0->target;
            t->pos.x = f0;
            t->pos.y = f0;
            t = arg0->h1f4->target;
            t->pos.x = f0;
            t->pos.y = f0;
            t = arg0->h1f8->target;
            t->pos.x = f0;
            t->pos.y = f0;
        }
    }
    GXSetCullMode(GX_CULL_NONE);
}
