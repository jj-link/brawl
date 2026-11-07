#include <so/event/so_event_system.h>
#pragma force_active on

struct Elem {
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual unsigned int f5();
};
struct List {
    virtual void f2();
    virtual void f3();
    virtual Elem** f4(int);
    virtual void f5();
    virtual int f6();
};
struct Inst {
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void* f8(int);
};
struct Unit {
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual List* f9();
};
struct Sys {
    void* unk0;
    char pad4[4];
    short unk8;
    short unkA;
    List* unkC;
};
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_bss_BE0[];
extern char lbl_27_data_3FD0[];
extern char __RTTI__11soEventUnit[];
}
extern "C" int fn_27_478D4(Sys* self) {
    soEventManager* mgr;
    List* v;
    Unit* p;
    short a;
    short id = self->unk8;
    int ok;
    List* list;
    int ret;
    int i;
    if (id <= -1) {
        list = (List*)lbl_27_bss_BE0;
        goto loop;
    }
    if (self->unkC != 0) goto blockB;
    if (id <= -1 || ((Inst*)soEventSystem::getInstance())->f8(id) == 0) {
        ok = 0;
        goto check;
    }
    if (soEventSystem::getInstance()->getManager(self->unk8)->getObserverCapacity(self->unkA) == 0) {
        self->unkC = 0;
        ok = 0;
        goto check;
    }
    a = self->unkA;
    mgr = soEventSystem::getInstance()->getManager(self->unk8);
    if (mgr->getObserverCapacity(a) == 0) {
        v = 0;
    } else {
        p = (Unit*)__dynamic_cast(mgr->getEventUnit(a), 0, lbl_27_data_3FD0, __RTTI__11soEventUnit, 0);
        if (p == 0) {
            v = 0;
        } else {
            v = p->f9();
        }
    }
    self->unkC = v;
    ok = (v != 0);
check:
    if (ok != 0) goto blockB;
    list = (List*)lbl_27_bss_BE0;
    goto loop;
blockB:
    if (soEventSystem::getInstance()->getManager(self->unk8)->getObserverCapacity(self->unkA) == 0) {
        self->unkC = 0;
        list = (List*)lbl_27_bss_BE0;
    } else {
        list = self->unkC;
    }
loop:
    ret = 0;
    for (i = 0; i < list->f6(); i++) {
        Elem* e = *list->f4(i);
        if (e->f5() == 1U) ret = 1;
    }
    return ret;
}