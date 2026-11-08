#pragma force_active on
#include <so/event/so_event_system.h>

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(int, float);
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
};
struct List {
    virtual void v0();
    virtual void v1();
    virtual Object_vptr_0** v2(int);
    virtual void v3();
    virtual int v4();
};
struct Unit {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual List* v7();
};
struct Mgr {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual int v4(int);
    virtual void v5(); virtual void v6(); virtual void v7();
    virtual void* v8(int);
};
struct Inst {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual int v6(int);
};
struct Self {
    void* pad;
    short id1;
    short id2;
    List* cache;
};
extern "C" {
extern char lbl_27_bss_D60[];
extern char lbl_27_data_18418[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
inline List* selectList(Self* self) {
    short id1;
    short id2;
    Mgr* mgr;
    List* cur;
    Unit* unit;
    int flag;
    id1 = self->id1;
    if (id1 <= -1) {
        return (List*)lbl_27_bss_D60;
    }
    if (self->cache != 0) {
        goto C;
    }
    if (id1 <= -1 || ((Inst*)soEventSystem::getInstance())->v6(id1) == 0) {
        flag = 0;
        goto CHECK;
    }
    if (((Mgr*)soEventSystem::getInstance()->getManager(self->id1))->v4(self->id2) == 0) {
        self->cache = 0;
        flag = 0;
        goto CHECK;
    }
    id2 = self->id2;
    mgr = (Mgr*)soEventSystem::getInstance()->getManager(self->id1);
    if (mgr->v4(id2) == 0) {
        cur = 0;
    } else {
        unit = (Unit*)__dynamic_cast(mgr->v8(id2), 0, lbl_27_data_18418, __RTTI__11soEventUnit, 0);
        if (unit == 0) {
            cur = 0;
        } else {
            cur = unit->v7();
        }
    }
    self->cache = cur;
    flag = (cur != 0);
CHECK:
    if (flag == 0) {
        return (List*)lbl_27_bss_D60;
    }
C:
    mgr = (Mgr*)soEventSystem::getInstance()->getManager(self->id1);
    if (mgr->v4(self->id2) == 0) {
        self->cache = 0;
        return (List*)lbl_27_bss_D60;
    }
    return self->cache;
}
extern "C" void fn_27_C60DC(Self* self, int arg1, float arg2) {
    List* list = selectList(self);
    int n = list->v4();
    for (int i = 0; i < n; i++) {
        Object_vptr_0** p = list->v2(i);
        (*p)->slot2(arg1, arg2);
    }
}
