#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

// Local views of the two concrete energies used by Quick Attack's end state.
struct QuickAttackEnergy : soKineticEnergy {
    Vec2f speed;
    float acceleration;
    char reserved[12];
    Vec2f speedLimit;
    Vec2f brake;
};

struct QuickAttackSpeed { float m_x; float m_y; };
struct QuickAttackEnergyView : soNullable {
    virtual void updateEnergy(soModuleAccesser*);
    virtual QuickAttackSpeed getSpeed();
};
struct QuickAttackParameters {
    char reserved[0x30];
    float stickThreshold;
    char reserved34[0xc];
    float horizontalScale;
    char reserved44[8];
    int angleLimit;
};
struct QuickAttackParameterSlot { void* owner; void* reserved; QuickAttackParameters* parameters; };
extern "C" {
extern const char lbl_98_data_600[], lbl_98_data_2F88[], lbl_98_data_769C[], lbl_98_data_24B0[];
extern const char lbl_98_data_7408[], lbl_98_data_7600[], lbl_98_data_7658[];
extern const float lbl_98_rodata_20[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
QuickAttackParameterSlot* fn_98_9530(void*);
Vec2f* fn_98_C46C(Vec2f*, const Vec2f*);
Vec2f* fn_98_F034(Vec2f*, float, float);
float fn_98_F040(const Vec2f*);
float fn_8003DDD0(const Vec2f*, const Vec2f*);
}

inline bool canRestartQuickAttack(soModuleAccesser* accesser, const float* constants) {
    QuickAttackParameters* parameters = fn_98_9530(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_98_data_600, lbl_98_data_2F88, 1))->parameters;
    soWorkManageModule& work = accesser->getWorkManageModule();
    if (work.getInt(0x20000000) < 2) {
        soControllerModule* controller = static_cast<soControllerModule*>(__dynamic_cast(
            &accesser->getControllerModule(), 0, lbl_98_data_7600, lbl_98_data_7658, 1));
        float y = controller->getStickY();
        float x = controller->getStickX();
        Vec2f stick;
        fn_98_F034(&stick, x, y);
        if (fn_98_F040(&stick) >= parameters->stickThreshold) {
            float oldX = work.getFloat(0x21000004);
            float oldY = work.getFloat(0x21000005);
            Vec2f previousStick(oldX, oldY);
            if (fn_8003DDD0(&previousStick, &stick) > constants[12] * parameters->angleLimit)
                return true;
        }
    }
    return false;
}

inline float dampQuickAttackSpeed(double speed, const float* constants) {
    float y = static_cast<float>(speed);
    y -= y / constants[16];
    return y;
}

extern "C" void fn_98_FA14(void*, soModuleAccesser* accesser) {
    Vec2f speed;
    const float* constants = lbl_98_rodata_20;
    QuickAttackParameters* parameters = fn_98_9530(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_98_data_600, lbl_98_data_2F88, 1))->parameters;
    int previous = accesser->getWorkManageModule().getInt(0x20000004);
    int next = previous;
    if (accesser->getSituationModule().getKind() == 0) {
        if (previous != 0) {
            next = 2;
            accesser->getKineticModule().changeKinetic(6, accesser);
        }
    } else if (previous <= 0) {
        soKineticModule& kinetic = accesser->getKineticModule();
        QuickAttackEnergy* gravity = static_cast<QuickAttackEnergy*>(__dynamic_cast(
            kinetic.getEnergy(1), 0, lbl_98_data_769C, lbl_98_data_24B0, 1));
        QuickAttackSpeed currentSpeed = reinterpret_cast<QuickAttackEnergyView*>(gravity)->getSpeed();
        speed.m_x = currentSpeed.m_x;
        speed.m_y = dampQuickAttackSpeed(currentSpeed.m_y, constants);
        gravity->acceleration = constants[0];
        gravity->speed.m_y = speed.m_y;
        reinterpret_cast<unsigned char*>(gravity)[5] |= 0x80;
        QuickAttackEnergy* control = static_cast<QuickAttackEnergy*>(__dynamic_cast(
            kinetic.getEnergy(2), 0, lbl_98_data_7408, lbl_98_data_24B0, 1));
        float limit = soValueAccesser::getConstantFloat(accesser, 0xbd6, 0);
        Vec2f limits(limit, limit);
        fn_98_C46C(&control->speedLimit, &limits);
        reinterpret_cast<unsigned char*>(control)[5] |= 0x80;
    } else {
        if (previous == 1) {
            if (canRestartQuickAttack(accesser, constants)) {
                accesser->getStatusModule().changeStatusRequest(0x117, accesser);
                return;
            }
            next = 2;
        }
        soKineticModule& kinetic = accesser->getKineticModule();
        QuickAttackEnergy* gravity = static_cast<QuickAttackEnergy*>(__dynamic_cast(
            kinetic.getEnergy(1), 0, lbl_98_data_769C, lbl_98_data_24B0, 1));
        gravity->acceleration = -soValueAccesser::getConstantFloat(accesser, 0xbcf, 0);
        reinterpret_cast<unsigned char*>(gravity)[5] |= 0x80;
        QuickAttackEnergy* control = static_cast<QuickAttackEnergy*>(__dynamic_cast(
            kinetic.getEnergy(2), 0, lbl_98_data_7408, lbl_98_data_24B0, 1));
        float brake = soValueAccesser::getConstantFloat(accesser, 0xbd5, 0);
        Vec2f brakes;
        brakes.m_x = brake * parameters->horizontalScale;
        brakes.m_y = constants[0];
        fn_98_C46C(&control->brake, &brakes);
        reinterpret_cast<unsigned char*>(control)[5] |= 0x80;
    }
    if (next != previous) accesser->getWorkManageModule().setInt(next, 0x20000004);
}
