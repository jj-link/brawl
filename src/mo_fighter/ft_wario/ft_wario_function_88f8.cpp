#include <ac/ac_cmd_interpreter.h>
#include <so/anim/so_anim_cmd_event_presenter.h>
#include <so/event/so_event_system.h>
#include <types.h>
#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on
extern "C" {
extern char lbl_110_data_2094[], lbl_110_data_208C[], lbl_110_data_20EC[], lbl_27_data_81A0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
struct WarioCmdInterpreter {
    acCmdInterpreter base;
    void* presenterVtable;
    short managerId;
    short unitId;
    void* observerList;
    int argument, field44, field48, field4C;
};
extern "C" WarioCmdInterpreter* fn_110_88F8(WarioCmdInterpreter* obj, short id,
    soArrayVector<acCmdInterpreterStackData, 8>* stack, int argument, int mode,
    const u8* reset, float step)
{
    WarioCmdInterpreter* self = obj;
    void* list;
    soEventManager* mgr;

    new (self) acCmdInterpreter(stack, mode, 0, reset, step);
    self->presenterVtable = lbl_110_data_2094;
    self->managerId = id;
    self->unitId = 5;
    list = 0;
    self->observerList = list;

    s32 idv = (s32)id;
    if (idv > 0 && (s16)idv > -1) {
        s16 manage = self->managerId;
        if (soEventSystem::getInstance()->getInstanceManager().isContain(manage)) {
            if (soEventSystem::getInstance()->getManager(self->managerId)->getObserverCapacity(self->unitId) == 0) {
                self->observerList = list;
            } else {
                short unit = self->unitId;
                mgr = soEventSystem::getInstance()->getManager(self->managerId);
                if (mgr->getObserverCapacity(unit) == 0) {
                    list = 0;
                } else {
                    soEventUnitWrapper<soAnimCmdEventObserver>* wrapper =
                        (soEventUnitWrapper<soAnimCmdEventObserver>*)__dynamic_cast(
                            mgr->getEventUnit(unit), 0, lbl_110_data_208C, lbl_110_data_20EC, 0);
                    if (wrapper == 0)
                        list = 0;
                    else
                        list = wrapper->getObserverListSub();
                }
                self->observerList = list;
            }
        }
    }
    *(void**)&self->base = lbl_27_data_81A0;
    self->presenterVtable = lbl_27_data_81A0 + 0x20;
    self->argument = argument;
    self->field44 = 0;
    self->field48 = 0;
    self->field4C = 0;
    return self;
}
