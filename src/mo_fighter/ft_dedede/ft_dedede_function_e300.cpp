#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

namespace {
struct DededeSummedSpeed { float x, y; };
// The original slot returns two words in r3/r4 and takes an attribute reference.
class DededeKineticSpeedView : public soNullable {
public:
    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy(soKineticEnergy*, int, soKineticEnergy::AttributeFlag, short);
    virtual void eraseEnergy(int);
    virtual void eraseEnergyAll();
    virtual soKineticEnergy* getEnergy(int);
    virtual bool isContain(int);
    virtual void updateEnergy(soModuleAccesser*, soKineticEnergy::AttributeFlag);
    virtual void clearSpeedAll();
    virtual void suspendEnergyAll();
    virtual void resumeEnergyAll();
    virtual void unableEnergyAll();
    virtual DededeSummedSpeed getSumSpeed(const unsigned short&);
};
struct DededeEnergyEnable { unsigned char enabled : 1; };
}

extern "C" {
extern const float lbl_117_rodata_18[4] = {0.0f, 1.0f, -1.0f, 0.0f};
extern const char lbl_117_data_8498[], lbl_117_data_84DC[], lbl_117_data_36A8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_117_92AC(Vec3f*, float, float, float);
}

static inline Vec3f* initializeRotation(const Vec3f& rotation, float x, float y, float z) {
    return fn_117_92AC(const_cast<Vec3f*>(&rotation), x, y, z);
}

extern "C" void fn_117_E300(void*, soModuleAccesser* accesser) {
    const float* constants = lbl_117_rodata_18;
    soKineticEnergy* motion = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(2), 0,
        lbl_117_data_8498, lbl_117_data_36A8, 1));
    int resetType = 0xb;
    unsigned short attributes = 1;
    Vec2f speed;
    DededeSummedSpeed summed = reinterpret_cast<DededeKineticSpeedView*>(
        &accesser->getKineticModule())->getSumSpeed(attributes);
    __memcpy(&speed, &summed, sizeof(speed));
    if (speed.m_x > soValueAccesser::getConstantFloat(accesser, 0xfb4, 0)) {
        speed.m_x = soValueAccesser::getConstantFloat(accesser, 0xfb4, 0);
    }
    Vec2f horizontal;
    horizontal.m_x = speed.m_x;
    horizontal.m_y = constants[0];
    motion->resetEnergy(resetType, &horizontal, initializeRotation(Vec3f(),
        constants[0], constants[0], constants[0]), accesser);
    *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(motion) + 0x3c) = constants[1];
    *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(motion) + 0x40) = constants[0];
    reinterpret_cast<DededeEnergyEnable*>(reinterpret_cast<unsigned char*>(motion) + 5)->enabled = 1;
    soKineticEnergy* gravity = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(1), 0,
        lbl_117_data_84DC, lbl_117_data_36A8, 1));
    float vertical = constants[2] * soValueAccesser::getConstantFloat(accesser, 0xfb5, 0);
    float acceleration = constants[2] * soValueAccesser::getConstantFloat(accesser, 0xfb6, 0);
    Vec2f gravitySpeed(constants[0], vertical);
    gravity->resetEnergy(0, &gravitySpeed, initializeRotation(Vec3f(),
        constants[0], constants[0], constants[0]), accesser);
    *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(gravity) + 0x10) = acceleration;
    if (accesser->getSituationModule().getKind() == 2) {
        reinterpret_cast<DededeEnergyEnable*>(reinterpret_cast<unsigned char*>(gravity) + 5)->enabled = 1;
    } else {
        reinterpret_cast<DededeEnergyEnable*>(reinterpret_cast<unsigned char*>(gravity) + 5)->enabled = 0;
    }
}
