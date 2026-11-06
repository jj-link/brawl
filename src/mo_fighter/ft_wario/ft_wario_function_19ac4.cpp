#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

extern "C" {
extern const unsigned char lbl_110_data_5EF0[], lbl_110_data_212C[], lbl_110_data_60DC[], lbl_110_data_168C[], lbl_110_data_6EB0[];
extern const float lbl_110_rodata_188[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
struct Vec2Words { float x, y; };
float fn_110_1526C(Vec2Words*);
}
struct EnergyView { virtual void v0(); virtual void v1(); virtual Vec2Words getSpeed(); };
struct WarioParams {
    char pad0[0xc]; float p0c; char pad10[4]; float p14, p18; char pad1c[4]; float p20;
    char pad24[0x1c]; float p40, p44, p48; char pad4c[4]; float p50;
    char pad54[0x10]; float p64;
};
struct WarioObject { char pad[0x2980]; WarioParams* params; };

extern "C" void fn_110_19AC4(void*, soModuleAccesser* accesser) {
    const float* constants = lbl_110_rodata_188 + 1;
    const soModuleEnumeration* modules = accesser->m_enumerationStart;
    soWorkManageModule* work = modules->m_workManageModule;
    soSituationModule* situation = modules->m_situationModule;
    soGroundModule* ground = modules->m_groundModule;
    soKineticModule* kinetic = modules->m_kineticModule;
    soMotionModule* motion = modules->m_motionModule;
    WarioParams* params = ((WarioObject*)__dynamic_cast(accesser->m_stageObject, 0x3c, lbl_110_data_5EF0, lbl_110_data_212C, 1))->params;
    bool left = work->isFlag(0x22000004);
    bool right = work->isFlag(0x22000005);
    bool center = work->isFlag(0x22000006);
    float angle = work->getFloat(0x21000000);
    float target = work->getFloat(0x21000002);
    float previous = work->getFloat(0x21000003);
    EnergyView* energy = (EnergyView*)__dynamic_cast(kinetic->getEnergy(0), 0, lbl_110_data_60DC, lbl_110_data_168C, 1);
    soKineticEnergy* gravity = (soKineticEnergy*)__dynamic_cast(kinetic->getEnergy(1), 0, lbl_110_data_6EB0, lbl_110_data_168C, 1);
    bool launch = false;
    float speed = constants[-1];
    if (work->isFlag(0x22000002)) {
        if (left || right) {
            float diff = nw4r::ut::Abs(angle - target);
            if (diff > params->p48 && !work->isFlag(0x22000007)) {
                work->onFlag(0x22000007);
                float scaled = diff / constants[1];
                speed = scaled * params->p50;
                launch = true;
            }
        }
        work->offFlag(0x22000002);
    } else if (center) {
        work->offFlag(0x22000007);
        float diff = target - previous;
        if (diff > params->p48) {
            float scaled = diff / constants[1];
                speed = scaled * params->p50;
            launch = true;
        }
    }
    if (launch) {
        *reinterpret_cast<float*>(reinterpret_cast<char*>(gravity) + 8) = speed;
        reinterpret_cast<unsigned char*>(gravity)[5] |= 0x80;
        kinetic->changeKinetic(0x21, accesser);
        situation->setKind(static_cast<SituationKind>(2), false);
        ground->setCorrect(static_cast<soGroundShapeImpl::CorrectKind>(5), 0);
        work->offFlag(0x22000004);
        work->offFlag(0x22000005);
        work->offFlag(0x22000006);
    } else if (left || right || center) {
        if (center) {
            if (angle > target) {
                angle -= params->p64;
                if (angle < target) angle = target;
            } else if (angle < target) {
                angle += params->p64;
                if (angle > target) angle = target;
            }
        } else if (!left && right) {
            angle -= params->p64;
            if (center) {
                if (angle < target) angle = target;
            } else if (angle < constants[2]) angle = constants[2];
        } else if (!right && left) {
            angle += params->p64;
            if (center) {
                if (angle > target) angle = target;
            } else if (angle > constants[3]) angle = constants[3];
        }
    }
    work->setFloat(angle, 0x21000000);
    Vec2Words v = energy->getSpeed();
    float value = fn_110_1526C(&v);
    float range;
    if (left || right) {
        value -= params->p14;
        range = params->p0c - params->p14;
    } else {
        value -= params->p20;
        range = params->p18 - params->p20;
    }
    if (value < constants[-1]) value = constants[-1];
    else if (value > range) value = range;
    float ratio = value / range;
    float rate = params->p44 + ratio * (params->p40 - params->p44);
    motion->setRate(rate);
}
