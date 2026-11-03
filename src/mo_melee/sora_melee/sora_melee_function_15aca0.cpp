#pragma force_active on
#include <so/event/so_event_system.h>
extern "C" {
extern char lbl_27_bss_3168[];
extern char lbl_27_data_26440[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, long);
}
struct EventSystemView {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual int isManagerValid(short);
};
struct ManagerView {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual int isEventValid(int);
    virtual void v5(); virtual void v6(); virtual void v7();
    virtual void* getEvent(int);
};
struct UnitView {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void* getList();
};
struct Element;
struct List {
    virtual void v0(); virtual void v1(); virtual Element** get(int);
    virtual void v3(); virtual int size();
};
struct Element {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void invoke(int);
};
struct Self {
    void* vtable; short managerId; short eventId; void* cachedList; int value;
};
extern "C" {
inline List* selectList(Self* self) {
    short managerId;
    short eventId;
    ManagerView* manager;
    List* current;
    List* selected;
    UnitView* unit;
    int valid;
    managerId = self->managerId;
    if (managerId <= -1) {
        selected = (List*)lbl_27_bss_3168;
        goto LOOP;
    }
    if (self->cachedList != 0) goto CHECK_CACHE;
    if (managerId <= -1 ||
        ((EventSystemView*)soEventSystem::getInstance())->isManagerValid(managerId) == 0) {
        valid = 0;
        goto CHECK_VALID;
    }
    if (((ManagerView*)soEventSystem::getInstance()->getManager(self->managerId))
            ->isEventValid(self->eventId) == 0) {
        self->cachedList = 0;
        valid = 0;
        goto CHECK_VALID;
    }
    eventId = self->eventId;
    manager = (ManagerView*)soEventSystem::getInstance()->getManager(self->managerId);
    if (manager->isEventValid(eventId) == 0) {
        current = 0;
    } else {
        unit = (UnitView*)__dynamic_cast(manager->getEvent(eventId), 0,
            lbl_27_data_26440, __RTTI__11soEventUnit, 0);
        if (unit == 0) current = 0;
        else current = (List*)unit->getList();
    }
    self->cachedList = current;
    valid = (current != 0);
CHECK_VALID:
    if (valid == 0) {
        selected = (List*)lbl_27_bss_3168;
        goto LOOP;
    }
CHECK_CACHE:
    manager = (ManagerView*)soEventSystem::getInstance()->getManager(self->managerId);
    if (manager->isEventValid(self->eventId) == 0) {
        self->cachedList = 0;
        selected = (List*)lbl_27_bss_3168;
    } else {
        selected = (List*)self->cachedList;
    }
LOOP:
    return selected;
}
void fn_27_15ACA0(Self* self) {
    List* list = selectList(self);
    int count = list->size();
    for (int i = 0; i < count; i++) {
        Element** element = list->get(i);
        (*element)->invoke(self->value);
    }
}
}