#include <ft/ft_common_data_accesser.h>
#pragma force_active on

struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
};
inline Vec2* tempVec(const Vec2& v) { return const_cast<Vec2*>(&v); }
struct Vec3 { float x, y, z; };
struct Flag { unsigned short mask; };
struct Params { float p0, p4, p8, pC, p10, p14, p18, p1C; };
struct Accesser;

class Energy {
public:
    virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3();
    virtual void e4();
    virtual void reset(int, Vec2*, Vec3*, Accesser*);
    unsigned char state;
    unsigned char flags;
    char pad0[0x10 - 0x06];
    float f10;
    float f14;
    float f18;
    float f1C;
    Vec2 v20;
};

class WorkModule {
public:
    virtual void w0(); virtual void w1(); virtual void w2(); virtual void w3();
    virtual void w4(); virtual void w5(); virtual void w6(); virtual void w7();
    virtual void w8(); virtual void w9(); virtual void w10(); virtual void w11();
    virtual void w12(); virtual void w13(); virtual void w14(); virtual void w15();
    virtual void w16();
    virtual bool isFlag(unsigned int);
    virtual void onFlag(unsigned int);
    virtual void offFlag(unsigned int);
};

class Kinetic {
public:
    virtual void k0(); virtual void k1(); virtual void k2(); virtual void k3();
    virtual void k4(); virtual void k5();
    virtual Energy* getEnergy(int);
    virtual void k7(); virtual void k8(); virtual void k9(); virtual void k10();
    virtual void k11(); virtual void k12();
    virtual Vec2 getSum(const Flag&);
};

struct Modules {
    char pad0[0x64];
    WorkModule* work;
    char pad1[0x7C - 0x68];
    Kinetic* kinetic;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
void fn_102_D75C(Accesser*);
void fn_102_D694(Accesser*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3* fn_102_C5B8(Vec3*, float, float, float);
extern const char lbl_102_data_5E6C[], lbl_102_data_5D8C[], lbl_102_data_14F4[];
extern const float lbl_102_rodata_20;
}

extern "C" void fn_102_D99C(void*, Accesser* accesser) {
    WorkModule* work = accesser->modules->work;
    if (work->isFlag(0x1200003D)) {
        fn_102_D75C(accesser);
        work->offFlag(0x1200003D);
    }
    Params* params = *(Params**)((char*)g_ftCommonDataAccesser.getData((ftKind)0xB) + 0x84);
    short one = 1;
    Flag flag;
    flag.mask = one;
    Vec2 speed;
    __memcpy(&speed, &accesser->modules->kinetic->getSum(flag), sizeof(speed));
    if (!work->isFlag(0x22000012)) {
        speed.x *= params->p0;
        speed.y *= params->p4;
        fn_102_D694(accesser);
        Energy* gravity = static_cast<Energy*>(__dynamic_cast(
            accesser->modules->kinetic->getEnergy(1), 0,
            lbl_102_data_5E6C, lbl_102_data_14F4, one));
        Vec3 rot;
        gravity->reset(0, tempVec(Vec2(lbl_102_rodata_20, speed.y)),
            fn_102_C5B8(&rot, lbl_102_rodata_20, lbl_102_rodata_20, lbl_102_rodata_20),
            accesser);
        gravity->f10 = params->pC;
        gravity->f14 = params->p10;
        gravity->f1C = params->p10;
        gravity->flags |= 0x80;

        Energy* stop = static_cast<Energy*>(__dynamic_cast(
            accesser->modules->kinetic->getEnergy(3), 0,
            lbl_102_data_5D8C, lbl_102_data_14F4, one));
        Vec3 rot2;
        stop->reset(9, tempVec(Vec2(speed.x, lbl_102_rodata_20)),
            fn_102_C5B8(&rot2, lbl_102_rodata_20, lbl_102_rodata_20, lbl_102_rodata_20),
            accesser);
        stop->v20 = Vec2(params->p8, lbl_102_rodata_20);
        stop->flags |= 0x80;
    } else {
        speed.y = params->p14;
        fn_102_D694(accesser);
        Energy* gravity = static_cast<Energy*>(__dynamic_cast(
            accesser->modules->kinetic->getEnergy(1), 0,
            lbl_102_data_5E6C, lbl_102_data_14F4, one));
        Vec3 rot;
        gravity->reset(0, tempVec(Vec2(lbl_102_rodata_20, params->p14)),
            fn_102_C5B8(&rot, lbl_102_rodata_20, lbl_102_rodata_20, lbl_102_rodata_20),
            accesser);
        gravity->f10 = lbl_102_rodata_20;
        gravity->flags |= 0x80;
        work->onFlag(0x22000011);
    }
}
