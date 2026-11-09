#include <types.h>
#include <so/event/so_event_system.h>
#include <so/so_instance_manager.h>

#pragma force_active on

extern "C" {
extern char lbl_27_data_7608[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct Self {
    void* vt;
    s16 a;
    s16 b;
    s16 c;
};

class Class_7618 {
public:
    virtual void fn_27_66114();
    virtual void fn_27_66154();
    virtual void fn_27_661B4();
    virtual void fn_27_661B8();
    virtual void fn_27_661C8();
    virtual void fn_27_661D4();
    virtual s16 fn_27_66284(Self*, s8);
    virtual void fn_27_6636C();
    virtual void fn_27_665FC();
};

extern "C" void fn_27_D443C(Self* self, s32 arg1, Self* arg2, s8 arg3) {
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

    if (arg1 <= -1 || self->b <= -1 ||
        soEventSystem::getInstance()->getInstanceManager().isContain(arg1) == 0) {
        return;
    }
    if (soEventSystem::getInstance()->getManager(arg1)->isNullUnit(self->b) != 1) {
        mgr = soEventSystem::getInstance()->getManager(arg1);
        if (mgr->getObserverCapacity(arg2->b) == 0) {
            ret = -1;
        } else {
            soEventUnit* unit = mgr->getEventUnit(arg2->b);
            Class_7618* cast = (Class_7618*)__dynamic_cast(
                unit, 0, lbl_27_data_7608, __RTTI__11soEventUnit, 0);
            if (cast == 0) {
                ret = -1;
            } else {
                ret = cast->fn_27_66284(arg2, arg3);
            }
        }
        self->c = ret;
        if (ret > -1 && ret > -1) {
            self->a = (s16)arg1;
        }
    }
}
