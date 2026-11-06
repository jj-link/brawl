#include <so/so_value_accesser.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

struct Pair { float x, y; };
struct Kinetic {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void* getEnergy(int);
    virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10();
    virtual void f11(); virtual void f12(); virtual Pair getSumSpeed(const short&);
};
struct Control {
virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31(); virtual void f32(); virtual void f33(); virtual void f34(); virtual void f35(); virtual void f36(); virtual void f37(); virtual void f38(); virtual void f39(); virtual void f40(); virtual unsigned int getButton();
};
struct CommonInput {
    char pad[0x18];
    float threshold;
    int frames;
    float bonus;
};
extern "C" {
extern const char lbl_120_data_6EEC[], lbl_120_data_7028[], lbl_120_data_2208[];
extern const float lbl_120_rodata_18;
extern unsigned char g_ftCommonDataAccesser[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
CommonInput* fn_27_14548C(void*);
Vec3f* fn_120_8718(Vec3f*, float, float, float);
void fn_27_89DAC(int, soModuleAccesser*);
}
inline unsigned int buttonTest(unsigned int buttons, unsigned int mask) { return buttons & mask; }
inline float addFrames(int frames, float bonus) { return (float)frames + bonus; }
extern "C" void fn_120_CFBC(void*, soModuleAccesser* a) {
    soKineticEnergy* stop = (soKineticEnergy*)__dynamic_cast(((Kinetic*)a->m_enumerationStart->m_kineticModule)->getEnergy(3), 0, lbl_120_data_6EEC, lbl_120_data_2208, 1);
    soKineticEnergy* gravity = (soKineticEnergy*)__dynamic_cast(((Kinetic*)a->m_enumerationStart->m_kineticModule)->getEnergy(1), 0, lbl_120_data_7028, lbl_120_data_2208, 1);
    short mask = 1;
    Vec2f speed;
    Pair sum = ((Kinetic*)a->m_enumerationStart->m_kineticModule)->getSumSpeed(mask);
    __memcpy(&speed, &sum, 8);
    float x = speed.m_x;
    float y = speed.m_y;
    switch (a->m_enumerationStart->m_statusModule->getStatusKind()) {
    case 0x113: {
        x = (float)(double)nw4r::math::FAbs(a->m_enumerationStart->m_controllerModule->getStickX());
        if (x >= fn_27_14548C(g_ftCommonDataAccesser)->threshold) {
            soControllerModule& controller = a->getControllerModule();
            x = fn_27_14548C(g_ftCommonDataAccesser)->bonus;
            x = addFrames(fn_27_14548C(g_ftCommonDataAccesser)->frames, x);
            if (controller.getFlickNoResetX() < x)
                a->getWorkManageModule().onFlag(0x22000012);
        }
        float value = soValueAccesser::getConstantFloat(a, 0xfae, 0);
        a->getWorkManageModule().setFloat(value, 0x21000004);
        a->getWorkManageModule().setFloat(soValueAccesser::getConstantFloat(a, 0xfb8, 0), 0x21000005);
        a->getWorkManageModule().setFloat(soValueAccesser::getConstantFloat(a, 0xfbb, 0), 0x21000006);
        a->getWorkManageModule().setFloat(lbl_120_rodata_18, 0x21000007);
        a->getWorkManageModule().setInt(soValueAccesser::getConstantInt(a, 0x5dc4, 0), 0x20000001);
        gravity = (soKineticEnergy*)a->m_enumerationStart->m_controllerModule;
        unsigned int button = soController::getButtonMask(soController::Pad_Button_Special);
        if (buttonTest(((Control*)gravity)->getButton(), button))
            a->getWorkManageModule().offFlag(0x22000011);
        else
            a->getWorkManageModule().onFlag(0x22000011);
        a->getWorkManageModule().onFlag(0x22000013);
        break;
    }
    case 0x117: {
        if (a->getSituationModule().getKind() == 2) {
            Vec2f horizontal(x, lbl_120_rodata_18);
            Vec3f rot;
            stop->resetEnergy(6, &horizontal, fn_120_8718(&rot, lbl_120_rodata_18, lbl_120_rodata_18, lbl_120_rodata_18), a);
            ((unsigned char*)stop)[5] |= 0x80;
            if (y < -soValueAccesser::getConstantFloat(a, 0xfb0, 0))
                y = -soValueAccesser::getConstantFloat(a, 0xfb0, 0);
            Vec2f vertical(lbl_120_rodata_18, y);
            Vec3f rot2;
            gravity->resetEnergy(0, &vertical, fn_120_8718(&rot2, lbl_120_rodata_18, lbl_120_rodata_18, lbl_120_rodata_18), a);
            ((unsigned char*)gravity)[5] |= 0x80;
        } else {
            Vec2f horizontal(x, lbl_120_rodata_18);
            Vec3f rot;
            stop->resetEnergy(0, &horizontal, fn_120_8718(&rot, lbl_120_rodata_18, lbl_120_rodata_18, lbl_120_rodata_18), a);
            ((unsigned char*)stop)[5] |= 0x80;
            fn_27_89DAC(1, a);
        }
        fn_27_89DAC(2, a);
        a->getWorkManageModule().setInt(a->getSituationModule().getKind(), 0x20000003);
        break;
    }
    }
}