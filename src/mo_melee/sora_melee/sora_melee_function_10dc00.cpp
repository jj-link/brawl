#include <so/event/so_event_system.h>
#pragma force_active on

extern "C" {
extern char lbl_27_bss_2C3C[];
extern char lbl_27_data_18418[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct soEventObserverSelf {
    s32 vt;
    s16 m_manageID;
    s16 m_unitID;
    s16 m_sendID;
};

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

static inline s16 fn_27_addObserverPrivate(soEventObserverSelf* self, s32 manageId, s8 p3) {
    soEventManager* evtMgr = soEventSystem::getInstance()->getManager((s16)manageId);
    if (!evtMgr->getObserverCapacity(self->m_unitID)) {
        return -1;
    }
    soEventUnitWrapper<soEventObserverSelf>* evt = (soEventUnitWrapper<soEventObserverSelf>*)__dynamic_cast(evtMgr->getEventUnit(self->m_unitID), 0, lbl_27_data_18418, __RTTI__11soEventUnit, 0);
    if (!evt) {
        return -1;
    }
    s16 res = evt->addObserverSub(self, p3);
    return res;
}

extern "C" void fn_27_10DC00(soEventObserverSelf* self, s32 unused, s8 p3) {
    s32 manageId = reinterpret_cast<soBss28Object*>(lbl_27_bss_2C3C + 0x28)->slot19();
    bool check4 = false;
    bool check3 = false;
    bool check2 = false;
    bool check1 = false;
    s32 removeID;
    s32 checkID = self->m_manageID;

    if (self->m_manageID >= 0 && self->m_unitID >= 0) {
        check1 = true;
    }
    if (check1 && self->m_sendID > -1) {
        check2 = true;
    }
    if (check2 && soEventSystem::getInstance()->getInstanceManager().isContain(checkID) == true) {
        check3 = true;
    }
    if (check3 && soEventSystem::getInstance()->getManager(self->m_manageID)->getObserverCapacity(self->m_unitID) == 1) {
        check4 = true;
    }
    if (check4 == true) {
        removeID = self->m_manageID;
        if (soEventSystem::getInstance()->getInstanceManager().isContain(removeID) == true) {
            soEventSystem::getInstance()->getManager(self->m_manageID)->eraseObserver(self->m_unitID, self->m_sendID);
        }
        self->m_sendID = -1;
        self->m_manageID = -1;
    }
    if ((s16)manageId > -1 && self->m_unitID > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain((s16)manageId)) {
            soEventManager* eventManager = soEventSystem::getInstance()->getManager((s16)manageId);
            if (eventManager->isNullUnit(self->m_unitID) != true) {
                self->m_sendID = fn_27_addObserverPrivate(self, manageId, p3);
                if (self->m_sendID > -1 && self->m_sendID > -1) {
                    self->m_manageID = (s16)manageId;
                }
            }
        }
    }
}
