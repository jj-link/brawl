#pragma force_active on

extern "C" {
extern char lbl_27_data_261F0[];
extern char lbl_27_data_261B0[];
extern char lbl_27_data_26440[];
extern char __RTTI__11soEventUnit[];
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void* __dynamic_cast(void*, long, const void*, const void*, long);
}

struct Sys {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int check(int);
};

struct Mgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int has(int);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void* get(int);
};

struct Unit {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int value();
};

struct Self {
    void* vt;
    short id;
    short kind;
    int value;
    int arg;
};

extern "C" Self* fn_27_1156C4(Self* self, int arg1, int id) {
    int result = 0;
    self->vt = lbl_27_data_261F0;
    self->id = id;
    self->kind = 0;
    self->value = result;
    if (id > 0 && id > -1) {
        if (((Sys*)getInstance__13soEventSystemFv())->check(id) != 0) {
            if (((Mgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id))->has(self->kind) == 0) {
                self->value = 0;
            } else {
                Mgr* m;
                short kind;
                kind = self->kind;
                m = (Mgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id);
                if (m->has(kind) == 0) {
                    result = 0;
                } else {
                    void* p = m->get(kind);
                    Unit* u = (Unit*)__dynamic_cast(p, 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
                    if (u == 0) {
                        result = 0;
                    } else {
                        result = u->value();
                    }
                }
                self->value = result;
            }
        }
    }
    self->arg = arg1;
    self->vt = lbl_27_data_261B0;
    return self;
}
