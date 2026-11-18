#include <math.h>
#pragma force_active on

extern "C" {
extern const unsigned char lbl_121_data_7C34[];
extern const unsigned char lbl_121_data_3CF0[];
extern const unsigned char lbl_121_data_8EF0[];
extern const unsigned char lbl_121_data_31F4[];
extern const float lbl_121_rodata_A0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
float rsqrtf__Ff(float);
}

struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
};

struct Vec3 {
    float x, y, z;
    Vec3();
    Vec3(const Vec3&);
};

extern "C" Vec2* fn_121_DAE8(Vec2*, const Vec2*);
extern "C" Vec3 fn_121_10470(const Vec3&, const Vec3&);

class KineticModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void* getEnergy(int);
};

class WorkModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual int getInt(unsigned int);
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void decInt(unsigned int);
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual float getFloat(unsigned int);
    virtual void setFloat(float, unsigned int);
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual int isFlag(unsigned int);
};

class ModelModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual unsigned int check(int);
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8C();
    virtual void slot90();
    virtual void slot94();
    virtual Vec3 getNode(unsigned int, unsigned int, bool);
};

class PostureModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual Vec3 getPos();
};

struct Modules {
    unsigned char unused0[0x0C];
    PostureModule* posture;
    unsigned char unused1[0x44];
    ModelModule* model;
    unsigned char unused2[0x0C];
    WorkModule* work;
    unsigned char unused3[0x14];
    KineticModule* kinetic;
};

struct Accesser {
    unsigned char unused0[8];
    void* stageObject;
    unsigned char unused1[0xCC];
    Modules* modules;
};

struct Fighter {
    unsigned char unused[0x20E4];
    unsigned char* parameters;
};

class Energy {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual Vec2 getSpeed();
};

extern "C" void fn_121_14DE8(void*, Accesser* accesser)
{
    const float* k = lbl_121_rodata_A0;
    unsigned char* parameters = static_cast<Fighter*>(__dynamic_cast(
        accesser->stageObject, 0x3C,
        lbl_121_data_7C34, lbl_121_data_3CF0, 1))->parameters;

    float angle = accesser->modules->work->getFloat(0x11000001);
    if (accesser->modules->model->check(1) == 1) {
        if (accesser->modules->work->isFlag(0x12000004) == 0) {
            if (accesser->modules->work->getInt(0x20000000) > 0) {
                Vec3 a = accesser->modules->model->getNode(1, *reinterpret_cast<int*>(parameters + 0x38), 1);
                Vec3 c = fn_121_10470(a, accesser->modules->posture->getPos());
                float target = (float)atan2(c.y, c.x);
                if (target < k[2]) {
                    target += k[3];
                } else if (target > k[1]) {
                    target -= k[3];
                }
                float diff = target - angle;
                if (diff < k[2]) {
                    diff += k[3];
                } else if (diff > k[1]) {
                    diff -= k[3];
                }
                float limit = *reinterpret_cast<float*>(parameters + 0x2C);
                if (diff > limit) {
                    diff = limit;
                } else if (diff < -limit) {
                    diff = -limit;
                }
                angle += diff;
                accesser->modules->work->setFloat(angle, 0x11000001);
                accesser->modules->work->decInt(0x20000000);
            }
        }
    }
    Energy* energy = static_cast<Energy*>(__dynamic_cast(
        accesser->modules->kinetic->getEnergy(0), 0,
        lbl_121_data_8EF0, lbl_121_data_31F4, 1));
    Vec2 w;
    __memcpy(&w, &energy->getSpeed(), sizeof(w));
    float sum = w.x * w.x + w.y * w.y;
    float len;
    if (static_cast<float>(fabs(sum)) <= k[4]) {
        len = k[0];
    } else {
        len = sum * rsqrtf__Ff(sum);
    }
    float mag = *reinterpret_cast<float*>(parameters + 0x1C) + len;
    float maxMag = *reinterpret_cast<float*>(parameters + 0x20);
    if (mag > maxMag) {
        mag = maxMag;
    }
    fn_121_DAE8(reinterpret_cast<Vec2*>(reinterpret_cast<unsigned char*>(energy) + 8), &Vec2(mag * static_cast<float>(cos(angle)), mag * static_cast<float>(sin(angle))));
}
