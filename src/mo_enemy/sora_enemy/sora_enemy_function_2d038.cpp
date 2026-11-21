#include <so/event/so_event_system.h>
#pragma force_active on

class soAnimCmdEventObserver {
public:
    virtual void addObserver();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void fn_41_12100();
    virtual void fn_41_13608();
    virtual void fn_41_13600();
    virtual void fn_41_135BC();
};

class Class_6E20 {
public:
    virtual void fn_41_3516C();
    virtual void fn_41_34F30();
    virtual void fn_41_350A4();
    virtual void fn_41_350AC();
    virtual void fn_41_350B4();
    virtual void fn_41_350BC();
    virtual void fn_41_350DC();
    virtual void fn_41_350C4();
    virtual void fn_41_35120();
};

extern "C" {
extern void* __vt__10soNullable[];
extern char lbl_41_data_400C[];
extern char lbl_41_data_4004[];
extern char lbl_41_data_1560[];
extern char lbl_41_data_3F20[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct Object {
    void* vtable;
    bool isNull;
    char pad5[3];
    void* presenterVtable;
    short manageID;
    short unitID;
    void* observerList;
    void* observerVtable;
    bool flag;
    char pad19[3];
    int value;
    int pad20;
    int argument;
};

inline void* getList(short manageID, short unitID) {
    soEventManager* manager = soEventSystem::getInstance()->getManager(manageID);
    if (!manager->getObserverCapacity(unitID))
        return 0;
    soEventUnitWrapper<soAnimCmdEventObserver>* unit =
        (soEventUnitWrapper<soAnimCmdEventObserver>*)__dynamic_cast(
            manager->getEventUnit(unitID), 0,
            lbl_41_data_4004, lbl_41_data_1560, 0);
    const bool missing = unit == 0;
    if (missing)
        return 0;
    return unit->getObserverListSub();
}

inline bool checkManageId(Object* self) {
    const short id = self->manageID;
    return soEventSystem::getInstance()->getInstanceManager().isContain(id);
}

inline void initialize(Object* self, short manageID, short unitID) {
    self->vtable = __vt__10soNullable;
    self->isNull = false;
    self->presenterVtable = lbl_41_data_400C;
    self->manageID = manageID;
    self->unitID = unitID;
    self->observerList = 0;
    if (self->manageID > 0) {
        if (self->manageID > -1 && checkManageId(self)) {
            if (!soEventSystem::getInstance()->getManager(self->manageID)->getObserverCapacity(self->unitID))
                self->observerList = 0;
            else {
                short unitID = self->unitID;
                self->observerList = getList(self->manageID, unitID);
            }
        }
    }
}

extern "C" Object* fn_41_2D038(Object* self, int argument) {
    initialize(self, -1, 11);
    self->flag = false;
    self->vtable = lbl_41_data_3F20;
    self->presenterVtable = lbl_41_data_3F20 + 0xC;
    self->observerVtable = lbl_41_data_3F20 + 0x94;
    self->value = 0;
    self->argument = argument;
    return self;
}
