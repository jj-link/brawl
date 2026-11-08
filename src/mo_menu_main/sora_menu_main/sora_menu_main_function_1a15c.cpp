#pragma force_active on
typedef int s32;
typedef unsigned char u8;

extern "C" {
void fn_16_228C(void*, void*, void*);
void fn_18_1AE0(void*, int, int);
}

struct GGSub {
    char pad[0x24];
    s32 w24;
    u8 b28;
};
struct GameGlobal {
    char pad[0x1c];
    GGSub* p1c;
};
extern GameGlobal* g_GameGlobal;

struct Base3C { char pad[0x3c]; };
struct Sub : Base3C {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22();
    virtual void f64();
    char pad1[0x9c - 0x40];
    s32 s9c;
    char pad2[0x3e0 - 0xa0];
    s32 s3e0;
    char pad3[0x3e8 - 0x3e4];
    s32 s3e8;
    s32 s3ec;
};
struct Obj658 : Base3C {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22();
    virtual void f64(int a, int b, int c);
};
struct S {
    char pad0[0x634];
    s32 s634;
    char pad1[0x658 - 0x638];
    Obj658* o658;
    char pad2[0x664 - 0x65c];
    s32 s664;
    char pad3[0x71c - 0x668];
    Sub* s71c;
    char pad4[0x724 - 0x720];
    u8 s724;
    char pad5[0x734 - 0x725];
    s32 s734;
};

extern "C" s32 fn_2_1A15C(S* self) {
    s32 r = 0;
    if (self->s724 == 0 && self->s71c->s9c != 1) {
        r = 4;
        self->s724 = 1;
    }
    Sub* p = self->s71c;
    switch (p->s3e8) {
    case 1:
    case 2: {
        s32 v = p->s3ec;
        GGSub* g = g_GameGlobal->p1c;
        g->b28 = (u8)v;
        g->w24 = self->s71c->s3e0;
        Sub* q = self->s71c;
        q->s3e8 = 0;
        q->s3ec = 0;
        fn_16_228C(self->s71c, q, g);
        self->s71c->f64();
        self->s71c = 0;
        fn_18_1AE0(self, 0x16, 1);
        break;
    }
    case 3:
        self->s634 = 5;
        r = 1;
        p->s3e8 = 0;
        p->s3ec = 0;
        break;
    case 4:
        r = 3;
        self->s664 = 1;
        p->f64();
        self->s71c = 0;
        break;
    }
    if (self->s71c != 0) {
        s32 t = ((self->s71c->s9c - 5) == 0) + 0x42;
        if (self->s734 != t) {
            self->o658->f64(t, 1, 0);
            self->s734 = t;
        }
    }
    return r;
}
