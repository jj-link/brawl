#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/collision/so_collision_hit_module_impl.h>
#pragma force_active on

class Capture {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void release(int);
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7(int);
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(int);
};

extern "C" void fn_27_191E3C(void*, soModuleAccesser* accesser, int kind) {
    if (kind != 0x108 && kind != 0x109 && kind != 0x42) {
        soLinkModule* link = accesser->m_enumerationStart->m_linkModule;
        if (link->isLink(0)) {
            Vec2f pos;
            Vec2f::copy(pos, link->getParentShapeCenterPos(0));
            ((Capture*)accesser->m_enumerationStart->m_captureModule)->release(0);
            accesser->m_enumerationStart->m_groundModule->setShapeSafePos(&pos, 0);
        }
        ((Object_vptr_0*)accesser->m_enumerationStart->m_workManageModule)->slot19(0x1200003B);
        soCollisionHitModule* hit = accesser->m_enumerationStart->m_collisionHitModule;
        hit->set((soSet<soCollisionHitData>*)soValueAccesser::getConstantIndefinite(accesser, 0xA803, 0), 0);
        ((Object_vptr_0*)accesser->m_enumerationStart->m_visibilityModule)->slot7(1);
    }
}
