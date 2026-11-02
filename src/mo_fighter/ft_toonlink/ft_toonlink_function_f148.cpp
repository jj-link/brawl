#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
void fn_27_15FBC8(int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_121_data_3110[], lbl_121_data_31F4[];
extern const float lbl_121_rodata_30;
}

extern "C" void fn_121_F148(void*, int, const void*, soModuleAccesser* accesser) {
    fn_27_15FBC8(0x11);
    soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(1), 0,
        lbl_121_data_3110, lbl_121_data_31F4, 1));
    Vec3f rotation(lbl_121_rodata_30, lbl_121_rodata_30, lbl_121_rodata_30);
    Vec2f speed(lbl_121_rodata_30, lbl_121_rodata_30);
    energy->resetEnergy(1, &speed, &rotation, accesser);
    float v = soValueAccesser::getConstantFloat(accesser, 0xfaf, 0);
    reinterpret_cast<float*>(energy)[3] = v;
    reinterpret_cast<float*>(energy)[4] = lbl_121_rodata_30;
    reinterpret_cast<unsigned char*>(energy)[5] |= 0x80;
}
