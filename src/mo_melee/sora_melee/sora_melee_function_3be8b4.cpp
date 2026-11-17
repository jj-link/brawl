#pragma force_active on
#pragma fp_contract off
#include <types.h>
#include <mt/mt_vector.h>
#include <so/so_value_accesser.h>

class Posture { public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
    virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual float getLR();
};
class Status { public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual int getStatus();
};
class Work { public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual int getInt(unsigned int); virtual void setInt(int, unsigned int);
    virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
    virtual void slot10(); virtual void slot11(); virtual float getFloat(unsigned int); virtual void setFloat(unsigned int, float);
};
struct Flag { short value; Flag(short v) : value(v) {} };
class Kinetic { public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual void* getEnergy(int); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10();
    virtual void slot11(); virtual void slot12(); virtual Vec2f getSumSpeed(Flag);
};
class Energy { public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
    virtual void resetEnergy(int, Vec2f*, Vec3f*, void*);
    virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10();
    virtual void slot11(); virtual void slot12(); virtual void slot13();
    char flags[12]; float a, b, c, d, e, f;
};
struct Modules {
    char pad0[0x0c]; Posture* posture;
    char pad1[0x14 - 0x10]; Status* status;
    char pad2[0x64 - 0x18]; Work* work;
    char pad3[0x7c - 0x68]; Kinetic* kinetic;
};
struct Owner { char pad[0xd8]; Modules* modules; };

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, long);
extern char lbl_27_data_2E5F8[], lbl_27_data_2E430[], lbl_27_data_CDF8[];
extern const float lbl_27_rodata_8080, lbl_27_rodata_8084;
float fn_27_192278(void*, unsigned long);
void fn_27_3C758C(void*);
void fn_27_89DAC(int, void*);
}

static inline void enterGround(Owner* owner) {
    Energy* e = (Energy*)__dynamic_cast(owner->modules->kinetic->getEnergy(3), 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
    float x = lbl_27_rodata_8080 * owner->modules->work->getFloat(0x21000011);
    e->resetEnergy(0x16, &Vec2f(x, lbl_27_rodata_8084),
                   &Vec3f(lbl_27_rodata_8084, lbl_27_rodata_8084, lbl_27_rodata_8084), owner);
    *(Vec2f*)((char*)e + 0x18) = Vec2f(x, lbl_27_rodata_8084);
    e->slot12();
    ((unsigned char*)e)[5] |= 0x80;
}
static inline void enterAir(Owner* owner) {
    Energy* stop = (Energy*)__dynamic_cast(owner->modules->kinetic->getEnergy(3), 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
    Energy* grav = (Energy*)__dynamic_cast(owner->modules->kinetic->getEnergy(1), 0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
    short mask = 1;
    Vec2f speed;
    Vec2f::copy(speed, owner->modules->kinetic->getSumSpeed(Flag(mask)));
    stop->resetEnergy(6, &Vec2f(speed.m_x, lbl_27_rodata_8084),
                      &Vec3f(lbl_27_rodata_8084, lbl_27_rodata_8084, lbl_27_rodata_8084), owner);
    ((unsigned char*)stop)[5] |= 0x80;
    grav->resetEnergy(0, &Vec2f(lbl_27_rodata_8084, speed.m_y),
                      &Vec3f(lbl_27_rodata_8084, lbl_27_rodata_8084, lbl_27_rodata_8084), owner);
    grav->a = -fn_27_192278(owner, 0xfa0);
    grav->d = fn_27_192278(owner, 0xfa1);
    grav->b = fn_27_192278(owner, 0xfa1);
    ((unsigned char*)grav)[5] |= 0x80;
}
extern "C" void fn_27_3BE8B4(void* self, Owner* owner) {
    float lr = owner->modules->posture->getLR();
    owner->modules->work->setFloat(0x2100000a, lr);
    int value = soValueAccesser::getConstantInt((soModuleAccesser*)owner, 0x5a03, 0);
    owner->modules->work->setInt(value, 0x2000000d);
    owner->modules->work->setFloat(0x21000011, lr);
    fn_27_3C758C(owner);
    if (owner->modules->status->getStatus() == 0) {
        enterGround(owner);
        Work* work = owner->modules->work;
        work->setFloat(0x21000008, fn_27_192278(owner, 0xfa2));
        fn_27_89DAC(1, owner);
    } else {
        enterAir(owner);
    }
    Work* work = owner->modules->work;
    int status = owner->modules->status->getStatus();
    work->setInt(status, 0x20000008);
    fn_27_89DAC(2, owner);
    fn_27_89DAC(0, owner);
}