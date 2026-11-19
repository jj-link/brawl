#include <types.h>
#include <so/event/so_event_system.h>
#include <so/so_instance_manager.h>
#pragma force_active on

class soGimmickEventObserver;

template <> class soEventUnitWrapper<soGimmickEventObserver> {
public:
    static unsigned char __RTTI[];
};

class ObserverUnitIface {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual s16 addObserverSub(soGimmickEventObserver*, s8);
};

extern "C" {
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

class WorkModule {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4(s32);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
};

struct Modules {
    char pad[0x64];
    WorkModule* work;
};

struct Arg {
    char pad[0xd8];
    Modules* modules;
};

struct Self {
    void* vt;
    void* observer;
    s16 a;
    s16 b;
    s16 c;
};

extern "C" void fn_27_1744D4(Self* self, Arg* arg) {
    s32 manageId = arg->modules->work->slot4(0x10000016);
    soEventManager* mgr;
    u32 f31 = 0;
    s32 f30 = 0;
    s32 f4 = 0;
    s32 f5 = 0;
    s16 ret;
    s16 id;
    s16 a = self->a;

    if (a >= 0 && self->b >= 0)
        f5 = 1;
    if (f5 != 0 && self->c > -1)
        f4 = 1;
    if (f4 != 0) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(a) == 1)
            f30 = 1;
    }
    if (f30 != 0) {
        if (soEventSystem::getInstance()->getManager(self->a)->getObserverCapacity(self->b) == 1)
            f31 = 1;
    }
    if (f31 == 1) {
        id = self->a;
        if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == 1)
            soEventSystem::getInstance()->getManager(self->a)->eraseObserver(self->b, self->c);
        self->c = -1;
        self->a = -1;
    }

    if ((s16)manageId > -1 && self->b > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain((s16)manageId)) {
            if (soEventSystem::getInstance()->getManager((s16)manageId)->isNullUnit(self->b) != 1) {
                mgr = soEventSystem::getInstance()->getManager((s16)manageId);
                if (mgr->getObserverCapacity(self->b) == 0) {
                    ret = -1;
                } else {
                    soEventUnit* unit = mgr->getEventUnit(self->b);
                    void* cast = __dynamic_cast(
                        unit, 0, soEventUnitWrapper<soGimmickEventObserver>::__RTTI,
                        __RTTI__11soEventUnit, 0);
                    if (cast == 0)
                        ret = -1;
                    else
                        ret = ((ObserverUnitIface*)cast)->addObserverSub(
                            (soGimmickEventObserver*)&self->observer, -1);
                }
                self->c = ret;
                if (ret > -1 && ret > -1)
                    self->a = (s16)manageId;
            }
        }
    }
}
