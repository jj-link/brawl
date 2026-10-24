#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_4088[];
extern char lbl_27_data_4040[];
extern char lbl_27_data_3FD0[];
extern char lbl_27_data_3FD8[];
extern char __RTTI__11soEventUnit[];

void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void* __dynamic_cast(void*, long, const void*, const void*, long);
}

struct I9 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s16 get(void*);
};

struct Sys {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual s32 check(long);
};

struct Mgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 check(long);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void* s10(long);
};

struct Unit {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s32 get();
};

struct Self {
    void* f0;
    void* f4;
    s16 f8;
    s16 fA;
    s32 fC;
};

inline s32 getResult(Self* self) {
    s16 id = self->fA;
    Mgr* mgr2 = (Mgr*)getManager__13soEventSystemFl(
        getInstance__13soEventSystemFv(), self->f8);
    if (mgr2->check(id) == 0) {
        return 0;
    }
    Unit* u = (Unit*)__dynamic_cast(
        mgr2->s10(id), 0, lbl_27_data_3FD0, __RTTI__11soEventUnit, 0);
    if (u == 0) {
        return 0;
    }
    return u->get();
}

extern "C" void* fn_27_47220(Self* self, void* arg1) {
    s32 result = 0;
    s32 eid;
    Mgr* mgr2;
    Mgr* mgr;
    char* ctx;
    char* obj;

    self->f0 = lbl_27_data_4088;
    ctx = *(char**)((char*)arg1 + 0xD8);
    obj = *(char**)(ctx + 0x80);
    eid = ((I9*)(obj + 8))->get(arg1);
    self->f4 = lbl_27_data_4040;
    self->f8 = eid;
    self->fA = 14;
    self->fC = result;

    if (eid > 0 && eid > -1) {
        if (((Sys*)getInstance__13soEventSystemFv())->check(eid) != 0) {
            mgr = (Mgr*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), self->f8);
            if (mgr->check(self->fA) == 0) {
                self->fC = 0;
            } else {
                result = getResult(self);
                self->fC = result;
            }
        }
    }

    self->f0 = lbl_27_data_3FD8;
    self->f4 = lbl_27_data_3FD8 + 0x18;
    return self;
}
