#include <types.h>
#include <so/event/so_event_system.h>

#pragma force_active on

class soGimmickEventObserver;
template <> class soEventUnitWrapper<soGimmickEventObserver> {
public:
    static unsigned char __RTTI[];
};

struct Pack {
    void* vt;
    s16 a;
    s16 b;
    s32 c;
    s32 d;
};

struct Pair {
    s32 a;
    s32 b;
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

extern "C" {
extern unsigned char lbl_27_data_2DC60[0xc];
extern unsigned char lbl_27_data_2DC20[0x10];
extern unsigned char __RTTI__11soEventUnit[0x8];

void fn_27_AA42C(void*, void*, void*, s32);
void* __dynamic_cast(void*, long, const void*, const void*, long);
}

extern "C" void fn_27_1548B4(void* self, void* arg1, const void* arg2) {
    Pack pk;
    Pair pr;
    s16 id = (s16)*(const s32*)((const char*)arg2 + 8);
    s32 r30 = 0;

    pk.vt = lbl_27_data_2DC60;
    pk.a = id;
    pk.b = 3;
    pk.c = r30;

    if (id > 0 && id > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(id)) {
            soEventManager* m1 =
                soEventSystem::getInstance()->getManager(pk.a);

            if (m1->getObserverCapacity(pk.b) == 0) {
                pk.c = 0;
            } else {
                soEventManager* m2;
                s16 unit = pk.b;

                m2 = soEventSystem::getInstance()->getManager(pk.a);

                if (m2->getObserverCapacity(unit) == 0) {
                    r30 = 0;
                } else {
                    soEventUnit* u = m2->getEventUnit(unit);
                    void* w = __dynamic_cast(
                        u, 0,
                        soEventUnitWrapper<soGimmickEventObserver>::__RTTI,
                        __RTTI__11soEventUnit, 0);

                    if (w == 0)
                        r30 = 0;
                    else
                        r30 = ((UnitIface*)w)->get();
                }

                pk.c = r30;
            }
        }
    }

    pk.vt = lbl_27_data_2DC20;
    pk.d = -1;
    pr.a = 0x32;
    pr.b = 0;

    fn_27_AA42C(&pk, &pr, arg1, -1);
}
