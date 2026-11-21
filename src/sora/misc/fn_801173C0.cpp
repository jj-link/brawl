#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_8045D9E0[0x38];
extern char lbl_8059E6A8[8];
extern const float lbl_805A2958;
extern const float lbl_805A295C;
extern const float lbl_805A2960;
}

struct A {
    u8 a;
    char pad0[3];
    float b;
    u32 c;
    u32 d;
    u32 e;
    u8 f;
    u8 g : 1;
    u8 rest : 7;
    char pad1[2];

    void init() {
        g = 0;
        b = lbl_805A295C;
        a = 255;
        c = 0;
        d = 0;
        e = 0;
        f = 0;
    }
};

struct B {
    u32 a;
    u32 b;
    u32 c;
    u8 d;
    u8 e : 1;
    u8 rest : 7;
    char pad[2];

    void init() {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        e = 0;
    }
};

struct W {
    u32 b0 : 8;
    u32 b1 : 8;
    u32 rest : 16;
};

struct S {
    float x;
    float y;
    float z;
    u8 flags01 : 2;
    u8 flag2 : 1;
    u8 flags36 : 4;
    u8 flag7 : 1;
    u8 d0;
    u8 e0;
    u8 f;
    u8 g;
    char p11[7];
    void* arg;
    u32 p1c;
    char p20[0x14];
    A a;
    A aa[7];
    A ab;
    char p10c[0x10];
    u16 h;
    char p11e[2];
    B b;
    B ba[7];
    u16 h2;
    char p1a2[0x82];
    B c;
    B d;
    B da[7];
    char* name;
    u32 p2b8;
    u32 p2bc;
    u32 p2c0;
    u32 p2c4;
    u8 p2c8;
    u8 p2c9;
    u8 p2ca;
    u8 p2cb;
    W p2cc;
    u32 p2d0;
    float f2d4;
    float f2d8;
    float f2dc;
    float f2e0;
    char p2e4[0x28];
    B e2;
    B f2;
    void* vtable;
};

inline void resetA(A* p, A* end) {
    do {
        p->init();
        p++;
    } while (p < end);
}

inline void resetB(B* p, B* end) {
    do {
        p->init();
        p++;
    } while (p < end);
}

extern "C" void fn_801173C0(S* self, void* arg) {
    self->vtable = lbl_8045D9E0;
    self->x = lbl_805A2958;
    self->y = lbl_805A2958;
    self->z = lbl_805A295C;
    self->flags01 = 0;
    self->flag2 = 1;
    self->flags36 = 0;
    self->d0 = 0;
    self->e0 = 0;
    self->p1c = 0;
    resetA(&self->a, self->aa + 7);
    self->ab.c = 0;
    self->ab.init();
    self->h = 0;
    resetB(&self->b, self->ba + 7);
    self->h2 = 0;
    self->c.init();
    resetB(&self->d, self->da + 7);
    self->p2b8 = 0;
    self->p2bc = 0;
    self->p2c0 = 0;
    self->p2c4 = 0;
    self->p2cc.b0 = 2;
    self->p2cc.b1 = 2;
    self->f2d4 = lbl_805A2960;
    self->f2d8 = lbl_805A2960;
    self->f2dc = lbl_805A2960;
    self->f2e0 = lbl_805A2960;
    self->e2.init();
    self->f2.init();
    self->arg = arg;
    self->name = lbl_8059E6A8;
    self->p2c8 = 0;
    self->p2c9 = 0;
    self->p2ca = 0;
    self->p2cb = 0;
    self->f = 0;
    self->g = 0;
}
