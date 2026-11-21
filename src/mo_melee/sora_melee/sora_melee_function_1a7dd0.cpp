#include <types.h>
#include <so/event/so_event_system.h>
#pragma force_active on

class soGimmickEventObserver;
extern "C" {
extern unsigned char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
template <> class soEventUnitWrapper<soGimmickEventObserver> : public soEventUnit {
public:
    static unsigned char __RTTI[];
    virtual s16 getEventId();
    virtual ~soEventUnitWrapper();
    virtual s16 addObserverSub(soGimmickEventObserver*, s8) = 0;
    virtual soInstanceManagerFullProperty<soGimmickEventObserver*>* getObserverListSub() = 0;
};


template <typename T>
class soEventObserver {
    s16 addObserverPrivate(s32 manageId, T* obsvr, s8 p3) {
        soEventManager* evtMgr = soEventSystem::getInstance()->getManager(manageId);
        if (!evtMgr->getObserverCapacity(reinterpret_cast<soEventObserver<T>*>(obsvr)->m_unitID))
            return -1;
        soEventUnitWrapper<T>* evt = (soEventUnitWrapper<T>*)__dynamic_cast(
            evtMgr->getEventUnit(reinterpret_cast<soEventObserver<T>*>(obsvr)->m_unitID),
            0, soEventUnitWrapper<T>::__RTTI, __RTTI__11soEventUnit, 0);
        if (!evt)
            return -1;
        s16 res = evt->addObserverSub(obsvr, p3);
        return res;
    }

public:
    virtual void addObserver(s16 param1, s8 param2) { }
    s16 m_manageID;
    s16 m_unitID;
    s16 m_sendID;

    void addObserverSub(long manageId, T* obsvr, s8 p3);
};

template <typename T>
void soEventObserver<T>::addObserverSub(long manageId, T* obsvr, s8 p3) {
    bool check4 = false;
    bool check3 = false;
    bool check2 = false;
    bool check1 = false;
    s32 removeID;
    s32 checkID = m_manageID;

    if (m_manageID >= 0 && m_unitID >= 0) {
        check1 = true;
    }
    if (check1 && m_sendID > -1) {
        check2 = true;
    }
    if (check2 && soEventSystem::getInstance()->getInstanceManager().isContain(checkID) == true) {
        check3 = true;
    }
    if (check3 && soEventSystem::getInstance()->getManager(m_manageID)->getObserverCapacity(m_unitID) == 1) {
        check4 = true;
    }
    if (check4 == true) {
        removeID = m_manageID;
        if (soEventSystem::getInstance()->getInstanceManager().isContain(removeID) == true) {
            soEventSystem::getInstance()->getManager(m_manageID)->eraseObserver(m_unitID, m_sendID);
        }
        m_sendID = -1;
        m_manageID = -1;
    }
    if (manageId <= -1 || m_unitID <= -1 ||
        soEventSystem::getInstance()->getInstanceManager().isContain(manageId) == false) {
        return;
    }
    soEventManager* eventManager = soEventSystem::getInstance()->getManager(manageId);
    if (eventManager->isNullUnit(m_unitID) != true) {
        m_sendID = addObserverPrivate(manageId, obsvr, p3);
        if (m_sendID > -1 && m_sendID > -1) {
            m_manageID = manageId;
        }
    }
}

template void soEventObserver<soGimmickEventObserver>::addObserverSub(long, soGimmickEventObserver*, s8);
