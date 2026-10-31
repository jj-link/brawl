#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

class Class_782C {
public:
    virtual void fn_120_5CB0();
    virtual void fn_120_120CC();
    virtual void fn_120_13B3C();
    virtual void fn_120_13B38();
    virtual void fn_120_13B34();
    virtual void fn_120_13B30();
    virtual void* fn_120_13B28(int);
    virtual void fn_120_13B70();
    virtual void fn_120_13B68();
    virtual void fn_120_13B60();
    virtual void fn_120_13B58();
    virtual void fn_120_13B50();
    virtual void fn_120_13AE8();
    virtual void fn_120_13B1C();
    virtual void fn_120_13B10();
    virtual void fn_120_13B08();
};

class Class_7A04 {
public:
    virtual void fn_120_5CB0();
    virtual void fn_120_12188();
    virtual void fn_120_13D28();
    virtual void fn_120_13D20();
    virtual void fn_120_13D18();
    virtual void fn_120_13D10();
    virtual void fn_120_13D08();
    virtual void fn_120_13D00();
    virtual void fn_120_13CF8();
    virtual void fn_120_13CF0();
    virtual void fn_120_13CE8();
    virtual void fn_120_13CE0();
    virtual float fn_120_13CD8(int);
    virtual void fn_120_13CD0();
    virtual void fn_120_13C80();
    virtual void fn_120_13CC8(float, int);
};

extern "C" {
extern const char lbl_120_data_7028[];
extern const char lbl_120_data_2208[];
extern const float lbl_120_rodata_50;
extern const float lbl_120_rodata_68;

void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_120_F7F8(void*, soModuleAccesser* accesser) {
    Class_782C* kinetic = *reinterpret_cast<Class_782C**>(
        *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xD8) + 0x7C);
    void* result = kinetic->fn_120_13B28(1);
    soKineticEnergy* energy = static_cast<soKineticEnergy*>(
        __dynamic_cast(result, 0, lbl_120_data_7028, lbl_120_data_2208, 1));

    if ((*reinterpret_cast<Class_7A04**>(
             *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xD8) + 0x64))
            ->fn_120_13CD8(0x11000015) > lbl_120_rodata_50) {
        float value = soValueAccesser::getConstantFloat(accesser, 0xFC4, 0);
        Vec2f speed;
        Vec2f::copy(speed, energy->getSpeed());

        (*reinterpret_cast<Class_7A04**>(
             *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xD8) + 0x64))
            ->fn_120_13CC8(lbl_120_rodata_68, 0x11000015);

        if (speed.m_y >= soValueAccesser::getConstantFloat(accesser, 0xFC5, 0)) {
            value = soValueAccesser::getConstantFloat(accesser, 0xFC6, 0);
        }

        *reinterpret_cast<float*>(reinterpret_cast<char*>(energy) + 0x10) = value;
    }
}
