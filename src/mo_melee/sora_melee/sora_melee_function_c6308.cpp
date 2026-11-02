#pragma force_active on

#include <so/event/so_event_system.h>

extern "C" {
extern char __RTTI__11soEventUnit[];
extern char lbl_27_data_18418[];
extern char lbl_27_bss_D60[];

void* __dynamic_cast(void*, long, const void*, const void*, long);
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
}

struct Observer {
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void call(s32, s32, s32, s32);
};

struct ObserverList {
    virtual void a0();
    virtual void a1();
    virtual Observer** at(s32);
    virtual void a3();
    virtual s32 size();
};

struct EventUnit {
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual ObserverList* getList();
};

struct EventManager {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 isExist(s16);
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void* getUnit(s16);
};

struct EventSystem {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual s32 isManagerExist(s16);
};

struct Self {
    char pad[4];
    s16 managerID;
    s16 eventID;
    ObserverList* cachedList;
};

inline ObserverList* selectList(Self* self) {
    s16 managerID;
    s16 eventID;
    EventManager* manager;
    ObserverList* cur;
    EventUnit* unit;
    ObserverList* list;
    s32 flag;

    managerID = self->managerID;
    if (managerID <= -1) {
        list = (ObserverList*)lbl_27_bss_D60;
        goto LOOP;
    }

    if (self->cachedList != 0) {
        goto C;
    }

    if (managerID <= -1 ||
        ((EventSystem*)getInstance__13soEventSystemFv())
                ->isManagerExist(managerID) == 0) {
        flag = 0;
        goto CHECK;
    }

    if (((EventManager*)getManager__13soEventSystemFl(
             getInstance__13soEventSystemFv(), self->managerID))
            ->isExist(self->eventID) == 0) {
        self->cachedList = 0;
        flag = 0;
        goto CHECK;
    }

    eventID = self->eventID;
    manager = (EventManager*)getManager__13soEventSystemFl(
        getInstance__13soEventSystemFv(), self->managerID
    );

    if (manager->isExist(eventID) == 0) {
        cur = 0;
    } else {
        unit = (EventUnit*)__dynamic_cast(
            manager->getUnit(eventID), 0, lbl_27_data_18418,
            __RTTI__11soEventUnit, 0
        );
        if (unit == 0) {
            cur = 0;
        } else {
            cur = unit->getList();
        }
    }

    self->cachedList = cur;
    flag = (cur != 0);

CHECK:
    if (flag == 0) {
        list = (ObserverList*)lbl_27_bss_D60;
        goto LOOP;
    }

C:
    manager = (EventManager*)getManager__13soEventSystemFl(
        getInstance__13soEventSystemFv(), self->managerID
    );

    if (manager->isExist(self->eventID) == 0) {
        self->cachedList = 0;
        list = (ObserverList*)lbl_27_bss_D60;
    } else {
        list = self->cachedList;
    }

LOOP:
    return list;
}

extern "C" void fn_27_C6308(
    Self* self, s32 arg1, s32 arg2, s32 arg3, s32 arg4
) {
    ObserverList* list = selectList(self);
    s32 i;
    s32 n = list->size();

    for (i = 0; i < n; ++i) {
        Observer** p = list->at(i);
        (*p)->call(arg1, arg2, arg3, arg4);
    }
}
