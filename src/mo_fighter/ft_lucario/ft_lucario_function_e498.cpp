#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on
#pragma optimization_level 2
#pragma scheduling off

typedef unsigned long long U64;

struct Vec {
    float x, y;
};

union Packed {
    U64 bits;
    Vec v;
};

struct Module {
    virtual void s08();
    virtual void s0c();
    virtual U64 speed();
    virtual void s14();
    virtual int getInt(unsigned long);
    virtual void s1c();
    virtual void* energy(int);
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual void s34();
    virtual float getFloat(unsigned long);
    virtual void setFloat(float, unsigned long);
    virtual void s40();
    virtual void s44();
    virtual float x();
    virtual int flag(unsigned long);
    virtual float y();
};

struct Modules {
    char p[0x5c];
    Module* control;
    void* p60;
    Module* work;
    char p68[0x14];
    Module* kinetic;
};

struct Access {
    char p[0xd8];
    Modules* modules;
};

extern "C" {
struct Constants {
    float f[11];
};

extern const Constants lbl_118_rodata_30;
extern const char lbl_118_data_620C[], lbl_118_data_17B0[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    Access*, unsigned long, unsigned long);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Access*, unsigned long, unsigned long);
void fn_118_FF04(Access*, float, float);
void fn_118_C3EC(void*, const Vec*);
void fn_118_DCAC(Vec*, float, float);
float fn_118_EDC4(const Vec*);
float fn_118_E474(float, float);
U64 fn_118_100CC(float, float);
float fn_118_EE38(const Vec*, const Vec*);
}

struct FlagModule {
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3c();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual int flag(unsigned long);
    virtual void on(unsigned long);
};

static inline float clampf(float value, float lo, float hi) {
    float t = nw4r::math::FSelect(value - lo, value, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}

static inline void setSpeedAngle(Access* a, float angle, Packed& speed,
                                 Packed& result, Vec& v3) {
    char* e = (char*)__dynamic_cast(
        a->modules->kinetic->energy(3), 0,
        lbl_118_data_620C, lbl_118_data_17B0, 1);
    speed.bits = ((Module*)e)->speed();
    result.bits = fn_118_100CC(angle, fn_118_EDC4(&speed.v));
    v3.x = result.v.x;
    v3.y = result.v.y;
    fn_118_C3EC(e + 8, &v3);
}

extern "C" void fn_118_E498(void*, Access* a) {
    const float* constants = lbl_118_rodata_30.f;
    Vec vthen, velse;
    Packed speed;
    Packed result;
    Packed p;
    Vec v3;
    Packed dir;
    Vec old;
    Vec stick;

    Module* work = a->modules->work;
    char* e = (char*)__dynamic_cast(
        a->modules->kinetic->energy(3), 0,
        lbl_118_data_620C, lbl_118_data_17B0, 1);
    int frames = work->getInt(0x20000000);

    if (frames > getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
                     a, 0x5dc2, 0)) {
        if (!((FlagModule*)work)->flag(0x22000013)) {
            float f = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                a, 0xfc0, 0);
            fn_118_FF04(a, f, f);
            ((FlagModule*)work)->on(0x22000013);
        }
        float f = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            a, 0xfc1, 0);
        vthen.x = f;
        vthen.y = f;
        fn_118_C3EC(e + 0x20, &vthen);
    } else {
        velse.x = constants[0];
        velse.y = constants[0];
        fn_118_C3EC(e + 0x20, &velse);
    }

    Module* control = a->modules->control;
    fn_118_DCAC(&stick, control->x(), control->y());

    if (fn_118_EDC4(&stick) > constants[9]) {
        Module* w = a->modules->work;
        fn_118_DCAC(&old, w->getFloat(0x21000006),
                    w->getFloat(0x21000007));
        p.bits = fn_118_100CC(
            constants[1] + fn_118_E474(old.y, old.x), constants[3]);
        dir = p;
        float dot = fn_118_EE38(&dir.v, &stick);
        float threshold =
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                a, 0xc2d, 0);
        float mag = (float)(double)nw4r::math::FAbs(dot);

        if (mag >= threshold) {
            Module* w = a->modules->work;
            float rate = (mag - threshold) / (constants[3] - threshold);
            float low = constants[0], high = constants[3];
            rate = clampf(rate, low, high);
            if (dot < low)
                rate *= constants[2];

            float angle = w->getFloat(0x21000005);
            float factor =
                getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                    a, 0xfbe, 0);
            float delta = constants[10] * factor;
            delta *= rate;
            float newAngle = angle + delta;
            w->setFloat(newAngle, 0x21000005);

            setSpeedAngle(a, newAngle, speed, result, v3);
        }
    }

    float x = a->modules->control->x();
    float th2 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        a, 0xc2d, 0);
    if ((float)(double)nw4r::math::FAbs(x) >= th2) {
        float direction = x > constants[0] ? constants[3] : constants[2];
        a->modules->work->setFloat(direction, 0x21000008);
    }
}
