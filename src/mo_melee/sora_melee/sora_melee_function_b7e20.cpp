#include <types.h>
#include <so/event/so_event_system.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_9D38[], lbl_27_data_250[], lbl_27_data_17788[];
extern char lbl_27_data_175C8[], lbl_27_data_175D0[], __RTTI__11soEventUnit[];
extern char __vt__21soStatusEventObserver[], __vt__22soAnimCmdEventObserver[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

class Object_vptr_0 {
public:
    virtual void slot0(short, signed char);
    virtual void* slot1(int);
    virtual void slot2();
    virtual int slot3();
    virtual int slot4(int);
    virtual void slot5();
    virtual int slot6(int);
    virtual int slot7();
    virtual void slot8();
};
struct Object_vptr_8_base { char pad[8]; };
class Object_vptr_8 : public Object_vptr_8_base { public: virtual void slot0(); };
struct Object_vptr_14_base { char pad[0x14]; };
class Object_vptr_14 : public Object_vptr_14_base { public: virtual void isNull__50soArrayVectorAbstract_25acCmdInterpreterStackData_CFv(); };
struct Object_vptr_20_base { char pad[0x20]; };
class Object_vptr_20 : public Object_vptr_20_base { public: virtual void slot0(); };

struct Obs {
    virtual void attach(short, int);
    short a, b, c;
};
struct ItemInfo {
    int a, b, c, d;
    unsigned char flagA:1;
    unsigned char flagB:1;
    unsigned char flagC:6;
};
struct Self {
    void* v;
    unsigned char f4;
    char pad5[3];
    Obs obs1, obs2, obs3;
    void* v2;
    short id, type;
    void* cache;
    Object_vptr_0* items;
    void* nodes;
    Object_vptr_0* obj;
    void* arg5;
    void* arg6;
    char pad4c[0x14];
    unsigned char f60, f61;
    char pad62[6];
    void* access;
};
class soItemManageEventObserver;
struct I9 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual short get();
};

inline int getResult(Self* self) {
    short unitId = self->type;
    soEventManager* mgr = soEventSystem::getInstance()->getManager(self->id);
    if (mgr->getObserverCapacity(unitId) == 0)
        return 0;
    soEventUnitWrapper<soItemManageEventObserver>* unit =
        (soEventUnitWrapper<soItemManageEventObserver>*)__dynamic_cast(
            mgr->getEventUnit(unitId), 0, lbl_27_data_175C8, __RTTI__11soEventUnit, 0);
    if (unit == 0)
        return 0;
    return (int)unit->getObserverListSub();
}

extern "C" Self* fn_27_B7E20(Self* self, void* access, Object_vptr_0* items,
    Object_vptr_0* obj, void* nodes, void* arg5, void* arg6) {
    int result = 0;
    char* ctx;
    char* p;
    short id;
    short unitId;
    int eventId;
    soEventManager* mgr;
    soEventUnitWrapper<soItemManageEventObserver>* unit;

    self->f4 = 0;
    self->v = lbl_27_data_9D38;
    ctx = *(char**)((char*)access + 0xd8);
    p = *(char**)(ctx + 0x80);
    id = ((I9*)(p + 8))->get();
    self->obs1.a = -1;
    self->obs1.b = 7;
    self->obs1.c = -1;
    *(void**)&self->obs1 = lbl_27_data_250;
    self->obs1.attach(id, -1);

    ctx = *(char**)((char*)access + 0xd8);
    p = *(char**)(ctx + 0x80);
    id = ((I9*)(p + 8))->get();
    Obs* o2 = &self->obs2;
    self->obs2.a = -1;
    self->obs2.b = 4;
    self->obs2.c = -1;
    *(void**)o2 = __vt__21soStatusEventObserver;
    o2->attach(id, -1);

    ctx = *(char**)((char*)access + 0xd8);
    p = *(char**)(ctx + 0x80);
    id = ((I9*)(p + 8))->get();
    Obs* o3 = &self->obs3;
    self->obs3.a = -1;
    self->obs3.b = 5;
    self->obs3.c = -1;
    *(void**)o3 = __vt__22soAnimCmdEventObserver;
    o3->attach(id, -1);

    ctx = *(char**)((char*)access + 0xd8);
    p = *(char**)(ctx + 0x80);
    eventId = ((I9*)(p + 8))->get();
    self->v2 = lbl_27_data_17788;
    self->id = eventId;
    self->type = 12;
    self->cache = 0;
    if (eventId > 0 && eventId > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(eventId)) {
            mgr = soEventSystem::getInstance()->getManager(self->id);
            if (mgr->getObserverCapacity(self->type) == 0) {
                self->cache = 0;
            } else {
                result = getResult(self);
                self->cache = (void*)result;
            }
        }
    }

    self->v = lbl_27_data_175D0;
    *(void**)&self->obs1 = lbl_27_data_175D0 + 0xf8;
    *(void**)&self->obs2 = lbl_27_data_175D0 + 0x108;
    *(void**)&self->obs3 = lbl_27_data_175D0 + 0x118;
    self->v2 = lbl_27_data_175D0 + 0x12c;
    self->items = items;
    self->nodes = nodes;
    self->obj = obj;
    self->arg5 = arg5;
    self->arg6 = arg6;
    self->f60 = 0;
    self->f61 = 1;
    self->access = access;
    for (int i = 0; i < self->items->slot3(); i++) {
        ItemInfo* item = (ItemInfo*)self->items->slot1(i);
        item->b = 0;
        item->a = -1;
        item->c = 0;
        item->d = 2;
        item->flagA = 1;
        item->flagB = 0;
        item->flagC = 0xfe;
    }
    self->obj->slot8();
    return self;
}