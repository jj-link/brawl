#include <types.h>
#include <new>
#include <ac/ac_cmd_interpreter.h>
#include <so/event/so_event_system.h>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern u8 lbl_27_data_81A0[];
extern u8 lbl_99_data_2154[];
extern u8 lbl_99_data_215C[];
extern u8 lbl_99_data_21B4[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

class soAnimCmdEventUnit {
public:
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual int value();
};

extern "C" acCmdInterpreter* fn_99_7C24(acCmdInterpreter* self, s16 id, soArrayVector<acCmdInterpreterStackData, 8>* stk, s32 r6, s32 mode, const u8* resetMode, f32 fixed)
{
    u8* base = (u8*)self;
    s32 result;

    new (self) acCmdInterpreter(stk, mode, NULL, resetMode, fixed);
    *(void**)(base + 0x34) = lbl_99_data_215C;
    *(s16*)(base + 0x38) = id;
    *(s16*)(base + 0x3A) = 5;
    result = 0;
    *(s32*)(base + 0x3C) = result;
    s32 idx = id;
    if (id > 0 && (s16)idx > -1) {
        s16 check = *(s16*)(base + 0x38);
        if (soEventSystem::getInstance()->getInstanceManager().isContain(check)) {
            if (soEventSystem::getInstance()->getManager(*(s16*)(base + 0x38))->getObserverCapacity(*(s16*)(base + 0x3A)) == 0) {
                *(s32*)(base + 0x3C) = 0;
            } else {
                soEventManager* m;
                s16 unit = *(s16*)(base + 0x3A);
                m = soEventSystem::getInstance()->getManager(*(s16*)(base + 0x38));
                if (m->getObserverCapacity(unit) == 0) {
                    result = 0;
                } else {
                    soAnimCmdEventUnit* u = (soAnimCmdEventUnit*)__dynamic_cast(m->getEventUnit(unit), 0, lbl_99_data_2154, lbl_99_data_21B4, 0);
                    if (u == NULL) {
                        result = 0;
                    } else {
                        result = u->value();
                    }
                }
                *(s32*)(base + 0x3C) = result;
            }
        }
    }
    *(void**)base = lbl_27_data_81A0;
    *(u8**)(base + 0x34) = lbl_27_data_81A0 + 0x20;
    *(s32*)(base + 0x40) = r6;
    *(s32*)(base + 0x44) = 0;
    *(s32*)(base + 0x48) = 0;
    *(s32*)(base + 0x4C) = 0;
    return self;
}