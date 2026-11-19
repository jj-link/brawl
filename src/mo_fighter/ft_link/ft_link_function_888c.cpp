#include <ac/ac_cmd_interpreter.h>
#include <so/event/so_event_system.h>
#include <so/event/so_event_presenter.h>
#include <so/anim/so_anim_cmd_event_presenter.h>
#include <types.h>
#include <new>

#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_93_data_3B60[];
extern char lbl_93_data_3B58[];
extern char lbl_93_data_3BB8[];
extern char lbl_27_data_81A0[];
}

class EventUnitWrapper {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual soInstanceManagerFullProperty<soAnimCmdEventObserver*>* getObserverListSub();
};

struct Obj {
    char pad[0x34];
    void* vptr34;
    s16 manageID;
    s16 unitID;
    soInstanceManagerFullProperty<soAnimCmdEventObserver*>* obsList;
    void* owner;
    s32 unk44;
    s32 unk48;
    s32 unk4c;
};

extern "C" acCmdInterpreter* fn_93_888C(acCmdInterpreter* self, s16 manageId,
    soArrayVector<acCmdInterpreterStackData, 8>* stack, void* owner, s32 mode,
    const u8* reset, float fixedTimeStep)
{
    Obj* p = reinterpret_cast<Obj*>(self);
    soInstanceManagerFullProperty<soAnimCmdEventObserver*>* list;
    soEventManager* mgr;
    s32 manage;

    new (self) acCmdInterpreter(stack, mode, 0, reset, fixedTimeStep);

    p->vptr34 = lbl_93_data_3B60;
    p->manageID = manageId;
    p->unitID = 5;
    list = 0;
    p->obsList = list;

    manage = manageId;
    if (manageId > 0 && (s16)manage > -1) {
        s16 id = p->manageID;
        if (soEventSystem::getInstance()->getInstanceManager().isContain(id)) {
            if (soEventSystem::getInstance()->getManager(p->manageID)->getObserverCapacity(p->unitID) == 0) {
                p->obsList = list;
            } else {
                s16 unit = p->unitID;
                mgr = soEventSystem::getInstance()->getManager(p->manageID);
                if (mgr->getObserverCapacity(unit) == 0) {
                    list = 0;
                } else {
                    EventUnitWrapper* w = reinterpret_cast<EventUnitWrapper*>(
                        __dynamic_cast(mgr->getEventUnit(unit), 0, lbl_93_data_3B58, lbl_93_data_3BB8, 0));
                    if (w == 0) {
                        list = 0;
                    } else {
                        list = w->getObserverListSub();
                    }
                }
                p->obsList = list;
            }
        }
    }

    *(void**)self = lbl_27_data_81A0;
    p->vptr34 = lbl_27_data_81A0 + 0x20;
    p->owner = owner;
    p->unk44 = 0;
    p->unk48 = 0;
    p->unk4c = 0;
    return self;
}
