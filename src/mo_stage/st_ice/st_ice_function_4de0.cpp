#include <types.h>
#include <so/event/so_event_system.h>
#include <so/so_instance_manager.h>
#pragma force_active on
extern "C" {
extern char lbl_62_data_16B0[];
extern char lbl_62_data_12B0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
struct Self { void* vt; s16 a; s16 b; s16 c; };
class Class_1890 {
public:
    virtual void fn_62_79D0();
    virtual void fn_62_6DF0();
    virtual void fn_62_6E00();
    virtual void fn_62_6134();
    virtual void fn_62_5E28();
    virtual void fn_62_567C();
    virtual s16 fn_62_712C(Self*, s8);
    virtual void fn_62_71E8();
    virtual void fn_62_7988();
};
class Class_2C60 {
public:
    virtual void fn_62_CA3C();
    virtual void fn_62_BF04();
    virtual void fn_62_BF14();
    virtual void fn_62_A624();
    virtual void fn_62_A3AC();
    virtual void fn_62_9FC8();
    virtual s16 fn_62_C208(Self*, s8);
    virtual void fn_62_C2C4();
    virtual void fn_62_C9F4();
};
class Class_4768 {
public:
    virtual void fn_62_79D0();
    virtual void fn_62_6DF0();
    virtual void fn_62_6E00();
    virtual void fn_62_F038();
    virtual void fn_62_5E28();
    virtual void fn_62_EF50();
    virtual s16 fn_62_712C(Self*, s8);
    virtual void fn_62_71E8();
    virtual void fn_62_7988();
};
extern "C" void fn_62_4DE0(Self* self, s32 arg1, s8 arg2) {
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
                    Class_1890* cast = (Class_1890*)__dynamic_cast(unit, 0, lbl_62_data_16B0, lbl_62_data_12B0, 0);
                    if (cast == 0) {
                        ret = -1;
                    } else {
                        ret = cast->fn_62_712C(self, arg2);
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