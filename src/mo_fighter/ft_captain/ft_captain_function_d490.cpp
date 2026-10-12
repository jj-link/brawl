#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/situation/so_situation_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>

// Only the inherited energy interface is used here. The shared gravity RTTI
// is bound by the build; this translation unit does not construct the class.
class ftKineticEnergyGravity : public soKineticEnergy {};

extern "C" {
extern const float lbl_100_rodata_20;
Vec3f* fn_100_CC84(Vec3f*, float, float, float);
}

namespace {
inline Vec2f* temporaryVector(const Vec2f& vector) {
    return const_cast<Vec2f*>(&vector);
}
}

extern "C" void fn_100_D490(void*, soModuleAccesser* accesser) {
    int situation = accesser->getSituationModule().getKind();
    soKineticModule* kinetic = &accesser->getKineticModule();
    int previousSituation = accesser->getWorkManageModule().getInt(0x20000000);
    if (previousSituation == 0 && situation == 0) {
        Vec2f speed;
        Vec2f::copy(speed, kinetic->getSumSpeed(soKineticEnergy::AttributeFlag(1)));
        soKineticEnergy* motion = kinetic->getEnergy(3);
        Vec3f rotation;
        motion->resetEnergy(0, temporaryVector(Vec2f(speed.m_x, lbl_100_rodata_20)),
            fn_100_CC84(&rotation, lbl_100_rodata_20, lbl_100_rodata_20, lbl_100_rodata_20), accesser);
    } else if (previousSituation == 2 && situation == 2) {
        Vec2f speed;
        Vec2f::copy(speed, kinetic->getSumSpeed(soKineticEnergy::AttributeFlag(1)));
        kinetic->unableEnergyAll();
        soKineticEnergy* gravity = &dynamic_cast<ftKineticEnergyGravity&>(*kinetic->getEnergy(1));
        soKineticEnergy* motion = kinetic->getEnergy(3);
        Vec3f gravityRotation;
        gravity->resetEnergy(0, temporaryVector(Vec2f(lbl_100_rodata_20, speed.m_y)),
            fn_100_CC84(&gravityRotation, lbl_100_rodata_20, lbl_100_rodata_20, lbl_100_rodata_20), accesser);
        Vec3f motionRotation;
        motion->resetEnergy(9, temporaryVector(Vec2f(speed.m_x, lbl_100_rodata_20)),
            fn_100_CC84(&motionRotation, lbl_100_rodata_20, lbl_100_rodata_20, lbl_100_rodata_20), accesser);
        // soEnable occupies byte 5 of soKineticEnergy; its high bit enables the energy.
        reinterpret_cast<unsigned char*>(gravity)[5] |= 0x80;
        reinterpret_cast<unsigned char*>(motion)[5] |= 0x80;
    }
}
