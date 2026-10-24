#pragma force_active on

extern "C" {
extern char __vt__10soNullable[];
extern char lbl_27_data_C940[];
extern char lbl_27_data_C910[];
extern char __RTTI__11soEventUnit[];
extern char lbl_27_data_13A70[];

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
    unsigned char flag;
    void* vt2;
    short id;
    short kind;
    int value;
};

extern "C" Self* fn_27_281308(Self* self, unsigned char flag) {
    self->vt = __vt__10soNullable;
    self->flag = flag;
    self->vt2 = lbl_27_data_C940;
    self->id = -1;
    self->kind = 11;
    int result = 0;
    self->value = result;

    if (self->id > 0 && self->id > -1) {
        if (((Sys*)getInstance__13soEventSystemFv())->check(self->id) != 0) {
            if (((Mgr*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), self->id))->has(self->kind) == 0) {
                self->value = result;
            } else {
                Mgr* m;
                short type;
                type = self->kind;
                m = (Mgr*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), self->id);
                if (m->has(type) == 0) {
                    result = 0;
                } else {
                    Unit* u = (Unit*)__dynamic_cast(
                        m->get(type), 0, lbl_27_data_C910, __RTTI__11soEventUnit, 0);
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

    self->vt = lbl_27_data_13A70;
    self->vt2 = lbl_27_data_13A70 + 12;
    return self;
}
