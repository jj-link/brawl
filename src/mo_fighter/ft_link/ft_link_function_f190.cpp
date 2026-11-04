#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
void fn_27_15FBC8(int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_93_data_3018[], lbl_93_data_30FC[];
extern const float lbl_93_rodata_30;
}

extern "C" void fn_93_F190(void*, int, const void*, soModuleAccesser* accesser) {
    fn_27_15FBC8(0x11);
    soKineticModule& kinetic = accesser->getKineticModule();
    void* energyObject = kinetic.getEnergy(1);
    soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(
        energyObject, 0, lbl_93_data_3018, lbl_93_data_30FC, 1));
    Vec3f rotation(lbl_93_rodata_30, lbl_93_rodata_30, lbl_93_rodata_30);
    Vec2f speed(lbl_93_rodata_30, lbl_93_rodata_30);
    energy->resetEnergy(1, &speed, &rotation, accesser);
    float v = soValueAccesser::getConstantFloat(accesser, 0xfaf, 0);
    reinterpret_cast<float*>(energy)[3] = v;
    reinterpret_cast<float*>(energy)[4] = lbl_93_rodata_30;
    reinterpret_cast<unsigned char*>(energy)[5] |= 0x80;
}