#include <mt/mt_prng.h>

#pragma force_active on

struct V3 {
    float x, y, z;
    V3() {}
    V3(const V3& v) : x(v.x), y(v.y), z(v.z) {}
};

#define P8(n) \
    virtual void a##n##0(); \
    virtual void a##n##1(); \
    virtual void a##n##2(); \
    virtual void a##n##3(); \
    virtual void a##n##4(); \
    virtual void a##n##5(); \
    virtual void a##n##6(); \
    virtual void a##n##7();

class Owner {
public:
    char pad[0x3c];
    P8(0)
    P8(1)
    P8(2)
    P8(3)
    P8(4)
    virtual int kind();
};

class Model {
public:
    char pad[8];
    P8(0)
    P8(1)
    P8(2)
    P8(3)
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual V3 pos(int, V3*, int, int);
};

class Posture {
public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual V3 pos();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual float lr();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
};

class Work {
public:
    P8(0)
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual float get(int);
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
};

class B {
public:
    virtual void a0();
    virtual void a1();
    virtual void* call();
};

class A {
public:
    virtual void a0();
    virtual void a1();
    virtual B* call(void*);
};

struct Mods {
    char p0[4];
    Model* model;
    char p1[4];
    Posture* posture;
    char p2[8];
    A* a;
    char p3[0x48];
    Work* work;
};

struct Ctx {
    char p0[8];
    Owner* owner;
    char p1[0xcc];
    Mods* mods;
};

struct Data {
    char pad[0x44];
    float y, z;
};

extern unsigned char g_ftCommonDataAccesser;
extern const float lbl_27_rodata_7B28[];

extern "C" void* fn_27_1481E0(void*, int);
extern "C" float fn_27_192278(void*, unsigned long);
extern "C" void fn_27_36CEA0(void*, void*, void*, V3*, int,
                             float, float, float, float, float);

extern "C" int fn_27_36908C(int unused, void* arg, Ctx* c) {
    Ctx* ctx = c;
    const float* constants = lbl_27_rodata_7B28 + 1;
    Work* w;
    Work* w2;
    int kind = ctx->owner->kind();
    Data* d = (Data*)fn_27_1481E0(&g_ftCommonDataAccesser, kind);

    float offsetY, offsetZ;
    offsetZ = d->y;
    offsetY = d->z;
    V3 offset;
    offset.y = offsetY;
    offset.x = constants[-1];
    offset.z = offsetZ;

    V3 pos = ctx->mods->posture->pos();
    float lr = ctx->mods->posture->lr();
    ctx->mods->posture->a22();

    float one = constants[0];
    float angle = ctx->mods->work->get(0x21000004);

    if (kind == 5)
        pos = ctx->mods->model->pos(0x19c, &offset, 0, 0);
    else
        pos = ctx->mods->model->pos(0x21, &offset, 0, 0);

    w = ctx->mods->work;
    float den = fn_27_192278(ctx, 0xfa6);
    float x = w->get(0x11000017) / den;

    w2 = ctx->mods->work;
    den = fn_27_192278(ctx, 0xfa8);
    float y = w2->get(0x11000016) / den;

    float base = fn_27_192278(ctx, 0xfa0);
    float range = fn_27_192278(ctx, 0xfa1);
    angle = base + angle;
    angle += range * randf() - constants[1] * range;

    void* owner = *(void**)((char*)ctx->owner + 0x28);
    void* obj = ctx->mods->a->call(ctx->owner)->call();
    fn_27_36CEA0(arg, owner, obj, &pos, 0, lr, x, y, one,
                 constants[2] * angle);
    return 0;
}
