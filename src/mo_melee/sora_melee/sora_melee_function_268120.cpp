#include <types.h>
#include <so/event/so_event_system.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_2DC20[];
extern char lbl_27_data_2DC60[];
void fn_27_AA42C(void* out, void* src, void* owner, s32 flag);
}

class soGimmickEventObserver;
template <> class soEventUnitWrapper<soGimmickEventObserver> {
public:
    static unsigned char __RTTI[];
};
extern "C" {
extern unsigned char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, long);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual s16 slot7(void*);
    virtual void slot8();
};

class UnitIface {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s32 get();
};

class SysIface {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual s32 check(s16);
};

struct EventArg {
    void* vtbl;
    s16 id;
    s16 kind;
    s32 result;
    s32 value;
};

inline s32 getUnit(soEventManager* mgr, s16 kind) {
    soEventUnit* base = mgr->getEventUnit(kind);
    void* w = __dynamic_cast(base, 0, soEventUnitWrapper<soGimmickEventObserver>::__RTTI, __RTTI__11soEventUnit, 0);
    if (w == 0)
        return 0;
    return ((UnitIface*)w)->get();
}

extern "C" void fn_27_268120(char* self, void* arg1, s32 arg2) {
    char* ctx = *(char**)(self + 0x180);
    s16 flag = *(s16*)(self + 0x360);
    Object_vptr_0* obj =
        (Object_vptr_0*)(*(char**)(ctx + 0x80) + 8);
    s16 id = (s16)obj->slot7(arg1);
    EventArg a;
    s32 res;
    a.vtbl = lbl_27_data_2DC60;
    a.id = id;
    a.kind = 3;
    res = 0;
    a.result = res;

    if (id > 0 && id > -1) {
        if (((SysIface*)soEventSystem::getInstance())->check(id) != 0) {
            soEventManager* m1 = soEventSystem::getInstance()->getManager(a.id);
            if (m1->getObserverCapacity(a.kind) == 0) {
                a.result = 0;
            } else {
                soEventManager* m2;
                s16 kind = a.kind;
                m2 = soEventSystem::getInstance()->getManager(a.id);
                if (m2->getObserverCapacity(kind) == 0) {
                    res = 0;
                } else {
                    res = getUnit(m2, kind);
                }
                a.result = res;
            }
        }
    }
    a.value = flag;
    a.vtbl = lbl_27_data_2DC20;
    fn_27_AA42C(&a, arg1, self + 0xa8, arg2);
}