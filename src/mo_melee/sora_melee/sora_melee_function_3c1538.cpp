#include <nw4r/math/math_arithmetic.h>
#include <mt/mt_vector.h>

#pragma force_active on

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};
struct Owner;
struct EnergyValues {
    Vec2f acceleration;
    Vec2f brake;
    Vec2f speedLimit;
    Vec2f speedMax;
};
struct SecondaryBase { char pad[8]; };
struct Object_vptr_3c_base { char pad[0x3c]; };

class Work {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int getInt(int);
    virtual void setInt(int, int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void setFlag(int, int);
    virtual void addInt(int, int);
    virtual void slot11();
    virtual float getFloat(int);
    virtual void setFloat(float, int);
    virtual void slot14();
    virtual void slot15();
    virtual void subFloat(float, int);
    virtual void slot17();
    virtual void onFlag(int);
};

class Situation {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int getSituation();
};

class Posture {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float getDirection();
};

class Controller {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual float getStickX();
};

class Motion {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void updateDirection();
};

class Status {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void changeStatus(int, Owner*);
};

class Energy {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void reset(int, const Vec2f*, const Vec3*, Owner*);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void clear();

    unsigned char pad04;
    unsigned char flags;
    char pad06[2];
    Vec2f speed;
    EnergyValues fields;
};

class Kinetic {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* getEnergy(int);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual Vec2f getSpeed(short*);
};

class Model : public SecondaryBase {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void setScale(int, const Vec3f*);
    virtual Vec3 getRotation(int);
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void setRotation(int, const Vec3*);
};

class GroundModule : public SecondaryBase {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual Vec2f getVector(int, int);
};

class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual int getKind();
};

struct Modules {
    char pad00[4];
    Model* model;
    char pad08[4];
    Posture* posture;
    GroundModule* ground;
    Situation* situation;
    char pad18[4];
    Motion* motion;
    char pad20[0x3c];
    Controller* controller;
    char pad60[4];
    Work* work;
    char pad68[8];
    Status* status;
    char pad74[8];
    Kinetic* kinetic;
};

struct Owner {
    char pad00[8];
    Object_vptr_3c* task;
    char pad0c[0xcc];
    Modules* modules;
};

extern "C" {
extern const float lbl_27_rodata_8080[];
extern float lbl_27_data_A2010[];
extern float lbl_27_data_A2020[];
extern char lbl_27_data_2E5F8[];
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_27_192278(Owner*, unsigned long);
void fn_27_3C2CD4(void*, Owner*);
void fn_27_89DAC(int, Owner*);
}

static inline void initializeEnergy(Owner* owner, const float* c, Vec3& zero)
{
    Energy* energy = static_cast<Energy*>(__dynamic_cast(
        owner->modules->kinetic->getEnergy(3), 0,
        lbl_27_data_2E5F8, lbl_27_data_CDF8, 1));
    __dynamic_cast(owner->modules->kinetic->getEnergy(1), 0,
                   lbl_27_data_2E430, lbl_27_data_CDF8, 1);
    short id = 1;
    Vec2f speed;
    Vec2f::copy(speed, owner->modules->kinetic->getSpeed(&id));
    zero.x = c[1];
    zero.y = c[1];
    zero.z = c[1];
    energy->reset(0, &Vec2f(speed.m_x, c[1]), &zero, owner);
    energy->fields.acceleration = Vec2f(c[1], c[1]);
    energy->fields.brake = Vec2f(c[1], c[1]);
    energy->fields.speedLimit = Vec2f(c[1], c[1]);
    energy->fields.speedMax = Vec2f(c[3], c[3]);
    energy->clear();
    energy->flags |= 0x80;
    fn_27_89DAC(1, owner);
}

static inline void updateGroundSpeed(Owner* owner, const float* c, Energy* energy, Work* work)
{
    float speed = work->getFloat(0x2100000a) *
                  (fn_27_192278(owner, 0xfbf) *
                   (work->getFloat(0x21000005) - fn_27_192278(owner, 0xfbd)));
    Vec2f groundSpeed;
    Vec2f::copy(groundSpeed, owner->modules->ground->getVector(8, 0));
    float extra = nw4r::math::FAbs(groundSpeed.m_x * speed) *
                  fn_27_192278(owner, 0xfc1);
    if (groundSpeed.m_x > c[1])
        speed += extra;
    else
        speed -= extra;

    if (nw4r::math::FAbs(speed) > fn_27_192278(owner, 0xfa4)) {
        if (speed < c[1])
            speed = -fn_27_192278(owner, 0xfa4);
        else
            speed = fn_27_192278(owner, 0xfa4);
    }
    if (nw4r::math::FAbs(speed) > fn_27_192278(owner, 0xfa5)) {
        if (speed < c[1])
            speed = -fn_27_192278(owner, 0xfa5);
        else
            speed = fn_27_192278(owner, 0xfa5);
    }
    owner->modules->work->setFloat(nw4r::math::FAbs(speed), 0x21000007);
    energy->speed = Vec2f(speed, c[1]);
}

