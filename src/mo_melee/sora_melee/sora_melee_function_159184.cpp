#pragma force_active on

struct Obj {
    virtual void e0();
    virtual void e1();
    virtual Obj** s4(int);
    virtual void e3();
    virtual int s6();
    virtual void e5();
    virtual void e6();
    virtual Obj* s9();
    virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3();
    virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3();
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d20(); virtual void d21();
    virtual void s24(int);
};

struct Ev {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual void d4(); virtual void d5();
    virtual int s8(int);
};

struct Mgr {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual int s6(int);
    virtual void d5(); virtual void d6(); virtual void d7();
    virtual void* s10(int);
};

struct Self {
    void* vt;
    short a;
    short b;
    Obj* cache;
    int c;
};

extern "C" {
extern char lbl_27_bss_3168[];
extern char lbl_27_data_26440[];
extern char __RTTI__11soEventUnit[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
Ev* getInstance__13soEventSystemFv();
Mgr* getManager__13soEventSystemFl(Ev*, long);

inline Obj* selectList(Self* self) {
    short id1;
    short id2;
    Mgr* mgr;
    int i;
    Obj* sel;
    Obj* cur;
    Obj* unit;
    int flag;

    id1 = self->a;
    if (id1 <= -1) {
        sel = (Obj*)lbl_27_bss_3168;
        goto LOOP;
    }
    if (self->cache != 0) {
        goto C;
    }
    if (id1 <= -1 || getInstance__13soEventSystemFv()->s8(id1) == 0) {
        flag = 0;
        goto CHECK;
    }
    if (getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->a)->s6(self->b) == 0) {
        self->cache = 0;
        flag = 0;
        goto CHECK;
    }
    id2 = self->b;
    mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->a);
    if (mgr->s6(id2) == 0) {
        cur = 0;
    } else {
        unit = (Obj*)__dynamic_cast(mgr->s10(id2), 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
        if (unit == 0) {
            cur = 0;
        } else {
            cur = unit->s9();
        }
    }
    self->cache = cur;
    flag = (cur != 0);
CHECK:
    if (flag == 0) {
        sel = (Obj*)lbl_27_bss_3168;
        goto LOOP;
    }
C:
    mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->a);
    if (mgr->s6(self->b) == 0) {
        self->cache = 0;
        sel = (Obj*)lbl_27_bss_3168;
    } else {
        sel = self->cache;
    }
LOOP:
    return sel;
}

void fn_27_159184(Self* self) {
    Obj* sel = selectList(self);
    int n = sel->s6();
    for (int i = 0; i < n; i++) {
        Obj** p = sel->s4(i);
        (*p)->s24(self->c);
    }
}
}
