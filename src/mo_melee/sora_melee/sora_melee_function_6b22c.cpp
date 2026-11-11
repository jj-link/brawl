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
struct Node { Node* next; char pad4[8]; void* data; };
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
struct Work { EventParams params; Node* selected[64]; };
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
extern "C" void fn_27_6B22C(void* object, int eventID, int arg2, int mask) {
    void* presenterOwner;
    int id;
    void* ownerValue;
    Node** entry;
    int count;
    int i;
    Work work;
    Node* node = (Node*)((utList*)((char*)object + 0x14))->getNode(0);
    if (node == 0) return;
    count = 0;
    if (eventID == -1) {
        Node** out = work.selected;
        while (node != 0) {
            if (mask == 0 || (mask & (((UnitData*)node->data)->flags >> 8))) {
                ++count;
                *out++ = node;
                if (count >= 64) break;
            }
            node = node->next;
        }
    } else {
        Node** out = work.selected;
        while (node != 0) {
            UnitData* data = (UnitData*)node->data;
            if ((eventID == (int)data->id && mask == 0) ||
                (mask & data->attributes)) {
                ++count;
                *out++ = node;
                if (count >= 64) break;
            }
            node = node->next;
        }
    }
    entry = work.selected;
    for (i = 0; i < count; ++entry, ++i) {
        Node* current = *entry;
        u32 flags = ((UnitData*)current->data)->flags;
        if ((flags & 1) == 0) continue;
        id = (flags >> 1) & 0x7f;
        Presenter* presenter = fn_27_6F30C(current);
        short managerID = presenter->moduleAccessor->moduleRoot->callback->object.slot7();
        work.params.vtable = lbl_27_data_7BA0;
        work.params.managerID = managerID;
        work.params.eventID = 7;
        work.params.cache = 0;
        if (managerID > 0 && managerID > -1) {
            if (soEventSystem::getInstance()->getInstanceManager().isContain(managerID)) {
                soEventManager* manager = soEventSystem::getInstance()->getManager(work.params.managerID);
                if (manager->getObserverCapacity(work.params.eventID) == 0) {
                    work.params.cache = 0;
                } else {
                    soEventManager* manager2;
                    short id = work.params.eventID;
                    manager2 = soEventSystem::getInstance()->getManager(work.params.managerID);
                    ObserverList* result;
                    if (manager2->getObserverCapacity(id) == 0)
                        result = 0;
                    else
                        result = getUnit(manager2, id);
                    work.params.cache = result;
                }
            }
        }
        work.params.vtable = lbl_27_data_7B68;
        void* owner = *(void**)((char*)object + 0x44);
        ownerValue = *(void**)((char*)owner + 8);
        presenterOwner = presenter->moduleAccessor;
        ObserverList* list;
        if (work.params.managerID <= -1) {
            list = (ObserverList*)lbl_27_bss_B40;
        } else if (!(work.params.cache || updateCache(&work.params))) {
            list = (ObserverList*)lbl_27_bss_B40;
        } else {
            soEventManager* manager = soEventSystem::getInstance()->getManager(work.params.managerID);
            if (manager->getObserverCapacity(work.params.eventID) == 0) {
                work.params.cache = 0;
                list = (ObserverList*)lbl_27_bss_B40;
            } else {
                list = work.params.cache;
            }
        }
        for (int j = 0; j < list->size(); ++j) {
            Observer* observer = *list->get(j);
            observer->notify(arg2, presenterOwner, ownerValue, id);
        }
    }
}