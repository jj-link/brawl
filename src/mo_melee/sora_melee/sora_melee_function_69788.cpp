#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_930;

struct Vec3f {
    float x;
    float y;
    float z;
};

struct IObj {
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
    virtual void v15(Vec3f* v, u32 flag);
};

struct B {
    u8 pad[0xc];
    IObj* obj;
};

struct A {
    u8 pad[0xd8];
    B* b;
};

struct Owner {
    u8 pad0[0x1c];
    A* a;
    u8 pad1[0x2c - 0x20];
    float f2c;
    float f30;
    s8 flags;
};

extern "C" {
void fn_27_69788(Owner* self) {
    Vec3f v;
    float z = lbl_27_rodata_930;
    self->f30 = z;
    self->flags &= ~0xE0;
    self->f2c = z;
    v.x = z;
    v.y = z;
    v.z = z;
    self->a->b->obj->v15(&v, 0);
    self->flags &= ~0x04;
}
}
