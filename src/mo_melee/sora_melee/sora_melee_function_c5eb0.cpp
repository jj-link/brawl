#pragma force_active on

struct Inst {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6(int);
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
    virtual void v0();
    virtual void v1();
    virtual Elem** v2(int);
    virtual void v3();
    virtual int v4();
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
    virtual void call(int, int, int, float);
};

struct Self {
    void* pad;
    short id1;
    short id2;
    List* cached;
};

extern "C" {
extern char lbl_27_bss_D60[];
extern char lbl_27_data_18418[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
Inst* getInstance__13soEventSystemFv();
Mgr* getManager__13soEventSystemFl(Inst*, long);
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
    if (self->cached != 0) {
        goto CHECK_CACHED;
    }
    if (id1 <= -1 || getInstance__13soEventSystemFv()->v6(id1) == 0) {
        flag = 0;
        goto CHECK;
    }
    if (getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1)->m4(self->id2) == 0) {
        self->cached = 0;
        flag = 0;
        goto CHECK;
    }
    id2 = self->id2;
    mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1);
    if (mgr->m4(id2) == 0) {
        cur = 0;
    } else {
        unit = (Unit*)__dynamic_cast(mgr->m8(id2), 0, lbl_27_data_18418, __RTTI__11soEventUnit, 0);
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
        return (List*)lbl_27_bss_D60;
    }
CHECK_CACHED:
    mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1);
    if (mgr->m4(self->id2) == 0) {
        self->cached = 0;
        return (List*)lbl_27_bss_D60;
    }
    return self->cached;
}

extern "C" void fn_27_C5EB0(Self* self, int arg1, int arg2, int arg3, float farg) {
    List* list = selectList(self);
    int n = list->v4();
    for (int i = 0; i < n; i++) {
        Elem** p = list->v2(i);
        (*p)->call(arg1, arg2, arg3, farg);
    }
}
