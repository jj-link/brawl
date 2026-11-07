#include <mt/mt_vector.h>
#pragma force_active on

class StatusMod {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual int slot3();
};
class WorkMod {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual int getInt(unsigned int);
    virtual void setInt(int, unsigned int);
    virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual float getFloat(unsigned int);
    virtual void setFloat(unsigned int, float);
};
struct Flag {
    short m_value;
    Flag(short v) : m_value(v) { }
};
class KineticMod {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual void* getEnergy(int);
    virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
    virtual Vec2f getSumSpeed(Flag);
};
class Energy {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
    virtual void resetEnergy(int, Vec2f*, Vec3f*, void*);
    virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12();
    virtual void slot13();
};
struct Modules {
    char pad0[0x14]; StatusMod* status;
    char pad1[0x64 - 0x18]; WorkMod* work;
    char pad2[0x7c - 0x68]; KineticMod* kinetic;
};
struct Owner { char pad[0xd8]; Modules* modules; };

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, long);
extern char lbl_27_data_2E5F8[];
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_8084;
extern const float lbl_27_rodata_8080;
float fn_27_192278(void*, unsigned long);
void fn_27_3BF00C(void*, Owner*);
void fn_27_89DAC(int, void*);
}

static inline void enterGround(Owner* owner) {
    Energy* e = (Energy*)__dynamic_cast(owner->modules->kinetic->getEnergy(3), 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
    float x = lbl_27_rodata_8080 * owner->modules->work->getFloat(0x21000011);
    e->resetEnergy(0x16, &Vec2f(x, lbl_27_rodata_8084), &Vec3f(lbl_27_rodata_8084, lbl_27_rodata_8084, lbl_27_rodata_8084), owner);
    *(Vec2f*)((char*)e + 0x18) = Vec2f(x, lbl_27_rodata_8084);
    e->slot12();
    ((unsigned char*)e)[5] |= 0x80;
}

static inline void enterAir(Owner* owner) {
    Energy* stop = (Energy*)__dynamic_cast(owner->modules->kinetic->getEnergy(3), 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
    Energy* grav = (Energy*)__dynamic_cast(owner->modules->kinetic->getEnergy(1), 0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
    Vec2f v;
    Vec2f::copy(v, owner->modules->kinetic->getSumSpeed(Flag(1)));
    stop->resetEnergy(6, &Vec2f(v.m_x, lbl_27_rodata_8084), &Vec3f(lbl_27_rodata_8084, lbl_27_rodata_8084, lbl_27_rodata_8084), owner);
    ((unsigned char*)stop)[5] |= 0x80;
    grav->resetEnergy(0, &Vec2f(lbl_27_rodata_8084, v.m_y), &Vec3f(lbl_27_rodata_8084, lbl_27_rodata_8084, lbl_27_rodata_8084), owner);
    *(float*)((char*)grav + 0x10) = -fn_27_192278(owner, 0xfa0);
    *(float*)((char*)grav + 0x1c) = fn_27_192278(owner, 0xfa1);
    *(float*)((char*)grav + 0x14) = fn_27_192278(owner, 0xfa1);
    ((unsigned char*)grav)[5] |= 0x80;
}

extern "C" void fn_27_3BEC9C(void* self, Owner* owner) {
    int status = owner->modules->status->slot3();
    int prev = owner->modules->work->getInt(0x20000008);
    owner->modules->work->setFloat(0x21000009, lbl_27_rodata_8084);
    fn_27_3BF00C(self, owner);
    if (status != prev) {
        if (status == 0) {
            enterGround(owner);
            WorkMod* w = owner->modules->work;
            w->setFloat(0x21000008, fn_27_192278(owner, 0xfa2));
            fn_27_89DAC(1, owner);
        } else {
            enterAir(owner);
        }
    }
    owner->modules->work->setInt(status, 0x20000008);
}
