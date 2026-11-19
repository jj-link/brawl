#include <so/event/so_event_system.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_data_2DC60[0xc];
extern unsigned char lbl_27_data_2DC20[0x10];
extern unsigned char lbl_27_data_15A70[0x8];
extern unsigned char __RTTI__11soEventUnit[0x8];
void fn_27_AA42C(void* out, void* src, void* owner, s32 flag);
void* __dynamic_cast(void*, long, const void*, const void*, long);
}

class soGimmickEventObserver;
template <> class soEventUnitWrapper<soGimmickEventObserver> {
public:
    static unsigned char __RTTI[];
};

struct ObjIface {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s16 get(void* p);
};

struct UnitIface {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s32 get();
};

struct Pack {
    void* vt;
    s16 a;
    s16 b;
    s32 c;
    s32 d;
};

extern "C" void fn_27_268820(void* arg0, void* arg1, s32 arg2) {
    char* self = (char*)arg0;
    s32 r31 = *(s16*)(self + 0x360);
    char* ctx = *(char**)(self + 0x180);
    char* obj = *(char**)(ctx + 0x80);
    s32 id = ((ObjIface*)(obj + 8))->get(arg1);
    s32 r29 = 0;
    Pack pk;

    pk.vt = lbl_27_data_2DC60;
    pk.a = id;
    pk.b = 3;
    pk.c = r29;

    if (id > 0 && id > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(id)) {
            if (soEventSystem::getInstance()->getManager(pk.a)->getObserverCapacity(pk.b) == 0) {
                pk.c = r29;
            } else {
                soEventManager* mgr2;
                s16 b = pk.b;
                mgr2 = soEventSystem::getInstance()->getManager(pk.a);
                if (mgr2->getObserverCapacity(b) == 0) {
                    r29 = 0;
                } else {
                    soEventUnit* u = mgr2->getEventUnit(b);
                    void* unitBase = __dynamic_cast(u, 0, soEventUnitWrapper<soGimmickEventObserver>::__RTTI, __RTTI__11soEventUnit, 0);
                    if (unitBase == 0) {
                        r29 = 0;
                    } else {
                        r29 = ((UnitIface*)unitBase)->get();
                    }
                }
                pk.c = r29;
            }
        }
    }

    pk.d = r31;
    pk.vt = lbl_27_data_2DC20;
    fn_27_AA42C(&pk, arg1, self + 0xa8, arg2);
}