#include <ft/ft_common_data_accesser.h>
#include <so/ground/so_ground_module_impl.h>
#pragma force_active on

struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };
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
    virtual void v0(); virtual void v1(); virtual void v2(); virtual int kind();
};
class Energy {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void reset(int, Vec2*, Vec3*, Accesser*);
};
class Kinetic {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual Energy* energy(int);
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual Vec2 sum(short*);
};

struct Modules {
    char pad0[8]; Ground* ground;
    char pad1[4]; soGroundModule* status; Situation* situation;
    char pad2[0x4c]; Work* work; char pad3[0x14]; Kinetic* kinetic;
};
struct Accesser { char pad[0xd8]; Modules* modules; };
extern "C" {
extern const char lbl_102_data_5E6C[], lbl_102_data_14F4[];
extern const float lbl_102_rodata_20;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_102_D694(Accesser*);
Vec3* fn_102_C5B8(Vec3*, float, float, float);
}
extern "C" void fn_102_DCC0(void*, Accesser* f) {
    Work* work = f->modules->work;
    float* data = *(float**)((char*)g_ftCommonDataAccesser.getData((ftKind)11) + 0x84);
    Vec2 speed;
    if (!work->isFlag(0x22000011) && f->modules->ground->check()) {
        fn_102_D694(f);
        Energy* energy = (Energy*)__dynamic_cast(f->modules->kinetic->energy(1), 0,
            lbl_102_data_5E6C, lbl_102_data_14F4, 1);
        float sy = data[5];
        Vec2 speed = {lbl_102_rodata_20, sy};
        Vec3 rotation;
        energy->reset(0, &speed, fn_102_C5B8(&rotation, lbl_102_rodata_20,
            lbl_102_rodata_20, lbl_102_rodata_20), f);
        ((float*)energy)[4] = lbl_102_rodata_20;
        ((unsigned char*)energy)[5] |= 0x80;
        work->onFlag(0x22000011);
    }
    short attr = 1;
    Vec2 sum = f->modules->kinetic->sum(&attr);
    __memcpy(&speed, &sum, sizeof(speed));
    if (work->isFlag(0x22000011) || speed.y < data[5]) {
        Energy* energy = (Energy*)__dynamic_cast(f->modules->kinetic->energy(1), 0,
            lbl_102_data_5E6C, lbl_102_data_14F4, 1);
        ((float*)energy)[3] = data[5];
    }
    if (f->modules->situation->kind() == 2) {
        if (work->isFlag(0x22000010)) {
            f->modules->status->setCliffCheck((soGroundShapeImpl::CliffCheckKind)2, 0);
        } else {
            f->modules->status->setCliffCheck((soGroundShapeImpl::CliffCheckKind)0, 0);
        }
    }
}