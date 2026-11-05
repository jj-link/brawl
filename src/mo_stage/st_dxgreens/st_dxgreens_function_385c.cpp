#include <types.h>
#include <so/event/so_event_system.h>
#include <so/so_instance_manager.h>
#pragma force_active on

extern "C" {
extern char lbl_79_data_1400[];
extern char lbl_79_data_1018[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct Self {
    void* vt;
    s16 a;
    s16 b;
    s16 c;
};

class Class_1410 {
public:
    virtual void fn_79_9A10();
    virtual void fn_79_8E30();
    virtual void fn_79_8E40();
    virtual void fn_79_56EC();
    virtual void fn_79_5350();
    virtual void fn_79_42DC();
    virtual s16 fn_79_916C(Self*, s8);
    virtual void fn_79_9228();
    virtual void fn_79_99C8();
};

class Class_1990 {
public:
    virtual void fn_79_801C();
    virtual void fn_79_74E4();
    virtual void fn_79_74F4();
    virtual void fn_79_59DC();
    virtual void fn_79_5444();
    virtual void fn_79_4518();
    virtual void fn_79_77E8();
    virtual void fn_79_78A4();
    virtual void fn_79_7FD4();
};

class Class_1D38 {
public:
    virtual void fn_79_9A10();
    virtual void fn_79_8E30();
    virtual void fn_79_8E40();
    virtual void fn_79_5B3C();
    virtual void fn_79_5350();
    virtual void fn_79_4618();
    virtual void fn_79_916C();
    virtual void fn_79_9228();
    virtual void fn_79_99C8();
};

extern "C" void fn_79_385C(Self* self, s32 arg1, s8 arg2) {
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
                    Class_1410* cast = (Class_1410*)__dynamic_cast(unit, 0, lbl_79_data_1400, lbl_79_data_1018, 0);
                    if (cast == 0) {
                        ret = -1;
                    } else {
                        ret = cast->fn_79_916C(self, arg2);
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