static inline void updateAirSpeed(Owner* owner, const float* c, Energy* energy, Work* work)
{
    float speed = work->getFloat(0x2100000a) *
                  (fn_27_192278(owner, 0xfbf) *
                   (work->getFloat(0x21000005) - fn_27_192278(owner, 0xfbd)));
    speed -= speed > c[1] ? fn_27_192278(owner, 0xfa7)
                          : -fn_27_192278(owner, 0xfa7);

    if (nw4r::math::FAbs(speed) < fn_27_192278(owner, 0xfa8)) {
        float sign = speed < c[1] ? c[3] : c[2];
        speed = sign * fn_27_192278(owner, 0xfa8);
    }
    Vec2f newSpeed(speed, c[1]);
    energy->speed = newSpeed;
    owner->modules->work->setFloat(nw4r::math::FAbs(speed), 0x21000007);
}

extern "C" void fn_27_3C1538(void* self, Owner* owner)
{
    Vec3f scale;
    int level;
    int node2;
    Vec3 zero;
    const float* c = lbl_27_rodata_8080;
    int situation = owner->modules->situation->getSituation();
    int oldSituation = owner->modules->work->getInt(0x20000008);
    owner->modules->work->setFloat(c[1], 0x21000009);

    scale.m_x = c[2];
    scale.m_y = c[2];
    scale.m_z = c[2];
    level = owner->modules->work->getInt(0x20000002);
    if (level >= 0 && level < 4) {
        scale.m_x = c[2];
        scale.m_y *= lbl_27_data_A2010[level];
        scale.m_z *= lbl_27_data_A2020[level];
        owner->modules->work->setFlag(1, 0x20000002);
    } else {
        scale.m_x = c[2];
        scale.m_y = c[2];
        scale.m_z = c[2];
    }

    int kind = owner->task->getKind();
    Model* model = owner->modules->model;
    int scaleNode = 3;
    if (kind == 5)
        scaleNode = 0x196;
    model->setScale(scaleNode, &scale);

    float oldAngle = owner->modules->work->getFloat(0x21000006);
    float delta = c[11] * fn_27_192278(owner, 0xfb6) * (owner->modules->work->getFloat(0x2100000a));
    if (owner->modules->situation->getSituation() == 0) {
        delta *= c[5] * owner->modules->work->getFloat(0x21000005);
    } else {
        Work* work = owner->modules->work;
        delta *= c[5] * work->getFloat(0x21000005) * (fn_27_192278(owner, 0xfbe));
    }

    float angle = oldAngle + delta;
    while (angle < c[1])
        angle += c[6];
    while (angle > c[6])
        angle -= c[6];

    owner->modules->work->setFloat(angle, 0x21000006);
    owner->modules->work->addInt(1, 0x20000000);
    if (owner->modules->work->getInt(0x20000000) <= 0 &&
        angle > c[9] && angle < c[12]) {
        if (delta > c[1]) {
            if (angle > c[13] && oldAngle < c[13]) {
                owner->modules->work->setInt(0, 0x20000000);
                owner->modules->work->onFlag(0x22000015);
            }
        } else if (angle < c[13] && oldAngle > c[13]) {
            owner->modules->work->setInt(0, 0x20000000);
            owner->modules->work->onFlag(0x22000015);
        }
    }

    float stick = owner->modules->controller->getStickX();
    if (nw4r::math::FAbs(stick) > fn_27_192278(owner, 0xfab)) {
        float sign = stick > c[1] ? c[2] : c[3];
        if (sign != owner->modules->work->getFloat(0x2100000a)) {
            owner->modules->motion->updateDirection();
            owner->modules->work->setFloat(sign, 0x21000009);
            owner->modules->work->setFloat(-sign, 0x2100000a);
            if (owner->task->getKind() == 5)
                owner->modules->status->changeStatus(0x189, owner);
            else
                owner->modules->status->changeStatus(0x11b, owner);
        }
    }

    if (situation == 0) {
        if (situation != oldSituation)
            initializeEnergy(owner, c, zero);

        Energy* energy = static_cast<Energy*>(__dynamic_cast(
            owner->modules->kinetic->getEnergy(3), 0,
            lbl_27_data_2E5F8, lbl_27_data_CDF8, 1));
        Work* work = owner->modules->work;
        updateGroundSpeed(owner, c, energy, work);
    } else {
        if (situation != oldSituation)
            fn_27_3C2CD4(self, owner);

        Energy* energy = static_cast<Energy*>(__dynamic_cast(
            owner->modules->kinetic->getEnergy(3), 0,
            lbl_27_data_2E5F8, lbl_27_data_CDF8, 1));
        Work* work = owner->modules->work;
        updateAirSpeed(owner, c, energy, work);
    }

    Work* work = owner->modules->work;
    float decrement = fn_27_192278(owner, 0xfbc);
    work->subFloat(decrement, 0x21000005);

    Work* thresholdWork = owner->modules->work;
    float minimum = fn_27_192278(owner, 0xfbd);
    if (thresholdWork->getFloat(0x21000005) < minimum)
        owner->modules->work->onFlag(0x22000015);

    float rotation = owner->modules->work->getFloat(0x21000006);
    int node = owner->task->getKind() == 5 ? 0x197 : 4;
    Vec3 rot = owner->modules->model->getRotation(node);
    rot.x = c[7] * rotation;
    owner->modules->model->setRotation(node, &rot);

    node2 = owner->task->getKind() == 5 ? 0x197 : 4;
    Vec3 rot2 = owner->modules->model->getRotation(node2);
    if (owner->modules->posture->getDirection() == c[3])
        rot2.y = c[4];
    else
        rot2.y = c[1];
    owner->modules->model->setRotation(node2, &rot2);

    owner->modules->work->setInt(situation, 0x20000008);
}
