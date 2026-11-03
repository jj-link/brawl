#include <mt/mt_vector.h>
#include <mt/mt_prng.h>
#include <internal/fdlibm_public.h>
#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* slot6(int);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();
};

class Class_7618 {
public:
    virtual void fn_27_66114();
    virtual void fn_27_66154();
    virtual void fn_27_661B4();
    virtual void fn_27_661B8();
    virtual void fn_27_661C8();
    virtual void fn_27_661D4(int, unsigned long);
    virtual void fn_27_66284();
    virtual void fn_27_6636C();
    virtual void fn_27_665FC();
    virtual void fn_27_666AC();
    virtual void fn_27_666FC();
    virtual void fn_27_66864();
    virtual float fn_27_669B0(unsigned long);
    virtual void fn_27_66A70();
    virtual void fn_27_66BD4();
    virtual void fn_27_66BDC();
    virtual void fn_27_66CBC();
};

class soPostureModuleImpl {
public:
    virtual void isNull();
    virtual ~soPostureModuleImpl();
    virtual void fn_27_2362C();
    virtual void fn_27_236B0();
    virtual void fn_27_25088();
    virtual void fn_27_23E84();
    virtual void fn_27_25184();
    virtual void fn_27_2370C();
    virtual void fn_27_23728();
    virtual float fn_27_23E28();
    virtual void fn_27_23CC0();
    virtual void fn_27_25068();
    virtual void fn_27_23A9C();
    virtual void fn_27_23B18();
    virtual void fn_27_250FC();
    virtual void fn_27_250A4();
    virtual void fn_27_23BF8();
};

struct Modules {
    char p0[0xc];
    soPostureModuleImpl* posture;
    char p10[0x54];
    Class_7618* work;
    char p68[8];
    soNullable* status;
    char p74[8];
    soNullable* kinetic;
};
struct Accesser {
    char p0[8];
    void* cast;
    char pc[0xcc];
    Modules* modules;
};
struct Params {
    int p0;
    int start;
    float speedMin, speedMax;
    float timeMin, timeMax;
    int end;
    float gravity;
};
struct Data {
    char p0[0x34];
    Params* params;
};
struct Energy {
    char p0[8];
    Vec2f speed;
    Vec2f accel;
    Vec2f limit;
    void setSpeed(const Vec2f& v) { speed = v; }
    void setAccel(const Vec2f& v) { accel = v; }
    void setLimit(const Vec2f& v) { limit = v; }
};
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
Data* fn_27_3A97E8(void*);
void fn_27_3A99A4(void*);
extern const char lbl_27_data_9D1F8[];
extern const char lbl_27_data_248[];
extern const char lbl_27_data_457C0[];
extern const char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_7F58;
extern const float lbl_27_rodata_7F5C;

void fn_27_3AA35C(void*, Accesser* acc) {
    void* obj = __dynamic_cast(acc->cast, 0x3c, lbl_27_data_9D1F8, lbl_27_data_248, 1);
    int state = acc->modules->status->slot16();
    if (state == 0) {
        int value = fn_27_3A97E8(obj)->params->start;
        acc->modules->work->fn_27_661D4(value, 0x10000003);
        acc->modules->work->fn_27_661D4(value, 0x10000004);
        fn_27_3A99A4(obj);
    } else if (state == 1) {
        Params* p = fn_27_3A97E8(obj)->params;
        float lr = acc->modules->posture->fn_27_23E28();
        float ratio = acc->modules->work->fn_27_669B0(0x11000001);
        float angle = acc->modules->work->fn_27_669B0(0x11000002);
        acc->modules->work->fn_27_661D4((int)(p->timeMin + ratio * (p->timeMax - p->timeMin)), 0x20000000);
        float speed = p->speedMin + ratio * (p->speedMax - p->speedMin);
        Vec2f v;
        v.m_x = lr * (speed * (float)cos(angle));
        v.m_y = speed * (float)sin(angle);
        Energy* e = (Energy*)__dynamic_cast(acc->modules->kinetic->slot6(0), 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1);
        e->setSpeed(v);
        e->setLimit(Vec2f(lbl_27_rodata_7F58, lbl_27_rodata_7F58));
        e->setAccel(Vec2f(lbl_27_rodata_7F5C, -p->gravity));
    } else if (state == 2) {
        int value = fn_27_3A97E8(obj)->params->end;
        acc->modules->work->fn_27_661D4(value, 0x10000003);
        acc->modules->work->fn_27_661D4(value, 0x10000004);
        acc->modules->work->fn_27_661D4(randi(4) + 3, 0x20000000);
    }
}
}
