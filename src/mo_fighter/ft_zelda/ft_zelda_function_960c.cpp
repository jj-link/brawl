#include <ac/ac_cmd_interpreter.h>
#include <so/event/so_event_system.h>
#include <types.h>
#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual int slot7();
    virtual void slot8();
};

extern "C" {
extern u8 lbl_104_data_2E3C[];
extern u8 lbl_104_data_2E44[];
extern u8 lbl_104_data_2E9C[];
extern u8 lbl_27_data_81A0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" acCmdInterpreter* fn_104_960C(acCmdInterpreter* self, s16 id,
    soArrayVector<acCmdInterpreterStackData, 8>* stk, s32 arg3, s32 arg4,
    const u8* arg5, float arg6)
{
    u8* p = reinterpret_cast<u8*>(self);
    s32 saved = arg3;

    new (self) acCmdInterpreter(stk, arg4, 0, arg5, arg6);
    *reinterpret_cast<u8**>(p + 0x34) = lbl_104_data_2E44;
    *reinterpret_cast<s16*>(p + 0x38) = id;
    *reinterpret_cast<s16*>(p + 0x3A) = 5;
    s32 r31 = 0;
    *reinterpret_cast<s32*>(p + 0x3C) = r31;

    s32 idx = id;
    if (id > 0 && (s16)idx > -1) {
        s16 check = *reinterpret_cast<s16*>(p + 0x38);
        if (soEventSystem::getInstance()->getInstanceManager().isContain(check)) {
            soEventManager* mgr = soEventSystem::getInstance()->getManager(*reinterpret_cast<s16*>(p + 0x38));
            if (mgr->getObserverCapacity(*reinterpret_cast<s16*>(p + 0x3A)) == 0) {
                *reinterpret_cast<s32*>(p + 0x3C) = r31;
            } else {
                soEventManager* mgr2;
                s16 r29 = *reinterpret_cast<s16*>(p + 0x3A);
                mgr2 = soEventSystem::getInstance()->getManager(*reinterpret_cast<s16*>(p + 0x38));
                if (mgr2->getObserverCapacity(r29) == 0) {
                    r31 = 0;
                } else {
                    void* unit = mgr2->getEventUnit(r29);
                    void* q = __dynamic_cast(unit, 0, lbl_104_data_2E3C, lbl_104_data_2E9C, 0);
                    if (q == 0) {
                        r31 = 0;
                    } else {
                        r31 = reinterpret_cast<Object_vptr_0*>(q)->slot7();
                    }
                }
                *reinterpret_cast<s32*>(p + 0x3C) = r31;
            }
        }
    }

    *reinterpret_cast<u8**>(p) = lbl_27_data_81A0;
    *reinterpret_cast<u8**>(p + 0x34) = lbl_27_data_81A0 + 0x20;
    *reinterpret_cast<s32*>(p + 0x40) = saved;
    *reinterpret_cast<s32*>(p + 0x44) = 0;
    *reinterpret_cast<s32*>(p + 0x48) = 0;
    *reinterpret_cast<s32*>(p + 0x4C) = 0;
    return self;
}