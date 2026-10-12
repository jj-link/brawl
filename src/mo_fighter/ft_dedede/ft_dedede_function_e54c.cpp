#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

extern "C" {
extern const float lbl_117_rodata_18[];
extern const char lbl_117_data_8498[], lbl_117_data_36A8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
namespace {
struct DededeMotionSpeed { float x, y; };
inline void assignSpeed(DededeMotionSpeed* destination, const Vec2f& speed) {
    destination->x = speed.m_x;
    destination->y = speed.m_y;
}
}
extern "C" void fn_117_E54C(void*, soModuleAccesser* accesser) {
    float facing = accesser->getControllerModule().getStickX();
    soKineticEnergy* motion = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(2), 0,
        lbl_117_data_8498, lbl_117_data_36A8, 1));
    Vec2f speed;
    speed.m_x = facing * soValueAccesser::getConstantFloat(accesser, 0xfb4, 0);
    speed.m_y = lbl_117_rodata_18[0];
    assignSpeed(reinterpret_cast<DededeMotionSpeed*>(reinterpret_cast<unsigned char*>(motion) + 8), speed);
    if (accesser->getSituationModule().getKind() == 2) {
        reinterpret_cast<unsigned char*>(accesser->getKineticModule().getEnergy(1))[5] |= 0x80;
    } else {
        reinterpret_cast<signed char*>(accesser->getKineticModule().getEnergy(1))[5] &= ~0x80;
    }
}
