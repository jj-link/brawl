#include <mt/mt_vector.h>
#include <math.h>
#pragma force_active on

extern "C" {
extern const unsigned char lbl_95_data_7A88[];
extern const unsigned char lbl_95_data_810C[];
extern const unsigned char lbl_95_data_81D8[];
extern const unsigned char lbl_95_data_2C38[];
extern const float lbl_95_rodata_110;
extern const float lbl_95_rodata_114;
extern unsigned char g_ftCommonDataAccesser[];

void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_95_11ADC(void*, const Vec2f*);
}

struct Energy {
    virtual void v0();
    virtual void v1();
    virtual Vec2f getSpeed();

    unsigned char pad4;
    unsigned char enabled : 1;
    unsigned char flags : 7;
    char pad6[2];
    float x;
    float y;
};

struct Kinetic {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* getEnergy(int);
};

struct Controller {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual float getX();
    virtual void v17();
    virtual float getY();
};

struct Posture {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float getLr();
};

struct Status {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual int getKind();
};

struct Motion {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void setRate(float);
};

struct Sound {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setRate(int, float);
};

struct Modules {
    char pad0[8];
    Motion* motion;
    Posture* posture;
    char pad10[0x4c];
    Controller* controller;
    char pad60[0x10];
    Status* status;
    char pad74[8];
    Kinetic* kinetic;
    char pad80[4];
    Sound* sound;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_95_13B78(void*, Accesser* accesser)
{
    Modules* modules = accesser->modules;
    Controller* controller = modules->controller;
    Kinetic* kinetic = modules->kinetic;
    Motion* motion = modules->motion;

    const float* params = *(const float**)(
        (char*)getData__20ftCommonDataAccesserCF6ftKind(
            g_ftCommonDataAccesser, 4) + 0x88);

    Energy* stop = (Energy*)__dynamic_cast(
        kinetic->getEnergy(3), 0,
        lbl_95_data_7A88, lbl_95_data_2C38, 1);
    Energy* gravity = (Energy*)__dynamic_cast(
        kinetic->getEnergy(1), 0,
        lbl_95_data_810C, lbl_95_data_2C38, 1);
    Energy* control = (Energy*)__dynamic_cast(
        kinetic->getEnergy(2), 0,
        lbl_95_data_81D8, lbl_95_data_2C38, 1);

    Vec2f a;
    Vec2f::copy(a, stop->getSpeed());
    Vec2f b;
    Vec2f::copy(b, gravity->getSpeed());
    Vec2f c;
    Vec2f::copy(c, control->getSpeed());

    float lr = accesser->modules->posture->getLr();
    float stickY = controller->getY();
    int status = accesser->modules->status->getKind();

    if (status == 0x120 || status == 0x122) {
        if (lbl_95_rodata_110 != controller->getX()) {
            c.m_x += a.m_x;
            a.m_x = lbl_95_rodata_110;
            stop->enabled = false;
        } else {
            float speed = c.m_x * lr;
            if (speed >= lbl_95_rodata_110 &&
                speed <= params[0] && !stop->enabled) {
                a.m_x = params[0] * lr;
                c.m_x = lbl_95_rodata_110;
                stop->enabled = true;
            }
        }
    }

    if ((unsigned)(status - 0x120) <= 2) {
        if (lbl_95_rodata_110 != stickY) {
            c.m_y += b.m_y;
            b.m_y = lbl_95_rodata_110;
            gravity->enabled = false;
        } else if (c.m_y > -params[8] &&
                   c.m_y <= lbl_95_rodata_110 &&
                   !gravity->enabled) {
            b.m_y = c.m_y;
            c.m_y = lbl_95_rodata_110;
            gravity->enabled = true;
        }
    }

    fn_95_11ADC(stop, &a);
    gravity->y = b.m_y;
    fn_95_11ADC(control, &c);

    if (status != 0x121 && status != 0x123) {
        float magnitude = __fabsf(c.m_y);
        float rate = magnitude / params[5];

        if (c.m_y > lbl_95_rodata_110)
            rate *= params[9] - lbl_95_rodata_114;
        else if (c.m_y < lbl_95_rodata_110)
            rate *= params[10] - lbl_95_rodata_114;

        rate += lbl_95_rodata_114;
        motion->setRate(rate);
        accesser->modules->sound->setRate(2, rate);
    } else {
        motion->setRate(lbl_95_rodata_114);
        accesser->modules->sound->setRate(2, lbl_95_rodata_114);
    }
}
