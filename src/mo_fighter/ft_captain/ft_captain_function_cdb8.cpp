#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <math.h>

// Declaration-only view of the control energy fields used by this callback.
struct CaptainControlEnergyView : soKineticEnergy {
    Vec2f speed;
    Vec2f acceleration;
    char reserved[0x10];
    Vec2f stableSpeed;
    char reserved30[0xc];
    float accelerationMultiplier;
};

extern "C" {
extern const char lbl_100_data_6250[], lbl_100_data_6138[], lbl_100_data_16D4[];
extern const float lbl_100_rodata_18;
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec2f* fn_100_B818(Vec2f*, const Vec2f*);
}

static inline void setAcceleration(CaptainControlEnergyView* energy, const Vec2f& acceleration) {
    fn_100_B818(&energy->acceleration, &acceleration);
}

static inline float horizontalMagnitude(float speed) {
    return fabs(speed);
}

extern "C" void fn_100_CDB8(void*, soModuleAccesser* accesser) {
    if (accesser->getKineticModule().getKineticType() == 0x64) {
        CaptainControlEnergyView* control = static_cast<CaptainControlEnergyView*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(2), 0,
            lbl_100_data_6250, lbl_100_data_16D4, 1));
        Vec2f speed;
        Vec2f::copy(speed, accesser->getKineticModule().getSumSpeed(soKineticEnergy::AttributeFlag(1)));
        Vec2f stable;
        Vec2f::copy(stable, control->stableSpeed);
        Vec2f correction;
        if (static_cast<float>(fabs(speed.m_x)) > stable.m_x) {
            setAcceleration(control, Vec2f(lbl_100_rodata_18, lbl_100_rodata_18));
            control->updateEnergy(accesser);
        } else {
            float multiplier = soValueAccesser::getConstantFloat(accesser, 0xbd3, 0);
            float acceleration;
            if (accesser->getSituationModule().getKind() == 0)
                acceleration = multiplier * soValueAccesser::getConstantFloat(accesser, 0xfaa, 0);
            else
                acceleration = multiplier * soValueAccesser::getConstantFloat(accesser, 0xfab, 0);
            control->accelerationMultiplier = acceleration;
            control->updateEnergy(accesser);
        }
        speed = accesser->getKineticModule().getSumSpeed(soKineticEnergy::AttributeFlag(1));
        soKineticEnergy* stop = static_cast<soKineticEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(3), 0,
            lbl_100_data_6138, lbl_100_data_16D4, 1));
        correction.m_x = lbl_100_rodata_18;
        correction.m_y = lbl_100_rodata_18;
        if (horizontalMagnitude(speed.m_x) > stable.m_x) {
            correction.m_x = (speed.m_x > lbl_100_rodata_18 ? stable.m_x : -stable.m_x) - speed.m_x;
        }
        fn_100_B818(reinterpret_cast<Vec2f*>(reinterpret_cast<char*>(stop) + 8), &correction);
    }
}
