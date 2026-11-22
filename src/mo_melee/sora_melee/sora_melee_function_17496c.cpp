#include <so/event/so_event_system.h>
#include <so/event/so_gimmick_event_presenter.h>
#pragma force_active on

template <> class soEventUnitWrapper<soGimmickEventObserver> : public soEventUnit {
public:
    static unsigned char __RTTI[];
    virtual s16 addObserverSub(soGimmickEventObserver*, s8);
    virtual soInstanceManagerFullProperty<soGimmickEventObserver*>* getObserverListSub();
};

struct Self {
    char pad[8];
    short a;
    short b;
    short c;
};

struct Pack {
    void* vt;
    short a;
    short b;
    int c;
    int d;
};

struct Args {
    int a;
    int b;
};

extern "C" {
extern unsigned char lbl_27_data_2DC60[0xc];
extern unsigned char lbl_27_data_2DC20[0x10];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_AA42C(void*, void*, int, int);
}

static inline int getUnit(soEventManager* manager, short id) {
    soEventUnitWrapper<soGimmickEventObserver>* unit =
        static_cast<soEventUnitWrapper<soGimmickEventObserver>*>(
            __dynamic_cast(manager->getEventUnit(id), 0, soEventUnitWrapper<soGimmickEventObserver>::__RTTI,
                           __RTTI__11soEventUnit, 0));
    if (unit == 0)
        return 0;
    return reinterpret_cast<int>(unit->getObserverListSub());
}

extern "C" void fn_27_17496C(Self* self, int arg) {
    if (self->c != -1) {
        Args args;
        args.a = 51;
        int zero = 0;
        args.b = zero;

        short id = self->a;
        short event = self->c;
        Pack pack;
        pack.vt = lbl_27_data_2DC60;
        pack.a = id;
        pack.b = 3;
        pack.c = zero;

        if (id > 0 && id > -1) {
            if (soEventSystem::getInstance()->getInstanceManager().isContain(id)) {
                if (soEventSystem::getInstance()->getManager(pack.a)->getObserverCapacity(pack.b) == 0) {
                    pack.c = zero;
                } else {
                    soEventManager* manager;
                    short kind;
                    kind = pack.b;
                    manager = soEventSystem::getInstance()->getManager(pack.a);
                    if (manager->getObserverCapacity(kind) == 0)
                        zero = 0;
                    else
                        zero = getUnit(manager, kind);
                    pack.c = zero;
                }
            }
        }

        pack.d = event;
        pack.vt = lbl_27_data_2DC20;
        fn_27_AA42C(&pack, &args, arg, -1);

        short n = self->a;
        if (soEventSystem::getInstance()->getInstanceManager().isContain(n) == 1)
            soEventSystem::getInstance()->getManager(self->a)->eraseObserver(self->b, self->c);

        self->c = -1;
        self->a = -1;
    }
}
