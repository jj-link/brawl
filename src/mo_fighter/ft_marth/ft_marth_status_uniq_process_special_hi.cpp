#include <math.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

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
double fn_106_BE30(double value);
}

static inline soKineticEnergy* castEnergy(soKineticEnergy* energy, const void* type) {
    return static_cast<soKineticEnergy*>(__dynamic_cast(energy, 0, type, lbl_106_data_EB4, 1));
}

static inline void enableEnergy(soKineticEnergy* energy) {
    reinterpret_cast<u8*>(energy)[5] |= 0x80;
}

static inline void disableEnergy(soKineticEnergy* energy) {
    reinterpret_cast<u8*>(energy)[5] &= ~0x80;
}

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
    Vec2f sumSpeed;
    Vec2f::copy(sumSpeed, moduleAccesser->getKineticModule().getSumSpeed(soKineticEnergy::ATTRIBUTE_MASK_MAIN));
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
            Vec2f speed(zero, zero);
            Vec3f rotation;
            gravity->resetEnergy(0, &speed, fn_106_77F4(&rotation, zero, zero, zero), moduleAccesser);
        }
        enableEnergy(gravity);
        soKineticEnergy* normal = castEnergy(moduleAccesser->getKineticModule().getEnergy(0), lbl_106_data_5390);
        {
            Vec2f speed(zero, zero);
            Vec3f rotation;
            normal->resetEnergy(5, &speed, fn_106_77F4(&rotation, zero, zero, zero), moduleAccesser);
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
    double stickMagnitude = fn_106_BE30(moduleAccesser->getControllerModule().getStickX());
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
            double previousMagnitude = fn_106_BE30(previousAngle);
            if (fn_106_BE30(angle) > previousMagnitude) {
                previousAngle = angle;
            }
            moduleAccesser->getWorkManageModule().setFloat(previousAngle, 0x21000004);
        }
    }
    Vec2f sumSpeed;
    Vec2f::copy(sumSpeed, moduleAccesser->getKineticModule().getSumSpeed(soKineticEnergy::ATTRIBUTE_MASK_MAIN));
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

