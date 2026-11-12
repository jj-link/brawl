#include <types.h>

#pragma force_active on

extern float lbl_27_rodata_D34;
extern float lbl_27_rodata_D30;

struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
};

struct Vec3 {
    float x, y, z;
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_A7E40();
    virtual void fn_27_A7F04();
    virtual void fn_27_A81B8();
    virtual void fn_27_A8AEC();
    virtual void fn_27_A82BC();
    virtual void fn_27_A8AFC();
    virtual void fn_27_A8D3C();
    virtual void fn_27_A8E30();
    virtual void fn_27_A9040();
    virtual void fn_27_A901C();
};

class Obj0 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual Vec3 s4();
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12(int, int, int);
    virtual void slot13();
    virtual void slot14(int);
    virtual void slot15();
    virtual void slot16();
    virtual void slot17(int, Vec2*, Vec2*);
};

struct Inner {
    char pad[0xc];
    Obj0* obj;
    char pad2[0x80];
    Object_vptr_0* manager;
};

struct Access {
    char pad[0xd8];
    Inner* inner;
};

struct FlagData {
    u32 bits;
    u32 val;
};

struct Owner {
    char pad0[0x14];
    Access* access;
    float f18, f1c, f20, f24;
    FlagData* flag;
    Vec3 position;
    u8 done, active;
    char pad3a[2];
    int a, b, c, d, e;
};

inline u32 test(int n, u32 bits, u8 active) {
    return active == 0 ? 0 : ((1 << n) & bits) != 0;
}

extern "C" void fn_27_A82BC(Owner* self, u32 arg) {
    Inner* inner = self->access->inner;
    float scale = lbl_27_rodata_D34;
    float x = self->f1c - self->f18;
    x *= scale;

    float range[4];
    range[0] = -x;
    range[1] = x;
    range[2] = self->f20 - self->f24;
    range[2] *= scale;
    range[3] = -range[2];

    Object_vptr_0* mgr = inner->manager;
    self->position = inner->obj->s4();

    int a = self->a;
    if (a != -1) {
        mgr->slot14(a);
        if (test(a, self->flag->bits, self->active) == 1)
            mgr->slot12(a, 1, -1);
        else
            mgr->slot12(a, 0, -1);

        if (test(self->a, self->flag->bits, self->active) == 1 && arg == 1) {
            Vec2 pos(lbl_27_rodata_D30, lbl_27_rodata_D30);
            Vec2 size(range[1] - range[0], range[2] - range[3]);
            mgr->slot17(self->a, &pos, &size);
        }
    }

    int b = self->b;
    if (b != -1) {
        mgr->slot14(b);
        if (test(b, self->flag->bits, self->active) == 1)
            mgr->slot12(b, 1, -1);
        else
            mgr->slot12(b, 0, -1);

        if (test(self->b, self->flag->bits, self->active) == 1 && arg == 1) {
            Vec2 pos;
            pos.y = range[2] + (float)(self->flag->val >> 1);
            pos.x = lbl_27_rodata_D30;
            Vec2 size((range[1] + (float)self->flag->val) -
                          (range[0] - (float)self->flag->val),
                      (float)self->flag->val);
            mgr->slot17(self->b, &pos, &size);
        }
    }

    int c = self->c;
    if (c != -1) {
        mgr->slot14(c);
        if (test(c, self->flag->bits, self->active) == 1)
            mgr->slot12(c, 1, -1);
        else
            mgr->slot12(c, 0, -1);

        if (test(self->c, self->flag->bits, self->active) == 1 && arg == 1) {
            Vec2 pos;
            pos.y = range[3] - (float)(self->flag->val >> 1);
            pos.x = lbl_27_rodata_D30;
            Vec2 size((range[1] + (float)self->flag->val) -
                          (range[0] - (float)self->flag->val),
                      (float)self->flag->val);
            mgr->slot17(self->c, &pos, &size);
        }
    }

    int d = self->d;
    if (d != -1) {
        mgr->slot14(d);
        if (test(d, self->flag->bits, self->active) == 1)
            mgr->slot12(d, 1, -1);
        else
            mgr->slot12(d, 0, -1);

        if (test(self->d, self->flag->bits, self->active) == 1 && arg == 1) {
            Vec2 pos;
            pos.x = range[1] + (float)(self->flag->val >> 1);
            pos.y = lbl_27_rodata_D30;
            Vec2 size((float)self->flag->val,
                      (range[2] + (float)self->flag->val) -
                          (range[3] - (float)self->flag->val));
            mgr->slot17(self->d, &pos, &size);
        }
    }

    int e = self->e;
    if (e != -1) {
        mgr->slot14(e);
        if (test(e, self->flag->bits, self->active) == 1)
            mgr->slot12(e, 1, -1);
        else
            mgr->slot12(e, 0, -1);

        if (test(self->e, self->flag->bits, self->active) == 1 && arg == 1) {
            Vec2 pos;
            pos.x = range[0] - (float)(self->flag->val >> 1);
            pos.y = lbl_27_rodata_D30;
            Vec2 size((float)self->flag->val,
                      (range[2] + (float)self->flag->val) -
                          (range[3] - (float)self->flag->val));
            mgr->slot17(self->e, &pos, &size);
        }
    }

    self->done = 1;
}
