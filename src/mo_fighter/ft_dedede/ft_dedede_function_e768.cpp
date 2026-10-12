#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mo_fighter/ft_dedede/ft_dedede_speed.h>
#include <cmath>

extern "C" {
extern const float lbl_117_rodata_28[3] = {0.0f, -1.0f, 180.0f};
extern const char lbl_117_data_84DC[], lbl_117_data_83A8[], lbl_117_data_36A8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_117_92AC(Vec3f*, float, float, float);
}
struct DededeKineticEnable { unsigned char enabled : 1; };

static inline Vec3f* initializeRotation(const Vec3f& rotation, float x, float y, float z) {
    return fn_117_92AC(const_cast<Vec3f*>(&rotation), x, y, z);
}
static inline Vec3f setRotation(const Vec3f& source, const float* constants) {
    Vec3f rotation;
    float z = source.m_z;
    rotation.m_x = source.m_x;
    rotation.m_y = constants[2];
    rotation.m_z = z;
    return rotation;
}
static inline Vec3f* rotationAddress(const Vec3f& rotation) {
    return const_cast<Vec3f*>(&rotation);
}

extern "C" void fn_117_E768(void*, soModuleAccesser* accesser) {
    const float* constants = lbl_117_rodata_28;
    float stick = accesser->getControllerModule().getStickX();
    float horizontal = stick * soValueAccesser::getConstantFloat(accesser, 0xfb7, 0);
    float vertical = soValueAccesser::getConstantFloat(accesser, 0xfb8, 0);
    if (accesser->getSituationModule().getKind() == 2) {
        vertical *= soValueAccesser::getConstantFloat(accesser, 0xfba, 0);
    }
    stick = __fabsf(stick);
    vertical -= stick * soValueAccesser::getConstantFloat(accesser, 0xfb9, 0);
    soKineticEnergy* gravity = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(1), 0,
        lbl_117_data_84DC, lbl_117_data_36A8, 1));
    Vec2f gravitySpeed(constants[0], vertical);
    gravity->resetEnergy(0, &gravitySpeed, initializeRotation(Vec3f(),
        constants[0], constants[0], constants[0]), accesser);
    *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(gravity) + 0x10) =
        -soValueAccesser::getConstantFloat(accesser, 0xfbb, 0);
    reinterpret_cast<DededeKineticEnable*>(reinterpret_cast<unsigned char*>(gravity) + 5)->enabled = 1;
    soKineticEnergy* stop = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(3), 0,
        lbl_117_data_83A8, lbl_117_data_36A8, 1));
    Vec2f stopSpeed;
    stopSpeed.m_x = horizontal;
    stopSpeed.m_y = constants[0];
    stop->resetEnergy(0x16, &stopSpeed, initializeRotation(Vec3f(),
        constants[0], constants[0], constants[0]), accesser);
    Vec2f acceleration;
    acceleration.m_x = constants[0];
    acceleration.m_y = constants[0];
    fn_117_D134(reinterpret_cast<DededeSpeed*>(reinterpret_cast<unsigned char*>(stop) + 0x10), reinterpret_cast<const DededeSpeed*>(&acceleration));
    Vec2f brake;
    brake.m_x = horizontal;
    brake.m_y = constants[0];
    fn_117_D134(reinterpret_cast<DededeSpeed*>(reinterpret_cast<unsigned char*>(stop) + 0x18), reinterpret_cast<const DededeSpeed*>(&brake));
    Vec2f limit;
    limit.m_x = constants[0];
    limit.m_y = constants[0];
    fn_117_D134(reinterpret_cast<DededeSpeed*>(reinterpret_cast<unsigned char*>(stop) + 0x20), reinterpret_cast<const DededeSpeed*>(&limit));
    Vec2f stable;
    stable.m_x = horizontal;
    stable.m_y = constants[0];
    fn_117_D134(reinterpret_cast<DededeSpeed*>(reinterpret_cast<unsigned char*>(stop) + 0x28), reinterpret_cast<const DededeSpeed*>(&stable));
    reinterpret_cast<DededeKineticEnable*>(reinterpret_cast<unsigned char*>(stop) + 5)->enabled = 1;
    reinterpret_cast<signed char*>(accesser->getKineticModule().getEnergy(2))[5] &= ~0x80;
    accesser->getWorkManageModule().onFlag(0x22000011);
    if (accesser->getPostureModule().getLr() == constants[1]) {
        const Vec3f& rotation = accesser->m_enumerationStart->m_modelModule->getNodeRotate(7);
        accesser->m_enumerationStart->m_modelModule->setNodeRotate(7,
            rotationAddress(setRotation(rotation, constants)));
    }
    accesser->getWorkManageModule().offFlag(0x22000015);
}
