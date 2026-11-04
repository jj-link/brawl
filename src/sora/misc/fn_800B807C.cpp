#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

struct G {
    u8 p0[0x1C];
    u16 h1c;
    u8 p1[2];
    s32 w20;
    s32 w24;
    u8 p2[4];
    u16 h2c;
    u8 p3[6];
    s32 w34;
};

class VT {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual f32 v6();
    virtual void v7();
    virtual void v8();
    virtual f32 v9();
    u8 pad[0x28];
    G* g;
};

class Iface {
public:
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual void i3();
    virtual void i4();
    virtual void i5();
    virtual void i6(s32, s32);
};

struct C {
    u8 p0[0x10];
    VT* z;
    VT* d;
    VT* f;
};

struct B {
    u8 p0[0x14];
    C* c;
};

struct Obj {
    u32 p0;
    VT* a;
    B* b;
};

extern "C" {
extern f32 lbl_805A2200;

void fn_800B807C(Obj* self, s32 arg1, Iface* arg2) {
    s32 r0;
    s32 flag;
    u16 h;
    C* c;
    VT* z;
    VT* d;
    VT* f;
    G* g;

    if (self->a != 0) {
        self->a->v2();
    }
    if (arg1 == 4) {
        c = self->b->c;
        if (c == 0) {
            r0 = 1;
        } else {
            z = c->z;
            if (z == 0) {
                r0 = 1;
            } else {
                g = z->g;
                if (g->w34 != 1 && ((h = g->h2c), 1) && z->v6() >= (f32)(h - 1)) {
                    r0 = 1;
                } else {
                    r0 = 0;
                }
            }
        }
        flag = 1;
        if (r0 == 0) {
            if (lbl_805A2200 != self->b->c->z->v9()) {
                flag = 0;
            }
        }
        if (flag != 0) {
            c = self->b->c;
            if (c == 0) {
                r0 = 1;
            } else {
                d = c->d;
                if (d == 0) {
                    r0 = 1;
                } else {
                    g = d->g;
                    if (g->w24 != 1 && ((h = g->h1c), 1) && d->v6() >= (f32)(h - 1)) {
                        r0 = 1;
                    } else {
                        r0 = 0;
                    }
                }
            }
            flag = 1;
            if (r0 == 0) {
                if (lbl_805A2200 != self->b->c->d->v9()) {
                    flag = 0;
                }
            }
        }
        if (flag != 0) {
            c = self->b->c;
            if (c == 0) {
                r0 = 1;
            } else {
                f = c->f;
                if (f == 0) {
                    r0 = 1;
                } else {
                    g = f->g;
                    if (g->w20 != 1 && ((h = g->h1c), 1) && f->v6() >= (f32)(h - 1)) {
                        r0 = 1;
                    } else {
                        r0 = 0;
                    }
                }
            }
            flag = 1;
            if (r0 == 0) {
                if (lbl_805A2200 != self->b->c->f->v9()) {
                    flag = 0;
                }
            }
        }
        arg2->i6(3, flag);
    }
}
}
