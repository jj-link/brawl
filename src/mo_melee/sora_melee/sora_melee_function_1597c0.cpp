#pragma force_active on

struct System {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual int s6(int);
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

struct Obj;
struct List;

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

struct Obj {
    virtual void o0();
    virtual void o1();
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual void o5();
    virtual void o6();
    virtual void o7();
    virtual void o8();
    virtual void o9();
    virtual void o10();
    virtual void o11();
    virtual void o12();
    virtual void o13();
    virtual void o14();
    virtual void o15();
    virtual void o16();
    virtual void o17();
    virtual void o18();
    virtual void o19();
    virtual void o20();
    virtual void o21();
    virtual void o22();
    virtual void o23(int, int, float);
};

struct List {
    virtual void l0();
    virtual void l1();
    virtual Obj** l2(int);
    virtual void l3();
    virtual int l4();
};

struct Self {
    void* vt;
    short id1;
    short id2;
    List* cache;
    int unkC;
};

extern "C" {
extern char lbl_27_bss_3168[];
extern char lbl_27_data_26440[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
System* getInstance__13soEventSystemFv();
Manager* getManager__13soEventSystemFl(System*, long);

inline List* selectList(Self* self) {
    short id1;
    short id2;
    Manager* mgr;
    List* sel;
    List* cur;
    Unit* unit;
    int flag;

    id1 = self->id1;
    if (id1 <= -1) {
        sel = (List*)lbl_27_bss_3168;
        goto LOOP;
    }
    if (self->cache != 0) {
        goto C;
    }
    if (id1 <= -1 || getInstance__13soEventSystemFv()->s6(id1) == 0) {
        flag = 0;
        goto CHECK;
    }
    if (getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1)->m4(self->id2) == 0) {
        self->cache = 0;
        flag = 0;
        goto CHECK;
    }
    id2 = self->id2;
    mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1);
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
        sel = (List*)lbl_27_bss_3168;
        goto LOOP;
    }
C:
    mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1);
    if (mgr->m4(self->id2) == 0) {
        self->cache = 0;
        sel = (List*)lbl_27_bss_3168;
    } else {
        sel = self->cache;
    }
LOOP:
    return sel;
}

void fn_27_1597C0(Self* self, int arg1, float f) {
    List* sel = selectList(self);
    int n = sel->l4();
    for (int i = 0; i < n; i++) {
        Obj** p = sel->l2(i);
        (*p)->o23(self->unkC, arg1, f);
    }
}
}
