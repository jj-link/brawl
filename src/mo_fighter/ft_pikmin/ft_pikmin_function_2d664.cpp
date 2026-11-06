#include <so/so_module_accesser.h>
#pragma force_active on

namespace {
struct Prefix8 {
    unsigned char prefix[8];
};

class PhysicsView : public Prefix8 {
public:
    virtual void s2() = 0; virtual void s3() = 0; virtual void s4() = 0; virtual void s5() = 0;
    virtual void s6() = 0; virtual void s7() = 0; virtual void s8() = 0; virtual void s9() = 0;
    virtual void s10() = 0; virtual void s11() = 0; virtual void s12() = 0; virtual void s13() = 0;
    virtual void s14() = 0; virtual void s15() = 0; virtual void s16() = 0; virtual void s17() = 0;
    virtual void s18() = 0; virtual void s19() = 0; virtual void s20() = 0; virtual void s21() = 0;
    virtual void s22() = 0; virtual void s23() = 0; virtual void s24() = 0; virtual void s25() = 0;
    virtual void s26() = 0; virtual void s27() = 0; virtual void s28() = 0; virtual void s29() = 0;
    virtual void s30() = 0; virtual void s31() = 0; virtual void s32() = 0; virtual void s33() = 0;
    virtual void s34() = 0; virtual void s35(int) = 0; virtual void s36() = 0; virtual void s37() = 0;
    virtual void s38() = 0; virtual void s39() = 0; virtual void s40() = 0; virtual void s41(int) = 0;
};
}

extern "C" void fn_113_2D664(void*, soModuleAccesser* accesser) {
    int value = accesser->getWorkManageModule().getInt(0x10000007);
    if (value > 0) {
        accesser->getWorkManageModule().isFlag(0x22000000);
        accesser->getLinkModule().getModelConstraintTargetNodePosition();
        static_cast<PhysicsView*>(accesser->m_enumerationStart->m_physicsModule)->s41(7);
        static_cast<PhysicsView*>(accesser->m_enumerationStart->m_physicsModule)->s35(value);
        accesser->getWorkManageModule().setInt(0, 0x20000000);
        accesser->getWorkManageModule().setInt(0, 0x20000001);
    }
}
