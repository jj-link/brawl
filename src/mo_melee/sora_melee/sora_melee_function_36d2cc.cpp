#pragma force_active on
#pragma fp_contract off
#include <nw4r/math/math_arithmetic.h>
#include <mt/mt_common.h>
struct Vec2 { float x; float y; };
extern "C" {
int fn_27_1DA24C(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
double atan2(double, double);
double cos(double);
double sin(double);
float fn_8003DDD0(const Vec2* lhs, const Vec2* rhs);
extern const float lbl_27_rodata_7B40[];
extern char lbl_27_data_457C0[];
extern char lbl_27_data_CDF8[];
}
inline Vec2 unpack(unsigned long long bits) { return *(Vec2*)&bits; }
struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
    virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
    virtual void slot44(); virtual void slot45(); virtual void slot46();
    virtual int fn_27_24CC58(signed char);
};
class NullableModule {
public:
    virtual void isNull();
    virtual signed char slot1();
    virtual signed char slot2();
};
class KineticEnergy {
public:
    virtual void isNull();
    virtual void updateEnergy();
    virtual unsigned long long getSpeed();
    unsigned char p04;
    unsigned char p05;
    char pad06[2];
    Vec2 speed;
};
inline void setSpeed(KineticEnergy* e, float x, float y) { Vec2 out; out.y = y; out.x = x; e->speed = out; }
class Kinetic {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5();
    virtual KineticEnergy* getEnergy(int index);
};
class Posture {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9();
};
struct FlagVecModule_base { char pad[8]; };
class FlagVecModule : public FlagVecModule_base {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43();
    virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47();
    virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51();
    virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55();
    virtual void s56();
    virtual unsigned long long getSumSpeed(int flags, int unk);
};
struct Modules {
    char pad0[0xc];
    Posture* posture;
    FlagVecModule* vecmod;
    char pad1[0x68];
    Kinetic* kinetic;
};
struct soModuleAccesser { char pad[0xd8]; Modules* modules; };
extern "C" int fn_27_36D2CC(gfTask* self, NullableModule* m, soModuleAccesser* a) {
    float cy;
    const float* c = lbl_27_rodata_7B40;
    if (fn_27_1DA24C(self)) return 1;
    if (self->fn_27_24CC58(m->slot1()) == 0) return 0;
    if (m->slot2() <= -1 || m->slot2() >= 11) return 0;
    switch (m->slot2()) {
    case 6: {
        KineticEnergy* e = static_cast<KineticEnergy*>(__dynamic_cast(
            a->modules->kinetic->getEnergy(0), 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1));
        Vec2 v = unpack(e->getSpeed());
        float sum = v.x * v.x + v.y * v.y;
        float mag;
        if ((float)(double)nw4r::math::FAbs(sum) <= c[7]) mag = c[1];
        else mag = sum * rsqrtf(sum);
        Vec2 w = unpack(a->modules->vecmod->getSumSpeed(0xff, 0));
        double wy = w.y;
        double wx = w.x;
        float angB = (float)atan2(wx, wy);
        double vy = v.y;
        double vx = v.x;
        float angA = (float)atan2(vx, vy);
        float diff = angA - angB;
        a->modules->posture->s9();
        while (diff > c[9]) diff -= c[8];
        while (diff < c[10]) diff += c[8];
        float corr = c[1];
        if (c[1] != diff) {
            float r = fn_8003DDD0(&w, &v);
            float ar = (float)(double)nw4r::math::FAbs(r);
            float t;
            if (ar < c[11]) t = c[12] * (ar / c[9]);
            else t = c[13] * (ar / c[9]);
            if (diff < c[1]) t = -t;
            corr = r * t;
        }
        float ang = angA - corr;
        while (ang < c[10]) ang += c[8];
        while (ang > c[9]) ang -= c[8];
        cy = mag * (float)cos(ang);
        float sx = mag * (float)sin(ang);
        setSpeed(e, sx, cy);
        return 1;
    }
    default:
        break;
    }
    return 0;
}