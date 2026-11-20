#include <types.h>
#include <ac/ac_cmd_interpreter.h>
#include <so/anim/so_anim_cmd_event_presenter.h>
#include <so/event/so_event_presenter.h>
#include <so/event/so_event_system.h>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern char lbl_116_data_2C68[];
extern char lbl_116_data_2C60[];
extern char lbl_116_data_2CC0[];
extern char lbl_27_data_81A0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

class MgrSlots {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual bool isExist(s16 id);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual soEventUnit* getEventUnit(s16 id);
};

class UnitSlots {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual soInstanceManagerFullProperty<soAnimCmdEventObserver*>* getObserverListSub();
    virtual void slot8();
};

extern "C" void* fn_116_8FE8(void* self, s16 manageID,
                             soArrayVector<acCmdInterpreterStackData, 8>* stk,
                             s32 arg0x40, s32 mode, const u8* resetMode, float fixedTimeStep)
{
    char* p = static_cast<char*>(self);
    new (self) acCmdInterpreter(stk, mode, NULL, resetMode, fixedTimeStep);
    *reinterpret_cast<void**>(p + 0x34) = lbl_116_data_2C68;
    *reinterpret_cast<s16*>(p + 0x38) = manageID;
    *reinterpret_cast<s16*>(p + 0x3A) = 5;
    soInstanceManagerFullProperty<soAnimCmdEventObserver*>* obsrvrList = NULL;
    *reinterpret_cast<void**>(p + 0x3C) = obsrvrList;

    s32 idx = manageID;
    if (manageID > 0 && (s16)idx > -1) {
        s16 check = *reinterpret_cast<s16*>(p + 0x38);
        if (soEventSystem::getInstance()->getInstanceManager().isContain(check)) {
            if (!reinterpret_cast<MgrSlots*>(
                    soEventSystem::getInstance()->getManager(*reinterpret_cast<s16*>(p + 0x38)))
                    ->isExist(*reinterpret_cast<s16*>(p + 0x3A))) {
                *reinterpret_cast<void**>(p + 0x3C) = obsrvrList;
            } else {
                MgrSlots* mgr;
                s16 unitID = *reinterpret_cast<s16*>(p + 0x3A);
                mgr = reinterpret_cast<MgrSlots*>(
                    soEventSystem::getInstance()->getManager(*reinterpret_cast<s16*>(p + 0x38)));
                if (!mgr->isExist(unitID)) {
                    obsrvrList = NULL;
                } else {
                    UnitSlots* unit = reinterpret_cast<UnitSlots*>(
                        __dynamic_cast(mgr->getEventUnit(unitID), 0,
                                       lbl_116_data_2C60, lbl_116_data_2CC0, 0));
                    if (unit == NULL) {
                        obsrvrList = NULL;
                    } else {
                        obsrvrList = unit->getObserverListSub();
                    }
                }
                *reinterpret_cast<void**>(p + 0x3C) = obsrvrList;
            }
        }
    }

    *reinterpret_cast<void**>(p) = lbl_27_data_81A0;
    *reinterpret_cast<void**>(p + 0x34) = lbl_27_data_81A0 + 0x20;
    *reinterpret_cast<s32*>(p + 0x40) = arg0x40;
    *reinterpret_cast<s32*>(p + 0x44) = 0;
    *reinterpret_cast<s32*>(p + 0x48) = 0;
    *reinterpret_cast<s32*>(p + 0x4C) = 0;
    return self;
}