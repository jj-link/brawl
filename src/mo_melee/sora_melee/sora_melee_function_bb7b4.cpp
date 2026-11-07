#include <so/event/so_event_system.h>
#pragma force_active on

class Observer {
public:
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
    virtual void a8(); virtual void notify(void*, int, int);
};
class List {
public:
    virtual void a0(); virtual void a1(); virtual Observer** at(int);
    virtual void a3(); virtual int size();
};
class Unit {
public:
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual void a4(); virtual void a5(); virtual void a6(); virtual List* list();
};
struct Data { void* pad; void* value; };
class Module {
public:
    virtual void a0(); virtual Data* getData(); virtual void a2(); virtual void a3();
    virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
    virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11();
    virtual void action(int);
};
class Self {
public:
    virtual void isNull(); virtual void fn_27_B81C4(); virtual void fn_27_B8360();
    virtual void fn_27_B83E4(); virtual void fn_27_B8674(); virtual void fn_27_B86B0();
    virtual void fn_27_B87B8(); virtual void fn_27_B88AC(); virtual void fn_27_B8A98();
    virtual void fn_27_B8B44(); virtual void fn_27_BC19C(); virtual void fn_27_B91FC();
    virtual void fn_27_B86D4(); virtual void fn_27_BE4F0(); virtual void fn_27_B83F4();
    virtual void fn_27_B8434(); virtual void fn_27_B8468(); virtual void fn_27_B849C();
    virtual void fn_27_B84D0(); virtual void fn_27_B8548(); virtual void fn_27_B8594();
    virtual void fn_27_B85E0(); virtual void fn_27_BE4E8(); virtual void fn_27_BE4E0();
    virtual void fn_27_BE4D8(); virtual void fn_27_B8648(); virtual void fn_27_B8780(void*);
    char pad[0x2c]; short a; short b; List* cache; char pad38[8]; Module* module;
};
extern "C" {
extern char lbl_27_bss_CC0[], lbl_27_data_175C8[], __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
inline bool checkManageId(const Self* self) { short id = self->a; return soEventSystem::getInstance()->getInstanceManager().isContain(id); }
inline List* selectList(Self* self) {
    short id1, id2;
    soEventManager* mgr;
    List* cur;
    Unit* unit;
    int flag;
    id1 = self->a;
    if (id1 <= -1) return (List*)lbl_27_bss_CC0;
    if (self->cache != 0) goto C;
    if (id1 <= -1 || checkManageId(self) == 0) {
        flag = 0; goto CHECK;
    }
    if (soEventSystem::getInstance()->getManager(self->a)->getObserverCapacity(self->b) == 0) {
        self->cache = 0; flag = 0; goto CHECK;
    }
    id2 = self->b;
    mgr = soEventSystem::getInstance()->getManager(self->a);
    if (mgr->getObserverCapacity(id2) == 0) cur = 0;
    else {
        unit = (Unit*)__dynamic_cast(mgr->getEventUnit(id2), 0, lbl_27_data_175C8, __RTTI__11soEventUnit, 0);
        if (unit == 0) cur = 0;
        else cur = unit->list();
    }
    self->cache = cur;
    flag = (cur != 0);
CHECK:
    if (flag == 0) return (List*)lbl_27_bss_CC0;
C:
    mgr = soEventSystem::getInstance()->getManager(self->a);
    if (mgr->getObserverCapacity(self->b) == 0) {
        self->cache = 0; return (List*)lbl_27_bss_CC0;
    }
    return self->cache;
}
extern "C" void fn_27_BB7B4(Self* self, int arg, unsigned mode, int last) {
    void* value = self->module->getData()->value;
    List* list = selectList(self);
    int n = list->size();
    for (int i = 0; i < n; i++) {
        (*list->at(i))->notify(value, arg, last);
    }
    self->module->action(arg);
    if (mode == 1) self->fn_27_B8780(value);
}