#pragma force_active on
#pragma fp_contract off

#include <nw4r/math/math_arithmetic.h>

typedef unsigned long long u64;

struct Vec2 {
    float x;
    float y;
};

struct Dst {
    virtual void d0();
    virtual void d1();
    virtual u64 get();
};

struct Energy {
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual void* get(int);
};

struct WorkModule {
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual int w4(unsigned long, void*);
    virtual void w5(int, unsigned long);
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual float getFloat(unsigned long);
    virtual void setFloat(unsigned long, float);
};

struct Modules {
    char pad0[0x64];
    WorkModule* work;
    char pad1[0x14];
    Energy* energy;
};

struct Access {
    char pad0[8];
    void* object;
    char pad1[0xCC];
    Modules* modules;
};

struct Self {
    char pad[0x60];
    Access* access;
};

struct Inner2 {
    char pad[8];
    int limit;
};

struct Inner1 {
    char pad[0x34];
    Inner2* inner2;
};

struct Inner0 {
    char pad[0xBC];
    Inner1* inner1;
};

extern "C" {
extern char lbl_27_data_457C0[];
extern char lbl_27_data_CDF8[];
extern char lbl_27_data_7E6B0[];
extern char lbl_27_data_248[];
extern const float lbl_27_rodata_6488[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_1DACB8(void*);
float rsqrtf__Ff(float);
double atan2(double, double);

int fn_27_2F031C(void* arg0) {
    const float* k = lbl_27_rodata_6488;
    Self* self = (Self*)arg0;
    Access* access;
    WorkModule* work;
    int ret = fn_27_1DACB8(arg0);

    access = self->access;
    Modules* modules = access->modules;
    work = modules->work;
    Energy* energy = modules->energy;
    Dst* dst = (Dst*)__dynamic_cast(energy->get(0), 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1);
    u64 bits = dst->get();
    Vec2 v = *(Vec2*)&bits;
    float sum = v.x * v.x + v.y * v.y;
    float mag;
    if ((float)(double)nw4r::math::FAbs(sum) <= k[7]) {
        mag = k[1];
    } else {
        mag = sum * rsqrtf__Ff(sum);
    }
    if (mag > k[8]) {
        double x = v.x;
        double y = v.y;
        work->setFloat(0x11000001, -(float)atan2(y, x));
    }

    Inner0* in0 = (Inner0*)__dynamic_cast(access->object, 0x3C, lbl_27_data_7E6B0, lbl_27_data_248, 1);
    Inner2* in2 = in0->inner1->inner2;
    int limit = in2->limit;
    if (work->w4(0x10000006, in2) > limit) {
        work->w5(limit, 0x10000006);
    }
    return ret;
}
}
