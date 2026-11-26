#include <ft/ft_entry.h>
#include <so/event/so_event_system.h>

#pragma force_active on

extern "C" {
extern char lbl_27_bss_3188[];
extern char lbl_27_data_27038[];
extern char __RTTI__11soEventUnit[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
}

typedef ftEntryEventObserver Elem;
typedef soInstanceManagerFullProperty<Elem*> List;
typedef soEventUnitWrapper<Elem> Unit;

struct EntryObserverSlots {
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual void e6();
    virtual void e7();
    virtual void e8();
    virtual void e9();
    virtual void e10();
    virtual void e11();
    virtual void e12(int, int);
    virtual void e13(int);
    virtual void e14();
    virtual void e15();
    virtual void e16();
};

struct CtxBase {
    char pad[0x3c];
};

struct Ctx : CtxBase {
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void processCamera();
    virtual void c12();
    virtual void c13();
    virtual void c14();
    virtual void c15();
    virtual void c16();
    virtual void renderOpa();
    virtual void c18();
    virtual void c19();
    virtual void c20();
    virtual void init();
    virtual void c22();
    virtual void c23();
    virtual void c24();
    virtual void c25();
    virtual void c26();
    virtual void c27();
    virtual void c28();
    virtual void c29();
    virtual void c30();
    virtual void c31();
    virtual void c32();
    virtual void c33();
    virtual void c34();
    virtual void c35();
    virtual void c36();
    virtual void c37();
    virtual void c38();
    virtual void c39();
    virtual int c40();
};

struct CtxHolder {
    void* a;
    void* b;
    Ctx* obj;
};

struct Self {
    void* vt;
    short a;
    short b;
    List* cache;
    CtxHolder* context;
};

inline List* selectList(Self* self, short& id1, short& id2) {
    soEventManager* mgr;
    List* cur;
    Unit* unit;
    int flag;

    id1 = self->a;
    if (id1 <= -1) {
        return (List*)lbl_27_bss_3188;
    }

    if (self->cache != 0)
        goto C;

    if (id1 <= -1 ||
        soEventSystem::getInstance()->getInstanceManager().isContain(id1) == 0) {
        flag = 0;
        goto CHECK;
    }

    if (soEventSystem::getInstance()->getManager(self->a)->getObserverCapacity(self->b) == 0) {
        self->cache = 0;
        flag = 0;
        goto CHECK;
    }

    id2 = self->b;
    mgr = soEventSystem::getInstance()->getManager(self->a);
    if (mgr->getObserverCapacity(id2) == 0) {
        cur = 0;
    } else {
        unit = (Unit*)__dynamic_cast(
            mgr->getEventUnit(id2), 0, lbl_27_data_27038,
            __RTTI__11soEventUnit, 0);
        if (unit == 0)
            cur = 0;
        else
            cur = unit->getObserverListSub();
    }

    self->cache = cur;
    flag = (cur != 0);

CHECK:
    if (flag == 0) {
        return (List*)lbl_27_bss_3188;
    }

C:
    mgr = soEventSystem::getInstance()->getManager(self->a);
    if (mgr->getObserverCapacity(self->b) == 0) {
        self->cache = 0;
        return (List*)lbl_27_bss_3188;
    }
    return self->cache;
}

extern "C" void fn_27_376A80(Self* self, int eventCode, int arg2) {
    short id2a;
    Ctx* obj1;
    short id1a;
    short id1b;
    short id2b;
    short id1c;
    short id2c;
    Ctx* obj2;
    int i1;
    int i2;
    int i3;

    if (eventCode >= 0x112) {
        goto HIGH;
    }
    switch (eventCode) {
    case 0x10c:
        goto LOW;
    default:
        goto TAIL;
    }

HIGH:
    if (eventCode >= 0x115)
        goto TAIL;

    {
        List* sel = selectList(self, id1a, id2a);
        for (i1 = 0; i1 < static_cast<int>(sel->size()); ++i1) {
            Elem** p;
            obj1 = self->context->obj;
            p = &sel->atIndex(i1);
            int result = obj1->c40();
            (*p)->notifyEventPokemonSpecial(result, eventCode);
        }
    }
    goto TAIL;

LOW:
    {
        List* sel = selectList(self, id1b, id2b);
        for (i2 = 0; i2 < static_cast<int>(sel->size()); ++i2) {
            Elem** p;
            obj2 = self->context->obj;
            p = &sel->atIndex(i2);
            int result = obj2->c40();
            reinterpret_cast<EntryObserverSlots*>(*p)->e13(result);
        }
    }

TAIL:
    switch (arg2) {
    case 0xbe: {
        List* sel = selectList(self, id1c, id2c);
        for (i3 = 0; i3 < static_cast<int>(sel->size()); ++i3) {
            Elem** p;
            p = &sel->atIndex(i3);
            (*p)->notifyEventPokemonRebirthEnd();
        }
        break;
    }
    }
}
