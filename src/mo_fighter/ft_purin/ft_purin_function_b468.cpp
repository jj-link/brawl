#include <cmath>
#pragma force_active on

struct Vec2 {
    float x, y;
};

struct Vec2Word {
    unsigned x, y;
};

struct Vec3 {
    float x, y, z;
};

struct soModuleAccesser;

struct Situation {
    virtual ~Situation();
    virtual void activate();
    virtual void deactivate();
    virtual int getKind();
};

struct Work {
    virtual void isNull();
    virtual ~Work();
    virtual void activate();
    virtual void setWork();
    virtual int getInt(unsigned);
    virtual void setInt();
    virtual void rndInt();
    virtual void incInt();
    virtual void decInt();
    virtual void addInt();
    virtual void subInt();
    virtual void countDownInt();
    virtual void getFloat();
    virtual void setFloat();
    virtual void rndFloat();
    virtual void addFloat();
    virtual void subFloat();
    virtual bool isFlag(unsigned);
    virtual void onFlag(unsigned);
    virtual void offFlag(unsigned);
};

struct Energy {
    virtual void isNull();
    virtual void update();
    virtual void getSpeed();
    virtual void getSpeed3();
    virtual void getRotation();
    virtual void reset(int, Vec2*, Vec3*, soModuleAccesser*);

    char pad[4];
    float x, y, accel, unk, stable;
};

struct Kinetic {
    virtual void isNull();
    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy();
    virtual void eraseEnergy();
    virtual void eraseEnergyAll();
    virtual Energy* getEnergy(int);
    virtual void isContain();
    virtual void updateEnergy();
    virtual void clearSpeedAll();
    virtual void suspendEnergyAll();
    virtual void resumeEnergyAll();
    virtual void unableEnergyAll();
    virtual Vec2Word getSumSpeed(const short*);
};

struct Controller {
    virtual ~Controller();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
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
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual float getStickY();
};

struct Posture {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual float getLr();
};

struct Modules {
    char p0[0xc];
    Posture* posture;
    char p10[4];
    Situation* situation;
    char p18[0x44];
    Controller* controller;
    char p60[4];
    Work* work;
    char p68[0x14];
    Kinetic* kinetic;
};

struct soModuleAccesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
extern char lbl_124_data_5A6C[];
extern char lbl_124_data_5B4C[];
extern char lbl_124_data_1254[];
extern const float lbl_124_rodata_10;

void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_124_B860(void*, soModuleAccesser*, float);
void fn_124_B848(Energy*, const Vec2*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);

void fn_124_B468(void* self, soModuleAccesser* acc) {
    if (acc->modules->situation->getKind() == 2) {
        Vec2 initialSpeed;
        Vec2Word sumSpeed;
        if (acc->modules->work->isFlag(0x22000011)) {
            acc->modules->work->offFlag(0x22000011);
            Energy* stop = (Energy*)__dynamic_cast(
                acc->modules->kinetic->getEnergy(3), 0,
                lbl_124_data_5A6C, lbl_124_data_1254, 1);
            Energy* gravity = (Energy*)__dynamic_cast(
                acc->modules->kinetic->getEnergy(1), 0,
                lbl_124_data_5B4C, lbl_124_data_1254, 1);

            float c;
            Posture* posture;
            float sine;
            double angle = fn_124_B860(
                self, acc, acc->modules->controller->getStickY());
            c = (float)cos(angle);
            posture = acc->modules->posture;
            c *= getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                acc, 0xfcb, 0);
            float lr = posture->getLr();
            initialSpeed.x = lr * c;
            sine = (float)sin(angle);
            initialSpeed.y = sine *
                getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                    acc, 0xfcb, 0);
            {
                float v[2] = { initialSpeed.x, lbl_124_rodata_10 };
                fn_124_B848(stop, (const Vec2*)v);
            }
            gravity->y = initialSpeed.y;
        }

        switch (acc->modules->work->getInt(0x20000000)) {
        case 1:
            short flag = 1;
            Vec2Word result = acc->modules->kinetic->getSumSpeed(&flag);
            sumSpeed = result;
            Energy* stop = (Energy*)__dynamic_cast(
                acc->modules->kinetic->getEnergy(3), 0,
                lbl_124_data_5A6C, lbl_124_data_1254, 1);
            Energy* gravity = (Energy*)__dynamic_cast(
                acc->modules->kinetic->getEnergy(1), 0,
                lbl_124_data_5B4C, lbl_124_data_1254, 1);
            float x = reinterpret_cast<const Vec2&>(sumSpeed).x *
                getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                    acc, 0xfcc, 0);
            float y = reinterpret_cast<const Vec2&>(sumSpeed).y *
                getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                    acc, 0xfcc, 0);
            if (acc->modules->work->isFlag(0x22000012)) {
                Vec3 zero = {
                    lbl_124_rodata_10, lbl_124_rodata_10, lbl_124_rodata_10
                };
                Vec2 v = { x, lbl_124_rodata_10 };
                stop->reset(0x16, &v, &zero, acc);
                gravity->accel = lbl_124_rodata_10;
                gravity->y = y;
                gravity->stable = lbl_124_rodata_10;
                acc->modules->work->offFlag(0x22000012);
            } else {
                Vec2 v = { x, lbl_124_rodata_10 };
                fn_124_B848(stop, &v);
                gravity->y = y;
            }
            break;
        }

        if (acc->modules->work->isFlag(0x22000012))
            acc->modules->work->offFlag(0x22000012);
    }
}
}
