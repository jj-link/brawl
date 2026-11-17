#include <types.h>
#include <ut/ut_list.h>
#include <so/event/so_event_system.h>
#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual void slot6(); virtual int slot7(); virtual void slot8();
};
struct Observer {
    virtual void slot0();
    virtual void notify(int, void*, void*, int);
};
struct ObserverList {
    virtual void slot0(); virtual void slot1();
    virtual Observer** get(int);
    virtual void slot3();
    virtual int size();
};
struct EventUnitView {
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual void slot6(); virtual ObserverList* getObserverList();
};
struct Node { Node* next; char pad4[4]; u32 key; void* data; };
struct UnitData {
    char pad[0x30];
    union {
        u32 flags;
        struct { u32 : 24; u32 id : 7; u32 active : 1; };
        struct { u32 attributes : 24; u32 : 8; };
    };
};
struct Callback { char pad[8]; Object_vptr_0 object; };
struct ModuleRoot { char pad[0x80]; Callback* callback; };
struct ModuleAccessor { char pad[0xD8]; ModuleRoot* moduleRoot; };
struct Presenter { char pad[0x44]; ModuleAccessor* moduleAccessor; };
struct EventParams {
    void* vtable; short managerID; short eventID; ObserverList* cache; char pad[4];
    short getManagerID() const { return managerID; }
    bool checkManager() const {
        const short id = managerID;
        return soEventSystem::getInstance()->getInstanceManager().isContain(id);
    }
};
extern "C" {
extern char lbl_27_data_7BA0[], lbl_27_data_7B68[], lbl_27_data_480[];
extern char __RTTI__11soEventUnit[], lbl_27_bss_B40[];
Presenter* fn_27_6F30C(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
inline ObserverList* getUnit(soEventManager* manager, short id) {
    EventUnitView* unit = (EventUnitView*)__dynamic_cast(
        manager->getEventUnit(id), 0, lbl_27_data_480, __RTTI__11soEventUnit, 0);
    if (unit == 0) return 0;
    return unit->getObserverList();
}
inline ObserverList* getObserverList(EventParams* params) {
    short id = params->eventID;
    soEventManager* manager = soEventSystem::getInstance()->getManager(params->getManagerID());
    if (manager->getObserverCapacity(id) == 0) return 0;
    return getUnit(manager, id);
}
inline bool updateCache(EventParams* params) {
    if (params->managerID <= -1 ||
        !params->checkManager())
        return false;
    soEventManager* manager = soEventSystem::getInstance()->getManager(params->getManagerID());
    if (manager->getObserverCapacity(params->eventID) == 0) {
        params->cache = 0;
        return false;
    }
    params->cache = getObserverList(params);
    return params->cache != 0;
}
extern "C" void fn_27_6B66C(void* object, int manageID, u32 key, int arg3) {
    Node* node = (Node*)((utList*)((char*)object + 0x14))->getNode(0);
    while (node != 0) {
        Node* next = node->next;
        if ((manageID == -1 || manageID == (int)((UnitData*)node->data)->id) && key == node->key) {
            int id = ((UnitData*)node->data)->id;
            Presenter* presenter = fn_27_6F30C(node);
            short managerID = presenter->moduleAccessor->moduleRoot->callback->object.slot7();
            EventParams params;
            *(void**)&params = lbl_27_data_7BA0;
            params.managerID = managerID;
            params.eventID = 7;
            params.cache = 0;
            if (managerID > 0 && managerID > -1) {
                if (soEventSystem::getInstance()->getInstanceManager().isContain(managerID)) {
                    soEventManager* manager = soEventSystem::getInstance()->getManager(params.managerID);
                    if (manager->getObserverCapacity(params.eventID) == 0) {
                        params.cache = 0;
                    } else {
                        soEventManager* manager2;
                        short eid = params.eventID;
                        manager2 = soEventSystem::getInstance()->getManager(params.managerID);
                        ObserverList* result;
                        if (manager2->getObserverCapacity(eid) == 0)
                            result = 0;
                        else
                            result = getUnit(manager2, eid);
                        params.cache = result;
                    }
                }
            }
            *(void**)&params = lbl_27_data_7B68;
            void* owner = *(void**)((char*)object + 0x44);
            void* ownerValue = *(void**)((char*)owner + 8);
            void* presenterOwner = presenter->moduleAccessor;
            ObserverList* list;
            if (params.managerID <= -1) {
                list = (ObserverList*)lbl_27_bss_B40;
            } else if (!(params.cache || updateCache(&params))) {
                list = (ObserverList*)lbl_27_bss_B40;
            } else {
                soEventManager* manager = soEventSystem::getInstance()->getManager(params.managerID);
                if (manager->getObserverCapacity(params.eventID) == 0) {
                    params.cache = 0;
                    list = (ObserverList*)lbl_27_bss_B40;
                } else {
                    list = params.cache;
                }
            }
            for (int j = 0; j < list->size(); ++j) {
                Observer* observer = *list->get(j);
                observer->notify(arg3, presenterOwner, ownerValue, id);
            }
        }
        node = next;
    }
}
