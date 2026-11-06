#include <so/so_value_accesser.h>
#pragma force_active on

class Class_823C {
public:
    virtual void fn_115_672C();
    virtual void fn_115_15384();
    virtual void fn_115_17168();
    virtual void fn_115_17164();
    virtual void fn_115_17160();
    virtual void fn_115_1715C();
    virtual void fn_115_17154();
    virtual void fn_115_1719C();
    virtual void fn_115_17194();
    virtual void fn_115_1718C();
    virtual void fn_115_17184();
    virtual void fn_115_1717C();
    virtual float fn_115_17114(unsigned int);
    virtual void fn_115_17148(float, unsigned int);
    virtual void fn_115_1713C();
    virtual void fn_115_17134();
    virtual void fn_115_17128();
};
class Class_83BC {
public:
    virtual void fn_115_672C();
    virtual void fn_115_15440();
    virtual void fn_115_17334();
    virtual void fn_115_1732C();
    virtual void fn_115_17324();
    virtual void fn_115_1731C();
    virtual void fn_115_17314();
    virtual void fn_115_1730C();
    virtual void fn_115_17304();
    virtual void fn_115_172FC();
    virtual void fn_115_172F4();
    virtual void fn_115_172EC();
    virtual void fn_115_172E4();
    virtual void fn_115_172DC();
    virtual void fn_115_1728C();
    virtual void fn_115_172D4();
    virtual int fn_115_172C4();
};
class Class_A860 {
public:
    virtual void fn_115_1B904();
    virtual void fn_115_1B73C();
    virtual void fn_115_1B748();
    virtual int fn_115_1B810();
    virtual void fn_115_1B85C();
    virtual void fn_115_1B864();
    virtual void fn_115_1B86C();
    virtual void fn_115_1B874();
    virtual void fn_115_1B87C();
    virtual void fn_115_1B888();
    virtual void fn_115_1B890();
    virtual void fn_115_1B898();
    virtual void fn_115_1B8A0();
    virtual void fn_115_1B8A4();
    virtual void fn_115_1B8A8();
    virtual void fn_115_1B8AC();
    virtual void fn_115_1B8B0();
};
struct Pair { float x, y; };
struct Speed {
    float x, y;
    Speed() {}
    Speed(float a, float b) : x(a), y(b) {}
};
struct Vector { float x, y, z; };
struct Accesser;
class Energy {
public:
    virtual void f0(); virtual void f1(); virtual void f2();
    virtual void f3(); virtual void f4();
    virtual void reset(int, Speed*, Vector*, Accesser*);
    unsigned char state, flags;
};
class Kinetic {
public:
    virtual void f0(); virtual void f1(); virtual void f2();
    virtual void f3(); virtual void f4(); virtual void f5();
    virtual Energy* getEnergy(int);
    virtual void f7(); virtual void f8(); virtual void f9();
    virtual void f10(); virtual void f11(); virtual void f12();
    virtual Pair getSum(const unsigned short&);
};
struct Modules {
    char pad[0x14];
    Class_A860* situation;
    char pad2[0x20];
    soDamageModule* damage;
    char pad3[0x28];
    Class_823C* work;
    char pad4[8];
    Class_83BC* status;
    char pad5[8];
    Kinetic* kinetic;
};
struct Accesser { char pad[0xd8]; Modules* modules; };

extern "C" {
extern const float lbl_115_rodata_58, lbl_115_rodata_5C;
extern const char lbl_115_data_7524[], lbl_115_data_7444[], lbl_115_data_2760[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vector* fn_115_8EF8(Vector*, float, float, float);
void fn_115_F0A8(Accesser*);
}
extern "C" void fn_115_ECB8(void*, Accesser* accesser) {
    switch (accesser->modules->status->fn_115_172C4()) {
    case 0x114:
        accesser->modules->work->fn_115_17148(lbl_115_rodata_58, 0x21000005);
        if (accesser->modules->situation->fn_115_1B810() != 0)
            fn_115_F0A8(accesser);
        break;
    case 0x129: {
        soDamageModule* damage = accesser->modules->damage;
        damage->addDamage(soValueAccesser::getConstantFloat(
            reinterpret_cast<soModuleAccesser*>(accesser), 0xfb6, 0), 0);
        unsigned short mask = 1;
        Speed speed;
        Pair sum = accesser->modules->kinetic->getSum(mask);
        __memcpy(&speed, &sum, sizeof(speed));
        float x = accesser->modules->work->fn_115_17114(0x21000007);
        float y = accesser->modules->work->fn_115_17114(0x21000008);
        speed.x *= soValueAccesser::getConstantFloat(reinterpret_cast<soModuleAccesser*>(accesser), 0xfb7, 0);
        speed.y *= soValueAccesser::getConstantFloat(reinterpret_cast<soModuleAccesser*>(accesser), 0xfb7, 0);
        Energy* gravity = static_cast<Energy*>(__dynamic_cast(
            accesser->modules->kinetic->getEnergy(1), 0,
            lbl_115_data_7524, lbl_115_data_2760, 1));
        Speed vertical(lbl_115_rodata_5C, speed.y + y);
        Vector rotation;
        gravity->reset(0, &vertical, fn_115_8EF8(&rotation,
            lbl_115_rodata_5C, lbl_115_rodata_5C, lbl_115_rodata_5C), accesser);
        gravity->flags |= 0x80;
        Energy* stop = static_cast<Energy*>(__dynamic_cast(
            accesser->modules->kinetic->getEnergy(3), 0,
            lbl_115_data_7444, lbl_115_data_2760, 1));
        Speed horizontal(speed.x + x, lbl_115_rodata_5C);
        Vector rotation2;
        stop->reset(6, &horizontal, fn_115_8EF8(&rotation2,
            lbl_115_rodata_5C, lbl_115_rodata_5C, lbl_115_rodata_5C), accesser);
        stop->flags |= 0x80;
        break;
    }
    }
}
