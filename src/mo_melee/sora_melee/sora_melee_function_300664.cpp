#include <so/stageobject.h>
#include <types.h>
#pragma force_active on

#define PAD8(n) virtual void a##n##0(); virtual void a##n##1(); virtual void a##n##2(); virtual void a##n##3(); virtual void a##n##4(); virtual void a##n##5(); virtual void a##n##6(); virtual void a##n##7();

class Owner;
class Mods;
class Module;
class Sub4v;
class Rate;
class B;
class CObj;
class A;
class Target;
class Obj;

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
float fn_27_192278(void*, unsigned long);
void fn_27_306ED4(void*, int, int, const Vec3f*, int, float);
void fn_27_1E1B14(void*, void*, int, void*, int, int, Vec3f*, unsigned int, unsigned int, int, int, int, int, int, int, int, int, int);
extern char g_ftCommonDataAccesser[];
extern char lbl_27_data_2C0C0[];
extern char lbl_27_data_CBA0[];
extern char lbl_27_data_31AD8[];
extern char lbl_27_data_817C0[];
extern char lbl_27_data_C938[];
extern float lbl_27_rodata_6550;
}

class Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual int kind();
};

struct ModBase { char pad[8]; };
class Module : public ModBase {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void* get();
};

class Target {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual int get(int);
};

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

class CObj {
public:
    virtual void s0();
    virtual void s1();
    virtual int get();
};

class B {
public:
    virtual void s0();
    virtual void s1();
    virtual CObj* get();
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
    Module* mod;
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

extern "C" int fn_27_300664(void* unused, Obj* b, Ctx* c) {
    int id;
    int owner;
    switch (b->kind()) {
    case 13: {
        char* data = (char*)getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 5);
        void** r29 = *(void***)(data + 0x64);
        Vec3f v;
        v.m_x = lbl_27_rodata_6550;
        v.m_y = lbl_27_rodata_6550;
        v.m_z = lbl_27_rodata_6550;
        Module* mod = c->m->mod;
        owner = c->owner->resource;
        Target* t = (Target*)__dynamic_cast(mod->get(), 0, lbl_27_data_2C0C0, lbl_27_data_CBA0, 1);
        id = t->get(0x18);
        Obj* o = (Obj*)__dynamic_cast(b, 0, lbl_27_data_31AD8, lbl_27_data_C938, 1);
        fn_27_1E1B14(o, (void*)owner, id, (char*)*r29 + 0xe0, 1, 0, &v, 0xFFFF, 0xFFFF, 0, 1, 0, -1, 0, 0, 2, 0, 0);
        return 1;
    }
    case 14: {
        b = (Obj*)__dynamic_cast(b, 0, lbl_27_data_817C0, lbl_27_data_C938, 0);
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
        int resource;
        B* bp = m->b;
        resource = owner->resource;
        int special = ap->f17(0x22000011, owner, m);
        int parameter = bp->get()->get();
        fn_27_306ED4(b, resource, parameter, &pos, special, rate);
        return 0;
    }
    default:
        return 0;
    }
}
