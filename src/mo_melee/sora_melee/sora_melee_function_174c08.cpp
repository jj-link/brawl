#include <so/event/so_event_system.h>
#include <types.h>
#pragma force_active on

struct Self {
    char pad0[8];
    s16 unk8;
    char padA[2];
    s16 unkC;
};

struct Pack {
    void* vt;
    s16 a, b;
    s32 c, d;
};

struct SysView {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual int f8(int);
};

struct UnitView {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual int f9();
};

class soGimmickEventObserver;
template <> class soEventUnitWrapper<soGimmickEventObserver> {
public:
    static unsigned char __RTTI[];
};

extern "C" {
extern char lbl_27_data_2DC60[0xc];
extern char lbl_27_data_2DC20[0x10];
extern char lbl_27_data_26440[];
extern char __RTTI__11soEventUnit[0x8];
void fn_27_AA42C(void*, void*, void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_27_174C08(Self* self, void* arg1, void* arg2) {
    s16 unit;
    s16 id;
    Pack pk;
    s32 res = 0;

    id = self->unk8;
    unit = self->unkC;
    pk.vt = lbl_27_data_2DC60;
    pk.a = id;
    pk.b = 3;
    pk.c = 0;

    if (id > 0 && id > -1) {
        if (((SysView*)soEventSystem::getInstance())->f8(id) != 0) {
            soEventManager* m1 = soEventSystem::getInstance()->getManager(pk.a);
            if (m1->getObserverCapacity(pk.b) == 0) {
                pk.c = 0;
            } else {
                soEventManager* m2;
                short r28 = pk.b;
                m2 = soEventSystem::getInstance()->getManager(pk.a);
                if (m2->getObserverCapacity(r28) == 0) {
                    res = 0;
                } else {
                    soEventUnit* u = m2->getEventUnit(r28);
                    UnitView* w = (UnitView*)__dynamic_cast(u, 0, soEventUnitWrapper<soGimmickEventObserver>::__RTTI, __RTTI__11soEventUnit, 0);
                    if (w == NULL) {
                        res = 0;
                    } else {
                        res = (s32)w->f9();
                    }
                }
                pk.c = res;
            }
        }
    }

    pk.d = unit;
    pk.vt = lbl_27_data_2DC20;
    fn_27_AA42C(&pk, arg1, arg2, -1);
}
