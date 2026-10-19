#include <so/so_module_accesser.h>
#pragma force_active on

namespace {
// The shared enumeration keeps the physics module opaque. This view preserves
// the original dispatch layout (8 leading bytes, then the vptr) and describes
// enough slots to reach the one invoked here, at vtable offset 0x64.
struct NessPhysicsPrefix {
    unsigned char prefix[8];
};
class NessPhysicsView : public NessPhysicsPrefix {
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
public:
    virtual void slot_64(int) = 0;
};
}

extern "C" void fn_101_20CF4(void*, soModuleAccesser* accesser) {
    NessPhysicsView* physics = static_cast<NessPhysicsView*>(accesser->m_enumerationStart->m_physicsModule);
    physics->slot_64(0);
}
