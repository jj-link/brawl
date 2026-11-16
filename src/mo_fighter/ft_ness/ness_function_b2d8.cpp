#include <new>
#include <ac/ac_cmd_interpreter.h>
#include <so/event/so_event_system.h>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern u8 lbl_101_data_4298[];
extern u8 lbl_101_data_4290[];
extern u8 lbl_101_data_42F0[];
extern u8 lbl_27_data_81A0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

class EventPresenterIface {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual s32 slot7();
};

extern "C" acCmdInterpreter* fn_101_B2D8(acCmdInterpreter* self, s16 id,
    soArrayVector<acCmdInterpreterStackData, 8>* stk, s32 arg3, s32 mode,
    const u8* reset, float fixedTimeStep)
{
    u8* p = (u8*)self;
    new (self) acCmdInterpreter(stk, mode, NULL, reset, fixedTimeStep);
    *(void**)(p + 0x34) = lbl_101_data_4298;
    *(s16*)(p + 0x38) = id;
    *(s16*)(p + 0x3A) = 5;
    s32 val = 0;
    *(s32*)(p + 0x3C) = 0;
    s32 manage = id;
    if (id > 0 && (s16)manage > -1) {
        s16 check = *(s16*)(p + 0x38);
        if (soEventSystem::getInstance()->getInstanceManager().isContain(check)) {
            if (!soEventSystem::getInstance()->getManager(*(s16*)(p + 0x38))->getObserverCapacity(*(s16*)(p + 0x3A))) {
                *(s32*)(p + 0x3C) = 0;
            } else {
                soEventManager* m;
                s16 e = *(s16*)(p + 0x3A);
                m = soEventSystem::getInstance()->getManager(*(s16*)(p + 0x38));
                if (!m->getObserverCapacity(e)) {
                    val = 0;
                } else {
                    void* d = __dynamic_cast(m->getEventUnit(e), 0, lbl_101_data_4290, lbl_101_data_42F0, 0);
                    if (d == NULL) {
                        val = 0;
                    } else {
                        val = ((EventPresenterIface*)d)->slot7();
                    }
                }
                *(s32*)(p + 0x3C) = val;
            }
        }
    }
    *(void**)p = lbl_27_data_81A0;
    *(void**)(p + 0x34) = lbl_27_data_81A0 + 0x20;
    *(s32*)(p + 0x40) = arg3;
    *(s32*)(p + 0x44) = 0;
    *(s32*)(p + 0x48) = 0;
    *(s32*)(p + 0x4C) = 0;
    return self;
}
