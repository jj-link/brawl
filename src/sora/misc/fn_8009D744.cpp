#pragma force_active on

typedef unsigned int u32;
typedef unsigned long long u64;
typedef int s32;
typedef unsigned char u8;
typedef float f32;

struct Vec3 {
    f32 x, y, z;
};

struct SrcBlock {
    u32 flags;
    char pad0[0x24];
    f32 a;
    char pad1[0xC];
    f32 b;
    char pad2[0xC];
    f32 c;
};

struct Rec {
    u32 a, b, c, d;
};

struct Obj {
    f32 x;
    f32 y;
    u8 pad08[0x8];
    struct { u32 high : 8; u32 low : 24; } w10;
    u8 pad14[0x18];
    Rec rec[16];
    Rec prev[16];
    s32 f22C;
    u32 anim[5];
    f32 thr[5];
    f32 ch[5];
    f32 t26C;
    u32 w270;
};

extern "C" {
    void* __memcpy(void*, const void*, unsigned long);
    void fn_8019564C(void* dst, SrcBlock* src, int zero, f32 f);
    void fn_8019589C(SrcBlock* src, Vec3* dst);
}
extern "C" const float lbl_805A1DC8;
extern "C" const float lbl_805A1DDC;

#define COPY_REC(k) \
    __memcpy(&p->prev[k].a, &p->rec[k].a, 8); \
    p->prev[k].c = p->rec[k].c; \
    p->prev[k].d = p->rec[k].d; \
    p->rec[k].d = 0;

extern "C" void fn_8009D744(Obj* self, f32 farg0) {
    Obj* p = self;
    for (s32 n = 0; n < 2; n++) {
        COPY_REC(0)
        COPY_REC(1)
        COPY_REC(2)
        COPY_REC(3)
        COPY_REC(4)
        COPY_REC(5)
        COPY_REC(6)
        COPY_REC(7)
        p = (Obj*)((char*)p + 0x80);
    }

    u32 r30 = self->w270 & 0x1F;
    if (r30 == 0) {
        self->w10.high = 0;
        return;
    }

    u32 r0 = r30 >> 1;
    s32 r29 = 0;
    while (r0 != 0 && r29 < 5) {
        r0 >>= 1;
        r29++;
    }

    s32 off = r29 * 4;
    self->w10.high = r29 + 1;
    f32 f1 = self->ch[r29];
    if (r29 == 0) {
        f1 = self->t26C;
    }

    if (self->f22C != 0) {
        SrcBlock src;
        Vec3 v;
        fn_8019564C(&self->anim[r29], &src, 0, f1);
        fn_8019589C(&src, &v);
        f1 = v.x;
        self->x = f1;
        f32 f2 = v.y;
        self->y = f2;
        if (r29 == 1) {
            f1 = f1 * lbl_805A1DDC;
            self->x = f1;
            self->y = f2 * lbl_805A1DDC;
        }
    }

    if (r30 & 1) {
        f32 limit = self->thr[0];
        f32 t = self->t26C + farg0;
        self->t26C = t;
        if (t >= limit) {
            t -= limit;
        }
        self->t26C = t;
    }

    for (s32 k = 0; r30 != 0 && k < 5; k++) {
        if (r30 & 1) {
            f1 = farg0 + self->ch[k];
            if (f1 >= self->thr[k]) {
                self->w270 &= ~(1u << k);
                f1 = lbl_805A1DC8;
            }
            self->ch[k] = f1;
        }
        r30 >>= 1;
    }
}
