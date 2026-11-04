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
    virtual int fn_120_13D18(int);
    virtual void fn_120_13D10(int, int);
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
    virtual void fn_120_13CB8();
    virtual int fn_120_13CA8(int);
    virtual void fn_120_13C98(int);
    virtual void fn_120_13C88(int);
    virtual void fn_120_13C70();
};

class Class_50 {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual int slot1C(int, bool, bool, int);
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
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
    virtual void slot58(int, int);
};

extern "C" {
extern const char lbl_120_data_7028[];
extern const char lbl_120_data_2208[];
extern const float lbl_120_rodata_30;
extern const float lbl_120_rodata_38;

void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_120_E6D4(soModuleAccesser* accesser, int flag) {
    Class_782C* kinetic = *reinterpret_cast<Class_782C**>(
        *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xD8) + 0x7C);
    void* result = kinetic->fn_120_13B28(1);
    soKineticEnergy* energy = static_cast<soKineticEnergy*>(
        __dynamic_cast(result, 0, lbl_120_data_7028, lbl_120_data_2208, 1));

    if (((*reinterpret_cast<Class_7A04**>(
              *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xD8) + 0x64))
             ->fn_120_13CA8(0x22000012) != 0) &&
        ((*reinterpret_cast<Class_7A04**>(
              *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xD8) + 0x64))
             ->fn_120_13CD8(0x11000015) > lbl_120_rodata_30)) {
        float value = soValueAccesser::getConstantFloat(accesser, 0xFC4, 0);
        Vec2f speed;
        Vec2f::copy(speed, energy->getSpeed());
        if (speed.m_y >= soValueAccesser::getConstantFloat(accesser, 0xFC5, 0)) {
            value = soValueAccesser::getConstantFloat(accesser, 0xFC6, 0);
        }
        *reinterpret_cast<float*>(reinterpret_cast<char*>(energy) + 0x10) =
            value - soValueAccesser::getConstantFloat(accesser, 0xFC9, 0);
        if (flag != 0) {
            value = lbl_120_rodata_38;
            float scale = soValueAccesser::getConstantFloat(accesser, 0xFCD, 0);
            if (scale != lbl_120_rodata_30) {
                value *= soValueAccesser::getConstantFloat(accesser, 0xFCE, 0);
            }
            (*reinterpret_cast<Class_7A04**>(
                 *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xD8) + 0x64))
                ->fn_120_13CC8(-value, 0x11000015);
        }
        (*reinterpret_cast<Class_7A04**>(
             *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xD8) + 0x64))
            ->fn_120_13C98(0x22000015);
        if ((*reinterpret_cast<Class_7A04**>(
                 *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xD8) + 0x64))
                ->fn_120_13CA8(0x22000016) == 0) {
            int handle = (*reinterpret_cast<Class_50**>(
                 *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xD8) + 0x50))
                ->slot1C(0x1775, false, false, 0);
            (*reinterpret_cast<Class_7A04**>(
                 *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xD8) + 0x64))
                ->fn_120_13D10(handle, 0x20000003);
            (*reinterpret_cast<Class_7A04**>(
                 *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xD8) + 0x64))
                ->fn_120_13C98(0x22000016);
        }
    } else {
        *reinterpret_cast<float*>(reinterpret_cast<char*>(energy) + 0x10) =
            -soValueAccesser::getConstantFloat(accesser, 0xFC9, 0);
        *reinterpret_cast<float*>(reinterpret_cast<char*>(energy) + 0x14) =
            soValueAccesser::getConstantFloat(accesser, 0xFCA, 0);
        (*reinterpret_cast<Class_7A04**>(
             *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xD8) + 0x64))
            ->fn_120_13C88(0x22000015);
        if ((*reinterpret_cast<Class_7A04**>(
                 *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xD8) + 0x64))
                ->fn_120_13CA8(0x22000016) != 0) {
            int v = (*reinterpret_cast<Class_7A04**>(
                 *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xD8) + 0x64))
                ->fn_120_13D18(0x20000003);
            if (v >= 0) {
                (*reinterpret_cast<Class_50**>(
                     *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xD8) + 0x50))
                    ->slot58(v, 0);
            }
            (*reinterpret_cast<Class_7A04**>(
                 *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xD8) + 0x64))
                ->fn_120_13C88(0x22000016);
        }
    }
}
