#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern f32 lbl_805A2200;

struct G {
    u8 p0[0x1C];
    u16 h1c;
    u8 p1[2];
    s32 w20;
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
    u8 p0[8];
    VT* y;
    VT* x;
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
void fn_800B8350(Obj* self, s32 arg1, Iface* arg2) {
    C* c;
    VT* z;
    G* g;
    s32 r0;

    if (self->a != 0) {
        self->a->v3();
    }
    if (arg1 == 4) {
        c = self->b->c;
        if (c == 0) {
            r0 = 1;
        } else {
            z = c->x;
            if (z == 0) {
                r0 = 1;
            } else {
                g = z->g;
                u16 h1;
                if (g->w20 != 1 && ((h1 = g->h1c), 1) && z->v6() >= (f32)(h1 - 1)) {
                    r0 = 1;
                } else {
                    r0 = 0;
                }
            }
        }
        s32 f1 = 1;
        if (r0 == 0) {
            if (lbl_805A2200 != self->b->c->x->v9()) {
                f1 = 0;
            }
        }
        c = self->b->c;
        if (c == 0) {
            r0 = 1;
        } else {
            z = c->y;
            if (z == 0) {
                r0 = 1;
            } else {
                g = z->g;
                u16 h2;
                if (g->w20 != 1 && ((h2 = g->h1c), 1) && z->v6() >= (f32)(h2 - 1)) {
                    r0 = 1;
                } else {
                    r0 = 0;
                }
            }
        }
        s32 f2 = 1;
        if (r0 == 0) {
            if (lbl_805A2200 != self->b->c->y->v9()) {
                f2 = 0;
            }
        }
        arg2->i6(2, f1 && f2);
        arg2->i6(5, f1);
    }
}
}
