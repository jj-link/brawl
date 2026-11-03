#include <so/event/so_event_system.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_bss_2C3C[];
extern char lbl_27_bss_2CB0[];
extern char lbl_27_data_18418[];
extern char lbl_27_data_18618[];
extern char lbl_27_data_185E0[];
extern char __RTTI__11soEventUnit[];
void fn_27_C656C(void);
void* __dynamic_cast(void*, long, const void*, const void*, long);
void __register_global_object(void*, void*, void*);
}

class soBss28Object {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
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
    virtual s32 slot19();
};

struct soEventObserverSelf {
    void* vt;
    s16 m_manageID;
    s16 m_unitID;
    s32 m_value;
};

extern "C" {
extern soEventObserverSelf lbl_27_bss_2CBC;
}

struct EventUnitView {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s32 get();
};

extern "C" void fn_27_C65AC() {
    soEventObserverSelf* self = &lbl_27_bss_2CBC;
    s32 var_r29;
    s16 temp_r28;

    temp_r28 = reinterpret_cast<soBss28Object*>(lbl_27_bss_2C3C + 0x28)->slot19();
    self->m_manageID = temp_r28;
    lbl_27_bss_2CBC.vt = lbl_27_data_18618;
    var_r29 = 0;
    self->m_unitID = var_r29;
    self->m_value = var_r29;

    if (temp_r28 > 0 && temp_r28 > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(temp_r28)) {
            if (soEventSystem::getInstance()->getManager(self->m_manageID)
                    ->getObserverCapacity(self->m_unitID) == 0) {
                self->m_value = var_r29;
            } else {
                s16 unitId = self->m_unitID;
                soEventManager* mgr = soEventSystem::getInstance()->getManager(self->m_manageID);
                if (mgr->getObserverCapacity(unitId) == 0) {
                    var_r29 = 0;
                } else {
                    EventUnitView* unit = (EventUnitView*)__dynamic_cast(
                        mgr->getEventUnit(unitId), 0, lbl_27_data_18418, __RTTI__11soEventUnit, 0);
                    if (unit == 0) {
                        var_r29 = 0;
                    } else {
                        var_r29 = unit->get();
                    }
                }
                self->m_value = var_r29;
            }
        }
    }

    self->vt = lbl_27_data_185E0;
    __register_global_object(&lbl_27_bss_2CBC, (void*)fn_27_C656C, lbl_27_bss_2CB0);
}

__declspec(section ".ctors") extern void* const fn_27_C65AC_ctor = (void*)fn_27_C65AC;
