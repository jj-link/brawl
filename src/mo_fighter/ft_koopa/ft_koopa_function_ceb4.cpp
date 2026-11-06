#include <ft/ft_common_data_accesser.h>
#pragma force_active on

struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
};
inline Vec2* tempVec(const Vec2& v) { return const_cast<Vec2*>(&v); }
inline Vec2& tempRef(const Vec2& v) { return const_cast<Vec2&>(v); }
struct Vec3 { float x, y, z; };
struct Flag { unsigned short mask; };
struct Params { float p0, p4, p8, pC, p10, p14, p18, p1C; };
struct Accesser;

class Energy {
public:
    virtual void e2(); virtual void e3();
    virtual void e4(); virtual void e5(); virtual void e6();
    virtual void reset(int, Vec2*, Vec3*, Accesser*);
    unsigned char state;
    unsigned char flags;
    char pad0[0x10 - 0x06];
    float f10;
    float f14;
    Vec2 v18;
    char pad1[0x28 - 0x20];
    Vec2 v28;
    char pad2[0x3C - 0x30];
    float f3C;
};

class WorkModule {
public:
    virtual void w2(); virtual void w3();
    virtual void w4(); virtual void w5(); virtual void w6();
    virtual void w7(int, unsigned int);
    virtual void w8(); virtual void w9(); virtual void w10(); virtual void w11();
    virtual void w12(); virtual void w13(); virtual void w14(); virtual void w15();
    virtual void w16(); virtual void w17(); virtual void w18();
    virtual bool isFlag(unsigned int);
    virtual void onFlag(unsigned int);
    virtual void offFlag(unsigned int);
};

class Sth {
public:
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42();
    virtual void setA(int, int);
    virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47();
    virtual void s48(); virtual void s49(); virtual void s50();
    virtual void setB(int, int);
};

class ModuleB {
public:
    virtual void b2(); virtual void b3();
    virtual void f4(int, int);
};

class Kinetic {
public:
    virtual void k2(); virtual void k3(); virtual void k4(); virtual void k5();
    virtual void k6(); virtual void k7();
    virtual Energy* getEnergy(int);
    virtual void k9(); virtual void k10(); virtual void k11(); virtual void k12();
    virtual void k13(); virtual void k14();
    virtual Vec2 getSum(const Flag&);
    virtual void k16(); virtual void k17(); virtual void k18(); virtual void k19();
    virtual void k20(); virtual void k21(); virtual void k22();
    virtual void f23(int, Accesser*);
};

struct Modules {
    char pad0[0x58];
    ModuleB* moduleB;
    char pad1[0x64 - 0x5C];
    WorkModule* work;
    char pad2[0x7C - 0x68];
    Kinetic* kinetic;
    char pad3[0xA8 - 0x80];
    Sth* sth;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
void fn_102_C1DC(Accesser*);
void fn_102_C2A4(Accesser*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3* fn_102_C5B8(Vec3*, float, float, float);
void fn_102_C5AC(Vec2*, float, float);
void fn_102_B024(void*, const void*);
extern const char lbl_102_data_5E6C[], lbl_102_data_5EBC[], lbl_102_data_14F4[];
extern const float lbl_102_rodata_10;
}

extern "C" void fn_102_CEB4(void*, Accesser* accesser) {
    WorkModule* work = accesser->modules->work;
    if (work->isFlag(0x1200003D)) {
        fn_102_C2A4(accesser);
        work->offFlag(0x1200003D);
    }
    Sth* sth = accesser->modules->sth;
    int notFlag = !work->isFlag(0x22000013);
    sth->setA(notFlag, 0);
    sth->setB(notFlag, 0xFF);
    work->w7(0, 0x20000000);
    if (!work->isFlag(0x22000010)) {
        Params* params = *reinterpret_cast<Params**>(
            reinterpret_cast<char*>(g_ftCommonDataAccesser.getData((ftKind)0xB)) + 0x80);
        s16 one = 1;
        Flag flag;
        flag.mask = one;
        Vec2 speed;
        __memcpy(&speed, &accesser->modules->kinetic->getSum(flag), sizeof(speed));
        fn_102_C1DC(accesser);
        Energy* gravity = static_cast<Energy*>(__dynamic_cast(
            accesser->modules->kinetic->getEnergy(1), 0,
            lbl_102_data_5E6C, lbl_102_data_14F4, one));
        Vec3 rot;
        gravity->reset(0, tempVec(Vec2(lbl_102_rodata_10, speed.y)),
            fn_102_C5B8(&rot, lbl_102_rodata_10, lbl_102_rodata_10, lbl_102_rodata_10),
            accesser);
        gravity->f10 = -params->p8;
        gravity->f14 = params->pC;
        gravity->v18.y = params->pC;
        gravity->flags |= 0x80;

        Energy* stop = static_cast<Energy*>(__dynamic_cast(
            accesser->modules->kinetic->getEnergy(2), 0,
            lbl_102_data_5EBC, lbl_102_data_14F4, one));
        Vec3 rot2;
        stop->reset(0, tempVec(Vec2(speed.x, lbl_102_rodata_10)),
            fn_102_C5B8(&rot2, lbl_102_rodata_10, lbl_102_rodata_10, lbl_102_rodata_10),
            accesser);
        stop->f3C = params->p1C;
        Vec2& a = tempRef(Vec2());
        fn_102_C5AC(&a, params->p14, stop->v18.y);
        fn_102_B024(&stop->v18, &a);
        Vec2& b = tempRef(Vec2());
        fn_102_C5AC(&b, params->p14, stop->v28.y);
        fn_102_B024(&stop->v28, &b);
        stop->flags |= 0x80;
    } else {
        accesser->modules->kinetic->f23(0, accesser);
    }
    if (work->isFlag(0x22000012)) {
        accesser->modules->moduleB->f4(1, 1);
        accesser->modules->moduleB->f4(0, -1);
    }
}
