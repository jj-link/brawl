#include <ft/ft_common_data_accesser.h>
#pragma force_active on

struct KoopaData {
    int first;
    unsigned char flag;
    unsigned char padding[3];
    int second;
    int value0;
    int value1;
    int value2;
    float scalar;
    unsigned char last;
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
class ModuleA {
public:
    virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3();
    virtual void p4(); virtual void p5(); virtual void p6(); virtual void p7();
    virtual void p8(); virtual void p9(); virtual void p10();
    virtual void notify(int, int, int, int, int);
};
class ModuleB {
public:
    virtual void q0(); virtual void q1(); virtual void q2(); virtual void q3();
    virtual void q4(); virtual void q5(); virtual void q6(); virtual void q7();
    virtual void q8(); virtual void q9(); virtual void q10(); virtual void q11();
    virtual void q12(); virtual void q13(); virtual void q14(); virtual void q15();
    virtual void send(int, KoopaData*, int);
    virtual void q17(); virtual void q18();
    virtual int get(int);
};
class ModuleC {
public:
    virtual void c0(); virtual void c1(); virtual void c2();
    virtual bool check();
    virtual void c4(); virtual void c5(); virtual void c6(); virtual void c7();
    virtual void c8();
    virtual float rate();
};
class Energy {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual void resetEnergy(int, void*, void*, void*);
};
class Kinetic {
public:
    virtual void k0(); virtual void k1(); virtual void k2(); virtual void k3();
    virtual void k4(); virtual void k5();
    virtual Energy* getEnergy(int);
};
struct Vec2 {
    float x, y;
    Vec2(float a, float b) : x(a), y(b) {}
};
struct Vec3 { float x, y, z; };
struct Modules {
    char pad0[0xc];
    ModuleC* status;
    char pad1[4];
    ModuleC* checker;
    char pad2[4];
    ModuleA* moduleA;
    char pad3[0x54 - 0x20];
    ModuleB* moduleB;
    char pad4[0x64 - 0x58];
    WorkModule* work;
    char pad5[0x7c - 0x68];
    Kinetic* kinetic;
};
struct Accesser {
    char pad[0xd8];
    Modules* modules;
};
extern "C" {
extern const char lbl_102_data_5E6C[], lbl_102_data_5D8C[], lbl_102_data_14F4[];
extern const float lbl_102_rodata_2C;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_102_E124(Accesser*);
Vec3* fn_102_C5B8(Vec3*, float, float, float);
void fn_102_E384(KoopaData*, int, int, unsigned char);
}
extern "C" void fn_102_EE54(void*, Accesser* accesser) {
    WorkModule* work = accesser->modules->work;
    float* data = *reinterpret_cast<float**>(
        reinterpret_cast<char*>(g_ftCommonDataAccesser.getData((ftKind)0xB)) + 0x88);
    if (work->isFlag(0x22000010)) {
        ModuleB* moduleB = accesser->modules->moduleB;
        if (work->isFlag(0x22000011)) {
            KoopaData koopaData;
            fn_102_E384(&koopaData, 0xB, -1, 1);
            moduleB->send(0, &koopaData, 0);
            accesser->modules->moduleA->notify(0, 0x4C, moduleB->get(0), 0, 0);
        }
        fn_102_E124(accesser);
        Energy* gravity = static_cast<Energy*>(__dynamic_cast(
            accesser->modules->kinetic->getEnergy(1), 0,
            lbl_102_data_5E6C, lbl_102_data_14F4, 1));
        Vec2 speed(lbl_102_rodata_2C, data[12]);
        Vec3 rotation;
        gravity->resetEnergy(0, &speed,
            fn_102_C5B8(&rotation, lbl_102_rodata_2C, lbl_102_rodata_2C,
                        lbl_102_rodata_2C), accesser);
        reinterpret_cast<unsigned char*>(gravity)[5] |= 0x80;
        Energy* stop = static_cast<Energy*>(__dynamic_cast(
            accesser->modules->kinetic->getEnergy(3), 0,
            lbl_102_data_5D8C, lbl_102_data_14F4, 1));
        Vec2 speed2(data[11] * accesser->modules->status->rate(),
                    lbl_102_rodata_2C);
        Vec3 rotation2;
        stop->resetEnergy(6, &speed2,
            fn_102_C5B8(&rotation2, lbl_102_rodata_2C, lbl_102_rodata_2C,
                        lbl_102_rodata_2C), accesser);
        reinterpret_cast<unsigned char*>(stop)[5] |= 0x80;
        work->offFlag(0x22000010);
    }
    if (!accesser->modules->checker->check()) {
        Energy* energy = static_cast<Energy*>(__dynamic_cast(
            accesser->modules->kinetic->getEnergy(1), 0,
            lbl_102_data_5E6C, lbl_102_data_14F4, 1));
        reinterpret_cast<float*>(energy)[3] = lbl_102_rodata_2C;
    }
}
