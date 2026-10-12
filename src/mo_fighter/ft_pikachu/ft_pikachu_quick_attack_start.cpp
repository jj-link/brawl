#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <math.h>

struct QuickAttackParameters {
    char prefix[0x30];
    float stickThreshold, speedMultiplier, speedAdd, repeatedSpeedMultiplier;
};
struct QuickAttackParameterView { char prefix[8]; QuickAttackParameters* parameters; };
struct QuickAttackEnergy {
    void* vtable;
    unsigned char nullable;
    unsigned char enabled : 1;
    unsigned char : 7;
    unsigned char suspended;
    unsigned char padding;
    Vec2f speed, acceleration, stableSpeed, brake, limitSpeed;
    inline void disable() { enabled = 0; }
};
extern "C" {
extern const float lbl_98_rodata_20[];
extern const char lbl_98_data_600[], lbl_98_data_2F88[];
extern const char lbl_98_data_7600[], lbl_98_data_7658[];
extern const char lbl_98_data_723C[], lbl_98_data_24B0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
QuickAttackParameterView* fn_98_9530(void*);
void fn_98_F034(Vec2f*, float, float);
float fn_98_F040(const Vec2f*);
float fn_98_F0B4(float, float);
void fn_98_F0D8(Vec2f*, float);
Vec2f* fn_98_C46C(Vec2f*, const Vec2f&);
float fn_8003DDD0(const Vec2f*, const Vec2f*);
void fn_8003DBA8(Vec2f*);
}

// Select the launch direction, respecting the touched ground and repeated dash.
extern "C" void fn_98_EB60(void*, soModuleAccesser* accesser) {
    const float* constants = lbl_98_rodata_20;
    const QuickAttackParameters* parameters = fn_98_9530(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_98_data_600, lbl_98_data_2F88, 1))->parameters;
    soKineticModule& kinetic = accesser->getKineticModule();
    soWorkManageModule& work = accesser->getWorkManageModule();
    bool useAngle = false;
    soControllerModule* controller = static_cast<soControllerModule*>(__dynamic_cast(
        &accesser->getControllerModule(), 0, lbl_98_data_7600, lbl_98_data_7658, 1));
    Vec2f stick;
    Vec2f speed;
    fn_98_F034(&stick, controller->getStickX(), controller->getStickY());
    float magnitude = fn_98_F040(&stick);
    if (magnitude > constants[1]) magnitude = constants[1];
    if (magnitude < parameters->stickThreshold) {
        useAngle = true;
    } else {
        soGroundModule& ground = accesser->getGroundModule();
        if (ground.isTouch(static_cast<grCollStatus::TouchMask>(8), 0)) {
            Vec2f normal = ground.getTouchNormal(static_cast<grCollStatus::TouchMask>(8), 0);
            if (fn_8003DDD0(&normal, &stick) < constants[2]) useAngle = true;
            if (ground.isPassableGround(0)) useAngle = true;
        } else {
            useAngle = true;
        }
    }
    if (useAngle) {
        work.setInt(soValueAccesser::getConstantInt(accesser, 0x59db, 0), 0x10000001);
        float length = fn_98_F040(&stick);
        if (length > constants[1]) length = constants[1];
        float angle;
        if (length > parameters->stickThreshold) {
            if (fabs(stick.m_x) > constants[3])
                accesser->getPostureModule().setStickLR(constants[0]);
            angle = fn_98_F0B4(stick.m_y, stick.m_x);
        } else {
            angle = constants[2];
        }
        speed.m_x = cos(angle);
        speed.m_y = sin(angle);
    } else {
        speed = stick;
        fn_8003DBA8(&speed);
    }
    if (speed.m_x >= constants[4])
        accesser->getPostureModule().setLr(constants[5]);
    else if (speed.m_x <= constants[6])
        accesser->getPostureModule().setLr(constants[7]);
    accesser->getPostureModule().updateRotYLr();
    work.setFloat(speed.m_x, 0x21000004);
    work.setFloat(speed.m_y, 0x21000005);
    magnitude *= parameters->speedMultiplier;
    magnitude += parameters->speedAdd;
    if (work.getInt(0x20000000) >= 1) magnitude *= parameters->repeatedSpeedMultiplier;
    fn_98_F0D8(&speed, magnitude);
    reinterpret_cast<QuickAttackEnergy*>(kinetic.getEnergy(0))->disable();
    reinterpret_cast<QuickAttackEnergy*>(kinetic.getEnergy(1))->disable();
    reinterpret_cast<QuickAttackEnergy*>(kinetic.getEnergy(3))->disable();
    QuickAttackEnergy* energy = static_cast<QuickAttackEnergy*>(__dynamic_cast(
        kinetic.getEnergy(2), 0, lbl_98_data_723C, lbl_98_data_24B0, 1));
    fn_98_C46C(&energy->speed, speed);
    fn_98_C46C(&energy->acceleration, Vec2f(constants[0], constants[0]));
    fn_98_C46C(&energy->stableSpeed, speed);
    fn_98_C46C(&energy->limitSpeed, speed);
    energy->enabled = 1;
    soMotionModule& motion = accesser->getMotionModule();
    soMotionChangeParam change;
    change.m_kind = 0x1db;
    change.m_frame = constants[8];
    change.m_rate = constants[0];
    change._12 = 0;
    change._13 = 0;
    change._14 = 0;
    change._15 = 0;
    motion.changeMotionRequest(&change);
}
