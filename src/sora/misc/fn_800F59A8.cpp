#include <types.h>
#pragma force_active on

extern const float lbl_805A2610;
extern const float lbl_805A2614;

struct VtB {
    virtual ~VtB();
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void f13(void* x, void* y);

    u8 pad[0xe0];
    void* f_e4;
};

struct Ptr9C {
    u8 pad[0x10];
    void* val;
};

struct Base {
    u8 pad[0x3c];
};

struct Obj : Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25(s32 x);

    u8 pad1[0x88 - 0x40];
    s32 f88;
    s32 f8c;
    VtB* p90;
    u8 pad2[0x9c - 0x94];
    Ptr9C* p9c;
    u8 flagA0;
    u8 pad3[0x404 - 0xa1];
    s32 f404;
    s32 f408;
    f32 f40c;
    f32 f410;
};

extern "C" void fn_800F59A8(Obj* self) {
    if (self->f88 != 0) {
        self->v25(1);
    }

    self->f88 = 1;
    self->f8c = 0;

    if (self->flagA0 == 0) {
        VtB* o = self->p90;
        o->f13(o->f_e4, self->p9c->val);
        self->flagA0 = 1;
    }

    self->f404 = 0;
    self->f408 = -1;
    self->f410 = lbl_805A2610;
    self->f40c = lbl_805A2614;
}
