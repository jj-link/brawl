#pragma force_active on

#include <types.h>

extern "C" s32 fn_801BBFD4(void* self, void* out, s32 a, s32 b, s32 c);
extern "C" s32 fn_801BC2A8(void* self, void* out, s32 index, s32 arg3);
extern "C" void* fn_801BE5A8(s32 kind, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_801BE254(void* self, void* buf, s32 a, s32 b);
extern "C" void fn_801BF2E0(void* self, s32 v);
extern "C" void fn_801BF2F8(void* self, s32 v);
extern "C" void fn_801BF398(void* self, s32 v);
extern "C" void fn_801BF3A0(void* self, s32 v);

extern const f32 lbl_805A3478;
extern const f32 lbl_805A347C;
extern const f32 lbl_805A3480;

struct Params {
    s32 index;
    u8 a;
    u8 b;
    u8 c;
    u8 d;
    u8 e;
    u8 f;
    u8 g;
    f32 h;
};

struct Input {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
};

struct Self {
    char pad[0xC];
    s32 unkC;
};

struct Obj {
    char pad[0xA8];
    f32 unkA8;
    f32 unkAC;
    f32 unkB0;
    f32 unkB4;
    s32 unkB8;
    s32 unkBC;
    s32 unkC0;
    s32 unkC4;
};

extern "C" void* fn_801BBDA8(Self* self, const Input* p) {
    u8 sp18[0x98];
    Params sp8;
    s32 kind;
    s32 k;
    Obj* obj;
    f32 t;

    if (fn_801BBFD4(self, &sp8, p->f0, p->f4, p->f8) == 0) {
        return 0;
    }
    if (fn_801BC2A8(self, sp18, sp8.index, self->unkC) == 0) {
        return 0;
    }
    k = sp18[2];
    kind = 2;
    if (k <= 2) {
        kind = k;
    }
    obj = (Obj*)fn_801BE5A8(kind, p->f18, p->f14, p->f1C, p->f20);
    if (obj == 0) {
        return 0;
    }
    obj->unkC0 = p->f4;
    obj->unkC4 = sp8.e;
    t = (f32)p->f8 / lbl_805A3478;
    t *= t;
    t *= (f32)sp8.g / lbl_805A3478;
    obj->unkA8 = t;
    obj->unkB4 = sp8.h;
    fn_801BF2E0(obj, sp8.a);
    fn_801BF2F8(obj, sp8.b);
    fn_801BF398(obj, sp8.c);
    fn_801BF3A0(obj, sp8.d);
    t = (f32)(sp8.f - 0x40) / lbl_805A347C;
    t += (f32)p->f10 / lbl_805A347C;
    obj->unkAC = t;
    obj->unkB0 = lbl_805A3480;
    fn_801BE254(obj, sp18, p->fC, 0);
    return obj;
}
