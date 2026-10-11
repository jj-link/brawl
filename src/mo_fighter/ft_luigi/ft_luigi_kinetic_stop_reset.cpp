#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

extern "C" {
extern const char lbl_99_data_6244[], lbl_99_data_171C[];
extern const float lbl_99_rodata_10;
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec2f* fn_99_AA80(Vec2f*, const Vec2f*);
void fn_27_15FBC8(int);
}

extern "C" void fn_99_C22C(void*, int, const void*, soModuleAccesser* accesser) {
    fn_27_15FBC8(6);
    soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(3), 0,
        lbl_99_data_6244, lbl_99_data_171C, 1));
    if (accesser->getWorkManageModule().isFlag(0x22000014) == false &&
        accesser->getWorkManageModule().isFlag(0x22000013) == true) {
        Vec2f speed(lbl_99_rodata_10, lbl_99_rodata_10);
        fn_99_AA80(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(energy) + 8), &speed);
    }
    Vec2f limit(soValueAccesser::getConstantFloat(accesser, 0xfb7, 0), lbl_99_rodata_10);
    fn_99_AA80(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(energy) + 0x20), &limit);
}
