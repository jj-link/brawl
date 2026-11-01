#include <so/so_module_accesser.h>
#include <cmath>
#pragma force_active on
struct ToonCommonInputParameters {
    unsigned char prefix[0x18];
    float stickThreshold;
    int flickFrames;
    float flickBonus;
};
#define V4(n) \
    virtual void slot_##n##_0(); \
    virtual void slot_##n##_1(); \
    virtual void slot_##n##_2(); \
    virtual void slot_##n##_3();
#define V16(n) V4(n##a) V4(n##b) V4(n##c) V4(n##d)
struct ToonResultPrefix { unsigned char prefix[0xc]; };
class ToonResult : public ToonResultPrefix {
public:
    V4(A) V4(B) V4(C)
    virtual void slot_tail();
    virtual void apply(int, int, int);
};
struct ToonFighterPrefix { unsigned char prefix[0x3c]; };
class ToonFighter : public ToonFighterPrefix {
public:
    V16(A) V16(B) V16(C) V16(D) V16(E) V16(F)
    V16(G) V16(H) V16(I) V16(J) V16(K)
    V4(L) V4(M)
    virtual void slot_tail();
    virtual ToonResult* getResult();
};
#undef V16
#undef V4
extern "C" {
extern unsigned char g_ftCommonDataAccesser[];
ToonCommonInputParameters* fn_27_14548C(void*);
extern const unsigned char lbl_121_data_3474[], lbl_121_data_3CF0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
extern "C" void fn_121_F474(void*, soModuleAccesser* accesser) {
    double stick_abs = fabs(accesser->getControllerModule().getStickX());
    float stick = static_cast<float>(stick_abs);
    if (stick >= fn_27_14548C(g_ftCommonDataAccesser)->stickThreshold) {
        soControllerModule& controller = accesser->getControllerModule();
        float bonus = fn_27_14548C(g_ftCommonDataAccesser)->flickBonus;
        float flickFramesFloat = static_cast<float>(fn_27_14548C(g_ftCommonDataAccesser)->flickFrames);
        float frames = flickFramesFloat + bonus;
        if (static_cast<float>(controller.getFlickNoResetX()) < frames) {
            ToonFighter* fighter = static_cast<ToonFighter*>(__dynamic_cast(
                accesser->m_stageObject, 0x3c, lbl_121_data_3474,
                lbl_121_data_3CF0, static_cast<short>(1)));
            accesser->getWorkManageModule().onFlag(0x22000011);
            ToonResult* result = fighter->getResult();
            result->apply(1, 0x19, 0);
        }
    }
}
