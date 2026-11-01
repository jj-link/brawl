#pragma force_active on

struct Target {
    virtual void t0();
    virtual void t1();
    virtual void t2();
    virtual void t3();
    virtual void t4();
    virtual void t5();
    virtual void t6();
    virtual void t7();
    virtual void t8();
    virtual void t9();
    virtual void t10(int, void*, void*, int);
};

struct EventList {
    virtual void l0();
    virtual void l1();
    virtual Target** l2(int);
    virtual void l3();
    virtual int l4();
};

struct UnitListAccess {
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual EventList* u7();
};

struct EventManager {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual int m4(short);
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void* m8(short);
};

struct EventSystem {
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual int e8(short);
};

struct EventObject {
    char pad[4];
    short eventID;
    short unitID;
    EventList* cache;
    int value;
};

extern "C" {
extern EventList lbl_27_bss_3168;
extern char lbl_27_data_26440[];
extern char __RTTI__11soEventUnit[];

void* __dynamic_cast(void*, long, const void*, const void*, long);
EventSystem* getInstance__13soEventSystemFv();
EventManager* getManager__13soEventSystemFl(EventSystem*, long);

void fn_27_158104(EventObject* self, void* arg1, void* arg2, int arg3) {
    EventManager* manager;
    short unitID;
    short eventID = self->eventID;
    EventList* current;
    int valid;
    EventList* list;

    if (eventID <= -1) {
        list = &lbl_27_bss_3168;
        goto LOOP;
    }

    if (self->cache == 0) {
        if (eventID <= -1 ||
            getInstance__13soEventSystemFv()->e8(eventID) == 0) {
            valid = 0;
        } else if (getManager__13soEventSystemFl(
                       getInstance__13soEventSystemFv(),
                       self->eventID)->m4(self->unitID) == 0) {
            self->cache = 0;
            valid = 0;
        } else {
            unitID = self->unitID;
            manager = getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), self->eventID);
            if (manager->m4(unitID) == 0) {
                current = 0;
            } else {
                UnitListAccess* unit = (UnitListAccess*)__dynamic_cast(
                    manager->m8(unitID), 0, lbl_27_data_26440,
                    __RTTI__11soEventUnit, 0);
                if (unit == 0)
                    current = 0;
                else
                    current = unit->u7();
            }
            self->cache = current;
            valid = current != 0;
        }

        if (valid == 0) {
            list = &lbl_27_bss_3168;
            goto LOOP;
        }
    }

    manager = getManager__13soEventSystemFl(
        getInstance__13soEventSystemFv(), self->eventID);
    if (manager->m4(self->unitID) == 0) {
        self->cache = 0;
        list = &lbl_27_bss_3168;
    } else {
        list = self->cache;
    }

LOOP:
    {
        EventList* selected = list;
        int count = selected->l4();
        for (int i = 0; i < count; i++) {
            Target* target = *selected->l2(i);
            target->t10(self->value, arg1, arg2, arg3);
        }
    }
}
}
