#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/controller/so_controller_module_impl.h>
#include <so/posture/so_posture_module_simple.h>
#pragma force_active on

class SoMotionSlots {
public:
    virtual void s00() = 0;
    virtual void s01() = 0;
    virtual void s02() = 0;
    virtual void s03() = 0;
    virtual void s04() = 0;
    virtual void s05() = 0;
    virtual void s06() = 0;
    virtual void s07() = 0;
    virtual void s08() = 0;
    virtual void s09() = 0;
    virtual void s10() = 0;
    virtual void s11() = 0;
    virtual void s12() = 0;
    virtual void s13() = 0;
    virtual void s14() = 0;
    virtual void s15() = 0;
    virtual void s16() = 0;
    virtual void s17() = 0;
    virtual void s18() = 0;
    virtual void s19() = 0;
    virtual void s20() = 0;
    virtual void s21() = 0;
    virtual void s22() = 0;
    virtual float s25(float) = 0;
    virtual void s24() = 0;
    virtual void s27(float) = 0;
    virtual void s28() = 0;
    virtual void s29() = 0;
    virtual void s30() = 0;
    virtual void s31() = 0;
    virtual void s32() = 0;
    virtual void s33() = 0;
    virtual void s34() = 0;
    virtual void s35() = 0;
    virtual void s36() = 0;
    virtual void s37(float) = 0;
    virtual float s38() = 0;
};

extern "C" {
extern const float lbl_104_rodata_108[];
double atan2(double, double);
float mtSqrtf__Ff(float);
}

extern "C" void fn_104_1E534(void*, soModuleAccesser* accesser) {
    const float* const constants = lbl_104_rodata_108;
    const soModuleEnumeration& modules = *accesser->m_enumerationStart;
    soWorkManageModule* work = modules.m_workManageModule;
    soControllerModule* controller = modules.m_controllerModule;
    soPostureModule* posture = modules.m_postureModule;
    SoMotionSlots* motion = reinterpret_cast<SoMotionSlots*>(modules.m_motionModule);

    float stickX = controller->getStickX();
    float stickY = controller->getStickY();
    float k = soValueAccesser::getConstantFloat(accesser, 0xCB2, 0);
    float angle = static_cast<float>(atan2(stickY, stickX * posture->getLr()));
    if (angle < constants[0]) {
        angle += constants[1];
    }
    float deg = constants[2] * angle;
    if (deg < constants[0]) {
        deg = constants[0];
    } else if (deg > constants[3]) {
        deg = constants[3];
    }

    float cur = work->getFloat(0x21000004);
    float diff = deg - cur;
    if (diff > constants[4]) {
        diff -= constants[5];
    } else if (diff < constants[6]) {
        diff += constants[5];
    }
    float wrapped = cur + diff * k;
    if (wrapped > constants[5]) {
        wrapped -= constants[5];
    } else if (wrapped < constants[0]) {
        wrapped += constants[5];
    }
    work->setFloat(wrapped, 0x21000004);

    float sqY = stickY * stickY;
    float sqX = stickX * stickX;
    float mag = mtSqrtf__Ff(sqX + sqY);
    if (mag > constants[7]) {
        mag = constants[7];
    }
    float speed = work->getFloat(0x21000005);
    mag = speed + k * (mag - speed);
    work->setFloat(mag, 0x21000005);

    float t = constants[9] * wrapped;
    float s = constants[8] + t;
    float r = motion->s25(t);
    float x = (constants[7] - speed) - r;
    motion->s27(x);
    float r2 = motion->s38();
    float y = s - r2;
    motion->s37(y);
}
