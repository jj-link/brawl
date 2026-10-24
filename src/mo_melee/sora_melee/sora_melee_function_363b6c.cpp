#pragma force_active on
#include <math.h>

struct Vec2 {
    float x;
    float y;
};

struct Rand {
    float f0;
    float f1;
    float f2;
    char pad[8];
    float f14;
};

struct Scene {
    char pad[0x1fe4];
    Rand* rnd;
};

struct Mod0C {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22();
    virtual void s25(float);
};

struct Mod5C {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual float calc();
};

struct Mod64 {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual float get(unsigned long);
    virtual void set(unsigned long, float);
};

struct Mod7C {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5();
    virtual void* get8(int);
};

struct Modules {
    char pad0[0xc];
    Mod0C* m0c;
    char pad1[0x4c];
    Mod5C* m5c;
    char pad2[4];
    Mod64* m64;
    char pad3[0x14];
    Mod7C* m7c;
};

struct Accesser {
    char pad[8];
    void* owner;
    char pad2[0xcc];
    Modules* modules;
};

struct Result {
    char pad[0x10];
    Vec2 pos;
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const float lbl_27_rodata_7AC8[];
extern const char lbl_27_data_907A8[];
extern const char lbl_27_data_248[];
extern const char lbl_27_data_457C0[];
extern const char lbl_27_data_CDF8[];
}

extern "C" void fn_27_363B6C(void*, Accesser* a) {
    float* tbl = (float*)lbl_27_rodata_7AC8;
    Mod64* v64 = a->modules->m64;
    Mod5C* v5c = a->modules->m5c;
    Mod7C* v7c = a->modules->m7c;
    Mod0C* v0c = a->modules->m0c;
    Rand* rnd = ((Scene*)__dynamic_cast(a->owner, 0x3c, lbl_27_data_907A8,
                                       lbl_27_data_248, 1))->rnd;

    float time = v64->get(0x21000001);
    time = time + tbl[0];
    if (time > rnd->f0)
        time = rnd->f0;
    v64->set(0x21000001, time);

    float power = v5c->calc();
    float scale = tbl[1];
    if (fabs(power) > tbl[2])
        scale = power * rnd->f14;

    Result* r = (Result*)__dynamic_cast(v7c->get8(0), 0, lbl_27_data_457C0,
                                       lbl_27_data_CDF8, 1);
    Vec2 tmp;
    tmp.x = scale;
    tmp.y = tbl[1];
    r->pos = tmp;

    v0c->s25(rnd->f1 + time * ((rnd->f2 - rnd->f1) / rnd->f0));
}
