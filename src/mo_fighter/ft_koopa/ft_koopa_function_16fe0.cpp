#pragma force_active on
#include <ft/ft_common_data_accesser.h>
#include <so/ground/so_ground_module_impl.h>

struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };
struct Params { float f[8]; };
struct Accesser;

class Work {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual bool isFlag(unsigned int);
    virtual void onFlag(unsigned int);
};

class Ground {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual bool check();
};

class Situation {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual int kind();
};

class Kinetic {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void* getEnergy(int);
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual Vec2 getSum(const short*);
};

class Energy {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void reset(int, Vec2*, Vec3*, Accesser*);
};

struct Modules {
    char pad0[8]; Ground* ground;
    char pad1[4]; soGroundModule* status; Situation* situation;
    char pad2[0x4c]; Work* work; char pad3[0x14]; Kinetic* kinetic;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
extern const char lbl_102_data_5E6C[], lbl_102_data_14F4[];
extern const float lbl_102_rodata_68;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_102_169B4(Accesser*);
Vec3* fn_102_C5B8(Vec3*, float, float, float);
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
}

extern "C" void fn_102_16FE0(void*, Accesser* accesser) {
    Work* work = accesser->modules->work;
    Params* params = *(Params**)((char*)getData__20ftCommonDataAccesserCF6ftKind(&g_ftCommonDataAccesser, 0x30) + 0x88);
    Vec2 speed;
    if (!work->isFlag(0x22000011) && accesser->modules->ground->check()) {
        fn_102_169B4(accesser);
        Energy* energy = (Energy*)__dynamic_cast(accesser->modules->kinetic->getEnergy(1), 0,
            lbl_102_data_5E6C, lbl_102_data_14F4, 1);
        float sy = params->f[5];
        Vec2 speed = {lbl_102_rodata_68, sy};
        Vec3 rotation;
        energy->reset(0, &speed, fn_102_C5B8(&rotation, lbl_102_rodata_68,
            lbl_102_rodata_68, lbl_102_rodata_68), accesser);
        ((float*)energy)[4] = lbl_102_rodata_68;
        ((unsigned char*)energy)[5] |= 0x80;
        work->onFlag(0x22000011);
    }
    short attr = 1;
    Vec2 sum = accesser->modules->kinetic->getSum(&attr);
    __memcpy(&speed, &sum, sizeof(Vec2));
    if (work->isFlag(0x22000011) || speed.y < params->f[5]) {
        Energy* energy = (Energy*)__dynamic_cast(accesser->modules->kinetic->getEnergy(1), 0,
            lbl_102_data_5E6C, lbl_102_data_14F4, 1);
        ((float*)energy)[3] = params->f[5];
    }
    if (accesser->modules->situation->kind() == 2) {
        if (work->isFlag(0x22000010)) {
            accesser->modules->status->setCliffCheck((soGroundShapeImpl::CliffCheckKind)2, 0);
        } else {
            accesser->modules->status->setCliffCheck((soGroundShapeImpl::CliffCheckKind)0, 0);
        }
    }
}
