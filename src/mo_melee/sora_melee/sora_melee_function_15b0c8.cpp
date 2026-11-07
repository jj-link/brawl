#include <so/event/so_event_system.h>
#pragma force_active on
extern "C" {
extern char lbl_27_data_26440[];
extern char lbl_27_bss_3168[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, long);
}
struct EventSystemView {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
virtual void v4(); virtual void v5(); virtual int isManagerValid(short);
};
struct ManagerView {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
virtual int isEventValid(int); virtual void v5(); virtual void v6(); virtual void v7();
virtual void* getEvent(int);
};
struct List;
struct UnitView {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
virtual void v4(); virtual void v5(); virtual void v6(); virtual List* getList();
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
virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
virtual void v36(); virtual void v37(); virtual void invoke(int);
};
struct List {
virtual void v0(); virtual void v1(); virtual Element** get(int);
virtual void v3(); virtual int size();
};
class ftOutsideEventPresenter {
public:
void* vtable; short managerId; short eventId; List* cachedList; int value;
void notifyOutsideEventKnockout();
};
inline List* selectList(ftOutsideEventPresenter* self) {
short managerId;
short eventId;
ManagerView* manager;
List* current;
List* selected;
UnitView* unit;
int valid;
managerId = self->managerId;
if (managerId <= -1) { selected = (List*)lbl_27_bss_3168; goto LOOP; }
if (self->cachedList != 0) goto CHECK_CACHE;
if (managerId <= -1 || ((EventSystemView*)soEventSystem::getInstance())->isManagerValid(managerId) == 0) {
valid = 0; goto CHECK_VALID;
}
if (((ManagerView*)soEventSystem::getInstance()->getManager(self->managerId))->isEventValid(self->eventId) == 0) {
self->cachedList = 0; valid = 0; goto CHECK_VALID;
}
eventId = self->eventId;
manager = (ManagerView*)soEventSystem::getInstance()->getManager(self->managerId);
if (manager->isEventValid(eventId) == 0) current = 0;
else {
unit = (UnitView*)__dynamic_cast(manager->getEvent(eventId), 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
if (unit == 0) current = 0;
else current = unit->getList();
}
self->cachedList = current;
valid = (current != 0);
CHECK_VALID:
if (valid == 0) { selected = (List*)lbl_27_bss_3168; goto LOOP; }
CHECK_CACHE:
manager = (ManagerView*)soEventSystem::getInstance()->getManager(self->managerId);
if (manager->isEventValid(self->eventId) == 0) {
self->cachedList = 0; selected = (List*)lbl_27_bss_3168;
} else selected = self->cachedList;
LOOP:
return selected;
}
void ftOutsideEventPresenter::notifyOutsideEventKnockout() {
List* list = selectList(this);
int count = list->size();
for (int i = 0; i < count; i++) {
Element** element = list->get(i);
(*element)->invoke(value);
}
}