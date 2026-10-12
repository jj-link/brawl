#include <so/so_module_accesser.h>

extern "C" {
extern const char lbl_98_data_769C[], lbl_98_data_24B0[];
extern const float lbl_98_rodata_68;
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

#pragma always_inline on
#pragma inline_depth(8)
extern "C" void fn_98_10B10(soModuleAccesser* accesser) {
    soKineticModule& kinetic = accesser->getKineticModule();
    soKineticEnergy* stop = kinetic.getEnergy(3);
    soKineticEnergy* gravity = static_cast<soKineticEnergy*>(__dynamic_cast(
        kinetic.getEnergy(1), 0, lbl_98_data_769C, lbl_98_data_24B0, 1));
    Vec2f speed = kinetic.getSumSpeed(static_cast<soKineticEnergy::AttributeFlag>(1));
    reinterpret_cast<signed char*>(stop)[5] &= ~0x80;
    if (speed.m_y > lbl_98_rodata_68) {
        *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(gravity) + 0xc) = lbl_98_rodata_68;
    }
    accesser->getWorkManageModule().onFlag(0x22000014);
}
