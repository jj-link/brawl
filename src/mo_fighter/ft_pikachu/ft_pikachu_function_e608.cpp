#include <so/so_module_accesser.h>

extern "C" {
extern const char lbl_98_data_7408[], lbl_98_data_24B0[];
extern const float lbl_98_rodata_10;
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec2f* fn_98_C46C(Vec2f*, const Vec2f&);
}

struct PikachuMotionEnergyView {
    void* vtable;
    unsigned char nullable;
    unsigned char enabled : 1;
    unsigned char : 7;
    unsigned char suspended;
    unsigned char padding;
    Vec2f speed;
    Vec2f acceleration;
};

#pragma always_inline on
#pragma inline_depth(8)
extern "C" void fn_98_E608(void*, int, soModuleAccesser* accesser) {
    soKineticModule& kinetic = accesser->getKineticModule();
    kinetic.unableEnergyAll();
    kinetic.clearSpeedAll();
    soKineticEnergy* motion = static_cast<soKineticEnergy*>(__dynamic_cast(
        kinetic.getEnergy(2), 0, lbl_98_data_7408, lbl_98_data_24B0, 1));
    Vec3f rotation(lbl_98_rodata_10, lbl_98_rodata_10, lbl_98_rodata_10);
    Vec2f speed(lbl_98_rodata_10, lbl_98_rodata_10);
    motion->resetEnergy(0xb, &speed, &rotation, accesser);
    fn_98_C46C(&reinterpret_cast<PikachuMotionEnergyView*>(motion)->acceleration,
        Vec2f(lbl_98_rodata_10, lbl_98_rodata_10));
    reinterpret_cast<PikachuMotionEnergyView*>(motion)->enabled = 1;
}
