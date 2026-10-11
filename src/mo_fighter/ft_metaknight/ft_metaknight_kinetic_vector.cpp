#include <so/kinetic/so_kinetic_energy.h>
#include <types.h>

extern "C" const float lbl_111_rodata_8;

extern "C" Vec3f fn_111_876C(soKineticEnergy* energy) {
    Vec3f speed;
    *speed.xy() = energy->getSpeed();
    speed.m_z = lbl_111_rodata_8;
    return speed;
}

extern "C" void* fn_111_87CC(const void* object) {
    return *reinterpret_cast<void* const*>(static_cast<const u8*>(object) + 0x20);
}
