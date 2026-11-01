#pragma force_active on

#include <so/event/so_event_system.h>

struct Elem {
    virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3();
    virtual void e4(); virtual void e5(); virtual void e6(); virtual void e7();
    virtual void e8(); virtual void e9(); virtual void e10(); virtual void e11();
    virtual void e12(); virtual void e13(); virtual void e14(); virtual void e15();
    virtual void e16(); virtual void e17(); virtual void e18(); virtual void e19();
    virtual void e20(); virtual void e21(); virtual void e22(); virtual void e23();
    virtual void e24(); virtual void e25(); virtual void e26(); virtual void e27();
    virtual void e28(); virtual void e29(); virtual void e30(); virtual void e31();
    virtual void e32(); virtual void e33(); virtual void e34(); virtual void e35();
    virtual void e36(); virtual void e37(); virtual void e38();
    virtual void call(int, int);
};

struct List {
    virtual void l0();
    virtual void l1();
    virtual Elem** l4(int);
    virtual void l3();
    virtual int l10();
};

struct Unit {
    virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3();
    virtual void u4(); virtual void u5(); virtual void u6();
    virtual List* u11();
};

struct Manager {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual int m6(int);
    virtual void m7(); virtual void m8(); virtual void m9();
    virtual void* m13(int);
};

struct Instance {
    virtual void i0(); virtual void i1(); virtual void i2();
    virtual void i3(); virtual void i4(); virtual void i5();
    virtual int i11(int);
};

struct Self {
    int field0;
    short id1;
    short id2;
    List* cached;
};

extern "C" {
extern char lbl_27_bss_3168[];
extern char lbl_27_data_26440[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
Instance* getInstance__13soEventSystemFv();
Manager* getManager__13soEventSystemFl(Instance*, long);
}

inline List* selectList(Self* self) {
    short id1;
    short id2;
    Manager* m;
    List* sel;
    List* cur;
    Unit* unit;
    int flag;

    id1 = self->id1;
    if (id1 <= -1) {
        sel = (List*)lbl_27_bss_3168;
        goto LOOP;
    }
    if (self->cached != 0) {
        goto C;
    }
    if (id1 <= -1 || getInstance__13soEventSystemFv()->i11(id1) == 0) {
        flag = 0;
        goto CHECK;
    }
    if (getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1)->m6(self->id2) == 0) {
        self->cached = 0;
        flag = 0;
        goto CHECK;
    }
    id2 = self->id2;
    m = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1);
    if (m->m6(id2) == 0) {
        cur = 0;
    } else {
        unit = (Unit*)__dynamic_cast(m->m13(id2), 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
        if (unit == 0) {
            cur = 0;
        } else {
            cur = unit->u11();
        }
    }
    self->cached = cur;
    flag = (cur != 0);
CHECK:
    if (flag == 0) {
        sel = (List*)lbl_27_bss_3168;
        goto LOOP;
    }
C:
    m = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1);
    if (m->m6(self->id2) == 0) {
        self->cached = 0;
        sel = (List*)lbl_27_bss_3168;
    } else {
        sel = self->cached;
    }
LOOP:
    return sel;
}

extern "C" void fn_27_15B908(Self* self, int arg1, int arg2) {
    List* list = selectList(self);
    int i;
    int n = list->l10();

    for (i = 0; i < n; i++) {
        Elem* e = *list->l4(i);
        e->call(arg1, arg2);
    }
}
