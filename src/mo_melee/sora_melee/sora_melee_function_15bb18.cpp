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

struct Elem {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(int, int); virtual void v41();
};

struct Self {
    void* pad;
    short id1;
    short id2;
    void* cache;
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

    id1 = self->id1;
    if (id1 <= -1) {
        return (List*)lbl_27_bss_3168;
    }
    if (self->cache != 0) {
        goto C;
    }
    if (id1 <= -1 || getInstance__13soEventSystemFv()->v6(id1) == 0) {
        flag = 0;
        goto CHECK;
    }
    if (getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1)->v4(self->id2) == 0) {
        self->cache = 0;
        flag = 0;
        goto CHECK;
    }
    id2 = self->id2;
    mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1);
    if (mgr->v4(id2) == 0) {
        cur = 0;
    } else {
        unit = (Unit*)__dynamic_cast(mgr->v8(id2), 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
        if (unit == 0) {
            cur = 0;
        } else {
            cur = unit->v7();
        }
    }
    self->cache = (void*)cur;
    flag = (cur != 0);
CHECK:
    if (flag == 0) {
        return (List*)lbl_27_bss_3168;
    }
C:
    mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1);
    if (mgr->v4(self->id2) == 0) {
        self->cache = 0;
        return (List*)lbl_27_bss_3168;
    }
    return (List*)self->cache;
}

void fn_27_15BB18(Self* self, int arg1, int arg2) {
    List* sel = selectList(self);
    int n = sel->v4();
    for (int i = 0; i < n; i++) {
        Elem** p = sel->v2(i);
        (*p)->v40(arg1, arg2);
    }
}
}
