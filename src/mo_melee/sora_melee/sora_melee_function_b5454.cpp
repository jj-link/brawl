#pragma force_active on

#include <types.h>
#include <so/event/so_event_system.h>

extern "C" {
extern char lbl_27_bss_C60[];
extern char lbl_27_data_52F0[];
extern char __RTTI__11soEventUnit[];

void* __dynamic_cast(void*, long, const void*, const void*, long);
}

struct Observer {
    virtual void v0();
    virtual void invoke(int, int, void*);
};

struct List {
    virtual void v0();
    virtual void v1();
    virtual Observer** get(int);
    virtual void v3();
    virtual int size();
};

struct Unit {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual List* getList();
};

struct Value {
    virtual void v0();
    virtual void v1();
    virtual int get();
    virtual void set(int);
};

struct Inner {
    char pad[0x28];
    void* value;
};

struct Outer {
    char pad[8];
    Inner* inner;
};

struct Self {
    char pad[0x20];
    Outer* outer;
    Value* current;
    void* unused;
    Value* other;
    char pad30[8];
    short managerId;
    short eventId;
    List* cached;
};

extern "C" void fn_27_B5454(Self* self, int value, unsigned int notify) {
    void* context;
    int i;
    List* sel;
    short evId;
    soEventManager* mgr;
    Unit* unit;
    List* cur;
    int flag;
    int old;
    s32 id;

    if (value != self->current->get()) {
        old = self->current->get();
        self->current->set(value);
        self->other->set(value);

        if (notify == 1) {
            context = self->outer->inner->value;

            id = self->managerId;
            if (id <= -1) {
                sel = (List*)lbl_27_bss_C60;
                goto LOOP;
            }
            if (self->cached != 0) {
                goto CHECK_CACHE;
            }
            if (id <= -1 ||
                !soEventSystem::getInstance()->getInstanceManager().isContain(id)) {
                flag = 0;
                goto CHECK_VALID;
            }
            if (soEventSystem::getInstance()
                    ->getManager(self->managerId)
                    ->getObserverCapacity(self->eventId) == 0) {
                self->cached = 0;
                flag = 0;
                goto CHECK_VALID;
            }

            evId = self->eventId;
            mgr = soEventSystem::getInstance()->getManager(self->managerId);
            if (mgr->getObserverCapacity(evId) == 0) {
                cur = 0;
            } else {
                unit = (Unit*)__dynamic_cast(
                    mgr->getEventUnit(evId), 0, lbl_27_data_52F0,
                    __RTTI__11soEventUnit, 0);
                if (unit == 0) {
                    cur = 0;
                } else {
                    cur = unit->getList();
                }
            }

            self->cached = cur;
            flag = (cur != 0);

CHECK_VALID:
            if (flag != 0) {
                goto CHECK_CACHE;
            }
            sel = (List*)lbl_27_bss_C60;
            goto LOOP;

CHECK_CACHE:
            mgr = soEventSystem::getInstance()->getManager(self->managerId);
            if (mgr->getObserverCapacity(self->eventId) == 0) {
                self->cached = 0;
                sel = (List*)lbl_27_bss_C60;
            } else {
                sel = self->cached;
            }

LOOP:
            for (i = 0; i < sel->size(); i++) {
                (*sel->get(i))->invoke(value, old, context);
            }
        }
    }
}
