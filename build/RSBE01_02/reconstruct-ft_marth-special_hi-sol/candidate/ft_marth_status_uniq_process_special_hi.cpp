#include "marth-hi-abi.h"

// These concrete fighter energies and their RTTI remain owned by the original
// module. Only the fields accessed by this status process are described here.
struct MarthGravityEnergy : soKineticEnergy {
    u8 unknown08[8];
    float acceleration;
    float terminalSpeed;
};

struct MarthMotionEnergy : soKineticEnergy {
    u8 unknown08[0x34];
    float rotationSpeed;
    float rotationAcceleration;
};

extern "C" {
extern const u8 lbl_106_data_534C[]; // ftKineticEnergyStop
extern const u8 lbl_106_data_5390[]; // soKineticEnergyNormal
extern const u8 lbl_106_data_544C[]; // ftKineticEnergyGravity
extern const u8 lbl_106_data_5530[]; // ftKineticEnergyController
extern const u8 lbl_106_data_557C[]; // ftKineticEnergyMotion
extern const u8 lbl_106_data_EB4[]; // soKineticEnergy
void* __dynamic_cast(const void*, int, const void*, const void*, short);
// The original module's out-of-line Vec3f constructor returns its receiver.
Vec3f* fn_106_77F4(Vec3f*, float, float, float);
void fn_27_89DAC(int energyIndex, soModuleAccesser* moduleAccesser);
void fn_27_15CF90(soKineticEnergy*, float);
void fn_27_15CF5C(soKineticEnergy*, float);
float fn_106_BE30(float value);
}

static inline soKineticEnergy* castEnergy(soKineticEnergy* energy, const void* type) {
    return static_cast<soKineticEnergy*>(__dynamic_cast(energy, 0, type, lbl_106_data_EB4, 1));
}

static inline void enableEnergy(soKineticEnergy* energy) {
    reinterpret_cast<u8*>(energy)[5] |= 0x80;
}

static inline void disableEnergy(soKineticEnergy* energy) {
    energy->disable();
}


// This vtable slot returns the two speed words directly, without Vec2f's
// owning wrapper, and receives the attribute mask by address.
struct MarthHiSpeed { float m_x, m_y; };
class MarthHiKineticModule : public soNullable {
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
    virtual MarthHiSpeed getSumSpeed(const unsigned short&);
};
class ftMarthStatusUniqProcessSpecialHi : public soStatusUniqProcess {
public:
    ftMarthStatusUniqProcessSpecialHi();
    virtual ~ftMarthStatusUniqProcessSpecialHi();
    virtual void initStatus(soModuleAccesser* moduleAccesser);
    virtual void exitStatus(soModuleAccesser* moduleAccesser, int);
    virtual void execStatus(soModuleAccesser* moduleAccesser);
    virtual void execStop(soModuleAccesser* moduleAccesser);
    virtual void execFixPos(soModuleAccesser* moduleAccesser);
    virtual bool onChangeLr(soModuleAccesser* moduleAccesser, float, float);
};

void ftMarthStatusUniqProcessSpecialHi::initStatus(soModuleAccesser* moduleAccesser) {
    soKineticEnergy* stop = castEnergy(moduleAccesser->getKineticModule().getEnergy(3), lbl_106_data_534C);
    soKineticEnergy* gravity = castEnergy(moduleAccesser->getKineticModule().getEnergy(1), lbl_106_data_544C);
    unsigned short attributes = 1;
    Vec2f sumSpeed;
    MarthHiSpeed sum = reinterpret_cast<MarthHiKineticModule*>(
        &moduleAccesser->getKineticModule())->getSumSpeed(attributes);
    __memcpy(&sumSpeed.m_x, &sum.m_x, sizeof(float));
    __memcpy(&sumSpeed.m_y, &sum.m_y, sizeof(float));
    float speedX = sumSpeed.m_x;
    if (moduleAccesser->getSituationModule().getKind() == 2) {
        speedX *= soValueAccesser::getConstantFloat(moduleAccesser, 0xFAC, 0);
        float zero = 0.0f;
        {
            Vec2f speed(speedX, zero);
            Vec3f rotation;
            stop->resetEnergy(6, &speed, fn_106_77F4(&rotation, zero, zero, zero), moduleAccesser);
        }
        enableEnergy(stop);
        {
            Vec2f speed(0.0f, zero);
            Vec3f rotation;
            gravity->resetEnergy(0, &speed, fn_106_77F4(&rotation, 0.0f, 0.0f, 0.0f), moduleAccesser);
        }
        enableEnergy(gravity);
        soKineticEnergy* normal = castEnergy(moduleAccesser->getKineticModule().getEnergy(0), lbl_106_data_5390);
        {
            Vec2f speed(0.0f, 0.0f);
            Vec3f rotation;
            normal->resetEnergy(5, &speed, fn_106_77F4(&rotation, 0.0f, 0.0f, 0.0f), moduleAccesser);
        }
        enableEnergy(normal);
        fn_27_89DAC(2, moduleAccesser);
    } else {
        soKineticEnergy* normal = castEnergy(moduleAccesser->getKineticModule().getEnergy(0), lbl_106_data_5390);
        Vec2f speed(0.0f, 0.0f);
        Vec3f rotation;
        normal->resetEnergy(3, &speed, fn_106_77F4(&rotation, 0.0f, 0.0f, 0.0f), moduleAccesser);
        enableEnergy(normal);
        fn_27_89DAC(3, moduleAccesser);
        fn_27_89DAC(1, moduleAccesser);
        fn_27_89DAC(2, moduleAccesser);
    }
}

