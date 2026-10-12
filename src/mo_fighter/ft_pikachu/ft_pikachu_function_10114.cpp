#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <ft/ft_owner.h>

struct PikachuEnergyState {
    void* vtable;
    unsigned char nullable;
    unsigned char enabled : 1;
    unsigned char : 7;
    unsigned char suspended;
    unsigned char padding;
    Vec2f speed;
    Vec2f acceleration;
};
struct PikachuGravityState {
    char prefix[0xc];
    float speed;
    float acceleration;
};
struct PikachuSummedSpeed { float x, y; };
// This entry's original ABI returns the POD pair in r3/r4.
class PikachuKineticSpeedView : public soNullable {
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
    virtual PikachuSummedSpeed getSumSpeed(const unsigned short&);
};
extern "C" {
extern const char lbl_98_data_600[], lbl_98_data_2F88[];
extern const char lbl_98_data_769C[], lbl_98_data_723C[], lbl_98_data_24B0[];
extern const float lbl_98_rodata_68;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_98_9530(void*);
Vec3f* fn_98_F5B0(Vec3f*, float, float, float);
Vec2f* fn_98_C46C(Vec2f*, const Vec2f&);
}
#pragma always_inline on
#pragma inline_depth(8)
extern "C" void fn_98_10114(void*, soModuleAccesser* accesser) {
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(accesser->m_stageObject,
        0x3c, lbl_98_data_600, lbl_98_data_2F88, 1));
    fn_98_9530(fighter);
    soKineticModule& kinetic = accesser->getKineticModule();
    unsigned short attributes = 1;
    Vec2f speed;
    PikachuSummedSpeed summed = reinterpret_cast<PikachuKineticSpeedView*>(&kinetic)->getSumSpeed(attributes);
    __memcpy(&speed, &summed, sizeof(speed));
    if (accesser->getSituationModule().getKind() == 2) {
        PikachuGravityState* gravity = static_cast<PikachuGravityState*>(__dynamic_cast(
            kinetic.getEnergy(1), 0, lbl_98_data_769C, lbl_98_data_24B0, 1));
        float gravityAcceleration = soValueAccesser::getConstantFloat(accesser, 0xfab, 0);
        gravity->speed = lbl_98_rodata_68;
        gravity->acceleration = -gravityAcceleration;
        reinterpret_cast<PikachuEnergyState*>(gravity)->enabled = 1;
        soKineticEnergy* stop = static_cast<soKineticEnergy*>(__dynamic_cast(
            kinetic.getEnergy(3), 0, lbl_98_data_723C, lbl_98_data_24B0, 1));
        float divisor = soValueAccesser::getConstantFloat(accesser, 0xfa9, 0);
        float acceleration = soValueAccesser::getConstantFloat(accesser, 0xfaa, 0);
        Vec2f horizontal(speed.m_x / divisor, lbl_98_rodata_68);
        Vec3f rotation;
        stop->resetEnergy(6, &horizontal, fn_98_F5B0(&rotation,
            lbl_98_rodata_68, lbl_98_rodata_68, lbl_98_rodata_68), accesser);
        fn_98_C46C(&reinterpret_cast<PikachuEnergyState*>(stop)->acceleration,
            Vec2f(acceleration, lbl_98_rodata_68));
        reinterpret_cast<PikachuEnergyState*>(stop)->enabled = 1;
    } else {
        reinterpret_cast<signed char*>(kinetic.getEnergy(1))[5] &= ~0x80;
        reinterpret_cast<signed char*>(kinetic.getEnergy(3))[5] &= ~0x80;
    }
    reinterpret_cast<signed char*>(kinetic.getEnergy(2))[5] &= ~0x80;
    reinterpret_cast<signed char*>(kinetic.getEnergy(0))[5] &= ~0x80;
    soControllerModule& controller = accesser->getControllerModule();
    int flickThreshold = soValueAccesser::getConstantFloat(accesser, 0xfa4, 0);
    if (controller.getFlickX() < flickThreshold) {
        soWorkManageModule& work = accesser->getWorkManageModule();
        int value = soValueAccesser::getConstantFloat(accesser, 0xfa5, 0);
        work.setInt(value, 0x20000000);
        work.onFlag(0x22000010);
        fighter->getOwner()->addLogInt(1, 0x19, 0);
    }
}
