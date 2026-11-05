#include <so/collision/so_collision_shield_event_presenter_reflector.h>
#pragma force_active on

extern "C" {
extern char lbl_27_bss_C00[];
extern char lbl_27_data_4118[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

typedef soInstanceManagerFullProperty<soCollisionReflectorEventObserver*> ObserverList;
struct Presenter {
    char pad[8];
    short id1;
    short id2;
    ObserverList* cached;
};

extern "C" void fn_27_47D0C(Presenter* self, soCollisionAttackModule* arg1, soCollisionLog* arg2, unsigned long arg3, soModuleAccesser* arg4, float f1, float f2, float f3) {
    soEventManager* mgr;
    int i;
    ObserverList* list;
    short id1;
    short id2;
    ObserverList* cur;
    soEventUnitWrapper<soCollisionReflectorEventObserver>* unit;
    int flag;

    id1 = self->id1;
    if (id1 <= -1) {
        list = (ObserverList*)lbl_27_bss_C00;
        goto LOOP;
    }
    if (self->cached != 0) {
        goto C;
    }
    if (id1 <= -1 || soEventSystem::getInstance()->getInstanceManager().isContain(id1) == 0) {
        flag = 0;
        goto CHECK;
    }
    if (soEventSystem::getInstance()->getManager(self->id1)->getObserverCapacity(self->id2) == 0) {
        self->cached = 0;
        flag = 0;
        goto CHECK;
    }
    id2 = self->id2;
    mgr = soEventSystem::getInstance()->getManager(self->id1);
    if (mgr->getObserverCapacity(id2) == 0) {
        cur = 0;
    } else {
        unit = (soEventUnitWrapper<soCollisionReflectorEventObserver>*)__dynamic_cast(mgr->getEventUnit(id2), 0, lbl_27_data_4118, __RTTI__11soEventUnit, 0);
        if (unit == 0) {
            cur = 0;
        } else {
            cur = unit->getObserverListSub();
        }
    }
    self->cached = cur;
    flag = (cur != 0);
CHECK:
    if (flag == 0) {
        list = (ObserverList*)lbl_27_bss_C00;
        goto LOOP;
    }
C:
    mgr = soEventSystem::getInstance()->getManager(self->id1);
    if (mgr->getObserverCapacity(self->id2) == 0) {
        self->cached = 0;
        list = (ObserverList*)lbl_27_bss_C00;
    } else {
        list = self->cached;
    }
LOOP:
    for (i = 0; i < (int)list->size(); i++) {
        soCollisionReflectorEventObserver** p = &list->atIndex(i);
        (*p)->notifyEventCollisionReflector(arg1, arg2, arg3, arg4, f1, f2, f3);
    }
}
