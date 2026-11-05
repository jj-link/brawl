#include <types.h>
#include <so/event/so_event_system.h>
#include <so/so_instance_manager.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_128[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
    short addObserverPrivate(long manageId, T* obsvr, signed char p3) {
        soEventManager* evtMgr = soEventSystem::getInstance()->getManager(manageId);
        if (!evtMgr->getObserverCapacity(obsvr->m_unitID))
            return -1;
        soEventUnitWrapper<T>* evt = (soEventUnitWrapper<T>*)__dynamic_cast(
            evtMgr->getEventUnit(obsvr->m_unitID), 0, lbl_27_data_128, __RTTI__11soEventUnit, 0);
        if (!evt)
            return -1;
        short res = evt->addObserverSub(obsvr, p3);
        return res;
    }

public:
    virtual void addObserver(short param1, signed char param2) { }
    short m_manageID;
    short m_unitID;
    short m_sendID;

    void removeObserver(short manageId) {
        const soInstanceManager<soEventManager*>& instMgr =
            soEventSystem::getInstance()->getInstanceManager();
        if (instMgr.isContain(manageId) == true) {
            soEventSystem::getInstance()->getManager(m_manageID)
                ->eraseObserver(m_unitID, m_sendID);
        }
        m_sendID = -1;
        m_manageID = -1;
    }

    void addObserverSub(long manageId, T* obsvr, signed char p3);
};

class soAnimCmdEventObserver : public soEventObserver<soAnimCmdEventObserver> {
};

template <class T>
void soEventObserver<T>::addObserverSub(long manageId, T* obsvr, signed char p3) {
    bool check4 = false;
    bool check3 = false;
    bool check2 = false;
    bool check1 = false;
    long removeID;
    long checkID = m_manageID;

    if (m_manageID >= 0 && m_unitID >= 0)
        check1 = true;
    if (check1 && m_sendID > -1)
        check2 = true;
    if (check2 && soEventSystem::getInstance()->getInstanceManager().isContain(checkID) == true)
        check3 = true;
    if (check3 && soEventSystem::getInstance()->getManager(m_manageID)->getObserverCapacity(m_unitID) == 1)
        check4 = true;
    if (check4 == true) {
        removeID = m_manageID;
        removeObserver(removeID);
    }
    if (manageId <= -1 || m_unitID <= -1 ||
        soEventSystem::getInstance()->getInstanceManager().isContain(manageId) == false)
        return;
    soEventManager* eventManager = soEventSystem::getInstance()->getManager(manageId);
    if (eventManager->isNullUnit(m_unitID) != true) {
        m_sendID = addObserverPrivate(manageId, obsvr, p3);
        if (m_sendID > -1 && m_sendID > -1)
            m_manageID = manageId;
    }
}

template void soEventObserver<soAnimCmdEventObserver>::addObserverSub(long, soAnimCmdEventObserver*, signed char);
