#pragma force_active on

struct Inst {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual void i3();
    virtual void i4();
    virtual void i5();
    virtual int i6(int);
};

struct Mgr {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual int m4(int);
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void* m8(int);
};

struct Elem;

struct List {
    virtual void l0();
    virtual void l1();
    virtual Elem** l2(int);
    virtual void l3();
    virtual int l4();
};

struct Unit {
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual List* u7();
};

struct Elem {
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
};

struct Self {
    void* vt;
    short a;
    short b;
    List* cache;
    int c;
};

extern "C" {
extern char lbl_27_bss_3168[];
extern char lbl_27_data_26440[];
extern char __RTTI__11soEventUnit[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
Inst* getInstance__13soEventSystemFv();
Mgr* getManager__13soEventSystemFl(Inst*, long);

inline List* selectList(Self* self) {
    short id1;
    short id2;
    Mgr* mgr;
    List* cur;
    Unit* unit;
    int flag;

    id1 = self->a;
    if (id1 <= -1) {
        return (List*)lbl_27_bss_3168;
    }
    if (self->cache != 0) {
        goto C;
    }
    if (id1 <= -1 || getInstance__13soEventSystemFv()->i6(id1) == 0) {
        flag = 0;
        goto CHECK;
    }
    if (getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->a)->m4(self->b) == 0) {
        self->cache = 0;
        flag = 0;
        goto CHECK;
    }
    id2 = self->b;
    mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->a);
    if (mgr->m4(id2) == 0) {
        cur = 0;
    } else {
        unit = (Unit*)__dynamic_cast(mgr->m8(id2), 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
        if (unit == 0) {
            cur = 0;
        } else {
            cur = unit->u7();
        }
    }
    self->cache = cur;
    flag = (cur != 0);
CHECK:
    if (flag == 0) {
        return (List*)lbl_27_bss_3168;
    }
C:
    mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->a);
    if (mgr->m4(self->b) == 0) {
        self->cache = 0;
        return (List*)lbl_27_bss_3168;
    }
    return self->cache;
}

void fn_27_158320(Self* self, int arg1) {
    List* sel = selectList(self);
    int n = sel->l4();
    for (int i = 0; i < n; i++) {
        Elem** p = sel->l2(i);
        (*p)->e12(self->c, arg1);
    }
}
}
