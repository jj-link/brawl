#pragma force_active on
namespace {
struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
};

inline Vec2* temporaryVector(const Vec2& v) {
    return const_cast<Vec2*>(&v);
}
}

struct Vec3 {
    float x, y, z;
};

struct Flag {
    unsigned short mask;
};

class Work {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void incInt(unsigned int);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual bool isFlag(unsigned int);
    virtual void onFlag(unsigned int);
};

struct Accesser;

class Energy {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void resetEnergy(int, Vec2*, Vec3*, Accesser*);
};

class Kinetic {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Energy* getEnergy(int);
    virtual void v7();
    virtual void v8();
    virtual void clearSpeedAll();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual Vec2 getSumSpeed(const Flag&);
};

class Slope {
public:
    virtual void v0();
    virtual void v1();
    virtual void setStatus(unsigned int, int, bool);
    virtual unsigned int getStatus();
};

class Visibility {
public:
    virtual void v0();
    virtual void v1();
    virtual void set(unsigned int, int);
};

struct Modules {
    char pad0[0x58];
    Visibility* visibility;
    char pad1[8];
    Work* work;
    char pad2[0x14];
    Kinetic* kinetic;
    char pad3[0x20];
    Slope* slope;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

extern "C" {
extern const char lbl_102_data_5D8C[];
extern const char lbl_102_data_14F4[];
extern const float lbl_102_rodata_10;

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_102_C1DC(Accesser*);
Vec3* fn_102_C5B8(Vec3*, float, float, float);
}

extern "C" void fn_102_CBB0(void*, Accesser* accesser) {
    Work* work = accesser->modules->work;

    if (work->isFlag(0x22000010) && !work->isFlag(0x22000011)) {
        Flag flag;
        flag.mask = 1;
        Vec2 speed;
        __memcpy(&speed, &accesser->modules->kinetic->getSumSpeed(flag),
                 sizeof(Vec2));

        accesser->modules->kinetic->clearSpeedAll();
        fn_102_C1DC(accesser);

        Energy* motion = (Energy*)__dynamic_cast(
            accesser->modules->kinetic->getEnergy(3), 0,
            lbl_102_data_5D8C, lbl_102_data_14F4, 1);

        Vec3 rotation;
        motion->resetEnergy(
            0, temporaryVector(Vec2(speed.x, lbl_102_rodata_10)),
            fn_102_C5B8(&rotation, lbl_102_rodata_10,
                        lbl_102_rodata_10, lbl_102_rodata_10),
            accesser);

        reinterpret_cast<unsigned char*>(motion)[5] |= 0x80;
        work->onFlag(0x22000011);
    }

    work->incInt(0x20000000);
    Slope* slope = accesser->modules->slope;

    if (work->isFlag(0x22000014)) {
        if (slope->getStatus() != 1) {
            slope->setStatus(1, 6, true);
        }
    } else {
        if (slope->getStatus() != 6) {
            slope->setStatus(6, 3, false);
        }
    }

    if (work->isFlag(0x22000013)) {
        accesser->modules->visibility->set(1, 1);
        accesser->modules->visibility->set(0, -1);
    } else {
        accesser->modules->visibility->set(1, 0);
        if (work->isFlag(0x12000006)) {
            accesser->modules->visibility->set(0, 0);
        }
    }
}
