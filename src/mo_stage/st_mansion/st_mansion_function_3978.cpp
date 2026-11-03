#include <types.h>
#include <so/event/so_event_system.h>
#include <so/so_instance_manager.h>
#pragma force_active on

extern "C" {
extern char lbl_47_data_2288[];
extern char lbl_47_data_1080[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct Self {
    void* vt;
    s16 a;
    s16 b;
    s16 c;
};

class Class_1640 {
public:
    virtual void fn_47_7394();
    virtual void fn_47_685C();
    virtual void fn_47_686C();
    virtual void fn_47_4D54();
    virtual void fn_47_499C();
    virtual void fn_47_4024();
    virtual s16 fn_47_6B60(Self*, s8);
    virtual void fn_47_6C1C();
    virtual void fn_47_734C();
};

class Class_18E8 {
public:
    virtual void fn_47_8D88();
    virtual void fn_47_81A8();
    virtual void fn_47_81B8();
    virtual void fn_47_4EB4();
    virtual void fn_47_4968();
    virtual void fn_47_41B0();
    virtual s16 fn_47_84E4(Self*, s8);
    virtual void fn_47_85A0();
    virtual void fn_47_8D40();
};

extern "C" void fn_47_3978(Self* self, s32 arg1, s8 arg2) {
    soEventManager* mgr;
    u32 f31 = 0;
    s32 f30 = 0;
    s32 f4 = 0;
    s32 f5 = 0;
    s16 ret;
    s16 id;
    s16 a = self->a;

    if (a >= 0 && self->b >= 0) {
        f5 = 1;
    }
    if (f5 != 0 && self->c > -1) {
        f4 = 1;
    }
    if (f4 != 0) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(a) == 1) {
            f30 = 1;
        }
    }
    if (f30 != 0) {
        if (soEventSystem::getInstance()->getManager(self->a)->getObserverCapacity(self->b) == 1) {
            f31 = 1;
        }
    }
    if (f31 == 1) {
        id = self->a;
        if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == 1) {
            soEventSystem::getInstance()->getManager(self->a)->eraseObserver(self->b, self->c);
        }
        self->c = -1;
        self->a = -1;
    }
    if (arg1 > -1 && self->b > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(arg1) != 0) {
            if (soEventSystem::getInstance()->getManager(arg1)->isNullUnit(self->b) != 1) {
                mgr = soEventSystem::getInstance()->getManager(arg1);
                if (mgr->getObserverCapacity(self->b) == 0) {
                    ret = -1;
                } else {
                    soEventUnit* unit = mgr->getEventUnit(self->b);
                    Class_1640* cast = (Class_1640*)__dynamic_cast(unit, 0, lbl_47_data_2288, lbl_47_data_1080, 0);
                    if (cast == 0) {
                        ret = -1;
                    } else {
                        ret = cast->fn_47_6B60(self, arg2);
                    }
                }
                self->c = ret;
                if (ret > -1 && ret > -1) {
                    self->a = (s16)arg1;
                }
            }
        }
    }
}