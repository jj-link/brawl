#include <types.h>
#pragma force_active on
#pragma fp_contract off

extern "C" {
extern const double lbl_805A3098;
extern const float lbl_805A3090;
extern const float lbl_805A30A0;
void* fn_80178868(void*);
s32 fn_8017B78C(void*, void*);
s32 fn_8017FBE4(void*, void*);
s32 fn_8017FBF0(void*, void*);
void fn_8017FBFC(void*);
void fn_80178564(void*);
void fn_8017E288(void*, void*, void*, s32, void*, s32, void*, s32, f32, f32, s32);
void fn_8017EB30(void*, s32, void*, void*, void*, s32);
void fn_8017EDDC(void*, void*, void*, void*, s32);
void fn_8017F894(void);
void GXBegin(u8, u8, u16);
}

typedef void* (*Fn1)(void*);
typedef void* (*Fn2)(void*, void*);

struct VT {
    virtual void v0();
    virtual void v1();
    virtual Fn1 v2(s32);
    virtual Fn2 v3(s32);
    virtual s32 v4(void*);
};

struct Obj {
    VT* vt;
    char p0[0x20];
    void* p24;
};

struct Q {
    char p0[0x9D];
    s8 b9D;
};

extern "C" void fn_8017FC00(VT* self, void** arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    char blk[5][0x1C];
    char c1C[0xC];
    char c10[0xC];
    s32 r25;
    s32 r24;
    Q* r23;
    Obj* r22;
    s32 r21;
    Fn1 r20;
    Fn2 r19;
    s32 prev;
    void* cur;
    char* p24;
    s32 r18;
    s32 r17;
    s32 i16;
    s32 i15;
    f32 f30;
    f32 f29;

    r22 = (Obj*)*arg1;
    r23 = (Q*)fn_80178868(r22->p24);
    r21 = self->v4(r22);
    r24 = fn_8017FBE4(self, r23);
    r20 = self->v2(r24);
    r19 = self->v3(r24);
    r25 = fn_8017B78C(self, r22);

    f32 f1 = (f32)r23->b9D;
    f30 = lbl_805A30A0 * f1;
    GXBegin(0x98, 0, (u16)((r25 * arg2 + 1) * 2));

    switch (fn_8017FBF0(self, r23)) {
    case 0:
    default:
        f29 = lbl_805A3090 / (f32)r25;
        break;
    case 0x40:
        f29 = lbl_805A3090;
        break;
    }

    r18 = -1;
    r17 = 2;
    if (r24 != 0) {
        r17 = -2;
        r18 = (r25 * 2) + 1;
    }

    fn_8017FBFC(blk[0]);
    fn_8017FBFC(blk[1]);
    fn_8017FBFC(blk[2]);
    fn_8017FBFC(blk[3]);
    fn_8017FBFC(blk[4]);
    fn_80178564(c1C);
    fn_80178564(c10);

    void* obj = r20(r22);
    fn_8017E288(self, blk[3], arg1, arg3, obj, r21, (char*)obj + 0xAC, arg4, f30, f29 * (f32)r18, arg5);

    obj = r19(r22, obj);
    r18 += r17;
    fn_8017E288(self, blk[4], arg1, arg3, obj, r21, (char*)obj + 0xAC, arg4, f30, f29 * (f32)r18, arg5);

    cur = r19(r22, obj);
    r18 += r17;
    i16 = 3;
    i15 = 4;

    while (cur != 0) {
        prev = i16;
        i16 = i15;
        i15 = (i15 + 1) % 3;
        p24 = (char*)blk + i15 * 0x1C;

        fn_8017E288(self, p24, arg1, arg3, cur, r21, (char*)cur + 0xAC, arg4, f30, f29 * (f32)r18, arg5);
        fn_8017EB30(self, arg2, (char*)blk + prev * 0x1C, (char*)blk + i16 * 0x1C, p24, arg3);

        cur = r19(r22, cur);
        r18 += r17;
    }

    char* p15 = (char*)blk + i15 * 0x1C;
    *(f32*)(blk[3] + 0x18) = f29 * (f32)r18;
    fn_8017EB30(self, arg2, (char*)blk + i16 * 0x1C, p15, blk[3], arg3);

    r18 += r17;
    *(f32*)(blk[4] + 0x18) = f29 * (f32)r18;
    fn_8017EB30(self, arg2, p15, blk[3], blk[4], arg3);
    fn_8017EDDC(self, p15, blk[3], blk[4], arg3);
    fn_8017F894();
}
