#include <so/work/so_work_manage_module_impl.h>

struct PikachuChargeModules {
    char prefix[0x64];
    soWorkManageModule* work;
};
struct PikachuChargeAccesser {
    char prefix[0xd8];
    PikachuChargeModules* modules;
};
extern "C" {
extern const float lbl_98_rodata_68, lbl_98_rodata_6C;
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
}

#pragma always_inline on
#pragma inline_depth(8)
extern "C" void fn_98_10510(void*, soModuleAccesser* accesser) {
    float lower, upper, difference, ratio;
    soWorkManageModule& work = *reinterpret_cast<PikachuChargeAccesser*>(accesser)->modules->work;
    int maximumCharge = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfa6, 0);
    int charge = work.getInt(0x20000000);
    int maximumDuration = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0x5dc1, 0);
    ratio = float(charge) / float(maximumCharge);
    upper = lbl_98_rodata_6C;
    lower = lbl_98_rodata_68;
    difference = ratio - lower;
    if (difference >= 0.0f) {
        lower = ratio;
    }
    difference = lower - upper;
    ratio = difference >= 0.0f ? upper : lower;
    work.setFloat(ratio, 0x21000004);
    int duration = int(float(maximumDuration) * ratio);
    work.setInt(duration, 0x20000001);
}
#include <so/posture/so_posture_module_simple.h>

// Only the energy-reset ABI is needed here; the attribute and speed-return
// interfaces used by other kinetic callbacks are deliberately not imported.
class PikachuResetEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual Vec2f getSpeed();
    virtual Vec3f getSpeed3f();
    virtual Vec3f getRotation();
    virtual void resetEnergy(int, Vec2f*, Vec3f*, soModuleAccesser*);
};
class PikachuResetKineticView : public soNullable {
public:
    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy();
    virtual void eraseEnergy(int);
    virtual void eraseEnergyAll();
    virtual PikachuResetEnergyView* getEnergy(int);
};
struct PikachuEnergyEnableView {
    void* vtable;
    unsigned char nullable;
    unsigned char enabled : 1;
    unsigned char : 7;
};
struct PikachuResetModules {
    char prefix[0xc];
    soPostureModule* posture;
    char beforeWork[0x54];
    soWorkManageModule* work;
    char beforeKinetic[0x14];
    PikachuResetKineticView* kinetic;
};
struct PikachuResetAccesser {
    char prefix[0xd8];
    PikachuResetModules* modules;
};
extern "C" {
extern const float lbl_98_rodata_68, lbl_98_rodata_78;
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
Vec3f* fn_98_F5B0(Vec3f*, float, float, float);
}
#pragma always_inline on
#pragma inline_depth(8)
extern "C" void fn_98_10660(void*, soModuleAccesser* accesser) {
    PikachuResetAccesser* view = reinterpret_cast<PikachuResetAccesser*>(accesser);
    PikachuResetKineticView& kinetic = *view->modules->kinetic;
    soWorkManageModule& work = *view->modules->work;
    float charge = work.getInt(0x20000000);
    work.getFloat(0x21000004);
    float baseSpeed = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfac, 0);
    float chargeSpeed = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfad, 0);
    PikachuResetEnergyView* stop = kinetic.getEnergy(3);
    baseSpeed += chargeSpeed * charge;
    baseSpeed *= view->modules->posture->getLr();
    Vec2f horizontal(baseSpeed, lbl_98_rodata_68);
    Vec3f horizontalRotation;
    stop->resetEnergy(0x16, &horizontal, fn_98_F5B0(&horizontalRotation,
        lbl_98_rodata_68, lbl_98_rodata_68, lbl_98_rodata_68), accesser);
    reinterpret_cast<PikachuEnergyEnableView*>(stop)->enabled = 1;
    PikachuResetEnergyView* gravity = kinetic.getEnergy(1);
    float verticalSpeed = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfae, 0);
    float chargeMaximum = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfa6, 0);
    float upwardSpeed = lbl_98_rodata_78 * verticalSpeed
        + verticalSpeed * (lbl_98_rodata_78 * charge / chargeMaximum);
    Vec2f vertical(lbl_98_rodata_68, upwardSpeed);
    Vec3f verticalRotation;
    gravity->resetEnergy(0, &vertical, fn_98_F5B0(&verticalRotation,
        lbl_98_rodata_68, lbl_98_rodata_68, lbl_98_rodata_68), accesser);
    reinterpret_cast<PikachuEnergyEnableView*>(gravity)->enabled = 1;
    reinterpret_cast<signed char*>(kinetic.getEnergy(2))[5] &= ~0x80;
    reinterpret_cast<signed char*>(kinetic.getEnergy(0))[5] &= ~0x80;
}

#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

extern "C" {
extern unsigned char lbl_98_data_769C[], lbl_98_data_723C[], lbl_98_data_24B0[];
extern const float lbl_98_rodata_68;
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec2f* fn_98_C46C(Vec2f*, const Vec2f*);
}

#pragma always_inline on
#pragma inline_depth(8)
extern "C" void fn_98_108C8(void*, soModuleAccesser* accesser) {
    soWorkManageModule& work = accesser->getWorkManageModule();
    soKineticModule& kinetic = accesser->getKineticModule();
    soKineticEnergy* gravity = static_cast<soKineticEnergy*>(__dynamic_cast(
        kinetic.getEnergy(1), 0, lbl_98_data_769C, lbl_98_data_24B0, 1));
    soKineticEnergy* stop = static_cast<soKineticEnergy*>(__dynamic_cast(
        kinetic.getEnergy(3), 0, lbl_98_data_723C, lbl_98_data_24B0, 1));
    if (work.isFlag(0x22000012)) {
        float acceleration = soValueAccesser::getConstantFloat(accesser, 0xfb3, 0);
        float terminalSpeed = soValueAccesser::getConstantFloat(accesser, 0xfb0, 0);
        *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(gravity) + 0x10) = -acceleration;
        *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(gravity) + 0x1c) = terminalSpeed;
        Vec2f braking(-soValueAccesser::getConstantFloat(accesser, 0xfb2, 0), lbl_98_rodata_68);
        fn_98_C46C(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(stop) + 0x10), &braking);
    } else {
        float acceleration = soValueAccesser::getConstantFloat(accesser, 0xfaf, 0);
        float terminalSpeed = soValueAccesser::getConstantFloat(accesser, 0xfb0, 0);
        *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(gravity) + 0x10) = -acceleration;
        *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(gravity) + 0x1c) = terminalSpeed;
    }
    soCollisionAttackModule& attack = accesser->getCollisionAttackModule();
    soWorkManageModule& currentWork = accesser->getWorkManageModule();
    if (!currentWork.isFlag(0x22000013)) {
        float base = soValueAccesser::getConstantFloat(accesser, 0xfa7, 0);
        float charge = currentWork.getInt(0x20000000);
        float perCharge = soValueAccesser::getConstantFloat(accesser, 0xfa8, 0);
        float powerMultiplier = (base + charge * perCharge) / base;
        attack.setPowerMulStatus(powerMultiplier);
        currentWork.onFlag(0x22000013);
    }
}
