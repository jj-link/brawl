#include <so/work/so_work_manage_module_impl.h>
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
