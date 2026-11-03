#pragma force_active on

struct EvSys {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual int gate(int);
};

struct Mgr {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual int gate(int);
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void* getEvent(int);
};

struct Unit {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void* getList();
};

struct Element {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void invoke(int);
};

struct List {
    virtual void d0();
    virtual void d1();
    virtual Element** get(int);
    virtual void d3();
    virtual int count();
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
EvSys* getInstance__13soEventSystemFv();
Mgr* getManager__13soEventSystemFl(EvSys*, long);

inline List* selectList(Self* self) {
    short id1;
    short id2;
    Mgr* mgr;
    int i;
    List* sel;
    List* cur;
    void* unit;
    int flag;

    id1 = self->a;
    if (id1 <= -1) {
        sel = (List*)lbl_27_bss_3168;
        goto LOOP;
    }
    if (self->cache != 0) {
        goto C;
    }
    if (id1 <= -1 || ((EvSys*)getInstance__13soEventSystemFv())->gate(id1) == 0) {
        flag = 0;
        goto CHECK;
    }
    if (getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->a)->gate(self->b) == 0) {
        self->cache = 0;
        flag = 0;
        goto CHECK;
    }
    id2 = self->b;
    mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->a);
    if (mgr->gate(id2) == 0) {
        cur = 0;
    } else {
        unit = __dynamic_cast(mgr->getEvent(id2), 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
        if (unit == 0) {
            cur = 0;
        } else {
            cur = (List*)((Unit*)unit)->getList();
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
    mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->a);
    if (mgr->gate(self->b) == 0) {
        self->cache = 0;
        sel = (List*)lbl_27_bss_3168;
    } else {
        sel = self->cache;
    }
LOOP:
    return sel;
}

void fn_27_15B2DC(Self* self) {
    List* sel = selectList(self);
    int n = sel->count();
    for (int i = 0; i < n; i++) {
        Element** p = sel->get(i);
        (*p)->invoke(self->c);
    }
}
}