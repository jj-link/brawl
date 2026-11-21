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
    virtual void e1(int, int, int);
};

struct Self {
    char pad[0x20];
    short id1;
    short id2;
    List* cache;
    int value;
    int level;
    int prev;
    int curr;
    unsigned char flag : 1;
};

extern "C" {
extern char lbl_27_bss_C80[];
extern char lbl_27_data_32A8[];
extern char __RTTI__11soEventUnit[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
Inst* getInstance__13soEventSystemFv();
Mgr* getManager__13soEventSystemFl(Inst*, long);

inline void selectList(Self* self, List*& result) {
    short id1;
    Mgr* m;
    short id2;
    List* cur;
    Unit* unit;
    int flag;

    id1 = self->id1;
    if (id1 <= -1) {
        result = (List*)lbl_27_bss_C80;
        return;
    }
    if (self->cache != 0) {
        goto C;
    }
    if (id1 <= -1 || getInstance__13soEventSystemFv()->i6(id1) == 0) {
        flag = 0;
        goto CHECK;
    }
    if (getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1)->m4(self->id2) == 0) {
        self->cache = 0;
        flag = 0;
        goto CHECK;
    }
    id2 = self->id2;
    m = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1);
    if (m->m4(id2) == 0) {
        cur = 0;
    } else {
        unit = (Unit*)__dynamic_cast(m->m8(id2), 0, lbl_27_data_32A8, __RTTI__11soEventUnit, 0);
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
        result = (List*)lbl_27_bss_C80;
        return;
    }

C:
    m = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1);
    if (m->m4(self->id2) == 0) {
        self->cache = 0;
        result = (List*)lbl_27_bss_C80;
        return;
    }
    result = self->cache;
}

void fn_27_355B8(Self* p, int arg1, int arg2) {
    int id;
    Self* self = p;
    List* list;
    int i;
    int n;

    if ((id = arg1) == -1 && p->level != 0) {
        id = 2;
    }
    if (self->level != id && id != -1) {
        selectList(self, list);
        n = list->l4();
        for (i = 0; i < n; i++) {
            Elem* e = *list->l2(i);
            e->e1(id, self->level, self->value);
        }
        self->level = id;
    }
    self->flag = arg2;
    if ((unsigned)(id - 4) <= 1) {
        self->flag = 1;
    }
    int lvl = self->level;
    self->prev = self->curr;
    self->curr = lvl;
}
}