void ftMarthStatusUniqProcessSpecialHi::execStatus(soModuleAccesser* moduleAccesser) {
    MarthMotionEnergy* motion = static_cast<MarthMotionEnergy*>(castEnergy(moduleAccesser->getKineticModule().getEnergy(0), lbl_106_data_557C));
    float stickMagnitude = fn_106_BE30(moduleAccesser->getControllerModule().getStickX());
    if (!moduleAccesser->getWorkManageModule().isFlag(0x22000016)) {
        float threshold = soValueAccesser::getConstantFloat(moduleAccesser, 0xFAA, 0);
        if (stickMagnitude > threshold) {
            float angle = static_cast<float>(stickMagnitude - threshold) / (1.0f - threshold);
            angle *= soValueAccesser::getConstantFloat(moduleAccesser, 0xFAB, 0);
            if (moduleAccesser->getControllerModule().getStickX() > 0.0f) {
                angle = -(0.017453292f * angle);
            } else {
                angle = 0.017453292f * angle;
            }
            float previousAngle = moduleAccesser->getWorkManageModule().getFloat(0x21000004);
            float previousMagnitude = fn_106_BE30(previousAngle);
            if (fn_106_BE30(angle) > previousMagnitude) {
                previousAngle = angle;
            }
            moduleAccesser->getWorkManageModule().setFloat(previousAngle, 0x21000004);
        }
    }
    unsigned short attributes = 1;
    Vec2f sumSpeed;
    MarthHiSpeed sum = reinterpret_cast<MarthHiKineticModule*>(
        &moduleAccesser->getKineticModule())->getSumSpeed(attributes);
    __memcpy(&sumSpeed.m_x, &sum.m_x, sizeof(float));
    __memcpy(&sumSpeed.m_y, &sum.m_y, sizeof(float));
    if (moduleAccesser->getWorkManageModule().isFlag(0x22000010)) {
        if (!moduleAccesser->getWorkManageModule().isFlag(0x22000013)) {
            if (moduleAccesser->getMotionModule().getKind() == 0x1E9) {
                motion->rotationAcceleration = soValueAccesser::getConstantFloat(moduleAccesser, 0xFAD, 0);
            }
            if (moduleAccesser->getWorkManageModule().isFlag(0x22000014) && sumSpeed.m_y < 0.0f) {
                moduleAccesser->getWorkManageModule().onFlag(0x22000013);
            }
        } else {
            if (!moduleAccesser->getKineticModule().getEnergy(1)->isEnable()) {
                MarthGravityEnergy* gravity = static_cast<MarthGravityEnergy*>(castEnergy(moduleAccesser->getKineticModule().getEnergy(1), lbl_106_data_544C));
                Vec2f speed(0.0f, sumSpeed.m_y);
                Vec3f rotation;
                gravity->resetEnergy(0, &speed, fn_106_77F4(&rotation, 0.0f, 0.0f, 0.0f), moduleAccesser);
                gravity->acceleration = -soValueAccesser::getConstantFloat(moduleAccesser, 0xFAE, 0);
                gravity->terminalSpeed = soValueAccesser::getConstantFloat(moduleAccesser, 0xFAF, 0);
                enableEnergy(gravity);
            }
            if (!moduleAccesser->getKineticModule().getEnergy(2)->isEnable()) {
                soKineticEnergy* controller = castEnergy(moduleAccesser->getKineticModule().getEnergy(2), lbl_106_data_5530);
                int resetType = 11;
                Vec2f speed(sumSpeed.m_x, 0.0f);
                Vec3f rotation;
                controller->resetEnergy(resetType, &speed, fn_106_77F4(&rotation, 0.0f, 0.0f, 0.0f), moduleAccesser);
                fn_27_15CF90(controller, soValueAccesser::getConstantFloat(moduleAccesser, 0xFA7, 0));
                fn_27_15CF5C(controller, soValueAccesser::getConstantFloat(moduleAccesser, 0xFA7, 0));
                enableEnergy(controller);
            }
            disableEnergy(motion);
        }
        moduleAccesser->getWorkManageModule().onFlag(0x22000014);
    }
    if (moduleAccesser->getWorkManageModule().isFlag(0x22000015)) {
        motion->rotationSpeed = moduleAccesser->getWorkManageModule().getFloat(0x21000004);
        moduleAccesser->getWorkManageModule().offFlag(0x22000015);
    }
}

extern "C" float fn_106_BE30(float value) {
    return __fabsf(value);
}

void ftMarthStatusUniqProcessSpecialHi::execStop(soModuleAccesser*) {}
void ftMarthStatusUniqProcessSpecialHi::execFixPos(soModuleAccesser*) {}

void ftMarthStatusUniqProcessSpecialHi::exitStatus(soModuleAccesser* moduleAccesser, int) {
    float speed = soValueAccesser::getConstantFloat(moduleAccesser, 0xFA8, 0);
    moduleAccesser->getWorkManageModule().setFloat(speed, 0x11000000);
    float control = soValueAccesser::getConstantFloat(moduleAccesser, 0xFA7, 0);
    moduleAccesser->getWorkManageModule().setFloat(control, 0x11000001);
    moduleAccesser->getWorkManageModule().onFlag(0x12000003);
}

bool ftMarthStatusUniqProcessSpecialHi::onChangeLr(soModuleAccesser* moduleAccesser, float, float) {
    moduleAccesser->getWorkManageModule().setFloat(0.0f, 0x21000004);
    moduleAccesser->getWorkManageModule().onFlag(0x22000016);
    return true;
}

ftMarthStatusUniqProcessSpecialHi::~ftMarthStatusUniqProcessSpecialHi() {}

ftMarthStatusUniqProcessSpecialHi g_ftMarthStatusUniqProcessSpecialHi;

ftMarthStatusUniqProcessSpecialHi::ftMarthStatusUniqProcessSpecialHi() {}
