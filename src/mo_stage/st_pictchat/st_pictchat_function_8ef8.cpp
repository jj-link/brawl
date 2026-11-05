#include <types.h>
#include <so/event/so_event_system.h>
#include <so/so_instance_manager.h>
#pragma force_active on

extern "C" {
extern char lbl_73_data_3DF8[];
extern char lbl_73_data_1DE0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct Self {
    void* vt;
    s16 a;
    s16 b;
    s16 c;
};

class Class_3E50 {
public:
    virtual void fn_73_C58C();
    virtual void fn_73_B9AC();
    virtual void fn_73_B9BC();
    virtual void fn_73_A9C8();
    virtual void fn_73_A784();
    virtual void fn_73_9D10();
    virtual s16 fn_73_BCE8(Self*, s8);
    virtual void fn_73_BDA4();
    virtual void fn_73_C544();
};

class Class_3F48 {
public:
    virtual void fn_73_C58C();
    virtual void fn_73_B9AC();
    virtual void fn_73_B9BC();
    virtual void fn_73_AA60();
    virtual void fn_73_A784();
    virtual void fn_73_9DA8();
    virtual s16 fn_73_BCE8(Self*, s8);
    virtual void fn_73_BDA4();
    virtual void fn_73_C544();
};

class Class_4040 {
public:
    virtual void fn_73_C58C();
    virtual void fn_73_B9AC();
    virtual void fn_73_B9BC();
    virtual void fn_73_AAF8();
    virtual void fn_73_A784();
    virtual void fn_73_9E40();
    virtual s16 fn_73_BCE8(Self*, s8);
    virtual void fn_73_BDA4();
    virtual void fn_73_C544();
};

class Class_4138 {
public:
    virtual void fn_73_C58C();
    virtual void fn_73_B9AC();
    virtual void fn_73_B9BC();
    virtual void fn_73_AB90();
    virtual void fn_73_A784();
    virtual void fn_73_9ED8();
    virtual s16 fn_73_BCE8(Self*, s8);
    virtual void fn_73_BDA4();
    virtual void fn_73_C544();
};

class Class_4400 {
public:
    virtual void fn_73_C58C();
    virtual void fn_73_B9AC();
    virtual void fn_73_B9BC();
    virtual void fn_73_ACF0();
    virtual void fn_73_A784();
    virtual void fn_73_9FD8();
    virtual s16 fn_73_BCE8(Self*, s8);
    virtual void fn_73_BDA4();
    virtual void fn_73_C544();
};

extern "C" void fn_73_8EF8(Self* self, s32 arg1, s8 arg2) {
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
                    Class_3E50* cast = (Class_3E50*)__dynamic_cast(unit, 0, lbl_73_data_3DF8, lbl_73_data_1DE0, 0);
                    if (cast == 0) {
                        ret = -1;
                    } else {
                        ret = cast->fn_73_BCE8(self, arg2);
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
