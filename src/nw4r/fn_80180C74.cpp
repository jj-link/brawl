#include <types.h>
#include <nw4r/math/math_types.h>
#pragma force_active on

using namespace nw4r::math;

extern "C" const f32 lbl_805A3078;
extern "C" const f32 lbl_805A30A0;

struct Sample {
    VEC3 pos;
    VEC3 a;
    VEC3 b;
    f32 f;
    Sample() {}
    Sample(const VEC3& p, const VEC3& x, const VEC3& y, f32 t) : pos(p), a(x), b(y), f(t) {}
};

struct Node {
    char pad0[0xC];
    s32 kind;
    char pad1[0xAC - 0x10];
    VEC3 pos;
};

struct State {
    char pad0[0x9C];
    u16 flags;
    char pad1[0x139 - 0x9E];
    s8 b139;
    s8 b13A;
    char pad2[0x140 - 0x13B];
    u8 b140;
    char pad3[0x142 - 0x141];
    u8 b142;
};

struct Info {
    char pad0[0x24];
    State* state;
    char pad1[0x3C - 0x28];
    Node* head;
    char pad2[0x42 - 0x40];
    u16 linkOff;
    char pad3[0x50 - 0x44];
    u16 val50;
};

struct Ctx {
    Info* info;
    char pad0[0xA4 - 0x4];
    VEC3 pos;
    char pad1[0xD4 - 0xB0];
    u32 d4;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void* slot2(u32 mode);
    virtual void* slot3(u32 mode);
    virtual s32 slot4(Info* info);
};

typedef s32 (*FnFirst)(Info*);
typedef s32 (*FnNext)(Info*, s32);

extern "C" void fn_8017E678(Object_vptr_0* self, Sample* out, Ctx* ctx, s32 arg3, s32 handle, s32 r28, f32 f1, f32 f2, f32 f3);
extern "C" void fn_8017EFC0(Object_vptr_0* self, s32 arg2, u8 idx, Sample* a, Sample* b, Sample* c, s32 arg3, u32 d4);

extern "C" void fn_80180C74(Object_vptr_0* self, Ctx* ctx, s32 arg2, s32 arg3) {
    Sample ring[3];
    State* st = ctx->info->state;
    u32 mode;
    Info* info = ctx->info;
    s32 r28 = self->slot4(info);
    mode = st->flags & 0x800;
    FnFirst first = (FnFirst)self->slot2(mode);
    FnNext next = (FnNext)self->slot3(mode);

    f32 f31 = lbl_805A30A0 * (f32)st->b139;
    f32 f30 = lbl_805A30A0 * (f32)st->b13A;

    Node* node = ctx->info->head;
    while (node != NULL && node->kind != 1) {
        u16 offset = ctx->info->linkOff;
        node = *(Node**)((char*)node + offset);
        while (node != NULL && node->kind != 1) {
            node = *(Node**)((char*)node + offset);
        }
    }
    VEC3 diff = ctx->pos - node->pos;

    int count = info->val50;
    f32 f29;
    switch (st->b142 & 0xC0) {
    case 0:
    default:
        f29 = lbl_805A3078 / (f32)count;
        break;
    case 0x40:
        f29 = lbl_805A3078;
        break;
    }

    s32 r26 = 0;
    s32 r25 = 1;
    if (mode != 0) {
        r26 = count;
        r25 = -1;
    }
    s32 r24 = 0;
    s32 r23 = 0;
    s32 h = first(info);
    fn_8017E678(self, &ring[0], ctx, arg3, h, r28, f31, f30, f29 * (f32)r26);
    r26 += r25;
    if (mode == 0) {
        Sample s48 = ring[0];
        s48.f = f29 * (f32)r26;
        r26 += r25;
        r23 = 1;
        ring[1] = s48;
        ring[0].pos += diff;
        fn_8017EFC0(self, arg2, st->b140, &ring[0], &ring[0], &ring[1], arg3, ctx->d4);
    }

    Sample* cur;
    s32 r16 = next(info, h);
    s32 r17;
    while (r16 != 0) {
        r17 = r24;
        r24 = r23;
        r23 = (r23 + 1) % 3;
        cur = &ring[r23];
        fn_8017E678(self, cur, ctx, arg3, r16, r28, f31, f30, f29 * (f32)r26);
        fn_8017EFC0(self, arg2, st->b140, &ring[r17], &ring[r24], cur, arg3, ctx->d4);
        r16 = next(info, r16);
        r26 += r25;
    }

    if (mode != 0) {
        s32 prev = r24;
        r24 = r23;
        r23 = (r23 + 1) % 3;
        Sample s20(ring[r24].pos + diff, ring[r24].a, ring[r24].b, f29 * (f32)r26);
        ring[r23] = s20;
        fn_8017EFC0(self, arg2, st->b140, &ring[prev], &ring[r24], &ring[r23], arg3, ctx->d4);
    }

    fn_8017EFC0(self, arg2, st->b140, &ring[r24], &ring[r23], &ring[r23], arg3, ctx->d4);
}
