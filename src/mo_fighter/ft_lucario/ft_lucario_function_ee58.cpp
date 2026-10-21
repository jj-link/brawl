#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern const char lbl_118_data_620C[], lbl_118_data_17B0[];
extern const float lbl_118_rodata_30;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_118_F1E4(soModuleAccesser*);
void fn_118_C3EC(void*, const Vec2f*);
}

extern "C" void fn_118_EE58(void*, soModuleAccesser* accesser) {
    fn_118_F1E4(accesser);
    soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(3), 0,
        lbl_118_data_620C, lbl_118_data_17B0, 1));
    Vec2f limit(soValueAccesser::getConstantFloat(accesser, 0xfc1, 0), lbl_118_rodata_30);
    fn_118_C3EC(reinterpret_cast<unsigned char*>(energy) + 0x20, &limit);
    reinterpret_cast<unsigned char*>(energy)[5] |= 0x80;
}
