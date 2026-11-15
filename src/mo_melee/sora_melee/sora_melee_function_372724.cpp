#include <types.h>
#include <mt/mt_vector.h>
#include <mt/mt_prng.h>
#pragma force_active on

struct V3 { f32 x, y, z; };

struct Out { char p[8]; f32 a, b, c, d, e; char pad[20]; };
struct Rodata { f32 one; f32 zero; f32 radians; f32 two; f32 half; };

struct Pad3c { char p[0x3c]; };
struct Pad8 { char p[8]; };

#define V8(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); \
    virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7();

class Owner : public Pad3c {
public:
    V8(a) V8(b) V8(c) V8(d) V8(e)
    virtual int kind();
};

class Sub : public Pad8 {
public:
    V8(a) V8(b) V8(c) V8(d)
    virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3();
    virtual V3 getPos(int, int);
    virtual void f0(); virtual void f1(); virtual void f2();
    virtual void m(int, void*, int);
};

class Rate : public Pad8 {
public:
    V8(a) V8(b) V8(c) V8(d) V8(e) V8(f) V8(g) V8(h) V8(i) V8(j) V8(k) V8(l) V8(m)
    virtual void n0(); virtual void n1(); virtual void n2(); virtual void n3();
    virtual void n4(); virtual void n5(); virtual void n6();
    virtual f32 get();
};

class FloatObj {
public:
    V8(a)
    virtual void b0();
    virtual f32 get();
};

class PtrObj {
public:
    virtual void a0();
    virtual void a1();
    virtual void* get();
};

class WorkObj {
public:
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual int getInt(unsigned int);
    virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3();
    virtual void b4(); virtual void b5(); virtual void b6();
    virtual f32 getFloat(unsigned int);
};

struct Mods {
    char p0[4];
    Sub* sub;
    char p1[4];
    FloatObj* fobj;
    Rate* rate;
    char p2[4];
    PtrObj* pobj;
    char p3[0x64 - 0x1c];
    WorkObj* work;
};

struct Acc {
    char p0[8];
    Owner* owner;
    char p1[0xcc];
    Mods* mods;
};

extern "C" {
extern const Rodata lbl_27_rodata_7BA0;
void fn_8003DC64(Vec2f*, f32, Vec2f*);
void fn_8003DE70(V3*);
f32 fn_27_192278(void*, unsigned long);
int fn_27_1922CC(void*, unsigned long);
void fn_27_375CCC(int, int, int, void*, V3*, V3*, f32, f32);
}

inline void fire(int arg2, Acc* acc, int arg4, V3* pos, V3 dir, f32 ratio, PtrObj*& pobj) {
    pobj = acc->mods->pobj;
    int taskId = *(int*)((char*)acc->owner + 0x28);
    f32 f1 = acc->mods->fobj->get();
    void* p2 = pobj->get();
    void* p3 = ((PtrObj*)p2)->get();
    fn_27_375CCC(arg2, taskId, arg4, p3, pos, &dir, f1, ratio);
}

extern "C" int fn_27_372724(int unused, int arg2, Acc* acc, int arg4) {
    V3 pos;
    if (acc->owner->kind() == 5) {
        pos = acc->mods->sub->getPos(0x19c, 0);
    } else {
        pos = acc->mods->sub->getPos(8, 0);
    }
    pos.z = acc->mods->rate->get();

    V3 dir;
    if (acc->owner->kind() == 5) {
        Vec2f rot;
        rot.m_x = 1.0f;
        rot.m_y = 0.0f;
        f32 f = acc->mods->work->getFloat(0x21000004);
        fn_8003DC64(&rot, 0.01745329238474369f * f, &rot);
        f32 y = rot.m_y;
        f32 g = acc->mods->fobj->get();
        Vec2f v(rot.m_x * g, y);
        dir.x = v.m_x;
        dir.y = v.m_y;
        dir.z = 0.0f;
        fn_8003DE70(&dir);
    } else {
        Out out;
        acc->mods->sub->m(0xa, &out, 0);
        f32 y = out.e;
        f32 x = out.a;
        dir.x = x;
        dir.y = y;
        dir.z = 0.0f;
        fn_8003DE70(&dir);
    }

    dir.y += 2.0f * (fn_27_192278(acc, 0xfa4) * (randf() - 0.5f));

    WorkObj* w = acc->mods->work;
    f32 timer = (f32)fn_27_1922CC(acc, 0x5dc0);
    f32 ratio = (f32)w->getInt(0x10000040) / timer;
    PtrObj* pobj;
    fire(arg2, acc, arg4, &pos, dir, ratio, pobj);
    return 0;
}