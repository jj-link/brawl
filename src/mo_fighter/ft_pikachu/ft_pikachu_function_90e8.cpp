#include <new>
#include <ac/ac_cmd_interpreter.h>
#include <so/anim/so_anim_cmd_event_presenter.h>
#include <so/event/so_event_system.h>
#include <types.h>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern u8 lbl_98_data_2EF0[];
extern u8 lbl_98_data_2EE8[];
extern u8 lbl_98_data_2F48[];
extern u8 lbl_27_data_81A0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct Self {
    u8 base[0x34];
    void* presenterVt;
    s16 manageID;
    s16 unitID;
    soInstanceManagerFullProperty<soAnimCmdEventObserver*>* obsrvrList;
    void* arg;
    s32 f44;
    s32 f48;
    s32 f4c;

    inline void initBase(soArrayVector<acCmdInterpreterStackData, 8>* stk, s32 mode,
                         const u8* reset, f32 step) {
        new (this) acCmdInterpreter(stk, mode, 0, reset, step);
    }
};

extern "C" Self* fn_98_90E8(Self* self, s16 id, soArrayVector<acCmdInterpreterStackData, 8>* stack,
                            void* arg, s32 mode, const u8* reset, f32 step)
{
    soInstanceManagerFullProperty<soAnimCmdEventObserver*>* list;

    self->initBase(stack, mode, reset, step);
    self->presenterVt = lbl_98_data_2EF0;
    self->manageID = id;
    self->unitID = 5;
    list = NULL;
    self->obsrvrList = list;

    s32 idx = id;
    if (id > 0 && (s16)idx > -1) {
        s16 check = self->manageID;
        if (soEventSystem::getInstance()->getInstanceManager().isContain(check)) {
            if (soEventSystem::getInstance()->getManager(self->manageID)
                    ->getObserverCapacity(self->unitID) == 0) {
                self->obsrvrList = list;
            } else {
                soEventManager* mgr;
                s16 unitID = self->unitID;
                mgr = soEventSystem::getInstance()->getManager(self->manageID);
                if (mgr->getObserverCapacity(unitID) == 0) {
                    list = NULL;
                } else {
                    soEventUnitWrapper<soAnimCmdEventObserver>* w =
                        reinterpret_cast<soEventUnitWrapper<soAnimCmdEventObserver>*>(
                            __dynamic_cast(mgr->getEventUnit(unitID), 0,
                                           lbl_98_data_2EE8, lbl_98_data_2F48, 0));
                    if (w == NULL) {
                        list = NULL;
                    } else {
                        list = w->getObserverListSub();
                    }
                }
                self->obsrvrList = list;
            }
        }
    }

    *(void**)self = lbl_27_data_81A0;
    self->presenterVt = lbl_27_data_81A0 + 0x20;
    self->arg = arg;
    self->f44 = 0;
    self->f48 = 0;
    self->f4c = 0;
    return self;
}
