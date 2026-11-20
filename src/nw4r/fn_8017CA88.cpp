#include <nw4r/math/math_types.h>
#pragma force_active on

using namespace nw4r::math;

extern "C" {
void fn_8017BC38(void* self, void* out, void* ctx, s32 arg2, s32 a, s32 b, float f1, float f2, float f3);
void fn_8017C0F0(void* self, void* prev, void* cur, s32 arg2, u8 mode, s32 extra);
extern const float lbl_805A3038;
extern const float lbl_805A303C;
}

struct Node {
    char pad0[0xC];
    s32 kind;
    char pad1[0xAC - 0x10];
    VEC3 pos;
};

struct Link {
    Node* next;
    Node* prev;
};

struct Settings {
    char pad0[0x9C];
    u16 unk9C;
    char pad1[0x139 - 0x9E];
    s8 unk139;
    s8 unk13A;
    char pad2[0x140 - 0x13B];
    u8 unk140;
    char pad3[0x142 - 0x141];
    u8 unk142;
};

struct Obj {
    char pad0[0x24];
    Settings* settings;
    char pad1[0x3C - 0x28];
    Node* list;
    char pad2[0x42 - 0x40];
    u16 linkOffset;
    char pad3[0x50 - 0x44];
    u16 unk50;
};

struct Ctx {
    Obj* obj;
    char pad0[0xA4 - 4];
    VEC3 pos;
    char pad1[0xD4 - 0xB0];
    s32 unkD4;
};

struct Pts3 {
    VEC3 a;
    VEC3 b;
    VEC3 c;
};

struct Seg {
    Pts3 p;
    float t;
};

typedef s32 (*Fn10)(Obj*);
typedef s32 (*Fn14)(Obj*, s32);

class Self {
public:
    virtual void v0();
    virtual void v1();
    virtual Fn10 v2(s32 mode);
    virtual Fn14 v3(s32 mode);
    virtual s32 v4(Obj* obj);
};

extern "C" void fn_8017CA88(Self* self, Ctx* ctx, s32 arg2) {
    Settings* st;
    s32 r30;
    u32 mode;
    Obj* obj;
    Seg sp40;
    Seg sp18;
    obj = ctx->obj;
    st = obj->settings;
    s32 r28 = self->v4(obj);
    mode = st->unk9C & 0x800;
    Fn10 fp10 = self->v2(mode);
    Fn14 fp14 = self->v3(mode);
    float f31 = lbl_805A3038 * (float)st->unk139;
    float f30 = lbl_805A3038 * (float)st->unk13A;
    int count = obj->unk50;
    float f29;
    switch (st->unk142 & 0xC0) {
    case 0:
    default:
        f29 = lbl_805A303C / (float)count;
        break;
    case 0x40:
        f29 = lbl_805A303C;
        break;
    }
    s32 r25 = 0;
    s32 r24 = 1;
    if (mode != 0) {
        r25 = count;
        r24 = -1;
    }
    s32 r27 = fp10(obj);
    fn_8017BC38(self, &sp18, ctx, arg2, r27, r28, f31, f30, f29 * (float)r25);
    r25 += r24;
    sp40.p = sp18.p;
    sp40.t = f29 * (float)r25;
    Node* node = obj->list;
    while (node != NULL && node->kind != 1) {
        u16 offset = obj->linkOffset;
        node = ((Link*)((char*)node + offset))->next;
        while (node != NULL && node->kind != 1) {
            node = ((Link*)((char*)node + offset))->next;
        }
    }
    sp18.p.a += ctx->pos - node->pos;
    r25 += r24;
    fn_8017C0F0(self, &sp18, &sp40, arg2, st->unk140, ctx->unkD4);
    r30 = fp14(obj, r27);
    while (r30 != 0) {
        sp18 = sp40;
        fn_8017BC38(self, &sp40, ctx, arg2, r30, r28, f31, f30, f29 * (float)r25);
        fn_8017C0F0(self, &sp18, &sp40, arg2, st->unk140, ctx->unkD4);
        r30 = fp14(obj, r30);
        r25 += r24;
    }
}
