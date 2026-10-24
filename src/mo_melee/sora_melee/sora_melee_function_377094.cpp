#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_bss_3188[];
extern char lbl_27_data_27038[];
extern char __RTTI__11soEventUnit[];
}

struct EvSys {
    char pad[4];
    short m4;
    short m6;
    void* m8;
};

struct Inst {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6(short);
};

struct Mgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(int);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void* v8(int);
};

struct Elem;

struct List {
    virtual void v0();
    virtual void v1();
    virtual Elem** v2(int);
    virtual void v3();
    virtual int v4();
};

struct Elem {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17(float);
};

struct Unit {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual List* v7();
};

extern "C" void fn_27_377094(EvSys* self, float f) {
    Mgr* mgr;
    int i;
    List* list;
    short id1;
    short id2;
    List* cur;
    Unit* unit;
    int flag;

    id1 = self->m4;
    if (id1 <= -1) {
        list = (List*)lbl_27_bss_3188;
        goto LOOP;
    }
    if (self->m8 != 0) {
        goto C;
    }
    if (id1 <= -1 || ((Inst*)getInstance__13soEventSystemFv())->v6(id1) == 0) {
        flag = 0;
        goto CHECK;
    }
    if (((Mgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->m4))->v4(self->m6) == 0) {
        self->m8 = 0;
        flag = 0;
        goto CHECK;
    }
    id2 = self->m6;
    mgr = (Mgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->m4);
    if (mgr->v4(id2) == 0) {
        cur = 0;
    } else {
        unit = (Unit*)__dynamic_cast(mgr->v8(id2), 0, lbl_27_data_27038, __RTTI__11soEventUnit, 0);
        if (unit == 0) {
            cur = 0;
        } else {
            cur = unit->v7();
        }
    }
    self->m8 = (void*)cur;
    flag = (cur != 0);
CHECK:
    if (flag == 0) {
        list = (List*)lbl_27_bss_3188;
        goto LOOP;
    }
C:
    mgr = (Mgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->m4);
    if (mgr->v4(self->m6) == 0) {
        self->m8 = 0;
        list = (List*)lbl_27_bss_3188;
    } else {
        list = (List*)self->m8;
    }
LOOP:
    for (i = 0; i < list->v4(); i++) {
        Elem** p = list->v2(i);
        (*p)->v17(f);
    }
}
