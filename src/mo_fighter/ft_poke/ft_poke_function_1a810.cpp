#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern const char lbl_116_data_6E04[], lbl_116_data_2260[];
extern const float lbl_116_rodata_60;

void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec2f* fn_116_CB3C(Vec2f*, const Vec2f*);
void fn_27_15FBC8(int);
}

extern "C" void fn_116_1A810(void*, int, const void*, soModuleAccesser* accesser) {
    fn_27_15FBC8(6);

    soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(3), 0,
        lbl_116_data_6E04, lbl_116_data_2260, 1));

    if (accesser->getWorkManageModule().isFlag(0x22000010) == false) {
        Vec2f speed;
        Vec2f::copy(speed, energy->getSpeed());

        float value;
        if (accesser->getWorkManageModule().isFlag(0x22000011)) {
            value = soValueAccesser::getConstantFloat(accesser, 0xfa9, 0);
        } else {
            value = soValueAccesser::getConstantFloat(accesser, 0xfa8, 0);
        }

        speed.m_x = value * accesser->getPostureModule().getLr();
        fn_116_CB3C(
            reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(energy) + 8),
            &speed);
    }

    fn_116_CB3C(
        reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(energy) + 0x20),
        &Vec2f(soValueAccesser::getConstantFloat(accesser, 0xfad, 0),
               lbl_116_rodata_60));
}