extern "C" double fn_106_BE30(double value) {
    return fabs(value);
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

// decomp-orchestrator: begin fn_106_BE38
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_106_BE38 {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_106_BE38(void) {}
}  // namespace decomp_orch_fn_106_BE38
// decomp-orchestrator: end fn_106_BE38

// decomp-orchestrator: begin fn_106_BE3C
#include <types.h>
#pragma force_active on
namespace decomp_orch_fn_106_BE3C {
// Generated by decomp-orchestrator template solver (empty).



extern "C" void fn_106_BE3C(void) {}
}  // namespace decomp_orch_fn_106_BE3C
// decomp-orchestrator: end fn_106_BE3C

// decomp-orchestrator: begin fn_106_BFE0
#pragma force_active on
namespace decomp_orch_fn_106_BFE0 {
extern "C" {
extern char lbl_106_data_5584[];

void fn_106_BFE0(void* self) {
    *(void**)self = lbl_106_data_5584;
}
}
}  // namespace decomp_orch_fn_106_BFE0
// decomp-orchestrator: end fn_106_BFE0

// decomp-orchestrator: begin fn_106_BF58
namespace decomp_orch_fn_106_BF58 {
#pragma force_active on
#pragma scheduling off
extern "C" void __dl__FPv(void*);
extern "C" void* fn_106_BF58(void* p, int flags) {
    if (p != 0 && (short)flags > 0) {
        __dl__FPv(p);
    }
    return p;
}
}  // namespace decomp_orch_fn_106_BF58
// decomp-orchestrator: end fn_106_BF58

// decomp-orchestrator: begin fn_106_BF98
namespace decomp_orch_fn_106_BF98 {
#pragma force_active on
extern "C" {
extern char lbl_106_bss_1B4[];
extern char lbl_106_bss_1A8[];
void fn_106_BFE0(void* self);
void* fn_106_BF58(void* p, int flags);
void __register_global_object(void* obj, void* dtor, void* handle);

#pragma scheduling off
void fn_106_BF98(void) {
    fn_106_BFE0(lbl_106_bss_1B4);
    __register_global_object(lbl_106_bss_1B4, (void*)fn_106_BF58, lbl_106_bss_1A8);
}
}
}  // namespace decomp_orch_fn_106_BF98
// decomp-orchestrator: end fn_106_BF98

// decomp-orchestrator: begin fn_106_BEE4
#include <so/so_module_accesser.h>
namespace decomp_orch_fn_106_BEE4 {
#pragma force_active on
#pragma scheduling off

extern "C" {
extern const float lbl_106_rodata_28;

bool fn_106_BEE4(void*, soModuleAccesser* moduleAccesser, float, float) {
    moduleAccesser->getWorkManageModule().setFloat(lbl_106_rodata_28, 0x21000004);
    moduleAccesser->getWorkManageModule().onFlag(0x22000016);
    return true;
}
}
}  // namespace decomp_orch_fn_106_BEE4
// decomp-orchestrator: end fn_106_BEE4

// decomp-orchestrator: begin fn_106_BE40
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on
#pragma scheduling off
extern "C" void fn_106_BE40(void*, soModuleAccesser* moduleAccesser, int) {
    float speed = soValueAccesser::getConstantFloat(moduleAccesser, 0xFA8, 0);
    moduleAccesser->getWorkManageModule().setFloat(speed, 0x11000000);
    float control = soValueAccesser::getConstantFloat(moduleAccesser, 0xFA7, 0);
    moduleAccesser->getWorkManageModule().setFloat(control, 0x11000001);
    moduleAccesser->getWorkManageModule().onFlag(0x12000003);
}
// decomp-orchestrator: end fn_106_BE40

// decomp-orchestrator: begin fn_106_B8E8
#include <types.h>
#include <math.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
namespace decomp_orch_fn_106_B8E8 {
#pragma force_active on





class MarthKineticSpeedView : public soNullable {
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
    virtual u64 getSumSpeed(const unsigned short&);
};

extern "C" {
extern const float lbl_106_rodata_28[];









void fn_27_89DAC(int, soModuleAccesser*);


float fn_106_BE30(double);
}

static inline soKineticEnergy* castMarthHiEnergy(
    soKineticEnergy* energy, const void* type, int flag = 1) {
    return static_cast<soKineticEnergy*>(
        __dynamic_cast(energy, 0, type, lbl_106_data_EB4, flag));
}

static inline void enableMarthHiEnergy(soKineticEnergy* energy) {
    reinterpret_cast<u8*>(energy)[5] |= 0x80;
}

static inline void disableMarthHiEnergy(soKineticEnergy* energy) {
    struct EnableFlag { u8 enabled : 1; };
    reinterpret_cast<EnableFlag*>(reinterpret_cast<u8*>(energy) + 5)->enabled = 0;
}



static inline void getSummedSpeed(Vec2f& result, Vec2f& summed, soKineticModule& kinetic, unsigned short attributes) {
    u64 raw = reinterpret_cast<MarthKineticSpeedView&>(kinetic).getSumSpeed(attributes);
    u32* words = reinterpret_cast<u32*>(&summed);
    words[1] = static_cast<u32>(raw);
    words[0] = static_cast<u32>(raw >> 32);
    Vec2f::copy(result, summed);
}

#pragma scheduling off
#pragma optimization_level 2
#pragma optimize_for_size on
#pragma opt_propagation off
extern "C" void fn_106_B8E8(
    ftMarthStatusUniqProcessSpecialHi*, soModuleAccesser* moduleAccesser) {
    const float* constants = lbl_106_rodata_28;
    MarthMotionEnergy* motion = static_cast<MarthMotionEnergy*>(
        castMarthHiEnergy(moduleAccesser->getKineticModule().getEnergy(0),
                   lbl_106_data_557C));
    float stickMagnitude =
        fn_106_BE30(moduleAccesser->getControllerModule().getStickX());
    if (!moduleAccesser->getWorkManageModule().isFlag(0x22000016)) {
        float threshold = soValueAccesser::getConstantFloat(moduleAccesser, 0xFAA, 0);
        if (stickMagnitude > threshold) {
            float angle = static_cast<float>(stickMagnitude - threshold) /
                          (constants[1] - threshold);
            angle *= soValueAccesser::getConstantFloat(moduleAccesser, 0xFAB, 0);
            if (moduleAccesser->getControllerModule().getStickX() > constants[0]) {
                angle = -(constants[2] * angle);
            } else {
                angle = constants[2] * angle;
            }
            float previousAngle =
                moduleAccesser->getWorkManageModule().getFloat(0x21000004);
            double previousMagnitude = fn_106_BE30(previousAngle);
            if (fn_106_BE30(angle) > previousMagnitude) {
                previousAngle = angle;
            }
            moduleAccesser->getWorkManageModule().setFloat(previousAngle, 0x21000004);
        }
    }

    int flag = 1;
    Vec2f sumSpeed;
    Vec2f summed;
    Vec2f gravitySpeed;
    Vec2f controllerSpeed;
    getSummedSpeed(sumSpeed, summed, moduleAccesser->getKineticModule(), flag);
    if (moduleAccesser->getWorkManageModule().isFlag(0x22000010)) {
        if (!moduleAccesser->getWorkManageModule().isFlag(0x22000013)) {
            if (moduleAccesser->getMotionModule().getKind() == 0x1E9) {
                motion->rotationAcceleration =
                    soValueAccesser::getConstantFloat(moduleAccesser, 0xFAD, 0);
            }
            if (moduleAccesser->getWorkManageModule().isFlag(0x22000014) &&
                sumSpeed.m_y < constants[0]) {
                moduleAccesser->getWorkManageModule().onFlag(0x22000013);
            }
        } else {
            bool gravityEnabled = moduleAccesser->getKineticModule().getEnergy(1)->isEnable();
            if (!gravityEnabled) {
                MarthGravityEnergy* gravity = static_cast<MarthGravityEnergy*>(
                    castMarthHiEnergy(moduleAccesser->getKineticModule().getEnergy(1),
                               lbl_106_data_544C, flag));
                Vec3f rotation;
                float vertical = sumSpeed.m_y;
                float zero = constants[0];
                gravitySpeed.m_x = zero;
                gravitySpeed.m_y = vertical;
                gravity->resetEnergy(0, &gravitySpeed,
                    fn_106_77F4(&rotation, zero, zero, zero),
                    moduleAccesser);
                gravity->acceleration =
                    -soValueAccesser::getConstantFloat(moduleAccesser, 0xFAE, 0);
                gravity->terminalSpeed =
                    soValueAccesser::getConstantFloat(moduleAccesser, 0xFAF, 0);
                enableMarthHiEnergy(gravity);
            }
            bool controllerEnabled = moduleAccesser->getKineticModule().getEnergy(2)->isEnable();
            if (!controllerEnabled) {
                soKineticEnergy* controller = castMarthHiEnergy(
                    moduleAccesser->getKineticModule().getEnergy(2),
                    lbl_106_data_5530);
                int resetType = 11;
                Vec3f rotation;
                controllerSpeed.m_x = sumSpeed.m_x;
                controllerSpeed.m_y = constants[0];
                controller->resetEnergy(resetType, &controllerSpeed,
                    fn_106_77F4(&rotation, constants[0], constants[0], constants[0]),
                    moduleAccesser);
                fn_27_15CF90(controller,
                    soValueAccesser::getConstantFloat(moduleAccesser, 0xFA7, 0));
                fn_27_15CF5C(controller,
                    soValueAccesser::getConstantFloat(moduleAccesser, 0xFA7, 0));
                enableMarthHiEnergy(controller);
            }
            disableMarthHiEnergy(motion);
        }
        moduleAccesser->getWorkManageModule().onFlag(0x22000014);
    }

    if (moduleAccesser->getWorkManageModule().isFlag(0x22000015)) {
        motion->rotationSpeed =
            moduleAccesser->getWorkManageModule().getFloat(0x21000004);
        moduleAccesser->getWorkManageModule().offFlag(0x22000015);
    }
}
}  // namespace decomp_orch_fn_106_B8E8
// decomp-orchestrator: end fn_106_B8E8
