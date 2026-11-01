#pragma force_active on

struct Obj {
    virtual void o0();
    virtual void o1();
    virtual void o2();
    virtual void o3();
    virtual void o4(int, int, int);
};

struct Container {
    virtual void c0();
    virtual void c1();
    virtual Obj** c2(int);
    virtual void c3();
    virtual int c4();
};

struct EventUnit {
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual Container* u7();
};

struct Manager {
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

struct Instance {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual void i3();
    virtual void i4();
    virtual void i5();
    virtual int i6(int);
};

struct Self {
    void* vtable;
    short id1;
    short id2;
    Container* cached;
    int c;
};

extern "C" {
extern char lbl_27_bss_3168[];
extern char lbl_27_data_26440[];
extern char __RTTI__11soEventUnit[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
Instance* getInstance__13soEventSystemFv();
Manager* getManager__13soEventSystemFl(Instance*, long);

inline Container* selectList(Self* self) {
    short id1;
    short id2;
    Manager* mgr;
    Container* cur;
    EventUnit* unit;
    int flag;

    id1 = self->id1;
    if (id1 <= -1) {
        return (Container*)lbl_27_bss_3168;
    }
    if (self->cached != 0) {
        goto CHECK_CACHED;
    }
    if (id1 <= -1 || getInstance__13soEventSystemFv()->i6(id1) == 0) {
        flag = 0;
        goto CHECK;
    }
    if (getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), self->id1)->m4(self->id2) == 0) {
        self->cached = 0;
        flag = 0;
        goto CHECK;
    }

    id2 = self->id2;
    mgr = getManager__13soEventSystemFl(
        getInstance__13soEventSystemFv(), self->id1);
    if (mgr->m4(id2) == 0) {
        cur = 0;
    } else {
        unit = (EventUnit*)__dynamic_cast(
            mgr->m8(id2), 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
        if (unit == 0) {
            cur = 0;
        } else {
            cur = unit->u7();
        }
    }

    self->cached = cur;
    flag = (cur != 0);

CHECK:
    if (flag == 0) {
        return (Container*)lbl_27_bss_3168;
    }

CHECK_CACHED:
    mgr = getManager__13soEventSystemFl(
        getInstance__13soEventSystemFv(), self->id1);
    if (mgr->m4(self->id2) == 0) {
        self->cached = 0;
        return (Container*)lbl_27_bss_3168;
    }
    return self->cached;
}

void fn_27_15746C(Self* self, int arg1, int arg2) {
    Container* list;
    int n;
    int i;

    list = selectList(self);
    n = list->c4();
    for (i = 0; i < n; i++) {
        Obj** p = list->c2(i);
        (*p)->o4(self->c, arg1, arg2);
    }
}
}
