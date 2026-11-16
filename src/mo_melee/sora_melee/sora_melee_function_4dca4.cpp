#include <types.h>
#include <so/event/so_event_system.h>
#include <so/so_array_vector_calculator.h>
#include <so/collision/so_collision_group.h>
#pragma force_active on

class soCollisionSearchEventObserver;

extern "C" {
extern char lbl_27_data_4A88[], lbl_27_data_4958[], lbl_27_data_4A40[], lbl_27_data_46F8[], lbl_27_data_4950[], __RTTI__11soEventUnit[];
extern char __vt__21soStatusEventObserver[], __vt__22soAnimCmdEventObserver[];
extern float lbl_27_rodata_530;
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __ct__16soCollisionGroupFv(void*);
void fn_27_37D3C(void*);
void fn_27_35C3C(void*, int, int, int, int, void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, long);
}

struct Getter {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual short get();
};

struct Item {
    virtual void v0(); virtual void v1(); virtual int slot2();
};

struct Module {
    char pad[0x18];
    Item* item;
    char pad2[0x64];
    char* obj;
};

struct Owner {
    char pad[0xd8];
    Module* module;
};

struct Obs {
    virtual void addObserver(short, signed char);
    short id, type, link;
};

struct Obs3 {
    void* vt;
    short id, type;
    void* unit;
};

struct Self {
    void* vt;
    Obs obs1, obs2;
    Obs3 obs3;
    Owner* owner;
    unsigned int f2c;
    float f30;
    void* calc;
    void* calc2;
    unsigned int top : 4;
    unsigned int mode : 2;
    unsigned int enabled : 1;
    unsigned int rest : 25;
    char groups[0x78];
    char pad[0x3c];
    void* cache;
    int fF8, fFC;
    char pad3[4];
    unsigned char f104;
    unsigned char flag;
};

inline int getResult(Self* self) {
    short t = self->obs3.type;
    soEventManager* mgr = soEventSystem::getInstance()->getManager(self->obs3.id);
    if (mgr->getObserverCapacity(t) == 0) return 0;
    soEventUnitWrapper<soCollisionSearchEventObserver>* unit =
        (soEventUnitWrapper<soCollisionSearchEventObserver>*)__dynamic_cast(
            mgr->getEventUnit(t), 0, lbl_27_data_4950, __RTTI__11soEventUnit, 0);
    if (unit == 0) return 0;
    return (int)unit->getObserverListSub();
}

extern "C" Self* fn_27_4DCA4(Self* self, Owner* owner, int a2, int a3, int a4, unsigned char a5) {
    int result = -1;
    self->vt = lbl_27_data_4A88;
    char* obj = owner->module->obj;
    short id = ((Getter*)(obj + 8))->get();
    self->obs1.id = result;
    self->obs1.type = 4;
    self->obs1.link = result;
    *(void**)&self->obs1 = __vt__21soStatusEventObserver;
    self->obs1.addObserver(id, -1);

    obj = owner->module->obj;
    id = ((Getter*)(obj + 8))->get();
    Obs* o2 = &self->obs2;
    self->obs2.id = result;
    self->obs2.type = 5;
    self->obs2.link = result;
    *(void**)o2 = __vt__22soAnimCmdEventObserver;
    o2->addObserver(id, -1);

    obj = owner->module->obj;
    int cid = (short)((Getter*)(obj + 8))->get();
    self->obs3.vt = lbl_27_data_4A40;
    self->obs3.id = cid;
    self->obs3.type = 17;
    result = 0;
    self->obs3.unit = (void*)result;

    if (cid > 0 && cid > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(cid)) {
            soEventManager* mgr = soEventSystem::getInstance()->getManager(self->obs3.id);
            if (mgr->getObserverCapacity(self->obs3.type) == 0) {
                self->obs3.unit = 0;
            } else {
                result = getResult(self);
                self->obs3.unit = (void*)result;
            }
        }
    }

    float f = lbl_27_rodata_530;
    self->vt = lbl_27_data_4958;
    *(void**)&self->obs1 = lbl_27_data_4958 + 0x54;
    *(void**)&self->obs2 = lbl_27_data_4958 + 0x64;
    *(void**)&self->obs3 = lbl_27_data_4958 + 0x78;
    self->owner = owner;
    self->f2c = a4;
    self->f30 = f;
    self->calc = lbl_27_data_46F8;
    self->calc2 = lbl_27_data_46F8 + 0x48;
    self->top = 0;
    self->mode = 1;
    self->enabled = 0;
    __construct_array(self->groups, __ct__16soCollisionGroupFv, fn_27_37D3C, 0x78, 1);
    soArrayVectorCalculator::postInitialize(*(soArrayVectorCalcInterface*)&self->calc2, 1, 1);
    fn_27_35C3C(self->pad, a2, a3, owner->module->item->slot2(), 5, &self->calc, 0);
    self->cache = (void*)-1;
    self->fF8 = 0;
    self->fFC = 0;
    self->f104 = 0;
    self->flag = a5;
    return self;
}