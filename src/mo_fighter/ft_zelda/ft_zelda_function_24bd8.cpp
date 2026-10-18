#include <so/so_module_accesser.h>
#pragma force_active on

namespace {
struct ZPhysicsPrefix {
    unsigned char prefix[8];
};
class ZPhysicsModule : public ZPhysicsPrefix {
public:
    virtual void slot_00() = 0;
    virtual void slot_04() = 0;
    virtual void slot_08() = 0;
    virtual void slot_0C() = 0;
    virtual void slot_10() = 0;
    virtual void slot_14() = 0;
    virtual void slot_18() = 0;
    virtual void slot_1C() = 0;
    virtual void slot_20() = 0;
    virtual void slot_24() = 0;
    virtual void slot_28() = 0;
    virtual void slot_2C() = 0;
    virtual void slot_30() = 0;
    virtual void slot_34() = 0;
    virtual void slot_38() = 0;
    virtual void slot_3C() = 0;
    virtual void slot_40() = 0;
    virtual void slot_44() = 0;
    virtual void slot_48() = 0;
    virtual void slot_4C() = 0;
    virtual void slot_50() = 0;
    virtual void slot_54() = 0;
    virtual void slot_58() = 0;
    virtual void slot_5C() = 0;
    virtual void slot_60() = 0;
    virtual void slot_64() = 0;
    virtual void slot_68() = 0;
    virtual void slot_6C() = 0;
    virtual void slot_70() = 0;
    virtual void slot_74() = 0;
    virtual void slot_78() = 0;
    virtual void slot_7C() = 0;
    virtual int f88() = 0;
    virtual void slot_8C() = 0;
    virtual void slot_90() = 0;
    virtual void slot_94() = 0;
    virtual void slot_98() = 0;
    virtual void slot_9C() = 0;
    virtual void slot_A0() = 0;
    virtual void fa4(int) = 0;
    virtual void slot_A8() = 0;
    virtual void slot_AC() = 0;
    virtual void slot_B0() = 0;
    virtual void fb4(int) = 0;
};
}

extern "C" void fn_104_24BD8(void*, soModuleAccesser* accesser) {
    if (static_cast<ZPhysicsModule*>(accesser->m_enumerationStart->m_physicsModule)->f88() > 0) {
        static_cast<ZPhysicsModule*>(accesser->m_enumerationStart->m_physicsModule)->fb4(1);
        if (static_cast<ZPhysicsModule*>(accesser->m_enumerationStart->m_physicsModule)->f88() == 0) {
            static_cast<ZPhysicsModule*>(accesser->m_enumerationStart->m_physicsModule)->fa4(6);
        }
    }
}
