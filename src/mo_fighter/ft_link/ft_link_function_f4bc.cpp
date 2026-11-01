#include <so/so_module_accesser.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
struct CommonInputParameters {
    unsigned char prefix[0x18];
    float stickThreshold;
    int flickFrames;
    float flickBonus;
};
#define V1(n) virtual void v##n();
#define V10(n) V1(n##0) V1(n##1) V1(n##2) V1(n##3) V1(n##4) V1(n##5) V1(n##6) V1(n##7) V1(n##8) V1(n##9)
#define V100(n) V10(n##0) V10(n##1) V10(n##2) V10(n##3) V10(n##4) V10(n##5) V10(n##6) V10(n##7) V10(n##8) V10(n##9)
struct OwnerBase { unsigned char pad[0xc]; };
struct Owner : OwnerBase {
    V10(a) V1(b0) V1(b1) V1(b2)
    virtual void action(int, int, int);
};
struct FighterBase { unsigned char pad[0x3c]; };
struct FighterView : FighterBase {
    V100(c) V10(d0) V10(d1) V10(d2) V10(d3) V10(d4) V10(d5) V10(d6) V10(d7) V1(e0) V1(e1) V1(e2) V1(e3) V1(e4)
    virtual Owner* getOwner();
};
extern "C" {
extern unsigned char g_ftCommonDataAccesser[];
extern const char lbl_93_data_337C[];
extern const char lbl_93_data_3BF8[];
CommonInputParameters* fn_27_14548C(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
static inline double absoluteStick(float value) {
    return __fabs(value);
}
static inline float addFlickBonus(int frames, float bonus) {
    return static_cast<float>(frames) + bonus;
}
extern "C" void fn_93_F4BC(void*, soModuleAccesser* accesser) {
    float stick = absoluteStick(accesser->getControllerModule().getStickX());
    if (stick >= fn_27_14548C(g_ftCommonDataAccesser)->stickThreshold) {
        soControllerModule& controller = accesser->getControllerModule();
        float bonus = fn_27_14548C(g_ftCommonDataAccesser)->flickBonus;
        float frames = addFlickBonus(fn_27_14548C(g_ftCommonDataAccesser)->flickFrames, bonus);
        if (static_cast<float>(controller.getFlickNoResetX()) < frames) {
            FighterView* fighter = static_cast<FighterView*>(__dynamic_cast(
                accesser->m_stageObject, 0x3c, lbl_93_data_337C, lbl_93_data_3BF8, (short)1));
            accesser->getWorkManageModule().onFlag(0x22000011);
            fighter->getOwner()->action(1, 0x19, 0);
        }
    }
}
