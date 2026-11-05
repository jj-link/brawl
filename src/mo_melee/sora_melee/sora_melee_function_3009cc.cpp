#include <so/stageobject.h>
#include <types.h>

#pragma force_active on

#define PAD8(n) virtual void a##n##0(); virtual void a##n##1(); virtual void a##n##2(); virtual void a##n##3(); virtual void a##n##4(); virtual void a##n##5(); virtual void a##n##6(); virtual void a##n##7();

class Owner;
class Mods;

struct Sub4vBase { char pad[8]; };
class Sub4v : public Sub4vBase {
public:
    PAD8(0)
    PAD8(1)
    PAD8(2)
    PAD8(3)
    virtual void q0(); virtual void q1(); virtual void q2(); virtual void q3();
    virtual Vec3f getPos(int, int);
};

class Rate {
public:
    PAD8(0)
    virtual void a0();
    virtual float get();
};

class C {
public:
    virtual void s0();
    virtual void s1();
    virtual int get();
};

class B {
public:
    virtual void s0();
    virtual void s1();
    virtual C* get();
};

class A {
public:
    PAD8(0)
    PAD8(1)
    virtual void f16();
    virtual int f17(int, Owner*, Mods*);
};

struct OwnerBase { char pad[0x28]; int resource; char pad2[0x10]; };
class Owner : public OwnerBase {
public:
    PAD8(0)
    PAD8(1)
    PAD8(2)
    PAD8(3)
    PAD8(4)
    virtual int kind();
};

struct Mods {
    char p0[4];
    Sub4v* s4;
    char p1[4];
    Rate* rate;
    char p2[8];
    B* b;
    char p3[0x48];
    A* a;
};

struct Ctx {
    char p[8];
    Owner* owner;
    char p2[0xcc];
    Mods* m;
};

extern "C" float fn_27_192278(void*, unsigned long);
extern "C" void fn_27_306ED4(StageObject* object, int resource, int parameter, const Vec3f* position, int special, float facing);

extern "C" int fn_27_3009CC(int a, StageObject* object, Ctx* c) {
    int n;
    if (c->owner->kind() == 5) {
        n = 0x1b8;
    } else {
        n = 0x36;
    }
    Vec3f pos = c->m->s4->getPos(n, 0);
    float rate = c->m->rate->get();
    float f31 = fn_27_192278(c, 0xfa0);
    float f1v = fn_27_192278(c, 0xfa1);
    pos.m_x += f31 * rate;
    pos.m_y += f1v;
    Owner* owner = c->owner;
    Mods* m = c->m;
    A* ap = m->a;
    int special;
    B* bp = m->b;
    int resource = owner->resource;
    special = ap->f17(0x22000011, owner, m);
    int parameter = bp->get()->get();
    fn_27_306ED4(object, resource, parameter, &pos, special, rate);
    return 0;
}
